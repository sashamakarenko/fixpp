#pragma once
#ifndef order_MESSAGES_H
#define order_MESSAGES_H

#include <order/Fields.h>

#include <vector>

namespace order
{

GetDepthMethod getTagDepthMethodByRawMsgType( raw_enum_t rawMsgType );

// start of Groups.hxx

// Generated


class GroupLegStipulations : public MessageBase
{
  
// Methods
   public:
   GroupLegStipulations();
   typedef std::vector<GroupLegStipulations> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetLegStipulationType() const { return fieldLegStipulationType.offset >= 0; }
   FieldLegStipulationType::ValueType getLegStipulationType() const { return fieldLegStipulationType.getValue( buf ); }
   const char * ptrToLegStipulationType() const { return buf + fieldLegStipulationType.offset; }
   private: FieldLegStipulationType fieldLegStipulationType;

   public:
   bool isSetLegStipulationValue() const { return fieldLegStipulationValue.offset >= 0; }
   FieldLegStipulationValue::ValueType getLegStipulationValue() const { return fieldLegStipulationValue.getValue( buf ); }
   const char * ptrToLegStipulationValue() const { return buf + fieldLegStipulationValue.offset; }
   private: FieldLegStipulationValue fieldLegStipulationValue;

};

class GroupNestedPartySubIDs : public MessageBase
{
  
// Methods
   public:
   GroupNestedPartySubIDs();
   typedef std::vector<GroupNestedPartySubIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNestedPartySubID() const { return fieldNestedPartySubID.offset >= 0; }
   FieldNestedPartySubID::ValueType getNestedPartySubID() const { return fieldNestedPartySubID.getValue( buf ); }
   const char * ptrToNestedPartySubID() const { return buf + fieldNestedPartySubID.offset; }
   private: FieldNestedPartySubID fieldNestedPartySubID;

   public:
   bool isSetNestedPartySubIDType() const { return fieldNestedPartySubIDType.offset >= 0; }
   FieldNestedPartySubIDType::ValueType getNestedPartySubIDType() const { return fieldNestedPartySubIDType.getValue( buf ); }
   const char * ptrToNestedPartySubIDType() const { return buf + fieldNestedPartySubIDType.offset; }
   private: FieldNestedPartySubIDType fieldNestedPartySubIDType;

};

class GroupNestedPartyIDs : public MessageBase
{
  
// Methods
   public:
   GroupNestedPartyIDs();
   typedef std::vector<GroupNestedPartyIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNestedPartyID() const { return fieldNestedPartyID.offset >= 0; }
   FieldNestedPartyID::ValueType getNestedPartyID() const { return fieldNestedPartyID.getValue( buf ); }
   const char * ptrToNestedPartyID() const { return buf + fieldNestedPartyID.offset; }
   private: FieldNestedPartyID fieldNestedPartyID;

   public:
   bool isSetNestedPartyIDSource() const { return fieldNestedPartyIDSource.offset >= 0; }
   FieldNestedPartyIDSource::ValueType getNestedPartyIDSource() const { return fieldNestedPartyIDSource.getValue( buf ); }
   const char * ptrToNestedPartyIDSource() const { return buf + fieldNestedPartyIDSource.offset; }
   private: FieldNestedPartyIDSource fieldNestedPartyIDSource;

   public:
   bool isSetNestedPartyRole() const { return fieldNestedPartyRole.offset >= 0; }
   FieldNestedPartyRole::ValueType getNestedPartyRole() const { return fieldNestedPartyRole.getValue( buf ); }
   const char * ptrToNestedPartyRole() const { return buf + fieldNestedPartyRole.offset; }
   private: FieldNestedPartyRole fieldNestedPartyRole;

   public:
   bool isSetNoNestedPartySubIDs() const { return fieldNoNestedPartySubIDs.offset >= 0; }
   FieldNoNestedPartySubIDs::ValueType getNoNestedPartySubIDs() const { return fieldNoNestedPartySubIDs.getValue( buf ); }
   const char * ptrToNoNestedPartySubIDs() const { return buf + fieldNoNestedPartySubIDs.offset; }
   private: FieldNoNestedPartySubIDs fieldNoNestedPartySubIDs;
  
   public:
   std::size_t getGroupCountNestedPartySubIDs() const { return groupsNestedPartySubIDs.size(); } 
   const GroupNestedPartySubIDs & getGroupNestedPartySubIDs( std::size_t idx ) const { return groupsNestedPartySubIDs[ idx ]; } 
   private: GroupNestedPartySubIDs::Array groupsNestedPartySubIDs{ 10 };

};

class GroupLegs : public MessageBase
{
  
// Methods
   public:
   GroupLegs();
   typedef std::vector<GroupLegs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetLegSymbol() const { return fieldLegSymbol.offset >= 0; }
   FieldLegSymbol::ValueType getLegSymbol() const { return fieldLegSymbol.getValue( buf ); }
   const char * ptrToLegSymbol() const { return buf + fieldLegSymbol.offset; }
   private: FieldLegSymbol fieldLegSymbol;

   public:
   bool isSetLegSide() const { return fieldLegSide.offset >= 0; }
   FieldLegSide::ValueType getLegSide() const { return fieldLegSide.getValue( buf ); }
   const char * ptrToLegSide() const { return buf + fieldLegSide.offset; }
   private: FieldLegSide fieldLegSide;

   public:
   bool isSetLegQty() const { return fieldLegQty.offset >= 0; }
   FieldLegQty::ValueType getLegQty() const { return fieldLegQty.getValue( buf ); }
   const char * ptrToLegQty() const { return buf + fieldLegQty.offset; }
   private: FieldLegQty fieldLegQty;

   public:
   bool isSetNoLegStipulations() const { return fieldNoLegStipulations.offset >= 0; }
   FieldNoLegStipulations::ValueType getNoLegStipulations() const { return fieldNoLegStipulations.getValue( buf ); }
   const char * ptrToNoLegStipulations() const { return buf + fieldNoLegStipulations.offset; }
   private: FieldNoLegStipulations fieldNoLegStipulations;
  
   public:
   std::size_t getGroupCountLegStipulations() const { return groupsLegStipulations.size(); } 
   const GroupLegStipulations & getGroupLegStipulations( std::size_t idx ) const { return groupsLegStipulations[ idx ]; } 
   private: GroupLegStipulations::Array groupsLegStipulations{ 10 };

   public:
   bool isSetLegPositionEffect() const { return fieldLegPositionEffect.offset >= 0; }
   FieldLegPositionEffect::ValueType getLegPositionEffect() const { return fieldLegPositionEffect.getValue( buf ); }
   const char * ptrToLegPositionEffect() const { return buf + fieldLegPositionEffect.offset; }
   private: FieldLegPositionEffect fieldLegPositionEffect;

   public:
   bool isSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0; }
   FieldNoNestedPartyIDs::ValueType getNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.getValue( buf ); }
   const char * ptrToNoNestedPartyIDs() const { return buf + fieldNoNestedPartyIDs.offset; }
   private: FieldNoNestedPartyIDs fieldNoNestedPartyIDs;
  
   public:
   std::size_t getGroupCountNestedPartyIDs() const { return groupsNestedPartyIDs.size(); } 
   const GroupNestedPartyIDs & getGroupNestedPartyIDs( std::size_t idx ) const { return groupsNestedPartyIDs[ idx ]; } 
   private: GroupNestedPartyIDs::Array groupsNestedPartyIDs{ 10 };

   public:
   bool isSetLegRefID() const { return fieldLegRefID.offset >= 0; }
   FieldLegRefID::ValueType getLegRefID() const { return fieldLegRefID.getValue( buf ); }
   const char * ptrToLegRefID() const { return buf + fieldLegRefID.offset; }
   private: FieldLegRefID fieldLegRefID;

   public:
   bool isSetLegPrice() const { return fieldLegPrice.offset >= 0; }
   FieldLegPrice::ValueType getLegPrice() const { return fieldLegPrice.getValue( buf ); }
   const char * ptrToLegPrice() const { return buf + fieldLegPrice.offset; }
   private: FieldLegPrice fieldLegPrice;

   public:
   bool isSetLegLastPx() const { return fieldLegLastPx.offset >= 0; }
   FieldLegLastPx::ValueType getLegLastPx() const { return fieldLegLastPx.getValue( buf ); }
   const char * ptrToLegLastPx() const { return buf + fieldLegLastPx.offset; }
   private: FieldLegLastPx fieldLegLastPx;

};
// end of Groups.hxx

// start of Messages.hxx

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
   const char * getFieldValue( tag_t tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<tag_t> & getKnownFields();
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
   const char * getFieldValue( tag_t tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<tag_t> & getKnownFields();
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
   const char * getFieldValue( tag_t tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<tag_t> & getKnownFields();
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
   std::size_t getGroupCountLegs() const { return groupsLegs.size(); } 
   const GroupLegs & getGroupLegs( std::size_t idx ) const { return groupsLegs[ idx ]; } 
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
// end of Messages.hxx

struct FixFormatStyle
{
    const char * messageBegin   ;
    const char * messageEnd     ;
    const char * indent         ;
    const char * groupFirstField;
    const char * fieldBegin     ;
    const char * fieldEnd       ;
    const char * headerTagNameStart;
    const char * headerTagNameStop ;
    const char * tagNameStart   ;
    const char * tagNameStop    ;
    const char * tagValueStart  ;
    const char * tagValueStop   ;
    const char * equal          ;
    const char * valueStart     ;
    const char * valueStop      ;
    const char * enumStart      ;
    const char * enumStop       ;
    const char * unknownStart   ;
    const char * unknownStop    ;
};

extern const FixFormatStyle defaultStyle;
extern const FixFormatStyle defaultVerticalStyle;
extern const FixFormatStyle ttyStyle;
extern const FixFormatStyle ttyRgbStyle;
extern const FixFormatStyle ttyRgbSingleLineStyle;

const GetDepthMethod autoIndentFields = (GetDepthMethod)(-1);

std::ostream & fixToHuman( const char * fix, offset_t & pos, std::ostream & os, const FixFormatStyle & style = defaultStyle, GetDepthMethod indentator = nullptr );

unsigned computeChecksum( const char * begin, const char * end );

unsigned parseMessageLength( const char * fix, unsigned & msgTypePos );

struct fixstr
{
    explicit fixstr( const char * fix, const FixFormatStyle & fstyle = defaultStyle, GetDepthMethod ind = autoIndentFields ): ptr(fix), style(fstyle), indentator{ind} {}
    const char * const ptr;
    const FixFormatStyle & style;
    const GetDepthMethod indentator;
};

const char * getEnumName( const char * fix, int valueOffset );

} // namespace order

inline std::ostream & operator << ( std::ostream & os, const order::fixstr & msg )
{
    order::offset_t pos = 0;
    return order::fixToHuman( msg.ptr, pos, os, msg.style, msg.indentator );
}

#endif /* order_MESSAGES_H */

