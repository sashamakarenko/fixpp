#include <tiny/Messages.h>
#include "FixSamples.h"
#include <utests/TrivialHelper.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <set>

using namespace tiny;
using namespace std::string_literals;

#define W9 std::setw(9)  <<  std::setfill('0')
#define W4 std::setw(4)  <<  std::setfill('0')
#define W3 std::setw(3)  <<  std::setfill('0')
#define W2 std::setw(2)  <<  std::setfill('0')

int main( int args, const char ** argv )
{
    // uncomment to test too big tags
    // [[maybe_unused]] raw_tag_t bigTag = tag_as_raw<123'000>();

    static_assert( std::is_same_v< Float, field_traits<FieldType::AMT>::native_type > );

    raw_tag_t raw = tag_as_raw<1>();
    tag_t tag = raw_to_tag( raw );
    CHECK_EQ( tag 1, tag, 1 );

    raw = tag_as_raw<12>();
    tag = raw_to_tag( raw );
    CHECK_EQ( tag 12, tag, 12 );

    raw = tag_as_raw<123>();
    tag = raw_to_tag( raw );
    CHECK_EQ( tag 123, tag, 123 );

    raw = tag_as_raw<1234>();
    tag = raw_to_tag( raw );
    CHECK_EQ( tag 1234, tag, 1234 );

    raw = tag_as_raw<12345>();
    tag = raw_to_tag( raw );
    CHECK_EQ( tag 12345, tag, 12345 );

    offset_t pos = 0;
    raw = tiny::loadRawTag( "1=", pos );
    CHECK_EQ( load tag 1, raw, tag_as_raw<1>() );

    pos = 0;
    raw = tiny::loadRawTag( "12345=", pos );
    CHECK_EQ( load tag 12345, raw, tag_as_raw<12345>() );

    tag = tiny::parseTag( "12345=" );
    CHECK_EQ( parse tag 12345, tag, 12345 );

    tag = tiny::parseTag( "=" );
    CHECK_EQ( parse empty tag, tag, 0 );

    CHECK_EQ( is good tag 0,      tiny::isGoodTag( "0=" ),      false );
    CHECK_EQ( is good tag 02,     tiny::isGoodTag( "02=" ),     false );
    CHECK_EQ( is good tag 123456, tiny::isGoodTag( "123456=" ), false );
    CHECK_EQ( is good tag 1 2,    tiny::isGoodTag( "1 2=" ),    false );
    CHECK_EQ( is good tag NaN,    tiny::isGoodTag( "NAN=" ),    false );
    CHECK_EQ( is good tag empty,  tiny::isGoodTag( "=" ),       false );
    CHECK_EQ( is good tag SOH,    tiny::isGoodTag( "\1=" ),     false );
    CHECK_EQ( is good tag 1,      tiny::isGoodTag( "1=" ),      true );
    CHECK_EQ( is good tag 12345,  tiny::isGoodTag( "12345=" ),  true );

    tag = tiny::parseTag( "A=" ); // 17=
    CHECK_EQ( parse tag A, tag, 'A' - '0' );

    const char * fixBuffer = EXAMPLE_MARKETDATA_FULL_REFRESH;
    tiny::MessageHeader header;
    pos = header.scan( fixBuffer, strlen( fixBuffer ) );
    tiny::MessageMarketDataSnapshotFullRefresh mdsfr;
    pos = mdsfr.scan( fixBuffer + pos, strlen( fixBuffer ) - pos );

    // 52=20071123-05:30:00.000
    std::stringstream result;
    unsigned yyyymmdd = parseYYYYMMDD( header.ptrToSendingTime() );
    result << yyyymmdd;
    CHECK_EQ( YYYYMMDD, result.str(), std::string_view( header.ptrToSendingTime(), 8 ) )
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
    CHECK_EQ( parseTime, result.str(), std::string_view( header.ptrToSendingTime(), 21 ) )


    parseTimestamp( header.ptrToSendingTime(), yyyy, mm, dd, hour, minute, second, nanos );
    result.str("");
    result << W4 << yyyy
           << W2 << mm
           << W2 << dd << "-"
           << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W3 << (nanos/1000000);
    CHECK_EQ( parseTimestamp, result.str(), std::string_view( header.ptrToSendingTime(), 21 ) )

    {
    unsigned short yyyy, mm, dd;
    const char *timeptr = parseYYYYMMDD( header.ptrToSendingTime(), yyyy, mm, dd ) + 1;
    unsigned short hour, minute, second;
    parseTime( timeptr, hour, minute, second, nanos );
    }

    {
    unsigned short yyyy, mm, dd;
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
    CHECK_EQ( short parseTime, result.str(), std::string_view( header.ptrToSendingTime(), 21 ) )
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
    CHECK_EQ( u64 parseTime, result.str(), std::string_view( header.ptrToSendingTime(), 21 ) )
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
    CHECK_EQ( 12:34:56, result.str(), timeptr + ".000000000"s )

    timeptr = "12:34:56.";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56., result.str(), timeptr + "000000000"s )

    timeptr = "12:34:56.789";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.789, result.str(), timeptr + "000000"s )

    timeptr = "12:34:56.789012";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.789012, result.str(), timeptr + "000"s )

    timeptr = "12:34:56.789012345";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.789012345, result.str(), timeptr )

    timeptr = "01:02:03.999999999";
    parseTime( timeptr, hour, minute, second, nanos );
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 01:02:03.999999999, result.str(), timeptr )

    timeptr = "12:34:56.001";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.001, result.str(), timeptr + "000000"s )

    timeptr = "12:34:56.000002";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.000002, result.str(), timeptr + "000"s )

    timeptr = "12:34:56.000000003";
    parseTime( timeptr, hour, minute, second, nanos );
    result.str("");
    result << W2 << hour << ":"
           << W2 << minute << ":"
           << W2 << second << "."
           << W9 << nanos;
    CHECK_EQ( 12:34:56.00000003, result.str(), timeptr )

    auto noMdEntries = mdsfr.getNoMDEntries();
    for( unsigned i = 0; i < noMdEntries; ++i )
    {
        const tiny::GroupMDEntries & mdentry = mdsfr.getGroupMDEntries(i);
        Float price = mdentry.getMDEntryPx();
        Float qty = mdentry.getMDEntrySize();
        std::cout << "MDEntry: " << i << " price: " << price << " quantity: " << qty << std::endl;
    }

    double d = parseDouble( "0" I );
    CHECK_EQ( double 0, d, 0 );

    d = parseDouble( "0.0" I );
    CHECK_EQ( double 0.0, d, 0.0 );

    d = parseDouble( "0.123" I );
    CHECK_EQ( double 0.123, d, 0.123 );

    d = parseDouble( ".123" I );
    CHECK_EQ( double .123, d, .123 );

    d = parseDouble( "0000.123000" I );
    CHECK_EQ( double 0000.123000, d, 0.123 );

    d = parseDouble( "1000" I );
    CHECK_EQ( double 1000, d, 1000 );

    d = parseDouble( "23.0000001" I );
    CHECK_EQ( double 23.0000001, d, 23.0000001 );

    d = parseDouble( "-1.345" I );
    CHECK_EQ( double -1.345, d, -1.345 );

    Quantity qty( "0" I );
    CHECK_EQ( qty 0 is int, qty.isInteger(), true );
    CHECK_EQ( qty 0, qty.asInt(), 0 );
    CHECK_EQ( qty < 0, qty < 0, false );
    CHECK_EQ( qty > 0, qty > 0, false );
    CHECK_EQ( qty < 1, qty < 1, true );

    qty.parse( "0.0" I );
    CHECK_EQ( qty 0.0 is int, qty.isInteger(), false );
    CHECK_EQ( qty 0.0, qty.asDouble(), 0.0 );

    qty.parse( "10.023" I );
    CHECK_EQ( qty 10.023 is int, qty.isInteger(), false );
    CHECK_EQ( qty 10.023, qty.asDouble(), 10.023 );

    qty = 1.2345;
    CHECK_EQ( qty 1.2345 is int, qty.isInteger(), false );
    CHECK_EQ( qty 1.2345 get double, qty.asDouble(), 1.2345 );
    CHECK_EQ( qty 1.2345 get int, qty.asInt(), 1 );

    std::set<Quantity> qtySet;
    qtySet.insert(   0 );
    qtySet.insert( 0.0 );
    CHECK_EQ( qty set size 1, qtySet.size(), 1 );
    qtySet.insert( 1.0 );
    qtySet.insert(   1 );
    CHECK_EQ( qty set size 2, qtySet.size(), 2 );

    return 0;
}
