#include <tiny/SenderApi.h>
#include "Helper.h"

using namespace tiny;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 512, 128 );
    execReport.header.append<FieldSenderCompID>("ASENDER");
    execReport.header.append<FieldTargetCompID>("ATARGET");
    execReport.header.pushTag<FieldMsgSeqNum>();
    execReport.header.finalize();

    execReport.append<FieldSendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.sendingTime.setup( execReport.end - TimestampKeeper::DATE_TIME_NANOS_LENGTH, TimestampKeeper::Precision::NANOSECONDS );
    execReport.sendingTime.update();
    const unsigned sendingTimeLength = execReport.end - execReport.begin;

    execReport.append<FieldClOrdID>("OID123");
    execReport.append<FieldQtyType>( QtyTypeEnums::CONTRACTS.value );
    execReport.append<FieldPrice>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;



    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<FieldClOrdID>("OID4567");
    execReport.append<FieldQtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<FieldPrice>( 21123.04567, 2 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(124);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<FieldClOrdID>("OID36194130303320464710274");
    execReport.append<FieldOrigClOrdID>( "2312320210" );
    execReport.append<FieldSecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<FieldQtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<FieldPrice>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<FieldClOrdID>("OID36194130303320464710274");
    execReport.append<FieldOrigClOrdID>( "2312320210" );
    execReport.append<FieldSecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<FieldQtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<FieldPrice>( 312.1204567, 7 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123456);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;
    execReport.rewind( sendingTimeLength );

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update( std::chrono::system_clock::now() + 10 * 24h );
    execReport.append<FieldClOrdID>("OID36194130303320710274");
    execReport.append<FieldOrigClOrdID>( "2312320210" );
    execReport.append<FieldSecurityID>("dhdddgqgddDDdwuidpdgqe");
    execReport.append<FieldTransactTime>( execReport.sendingTime.begin, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.append<FieldSide>( SideEnums::BUY.value );
    execReport.append<FieldQtyType>( QtyTypeEnums::UNITS.value );
    execReport.append<FieldPrice>( 2.12, 7 );
    execReport.append<FieldOrdType>( OrdTypeEnums::LIMIT.value );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    execReport.rewind( sendingTimeLength );
    execReport.sendingTime.update();
    execReport.append<FieldClOrdID>("OID123");
    execReport.append<FieldQtyType>( QtyTypeEnums::CONTRACTS.value );
    execReport.append<FieldPrice>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;
    execReport.rewind( sendingTimeLength );

    return 0;
}
