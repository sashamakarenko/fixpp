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

    execReport.append<SendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.sendingTime.setup( execReport.end - TimestampKeeper::DATE_TIME_NANOS_LENGTH, TimestampKeeper::Precision::NANOSECONDS );
    execReport.sendingTime.update();
    const unsigned sendingTimeLength = execReport.end - execReport.begin;

    execReport.append<ClOrdID>("OID123");
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS.value );
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
    execReport.append<QtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<Price>( 21123.04567, 2 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(124);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<Price>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID36194130303320464710274");
    execReport.append<OrigClOrdID>( "2312320210" );
    execReport.append<SecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<QtyType>( QtyTypeEnums::UNITS.value );
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
    execReport.append<Side>( SideEnums::BUY.value );
    execReport.append<QtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<Price>( 2.12, 7 );
    execReport.append<OrdType>( OrdTypeEnums::LIMIT.value );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<ClOrdID>("OID123");
    execReport.append<QtyType>( QtyTypeEnums::CONTRACTS.value );
    execReport.append<Price>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;
    execReport.rewind( sendingTimeLength );

    return 0;
}
