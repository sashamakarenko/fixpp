#include <vector>
#include <set>

#include <order/Messages.h>

namespace order
{

// start of Messages.cxx

// Generated

// -------------------------- getMessageName getMessageType -------------------------

const std::string EMPTY_STRING;

const char * MessageHeader::getMessageName(){
     return "Header";
}

const std::string & MessageHeader::getMessageType(){
     return EMPTY_STRING;
}


const char * MessageNewOrderSingle::getMessageName(){
     return "NewOrderSingle";
}

const std::string & MessageNewOrderSingle::getMessageType(){
     return MsgTypeEnums::ORDER_SINGLE.str;
}


const char * MessageExecutionReport::getMessageName(){
     return "ExecutionReport";
}

const std::string & MessageExecutionReport::getMessageType(){
     return MsgTypeEnums::EXECUTION_REPORT.str;
}


// -------------------------------------- scan ----------------------------------------

offset_t MessageHeader::scan( const char * fix, unsigned len ){
buf = fix; 
offset_t prev = 0, pos = 0; 
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldBeginString::RAW :
     FIXPP_PRINT_FIELD(BeginString) 
     fieldBeginString.offset = pos;
     break;

   case FieldBodyLength::RAW :
     FIXPP_PRINT_FIELD(BodyLength) 
     fieldBodyLength.offset = pos;
     break;

   case FieldMsgType::RAW :
     FIXPP_PRINT_FIELD(MsgType) 
     fieldMsgType.offset = pos;
     break;

   case FieldSenderCompID::RAW :
     FIXPP_PRINT_FIELD(SenderCompID) 
     fieldSenderCompID.offset = pos;
     break;

   case FieldTargetCompID::RAW :
     FIXPP_PRINT_FIELD(TargetCompID) 
     fieldTargetCompID.offset = pos;
     break;

   case FieldMsgSeqNum::RAW :
     FIXPP_PRINT_FIELD(MsgSeqNum) 
     fieldMsgSeqNum.offset = pos;
     break;

   case FieldSendingTime::RAW :
     FIXPP_PRINT_FIELD(SendingTime) 
     fieldSendingTime.offset = pos;
     break;

   case FieldCheckSum::RAW :
     FIXPP_PRINT_FIELD(CheckSum) 
     fieldCheckSum.offset = pos;
     gotoNextField( fix, pos );
     return pos; 

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}

offset_t MessageNewOrderSingle::scan( const char * fix, unsigned len ){
buf = fix; 
offset_t prev = 0, pos = 0; 
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldClOrdID::RAW :
     FIXPP_PRINT_FIELD(ClOrdID) 
     fieldClOrdID.offset = pos;
     break;

   case FieldAccount::RAW :
     FIXPP_PRINT_FIELD(Account) 
     fieldAccount.offset = pos;
     break;

   case FieldSymbol::RAW :
     FIXPP_PRINT_FIELD(Symbol) 
     fieldSymbol.offset = pos;
     break;

   case FieldSecurityID::RAW :
     FIXPP_PRINT_FIELD(SecurityID) 
     fieldSecurityID.offset = pos;
     break;

   case FieldSide::RAW :
     FIXPP_PRINT_FIELD(Side) 
     fieldSide.offset = pos;
     break;

   case FieldQtyType::RAW :
     FIXPP_PRINT_FIELD(QtyType) 
     fieldQtyType.offset = pos;
     break;

   case FieldOrderQty::RAW :
     FIXPP_PRINT_FIELD(OrderQty) 
     fieldOrderQty.offset = pos;
     break;

   case FieldOrdType::RAW :
     FIXPP_PRINT_FIELD(OrdType) 
     fieldOrdType.offset = pos;
     break;

   case FieldPrice::RAW :
     FIXPP_PRINT_FIELD(Price) 
     fieldPrice.offset = pos;
     break;

   case FieldStopPx::RAW :
     FIXPP_PRINT_FIELD(StopPx) 
     fieldStopPx.offset = pos;
     break;

   case FieldTransactTime::RAW :
     FIXPP_PRINT_FIELD(TransactTime) 
     fieldTransactTime.offset = pos;
     break;

   case FieldCheckSum::RAW :
     FIXPP_PRINT_FIELD(CheckSum) 
     fieldCheckSum.offset = pos;
     gotoNextField( fix, pos );
     return pos; 

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}

offset_t MessageExecutionReport::scan( const char * fix, unsigned len ){
buf = fix; 
offset_t prev = 0, pos = 0; 
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldOrderID::RAW :
     FIXPP_PRINT_FIELD(OrderID) 
     fieldOrderID.offset = pos;
     break;

   case FieldClOrdID::RAW :
     FIXPP_PRINT_FIELD(ClOrdID) 
     fieldClOrdID.offset = pos;
     break;

   case FieldOrigClOrdID::RAW :
     FIXPP_PRINT_FIELD(OrigClOrdID) 
     fieldOrigClOrdID.offset = pos;
     break;

   case FieldExecID::RAW :
     FIXPP_PRINT_FIELD(ExecID) 
     fieldExecID.offset = pos;
     break;

   case FieldExecType::RAW :
     FIXPP_PRINT_FIELD(ExecType) 
     fieldExecType.offset = pos;
     break;

   case FieldOrdStatus::RAW :
     FIXPP_PRINT_FIELD(OrdStatus) 
     fieldOrdStatus.offset = pos;
     break;

   case FieldOrdRejReason::RAW :
     FIXPP_PRINT_FIELD(OrdRejReason) 
     fieldOrdRejReason.offset = pos;
     break;

   case FieldAccount::RAW :
     FIXPP_PRINT_FIELD(Account) 
     fieldAccount.offset = pos;
     break;

   case FieldSymbol::RAW :
     FIXPP_PRINT_FIELD(Symbol) 
     fieldSymbol.offset = pos;
     break;

   case FieldSecurityID::RAW :
     FIXPP_PRINT_FIELD(SecurityID) 
     fieldSecurityID.offset = pos;
     break;

   case FieldSecurityType::RAW :
     FIXPP_PRINT_FIELD(SecurityType) 
     fieldSecurityType.offset = pos;
     break;

   case FieldText::RAW :
     FIXPP_PRINT_FIELD(Text) 
     fieldText.offset = pos;
     break;

   case FieldProduct::RAW :
     FIXPP_PRINT_FIELD(Product) 
     fieldProduct.offset = pos;
     break;

   case FieldSide::RAW :
     FIXPP_PRINT_FIELD(Side) 
     fieldSide.offset = pos;
     break;

   case FieldQtyType::RAW :
     FIXPP_PRINT_FIELD(QtyType) 
     fieldQtyType.offset = pos;
     break;

   case FieldOrderQty::RAW :
     FIXPP_PRINT_FIELD(OrderQty) 
     fieldOrderQty.offset = pos;
     break;

   case FieldOrdType::RAW :
     FIXPP_PRINT_FIELD(OrdType) 
     fieldOrdType.offset = pos;
     break;

   case FieldPriceType::RAW :
     FIXPP_PRINT_FIELD(PriceType) 
     fieldPriceType.offset = pos;
     break;

   case FieldPrice::RAW :
     FIXPP_PRINT_FIELD(Price) 
     fieldPrice.offset = pos;
     break;

   case FieldStopPx::RAW :
     FIXPP_PRINT_FIELD(StopPx) 
     fieldStopPx.offset = pos;
     break;

   case FieldCurrency::RAW :
     FIXPP_PRINT_FIELD(Currency) 
     fieldCurrency.offset = pos;
     break;

   case FieldTimeInForce::RAW :
     FIXPP_PRINT_FIELD(TimeInForce) 
     fieldTimeInForce.offset = pos;
     break;

   case FieldExecInst::RAW :
     FIXPP_PRINT_FIELD(ExecInst) 
     fieldExecInst.offset = pos;
     break;

   case FieldLastQty::RAW :
     FIXPP_PRINT_FIELD(LastQty) 
     fieldLastQty.offset = pos;
     break;

   case FieldLastPx::RAW :
     FIXPP_PRINT_FIELD(LastPx) 
     fieldLastPx.offset = pos;
     break;

   case FieldLeavesQty::RAW :
     FIXPP_PRINT_FIELD(LeavesQty) 
     fieldLeavesQty.offset = pos;
     break;

   case FieldAvgPx::RAW :
     FIXPP_PRINT_FIELD(AvgPx) 
     fieldAvgPx.offset = pos;
     break;

   case FieldCumQty::RAW :
     FIXPP_PRINT_FIELD(CumQty) 
     fieldCumQty.offset = pos;
     break;

   case FieldNoLegs::RAW :
     FIXPP_PRINT_FIELD(NoLegs) 
     fieldNoLegs.offset = pos;
     isGroupStart = true;
     gotoNextField( fix, pos );
     pos += GroupLegs::scan( groupsLegs, fix+pos, len - pos );
     break;

   case FieldCheckSum::RAW :
     FIXPP_PRINT_FIELD(CheckSum) 
     fieldCheckSum.offset = pos;
     gotoNextField( fix, pos );
     return pos; 

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}


// -------------------------------------- skip ----------------------------------------

offset_t MessageHeader::skip( const char * fix, unsigned len ) const
{
offset_t prev = 0, pos = 0; 
gotoNextField( fix, pos );
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldBeginString::RAW :
     break;

   case FieldBodyLength::RAW :
     break;

   case FieldMsgType::RAW :
     break;

   case FieldSenderCompID::RAW :
     break;

   case FieldTargetCompID::RAW :
     break;

   case FieldMsgSeqNum::RAW :
     break;

   case FieldSendingTime::RAW :
     break;

   case FieldCheckSum::RAW :
     gotoNextField( fix, pos );
     return pos;

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}

offset_t MessageNewOrderSingle::skip( const char * fix, unsigned len ) const
{
offset_t prev = 0, pos = 0; 
gotoNextField( fix, pos );
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldClOrdID::RAW :
     break;

   case FieldAccount::RAW :
     break;

   case FieldSymbol::RAW :
     break;

   case FieldSecurityID::RAW :
     break;

   case FieldSide::RAW :
     break;

   case FieldQtyType::RAW :
     break;

   case FieldOrderQty::RAW :
     break;

   case FieldOrdType::RAW :
     break;

   case FieldPrice::RAW :
     break;

   case FieldStopPx::RAW :
     break;

   case FieldTransactTime::RAW :
     break;

   case FieldCheckSum::RAW :
     gotoNextField( fix, pos );
     return pos;

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}

offset_t MessageExecutionReport::skip( const char * fix, unsigned len ) const
{
offset_t prev = 0, pos = 0; 
gotoNextField( fix, pos );
while( pos < (int)len ) {
   bool isGroupStart = false;
   prev = pos;
   raw_tag_t tag = nextRawTag( fix+pos, pos );
   switch( tag ){

   case FieldOrderID::RAW :
     break;

   case FieldClOrdID::RAW :
     break;

   case FieldOrigClOrdID::RAW :
     break;

   case FieldExecID::RAW :
     break;

   case FieldExecType::RAW :
     break;

   case FieldOrdStatus::RAW :
     break;

   case FieldOrdRejReason::RAW :
     break;

   case FieldAccount::RAW :
     break;

   case FieldSymbol::RAW :
     break;

   case FieldSecurityID::RAW :
     break;

   case FieldSecurityType::RAW :
     break;

   case FieldText::RAW :
     break;

   case FieldProduct::RAW :
     break;

   case FieldSide::RAW :
     break;

   case FieldQtyType::RAW :
     break;

   case FieldOrderQty::RAW :
     break;

   case FieldOrdType::RAW :
     break;

   case FieldPriceType::RAW :
     break;

   case FieldPrice::RAW :
     break;

   case FieldStopPx::RAW :
     break;

   case FieldCurrency::RAW :
     break;

   case FieldTimeInForce::RAW :
     break;

   case FieldExecInst::RAW :
     break;

   case FieldLastQty::RAW :
     break;

   case FieldLastPx::RAW :
     break;

   case FieldLeavesQty::RAW :
     break;

   case FieldAvgPx::RAW :
     break;

   case FieldCumQty::RAW :
     break;

   case FieldNoLegs::RAW :
     isGroupStart = true;
     gotoNextField( fix, pos );
     pos += GroupLegs::skip( fix+pos, len - pos );
     break;

   case FieldCheckSum::RAW :
     gotoNextField( fix, pos );
     return pos;

   default: FIXPP_PRINT_UNKNOWN_FIELD
     return prev;
   }
   if( ! isGroupStart ) gotoNextField( fix, pos );
 }
 return pos;
}


// ---------------------------------- fields ---------------------------------

GetDepthMethod MessageHeader::groupGetDepthMethods[] = {
  nullptr };

GetDepthMethod MessageNewOrderSingle::groupGetDepthMethods[] = {
  nullptr };

GetDepthMethod MessageExecutionReport::groupGetDepthMethods[] = {
  GroupLegs::getFieldDepth,
  nullptr };


FieldDepth MessageHeader::getFieldDepth( raw_tag_t tag ){
   FieldDepth ret;
   switch( tag ){
     case FieldBeginString::RAW :
     case FieldBodyLength::RAW :
     case FieldMsgType::RAW :
     case FieldSenderCompID::RAW :
     case FieldTargetCompID::RAW :
     case FieldMsgSeqNum::RAW :
     case FieldSendingTime::RAW :
     case FieldCheckSum::RAW :
     ret.depth = 0; 
     return ret; 
   }
   for( auto m : groupGetDepthMethods ) if( m ){
     FieldDepth gdepth = (*m)( tag ); 
     if( gdepth.depth >= 0 ) { return gdepth.inc(); }
   }
   return ret;
}

FieldDepth MessageNewOrderSingle::getFieldDepth( raw_tag_t tag ){
   FieldDepth ret;
   switch( tag ){
     case FieldClOrdID::RAW :
     case FieldAccount::RAW :
     case FieldSymbol::RAW :
     case FieldSecurityID::RAW :
     case FieldSide::RAW :
     case FieldQtyType::RAW :
     case FieldOrderQty::RAW :
     case FieldOrdType::RAW :
     case FieldPrice::RAW :
     case FieldStopPx::RAW :
     case FieldTransactTime::RAW :
     case FieldCheckSum::RAW :
     ret.depth = 0; 
     return ret; 
   }
   for( auto m : groupGetDepthMethods ) if( m ){
     FieldDepth gdepth = (*m)( tag ); 
     if( gdepth.depth >= 0 ) { return gdepth.inc(); }
   }
   return ret;
}

FieldDepth MessageExecutionReport::getFieldDepth( raw_tag_t tag ){
   FieldDepth ret;
   switch( tag ){
     case FieldOrderID::RAW :
     case FieldClOrdID::RAW :
     case FieldOrigClOrdID::RAW :
     case FieldExecID::RAW :
     case FieldExecType::RAW :
     case FieldOrdStatus::RAW :
     case FieldOrdRejReason::RAW :
     case FieldAccount::RAW :
     case FieldSymbol::RAW :
     case FieldSecurityID::RAW :
     case FieldSecurityType::RAW :
     case FieldText::RAW :
     case FieldProduct::RAW :
     case FieldSide::RAW :
     case FieldQtyType::RAW :
     case FieldOrderQty::RAW :
     case FieldOrdType::RAW :
     case FieldPriceType::RAW :
     case FieldPrice::RAW :
     case FieldStopPx::RAW :
     case FieldCurrency::RAW :
     case FieldTimeInForce::RAW :
     case FieldExecInst::RAW :
     case FieldLastQty::RAW :
     case FieldLastPx::RAW :
     case FieldLeavesQty::RAW :
     case FieldAvgPx::RAW :
     case FieldCumQty::RAW :
     case FieldNoLegs::RAW :
     case FieldCheckSum::RAW :
     ret.depth = 0; 
     return ret; 
   }
   for( auto m : groupGetDepthMethods ) if( m ){
     FieldDepth gdepth = (*m)( tag ); 
     if( gdepth.depth >= 0 ) { return gdepth.inc(); }
   }
   return ret;
}


const char * MessageHeader::getFieldValue( unsigned tag ) const {
   if( buf == nullptr ) return nullptr;
   switch( tag ){
     case FieldBeginString::KEY : return fieldBeginString.offset >= 0 ? buf + fieldBeginString.offset : nullptr;
     case FieldBodyLength::KEY : return fieldBodyLength.offset >= 0 ? buf + fieldBodyLength.offset : nullptr;
     case FieldMsgType::KEY : return fieldMsgType.offset >= 0 ? buf + fieldMsgType.offset : nullptr;
     case FieldSenderCompID::KEY : return fieldSenderCompID.offset >= 0 ? buf + fieldSenderCompID.offset : nullptr;
     case FieldTargetCompID::KEY : return fieldTargetCompID.offset >= 0 ? buf + fieldTargetCompID.offset : nullptr;
     case FieldMsgSeqNum::KEY : return fieldMsgSeqNum.offset >= 0 ? buf + fieldMsgSeqNum.offset : nullptr;
     case FieldSendingTime::KEY : return fieldSendingTime.offset >= 0 ? buf + fieldSendingTime.offset : nullptr;
     case FieldCheckSum::KEY : return fieldCheckSum.offset >= 0 ? buf + fieldCheckSum.offset : nullptr; 
     default : return nullptr; 
   }
   return nullptr;
}

const char * MessageNewOrderSingle::getFieldValue( unsigned tag ) const {
   if( buf == nullptr ) return nullptr;
   switch( tag ){
     case FieldClOrdID::KEY : return fieldClOrdID.offset >= 0 ? buf + fieldClOrdID.offset : nullptr;
     case FieldAccount::KEY : return fieldAccount.offset >= 0 ? buf + fieldAccount.offset : nullptr;
     case FieldSymbol::KEY : return fieldSymbol.offset >= 0 ? buf + fieldSymbol.offset : nullptr;
     case FieldSecurityID::KEY : return fieldSecurityID.offset >= 0 ? buf + fieldSecurityID.offset : nullptr;
     case FieldSide::KEY : return fieldSide.offset >= 0 ? buf + fieldSide.offset : nullptr;
     case FieldQtyType::KEY : return fieldQtyType.offset >= 0 ? buf + fieldQtyType.offset : nullptr;
     case FieldOrderQty::KEY : return fieldOrderQty.offset >= 0 ? buf + fieldOrderQty.offset : nullptr;
     case FieldOrdType::KEY : return fieldOrdType.offset >= 0 ? buf + fieldOrdType.offset : nullptr;
     case FieldPrice::KEY : return fieldPrice.offset >= 0 ? buf + fieldPrice.offset : nullptr;
     case FieldStopPx::KEY : return fieldStopPx.offset >= 0 ? buf + fieldStopPx.offset : nullptr;
     case FieldTransactTime::KEY : return fieldTransactTime.offset >= 0 ? buf + fieldTransactTime.offset : nullptr;
     case FieldCheckSum::KEY : return fieldCheckSum.offset >= 0 ? buf + fieldCheckSum.offset : nullptr; 
     default : return nullptr; 
   }
   return nullptr;
}

const char * MessageExecutionReport::getFieldValue( unsigned tag ) const {
   if( buf == nullptr ) return nullptr;
   switch( tag ){
     case FieldOrderID::KEY : return fieldOrderID.offset >= 0 ? buf + fieldOrderID.offset : nullptr;
     case FieldClOrdID::KEY : return fieldClOrdID.offset >= 0 ? buf + fieldClOrdID.offset : nullptr;
     case FieldOrigClOrdID::KEY : return fieldOrigClOrdID.offset >= 0 ? buf + fieldOrigClOrdID.offset : nullptr;
     case FieldExecID::KEY : return fieldExecID.offset >= 0 ? buf + fieldExecID.offset : nullptr;
     case FieldExecType::KEY : return fieldExecType.offset >= 0 ? buf + fieldExecType.offset : nullptr;
     case FieldOrdStatus::KEY : return fieldOrdStatus.offset >= 0 ? buf + fieldOrdStatus.offset : nullptr;
     case FieldOrdRejReason::KEY : return fieldOrdRejReason.offset >= 0 ? buf + fieldOrdRejReason.offset : nullptr;
     case FieldAccount::KEY : return fieldAccount.offset >= 0 ? buf + fieldAccount.offset : nullptr;
     case FieldSymbol::KEY : return fieldSymbol.offset >= 0 ? buf + fieldSymbol.offset : nullptr;
     case FieldSecurityID::KEY : return fieldSecurityID.offset >= 0 ? buf + fieldSecurityID.offset : nullptr;
     case FieldSecurityType::KEY : return fieldSecurityType.offset >= 0 ? buf + fieldSecurityType.offset : nullptr;
     case FieldText::KEY : return fieldText.offset >= 0 ? buf + fieldText.offset : nullptr;
     case FieldProduct::KEY : return fieldProduct.offset >= 0 ? buf + fieldProduct.offset : nullptr;
     case FieldSide::KEY : return fieldSide.offset >= 0 ? buf + fieldSide.offset : nullptr;
     case FieldQtyType::KEY : return fieldQtyType.offset >= 0 ? buf + fieldQtyType.offset : nullptr;
     case FieldOrderQty::KEY : return fieldOrderQty.offset >= 0 ? buf + fieldOrderQty.offset : nullptr;
     case FieldOrdType::KEY : return fieldOrdType.offset >= 0 ? buf + fieldOrdType.offset : nullptr;
     case FieldPriceType::KEY : return fieldPriceType.offset >= 0 ? buf + fieldPriceType.offset : nullptr;
     case FieldPrice::KEY : return fieldPrice.offset >= 0 ? buf + fieldPrice.offset : nullptr;
     case FieldStopPx::KEY : return fieldStopPx.offset >= 0 ? buf + fieldStopPx.offset : nullptr;
     case FieldCurrency::KEY : return fieldCurrency.offset >= 0 ? buf + fieldCurrency.offset : nullptr;
     case FieldTimeInForce::KEY : return fieldTimeInForce.offset >= 0 ? buf + fieldTimeInForce.offset : nullptr;
     case FieldExecInst::KEY : return fieldExecInst.offset >= 0 ? buf + fieldExecInst.offset : nullptr;
     case FieldLastQty::KEY : return fieldLastQty.offset >= 0 ? buf + fieldLastQty.offset : nullptr;
     case FieldLastPx::KEY : return fieldLastPx.offset >= 0 ? buf + fieldLastPx.offset : nullptr;
     case FieldLeavesQty::KEY : return fieldLeavesQty.offset >= 0 ? buf + fieldLeavesQty.offset : nullptr;
     case FieldAvgPx::KEY : return fieldAvgPx.offset >= 0 ? buf + fieldAvgPx.offset : nullptr;
     case FieldCumQty::KEY : return fieldCumQty.offset >= 0 ? buf + fieldCumQty.offset : nullptr;
     case FieldNoLegs::KEY : return fieldNoLegs.offset >= 0 ? buf + fieldNoLegs.offset : nullptr;
     case FieldCheckSum::KEY : return fieldCheckSum.offset >= 0 ? buf + fieldCheckSum.offset : nullptr; 
     default : return nullptr; 
   }
   return nullptr;
}


namespace {

const std::vector<tag_t> Header_knownFields = {
FieldBeginString::KEY,
FieldBodyLength::KEY,
FieldMsgType::KEY,
FieldSenderCompID::KEY,
FieldTargetCompID::KEY,
FieldMsgSeqNum::KEY,
FieldSendingTime::KEY,
FieldCheckSum::KEY };

const std::vector<tag_t> NewOrderSingle_knownFields = {
FieldClOrdID::KEY,
FieldAccount::KEY,
FieldSymbol::KEY,
FieldSecurityID::KEY,
FieldSide::KEY,
FieldQtyType::KEY,
FieldOrderQty::KEY,
FieldOrdType::KEY,
FieldPrice::KEY,
FieldStopPx::KEY,
FieldTransactTime::KEY,
FieldCheckSum::KEY };

const std::vector<tag_t> ExecutionReport_knownFields = {
FieldOrderID::KEY,
FieldClOrdID::KEY,
FieldOrigClOrdID::KEY,
FieldExecID::KEY,
FieldExecType::KEY,
FieldOrdStatus::KEY,
FieldOrdRejReason::KEY,
FieldAccount::KEY,
FieldSymbol::KEY,
FieldSecurityID::KEY,
FieldSecurityType::KEY,
FieldText::KEY,
FieldProduct::KEY,
FieldSide::KEY,
FieldQtyType::KEY,
FieldOrderQty::KEY,
FieldOrdType::KEY,
FieldPriceType::KEY,
FieldPrice::KEY,
FieldStopPx::KEY,
FieldCurrency::KEY,
FieldTimeInForce::KEY,
FieldExecInst::KEY,
FieldLastQty::KEY,
FieldLastPx::KEY,
FieldLeavesQty::KEY,
FieldAvgPx::KEY,
FieldCumQty::KEY,
FieldNoLegs::KEY,
FieldCheckSum::KEY };

}


const std::vector<tag_t> & MessageHeader::getKnownFields(){ return Header_knownFields; }

const std::vector<tag_t> & MessageNewOrderSingle::getKnownFields(){ return NewOrderSingle_knownFields; }

const std::vector<tag_t> & MessageExecutionReport::getKnownFields(){ return ExecutionReport_knownFields; }


GetDepthMethod getTagDepthMethodByRawMsgType( raw_enum_t rawMsgType ){
  switch( rawMsgType ){

   case MsgTypeRaw__ :
     return MessageHeader::getFieldDepth;

   case MsgTypeRaw_ORDER_SINGLE :
     return MessageNewOrderSingle::getFieldDepth;

   case MsgTypeRaw_EXECUTION_REPORT :
     return MessageExecutionReport::getFieldDepth;
  }
  return nullptr;
}


// -------------------------------------- reset ----------------------------------------

void MessageHeader::reset(){
     buf = nullptr;
     fieldBeginString.offset = -1;
     fieldBodyLength.offset = -1;
     fieldMsgType.offset = -1;
     fieldSenderCompID.offset = -1;
     fieldTargetCompID.offset = -1;
     fieldMsgSeqNum.offset = -1;
     fieldSendingTime.offset = -1;
     fieldCheckSum.offset = -1;
}

void MessageNewOrderSingle::reset(){
     buf = nullptr;
     fieldClOrdID.offset = -1;
     fieldAccount.offset = -1;
     fieldSymbol.offset = -1;
     fieldSecurityID.offset = -1;
     fieldSide.offset = -1;
     fieldQtyType.offset = -1;
     fieldOrderQty.offset = -1;
     fieldOrdType.offset = -1;
     fieldPrice.offset = -1;
     fieldStopPx.offset = -1;
     fieldTransactTime.offset = -1;
     fieldCheckSum.offset = -1;
}

void MessageExecutionReport::reset(){
     buf = nullptr;
     fieldOrderID.offset = -1;
     fieldClOrdID.offset = -1;
     fieldOrigClOrdID.offset = -1;
     fieldExecID.offset = -1;
     fieldExecType.offset = -1;
     fieldOrdStatus.offset = -1;
     fieldOrdRejReason.offset = -1;
     fieldAccount.offset = -1;
     fieldSymbol.offset = -1;
     fieldSecurityID.offset = -1;
     fieldSecurityType.offset = -1;
     fieldText.offset = -1;
     fieldProduct.offset = -1;
     fieldSide.offset = -1;
     fieldQtyType.offset = -1;
     fieldOrderQty.offset = -1;
     fieldOrdType.offset = -1;
     fieldPriceType.offset = -1;
     fieldPrice.offset = -1;
     fieldStopPx.offset = -1;
     fieldCurrency.offset = -1;
     fieldTimeInForce.offset = -1;
     fieldExecInst.offset = -1;
     fieldLastQty.offset = -1;
     fieldLastPx.offset = -1;
     fieldLeavesQty.offset = -1;
     fieldAvgPx.offset = -1;
     fieldCumQty.offset = -1;
     for( auto g = groupsLegs.begin(); g != groupsLegs.end() and g->getMessageBuffer(); ++g ) g->reset();
     fieldCheckSum.offset = -1;
}


// -------------------------------------- ParserDispatcher ----------------------------------------


const char * ParserDispatcher::parseAndDipatch( const char * buf, unsigned len, bool resetMessage )
{
    if( resetMessage )
    {
        _msgHeader.reset();
    }
    offset_t pos = _msgHeader.scan( buf, len );

    unsigned bodyLength = _msgHeader.getBodyLength();
    const char * endOfMessage = _msgHeader.ptrToMsgType() + bodyLength + 4; // 7 for checkSum - 3 for msg type tag
    if( endOfMessage - buf > len )
    {
        return nullptr;
    }

    const raw_enum_t msgType = toRawEnum( _msgHeader.ptrToMsgType() );
    if( ignoreMessage( msgType ) )
    {
      return endOfMessage;
    }

    buf += pos;
    switch( msgType )
    {


// case-begin-_
      case MsgTypeRaw__ : {
       if( resetMessage ) _msgHeader.reset();
       pos = _msgHeader.scan( buf, len - pos );
       onMessage( _msgHeader );
       break;
      }
// case-end-_


// case-begin-ORDER_SINGLE
      case MsgTypeRaw_ORDER_SINGLE : {
       if( resetMessage ) _msgNewOrderSingle.reset();
       pos = _msgNewOrderSingle.scan( buf, len - pos );
       onMessage( _msgNewOrderSingle );
       break;
      }
// case-end-ORDER_SINGLE


// case-begin-EXECUTION_REPORT
      case MsgTypeRaw_EXECUTION_REPORT : {
       if( resetMessage ) _msgExecutionReport.reset();
       pos = _msgExecutionReport.scan( buf, len - pos );
       onMessage( _msgExecutionReport );
       break;
      }
// case-end-EXECUTION_REPORT


      default:
        onUnknownMessage( msgType );
        return endOfMessage;
    }
    return buf + pos;
}

void ParserDispatcher::onMessage( MessageHeader & msg )
{
   unprocessedMessage( MsgTypeRaw__, msg ); 
   msg.reset(); 
}


void ParserDispatcher::onMessage( MessageNewOrderSingle & msg )
{
   unprocessedMessage( MsgTypeRaw_ORDER_SINGLE, msg ); 
   msg.reset(); 
}


void ParserDispatcher::onMessage( MessageExecutionReport & msg )
{
   unprocessedMessage( MsgTypeRaw_EXECUTION_REPORT, msg ); 
   msg.reset(); 
}


// end of Messages.cxx


ParserDispatcher::ParserDispatcher()
{
}

ParserDispatcher::~ParserDispatcher()
{
}

void ParserDispatcher::onUnknownMessage( raw_enum_t msgType )
{
}

bool ParserDispatcher::ignoreMessage( raw_enum_t msgType ) const
{
    return false;
}

void ParserDispatcher::unprocessedMessage( raw_enum_t msgType, MessageBase & msg )
{
}

std::set< raw_tag_t > headerFields =
{
// start of Header.cxx
 FieldBeginString::RAW,
 FieldBodyLength::RAW,
 FieldMsgType::RAW,
 FieldSenderCompID::RAW,
 FieldTargetCompID::RAW,
 FieldMsgSeqNum::RAW,
 FieldSendingTime::RAW,
// end of Header.cxx
};

const FixFormatStyle defaultStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "",  //  indent
    "",  //  groupFirstField;
    "",  //  fieldBegin   
    " ", //  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "",  //  tagNameStart 
    "",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">", //  enumStop     
    "",  //  unknownStart
    ""   //  unknownStop
};

const FixFormatStyle defaultVerticalStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " *",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "",  //  tagNameStart 
    "",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">", //  enumStop     
    "",  //  unknownStart
    ""   //  unknownStop
};

const FixFormatStyle ttyStyle = 
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " \u2022",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "",  //  headerTagNameStart 
    "",  //  headerTagNameStop  
    "\e[1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "(", //  tagValueStart
    ")", //  tagValueStop 
    "=", //  equal        
    "",  //  valueStart   
    "",  //  valueStop    
    "<", //  enumStart    
    ">",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
};

const FixFormatStyle ttyRgbStyle =
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "  ",//  indent
    " \u2022",//  groupFirstField;
    " ", //  fieldBegin   
    "\n",//  fieldEnd     
    "\e[33m",  //  headerTagNameStart 
    "\e[0m",  //  headerTagNameStop  
    "\e[33;1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "(\e[37;1m", //  tagValueStart
    "\e[0m)", //  tagValueStop 
    " = ", //  equal        
    "\e[34;1m",  //  valueStart   
    "\e[0m",  //  valueStop    
    " \e[32m", //  enumStart    
    "\e[0m",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
};

const FixFormatStyle ttyRgbSingleLineStyle =
{
    "",  //  messageBegin 
    "",  //  messageEnd   
    "",//  indent
    "",//  groupFirstField;
    "", //  fieldBegin   
    "  ",//  fieldEnd     
    "\e[33m",  //  headerTagNameStart 
    "\e[0m",  //  headerTagNameStop  
    "\e[33;1m",  //  tagNameStart 
    "\e[0m",  //  tagNameStop  
    "<\e[37;1m", //  tagValueStart
    "\e[0m>", //  tagValueStop 
    "=", //  equal        
    "\e[34;1m",  //  valueStart   
    "\e[0m",  //  valueStop    
    "/\e[32m", //  enumStart    
    "\e[0m",  //  enumStop     
    "\e[31;1m",  //  unknownStart
    "\e[0m"      //  unknownStop
};

// msgTypePos = offset of 35=
unsigned parseMessageLength( const char * fix, unsigned & msgTypePos )
{
    unsigned bodyLengthPos = msgTypePos = FixBeginStringValue.size() + 5; // 8=| + 9=|
    return parseUInt( fix + bodyLengthPos, ++msgTypePos );
}


unsigned computeChecksum( const char * begin, const char * end )
{
    unsigned sum = 0;
    while( begin < end )
    {
        sum += (unsigned)*begin++;
    }
    return sum & 0xff;
}

const char * getEnumName( const char * fix, int valueOffset )
{
    if( valueOffset < 0 )
    {
        return nullptr;
    }

    offset_t pos = (offset_t)valueOffset;
    while( pos > 0 and fix[pos-1] != FIXPP_SOH )
    {
        --pos;
    }

    const raw_tag_t tag = nextRawTag( fix+pos, pos );
    if( tag == 0 )
    {
        return nullptr;
    }

    auto eit = rawToEnum.find( tag );
    if( eit == rawToEnum.end() )
    {
        return nullptr;
    }    
    const FieldEnumsBase * enums = eit->second;
    raw_enum_t rawEnum = toRawEnum( fix + valueOffset );
    const char * enumName = enums->getEnumNameByRaw( rawEnum );
    return enumName;
}

std::ostream & fixToHuman( const char * fix, offset_t & pos, std::ostream & os, const FixFormatStyle & style, GetDepthMethod indentator )
{
    os << style.messageBegin;
    
    while( fix[pos] )
    {
        offset_t prev = pos;
        const raw_tag_t tag = nextRawTag( fix+pos, pos );

        if( tag == 0 )
        {
            os << style.unknownStart << "[bad tag at " << pos << "]" << style.unknownStop << style.messageEnd;
            return os;
        }

        os << style.fieldBegin;
        
        auto it = rawToTagName.find( tag );
        const FieldEnumsBase * enums = nullptr;
        if( it != rawToTagName.end() )
        {
            if( headerFields.find( tag ) != headerFields.end() )
            {
                if( style.headerTagNameStart )
                {
                    os << style.headerTagNameStart << it->second << style.headerTagNameStop;
                }
            }
            else
            {
                if( indentator and indentator != autoIndentFields )
                {
                    FieldDepth fd = (*indentator)( tag );
                    if( fd.isFirstInGroup )
                    {
                        for( int d = 1; d < fd.depth; ++d ) os << style.indent;
                        os << style.groupFirstField;
                    }
                    else
                    {
                        for( int d = 0; d < fd.depth; ++d ) os << style.indent;
                    }
                }
                if( style.tagNameStart )
                {
                    os << style.tagNameStart << it->second << style.tagNameStop;
                }
            }
            
            auto eit = rawToEnum.find( tag );
            if( eit != rawToEnum.end() )
            {
                enums = eit->second;
            }
        }
        else
        {
            os << style.unknownStart << "Unknown" << style.unknownStop;
        }
        
        // tag
        os << style.tagValueStart;
        while( fix[prev] != '=' )
        {
            os << fix[prev++];
        }
        os << style.tagValueStop << style.equal << style.valueStart;
        
        raw_enum_t rawEnum = toRawEnum( fix + pos );
        
        // value as is
        while( fix[pos] and fix[pos] != FIXPP_SOH )
        {
            os << fix[pos++];
        }
        
        os << style.valueStop;
        
        // enum
        if( enums and style.enumStart )
        {
            const char * enumName = enums->getEnumNameByRaw( rawEnum );
            if( enumName )
            {
                os << style.enumStart << enumName << style.enumStop;
            }
            else
            {
                os << style.unknownStart << " UNKNOWN" << style.unknownStop;
            }

            if( tag == FieldMsgType::RAW and indentator == autoIndentFields )
            {
                indentator = getTagDepthMethodByRawMsgType( rawEnum );
            }

        }

        os << style.fieldEnd;
        os.flush();
        
        ++pos;
        if( tag == FieldCheckSum::RAW )
        {
            break;
        }
        
    }
    os << style.messageEnd;
    return os;
}

} // namespace order

// gdb helper
extern "C" const char * fixppGetEnumName( const char * fix, int valueOffset )
{
    return order::getEnumName( fix, valueOffset );
}
