#include <tiny/SenderApi.h>
#include "Helper.h"

using namespace tiny;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;

    CHECK( 0, uintWidth(0), == 1 )
    CHECK( 9, uintWidth(9), == 1 )
    CHECK( 10, uintWidth(10), == 2 )
    CHECK( 99, uintWidth(99), == 2 )
    CHECK( 100, uintWidth(100), == 3 )
    CHECK( 999, uintWidth(999), == 3 )
    CHECK( 1000, uintWidth(1000), == 4 )
    CHECK( 9999, uintWidth(9999), == 4 )
    CHECK( 10000, uintWidth(10000), == 5 )
    CHECK( 99999, uintWidth(99999), == 5 )
    CHECK( 100000, uintWidth(100000), == 6 )
    CHECK( 999999, uintWidth(999999), == 6 )
    CHECK( 1000000, uintWidth(1000000), == 7 )
    CHECK( 9999999, uintWidth(9999999), == 7 )
    CHECK( 10000000, uintWidth(10000000), == 8 )
    CHECK( 99999999, uintWidth(99999999), == 8 )
    CHECK( 100000000, uintWidth(100000000), == 9 )
    CHECK( 999999999, uintWidth(999999999), == 9 )


    CHECK( 0, smallUintWidth(0), == 1 )
    CHECK( 9, smallUintWidth(9), == 1 )
    CHECK( 10, smallUintWidth(10), == 2 )
    CHECK( 99, smallUintWidth(99), == 2 )
    CHECK( 100, smallUintWidth(100), == 3 )
    CHECK( 999, smallUintWidth(999), == 3 )
    CHECK( 1000, smallUintWidth(1000), == 4 )
    CHECK( 9999, smallUintWidth(9999), == 4 )
    CHECK( 10000, smallUintWidth(10000), == 5 )
    CHECK( 99999, smallUintWidth(99999), == 5 )
    CHECK( 100000, smallUintWidth(100000), == 6 )
    CHECK( 999999, smallUintWidth(999999), == 6 )
    CHECK( 1000000, smallUintWidth(1000000), == 7 )
    CHECK( 9999999, smallUintWidth(9999999), == 7 )

    char buf[1024];
    buf[10] = 0;
    CHECK( 0, std::string_view( reverseUIntToString( buf + 10, 0 ) ), == "0" );
    CHECK( 1, std::string_view( reverseUIntToString( buf + 10, 1 ) ), == "1" );
    CHECK( 12, std::string_view( reverseUIntToString( buf + 10, 12 ) ), == "12" );
    CHECK( 120, std::string_view( reverseUIntToString( buf + 10, 120 ) ), == "120" );
    CHECK( 123456, std::string_view( reverseUIntToString( buf + 10, 123456 ) ), == "123456" );

    buf[20] = 0;
    char * p = reverseUIntToString( buf + 20, 120 ) - FieldMsgSeqNum::INSERTABLE_TAG_WIDTH;
    insert<FieldMsgSeqNum>(p);
    std::cout << p << "\n";

    p = buf;
    p = insert<FieldBeginString>(p);
    p = insert<FieldMsgType>(p);
    p = insert<FieldAccount>(p);
    p = insert<FieldAvgPx>(p);
    *p = 0;
    std::cout << buf << "\n";

    FixBufferStream fixstr( buf );
    fixstr.pushTag<FieldBeginString>().pushTag<FieldBodyLength>().append<FieldAccount>( "trader", 6 ).append<FieldNoLegs>(679);
    *fixstr.end = 0;
    std::cout << buf << "\n";

    std::cout << MessageExecutionReport::getMessageName() << " " << MessageExecutionReport::getMessageType() << "\n";

    return 0;
}
