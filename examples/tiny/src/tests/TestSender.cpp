#include <tiny/SenderApi.h>
#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 512, 128 );
    execReport.header().append<SenderCompID>("ASENDER");
    execReport.header().append<TargetCompID>("ATARGET");
    execReport.header().pushTag<MsgSeqNum>();
    execReport.header().finalize();

    // will use userTime(1) as TransactTime
    execReport.userTime(1).setPrecision( ClockPrecision::MILLISECONDS );

    execReport.append<SendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.sendingTime().setup( execReport.end() - TimestampKeeper::DATE_TIME_NANOS_LENGTH, ClockPrecision::NANOSECONDS );
    execReport.sendingTime().update();
    const unsigned sendingTimeLength = execReport.bodyLength();

    execReport.append<ClOrdID>("OID123");
    execReport.append<TransactTime>( execReport.userTime(1) );
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS );
    execReport.append<Price>( "123.04567"_ff );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;

    int chksum;
    size_t len;
    offset_t pos;
    Header header;
    ExecutionReport er;
    auto parseBack = [&]( int line )
    {
        std::cout << " --- line : " << line << " --- " << std::endl;
        chksum = computeChecksum( execReport.messageBegin(), execReport.end() - 7 );
        len = execReport.end() - execReport.messageBegin();
        header.reset();
        pos = header.scan( execReport.messageBegin(), len );
        er.reset();
        pos = er.scan( execReport.messageBegin() + pos, len - pos );
        CHECK_EQ( exec report all scanned, header.getMessageLength() + er.getMessageLength(), (size_t)len )
        CHECK_EQ( exec report no bad fields, er.findBadField() == nullptr, true )
        CHECK_EQ( exec report check sum, er.getCheckSum(), chksum )
        std::cout << std::endl;
    };

    parseBack( __LINE__ );

    for( int foo = 0; foo < 2; ++foo )
    {
    execReport.rewind( sendingTimeLength );
    execReport.sendingTime().update();
    execReport.append<ClOrdID>("OID4567");
    execReport.append<TransactTime>( execReport.userTime(1) );
    execReport.append<QtyType>( QtyTypeEnums::UNITS );
    execReport.append<Price>( 21123.04567, 2 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(124);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;
    parseBack( __LINE__ );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime().update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<TransactTime>( execReport.userTime(1) );
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS );
    execReport.append<Price>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;
    parseBack( __LINE__ );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime().update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<TransactTime>( execReport.userTime(1) );
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS );
    execReport.append<Price>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123456);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;
    parseBack( __LINE__ );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime().update( std::chrono::system_clock::now() + 10 * 24h );
    execReport.append<ClOrdID>("OID36194130303320710274");
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<TransactTime>( execReport.sendingTime().data(), TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.append<Side>( SideEnums::BUY );
    execReport.append<QtyType>( QtyTypeEnums::UNITS );
    execReport.append<Price>( 2.12, 7 );
    execReport.append<OrdType>( OrdTypeEnums::LIMIT );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;
    parseBack( __LINE__ );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime().update();
    execReport.append<ClOrdID>("OID123");
    execReport.append<TransactTime>( ClockType::now(), ClockPrecision::NANOSECONDS );
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS );
    execReport.append<Price>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;
    parseBack( __LINE__ );

    execReport.setMinBodyLengthWidth(6);
    execReport.setMinSeqnumWidth(8);
    }

    // second fractions
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    char timestamp_sec[ TimestampKeeper::DATE_TIME_SECONDS_LENGTH + 1 ];
    TimestampKeeper tsSecs( timestamp_sec, ClockPrecision::SECONDS );
    tsSecs.update( now );
    timestamp_sec[ sizeof(timestamp_sec) - 1 ] = 0;
    std::cout << "seconds: " << timestamp_sec << std::endl;

    char timestamp_mil[ TimestampKeeper::DATE_TIME_MILLIS_LENGTH + 1 ];
    TimestampKeeper tsMils( timestamp_mil, ClockPrecision::MILLISECONDS );
    tsMils.update( now );
    timestamp_mil[ sizeof(timestamp_mil) - 1 ] = 0;
    std::cout << "millis:  " << timestamp_mil << std::endl;

    char timestamp_mic[ TimestampKeeper::DATE_TIME_MICROS_LENGTH + 1 ];
    TimestampKeeper tsMics( timestamp_mic, ClockPrecision::MICROSECONDS );
    tsMics.update( now );
    timestamp_mic[ sizeof(timestamp_mic) - 1 ] = 0;
    std::cout << "micros:  " << timestamp_mic << std::endl;

    char timestamp_nan[ TimestampKeeper::DATE_TIME_NANOS_LENGTH + 1 ];
    TimestampKeeper tsNans( timestamp_nan, ClockPrecision::NANOSECONDS );
    tsNans.update( now );
    timestamp_nan[ sizeof(timestamp_nan) - 1 ] = 0;
    std::cout << "nanos:   " << timestamp_nan << std::endl;

    return 0;
}
