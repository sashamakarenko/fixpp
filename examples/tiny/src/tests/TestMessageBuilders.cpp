#include <tiny/MessageBuilders.h>
#include <utests/TrivialHelper.h>

using namespace tiny;

int main( int args, const char ** argv )
{
    ReusableMessageBuilder mdfr( MessageMarketDataSnapshotFullRefresh::getMessageType(), 512, 128 );
    auto & builder = MarketDataSnapshotFullRefreshBuilder::Ref( mdfr );
    auto & header  = builder.getHeader();
    header.appendSenderCompID( "sender" );
    header.appendTargetCompID( "target" );
    header.finalize();
    builder.super().setupSendingTime( ClockPrecision::NANOSECONDS );
    builder.appendMDReqID( "reqid"s );
    auto & entries = builder.appendNoMDEntries( 2 );
    entries.appendMDEntryType( MDEntryTypeEnums::BID );
    entries.appendMDEntryPositionNo( 1 );
    entries.appendMDEntryPx( 1.123, 6 );
    entries.appendMDEntrySize( 100 );
    entries.appendMDEntryType( MDEntryTypeEnums::OFFER );
    entries.appendMDEntryPositionNo( 1 );
    entries.appendMDEntryPx( 1.234, 6 );
    entries.appendMDEntrySize( 200 );
    builder.finalizeWithSeqnum(1);
    std::cout << fixstr( mdfr.start, ttyRgbStyle ) << std::endl;
}
