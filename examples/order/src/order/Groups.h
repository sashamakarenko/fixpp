// Generated by https://github.com/sashamakarenko/fixpp
// Copyright (c) 2021 sashamakarenko
// https://github.com/sashamakarenko/fixpp/blob/main/LICENSE
#pragma once
#ifndef order_GROUPS_H
#define order_GROUPS_H

#include <vector>

#include <order/Fields.h>

namespace order
{

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
   std::string_view getLegStipulationTypeView() const { return fieldLegStipulationType.offset >= 0 ? std::string_view{ buf + fieldLegStipulationType.offset, getValueLength( buf + fieldLegStipulationType.offset ) } : std::string_view{}; }
   const char * ptrToLegStipulationType() const { return buf + fieldLegStipulationType.offset; }
   const char * getIfSetLegStipulationType() const { return fieldLegStipulationType.offset >= 0 ? buf + fieldLegStipulationType.offset : nullptr; }
   private: FieldLegStipulationType fieldLegStipulationType;

   public:
   bool isSetLegStipulationValue() const { return fieldLegStipulationValue.offset >= 0; }
   FieldLegStipulationValue::ValueType getLegStipulationValue() const { return fieldLegStipulationValue.getValue( buf ); }
   std::string_view getLegStipulationValueView() const { return fieldLegStipulationValue.offset >= 0 ? std::string_view{ buf + fieldLegStipulationValue.offset, getValueLength( buf + fieldLegStipulationValue.offset ) } : std::string_view{}; }
   const char * ptrToLegStipulationValue() const { return buf + fieldLegStipulationValue.offset; }
   const char * getIfSetLegStipulationValue() const { return fieldLegStipulationValue.offset >= 0 ? buf + fieldLegStipulationValue.offset : nullptr; }
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
   std::string_view getNestedPartySubIDView() const { return fieldNestedPartySubID.offset >= 0 ? std::string_view{ buf + fieldNestedPartySubID.offset, getValueLength( buf + fieldNestedPartySubID.offset ) } : std::string_view{}; }
   const char * ptrToNestedPartySubID() const { return buf + fieldNestedPartySubID.offset; }
   const char * getIfSetNestedPartySubID() const { return fieldNestedPartySubID.offset >= 0 ? buf + fieldNestedPartySubID.offset : nullptr; }
   private: FieldNestedPartySubID fieldNestedPartySubID;

   public:
   bool isSetNestedPartySubIDType() const { return fieldNestedPartySubIDType.offset >= 0; }
   FieldNestedPartySubIDType::ValueType getNestedPartySubIDType() const { return fieldNestedPartySubIDType.getValue( buf ); }
   std::string_view getNestedPartySubIDTypeView() const { return fieldNestedPartySubIDType.offset >= 0 ? std::string_view{ buf + fieldNestedPartySubIDType.offset, getValueLength( buf + fieldNestedPartySubIDType.offset ) } : std::string_view{}; }
   const char * ptrToNestedPartySubIDType() const { return buf + fieldNestedPartySubIDType.offset; }
   const char * getIfSetNestedPartySubIDType() const { return fieldNestedPartySubIDType.offset >= 0 ? buf + fieldNestedPartySubIDType.offset : nullptr; }
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
   std::string_view getNestedPartyIDView() const { return fieldNestedPartyID.offset >= 0 ? std::string_view{ buf + fieldNestedPartyID.offset, getValueLength( buf + fieldNestedPartyID.offset ) } : std::string_view{}; }
   const char * ptrToNestedPartyID() const { return buf + fieldNestedPartyID.offset; }
   const char * getIfSetNestedPartyID() const { return fieldNestedPartyID.offset >= 0 ? buf + fieldNestedPartyID.offset : nullptr; }
   private: FieldNestedPartyID fieldNestedPartyID;

   public:
   bool isSetNestedPartyIDSource() const { return fieldNestedPartyIDSource.offset >= 0; }
   FieldNestedPartyIDSource::ValueType getNestedPartyIDSource() const { return fieldNestedPartyIDSource.getValue( buf ); }
   std::string_view getNestedPartyIDSourceView() const { return fieldNestedPartyIDSource.offset >= 0 ? std::string_view{ buf + fieldNestedPartyIDSource.offset, getValueLength( buf + fieldNestedPartyIDSource.offset ) } : std::string_view{}; }
   const char * ptrToNestedPartyIDSource() const { return buf + fieldNestedPartyIDSource.offset; }
   const char * getIfSetNestedPartyIDSource() const { return fieldNestedPartyIDSource.offset >= 0 ? buf + fieldNestedPartyIDSource.offset : nullptr; }
   private: FieldNestedPartyIDSource fieldNestedPartyIDSource;

   public:
   bool isSetNestedPartyRole() const { return fieldNestedPartyRole.offset >= 0; }
   FieldNestedPartyRole::ValueType getNestedPartyRole() const { return fieldNestedPartyRole.getValue( buf ); }
   std::string_view getNestedPartyRoleView() const { return fieldNestedPartyRole.offset >= 0 ? std::string_view{ buf + fieldNestedPartyRole.offset, getValueLength( buf + fieldNestedPartyRole.offset ) } : std::string_view{}; }
   const char * ptrToNestedPartyRole() const { return buf + fieldNestedPartyRole.offset; }
   const char * getIfSetNestedPartyRole() const { return fieldNestedPartyRole.offset >= 0 ? buf + fieldNestedPartyRole.offset : nullptr; }
   private: FieldNestedPartyRole fieldNestedPartyRole;

   public:
   bool isSetNoNestedPartySubIDs() const { return fieldNoNestedPartySubIDs.offset >= 0; }
   FieldNoNestedPartySubIDs::ValueType getNoNestedPartySubIDs() const { return fieldNoNestedPartySubIDs.getValue( buf ); }
   std::string_view getNoNestedPartySubIDsView() const { return fieldNoNestedPartySubIDs.offset >= 0 ? std::string_view{ buf + fieldNoNestedPartySubIDs.offset, getValueLength( buf + fieldNoNestedPartySubIDs.offset ) } : std::string_view{}; }
   const char * ptrToNoNestedPartySubIDs() const { return buf + fieldNoNestedPartySubIDs.offset; }
   const char * getIfSetNoNestedPartySubIDs() const { return fieldNoNestedPartySubIDs.offset >= 0 ? buf + fieldNoNestedPartySubIDs.offset : nullptr; }
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
   std::string_view getLegSymbolView() const { return fieldLegSymbol.offset >= 0 ? std::string_view{ buf + fieldLegSymbol.offset, getValueLength( buf + fieldLegSymbol.offset ) } : std::string_view{}; }
   const char * ptrToLegSymbol() const { return buf + fieldLegSymbol.offset; }
   const char * getIfSetLegSymbol() const { return fieldLegSymbol.offset >= 0 ? buf + fieldLegSymbol.offset : nullptr; }
   private: FieldLegSymbol fieldLegSymbol;

   public:
   bool isSetLegSide() const { return fieldLegSide.offset >= 0; }
   FieldLegSide::ValueType getLegSide() const { return fieldLegSide.getValue( buf ); }
   std::string_view getLegSideView() const { return fieldLegSide.offset >= 0 ? std::string_view{ buf + fieldLegSide.offset, getValueLength( buf + fieldLegSide.offset ) } : std::string_view{}; }
   const char * ptrToLegSide() const { return buf + fieldLegSide.offset; }
   const char * getIfSetLegSide() const { return fieldLegSide.offset >= 0 ? buf + fieldLegSide.offset : nullptr; }
   private: FieldLegSide fieldLegSide;

   public:
   bool isSetLegQty() const { return fieldLegQty.offset >= 0; }
   FieldLegQty::ValueType getLegQty() const { return fieldLegQty.getValue( buf ); }
   std::string_view getLegQtyView() const { return fieldLegQty.offset >= 0 ? std::string_view{ buf + fieldLegQty.offset, getValueLength( buf + fieldLegQty.offset ) } : std::string_view{}; }
   const char * ptrToLegQty() const { return buf + fieldLegQty.offset; }
   const char * getIfSetLegQty() const { return fieldLegQty.offset >= 0 ? buf + fieldLegQty.offset : nullptr; }
   private: FieldLegQty fieldLegQty;

   public:
   bool isSetNoLegStipulations() const { return fieldNoLegStipulations.offset >= 0; }
   FieldNoLegStipulations::ValueType getNoLegStipulations() const { return fieldNoLegStipulations.getValue( buf ); }
   std::string_view getNoLegStipulationsView() const { return fieldNoLegStipulations.offset >= 0 ? std::string_view{ buf + fieldNoLegStipulations.offset, getValueLength( buf + fieldNoLegStipulations.offset ) } : std::string_view{}; }
   const char * ptrToNoLegStipulations() const { return buf + fieldNoLegStipulations.offset; }
   const char * getIfSetNoLegStipulations() const { return fieldNoLegStipulations.offset >= 0 ? buf + fieldNoLegStipulations.offset : nullptr; }
   private: FieldNoLegStipulations fieldNoLegStipulations;
  
   public:
   std::size_t getGroupCountLegStipulations() const { return groupsLegStipulations.size(); } 
   const GroupLegStipulations & getGroupLegStipulations( std::size_t idx ) const { return groupsLegStipulations[ idx ]; } 
   private: GroupLegStipulations::Array groupsLegStipulations{ 10 };

   public:
   bool isSetLegPositionEffect() const { return fieldLegPositionEffect.offset >= 0; }
   FieldLegPositionEffect::ValueType getLegPositionEffect() const { return fieldLegPositionEffect.getValue( buf ); }
   std::string_view getLegPositionEffectView() const { return fieldLegPositionEffect.offset >= 0 ? std::string_view{ buf + fieldLegPositionEffect.offset, getValueLength( buf + fieldLegPositionEffect.offset ) } : std::string_view{}; }
   const char * ptrToLegPositionEffect() const { return buf + fieldLegPositionEffect.offset; }
   const char * getIfSetLegPositionEffect() const { return fieldLegPositionEffect.offset >= 0 ? buf + fieldLegPositionEffect.offset : nullptr; }
   private: FieldLegPositionEffect fieldLegPositionEffect;

   public:
   bool isSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0; }
   FieldNoNestedPartyIDs::ValueType getNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.getValue( buf ); }
   std::string_view getNoNestedPartyIDsView() const { return fieldNoNestedPartyIDs.offset >= 0 ? std::string_view{ buf + fieldNoNestedPartyIDs.offset, getValueLength( buf + fieldNoNestedPartyIDs.offset ) } : std::string_view{}; }
   const char * ptrToNoNestedPartyIDs() const { return buf + fieldNoNestedPartyIDs.offset; }
   const char * getIfSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0 ? buf + fieldNoNestedPartyIDs.offset : nullptr; }
   private: FieldNoNestedPartyIDs fieldNoNestedPartyIDs;
  
   public:
   std::size_t getGroupCountNestedPartyIDs() const { return groupsNestedPartyIDs.size(); } 
   const GroupNestedPartyIDs & getGroupNestedPartyIDs( std::size_t idx ) const { return groupsNestedPartyIDs[ idx ]; } 
   private: GroupNestedPartyIDs::Array groupsNestedPartyIDs{ 10 };

   public:
   bool isSetLegRefID() const { return fieldLegRefID.offset >= 0; }
   FieldLegRefID::ValueType getLegRefID() const { return fieldLegRefID.getValue( buf ); }
   std::string_view getLegRefIDView() const { return fieldLegRefID.offset >= 0 ? std::string_view{ buf + fieldLegRefID.offset, getValueLength( buf + fieldLegRefID.offset ) } : std::string_view{}; }
   const char * ptrToLegRefID() const { return buf + fieldLegRefID.offset; }
   const char * getIfSetLegRefID() const { return fieldLegRefID.offset >= 0 ? buf + fieldLegRefID.offset : nullptr; }
   private: FieldLegRefID fieldLegRefID;

   public:
   bool isSetLegPrice() const { return fieldLegPrice.offset >= 0; }
   FieldLegPrice::ValueType getLegPrice() const { return fieldLegPrice.getValue( buf ); }
   std::string_view getLegPriceView() const { return fieldLegPrice.offset >= 0 ? std::string_view{ buf + fieldLegPrice.offset, getValueLength( buf + fieldLegPrice.offset ) } : std::string_view{}; }
   const char * ptrToLegPrice() const { return buf + fieldLegPrice.offset; }
   const char * getIfSetLegPrice() const { return fieldLegPrice.offset >= 0 ? buf + fieldLegPrice.offset : nullptr; }
   private: FieldLegPrice fieldLegPrice;

   public:
   bool isSetLegLastPx() const { return fieldLegLastPx.offset >= 0; }
   FieldLegLastPx::ValueType getLegLastPx() const { return fieldLegLastPx.getValue( buf ); }
   std::string_view getLegLastPxView() const { return fieldLegLastPx.offset >= 0 ? std::string_view{ buf + fieldLegLastPx.offset, getValueLength( buf + fieldLegLastPx.offset ) } : std::string_view{}; }
   const char * ptrToLegLastPx() const { return buf + fieldLegLastPx.offset; }
   const char * getIfSetLegLastPx() const { return fieldLegLastPx.offset >= 0 ? buf + fieldLegLastPx.offset : nullptr; }
   private: FieldLegLastPx fieldLegLastPx;

};
// end of Groups.hxx

} // namespace order

#endif /* order_GROUPS_H */

