
// Generated


class MessageHeader: public MessageBase
{
  
// Methods

   public:
   static const char * getMessageName();
   static const std::string & getMessageType();
   offset_t scan( const char * fix, unsigned len );
   offset_t skip( const char * fix, unsigned len ) const;
   void reset();
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];

// Fields

   public:
   bool isSetBeginString() const { return fieldBeginString.offset >= 0; }
   FieldBeginString::ValueType getBeginString() const { return fieldBeginString.getValue( buf ); }
   const char * ptrToBeginString() const { return buf + fieldBeginString.offset; }
   private: FieldBeginString fieldBeginString;

   public:
   bool isSetBodyLength() const { return fieldBodyLength.offset >= 0; }
   FieldBodyLength::ValueType getBodyLength() const { return fieldBodyLength.getValue( buf ); }
   const char * ptrToBodyLength() const { return buf + fieldBodyLength.offset; }
   private: FieldBodyLength fieldBodyLength;

   public:
   bool isSetMsgType() const { return fieldMsgType.offset >= 0; }
   FieldMsgType::ValueType getMsgType() const { return fieldMsgType.getValue( buf ); }
   const char * ptrToMsgType() const { return buf + fieldMsgType.offset; }
   private: FieldMsgType fieldMsgType;

   public:
   bool isSetSenderCompID() const { return fieldSenderCompID.offset >= 0; }
   FieldSenderCompID::ValueType getSenderCompID() const { return fieldSenderCompID.getValue( buf ); }
   const char * ptrToSenderCompID() const { return buf + fieldSenderCompID.offset; }
   private: FieldSenderCompID fieldSenderCompID;

   public:
   bool isSetTargetCompID() const { return fieldTargetCompID.offset >= 0; }
   FieldTargetCompID::ValueType getTargetCompID() const { return fieldTargetCompID.getValue( buf ); }
   const char * ptrToTargetCompID() const { return buf + fieldTargetCompID.offset; }
   private: FieldTargetCompID fieldTargetCompID;

   public:
   bool isSetMsgSeqNum() const { return fieldMsgSeqNum.offset >= 0; }
   FieldMsgSeqNum::ValueType getMsgSeqNum() const { return fieldMsgSeqNum.getValue( buf ); }
   const char * ptrToMsgSeqNum() const { return buf + fieldMsgSeqNum.offset; }
   private: FieldMsgSeqNum fieldMsgSeqNum;

   public:
   bool isSetSendingTime() const { return fieldSendingTime.offset >= 0; }
   FieldSendingTime::ValueType getSendingTime() const { return fieldSendingTime.getValue( buf ); }
   const char * ptrToSendingTime() const { return buf + fieldSendingTime.offset; }
   private: FieldSendingTime fieldSendingTime;

 
   public:
   bool isSetCheckSum() const { return fieldCheckSum.offset >= 0; }
   FieldCheckSum::ValueType getCheckSum() const { return fieldCheckSum.getValue( buf ); }
   const char * ptrToCheckSum() const { return buf + fieldCheckSum.offset; }
   private: FieldCheckSum fieldCheckSum;
};

class MessageNewOrderSingle: public MessageBase
{
  
// Methods

   public:
   static const char * getMessageName();
   static const std::string & getMessageType();
   offset_t scan( const char * fix, unsigned len );
   offset_t skip( const char * fix, unsigned len ) const;
   void reset();
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];

// Fields

   public:
   bool isSetClOrdID() const { return fieldClOrdID.offset >= 0; }
   FieldClOrdID::ValueType getClOrdID() const { return fieldClOrdID.getValue( buf ); }
   const char * ptrToClOrdID() const { return buf + fieldClOrdID.offset; }
   private: FieldClOrdID fieldClOrdID;

   public:
   bool isSetAccount() const { return fieldAccount.offset >= 0; }
   FieldAccount::ValueType getAccount() const { return fieldAccount.getValue( buf ); }
   const char * ptrToAccount() const { return buf + fieldAccount.offset; }
   private: FieldAccount fieldAccount;

   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetQtyType() const { return fieldQtyType.offset >= 0; }
   FieldQtyType::ValueType getQtyType() const { return fieldQtyType.getValue( buf ); }
   const char * ptrToQtyType() const { return buf + fieldQtyType.offset; }
   private: FieldQtyType fieldQtyType;

   public:
   bool isSetOrderQty() const { return fieldOrderQty.offset >= 0; }
   FieldOrderQty::ValueType getOrderQty() const { return fieldOrderQty.getValue( buf ); }
   const char * ptrToOrderQty() const { return buf + fieldOrderQty.offset; }
   private: FieldOrderQty fieldOrderQty;

   public:
   bool isSetOrdType() const { return fieldOrdType.offset >= 0; }
   FieldOrdType::ValueType getOrdType() const { return fieldOrdType.getValue( buf ); }
   const char * ptrToOrdType() const { return buf + fieldOrdType.offset; }
   private: FieldOrdType fieldOrdType;

   public:
   bool isSetPrice() const { return fieldPrice.offset >= 0; }
   FieldPrice::ValueType getPrice() const { return fieldPrice.getValue( buf ); }
   const char * ptrToPrice() const { return buf + fieldPrice.offset; }
   private: FieldPrice fieldPrice;

   public:
   bool isSetStopPx() const { return fieldStopPx.offset >= 0; }
   FieldStopPx::ValueType getStopPx() const { return fieldStopPx.getValue( buf ); }
   const char * ptrToStopPx() const { return buf + fieldStopPx.offset; }
   private: FieldStopPx fieldStopPx;

   public:
   bool isSetTransactTime() const { return fieldTransactTime.offset >= 0; }
   FieldTransactTime::ValueType getTransactTime() const { return fieldTransactTime.getValue( buf ); }
   const char * ptrToTransactTime() const { return buf + fieldTransactTime.offset; }
   private: FieldTransactTime fieldTransactTime;

 
   public:
   bool isSetCheckSum() const { return fieldCheckSum.offset >= 0; }
   FieldCheckSum::ValueType getCheckSum() const { return fieldCheckSum.getValue( buf ); }
   const char * ptrToCheckSum() const { return buf + fieldCheckSum.offset; }
   private: FieldCheckSum fieldCheckSum;
};

class MessageExecutionReport: public MessageBase
{
  
// Methods

   public:
   static const char * getMessageName();
   static const std::string & getMessageType();
   offset_t scan( const char * fix, unsigned len );
   offset_t skip( const char * fix, unsigned len ) const;
   void reset();
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];

// Fields

   public:
   bool isSetOrderID() const { return fieldOrderID.offset >= 0; }
   FieldOrderID::ValueType getOrderID() const { return fieldOrderID.getValue( buf ); }
   const char * ptrToOrderID() const { return buf + fieldOrderID.offset; }
   private: FieldOrderID fieldOrderID;

   public:
   bool isSetClOrdID() const { return fieldClOrdID.offset >= 0; }
   FieldClOrdID::ValueType getClOrdID() const { return fieldClOrdID.getValue( buf ); }
   const char * ptrToClOrdID() const { return buf + fieldClOrdID.offset; }
   private: FieldClOrdID fieldClOrdID;

   public:
   bool isSetOrigClOrdID() const { return fieldOrigClOrdID.offset >= 0; }
   FieldOrigClOrdID::ValueType getOrigClOrdID() const { return fieldOrigClOrdID.getValue( buf ); }
   const char * ptrToOrigClOrdID() const { return buf + fieldOrigClOrdID.offset; }
   private: FieldOrigClOrdID fieldOrigClOrdID;

   public:
   bool isSetExecID() const { return fieldExecID.offset >= 0; }
   FieldExecID::ValueType getExecID() const { return fieldExecID.getValue( buf ); }
   const char * ptrToExecID() const { return buf + fieldExecID.offset; }
   private: FieldExecID fieldExecID;

   public:
   bool isSetExecType() const { return fieldExecType.offset >= 0; }
   FieldExecType::ValueType getExecType() const { return fieldExecType.getValue( buf ); }
   const char * ptrToExecType() const { return buf + fieldExecType.offset; }
   private: FieldExecType fieldExecType;

   public:
   bool isSetOrdStatus() const { return fieldOrdStatus.offset >= 0; }
   FieldOrdStatus::ValueType getOrdStatus() const { return fieldOrdStatus.getValue( buf ); }
   const char * ptrToOrdStatus() const { return buf + fieldOrdStatus.offset; }
   private: FieldOrdStatus fieldOrdStatus;

   public:
   bool isSetOrdRejReason() const { return fieldOrdRejReason.offset >= 0; }
   FieldOrdRejReason::ValueType getOrdRejReason() const { return fieldOrdRejReason.getValue( buf ); }
   const char * ptrToOrdRejReason() const { return buf + fieldOrdRejReason.offset; }
   private: FieldOrdRejReason fieldOrdRejReason;

   public:
   bool isSetAccount() const { return fieldAccount.offset >= 0; }
   FieldAccount::ValueType getAccount() const { return fieldAccount.getValue( buf ); }
   const char * ptrToAccount() const { return buf + fieldAccount.offset; }
   private: FieldAccount fieldAccount;

   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetText() const { return fieldText.offset >= 0; }
   FieldText::ValueType getText() const { return fieldText.getValue( buf ); }
   const char * ptrToText() const { return buf + fieldText.offset; }
   private: FieldText fieldText;

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetQtyType() const { return fieldQtyType.offset >= 0; }
   FieldQtyType::ValueType getQtyType() const { return fieldQtyType.getValue( buf ); }
   const char * ptrToQtyType() const { return buf + fieldQtyType.offset; }
   private: FieldQtyType fieldQtyType;

   public:
   bool isSetOrderQty() const { return fieldOrderQty.offset >= 0; }
   FieldOrderQty::ValueType getOrderQty() const { return fieldOrderQty.getValue( buf ); }
   const char * ptrToOrderQty() const { return buf + fieldOrderQty.offset; }
   private: FieldOrderQty fieldOrderQty;

   public:
   bool isSetOrdType() const { return fieldOrdType.offset >= 0; }
   FieldOrdType::ValueType getOrdType() const { return fieldOrdType.getValue( buf ); }
   const char * ptrToOrdType() const { return buf + fieldOrdType.offset; }
   private: FieldOrdType fieldOrdType;

   public:
   bool isSetPriceType() const { return fieldPriceType.offset >= 0; }
   FieldPriceType::ValueType getPriceType() const { return fieldPriceType.getValue( buf ); }
   const char * ptrToPriceType() const { return buf + fieldPriceType.offset; }
   private: FieldPriceType fieldPriceType;

   public:
   bool isSetPrice() const { return fieldPrice.offset >= 0; }
   FieldPrice::ValueType getPrice() const { return fieldPrice.getValue( buf ); }
   const char * ptrToPrice() const { return buf + fieldPrice.offset; }
   private: FieldPrice fieldPrice;

   public:
   bool isSetStopPx() const { return fieldStopPx.offset >= 0; }
   FieldStopPx::ValueType getStopPx() const { return fieldStopPx.getValue( buf ); }
   const char * ptrToStopPx() const { return buf + fieldStopPx.offset; }
   private: FieldStopPx fieldStopPx;

   public:
   bool isSetCurrency() const { return fieldCurrency.offset >= 0; }
   FieldCurrency::ValueType getCurrency() const { return fieldCurrency.getValue( buf ); }
   const char * ptrToCurrency() const { return buf + fieldCurrency.offset; }
   private: FieldCurrency fieldCurrency;

   public:
   bool isSetTimeInForce() const { return fieldTimeInForce.offset >= 0; }
   FieldTimeInForce::ValueType getTimeInForce() const { return fieldTimeInForce.getValue( buf ); }
   const char * ptrToTimeInForce() const { return buf + fieldTimeInForce.offset; }
   private: FieldTimeInForce fieldTimeInForce;

   public:
   bool isSetExecInst() const { return fieldExecInst.offset >= 0; }
   FieldExecInst::ValueType getExecInst() const { return fieldExecInst.getValue( buf ); }
   const char * ptrToExecInst() const { return buf + fieldExecInst.offset; }
   private: FieldExecInst fieldExecInst;

   public:
   bool isSetLastQty() const { return fieldLastQty.offset >= 0; }
   FieldLastQty::ValueType getLastQty() const { return fieldLastQty.getValue( buf ); }
   const char * ptrToLastQty() const { return buf + fieldLastQty.offset; }
   private: FieldLastQty fieldLastQty;

   public:
   bool isSetLastPx() const { return fieldLastPx.offset >= 0; }
   FieldLastPx::ValueType getLastPx() const { return fieldLastPx.getValue( buf ); }
   const char * ptrToLastPx() const { return buf + fieldLastPx.offset; }
   private: FieldLastPx fieldLastPx;

   public:
   bool isSetLeavesQty() const { return fieldLeavesQty.offset >= 0; }
   FieldLeavesQty::ValueType getLeavesQty() const { return fieldLeavesQty.getValue( buf ); }
   const char * ptrToLeavesQty() const { return buf + fieldLeavesQty.offset; }
   private: FieldLeavesQty fieldLeavesQty;

   public:
   bool isSetAvgPx() const { return fieldAvgPx.offset >= 0; }
   FieldAvgPx::ValueType getAvgPx() const { return fieldAvgPx.getValue( buf ); }
   const char * ptrToAvgPx() const { return buf + fieldAvgPx.offset; }
   private: FieldAvgPx fieldAvgPx;

   public:
   bool isSetCumQty() const { return fieldCumQty.offset >= 0; }
   FieldCumQty::ValueType getCumQty() const { return fieldCumQty.getValue( buf ); }
   const char * ptrToCumQty() const { return buf + fieldCumQty.offset; }
   private: FieldCumQty fieldCumQty;

   public:
   bool isSetNoLegs() const { return fieldNoLegs.offset >= 0; }
   FieldNoLegs::ValueType getNoLegs() const { return fieldNoLegs.getValue( buf ); }
   const char * ptrToNoLegs() const { return buf + fieldNoLegs.offset; }
   private: FieldNoLegs fieldNoLegs;
  
   public:
   size_t getGroupCountLegs() const { return groupsLegs.size(); } 
   const GroupLegs & getGroupLegs( size_t idx ) const { return groupsLegs[ idx ]; } 
   private: GroupLegs::Array groupsLegs{ 10 };

 
   public:
   bool isSetCheckSum() const { return fieldCheckSum.offset >= 0; }
   FieldCheckSum::ValueType getCheckSum() const { return fieldCheckSum.getValue( buf ); }
   const char * ptrToCheckSum() const { return buf + fieldCheckSum.offset; }
   private: FieldCheckSum fieldCheckSum;
};


class ParserDispatcher
{
   public:

     virtual const char * parseAndDipatch( const char * buf, unsigned len, bool resetMessage = true );

   protected:

     ParserDispatcher();

     virtual ~ParserDispatcher() = 0;

     virtual void onUnknownMessage( raw_enum_t msgType );

     virtual bool ignoreMessage( raw_enum_t msgType ) const;

     virtual void unprocessedMessage( raw_enum_t msgType, MessageBase & msg );

     inline MessageHeader & getCurrentHeader() { return _msgHeader; }

     
// dispatching
 
// onHeader will never be called


     virtual void onMessage( MessageHeader & msg );


     virtual void onMessage( MessageNewOrderSingle & msg );


     virtual void onMessage( MessageExecutionReport & msg );


   private:


     MessageHeader _msgHeader;


     MessageNewOrderSingle _msgNewOrderSingle;


     MessageExecutionReport _msgExecutionReport;


};


// -------------------------------------- convenience message namespace ----------------------------------------
namespace message
{

typedef MessageHeader Header;


typedef MessageNewOrderSingle NewOrderSingle;


typedef MessageExecutionReport ExecutionReport;


}
