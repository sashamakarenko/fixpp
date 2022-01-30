#include <tiny/SenderApi.h>
#include <pe/Measurement.h>

using namespace tiny;

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
    { "OID123452223", 12, "GBP/USD", 7, "TRADER7", 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 10000  , 1.30 },
    { "OID123455454", 12, "EUR/USD", 7, "TRADER7", 7, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 2000000, 1.20 },
    { "OID123454100", 12, "GBP/USD", 7, "TRADER7", 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 250000 , 1.31 },
    { "OID123454175", 12, "GBP/EUR", 7, "TRADER7", 7, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 4000000, 1.21 },
    { "OID123457117", 12, "GBP/USD", 7, "TRADER7", 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 10000  , 1.30 },
    { "OID123452234", 12, "EUR/USD", 7, "TRADER7", 7, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 2000000, 1.20 },
    { "OID155258100", 12, "GBP/USD", 7, "TRADER7", 7, SideEnums::BUY.value , OrdTypeEnums::LIMIT.value, 250000 , 1.31 },
    { "OID123451234", 12, "GBP/EUR", 7, "TRADER7", 7, SideEnums::SELL.value, OrdTypeEnums::FOREX.value, 50000  , 1.21 },
    {}
};

struct ForexNewOrderSingle: public ReusableMessageBuilder
{
    ForexNewOrderSingle(): ReusableMessageBuilder( MessageNewOrderSingle::getMessageType(), 512, 128 ){}
    
    template< typename FIELD >
    unsigned getOffset() const
    {
        return ( end - begin ) + FIELD::INSERTABLE_TAG_WIDTH;
    }

    unsigned accountOffset, orderIdOffset, symbolOffset, sideOffset, transactTimeOffset, ordTypeOffset, orderQtyOffset;
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
    m.initialize( 100 );

    ForexNewOrderSingle order;
    order.header.append<FieldSenderCompID>("ASENDER");
    order.header.append<FieldTargetCompID>("ATARGET");
    order.header.pushTag<FieldMsgSeqNum>();
    order.header.finalize();

    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_SECONDS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::SECONDS;
    auto constexpr tsLen  = TimestampKeeper::DATE_TIME_MILLIS_LENGTH;
    auto constexpr tsFrac = TimestampKeeper::Precision::MILLISECONDS;
    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_MICROS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::MICROSECONDS;
    //auto constexpr tsLen  = TimestampKeeper::DATE_TIME_NANOS_LENGTH;
    //auto constexpr tsFrac = TimestampKeeper::Precision::NANOSECONDS;
    order.append<FieldSendingTime>( TimestampKeeper::PLACE_HOLDER, tsLen );
    order.sendingTime.setup( order.end - tsLen, tsFrac );
    order.sendingTime.update();
    const unsigned sendingTimeLength = order.end - order.begin;

    unsigned seqnum = 1000;
    // build order template
    {
        const OrderFields & of = orders[0];
        order.rewind( sendingTimeLength );
        order.sendingTime.update();

        // fixed width fields
        order.accountOffset = order.getOffset<FieldAccount>();
        order.append<FieldAccount>( of.account, of.accountLen );

        order.orderIdOffset = order.getOffset<FieldClOrdID>();
        order.append<FieldClOrdID>( of.orderId, of.orderIdLen );

        order.symbolOffset = order.getOffset<FieldSymbol>();
        order.append<FieldSymbol>( of.symbol, of.symbolLen );

        order.sideOffset = order.getOffset<FieldSide>();
        order.append<FieldSide>( of.side );

        order.transactTimeOffset = order.getOffset<FieldTransactTime>();
        order.append<FieldTransactTime>( order.sendingTime.begin, tsLen );

        order.ordTypeOffset = order.getOffset<FieldOrdType>();
        order.append<FieldOrdType>( of.type );

        // changing width fields
        order.orderQtyOffset = order.getOffset<FieldOrderQty>();
        order.append<FieldOrderQty>( of.qty );

        order.append<FieldPrice>( of.price, 6 );
        order.setSeqnumAndUpdateHeaderAndChecksum(++seqnum);
        std::cout << fixstr( order.start, ttyRgbStyle ) << std::endl;
    }

    // check it
    {
        const OrderFields & of = orders[1];
        order.sendingTime.update();

        // fixed width fields
        memcpy( order.begin + order.accountOffset, of.account, of.accountLen );
        memcpy( order.begin + order.orderIdOffset, of.orderId, of.orderIdLen );
        memcpy( order.begin + order.symbolOffset , of.symbol, of.symbolLen );
        order.begin[order.sideOffset] = of.side;
        memcpy( order.begin + order.transactTimeOffset, order.sendingTime.begin, tsLen );
        order.begin[order.ordTypeOffset] = of.type;

        // changing width fields
        order.rewind( order.orderQtyOffset );
        order.pushValue( of.qty );
        order.append<FieldPrice>( of.price, 6 );
        order.setSeqnumAndUpdateHeaderAndChecksum(seqnum);
        std::cout << fixstr( order.start, ttyRgbStyle ) << std::endl;
    }

    for( int i = 0; i < m.getMaxCaptures(); ++i )
    {
        const OrderFields & of = orders[ i % 8 ];
        m.startCapture();
        order.sendingTime.update();
        memcpy( order.begin + order.accountOffset, of.account, of.accountLen );
        memcpy( order.begin + order.orderIdOffset, of.orderId, of.orderIdLen );
        memcpy( order.begin + order.symbolOffset, of.symbol, of.symbolLen );
        order.begin[order.sideOffset] = of.side;
        memcpy( order.begin + order.transactTimeOffset, order.sendingTime.begin, tsLen );
        order.begin[order.ordTypeOffset] = of.type;
        order.rewind( order.orderQtyOffset );
        order.pushValue( of.qty );
        order.append<FieldPrice>( of.price, 6 );
        order.setSeqnumAndUpdateHeaderAndChecksum(seqnum);
        m.stopCapture();
    }

    /*
    i9-9900K @ 5GHz
    -------------
    cpu.cycles:	303
    hw.instrs:	821
    br.instrs:	90
    cch.ll.rmiss:	0
    br.misses:	1
    */
    std::cout << "\n -- Build order -- " << std::endl;
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    return 0;
}
