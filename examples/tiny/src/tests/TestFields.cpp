#include <tiny/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace tiny;

int main( int args, const char ** argv )
{
    const char * fixBuffer = EXAMPLE_MARKETDATA_FULL_REFRESH;
    tiny::MessageHeader header;
    offset_t pos = header.scan( fixBuffer, strlen( fixBuffer ) );
    tiny::MessageMarketDataSnapshotFullRefresh mdsfr;
    pos = mdsfr.scan( fixBuffer + pos, strlen( fixBuffer ) - pos );

    unsigned yyyymmdd = parseYYYYMMDD( header.ptrToSendingTime() );
    unsigned yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    unsigned hour, minute, second, nanos;
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << "SendingTime: " << yyyymmdd << " = " << yyyy << "/" << mm << "/" << dd << "-"
              << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    parseTimestamp( header.ptrToSendingTime(), yyyy, mm, dd, hour, minute, second, nanos );
    std::cout << "SendingTime: " << yyyy << "/" << mm << "/" << dd << "-"
              << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    std::tm tm = {};
    parseTimestamp( header.ptrToSendingTime(), tm.tm_year, tm.tm_mon, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, nanos );
    tm.tm_year -= 1900;
    tm.tm_mon  -= 1;
    std::cout << "SendingTime: " << std::asctime(&tm) << std::endl;

    timeptr = "12:34:56";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.789";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.789012";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.789012345";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "01:02:03.999999999";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.001";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.000002";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

    timeptr = "12:34:56.000000003";
    parseTime( timeptr, hour, minute, second, nanos );
    std::cout << timeptr << " = " << hour << ":" << minute << ":" << second << "." << nanos << std::endl;

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
