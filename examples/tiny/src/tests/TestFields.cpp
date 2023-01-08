#include <tiny/Messages.h>
#include "FixSamples.h"
#include "Helper.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>

namespace tiny
{

union Quantity
{
    Quantity( int64_t  i ): integer{i}{}
    Quantity( uint64_t i ): integer{(int64_t)i}{}
    Quantity( double   r ): real{r}{}
    Quantity( float    r ): real{r}{}
    int64_t integer;
    double  real;
};

struct ExtQuantity
{
    template< typename T >
    ExtQuantity( const T & value, bool isInt ): value{ value }, isInteger{ isInt }{}
    Quantity value;
    bool     isInteger;
};

inline ExtQuantity parseQuantity( const char * ptr )
{
    int sign = 1;
    if( *ptr == '-' )
    {
        sign = -1;
        ++ptr;
    }
    unsigned intlen = 0;
    int64_t integer = parseUInt<int64_t>( ptr, intlen );
    if( ptr[intlen] != '.' ) // SOH
    {
       return { sign * integer, true };
    }

    unsigned mantissaLength = 0;
    double mantissa = parseUInt( ptr + intlen + 1, mantissaLength );
    mantissa *= div10Pow[ mantissaLength ];
    return { sign * ( (double)integer + mantissa ), false };
}

}

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

    double d = parseDouble( "0" I );
    CHECK( double 0, d, == 0 );

    d = parseDouble( "0.0" I );
    CHECK( double 0.0, d, == 0.0 );

    d = parseDouble( "0.123" I );
    CHECK( double 0.123, d, == 0.123 );

    d = parseDouble( ".123" I );
    CHECK( double .123, d, == .123 );

    d = parseDouble( "0000.123000" I );
    CHECK( double 0000.123000, d, == 0.123 );

    d = parseDouble( "1000" I );
    CHECK( double 1000, d, == 1000 );

    d = parseDouble( "23.0000001" I );
    CHECK( double 23.0000001, d, == 23.0000001 );

    d = parseDouble( "-1.345" I );
    CHECK( double -1.345, d, == -1.345 );

    ExtQuantity qty = parseQuantity( "0" I );
    CHECK( qty 0 is int, qty.isInteger, == true );
    CHECK( qty 0, qty.value.integer, == 0 );

    qty = parseQuantity( "0.0" I );
    CHECK( qty 0.0 is int, qty.isInteger, == false );
    CHECK( qty 0.0, qty.value.real, == 0.0 );

    qty = parseQuantity( "10.023" I );
    CHECK( qty 10.023 is int, qty.isInteger, == false );
    CHECK( qty 10.023, qty.value.real, == 10.023 );

    return 0;
}
