#include <tiny/Messages.h>
#include "FixSamples.h"
#include "Helper.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace tiny;
using namespace std::string_literals;

#define W9 std::setw(9)  <<  std::setfill('0')
#define W4 std::setw(4)  <<  std::setfill('0')
#define W3 std::setw(3)  <<  std::setfill('0')
#define W2 std::setw(2)  <<  std::setfill('0')

int main( int args, const char ** argv )
{
    const char * fixBuffer = EXAMPLE_MARKETDATA_FULL_REFRESH;
    tiny::MessageHeader header;
    offset_t pos = header.scan( fixBuffer, strlen( fixBuffer ) );
    tiny::MessageMarketDataSnapshotFullRefresh mdsfr;
    pos = mdsfr.scan( fixBuffer + pos, strlen( fixBuffer ) - pos );

    // 52=20071123-05:30:00.000
    std::stringstream result;
    unsigned yyyymmdd = parseYYYYMMDD( header.ptrToSendingTime() );
    result << yyyymmdd;
    CHECK( YYYYMMDD, result.str(), == std::string_view( header.ptrToSendingTime(), 8 ) )
    unsigned yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    unsigned hour, minute, second, nanos;
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W4 << yyyy 
           << W2 << mm 
           << W2 << dd << "-"
           << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "." 
           << W3 << (nanos/1000000);
    CHECK( parseTime, result.str(), == std::string_view( header.ptrToSendingTime(), 21 ) )


    parseTimestamp( header.ptrToSendingTime(), yyyy, mm, dd, hour, minute, second, nanos );
    result.str("");
    result << W4 << yyyy 
           << W2 << mm 
           << W2 << dd << "-"
           << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "." 
           << W3 << (nanos/1000000);
    CHECK( parseTimestamp, result.str(), == std::string_view( header.ptrToSendingTime(), 21 ) )

    {
    unsigned short yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    unsigned short hour, minute, second;
    parseTime( timeptr, hour, minute, second, nanos );

    }

    {
    short yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    short hour, minute, second;
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W4 << yyyy 
           << W2 << mm 
           << W2 << dd << "-"
           << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "." 
           << W3 << (nanos/1000000);
    CHECK( short parseTime, result.str(), == std::string_view( header.ptrToSendingTime(), 21 ) )
    }

    {
    uint64_t yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    uint64_t hour, minute, second, nanos;
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W4 << yyyy 
           << W2 << mm 
           << W2 << dd << "-"
           << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "." 
           << W3 << (nanos/1000000);
    CHECK( u64 parseTime, result.str(), == std::string_view( header.ptrToSendingTime(), 21 ) )
    }

    std::tm tm = {};
    parseTimestamp( header.ptrToSendingTime(), tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, nanos );
    tm.tm_year -= 1900;
    tm.tm_mon  -= 1;
    std::cout << "SendingTime tm: " << std::asctime(&tm) << std::endl;

    timeptr = "12:34:56";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56, result.str(), == timeptr + ".000000000"s )

    timeptr = "12:34:56.";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56., result.str(), == timeptr + "000000000"s )

    timeptr = "12:34:56.789";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.789, result.str(), == timeptr + "000000"s )

    timeptr = "12:34:56.789012";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.789012, result.str(), == timeptr + "000"s )

    timeptr = "12:34:56.789012345";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.789012345, result.str(), == timeptr )

    timeptr = "01:02:03.999999999";
    parseTime( timeptr, hour, minute, second, nanos );
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 01:02:03.999999999, result.str(), == timeptr )

    timeptr = "12:34:56.001";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.001, result.str(), == timeptr + "000000"s )

    timeptr = "12:34:56.000002";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.000002, result.str(), == timeptr + "000"s )

    timeptr = "12:34:56.000000003";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":" 
           << W2 << minute << ":" 
           << W2 << second << "."
           << W9 << nanos;
    CHECK( 12:34:56.00000003, result.str(), == timeptr )

    auto noMdEntries = mdsfr.getNoMDEntries();
    for( auto i = 0; i < noMdEntries; ++i )
    {
        const tiny::GroupMDEntries & mdentry = mdsfr.getGroupMDEntries(i);
        double price = mdentry.getMDEntryPx();
        unsigned qty = mdentry.getMDEntrySize();
        std::cout << "MDEntry: " << i << " price: " << price << " quantity: " << qty << std::endl;
    }

    return 0;
}
