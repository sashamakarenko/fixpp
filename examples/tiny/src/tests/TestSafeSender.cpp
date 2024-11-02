#include <tiny/SenderApi.h>
#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    using namespace std::chrono_literals;
    ReusableMessageBuilder execReport( MessageExecutionReport::getMessageType(), 30, 128 );
    execReport.setBufferGrowChunkSize(8);
    execReport.header().append<SenderCompID>("ASENDER");
    execReport.header().append<TargetCompID>("ATARGET");
    execReport.header().finalize();
    execReport.setupSendingTime( TimestampKeeper::Precision::NANOSECONDS );
    auto sz1 = execReport.length();
    execReport.userTime(1).setPrecision( ClockPrecision::MILLISECONDS );
    execReport.appendSafely<TransactTime>( execReport.userTime(1) );
    execReport.appendSafely<ClOrdID>("OID123");
    execReport.appendSafely<QtyType>( QtyTypeEnums::CONTRACTS );
    execReport.appendSafely<Price>( 123.04567, 4 );
    execReport.userTime(1).update();
    execReport.setSeqnumAndUpdateHeaderAndChecksum(123);
    std::cout << computeChecksum( execReport.messageBegin(), execReport.end() - 7 ) << "\n";
    std::cout << fixstr( execReport.messageBegin(), ttyRgbStyle ) << std::endl;

    auto len = execReport.totalLength();
    std::cout.write( execReport.messageBegin(), len ) << std::endl;
    Header header;
    offset_t pos = header.scan( execReport.messageBegin(), len );
    ExecutionReport er;
    pos = er.scan( execReport.messageBegin() + pos, len - pos );

    auto sz2 = execReport.totalLength();
    CHECK_NOT_EQ( has been resized, sz2 - sz1, 0 )
    return 0;
}
