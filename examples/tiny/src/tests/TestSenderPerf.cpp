#include <tiny/SenderApi.h>
#include <pe/Measurement.h>

using namespace tiny;
using namespace tiny::field;

struct OrderFields
{
    const char * const orderId;
    unsigned orderIdLen;

    const char * const symbol;
    unsigned symbolLen;

    const char * const account;
    unsigned accountLen;

    SideEnums::ValueType side;
    OrdTypeEnums::ValueType type;
    unsigned qty;
    double price;
};

OrderFields orders[] =
{
    { "OID12345-22" , 11, "GBP/USD", 7, "TRADER7"   , 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 10000  , 1.30 },
    { "OID12345"    ,  8, "EUR/USD", 7, "TRADER78"  , 8, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 2000000, 1.20 },
    { "OID12345-100", 12, "GBP/USD", 7, "TRADER789" , 9, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 250000 , 1.31 },
    { "OID12345-1"  , 10, "GBP/EUR", 7, "TRADER789A",10, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 4000000, 1.21 },
    { "OID12345-11" , 11, "GBP/USD", 7, "TRADER7"   , 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 10000  , 1.30 },
    { "OID12345"    ,  8, "EUR/USD", 7, "TRADER78"  , 8, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 2000000, 1.20 },
    { "OID15525-100", 12, "GBP/USD", 7, "TRADER789" , 9, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 250000 , 1.31 },
    { "OID12345-1"  , 10, "GBP/EUR", 7, "TRADER789A",10, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 50000  , 1.21 },
    {}
};

int main( int args, const char ** argv )
{
    pe::Measurement m;
    m.pinToCpuCore( 3 );
    m.addEvent( pe::EventType::cpuCycles );
    m.addEvent( pe::EventType::hwInstructions );
    m.addEvent( pe::EventType::branchInstructions );
    m.addEvent( pe::EventType::llCacheReadMisses );
    m.addEvent( pe::EventType::branchMisses );
    // m.addEvent( pe::EventType::memory );
    m.initialize( 100 );

    ReusableMessageBuilder order( MessageNewOrderSingle::getMessageType(), 512, 128 );
    order.header.append<SenderCompID>("ASENDER");
    order.header.append<TargetCompID>("ATARGET");
    order.header.pushTag<MsgSeqNum>();
    order.header.finalize();

    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_SECONDS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::SECONDS;
    auto constexpr tsLen  = TimestampKeeper::DATE_TIME_MILLIS_LENGTH;
    auto constexpr tsFrac = TimestampKeeper::Precision::MILLISECONDS;
    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_MICROS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::MICROSECONDS;
    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_NANOS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::NANOSECONDS;
    order.append<SendingTime>( TimestampKeeper::PLACE_HOLDER, tsLen );
    order.sendingTime.setup( order.end - tsLen, tsFrac );
    order.sendingTime.update();
    const unsigned sendingTimeLength = order.end - order.begin;

    unsigned seqnum = 1000;
    {
        const OrderFields & of = orders[0];
        order.rewind( sendingTimeLength );
        order.sendingTime.update();
        order.append<Account>( of.account );
        order.append<ClOrdID>( of.orderId );
        order.append<Symbol>( of.symbol );
        order.append<Side>( of.side );
        order.append<OrderQty>( of.qty );
        order.append<Price>( of.price, 6 );
        order.append<TransactTime>( order.sendingTime.begin, tsLen );
        order.append<OrdType>( of.type );
        order.setSeqnumAndUpdateHeaderAndChecksum(seqnum);
        std::cout << fixstr( order.start, ttyRgbStyle ) << std::endl;
    }

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        m.startCapture();
        order.rewind( sendingTimeLength );
        order.sendingTime.update();
        order.append<Account>( of.account, of.accountLen );
        order.append<ClOrdID>( of.orderId, of.orderIdLen );
        order.append<Symbol>( of.symbol, of.symbolLen );
        order.append<Side>( of.side );
        order.append<Price>( of.price, 6 );
        order.append<OrderQty>( of.qty );
        order.append<TransactTime>( order.sendingTime.begin, tsLen );
        order.append<OrdType>( of.type );
        order.setSeqnumAndUpdateHeaderAndChecksum(++seqnum);
        m.stopCapture();
    }

    /*
    i9-9900K @ 5GHz
    -------------
    cpu.cycles:	338
    hw.instrs:	909
    br.instrs:	97
    cch.ll.rmiss:	0
    br.misses:	1
    */
    std::cout << "\n -- Build order -- " << std::endl;
    m.prepareResults();
    // m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        order.rewind( sendingTimeLength );
        m.startCapture();
        order.sendingTime.update();
        m.stopCapture();
    }

    std::cout << "\n -- Timestamp update -- " << std::endl;
    m.prepareResults();
    m.showAverageValues( std::cout );
    m.rewind();

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        order.rewind( sendingTimeLength );
        m.startCapture();
        order.append<ClOrdID>( of.orderId, of.orderIdLen );
        m.stopCapture();
    }

    std::cout << "\n -- Set order id -- " << std::endl;
    m.prepareResults();
    m.showAverageValues( std::cout );
    m.rewind();

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        order.rewind( sendingTimeLength );
        m.startCapture();
        order.append<Price>( of.price, 6 );
        m.stopCapture();
    }

    std::cout << "\n -- Set price -- " << std::endl;
    m.prepareResults();
    m.showAverageValues( std::cout );
    m.rewind();

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        order.rewind( sendingTimeLength );
        m.startCapture();
        order.append<OrderQty>( of.qty );
        m.stopCapture();
    }

    std::cout << "\n -- Set qty -- " << std::endl;
    m.prepareResults();
    m.showAverageValues( std::cout );
    m.rewind();

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        order.rewind( sendingTimeLength );
        order.sendingTime.update();
        order.append<Account>( of.account, of.accountLen );
        order.append<ClOrdID>( of.orderId, of.orderIdLen );
        order.append<Symbol>( of.symbol, of.symbolLen );
        order.append<Side>( of.side );
        order.append<OrderQty>( of.qty );
        order.append<Price>( of.price, 6 );
        m.startCapture();
        order.setSeqnumAndUpdateHeaderAndChecksum(++seqnum);
        m.stopCapture();
    }

    std::cout << "\n -- setSeqnumAndUpdateHeaderAndChecksum -- " << std::endl;
    m.prepareResults();
    m.showAverageValues( std::cout );
    m.rewind();

    return 0;
}
