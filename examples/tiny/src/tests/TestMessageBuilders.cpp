#include <tiny/MessageBuilders.h>
#include <utests/TrivialHelper.h>

using namespace tiny;

int main( int args, const char ** argv )
{
    ReusableMessageBuilder mdfr( MessageMarketDataSnapshotFullRefresh::getMessageType(), 512, 128 );
    auto & builder = MarketDataSnapshotFullRefreshBuilder::New(mdfr);
    auto & header = builder.getHeader();
    header.appendSenderCompID( "sender" );
    header.finalize();
    builder.appendMDReqID( "reqid"s );
    auto & entries = builder.appendNoMDEntries( 2 );
    entries.appendMDEntryType( MDEntryTypeEnums::ITEM_BID );
    entries.appendMDEntryPositionNo( 1 );
    entries.appendMDEntryPx( Float{ 1.123, 6 } );
    entries.appendMDEntrySize( 100 );
    entries.appendMDEntryType( MDEntryTypeEnums::ITEM_OFFER );
    entries.appendMDEntryPositionNo( 1 );
    entries.appendMDEntryPx( Float{ 1.234, 6 } );
    entries.appendMDEntrySize( 200 );
    mdfr.setSeqnumAndUpdateHeaderAndChecksum(1);
    std::cout << fixstr( mdfr.start, ttyRgbStyle ) << std::endl;
}
