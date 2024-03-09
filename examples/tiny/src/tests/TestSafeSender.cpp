#include <tiny/SenderApi.h>
#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 140, 128 );
    execReport.bufferGrowChunk = 8;
    execReport.header.append<SenderCompID>("ASENDER");
    execReport.header.append<TargetCompID>("ATARGET");
    execReport.header.pushTag<MsgSeqNum>();
    execReport.header.finalize();

    execReport.appendSafely<SendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::DATE_TIME_NANOS_LENGTH );
    execReport.sendingTime.setup( execReport.end - TimestampKeeper::DATE_TIME_NANOS_LENGTH, TimestampKeeper::Precision::NANOSECONDS );
    execReport.sendingTime.update();
    const unsigned sendingTimeLength = execReport.end - execReport.begin;

    execReport.appendSafely<ClOrdID>("OID123");
    execReport.appendSafely<QtyType>( QtyTypeEnums::CONTRACTS() );
    execReport.appendSafely<Price>( 123.04567, 4 );
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    auto len = execReport.end - execReport.start;
    std::cout.write( execReport.start, len ) << std::endl;
    Header header;
    offset_t pos = header.scan( execReport.start, len );
    ExecutionReport er;
    pos = er.scan( execReport.start + pos, len - pos );

    return 0;
}
