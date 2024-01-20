#include <tiny/SenderApi.h>
#include "Helper.h"

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 512, 128 );
    execReport.header.append<SenderCompID>("ASENDER");
    execReport.header.append<TargetCompID>("ATARGET");
    execReport.header.pushTag<MsgSeqNum>();
    execReport.header.finalize();

    // will use userTime1 as TransactTime
    execReport.userTime1.secFraction = TimestampKeeper::Precision::MILLISECONDS;

    execReport.append<SendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.sendingTime.setup( execReport.end - TimestampKeeper::DATE_TIME_NANOS_LENGTH, TimestampKeeper::Precision::NANOSECONDS );
    execReport.sendingTime.update();
    const unsigned sendingTimeLength = execReport.end - execReport.begin;

    execReport.append<ClOrdID>("OID123");
    execReport.append<TransactTime>( execReport.userTime1 );
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS() );
    execReport.append<Price>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    auto len = execReport.end - execReport.start;
    std::cout.write( execReport.start, len ) << std::endl;
    Header header;
    offset_t pos = header.scan( execReport.start, len );
    ExecutionReport er;
    pos = er.scan( execReport.start + pos, len - pos );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID4567");
    execReport.append<TransactTime>( execReport.userTime1 );
    execReport.append<QtyType>( QtyTypeEnums::UNITS() );
    execReport.append<Price>( 21123.04567, 2 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(124);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<TransactTime>( execReport.userTime1 );
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS() );
    execReport.append<Price>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<TransactTime>( execReport.userTime1 );
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS() );
    execReport.append<Price>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123456);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;
    execReport.rewind( sendingTimeLength );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update( std::chrono::system_clock::now() + 10 * 24h );
    execReport.append<ClOrdID>("OID36194130303320710274");
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<TransactTime>( execReport.sendingTime.begin, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.append<Side>( SideEnums::BUY() );
    execReport.append<QtyType>( QtyTypeEnums::UNITS() );
    execReport.append<Price>( 2.12, 7 );
    execReport.append<OrdType>( OrdTypeEnums::LIMIT() );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID123");
    execReport.append<TransactTime>( execReport.userTime1 );
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS() );
    execReport.append<Price>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;
    execReport.rewind( sendingTimeLength );

    // second fractions
    const std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    char timestamp_sec[ TimestampKeeper::DATE_TIME_SECONDS_LENGTH + 1 ];
    TimestampKeeper tsSecs( timestamp_sec, TimestampKeeper::Precision::SECONDS );
    tsSecs.update( now );
    timestamp_sec[ sizeof(timestamp_sec) - 1 ] = 0;
    std::cout << "seconds: " << timestamp_sec << std::endl;

    char timestamp_mil[ TimestampKeeper::DATE_TIME_MILLIS_LENGTH + 1 ];
    TimestampKeeper tsMils( timestamp_mil, TimestampKeeper::Precision::MILLISECONDS );
    tsMils.update( now );
    timestamp_mil[ sizeof(timestamp_mil) - 1 ] = 0;
    std::cout << "millis:  " << timestamp_mil << std::endl;

    char timestamp_mic[ TimestampKeeper::DATE_TIME_MICROS_LENGTH + 1 ];
    TimestampKeeper tsMics( timestamp_mic, TimestampKeeper::Precision::MICROSECONDS );
    tsMics.update( now );
    timestamp_mic[ sizeof(timestamp_mic) - 1 ] = 0;
    std::cout << "micros:  " << timestamp_mic << std::endl;

    char timestamp_nan[ TimestampKeeper::DATE_TIME_NANOS_LENGTH + 1 ];
    TimestampKeeper tsNans( timestamp_nan, TimestampKeeper::Precision::NANOSECONDS );
    tsNans.update( now );
    timestamp_nan[ sizeof(timestamp_nan) - 1 ] = 0;
    std::cout << "nanos:   " << timestamp_nan << std::endl;

    return 0;
}
