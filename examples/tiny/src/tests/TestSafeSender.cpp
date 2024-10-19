#include <tiny/SenderApi.h>
#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 30, 128 );
    execReport.bufferGrowChunk = 8;
    execReport.header.append<SenderCompID>("ASENDER");
    execReport.header.append<TargetCompID>("ATARGET");
    execReport.header.finalize();
    execReport.setupSendingTime( TimestampKeeper::Precision::NANOSECONDS );
    auto sz1 = execReport.end - execReport.begin;
    execReport.userTime[1].secFraction = ClockPrecision::MILLISECONDS;
    execReport.appendSafely<TransactTime>( execReport.userTime[1] );
    execReport.appendSafely<ClOrdID>("OID123");
    execReport.appendSafely<QtyType>( QtyTypeEnums::CONTRACTS );
    execReport.appendSafely<Price>( 123.04567, 4 );
    execReport.userTime[1].update();
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << computeChecksum( execReport.start, execReport.end - 7 ) << "\n";
    std::cout << fixstr( execReport.start, ttyRgbStyle ) << std::endl;

    auto len = execReport.end - execReport.start;
    std::cout.write( execReport.start, len ) << std::endl;
    Header header;
    offset_t pos = header.scan( execReport.start, len );
    ExecutionReport er;
    pos = er.scan( execReport.start + pos, len - pos );

    auto sz2 = execReport.end - execReport.begin;
    CHECK_NOT_EQ( has been resized, sz2 - sz1, 0 )
    return 0;
}
