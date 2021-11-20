
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

class GroupEvents : public MessageBase
{
  
// Methods
   public:
   GroupEvents();
   typedef std::vector<GroupEvents> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetEventType() const { return fieldEventType.offset >= 0; }
   FieldEventType::ValueType getEventType() const { return fieldEventType.getValue( buf ); }
   const char * ptrToEventType() const { return buf + fieldEventType.offset; }
   private: FieldEventType fieldEventType;

   public:
   bool isSetEventDate() const { return fieldEventDate.offset >= 0; }
   FieldEventDate::ValueType getEventDate() const { return fieldEventDate.getValue( buf ); }
   const char * ptrToEventDate() const { return buf + fieldEventDate.offset; }
   private: FieldEventDate fieldEventDate;

   public:
   bool isSetEventPx() const { return fieldEventPx.offset >= 0; }
   FieldEventPx::ValueType getEventPx() const { return fieldEventPx.getValue( buf ); }
   const char * ptrToEventPx() const { return buf + fieldEventPx.offset; }
   private: FieldEventPx fieldEventPx;

   public:
   bool isSetEventText() const { return fieldEventText.offset >= 0; }
   FieldEventText::ValueType getEventText() const { return fieldEventText.getValue( buf ); }
   const char * ptrToEventText() const { return buf + fieldEventText.offset; }
   private: FieldEventText fieldEventText;

};

class GroupLegSecurityAltID : public MessageBase
{
  
// Methods
   public:
   GroupLegSecurityAltID();
   typedef std::vector<GroupLegSecurityAltID> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetLegSecurityAltID() const { return fieldLegSecurityAltID.offset >= 0; }
   FieldLegSecurityAltID::ValueType getLegSecurityAltID() const { return fieldLegSecurityAltID.getValue( buf ); }
   const char * ptrToLegSecurityAltID() const { return buf + fieldLegSecurityAltID.offset; }
   private: FieldLegSecurityAltID fieldLegSecurityAltID;

   public:
   bool isSetLegSecurityAltIDSource() const { return fieldLegSecurityAltIDSource.offset >= 0; }
   FieldLegSecurityAltIDSource::ValueType getLegSecurityAltIDSource() const { return fieldLegSecurityAltIDSource.getValue( buf ); }
   const char * ptrToLegSecurityAltIDSource() const { return buf + fieldLegSecurityAltIDSource.offset; }
   private: FieldLegSecurityAltIDSource fieldLegSecurityAltIDSource;

};

class GroupCapacities : public MessageBase
{
  
// Methods
   public:
   GroupCapacities();
   typedef std::vector<GroupCapacities> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetOrderCapacity() const { return fieldOrderCapacity.offset >= 0; }
   FieldOrderCapacity::ValueType getOrderCapacity() const { return fieldOrderCapacity.getValue( buf ); }
   const char * ptrToOrderCapacity() const { return buf + fieldOrderCapacity.offset; }
   private: FieldOrderCapacity fieldOrderCapacity;

   public:
   bool isSetOrderRestrictions() const { return fieldOrderRestrictions.offset >= 0; }
   FieldOrderRestrictions::ValueType getOrderRestrictions() const { return fieldOrderRestrictions.getValue( buf ); }
   const char * ptrToOrderRestrictions() const { return buf + fieldOrderRestrictions.offset; }
   private: FieldOrderRestrictions fieldOrderRestrictions;

   public:
   bool isSetOrderCapacityQty() const { return fieldOrderCapacityQty.offset >= 0; }
   FieldOrderCapacityQty::ValueType getOrderCapacityQty() const { return fieldOrderCapacityQty.getValue( buf ); }
   const char * ptrToOrderCapacityQty() const { return buf + fieldOrderCapacityQty.offset; }
   private: FieldOrderCapacityQty fieldOrderCapacityQty;

};

class GroupNested3PartySubIDs : public MessageBase
{
  
// Methods
   public:
   GroupNested3PartySubIDs();
   typedef std::vector<GroupNested3PartySubIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNested3PartySubID() const { return fieldNested3PartySubID.offset >= 0; }
   FieldNested3PartySubID::ValueType getNested3PartySubID() const { return fieldNested3PartySubID.getValue( buf ); }
   const char * ptrToNested3PartySubID() const { return buf + fieldNested3PartySubID.offset; }
   private: FieldNested3PartySubID fieldNested3PartySubID;

   public:
   bool isSetNested3PartySubIDType() const { return fieldNested3PartySubIDType.offset >= 0; }
   FieldNested3PartySubIDType::ValueType getNested3PartySubIDType() const { return fieldNested3PartySubIDType.getValue( buf ); }
   const char * ptrToNested3PartySubIDType() const { return buf + fieldNested3PartySubIDType.offset; }
   private: FieldNested3PartySubIDType fieldNested3PartySubIDType;

};

class GroupPartySubIDs : public MessageBase
{
  
// Methods
   public:
   GroupPartySubIDs();
   typedef std::vector<GroupPartySubIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetPartySubID() const { return fieldPartySubID.offset >= 0; }
   FieldPartySubID::ValueType getPartySubID() const { return fieldPartySubID.getValue( buf ); }
   const char * ptrToPartySubID() const { return buf + fieldPartySubID.offset; }
   private: FieldPartySubID fieldPartySubID;

   public:
   bool isSetPartySubIDType() const { return fieldPartySubIDType.offset >= 0; }
   FieldPartySubIDType::ValueType getPartySubIDType() const { return fieldPartySubIDType.getValue( buf ); }
   const char * ptrToPartySubIDType() const { return buf + fieldPartySubIDType.offset; }
   private: FieldPartySubIDType fieldPartySubIDType;

};

class GroupNested2PartySubIDs : public MessageBase
{
  
// Methods
   public:
   GroupNested2PartySubIDs();
   typedef std::vector<GroupNested2PartySubIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNested2PartySubID() const { return fieldNested2PartySubID.offset >= 0; }
   FieldNested2PartySubID::ValueType getNested2PartySubID() const { return fieldNested2PartySubID.getValue( buf ); }
   const char * ptrToNested2PartySubID() const { return buf + fieldNested2PartySubID.offset; }
   private: FieldNested2PartySubID fieldNested2PartySubID;

   public:
   bool isSetNested2PartySubIDType() const { return fieldNested2PartySubIDType.offset >= 0; }
   FieldNested2PartySubIDType::ValueType getNested2PartySubIDType() const { return fieldNested2PartySubIDType.getValue( buf ); }
   const char * ptrToNested2PartySubIDType() const { return buf + fieldNested2PartySubIDType.offset; }
   private: FieldNested2PartySubIDType fieldNested2PartySubIDType;

};

class GroupNested2PartyIDs : public MessageBase
{
  
// Methods
   public:
   GroupNested2PartyIDs();
   typedef std::vector<GroupNested2PartyIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNested2PartyID() const { return fieldNested2PartyID.offset >= 0; }
   FieldNested2PartyID::ValueType getNested2PartyID() const { return fieldNested2PartyID.getValue( buf ); }
   const char * ptrToNested2PartyID() const { return buf + fieldNested2PartyID.offset; }
   private: FieldNested2PartyID fieldNested2PartyID;

   public:
   bool isSetNested2PartyIDSource() const { return fieldNested2PartyIDSource.offset >= 0; }
   FieldNested2PartyIDSource::ValueType getNested2PartyIDSource() const { return fieldNested2PartyIDSource.getValue( buf ); }
   const char * ptrToNested2PartyIDSource() const { return buf + fieldNested2PartyIDSource.offset; }
   private: FieldNested2PartyIDSource fieldNested2PartyIDSource;

   public:
   bool isSetNested2PartyRole() const { return fieldNested2PartyRole.offset >= 0; }
   FieldNested2PartyRole::ValueType getNested2PartyRole() const { return fieldNested2PartyRole.getValue( buf ); }
   const char * ptrToNested2PartyRole() const { return buf + fieldNested2PartyRole.offset; }
   private: FieldNested2PartyRole fieldNested2PartyRole;

   public:
   bool isSetNoNested2PartySubIDs() const { return fieldNoNested2PartySubIDs.offset >= 0; }
   FieldNoNested2PartySubIDs::ValueType getNoNested2PartySubIDs() const { return fieldNoNested2PartySubIDs.getValue( buf ); }
   const char * ptrToNoNested2PartySubIDs() const { return buf + fieldNoNested2PartySubIDs.offset; }
   private: FieldNoNested2PartySubIDs fieldNoNested2PartySubIDs;
  
   public:
   size_t getGroupCountNested2PartySubIDs() const { return groupsNested2PartySubIDs.size(); } 
   const GroupNested2PartySubIDs & getGroupNested2PartySubIDs( size_t idx ) const { return groupsNested2PartySubIDs[ idx ]; } 
   private: GroupNested2PartySubIDs::Array groupsNested2PartySubIDs{ 10 };

};

class GroupHops : public MessageBase
{
  
// Methods
   public:
   GroupHops();
   typedef std::vector<GroupHops> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetHopCompID() const { return fieldHopCompID.offset >= 0; }
   FieldHopCompID::ValueType getHopCompID() const { return fieldHopCompID.getValue( buf ); }
   const char * ptrToHopCompID() const { return buf + fieldHopCompID.offset; }
   private: FieldHopCompID fieldHopCompID;

   public:
   bool isSetHopSendingTime() const { return fieldHopSendingTime.offset >= 0; }
   FieldHopSendingTime::ValueType getHopSendingTime() const { return fieldHopSendingTime.getValue( buf ); }
   const char * ptrToHopSendingTime() const { return buf + fieldHopSendingTime.offset; }
   private: FieldHopSendingTime fieldHopSendingTime;

   public:
   bool isSetHopRefID() const { return fieldHopRefID.offset >= 0; }
   FieldHopRefID::ValueType getHopRefID() const { return fieldHopRefID.getValue( buf ); }
   const char * ptrToHopRefID() const { return buf + fieldHopRefID.offset; }
   private: FieldHopRefID fieldHopRefID;

};

class GroupCollInquiryQualifier : public MessageBase
{
  
// Methods
   public:
   GroupCollInquiryQualifier();
   typedef std::vector<GroupCollInquiryQualifier> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetCollInquiryQualifier() const { return fieldCollInquiryQualifier.offset >= 0; }
   FieldCollInquiryQualifier::ValueType getCollInquiryQualifier() const { return fieldCollInquiryQualifier.getValue( buf ); }
   const char * ptrToCollInquiryQualifier() const { return buf + fieldCollInquiryQualifier.offset; }
   private: FieldCollInquiryQualifier fieldCollInquiryQualifier;

};

class GroupPartyIDs : public MessageBase
{
  
// Methods
   public:
   GroupPartyIDs();
   typedef std::vector<GroupPartyIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetPartyID() const { return fieldPartyID.offset >= 0; }
   FieldPartyID::ValueType getPartyID() const { return fieldPartyID.getValue( buf ); }
   const char * ptrToPartyID() const { return buf + fieldPartyID.offset; }
   private: FieldPartyID fieldPartyID;

   public:
   bool isSetPartyIDSource() const { return fieldPartyIDSource.offset >= 0; }
   FieldPartyIDSource::ValueType getPartyIDSource() const { return fieldPartyIDSource.getValue( buf ); }
   const char * ptrToPartyIDSource() const { return buf + fieldPartyIDSource.offset; }
   private: FieldPartyIDSource fieldPartyIDSource;

   public:
   bool isSetPartyRole() const { return fieldPartyRole.offset >= 0; }
   FieldPartyRole::ValueType getPartyRole() const { return fieldPartyRole.getValue( buf ); }
   const char * ptrToPartyRole() const { return buf + fieldPartyRole.offset; }
   private: FieldPartyRole fieldPartyRole;

   public:
   bool isSetNoPartySubIDs() const { return fieldNoPartySubIDs.offset >= 0; }
   FieldNoPartySubIDs::ValueType getNoPartySubIDs() const { return fieldNoPartySubIDs.getValue( buf ); }
   const char * ptrToNoPartySubIDs() const { return buf + fieldNoPartySubIDs.offset; }
   private: FieldNoPartySubIDs fieldNoPartySubIDs;
  
   public:
   size_t getGroupCountPartySubIDs() const { return groupsPartySubIDs.size(); } 
   const GroupPartySubIDs & getGroupPartySubIDs( size_t idx ) const { return groupsPartySubIDs[ idx ]; } 
   private: GroupPartySubIDs::Array groupsPartySubIDs{ 10 };

};

class GroupAllocs : public MessageBase
{
  
// Methods
   public:
   GroupAllocs();
   typedef std::vector<GroupAllocs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetAllocAccount() const { return fieldAllocAccount.offset >= 0; }
   FieldAllocAccount::ValueType getAllocAccount() const { return fieldAllocAccount.getValue( buf ); }
   const char * ptrToAllocAccount() const { return buf + fieldAllocAccount.offset; }
   private: FieldAllocAccount fieldAllocAccount;

   public:
   bool isSetAllocAcctIDSource() const { return fieldAllocAcctIDSource.offset >= 0; }
   FieldAllocAcctIDSource::ValueType getAllocAcctIDSource() const { return fieldAllocAcctIDSource.getValue( buf ); }
   const char * ptrToAllocAcctIDSource() const { return buf + fieldAllocAcctIDSource.offset; }
   private: FieldAllocAcctIDSource fieldAllocAcctIDSource;

   public:
   bool isSetAllocPrice() const { return fieldAllocPrice.offset >= 0; }
   FieldAllocPrice::ValueType getAllocPrice() const { return fieldAllocPrice.getValue( buf ); }
   const char * ptrToAllocPrice() const { return buf + fieldAllocPrice.offset; }
   private: FieldAllocPrice fieldAllocPrice;

   public:
   bool isSetIndividualAllocID() const { return fieldIndividualAllocID.offset >= 0; }
   FieldIndividualAllocID::ValueType getIndividualAllocID() const { return fieldIndividualAllocID.getValue( buf ); }
   const char * ptrToIndividualAllocID() const { return buf + fieldIndividualAllocID.offset; }
   private: FieldIndividualAllocID fieldIndividualAllocID;

   public:
   bool isSetIndividualAllocRejCode() const { return fieldIndividualAllocRejCode.offset >= 0; }
   FieldIndividualAllocRejCode::ValueType getIndividualAllocRejCode() const { return fieldIndividualAllocRejCode.getValue( buf ); }
   const char * ptrToIndividualAllocRejCode() const { return buf + fieldIndividualAllocRejCode.offset; }
   private: FieldIndividualAllocRejCode fieldIndividualAllocRejCode;

   public:
   bool isSetAllocText() const { return fieldAllocText.offset >= 0; }
   FieldAllocText::ValueType getAllocText() const { return fieldAllocText.getValue( buf ); }
   const char * ptrToAllocText() const { return buf + fieldAllocText.offset; }
   private: FieldAllocText fieldAllocText;

   public:
   bool isSetEncodedAllocTextLen() const { return fieldEncodedAllocTextLen.offset >= 0; }
   FieldEncodedAllocTextLen::ValueType getEncodedAllocTextLen() const { return fieldEncodedAllocTextLen.getValue( buf ); }
   const char * ptrToEncodedAllocTextLen() const { return buf + fieldEncodedAllocTextLen.offset; }
   private: FieldEncodedAllocTextLen fieldEncodedAllocTextLen;

   public:
   bool isSetEncodedAllocText() const { return fieldEncodedAllocText.offset >= 0; }
   FieldEncodedAllocText::ValueType getEncodedAllocText() const { return fieldEncodedAllocText.getValue( buf ); }
   const char * ptrToEncodedAllocText() const { return buf + fieldEncodedAllocText.offset; }
   private: FieldEncodedAllocText fieldEncodedAllocText;

};

class GroupTradingSessions : public MessageBase
{
  
// Methods
   public:
   GroupTradingSessions();
   typedef std::vector<GroupTradingSessions> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetTradingSessionID() const { return fieldTradingSessionID.offset >= 0; }
   FieldTradingSessionID::ValueType getTradingSessionID() const { return fieldTradingSessionID.getValue( buf ); }
   const char * ptrToTradingSessionID() const { return buf + fieldTradingSessionID.offset; }
   private: FieldTradingSessionID fieldTradingSessionID;

   public:
   bool isSetTradingSessionSubID() const { return fieldTradingSessionSubID.offset >= 0; }
   FieldTradingSessionSubID::ValueType getTradingSessionSubID() const { return fieldTradingSessionSubID.getValue( buf ); }
   const char * ptrToTradingSessionSubID() const { return buf + fieldTradingSessionSubID.offset; }
   private: FieldTradingSessionSubID fieldTradingSessionSubID;

};

class GroupSecurityAltID : public MessageBase
{
  
// Methods
   public:
   GroupSecurityAltID();
   typedef std::vector<GroupSecurityAltID> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSecurityAltID() const { return fieldSecurityAltID.offset >= 0; }
   FieldSecurityAltID::ValueType getSecurityAltID() const { return fieldSecurityAltID.getValue( buf ); }
   const char * ptrToSecurityAltID() const { return buf + fieldSecurityAltID.offset; }
   private: FieldSecurityAltID fieldSecurityAltID;

   public:
   bool isSetSecurityAltIDSource() const { return fieldSecurityAltIDSource.offset >= 0; }
   FieldSecurityAltIDSource::ValueType getSecurityAltIDSource() const { return fieldSecurityAltIDSource.getValue( buf ); }
   const char * ptrToSecurityAltIDSource() const { return buf + fieldSecurityAltIDSource.offset; }
   private: FieldSecurityAltIDSource fieldSecurityAltIDSource;

};

class GroupUnderlyingSecurityAltID : public MessageBase
{
  
// Methods
   public:
   GroupUnderlyingSecurityAltID();
   typedef std::vector<GroupUnderlyingSecurityAltID> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetUnderlyingSecurityAltID() const { return fieldUnderlyingSecurityAltID.offset >= 0; }
   FieldUnderlyingSecurityAltID::ValueType getUnderlyingSecurityAltID() const { return fieldUnderlyingSecurityAltID.getValue( buf ); }
   const char * ptrToUnderlyingSecurityAltID() const { return buf + fieldUnderlyingSecurityAltID.offset; }
   private: FieldUnderlyingSecurityAltID fieldUnderlyingSecurityAltID;

   public:
   bool isSetUnderlyingSecurityAltIDSource() const { return fieldUnderlyingSecurityAltIDSource.offset >= 0; }
   FieldUnderlyingSecurityAltIDSource::ValueType getUnderlyingSecurityAltIDSource() const { return fieldUnderlyingSecurityAltIDSource.getValue( buf ); }
   const char * ptrToUnderlyingSecurityAltIDSource() const { return buf + fieldUnderlyingSecurityAltIDSource.offset; }
   private: FieldUnderlyingSecurityAltIDSource fieldUnderlyingSecurityAltIDSource;

};

class GroupUnderlyingStips : public MessageBase
{
  
// Methods
   public:
   GroupUnderlyingStips();
   typedef std::vector<GroupUnderlyingStips> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetUnderlyingStipType() const { return fieldUnderlyingStipType.offset >= 0; }
   FieldUnderlyingStipType::ValueType getUnderlyingStipType() const { return fieldUnderlyingStipType.getValue( buf ); }
   const char * ptrToUnderlyingStipType() const { return buf + fieldUnderlyingStipType.offset; }
   private: FieldUnderlyingStipType fieldUnderlyingStipType;

   public:
   bool isSetUnderlyingStipValue() const { return fieldUnderlyingStipValue.offset >= 0; }
   FieldUnderlyingStipValue::ValueType getUnderlyingStipValue() const { return fieldUnderlyingStipValue.getValue( buf ); }
   const char * ptrToUnderlyingStipValue() const { return buf + fieldUnderlyingStipValue.offset; }
   private: FieldUnderlyingStipValue fieldUnderlyingStipValue;

};

class GroupUnderlyings : public MessageBase
{
  
// Methods
   public:
   GroupUnderlyings();
   typedef std::vector<GroupUnderlyings> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetUnderlyingSymbol() const { return fieldUnderlyingSymbol.offset >= 0; }
   FieldUnderlyingSymbol::ValueType getUnderlyingSymbol() const { return fieldUnderlyingSymbol.getValue( buf ); }
   const char * ptrToUnderlyingSymbol() const { return buf + fieldUnderlyingSymbol.offset; }
   private: FieldUnderlyingSymbol fieldUnderlyingSymbol;

   public:
   bool isSetUnderlyingSymbolSfx() const { return fieldUnderlyingSymbolSfx.offset >= 0; }
   FieldUnderlyingSymbolSfx::ValueType getUnderlyingSymbolSfx() const { return fieldUnderlyingSymbolSfx.getValue( buf ); }
   const char * ptrToUnderlyingSymbolSfx() const { return buf + fieldUnderlyingSymbolSfx.offset; }
   private: FieldUnderlyingSymbolSfx fieldUnderlyingSymbolSfx;

   public:
   bool isSetUnderlyingSecurityID() const { return fieldUnderlyingSecurityID.offset >= 0; }
   FieldUnderlyingSecurityID::ValueType getUnderlyingSecurityID() const { return fieldUnderlyingSecurityID.getValue( buf ); }
   const char * ptrToUnderlyingSecurityID() const { return buf + fieldUnderlyingSecurityID.offset; }
   private: FieldUnderlyingSecurityID fieldUnderlyingSecurityID;

   public:
   bool isSetUnderlyingSecurityIDSource() const { return fieldUnderlyingSecurityIDSource.offset >= 0; }
   FieldUnderlyingSecurityIDSource::ValueType getUnderlyingSecurityIDSource() const { return fieldUnderlyingSecurityIDSource.getValue( buf ); }
   const char * ptrToUnderlyingSecurityIDSource() const { return buf + fieldUnderlyingSecurityIDSource.offset; }
   private: FieldUnderlyingSecurityIDSource fieldUnderlyingSecurityIDSource;

   public:
   bool isSetNoUnderlyingSecurityAltID() const { return fieldNoUnderlyingSecurityAltID.offset >= 0; }
   FieldNoUnderlyingSecurityAltID::ValueType getNoUnderlyingSecurityAltID() const { return fieldNoUnderlyingSecurityAltID.getValue( buf ); }
   const char * ptrToNoUnderlyingSecurityAltID() const { return buf + fieldNoUnderlyingSecurityAltID.offset; }
   private: FieldNoUnderlyingSecurityAltID fieldNoUnderlyingSecurityAltID;
  
   public:
   size_t getGroupCountUnderlyingSecurityAltID() const { return groupsUnderlyingSecurityAltID.size(); } 
   const GroupUnderlyingSecurityAltID & getGroupUnderlyingSecurityAltID( size_t idx ) const { return groupsUnderlyingSecurityAltID[ idx ]; } 
   private: GroupUnderlyingSecurityAltID::Array groupsUnderlyingSecurityAltID{ 10 };

   public:
   bool isSetUnderlyingProduct() const { return fieldUnderlyingProduct.offset >= 0; }
   FieldUnderlyingProduct::ValueType getUnderlyingProduct() const { return fieldUnderlyingProduct.getValue( buf ); }
   const char * ptrToUnderlyingProduct() const { return buf + fieldUnderlyingProduct.offset; }
   private: FieldUnderlyingProduct fieldUnderlyingProduct;

   public:
   bool isSetUnderlyingCFICode() const { return fieldUnderlyingCFICode.offset >= 0; }
   FieldUnderlyingCFICode::ValueType getUnderlyingCFICode() const { return fieldUnderlyingCFICode.getValue( buf ); }
   const char * ptrToUnderlyingCFICode() const { return buf + fieldUnderlyingCFICode.offset; }
   private: FieldUnderlyingCFICode fieldUnderlyingCFICode;

   public:
   bool isSetUnderlyingSecurityType() const { return fieldUnderlyingSecurityType.offset >= 0; }
   FieldUnderlyingSecurityType::ValueType getUnderlyingSecurityType() const { return fieldUnderlyingSecurityType.getValue( buf ); }
   const char * ptrToUnderlyingSecurityType() const { return buf + fieldUnderlyingSecurityType.offset; }
   private: FieldUnderlyingSecurityType fieldUnderlyingSecurityType;

   public:
   bool isSetUnderlyingSecuritySubType() const { return fieldUnderlyingSecuritySubType.offset >= 0; }
   FieldUnderlyingSecuritySubType::ValueType getUnderlyingSecuritySubType() const { return fieldUnderlyingSecuritySubType.getValue( buf ); }
   const char * ptrToUnderlyingSecuritySubType() const { return buf + fieldUnderlyingSecuritySubType.offset; }
   private: FieldUnderlyingSecuritySubType fieldUnderlyingSecuritySubType;

   public:
   bool isSetUnderlyingMaturityMonthYear() const { return fieldUnderlyingMaturityMonthYear.offset >= 0; }
   FieldUnderlyingMaturityMonthYear::ValueType getUnderlyingMaturityMonthYear() const { return fieldUnderlyingMaturityMonthYear.getValue( buf ); }
   const char * ptrToUnderlyingMaturityMonthYear() const { return buf + fieldUnderlyingMaturityMonthYear.offset; }
   private: FieldUnderlyingMaturityMonthYear fieldUnderlyingMaturityMonthYear;

   public:
   bool isSetUnderlyingMaturityDate() const { return fieldUnderlyingMaturityDate.offset >= 0; }
   FieldUnderlyingMaturityDate::ValueType getUnderlyingMaturityDate() const { return fieldUnderlyingMaturityDate.getValue( buf ); }
   const char * ptrToUnderlyingMaturityDate() const { return buf + fieldUnderlyingMaturityDate.offset; }
   private: FieldUnderlyingMaturityDate fieldUnderlyingMaturityDate;

   public:
   bool isSetUnderlyingPutOrCall() const { return fieldUnderlyingPutOrCall.offset >= 0; }
   FieldUnderlyingPutOrCall::ValueType getUnderlyingPutOrCall() const { return fieldUnderlyingPutOrCall.getValue( buf ); }
   const char * ptrToUnderlyingPutOrCall() const { return buf + fieldUnderlyingPutOrCall.offset; }
   private: FieldUnderlyingPutOrCall fieldUnderlyingPutOrCall;

   public:
   bool isSetUnderlyingCouponPaymentDate() const { return fieldUnderlyingCouponPaymentDate.offset >= 0; }
   FieldUnderlyingCouponPaymentDate::ValueType getUnderlyingCouponPaymentDate() const { return fieldUnderlyingCouponPaymentDate.getValue( buf ); }
   const char * ptrToUnderlyingCouponPaymentDate() const { return buf + fieldUnderlyingCouponPaymentDate.offset; }
   private: FieldUnderlyingCouponPaymentDate fieldUnderlyingCouponPaymentDate;

   public:
   bool isSetUnderlyingIssueDate() const { return fieldUnderlyingIssueDate.offset >= 0; }
   FieldUnderlyingIssueDate::ValueType getUnderlyingIssueDate() const { return fieldUnderlyingIssueDate.getValue( buf ); }
   const char * ptrToUnderlyingIssueDate() const { return buf + fieldUnderlyingIssueDate.offset; }
   private: FieldUnderlyingIssueDate fieldUnderlyingIssueDate;

   public:
   bool isSetUnderlyingRepoCollateralSecurityType() const { return fieldUnderlyingRepoCollateralSecurityType.offset >= 0; }
   FieldUnderlyingRepoCollateralSecurityType::ValueType getUnderlyingRepoCollateralSecurityType() const { return fieldUnderlyingRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToUnderlyingRepoCollateralSecurityType() const { return buf + fieldUnderlyingRepoCollateralSecurityType.offset; }
   private: FieldUnderlyingRepoCollateralSecurityType fieldUnderlyingRepoCollateralSecurityType;

   public:
   bool isSetUnderlyingRepurchaseTerm() const { return fieldUnderlyingRepurchaseTerm.offset >= 0; }
   FieldUnderlyingRepurchaseTerm::ValueType getUnderlyingRepurchaseTerm() const { return fieldUnderlyingRepurchaseTerm.getValue( buf ); }
   const char * ptrToUnderlyingRepurchaseTerm() const { return buf + fieldUnderlyingRepurchaseTerm.offset; }
   private: FieldUnderlyingRepurchaseTerm fieldUnderlyingRepurchaseTerm;

   public:
   bool isSetUnderlyingRepurchaseRate() const { return fieldUnderlyingRepurchaseRate.offset >= 0; }
   FieldUnderlyingRepurchaseRate::ValueType getUnderlyingRepurchaseRate() const { return fieldUnderlyingRepurchaseRate.getValue( buf ); }
   const char * ptrToUnderlyingRepurchaseRate() const { return buf + fieldUnderlyingRepurchaseRate.offset; }
   private: FieldUnderlyingRepurchaseRate fieldUnderlyingRepurchaseRate;

   public:
   bool isSetUnderlyingFactor() const { return fieldUnderlyingFactor.offset >= 0; }
   FieldUnderlyingFactor::ValueType getUnderlyingFactor() const { return fieldUnderlyingFactor.getValue( buf ); }
   const char * ptrToUnderlyingFactor() const { return buf + fieldUnderlyingFactor.offset; }
   private: FieldUnderlyingFactor fieldUnderlyingFactor;

   public:
   bool isSetUnderlyingCreditRating() const { return fieldUnderlyingCreditRating.offset >= 0; }
   FieldUnderlyingCreditRating::ValueType getUnderlyingCreditRating() const { return fieldUnderlyingCreditRating.getValue( buf ); }
   const char * ptrToUnderlyingCreditRating() const { return buf + fieldUnderlyingCreditRating.offset; }
   private: FieldUnderlyingCreditRating fieldUnderlyingCreditRating;

   public:
   bool isSetUnderlyingInstrRegistry() const { return fieldUnderlyingInstrRegistry.offset >= 0; }
   FieldUnderlyingInstrRegistry::ValueType getUnderlyingInstrRegistry() const { return fieldUnderlyingInstrRegistry.getValue( buf ); }
   const char * ptrToUnderlyingInstrRegistry() const { return buf + fieldUnderlyingInstrRegistry.offset; }
   private: FieldUnderlyingInstrRegistry fieldUnderlyingInstrRegistry;

   public:
   bool isSetUnderlyingCountryOfIssue() const { return fieldUnderlyingCountryOfIssue.offset >= 0; }
   FieldUnderlyingCountryOfIssue::ValueType getUnderlyingCountryOfIssue() const { return fieldUnderlyingCountryOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingCountryOfIssue() const { return buf + fieldUnderlyingCountryOfIssue.offset; }
   private: FieldUnderlyingCountryOfIssue fieldUnderlyingCountryOfIssue;

   public:
   bool isSetUnderlyingStateOrProvinceOfIssue() const { return fieldUnderlyingStateOrProvinceOfIssue.offset >= 0; }
   FieldUnderlyingStateOrProvinceOfIssue::ValueType getUnderlyingStateOrProvinceOfIssue() const { return fieldUnderlyingStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingStateOrProvinceOfIssue() const { return buf + fieldUnderlyingStateOrProvinceOfIssue.offset; }
   private: FieldUnderlyingStateOrProvinceOfIssue fieldUnderlyingStateOrProvinceOfIssue;

   public:
   bool isSetUnderlyingLocaleOfIssue() const { return fieldUnderlyingLocaleOfIssue.offset >= 0; }
   FieldUnderlyingLocaleOfIssue::ValueType getUnderlyingLocaleOfIssue() const { return fieldUnderlyingLocaleOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingLocaleOfIssue() const { return buf + fieldUnderlyingLocaleOfIssue.offset; }
   private: FieldUnderlyingLocaleOfIssue fieldUnderlyingLocaleOfIssue;

   public:
   bool isSetUnderlyingRedemptionDate() const { return fieldUnderlyingRedemptionDate.offset >= 0; }
   FieldUnderlyingRedemptionDate::ValueType getUnderlyingRedemptionDate() const { return fieldUnderlyingRedemptionDate.getValue( buf ); }
   const char * ptrToUnderlyingRedemptionDate() const { return buf + fieldUnderlyingRedemptionDate.offset; }
   private: FieldUnderlyingRedemptionDate fieldUnderlyingRedemptionDate;

   public:
   bool isSetUnderlyingStrikePrice() const { return fieldUnderlyingStrikePrice.offset >= 0; }
   FieldUnderlyingStrikePrice::ValueType getUnderlyingStrikePrice() const { return fieldUnderlyingStrikePrice.getValue( buf ); }
   const char * ptrToUnderlyingStrikePrice() const { return buf + fieldUnderlyingStrikePrice.offset; }
   private: FieldUnderlyingStrikePrice fieldUnderlyingStrikePrice;

   public:
   bool isSetUnderlyingStrikeCurrency() const { return fieldUnderlyingStrikeCurrency.offset >= 0; }
   FieldUnderlyingStrikeCurrency::ValueType getUnderlyingStrikeCurrency() const { return fieldUnderlyingStrikeCurrency.getValue( buf ); }
   const char * ptrToUnderlyingStrikeCurrency() const { return buf + fieldUnderlyingStrikeCurrency.offset; }
   private: FieldUnderlyingStrikeCurrency fieldUnderlyingStrikeCurrency;

   public:
   bool isSetUnderlyingOptAttribute() const { return fieldUnderlyingOptAttribute.offset >= 0; }
   FieldUnderlyingOptAttribute::ValueType getUnderlyingOptAttribute() const { return fieldUnderlyingOptAttribute.getValue( buf ); }
   const char * ptrToUnderlyingOptAttribute() const { return buf + fieldUnderlyingOptAttribute.offset; }
   private: FieldUnderlyingOptAttribute fieldUnderlyingOptAttribute;

   public:
   bool isSetUnderlyingContractMultiplier() const { return fieldUnderlyingContractMultiplier.offset >= 0; }
   FieldUnderlyingContractMultiplier::ValueType getUnderlyingContractMultiplier() const { return fieldUnderlyingContractMultiplier.getValue( buf ); }
   const char * ptrToUnderlyingContractMultiplier() const { return buf + fieldUnderlyingContractMultiplier.offset; }
   private: FieldUnderlyingContractMultiplier fieldUnderlyingContractMultiplier;

   public:
   bool isSetUnderlyingCouponRate() const { return fieldUnderlyingCouponRate.offset >= 0; }
   FieldUnderlyingCouponRate::ValueType getUnderlyingCouponRate() const { return fieldUnderlyingCouponRate.getValue( buf ); }
   const char * ptrToUnderlyingCouponRate() const { return buf + fieldUnderlyingCouponRate.offset; }
   private: FieldUnderlyingCouponRate fieldUnderlyingCouponRate;

   public:
   bool isSetUnderlyingSecurityExchange() const { return fieldUnderlyingSecurityExchange.offset >= 0; }
   FieldUnderlyingSecurityExchange::ValueType getUnderlyingSecurityExchange() const { return fieldUnderlyingSecurityExchange.getValue( buf ); }
   const char * ptrToUnderlyingSecurityExchange() const { return buf + fieldUnderlyingSecurityExchange.offset; }
   private: FieldUnderlyingSecurityExchange fieldUnderlyingSecurityExchange;

   public:
   bool isSetUnderlyingIssuer() const { return fieldUnderlyingIssuer.offset >= 0; }
   FieldUnderlyingIssuer::ValueType getUnderlyingIssuer() const { return fieldUnderlyingIssuer.getValue( buf ); }
   const char * ptrToUnderlyingIssuer() const { return buf + fieldUnderlyingIssuer.offset; }
   private: FieldUnderlyingIssuer fieldUnderlyingIssuer;

   public:
   bool isSetEncodedUnderlyingIssuerLen() const { return fieldEncodedUnderlyingIssuerLen.offset >= 0; }
   FieldEncodedUnderlyingIssuerLen::ValueType getEncodedUnderlyingIssuerLen() const { return fieldEncodedUnderlyingIssuerLen.getValue( buf ); }
   const char * ptrToEncodedUnderlyingIssuerLen() const { return buf + fieldEncodedUnderlyingIssuerLen.offset; }
   private: FieldEncodedUnderlyingIssuerLen fieldEncodedUnderlyingIssuerLen;

   public:
   bool isSetEncodedUnderlyingIssuer() const { return fieldEncodedUnderlyingIssuer.offset >= 0; }
   FieldEncodedUnderlyingIssuer::ValueType getEncodedUnderlyingIssuer() const { return fieldEncodedUnderlyingIssuer.getValue( buf ); }
   const char * ptrToEncodedUnderlyingIssuer() const { return buf + fieldEncodedUnderlyingIssuer.offset; }
   private: FieldEncodedUnderlyingIssuer fieldEncodedUnderlyingIssuer;

   public:
   bool isSetUnderlyingSecurityDesc() const { return fieldUnderlyingSecurityDesc.offset >= 0; }
   FieldUnderlyingSecurityDesc::ValueType getUnderlyingSecurityDesc() const { return fieldUnderlyingSecurityDesc.getValue( buf ); }
   const char * ptrToUnderlyingSecurityDesc() const { return buf + fieldUnderlyingSecurityDesc.offset; }
   private: FieldUnderlyingSecurityDesc fieldUnderlyingSecurityDesc;

   public:
   bool isSetEncodedUnderlyingSecurityDescLen() const { return fieldEncodedUnderlyingSecurityDescLen.offset >= 0; }
   FieldEncodedUnderlyingSecurityDescLen::ValueType getEncodedUnderlyingSecurityDescLen() const { return fieldEncodedUnderlyingSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedUnderlyingSecurityDescLen() const { return buf + fieldEncodedUnderlyingSecurityDescLen.offset; }
   private: FieldEncodedUnderlyingSecurityDescLen fieldEncodedUnderlyingSecurityDescLen;

   public:
   bool isSetEncodedUnderlyingSecurityDesc() const { return fieldEncodedUnderlyingSecurityDesc.offset >= 0; }
   FieldEncodedUnderlyingSecurityDesc::ValueType getEncodedUnderlyingSecurityDesc() const { return fieldEncodedUnderlyingSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedUnderlyingSecurityDesc() const { return buf + fieldEncodedUnderlyingSecurityDesc.offset; }
   private: FieldEncodedUnderlyingSecurityDesc fieldEncodedUnderlyingSecurityDesc;

   public:
   bool isSetUnderlyingCPProgram() const { return fieldUnderlyingCPProgram.offset >= 0; }
   FieldUnderlyingCPProgram::ValueType getUnderlyingCPProgram() const { return fieldUnderlyingCPProgram.getValue( buf ); }
   const char * ptrToUnderlyingCPProgram() const { return buf + fieldUnderlyingCPProgram.offset; }
   private: FieldUnderlyingCPProgram fieldUnderlyingCPProgram;

   public:
   bool isSetUnderlyingCPRegType() const { return fieldUnderlyingCPRegType.offset >= 0; }
   FieldUnderlyingCPRegType::ValueType getUnderlyingCPRegType() const { return fieldUnderlyingCPRegType.getValue( buf ); }
   const char * ptrToUnderlyingCPRegType() const { return buf + fieldUnderlyingCPRegType.offset; }
   private: FieldUnderlyingCPRegType fieldUnderlyingCPRegType;

   public:
   bool isSetUnderlyingCurrency() const { return fieldUnderlyingCurrency.offset >= 0; }
   FieldUnderlyingCurrency::ValueType getUnderlyingCurrency() const { return fieldUnderlyingCurrency.getValue( buf ); }
   const char * ptrToUnderlyingCurrency() const { return buf + fieldUnderlyingCurrency.offset; }
   private: FieldUnderlyingCurrency fieldUnderlyingCurrency;

   public:
   bool isSetUnderlyingQty() const { return fieldUnderlyingQty.offset >= 0; }
   FieldUnderlyingQty::ValueType getUnderlyingQty() const { return fieldUnderlyingQty.getValue( buf ); }
   const char * ptrToUnderlyingQty() const { return buf + fieldUnderlyingQty.offset; }
   private: FieldUnderlyingQty fieldUnderlyingQty;

   public:
   bool isSetUnderlyingPx() const { return fieldUnderlyingPx.offset >= 0; }
   FieldUnderlyingPx::ValueType getUnderlyingPx() const { return fieldUnderlyingPx.getValue( buf ); }
   const char * ptrToUnderlyingPx() const { return buf + fieldUnderlyingPx.offset; }
   private: FieldUnderlyingPx fieldUnderlyingPx;

   public:
   bool isSetUnderlyingDirtyPrice() const { return fieldUnderlyingDirtyPrice.offset >= 0; }
   FieldUnderlyingDirtyPrice::ValueType getUnderlyingDirtyPrice() const { return fieldUnderlyingDirtyPrice.getValue( buf ); }
   const char * ptrToUnderlyingDirtyPrice() const { return buf + fieldUnderlyingDirtyPrice.offset; }
   private: FieldUnderlyingDirtyPrice fieldUnderlyingDirtyPrice;

   public:
   bool isSetUnderlyingEndPrice() const { return fieldUnderlyingEndPrice.offset >= 0; }
   FieldUnderlyingEndPrice::ValueType getUnderlyingEndPrice() const { return fieldUnderlyingEndPrice.getValue( buf ); }
   const char * ptrToUnderlyingEndPrice() const { return buf + fieldUnderlyingEndPrice.offset; }
   private: FieldUnderlyingEndPrice fieldUnderlyingEndPrice;

   public:
   bool isSetUnderlyingStartValue() const { return fieldUnderlyingStartValue.offset >= 0; }
   FieldUnderlyingStartValue::ValueType getUnderlyingStartValue() const { return fieldUnderlyingStartValue.getValue( buf ); }
   const char * ptrToUnderlyingStartValue() const { return buf + fieldUnderlyingStartValue.offset; }
   private: FieldUnderlyingStartValue fieldUnderlyingStartValue;

   public:
   bool isSetUnderlyingCurrentValue() const { return fieldUnderlyingCurrentValue.offset >= 0; }
   FieldUnderlyingCurrentValue::ValueType getUnderlyingCurrentValue() const { return fieldUnderlyingCurrentValue.getValue( buf ); }
   const char * ptrToUnderlyingCurrentValue() const { return buf + fieldUnderlyingCurrentValue.offset; }
   private: FieldUnderlyingCurrentValue fieldUnderlyingCurrentValue;

   public:
   bool isSetUnderlyingEndValue() const { return fieldUnderlyingEndValue.offset >= 0; }
   FieldUnderlyingEndValue::ValueType getUnderlyingEndValue() const { return fieldUnderlyingEndValue.getValue( buf ); }
   const char * ptrToUnderlyingEndValue() const { return buf + fieldUnderlyingEndValue.offset; }
   private: FieldUnderlyingEndValue fieldUnderlyingEndValue;

   public:
   bool isSetNoUnderlyingStips() const { return fieldNoUnderlyingStips.offset >= 0; }
   FieldNoUnderlyingStips::ValueType getNoUnderlyingStips() const { return fieldNoUnderlyingStips.getValue( buf ); }
   const char * ptrToNoUnderlyingStips() const { return buf + fieldNoUnderlyingStips.offset; }
   private: FieldNoUnderlyingStips fieldNoUnderlyingStips;
  
   public:
   size_t getGroupCountUnderlyingStips() const { return groupsUnderlyingStips.size(); } 
   const GroupUnderlyingStips & getGroupUnderlyingStips( size_t idx ) const { return groupsUnderlyingStips[ idx ]; } 
   private: GroupUnderlyingStips::Array groupsUnderlyingStips{ 10 };

   public:
   bool isSetUnderlyingSettlPrice() const { return fieldUnderlyingSettlPrice.offset >= 0; }
   FieldUnderlyingSettlPrice::ValueType getUnderlyingSettlPrice() const { return fieldUnderlyingSettlPrice.getValue( buf ); }
   const char * ptrToUnderlyingSettlPrice() const { return buf + fieldUnderlyingSettlPrice.offset; }
   private: FieldUnderlyingSettlPrice fieldUnderlyingSettlPrice;

   public:
   bool isSetUnderlyingSettlPriceType() const { return fieldUnderlyingSettlPriceType.offset >= 0; }
   FieldUnderlyingSettlPriceType::ValueType getUnderlyingSettlPriceType() const { return fieldUnderlyingSettlPriceType.getValue( buf ); }
   const char * ptrToUnderlyingSettlPriceType() const { return buf + fieldUnderlyingSettlPriceType.offset; }
   private: FieldUnderlyingSettlPriceType fieldUnderlyingSettlPriceType;

};

class GroupStipulations : public MessageBase
{
  
// Methods
   public:
   GroupStipulations();
   typedef std::vector<GroupStipulations> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetStipulationType() const { return fieldStipulationType.offset >= 0; }
   FieldStipulationType::ValueType getStipulationType() const { return fieldStipulationType.getValue( buf ); }
   const char * ptrToStipulationType() const { return buf + fieldStipulationType.offset; }
   private: FieldStipulationType fieldStipulationType;

   public:
   bool isSetStipulationValue() const { return fieldStipulationValue.offset >= 0; }
   FieldStipulationValue::ValueType getStipulationValue() const { return fieldStipulationValue.getValue( buf ); }
   const char * ptrToStipulationValue() const { return buf + fieldStipulationValue.offset; }
   private: FieldStipulationValue fieldStipulationValue;

};

class GroupOrders : public MessageBase
{
  
// Methods
   public:
   GroupOrders();
   typedef std::vector<GroupOrders> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetClOrdID() const { return fieldClOrdID.offset >= 0; }
   FieldClOrdID::ValueType getClOrdID() const { return fieldClOrdID.getValue( buf ); }
   const char * ptrToClOrdID() const { return buf + fieldClOrdID.offset; }
   private: FieldClOrdID fieldClOrdID;

   public:
   bool isSetSecondaryClOrdID() const { return fieldSecondaryClOrdID.offset >= 0; }
   FieldSecondaryClOrdID::ValueType getSecondaryClOrdID() const { return fieldSecondaryClOrdID.getValue( buf ); }
   const char * ptrToSecondaryClOrdID() const { return buf + fieldSecondaryClOrdID.offset; }
   private: FieldSecondaryClOrdID fieldSecondaryClOrdID;

   public:
   bool isSetListSeqNo() const { return fieldListSeqNo.offset >= 0; }
   FieldListSeqNo::ValueType getListSeqNo() const { return fieldListSeqNo.getValue( buf ); }
   const char * ptrToListSeqNo() const { return buf + fieldListSeqNo.offset; }
   private: FieldListSeqNo fieldListSeqNo;

   public:
   bool isSetClOrdLinkID() const { return fieldClOrdLinkID.offset >= 0; }
   FieldClOrdLinkID::ValueType getClOrdLinkID() const { return fieldClOrdLinkID.getValue( buf ); }
   const char * ptrToClOrdLinkID() const { return buf + fieldClOrdLinkID.offset; }
   private: FieldClOrdLinkID fieldClOrdLinkID;

   public:
   bool isSetSettlInstMode() const { return fieldSettlInstMode.offset >= 0; }
   FieldSettlInstMode::ValueType getSettlInstMode() const { return fieldSettlInstMode.getValue( buf ); }
   const char * ptrToSettlInstMode() const { return buf + fieldSettlInstMode.offset; }
   private: FieldSettlInstMode fieldSettlInstMode;

   public:
   bool isSetNoPartyIDs() const { return fieldNoPartyIDs.offset >= 0; }
   FieldNoPartyIDs::ValueType getNoPartyIDs() const { return fieldNoPartyIDs.getValue( buf ); }
   const char * ptrToNoPartyIDs() const { return buf + fieldNoPartyIDs.offset; }
   private: FieldNoPartyIDs fieldNoPartyIDs;
  
   public:
   size_t getGroupCountPartyIDs() const { return groupsPartyIDs.size(); } 
   const GroupPartyIDs & getGroupPartyIDs( size_t idx ) const { return groupsPartyIDs[ idx ]; } 
   private: GroupPartyIDs::Array groupsPartyIDs{ 10 };

   public:
   bool isSetTradeOriginationDate() const { return fieldTradeOriginationDate.offset >= 0; }
   FieldTradeOriginationDate::ValueType getTradeOriginationDate() const { return fieldTradeOriginationDate.getValue( buf ); }
   const char * ptrToTradeOriginationDate() const { return buf + fieldTradeOriginationDate.offset; }
   private: FieldTradeOriginationDate fieldTradeOriginationDate;

   public:
   bool isSetTradeDate() const { return fieldTradeDate.offset >= 0; }
   FieldTradeDate::ValueType getTradeDate() const { return fieldTradeDate.getValue( buf ); }
   const char * ptrToTradeDate() const { return buf + fieldTradeDate.offset; }
   private: FieldTradeDate fieldTradeDate;

   public:
   bool isSetAccount() const { return fieldAccount.offset >= 0; }
   FieldAccount::ValueType getAccount() const { return fieldAccount.getValue( buf ); }
   const char * ptrToAccount() const { return buf + fieldAccount.offset; }
   private: FieldAccount fieldAccount;

   public:
   bool isSetAcctIDSource() const { return fieldAcctIDSource.offset >= 0; }
   FieldAcctIDSource::ValueType getAcctIDSource() const { return fieldAcctIDSource.getValue( buf ); }
   const char * ptrToAcctIDSource() const { return buf + fieldAcctIDSource.offset; }
   private: FieldAcctIDSource fieldAcctIDSource;

   public:
   bool isSetAccountType() const { return fieldAccountType.offset >= 0; }
   FieldAccountType::ValueType getAccountType() const { return fieldAccountType.getValue( buf ); }
   const char * ptrToAccountType() const { return buf + fieldAccountType.offset; }
   private: FieldAccountType fieldAccountType;

   public:
   bool isSetDayBookingInst() const { return fieldDayBookingInst.offset >= 0; }
   FieldDayBookingInst::ValueType getDayBookingInst() const { return fieldDayBookingInst.getValue( buf ); }
   const char * ptrToDayBookingInst() const { return buf + fieldDayBookingInst.offset; }
   private: FieldDayBookingInst fieldDayBookingInst;

   public:
   bool isSetBookingUnit() const { return fieldBookingUnit.offset >= 0; }
   FieldBookingUnit::ValueType getBookingUnit() const { return fieldBookingUnit.getValue( buf ); }
   const char * ptrToBookingUnit() const { return buf + fieldBookingUnit.offset; }
   private: FieldBookingUnit fieldBookingUnit;

   public:
   bool isSetAllocID() const { return fieldAllocID.offset >= 0; }
   FieldAllocID::ValueType getAllocID() const { return fieldAllocID.getValue( buf ); }
   const char * ptrToAllocID() const { return buf + fieldAllocID.offset; }
   private: FieldAllocID fieldAllocID;

   public:
   bool isSetPreallocMethod() const { return fieldPreallocMethod.offset >= 0; }
   FieldPreallocMethod::ValueType getPreallocMethod() const { return fieldPreallocMethod.getValue( buf ); }
   const char * ptrToPreallocMethod() const { return buf + fieldPreallocMethod.offset; }
   private: FieldPreallocMethod fieldPreallocMethod;

   public:
   bool isSetNoAllocs() const { return fieldNoAllocs.offset >= 0; }
   FieldNoAllocs::ValueType getNoAllocs() const { return fieldNoAllocs.getValue( buf ); }
   const char * ptrToNoAllocs() const { return buf + fieldNoAllocs.offset; }
   private: FieldNoAllocs fieldNoAllocs;
  
   public:
   size_t getGroupCountAllocs() const { return groupsAllocs.size(); } 
   const GroupAllocs & getGroupAllocs( size_t idx ) const { return groupsAllocs[ idx ]; } 
   private: GroupAllocs::Array groupsAllocs{ 10 };

   public:
   bool isSetSettlType() const { return fieldSettlType.offset >= 0; }
   FieldSettlType::ValueType getSettlType() const { return fieldSettlType.getValue( buf ); }
   const char * ptrToSettlType() const { return buf + fieldSettlType.offset; }
   private: FieldSettlType fieldSettlType;

   public:
   bool isSetSettlDate() const { return fieldSettlDate.offset >= 0; }
   FieldSettlDate::ValueType getSettlDate() const { return fieldSettlDate.getValue( buf ); }
   const char * ptrToSettlDate() const { return buf + fieldSettlDate.offset; }
   private: FieldSettlDate fieldSettlDate;

   public:
   bool isSetCashMargin() const { return fieldCashMargin.offset >= 0; }
   FieldCashMargin::ValueType getCashMargin() const { return fieldCashMargin.getValue( buf ); }
   const char * ptrToCashMargin() const { return buf + fieldCashMargin.offset; }
   private: FieldCashMargin fieldCashMargin;

   public:
   bool isSetClearingFeeIndicator() const { return fieldClearingFeeIndicator.offset >= 0; }
   FieldClearingFeeIndicator::ValueType getClearingFeeIndicator() const { return fieldClearingFeeIndicator.getValue( buf ); }
   const char * ptrToClearingFeeIndicator() const { return buf + fieldClearingFeeIndicator.offset; }
   private: FieldClearingFeeIndicator fieldClearingFeeIndicator;

   public:
   bool isSetHandlInst() const { return fieldHandlInst.offset >= 0; }
   FieldHandlInst::ValueType getHandlInst() const { return fieldHandlInst.getValue( buf ); }
   const char * ptrToHandlInst() const { return buf + fieldHandlInst.offset; }
   private: FieldHandlInst fieldHandlInst;

   public:
   bool isSetExecInst() const { return fieldExecInst.offset >= 0; }
   FieldExecInst::ValueType getExecInst() const { return fieldExecInst.getValue( buf ); }
   const char * ptrToExecInst() const { return buf + fieldExecInst.offset; }
   private: FieldExecInst fieldExecInst;

   public:
   bool isSetMinQty() const { return fieldMinQty.offset >= 0; }
   FieldMinQty::ValueType getMinQty() const { return fieldMinQty.getValue( buf ); }
   const char * ptrToMinQty() const { return buf + fieldMinQty.offset; }
   private: FieldMinQty fieldMinQty;

   public:
   bool isSetMaxFloor() const { return fieldMaxFloor.offset >= 0; }
   FieldMaxFloor::ValueType getMaxFloor() const { return fieldMaxFloor.getValue( buf ); }
   const char * ptrToMaxFloor() const { return buf + fieldMaxFloor.offset; }
   private: FieldMaxFloor fieldMaxFloor;

   public:
   bool isSetExDestination() const { return fieldExDestination.offset >= 0; }
   FieldExDestination::ValueType getExDestination() const { return fieldExDestination.getValue( buf ); }
   const char * ptrToExDestination() const { return buf + fieldExDestination.offset; }
   private: FieldExDestination fieldExDestination;

   public:
   bool isSetNoTradingSessions() const { return fieldNoTradingSessions.offset >= 0; }
   FieldNoTradingSessions::ValueType getNoTradingSessions() const { return fieldNoTradingSessions.getValue( buf ); }
   const char * ptrToNoTradingSessions() const { return buf + fieldNoTradingSessions.offset; }
   private: FieldNoTradingSessions fieldNoTradingSessions;
  
   public:
   size_t getGroupCountTradingSessions() const { return groupsTradingSessions.size(); } 
   const GroupTradingSessions & getGroupTradingSessions( size_t idx ) const { return groupsTradingSessions[ idx ]; } 
   private: GroupTradingSessions::Array groupsTradingSessions{ 10 };

   public:
   bool isSetProcessCode() const { return fieldProcessCode.offset >= 0; }
   FieldProcessCode::ValueType getProcessCode() const { return fieldProcessCode.getValue( buf ); }
   const char * ptrToProcessCode() const { return buf + fieldProcessCode.offset; }
   private: FieldProcessCode fieldProcessCode;

   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSymbolSfx() const { return fieldSymbolSfx.offset >= 0; }
   FieldSymbolSfx::ValueType getSymbolSfx() const { return fieldSymbolSfx.getValue( buf ); }
   const char * ptrToSymbolSfx() const { return buf + fieldSymbolSfx.offset; }
   private: FieldSymbolSfx fieldSymbolSfx;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSecurityIDSource() const { return fieldSecurityIDSource.offset >= 0; }
   FieldSecurityIDSource::ValueType getSecurityIDSource() const { return fieldSecurityIDSource.getValue( buf ); }
   const char * ptrToSecurityIDSource() const { return buf + fieldSecurityIDSource.offset; }
   private: FieldSecurityIDSource fieldSecurityIDSource;

   public:
   bool isSetNoSecurityAltID() const { return fieldNoSecurityAltID.offset >= 0; }
   FieldNoSecurityAltID::ValueType getNoSecurityAltID() const { return fieldNoSecurityAltID.getValue( buf ); }
   const char * ptrToNoSecurityAltID() const { return buf + fieldNoSecurityAltID.offset; }
   private: FieldNoSecurityAltID fieldNoSecurityAltID;
  
   public:
   size_t getGroupCountSecurityAltID() const { return groupsSecurityAltID.size(); } 
   const GroupSecurityAltID & getGroupSecurityAltID( size_t idx ) const { return groupsSecurityAltID[ idx ]; } 
   private: GroupSecurityAltID::Array groupsSecurityAltID{ 10 };

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetSecuritySubType() const { return fieldSecuritySubType.offset >= 0; }
   FieldSecuritySubType::ValueType getSecuritySubType() const { return fieldSecuritySubType.getValue( buf ); }
   const char * ptrToSecuritySubType() const { return buf + fieldSecuritySubType.offset; }
   private: FieldSecuritySubType fieldSecuritySubType;

   public:
   bool isSetMaturityMonthYear() const { return fieldMaturityMonthYear.offset >= 0; }
   FieldMaturityMonthYear::ValueType getMaturityMonthYear() const { return fieldMaturityMonthYear.getValue( buf ); }
   const char * ptrToMaturityMonthYear() const { return buf + fieldMaturityMonthYear.offset; }
   private: FieldMaturityMonthYear fieldMaturityMonthYear;

   public:
   bool isSetMaturityDate() const { return fieldMaturityDate.offset >= 0; }
   FieldMaturityDate::ValueType getMaturityDate() const { return fieldMaturityDate.getValue( buf ); }
   const char * ptrToMaturityDate() const { return buf + fieldMaturityDate.offset; }
   private: FieldMaturityDate fieldMaturityDate;

   public:
   bool isSetPutOrCall() const { return fieldPutOrCall.offset >= 0; }
   FieldPutOrCall::ValueType getPutOrCall() const { return fieldPutOrCall.getValue( buf ); }
   const char * ptrToPutOrCall() const { return buf + fieldPutOrCall.offset; }
   private: FieldPutOrCall fieldPutOrCall;

   public:
   bool isSetCouponPaymentDate() const { return fieldCouponPaymentDate.offset >= 0; }
   FieldCouponPaymentDate::ValueType getCouponPaymentDate() const { return fieldCouponPaymentDate.getValue( buf ); }
   const char * ptrToCouponPaymentDate() const { return buf + fieldCouponPaymentDate.offset; }
   private: FieldCouponPaymentDate fieldCouponPaymentDate;

   public:
   bool isSetIssueDate() const { return fieldIssueDate.offset >= 0; }
   FieldIssueDate::ValueType getIssueDate() const { return fieldIssueDate.getValue( buf ); }
   const char * ptrToIssueDate() const { return buf + fieldIssueDate.offset; }
   private: FieldIssueDate fieldIssueDate;

   public:
   bool isSetRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.offset >= 0; }
   FieldRepoCollateralSecurityType::ValueType getRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToRepoCollateralSecurityType() const { return buf + fieldRepoCollateralSecurityType.offset; }
   private: FieldRepoCollateralSecurityType fieldRepoCollateralSecurityType;

   public:
   bool isSetRepurchaseTerm() const { return fieldRepurchaseTerm.offset >= 0; }
   FieldRepurchaseTerm::ValueType getRepurchaseTerm() const { return fieldRepurchaseTerm.getValue( buf ); }
   const char * ptrToRepurchaseTerm() const { return buf + fieldRepurchaseTerm.offset; }
   private: FieldRepurchaseTerm fieldRepurchaseTerm;

   public:
   bool isSetRepurchaseRate() const { return fieldRepurchaseRate.offset >= 0; }
   FieldRepurchaseRate::ValueType getRepurchaseRate() const { return fieldRepurchaseRate.getValue( buf ); }
   const char * ptrToRepurchaseRate() const { return buf + fieldRepurchaseRate.offset; }
   private: FieldRepurchaseRate fieldRepurchaseRate;

   public:
   bool isSetFactor() const { return fieldFactor.offset >= 0; }
   FieldFactor::ValueType getFactor() const { return fieldFactor.getValue( buf ); }
   const char * ptrToFactor() const { return buf + fieldFactor.offset; }
   private: FieldFactor fieldFactor;

   public:
   bool isSetCreditRating() const { return fieldCreditRating.offset >= 0; }
   FieldCreditRating::ValueType getCreditRating() const { return fieldCreditRating.getValue( buf ); }
   const char * ptrToCreditRating() const { return buf + fieldCreditRating.offset; }
   private: FieldCreditRating fieldCreditRating;

   public:
   bool isSetInstrRegistry() const { return fieldInstrRegistry.offset >= 0; }
   FieldInstrRegistry::ValueType getInstrRegistry() const { return fieldInstrRegistry.getValue( buf ); }
   const char * ptrToInstrRegistry() const { return buf + fieldInstrRegistry.offset; }
   private: FieldInstrRegistry fieldInstrRegistry;

   public:
   bool isSetCountryOfIssue() const { return fieldCountryOfIssue.offset >= 0; }
   FieldCountryOfIssue::ValueType getCountryOfIssue() const { return fieldCountryOfIssue.getValue( buf ); }
   const char * ptrToCountryOfIssue() const { return buf + fieldCountryOfIssue.offset; }
   private: FieldCountryOfIssue fieldCountryOfIssue;

   public:
   bool isSetStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.offset >= 0; }
   FieldStateOrProvinceOfIssue::ValueType getStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToStateOrProvinceOfIssue() const { return buf + fieldStateOrProvinceOfIssue.offset; }
   private: FieldStateOrProvinceOfIssue fieldStateOrProvinceOfIssue;

   public:
   bool isSetLocaleOfIssue() const { return fieldLocaleOfIssue.offset >= 0; }
   FieldLocaleOfIssue::ValueType getLocaleOfIssue() const { return fieldLocaleOfIssue.getValue( buf ); }
   const char * ptrToLocaleOfIssue() const { return buf + fieldLocaleOfIssue.offset; }
   private: FieldLocaleOfIssue fieldLocaleOfIssue;

   public:
   bool isSetRedemptionDate() const { return fieldRedemptionDate.offset >= 0; }
   FieldRedemptionDate::ValueType getRedemptionDate() const { return fieldRedemptionDate.getValue( buf ); }
   const char * ptrToRedemptionDate() const { return buf + fieldRedemptionDate.offset; }
   private: FieldRedemptionDate fieldRedemptionDate;

   public:
   bool isSetStrikePrice() const { return fieldStrikePrice.offset >= 0; }
   FieldStrikePrice::ValueType getStrikePrice() const { return fieldStrikePrice.getValue( buf ); }
   const char * ptrToStrikePrice() const { return buf + fieldStrikePrice.offset; }
   private: FieldStrikePrice fieldStrikePrice;

   public:
   bool isSetStrikeCurrency() const { return fieldStrikeCurrency.offset >= 0; }
   FieldStrikeCurrency::ValueType getStrikeCurrency() const { return fieldStrikeCurrency.getValue( buf ); }
   const char * ptrToStrikeCurrency() const { return buf + fieldStrikeCurrency.offset; }
   private: FieldStrikeCurrency fieldStrikeCurrency;

   public:
   bool isSetOptAttribute() const { return fieldOptAttribute.offset >= 0; }
   FieldOptAttribute::ValueType getOptAttribute() const { return fieldOptAttribute.getValue( buf ); }
   const char * ptrToOptAttribute() const { return buf + fieldOptAttribute.offset; }
   private: FieldOptAttribute fieldOptAttribute;

   public:
   bool isSetContractMultiplier() const { return fieldContractMultiplier.offset >= 0; }
   FieldContractMultiplier::ValueType getContractMultiplier() const { return fieldContractMultiplier.getValue( buf ); }
   const char * ptrToContractMultiplier() const { return buf + fieldContractMultiplier.offset; }
   private: FieldContractMultiplier fieldContractMultiplier;

   public:
   bool isSetCouponRate() const { return fieldCouponRate.offset >= 0; }
   FieldCouponRate::ValueType getCouponRate() const { return fieldCouponRate.getValue( buf ); }
   const char * ptrToCouponRate() const { return buf + fieldCouponRate.offset; }
   private: FieldCouponRate fieldCouponRate;

   public:
   bool isSetSecurityExchange() const { return fieldSecurityExchange.offset >= 0; }
   FieldSecurityExchange::ValueType getSecurityExchange() const { return fieldSecurityExchange.getValue( buf ); }
   const char * ptrToSecurityExchange() const { return buf + fieldSecurityExchange.offset; }
   private: FieldSecurityExchange fieldSecurityExchange;

   public:
   bool isSetIssuer() const { return fieldIssuer.offset >= 0; }
   FieldIssuer::ValueType getIssuer() const { return fieldIssuer.getValue( buf ); }
   const char * ptrToIssuer() const { return buf + fieldIssuer.offset; }
   private: FieldIssuer fieldIssuer;

   public:
   bool isSetEncodedIssuerLen() const { return fieldEncodedIssuerLen.offset >= 0; }
   FieldEncodedIssuerLen::ValueType getEncodedIssuerLen() const { return fieldEncodedIssuerLen.getValue( buf ); }
   const char * ptrToEncodedIssuerLen() const { return buf + fieldEncodedIssuerLen.offset; }
   private: FieldEncodedIssuerLen fieldEncodedIssuerLen;

   public:
   bool isSetEncodedIssuer() const { return fieldEncodedIssuer.offset >= 0; }
   FieldEncodedIssuer::ValueType getEncodedIssuer() const { return fieldEncodedIssuer.getValue( buf ); }
   const char * ptrToEncodedIssuer() const { return buf + fieldEncodedIssuer.offset; }
   private: FieldEncodedIssuer fieldEncodedIssuer;

   public:
   bool isSetSecurityDesc() const { return fieldSecurityDesc.offset >= 0; }
   FieldSecurityDesc::ValueType getSecurityDesc() const { return fieldSecurityDesc.getValue( buf ); }
   const char * ptrToSecurityDesc() const { return buf + fieldSecurityDesc.offset; }
   private: FieldSecurityDesc fieldSecurityDesc;

   public:
   bool isSetEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.offset >= 0; }
   FieldEncodedSecurityDescLen::ValueType getEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedSecurityDescLen() const { return buf + fieldEncodedSecurityDescLen.offset; }
   private: FieldEncodedSecurityDescLen fieldEncodedSecurityDescLen;

   public:
   bool isSetEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.offset >= 0; }
   FieldEncodedSecurityDesc::ValueType getEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedSecurityDesc() const { return buf + fieldEncodedSecurityDesc.offset; }
   private: FieldEncodedSecurityDesc fieldEncodedSecurityDesc;

   public:
   bool isSetPool() const { return fieldPool.offset >= 0; }
   FieldPool::ValueType getPool() const { return fieldPool.getValue( buf ); }
   const char * ptrToPool() const { return buf + fieldPool.offset; }
   private: FieldPool fieldPool;

   public:
   bool isSetContractSettlMonth() const { return fieldContractSettlMonth.offset >= 0; }
   FieldContractSettlMonth::ValueType getContractSettlMonth() const { return fieldContractSettlMonth.getValue( buf ); }
   const char * ptrToContractSettlMonth() const { return buf + fieldContractSettlMonth.offset; }
   private: FieldContractSettlMonth fieldContractSettlMonth;

   public:
   bool isSetCPProgram() const { return fieldCPProgram.offset >= 0; }
   FieldCPProgram::ValueType getCPProgram() const { return fieldCPProgram.getValue( buf ); }
   const char * ptrToCPProgram() const { return buf + fieldCPProgram.offset; }
   private: FieldCPProgram fieldCPProgram;

   public:
   bool isSetCPRegType() const { return fieldCPRegType.offset >= 0; }
   FieldCPRegType::ValueType getCPRegType() const { return fieldCPRegType.getValue( buf ); }
   const char * ptrToCPRegType() const { return buf + fieldCPRegType.offset; }
   private: FieldCPRegType fieldCPRegType;

   public:
   bool isSetNoEvents() const { return fieldNoEvents.offset >= 0; }
   FieldNoEvents::ValueType getNoEvents() const { return fieldNoEvents.getValue( buf ); }
   const char * ptrToNoEvents() const { return buf + fieldNoEvents.offset; }
   private: FieldNoEvents fieldNoEvents;
  
   public:
   size_t getGroupCountEvents() const { return groupsEvents.size(); } 
   const GroupEvents & getGroupEvents( size_t idx ) const { return groupsEvents[ idx ]; } 
   private: GroupEvents::Array groupsEvents{ 10 };

   public:
   bool isSetDatedDate() const { return fieldDatedDate.offset >= 0; }
   FieldDatedDate::ValueType getDatedDate() const { return fieldDatedDate.getValue( buf ); }
   const char * ptrToDatedDate() const { return buf + fieldDatedDate.offset; }
   private: FieldDatedDate fieldDatedDate;

   public:
   bool isSetInterestAccrualDate() const { return fieldInterestAccrualDate.offset >= 0; }
   FieldInterestAccrualDate::ValueType getInterestAccrualDate() const { return fieldInterestAccrualDate.getValue( buf ); }
   const char * ptrToInterestAccrualDate() const { return buf + fieldInterestAccrualDate.offset; }
   private: FieldInterestAccrualDate fieldInterestAccrualDate;

   public:
   bool isSetNoUnderlyings() const { return fieldNoUnderlyings.offset >= 0; }
   FieldNoUnderlyings::ValueType getNoUnderlyings() const { return fieldNoUnderlyings.getValue( buf ); }
   const char * ptrToNoUnderlyings() const { return buf + fieldNoUnderlyings.offset; }
   private: FieldNoUnderlyings fieldNoUnderlyings;
  
   public:
   size_t getGroupCountUnderlyings() const { return groupsUnderlyings.size(); } 
   const GroupUnderlyings & getGroupUnderlyings( size_t idx ) const { return groupsUnderlyings[ idx ]; } 
   private: GroupUnderlyings::Array groupsUnderlyings{ 10 };

   public:
   bool isSetPrevClosePx() const { return fieldPrevClosePx.offset >= 0; }
   FieldPrevClosePx::ValueType getPrevClosePx() const { return fieldPrevClosePx.getValue( buf ); }
   const char * ptrToPrevClosePx() const { return buf + fieldPrevClosePx.offset; }
   private: FieldPrevClosePx fieldPrevClosePx;

   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetSideValueInd() const { return fieldSideValueInd.offset >= 0; }
   FieldSideValueInd::ValueType getSideValueInd() const { return fieldSideValueInd.getValue( buf ); }
   const char * ptrToSideValueInd() const { return buf + fieldSideValueInd.offset; }
   private: FieldSideValueInd fieldSideValueInd;

   public:
   bool isSetLocateReqd() const { return fieldLocateReqd.offset >= 0; }
   FieldLocateReqd::ValueType getLocateReqd() const { return fieldLocateReqd.getValue( buf ); }
   const char * ptrToLocateReqd() const { return buf + fieldLocateReqd.offset; }
   private: FieldLocateReqd fieldLocateReqd;

   public:
   bool isSetTransactTime() const { return fieldTransactTime.offset >= 0; }
   FieldTransactTime::ValueType getTransactTime() const { return fieldTransactTime.getValue( buf ); }
   const char * ptrToTransactTime() const { return buf + fieldTransactTime.offset; }
   private: FieldTransactTime fieldTransactTime;

   public:
   bool isSetNoStipulations() const { return fieldNoStipulations.offset >= 0; }
   FieldNoStipulations::ValueType getNoStipulations() const { return fieldNoStipulations.getValue( buf ); }
   const char * ptrToNoStipulations() const { return buf + fieldNoStipulations.offset; }
   private: FieldNoStipulations fieldNoStipulations;
  
   public:
   size_t getGroupCountStipulations() const { return groupsStipulations.size(); } 
   const GroupStipulations & getGroupStipulations( size_t idx ) const { return groupsStipulations[ idx ]; } 
   private: GroupStipulations::Array groupsStipulations{ 10 };

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
   bool isSetCashOrderQty() const { return fieldCashOrderQty.offset >= 0; }
   FieldCashOrderQty::ValueType getCashOrderQty() const { return fieldCashOrderQty.getValue( buf ); }
   const char * ptrToCashOrderQty() const { return buf + fieldCashOrderQty.offset; }
   private: FieldCashOrderQty fieldCashOrderQty;

   public:
   bool isSetOrderPercent() const { return fieldOrderPercent.offset >= 0; }
   FieldOrderPercent::ValueType getOrderPercent() const { return fieldOrderPercent.getValue( buf ); }
   const char * ptrToOrderPercent() const { return buf + fieldOrderPercent.offset; }
   private: FieldOrderPercent fieldOrderPercent;

   public:
   bool isSetRoundingDirection() const { return fieldRoundingDirection.offset >= 0; }
   FieldRoundingDirection::ValueType getRoundingDirection() const { return fieldRoundingDirection.getValue( buf ); }
   const char * ptrToRoundingDirection() const { return buf + fieldRoundingDirection.offset; }
   private: FieldRoundingDirection fieldRoundingDirection;

   public:
   bool isSetRoundingModulus() const { return fieldRoundingModulus.offset >= 0; }
   FieldRoundingModulus::ValueType getRoundingModulus() const { return fieldRoundingModulus.getValue( buf ); }
   const char * ptrToRoundingModulus() const { return buf + fieldRoundingModulus.offset; }
   private: FieldRoundingModulus fieldRoundingModulus;

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
   bool isSetSpread() const { return fieldSpread.offset >= 0; }
   FieldSpread::ValueType getSpread() const { return fieldSpread.getValue( buf ); }
   const char * ptrToSpread() const { return buf + fieldSpread.offset; }
   private: FieldSpread fieldSpread;

   public:
   bool isSetBenchmarkCurveCurrency() const { return fieldBenchmarkCurveCurrency.offset >= 0; }
   FieldBenchmarkCurveCurrency::ValueType getBenchmarkCurveCurrency() const { return fieldBenchmarkCurveCurrency.getValue( buf ); }
   const char * ptrToBenchmarkCurveCurrency() const { return buf + fieldBenchmarkCurveCurrency.offset; }
   private: FieldBenchmarkCurveCurrency fieldBenchmarkCurveCurrency;

   public:
   bool isSetBenchmarkCurveName() const { return fieldBenchmarkCurveName.offset >= 0; }
   FieldBenchmarkCurveName::ValueType getBenchmarkCurveName() const { return fieldBenchmarkCurveName.getValue( buf ); }
   const char * ptrToBenchmarkCurveName() const { return buf + fieldBenchmarkCurveName.offset; }
   private: FieldBenchmarkCurveName fieldBenchmarkCurveName;

   public:
   bool isSetBenchmarkCurvePoint() const { return fieldBenchmarkCurvePoint.offset >= 0; }
   FieldBenchmarkCurvePoint::ValueType getBenchmarkCurvePoint() const { return fieldBenchmarkCurvePoint.getValue( buf ); }
   const char * ptrToBenchmarkCurvePoint() const { return buf + fieldBenchmarkCurvePoint.offset; }
   private: FieldBenchmarkCurvePoint fieldBenchmarkCurvePoint;

   public:
   bool isSetBenchmarkPrice() const { return fieldBenchmarkPrice.offset >= 0; }
   FieldBenchmarkPrice::ValueType getBenchmarkPrice() const { return fieldBenchmarkPrice.getValue( buf ); }
   const char * ptrToBenchmarkPrice() const { return buf + fieldBenchmarkPrice.offset; }
   private: FieldBenchmarkPrice fieldBenchmarkPrice;

   public:
   bool isSetBenchmarkPriceType() const { return fieldBenchmarkPriceType.offset >= 0; }
   FieldBenchmarkPriceType::ValueType getBenchmarkPriceType() const { return fieldBenchmarkPriceType.getValue( buf ); }
   const char * ptrToBenchmarkPriceType() const { return buf + fieldBenchmarkPriceType.offset; }
   private: FieldBenchmarkPriceType fieldBenchmarkPriceType;

   public:
   bool isSetBenchmarkSecurityID() const { return fieldBenchmarkSecurityID.offset >= 0; }
   FieldBenchmarkSecurityID::ValueType getBenchmarkSecurityID() const { return fieldBenchmarkSecurityID.getValue( buf ); }
   const char * ptrToBenchmarkSecurityID() const { return buf + fieldBenchmarkSecurityID.offset; }
   private: FieldBenchmarkSecurityID fieldBenchmarkSecurityID;

   public:
   bool isSetBenchmarkSecurityIDSource() const { return fieldBenchmarkSecurityIDSource.offset >= 0; }
   FieldBenchmarkSecurityIDSource::ValueType getBenchmarkSecurityIDSource() const { return fieldBenchmarkSecurityIDSource.getValue( buf ); }
   const char * ptrToBenchmarkSecurityIDSource() const { return buf + fieldBenchmarkSecurityIDSource.offset; }
   private: FieldBenchmarkSecurityIDSource fieldBenchmarkSecurityIDSource;

   public:
   bool isSetYieldType() const { return fieldYieldType.offset >= 0; }
   FieldYieldType::ValueType getYieldType() const { return fieldYieldType.getValue( buf ); }
   const char * ptrToYieldType() const { return buf + fieldYieldType.offset; }
   private: FieldYieldType fieldYieldType;

   public:
   bool isSetYield() const { return fieldYield.offset >= 0; }
   FieldYield::ValueType getYield() const { return fieldYield.getValue( buf ); }
   const char * ptrToYield() const { return buf + fieldYield.offset; }
   private: FieldYield fieldYield;

   public:
   bool isSetYieldCalcDate() const { return fieldYieldCalcDate.offset >= 0; }
   FieldYieldCalcDate::ValueType getYieldCalcDate() const { return fieldYieldCalcDate.getValue( buf ); }
   const char * ptrToYieldCalcDate() const { return buf + fieldYieldCalcDate.offset; }
   private: FieldYieldCalcDate fieldYieldCalcDate;

   public:
   bool isSetYieldRedemptionDate() const { return fieldYieldRedemptionDate.offset >= 0; }
   FieldYieldRedemptionDate::ValueType getYieldRedemptionDate() const { return fieldYieldRedemptionDate.getValue( buf ); }
   const char * ptrToYieldRedemptionDate() const { return buf + fieldYieldRedemptionDate.offset; }
   private: FieldYieldRedemptionDate fieldYieldRedemptionDate;

   public:
   bool isSetYieldRedemptionPrice() const { return fieldYieldRedemptionPrice.offset >= 0; }
   FieldYieldRedemptionPrice::ValueType getYieldRedemptionPrice() const { return fieldYieldRedemptionPrice.getValue( buf ); }
   const char * ptrToYieldRedemptionPrice() const { return buf + fieldYieldRedemptionPrice.offset; }
   private: FieldYieldRedemptionPrice fieldYieldRedemptionPrice;

   public:
   bool isSetYieldRedemptionPriceType() const { return fieldYieldRedemptionPriceType.offset >= 0; }
   FieldYieldRedemptionPriceType::ValueType getYieldRedemptionPriceType() const { return fieldYieldRedemptionPriceType.getValue( buf ); }
   const char * ptrToYieldRedemptionPriceType() const { return buf + fieldYieldRedemptionPriceType.offset; }
   private: FieldYieldRedemptionPriceType fieldYieldRedemptionPriceType;

   public:
   bool isSetCurrency() const { return fieldCurrency.offset >= 0; }
   FieldCurrency::ValueType getCurrency() const { return fieldCurrency.getValue( buf ); }
   const char * ptrToCurrency() const { return buf + fieldCurrency.offset; }
   private: FieldCurrency fieldCurrency;

   public:
   bool isSetComplianceID() const { return fieldComplianceID.offset >= 0; }
   FieldComplianceID::ValueType getComplianceID() const { return fieldComplianceID.getValue( buf ); }
   const char * ptrToComplianceID() const { return buf + fieldComplianceID.offset; }
   private: FieldComplianceID fieldComplianceID;

   public:
   bool isSetSolicitedFlag() const { return fieldSolicitedFlag.offset >= 0; }
   FieldSolicitedFlag::ValueType getSolicitedFlag() const { return fieldSolicitedFlag.getValue( buf ); }
   const char * ptrToSolicitedFlag() const { return buf + fieldSolicitedFlag.offset; }
   private: FieldSolicitedFlag fieldSolicitedFlag;

   public:
   bool isSetIOIID() const { return fieldIOIID.offset >= 0; }
   FieldIOIID::ValueType getIOIID() const { return fieldIOIID.getValue( buf ); }
   const char * ptrToIOIID() const { return buf + fieldIOIID.offset; }
   private: FieldIOIID fieldIOIID;

   public:
   bool isSetQuoteID() const { return fieldQuoteID.offset >= 0; }
   FieldQuoteID::ValueType getQuoteID() const { return fieldQuoteID.getValue( buf ); }
   const char * ptrToQuoteID() const { return buf + fieldQuoteID.offset; }
   private: FieldQuoteID fieldQuoteID;

   public:
   bool isSetTimeInForce() const { return fieldTimeInForce.offset >= 0; }
   FieldTimeInForce::ValueType getTimeInForce() const { return fieldTimeInForce.getValue( buf ); }
   const char * ptrToTimeInForce() const { return buf + fieldTimeInForce.offset; }
   private: FieldTimeInForce fieldTimeInForce;

   public:
   bool isSetEffectiveTime() const { return fieldEffectiveTime.offset >= 0; }
   FieldEffectiveTime::ValueType getEffectiveTime() const { return fieldEffectiveTime.getValue( buf ); }
   const char * ptrToEffectiveTime() const { return buf + fieldEffectiveTime.offset; }
   private: FieldEffectiveTime fieldEffectiveTime;

   public:
   bool isSetExpireDate() const { return fieldExpireDate.offset >= 0; }
   FieldExpireDate::ValueType getExpireDate() const { return fieldExpireDate.getValue( buf ); }
   const char * ptrToExpireDate() const { return buf + fieldExpireDate.offset; }
   private: FieldExpireDate fieldExpireDate;

   public:
   bool isSetExpireTime() const { return fieldExpireTime.offset >= 0; }
   FieldExpireTime::ValueType getExpireTime() const { return fieldExpireTime.getValue( buf ); }
   const char * ptrToExpireTime() const { return buf + fieldExpireTime.offset; }
   private: FieldExpireTime fieldExpireTime;

   public:
   bool isSetGTBookingInst() const { return fieldGTBookingInst.offset >= 0; }
   FieldGTBookingInst::ValueType getGTBookingInst() const { return fieldGTBookingInst.getValue( buf ); }
   const char * ptrToGTBookingInst() const { return buf + fieldGTBookingInst.offset; }
   private: FieldGTBookingInst fieldGTBookingInst;

   public:
   bool isSetCommission() const { return fieldCommission.offset >= 0; }
   FieldCommission::ValueType getCommission() const { return fieldCommission.getValue( buf ); }
   const char * ptrToCommission() const { return buf + fieldCommission.offset; }
   private: FieldCommission fieldCommission;

   public:
   bool isSetCommType() const { return fieldCommType.offset >= 0; }
   FieldCommType::ValueType getCommType() const { return fieldCommType.getValue( buf ); }
   const char * ptrToCommType() const { return buf + fieldCommType.offset; }
   private: FieldCommType fieldCommType;

   public:
   bool isSetCommCurrency() const { return fieldCommCurrency.offset >= 0; }
   FieldCommCurrency::ValueType getCommCurrency() const { return fieldCommCurrency.getValue( buf ); }
   const char * ptrToCommCurrency() const { return buf + fieldCommCurrency.offset; }
   private: FieldCommCurrency fieldCommCurrency;

   public:
   bool isSetFundRenewWaiv() const { return fieldFundRenewWaiv.offset >= 0; }
   FieldFundRenewWaiv::ValueType getFundRenewWaiv() const { return fieldFundRenewWaiv.getValue( buf ); }
   const char * ptrToFundRenewWaiv() const { return buf + fieldFundRenewWaiv.offset; }
   private: FieldFundRenewWaiv fieldFundRenewWaiv;

   public:
   bool isSetOrderCapacity() const { return fieldOrderCapacity.offset >= 0; }
   FieldOrderCapacity::ValueType getOrderCapacity() const { return fieldOrderCapacity.getValue( buf ); }
   const char * ptrToOrderCapacity() const { return buf + fieldOrderCapacity.offset; }
   private: FieldOrderCapacity fieldOrderCapacity;

   public:
   bool isSetOrderRestrictions() const { return fieldOrderRestrictions.offset >= 0; }
   FieldOrderRestrictions::ValueType getOrderRestrictions() const { return fieldOrderRestrictions.getValue( buf ); }
   const char * ptrToOrderRestrictions() const { return buf + fieldOrderRestrictions.offset; }
   private: FieldOrderRestrictions fieldOrderRestrictions;

   public:
   bool isSetCustOrderCapacity() const { return fieldCustOrderCapacity.offset >= 0; }
   FieldCustOrderCapacity::ValueType getCustOrderCapacity() const { return fieldCustOrderCapacity.getValue( buf ); }
   const char * ptrToCustOrderCapacity() const { return buf + fieldCustOrderCapacity.offset; }
   private: FieldCustOrderCapacity fieldCustOrderCapacity;

   public:
   bool isSetForexReq() const { return fieldForexReq.offset >= 0; }
   FieldForexReq::ValueType getForexReq() const { return fieldForexReq.getValue( buf ); }
   const char * ptrToForexReq() const { return buf + fieldForexReq.offset; }
   private: FieldForexReq fieldForexReq;

   public:
   bool isSetSettlCurrency() const { return fieldSettlCurrency.offset >= 0; }
   FieldSettlCurrency::ValueType getSettlCurrency() const { return fieldSettlCurrency.getValue( buf ); }
   const char * ptrToSettlCurrency() const { return buf + fieldSettlCurrency.offset; }
   private: FieldSettlCurrency fieldSettlCurrency;

   public:
   bool isSetBookingType() const { return fieldBookingType.offset >= 0; }
   FieldBookingType::ValueType getBookingType() const { return fieldBookingType.getValue( buf ); }
   const char * ptrToBookingType() const { return buf + fieldBookingType.offset; }
   private: FieldBookingType fieldBookingType;

   public:
   bool isSetText() const { return fieldText.offset >= 0; }
   FieldText::ValueType getText() const { return fieldText.getValue( buf ); }
   const char * ptrToText() const { return buf + fieldText.offset; }
   private: FieldText fieldText;

   public:
   bool isSetEncodedTextLen() const { return fieldEncodedTextLen.offset >= 0; }
   FieldEncodedTextLen::ValueType getEncodedTextLen() const { return fieldEncodedTextLen.getValue( buf ); }
   const char * ptrToEncodedTextLen() const { return buf + fieldEncodedTextLen.offset; }
   private: FieldEncodedTextLen fieldEncodedTextLen;

   public:
   bool isSetEncodedText() const { return fieldEncodedText.offset >= 0; }
   FieldEncodedText::ValueType getEncodedText() const { return fieldEncodedText.getValue( buf ); }
   const char * ptrToEncodedText() const { return buf + fieldEncodedText.offset; }
   private: FieldEncodedText fieldEncodedText;

   public:
   bool isSetSettlDate2() const { return fieldSettlDate2.offset >= 0; }
   FieldSettlDate2::ValueType getSettlDate2() const { return fieldSettlDate2.getValue( buf ); }
   const char * ptrToSettlDate2() const { return buf + fieldSettlDate2.offset; }
   private: FieldSettlDate2 fieldSettlDate2;

   public:
   bool isSetOrderQty2() const { return fieldOrderQty2.offset >= 0; }
   FieldOrderQty2::ValueType getOrderQty2() const { return fieldOrderQty2.getValue( buf ); }
   const char * ptrToOrderQty2() const { return buf + fieldOrderQty2.offset; }
   private: FieldOrderQty2 fieldOrderQty2;

   public:
   bool isSetPrice2() const { return fieldPrice2.offset >= 0; }
   FieldPrice2::ValueType getPrice2() const { return fieldPrice2.getValue( buf ); }
   const char * ptrToPrice2() const { return buf + fieldPrice2.offset; }
   private: FieldPrice2 fieldPrice2;

   public:
   bool isSetPositionEffect() const { return fieldPositionEffect.offset >= 0; }
   FieldPositionEffect::ValueType getPositionEffect() const { return fieldPositionEffect.getValue( buf ); }
   const char * ptrToPositionEffect() const { return buf + fieldPositionEffect.offset; }
   private: FieldPositionEffect fieldPositionEffect;

   public:
   bool isSetCoveredOrUncovered() const { return fieldCoveredOrUncovered.offset >= 0; }
   FieldCoveredOrUncovered::ValueType getCoveredOrUncovered() const { return fieldCoveredOrUncovered.getValue( buf ); }
   const char * ptrToCoveredOrUncovered() const { return buf + fieldCoveredOrUncovered.offset; }
   private: FieldCoveredOrUncovered fieldCoveredOrUncovered;

   public:
   bool isSetMaxShow() const { return fieldMaxShow.offset >= 0; }
   FieldMaxShow::ValueType getMaxShow() const { return fieldMaxShow.getValue( buf ); }
   const char * ptrToMaxShow() const { return buf + fieldMaxShow.offset; }
   private: FieldMaxShow fieldMaxShow;

   public:
   bool isSetPegOffsetValue() const { return fieldPegOffsetValue.offset >= 0; }
   FieldPegOffsetValue::ValueType getPegOffsetValue() const { return fieldPegOffsetValue.getValue( buf ); }
   const char * ptrToPegOffsetValue() const { return buf + fieldPegOffsetValue.offset; }
   private: FieldPegOffsetValue fieldPegOffsetValue;

   public:
   bool isSetPegMoveType() const { return fieldPegMoveType.offset >= 0; }
   FieldPegMoveType::ValueType getPegMoveType() const { return fieldPegMoveType.getValue( buf ); }
   const char * ptrToPegMoveType() const { return buf + fieldPegMoveType.offset; }
   private: FieldPegMoveType fieldPegMoveType;

   public:
   bool isSetPegOffsetType() const { return fieldPegOffsetType.offset >= 0; }
   FieldPegOffsetType::ValueType getPegOffsetType() const { return fieldPegOffsetType.getValue( buf ); }
   const char * ptrToPegOffsetType() const { return buf + fieldPegOffsetType.offset; }
   private: FieldPegOffsetType fieldPegOffsetType;

   public:
   bool isSetPegLimitType() const { return fieldPegLimitType.offset >= 0; }
   FieldPegLimitType::ValueType getPegLimitType() const { return fieldPegLimitType.getValue( buf ); }
   const char * ptrToPegLimitType() const { return buf + fieldPegLimitType.offset; }
   private: FieldPegLimitType fieldPegLimitType;

   public:
   bool isSetPegRoundDirection() const { return fieldPegRoundDirection.offset >= 0; }
   FieldPegRoundDirection::ValueType getPegRoundDirection() const { return fieldPegRoundDirection.getValue( buf ); }
   const char * ptrToPegRoundDirection() const { return buf + fieldPegRoundDirection.offset; }
   private: FieldPegRoundDirection fieldPegRoundDirection;

   public:
   bool isSetPegScope() const { return fieldPegScope.offset >= 0; }
   FieldPegScope::ValueType getPegScope() const { return fieldPegScope.getValue( buf ); }
   const char * ptrToPegScope() const { return buf + fieldPegScope.offset; }
   private: FieldPegScope fieldPegScope;

   public:
   bool isSetDiscretionInst() const { return fieldDiscretionInst.offset >= 0; }
   FieldDiscretionInst::ValueType getDiscretionInst() const { return fieldDiscretionInst.getValue( buf ); }
   const char * ptrToDiscretionInst() const { return buf + fieldDiscretionInst.offset; }
   private: FieldDiscretionInst fieldDiscretionInst;

   public:
   bool isSetDiscretionOffsetValue() const { return fieldDiscretionOffsetValue.offset >= 0; }
   FieldDiscretionOffsetValue::ValueType getDiscretionOffsetValue() const { return fieldDiscretionOffsetValue.getValue( buf ); }
   const char * ptrToDiscretionOffsetValue() const { return buf + fieldDiscretionOffsetValue.offset; }
   private: FieldDiscretionOffsetValue fieldDiscretionOffsetValue;

   public:
   bool isSetDiscretionMoveType() const { return fieldDiscretionMoveType.offset >= 0; }
   FieldDiscretionMoveType::ValueType getDiscretionMoveType() const { return fieldDiscretionMoveType.getValue( buf ); }
   const char * ptrToDiscretionMoveType() const { return buf + fieldDiscretionMoveType.offset; }
   private: FieldDiscretionMoveType fieldDiscretionMoveType;

   public:
   bool isSetDiscretionOffsetType() const { return fieldDiscretionOffsetType.offset >= 0; }
   FieldDiscretionOffsetType::ValueType getDiscretionOffsetType() const { return fieldDiscretionOffsetType.getValue( buf ); }
   const char * ptrToDiscretionOffsetType() const { return buf + fieldDiscretionOffsetType.offset; }
   private: FieldDiscretionOffsetType fieldDiscretionOffsetType;

   public:
   bool isSetDiscretionLimitType() const { return fieldDiscretionLimitType.offset >= 0; }
   FieldDiscretionLimitType::ValueType getDiscretionLimitType() const { return fieldDiscretionLimitType.getValue( buf ); }
   const char * ptrToDiscretionLimitType() const { return buf + fieldDiscretionLimitType.offset; }
   private: FieldDiscretionLimitType fieldDiscretionLimitType;

   public:
   bool isSetDiscretionRoundDirection() const { return fieldDiscretionRoundDirection.offset >= 0; }
   FieldDiscretionRoundDirection::ValueType getDiscretionRoundDirection() const { return fieldDiscretionRoundDirection.getValue( buf ); }
   const char * ptrToDiscretionRoundDirection() const { return buf + fieldDiscretionRoundDirection.offset; }
   private: FieldDiscretionRoundDirection fieldDiscretionRoundDirection;

   public:
   bool isSetDiscretionScope() const { return fieldDiscretionScope.offset >= 0; }
   FieldDiscretionScope::ValueType getDiscretionScope() const { return fieldDiscretionScope.getValue( buf ); }
   const char * ptrToDiscretionScope() const { return buf + fieldDiscretionScope.offset; }
   private: FieldDiscretionScope fieldDiscretionScope;

   public:
   bool isSetTargetStrategy() const { return fieldTargetStrategy.offset >= 0; }
   FieldTargetStrategy::ValueType getTargetStrategy() const { return fieldTargetStrategy.getValue( buf ); }
   const char * ptrToTargetStrategy() const { return buf + fieldTargetStrategy.offset; }
   private: FieldTargetStrategy fieldTargetStrategy;

   public:
   bool isSetTargetStrategyParameters() const { return fieldTargetStrategyParameters.offset >= 0; }
   FieldTargetStrategyParameters::ValueType getTargetStrategyParameters() const { return fieldTargetStrategyParameters.getValue( buf ); }
   const char * ptrToTargetStrategyParameters() const { return buf + fieldTargetStrategyParameters.offset; }
   private: FieldTargetStrategyParameters fieldTargetStrategyParameters;

   public:
   bool isSetParticipationRate() const { return fieldParticipationRate.offset >= 0; }
   FieldParticipationRate::ValueType getParticipationRate() const { return fieldParticipationRate.getValue( buf ); }
   const char * ptrToParticipationRate() const { return buf + fieldParticipationRate.offset; }
   private: FieldParticipationRate fieldParticipationRate;

   public:
   bool isSetDesignation() const { return fieldDesignation.offset >= 0; }
   FieldDesignation::ValueType getDesignation() const { return fieldDesignation.getValue( buf ); }
   const char * ptrToDesignation() const { return buf + fieldDesignation.offset; }
   private: FieldDesignation fieldDesignation;

};

class GroupSettlPartySubIDs : public MessageBase
{
  
// Methods
   public:
   GroupSettlPartySubIDs();
   typedef std::vector<GroupSettlPartySubIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSettlPartySubID() const { return fieldSettlPartySubID.offset >= 0; }
   FieldSettlPartySubID::ValueType getSettlPartySubID() const { return fieldSettlPartySubID.getValue( buf ); }
   const char * ptrToSettlPartySubID() const { return buf + fieldSettlPartySubID.offset; }
   private: FieldSettlPartySubID fieldSettlPartySubID;

   public:
   bool isSetSettlPartySubIDType() const { return fieldSettlPartySubIDType.offset >= 0; }
   FieldSettlPartySubIDType::ValueType getSettlPartySubIDType() const { return fieldSettlPartySubIDType.getValue( buf ); }
   const char * ptrToSettlPartySubIDType() const { return buf + fieldSettlPartySubIDType.offset; }
   private: FieldSettlPartySubIDType fieldSettlPartySubIDType;

};

class GroupSettlPartyIDs : public MessageBase
{
  
// Methods
   public:
   GroupSettlPartyIDs();
   typedef std::vector<GroupSettlPartyIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSettlPartyID() const { return fieldSettlPartyID.offset >= 0; }
   FieldSettlPartyID::ValueType getSettlPartyID() const { return fieldSettlPartyID.getValue( buf ); }
   const char * ptrToSettlPartyID() const { return buf + fieldSettlPartyID.offset; }
   private: FieldSettlPartyID fieldSettlPartyID;

   public:
   bool isSetSettlPartyIDSource() const { return fieldSettlPartyIDSource.offset >= 0; }
   FieldSettlPartyIDSource::ValueType getSettlPartyIDSource() const { return fieldSettlPartyIDSource.getValue( buf ); }
   const char * ptrToSettlPartyIDSource() const { return buf + fieldSettlPartyIDSource.offset; }
   private: FieldSettlPartyIDSource fieldSettlPartyIDSource;

   public:
   bool isSetSettlPartyRole() const { return fieldSettlPartyRole.offset >= 0; }
   FieldSettlPartyRole::ValueType getSettlPartyRole() const { return fieldSettlPartyRole.getValue( buf ); }
   const char * ptrToSettlPartyRole() const { return buf + fieldSettlPartyRole.offset; }
   private: FieldSettlPartyRole fieldSettlPartyRole;

   public:
   bool isSetNoSettlPartySubIDs() const { return fieldNoSettlPartySubIDs.offset >= 0; }
   FieldNoSettlPartySubIDs::ValueType getNoSettlPartySubIDs() const { return fieldNoSettlPartySubIDs.getValue( buf ); }
   const char * ptrToNoSettlPartySubIDs() const { return buf + fieldNoSettlPartySubIDs.offset; }
   private: FieldNoSettlPartySubIDs fieldNoSettlPartySubIDs;
  
   public:
   size_t getGroupCountSettlPartySubIDs() const { return groupsSettlPartySubIDs.size(); } 
   const GroupSettlPartySubIDs & getGroupSettlPartySubIDs( size_t idx ) const { return groupsSettlPartySubIDs[ idx ]; } 
   private: GroupSettlPartySubIDs::Array groupsSettlPartySubIDs{ 10 };

};

class GroupDlvyInst : public MessageBase
{
  
// Methods
   public:
   GroupDlvyInst();
   typedef std::vector<GroupDlvyInst> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSettlInstSource() const { return fieldSettlInstSource.offset >= 0; }
   FieldSettlInstSource::ValueType getSettlInstSource() const { return fieldSettlInstSource.getValue( buf ); }
   const char * ptrToSettlInstSource() const { return buf + fieldSettlInstSource.offset; }
   private: FieldSettlInstSource fieldSettlInstSource;

   public:
   bool isSetDlvyInstType() const { return fieldDlvyInstType.offset >= 0; }
   FieldDlvyInstType::ValueType getDlvyInstType() const { return fieldDlvyInstType.getValue( buf ); }
   const char * ptrToDlvyInstType() const { return buf + fieldDlvyInstType.offset; }
   private: FieldDlvyInstType fieldDlvyInstType;

   public:
   bool isSetNoSettlPartyIDs() const { return fieldNoSettlPartyIDs.offset >= 0; }
   FieldNoSettlPartyIDs::ValueType getNoSettlPartyIDs() const { return fieldNoSettlPartyIDs.getValue( buf ); }
   const char * ptrToNoSettlPartyIDs() const { return buf + fieldNoSettlPartyIDs.offset; }
   private: FieldNoSettlPartyIDs fieldNoSettlPartyIDs;
  
   public:
   size_t getGroupCountSettlPartyIDs() const { return groupsSettlPartyIDs.size(); } 
   const GroupSettlPartyIDs & getGroupSettlPartyIDs( size_t idx ) const { return groupsSettlPartyIDs[ idx ]; } 
   private: GroupSettlPartyIDs::Array groupsSettlPartyIDs{ 10 };

};

class GroupClearingInstructions : public MessageBase
{
  
// Methods
   public:
   GroupClearingInstructions();
   typedef std::vector<GroupClearingInstructions> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetClearingInstruction() const { return fieldClearingInstruction.offset >= 0; }
   FieldClearingInstruction::ValueType getClearingInstruction() const { return fieldClearingInstruction.getValue( buf ); }
   const char * ptrToClearingInstruction() const { return buf + fieldClearingInstruction.offset; }
   private: FieldClearingInstruction fieldClearingInstruction;

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
   size_t getGroupCountNestedPartySubIDs() const { return groupsNestedPartySubIDs.size(); } 
   const GroupNestedPartySubIDs & getGroupNestedPartySubIDs( size_t idx ) const { return groupsNestedPartySubIDs[ idx ]; } 
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
   bool isSetLegSymbolSfx() const { return fieldLegSymbolSfx.offset >= 0; }
   FieldLegSymbolSfx::ValueType getLegSymbolSfx() const { return fieldLegSymbolSfx.getValue( buf ); }
   const char * ptrToLegSymbolSfx() const { return buf + fieldLegSymbolSfx.offset; }
   private: FieldLegSymbolSfx fieldLegSymbolSfx;

   public:
   bool isSetLegSecurityID() const { return fieldLegSecurityID.offset >= 0; }
   FieldLegSecurityID::ValueType getLegSecurityID() const { return fieldLegSecurityID.getValue( buf ); }
   const char * ptrToLegSecurityID() const { return buf + fieldLegSecurityID.offset; }
   private: FieldLegSecurityID fieldLegSecurityID;

   public:
   bool isSetLegSecurityIDSource() const { return fieldLegSecurityIDSource.offset >= 0; }
   FieldLegSecurityIDSource::ValueType getLegSecurityIDSource() const { return fieldLegSecurityIDSource.getValue( buf ); }
   const char * ptrToLegSecurityIDSource() const { return buf + fieldLegSecurityIDSource.offset; }
   private: FieldLegSecurityIDSource fieldLegSecurityIDSource;

   public:
   bool isSetNoLegSecurityAltID() const { return fieldNoLegSecurityAltID.offset >= 0; }
   FieldNoLegSecurityAltID::ValueType getNoLegSecurityAltID() const { return fieldNoLegSecurityAltID.getValue( buf ); }
   const char * ptrToNoLegSecurityAltID() const { return buf + fieldNoLegSecurityAltID.offset; }
   private: FieldNoLegSecurityAltID fieldNoLegSecurityAltID;
  
   public:
   size_t getGroupCountLegSecurityAltID() const { return groupsLegSecurityAltID.size(); } 
   const GroupLegSecurityAltID & getGroupLegSecurityAltID( size_t idx ) const { return groupsLegSecurityAltID[ idx ]; } 
   private: GroupLegSecurityAltID::Array groupsLegSecurityAltID{ 10 };

   public:
   bool isSetLegProduct() const { return fieldLegProduct.offset >= 0; }
   FieldLegProduct::ValueType getLegProduct() const { return fieldLegProduct.getValue( buf ); }
   const char * ptrToLegProduct() const { return buf + fieldLegProduct.offset; }
   private: FieldLegProduct fieldLegProduct;

   public:
   bool isSetLegCFICode() const { return fieldLegCFICode.offset >= 0; }
   FieldLegCFICode::ValueType getLegCFICode() const { return fieldLegCFICode.getValue( buf ); }
   const char * ptrToLegCFICode() const { return buf + fieldLegCFICode.offset; }
   private: FieldLegCFICode fieldLegCFICode;

   public:
   bool isSetLegSecurityType() const { return fieldLegSecurityType.offset >= 0; }
   FieldLegSecurityType::ValueType getLegSecurityType() const { return fieldLegSecurityType.getValue( buf ); }
   const char * ptrToLegSecurityType() const { return buf + fieldLegSecurityType.offset; }
   private: FieldLegSecurityType fieldLegSecurityType;

   public:
   bool isSetLegSecuritySubType() const { return fieldLegSecuritySubType.offset >= 0; }
   FieldLegSecuritySubType::ValueType getLegSecuritySubType() const { return fieldLegSecuritySubType.getValue( buf ); }
   const char * ptrToLegSecuritySubType() const { return buf + fieldLegSecuritySubType.offset; }
   private: FieldLegSecuritySubType fieldLegSecuritySubType;

   public:
   bool isSetLegMaturityMonthYear() const { return fieldLegMaturityMonthYear.offset >= 0; }
   FieldLegMaturityMonthYear::ValueType getLegMaturityMonthYear() const { return fieldLegMaturityMonthYear.getValue( buf ); }
   const char * ptrToLegMaturityMonthYear() const { return buf + fieldLegMaturityMonthYear.offset; }
   private: FieldLegMaturityMonthYear fieldLegMaturityMonthYear;

   public:
   bool isSetLegMaturityDate() const { return fieldLegMaturityDate.offset >= 0; }
   FieldLegMaturityDate::ValueType getLegMaturityDate() const { return fieldLegMaturityDate.getValue( buf ); }
   const char * ptrToLegMaturityDate() const { return buf + fieldLegMaturityDate.offset; }
   private: FieldLegMaturityDate fieldLegMaturityDate;

   public:
   bool isSetLegCouponPaymentDate() const { return fieldLegCouponPaymentDate.offset >= 0; }
   FieldLegCouponPaymentDate::ValueType getLegCouponPaymentDate() const { return fieldLegCouponPaymentDate.getValue( buf ); }
   const char * ptrToLegCouponPaymentDate() const { return buf + fieldLegCouponPaymentDate.offset; }
   private: FieldLegCouponPaymentDate fieldLegCouponPaymentDate;

   public:
   bool isSetLegIssueDate() const { return fieldLegIssueDate.offset >= 0; }
   FieldLegIssueDate::ValueType getLegIssueDate() const { return fieldLegIssueDate.getValue( buf ); }
   const char * ptrToLegIssueDate() const { return buf + fieldLegIssueDate.offset; }
   private: FieldLegIssueDate fieldLegIssueDate;

   public:
   bool isSetLegRepoCollateralSecurityType() const { return fieldLegRepoCollateralSecurityType.offset >= 0; }
   FieldLegRepoCollateralSecurityType::ValueType getLegRepoCollateralSecurityType() const { return fieldLegRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToLegRepoCollateralSecurityType() const { return buf + fieldLegRepoCollateralSecurityType.offset; }
   private: FieldLegRepoCollateralSecurityType fieldLegRepoCollateralSecurityType;

   public:
   bool isSetLegRepurchaseTerm() const { return fieldLegRepurchaseTerm.offset >= 0; }
   FieldLegRepurchaseTerm::ValueType getLegRepurchaseTerm() const { return fieldLegRepurchaseTerm.getValue( buf ); }
   const char * ptrToLegRepurchaseTerm() const { return buf + fieldLegRepurchaseTerm.offset; }
   private: FieldLegRepurchaseTerm fieldLegRepurchaseTerm;

   public:
   bool isSetLegRepurchaseRate() const { return fieldLegRepurchaseRate.offset >= 0; }
   FieldLegRepurchaseRate::ValueType getLegRepurchaseRate() const { return fieldLegRepurchaseRate.getValue( buf ); }
   const char * ptrToLegRepurchaseRate() const { return buf + fieldLegRepurchaseRate.offset; }
   private: FieldLegRepurchaseRate fieldLegRepurchaseRate;

   public:
   bool isSetLegFactor() const { return fieldLegFactor.offset >= 0; }
   FieldLegFactor::ValueType getLegFactor() const { return fieldLegFactor.getValue( buf ); }
   const char * ptrToLegFactor() const { return buf + fieldLegFactor.offset; }
   private: FieldLegFactor fieldLegFactor;

   public:
   bool isSetLegCreditRating() const { return fieldLegCreditRating.offset >= 0; }
   FieldLegCreditRating::ValueType getLegCreditRating() const { return fieldLegCreditRating.getValue( buf ); }
   const char * ptrToLegCreditRating() const { return buf + fieldLegCreditRating.offset; }
   private: FieldLegCreditRating fieldLegCreditRating;

   public:
   bool isSetLegInstrRegistry() const { return fieldLegInstrRegistry.offset >= 0; }
   FieldLegInstrRegistry::ValueType getLegInstrRegistry() const { return fieldLegInstrRegistry.getValue( buf ); }
   const char * ptrToLegInstrRegistry() const { return buf + fieldLegInstrRegistry.offset; }
   private: FieldLegInstrRegistry fieldLegInstrRegistry;

   public:
   bool isSetLegCountryOfIssue() const { return fieldLegCountryOfIssue.offset >= 0; }
   FieldLegCountryOfIssue::ValueType getLegCountryOfIssue() const { return fieldLegCountryOfIssue.getValue( buf ); }
   const char * ptrToLegCountryOfIssue() const { return buf + fieldLegCountryOfIssue.offset; }
   private: FieldLegCountryOfIssue fieldLegCountryOfIssue;

   public:
   bool isSetLegStateOrProvinceOfIssue() const { return fieldLegStateOrProvinceOfIssue.offset >= 0; }
   FieldLegStateOrProvinceOfIssue::ValueType getLegStateOrProvinceOfIssue() const { return fieldLegStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToLegStateOrProvinceOfIssue() const { return buf + fieldLegStateOrProvinceOfIssue.offset; }
   private: FieldLegStateOrProvinceOfIssue fieldLegStateOrProvinceOfIssue;

   public:
   bool isSetLegLocaleOfIssue() const { return fieldLegLocaleOfIssue.offset >= 0; }
   FieldLegLocaleOfIssue::ValueType getLegLocaleOfIssue() const { return fieldLegLocaleOfIssue.getValue( buf ); }
   const char * ptrToLegLocaleOfIssue() const { return buf + fieldLegLocaleOfIssue.offset; }
   private: FieldLegLocaleOfIssue fieldLegLocaleOfIssue;

   public:
   bool isSetLegRedemptionDate() const { return fieldLegRedemptionDate.offset >= 0; }
   FieldLegRedemptionDate::ValueType getLegRedemptionDate() const { return fieldLegRedemptionDate.getValue( buf ); }
   const char * ptrToLegRedemptionDate() const { return buf + fieldLegRedemptionDate.offset; }
   private: FieldLegRedemptionDate fieldLegRedemptionDate;

   public:
   bool isSetLegStrikePrice() const { return fieldLegStrikePrice.offset >= 0; }
   FieldLegStrikePrice::ValueType getLegStrikePrice() const { return fieldLegStrikePrice.getValue( buf ); }
   const char * ptrToLegStrikePrice() const { return buf + fieldLegStrikePrice.offset; }
   private: FieldLegStrikePrice fieldLegStrikePrice;

   public:
   bool isSetLegStrikeCurrency() const { return fieldLegStrikeCurrency.offset >= 0; }
   FieldLegStrikeCurrency::ValueType getLegStrikeCurrency() const { return fieldLegStrikeCurrency.getValue( buf ); }
   const char * ptrToLegStrikeCurrency() const { return buf + fieldLegStrikeCurrency.offset; }
   private: FieldLegStrikeCurrency fieldLegStrikeCurrency;

   public:
   bool isSetLegOptAttribute() const { return fieldLegOptAttribute.offset >= 0; }
   FieldLegOptAttribute::ValueType getLegOptAttribute() const { return fieldLegOptAttribute.getValue( buf ); }
   const char * ptrToLegOptAttribute() const { return buf + fieldLegOptAttribute.offset; }
   private: FieldLegOptAttribute fieldLegOptAttribute;

   public:
   bool isSetLegContractMultiplier() const { return fieldLegContractMultiplier.offset >= 0; }
   FieldLegContractMultiplier::ValueType getLegContractMultiplier() const { return fieldLegContractMultiplier.getValue( buf ); }
   const char * ptrToLegContractMultiplier() const { return buf + fieldLegContractMultiplier.offset; }
   private: FieldLegContractMultiplier fieldLegContractMultiplier;

   public:
   bool isSetLegCouponRate() const { return fieldLegCouponRate.offset >= 0; }
   FieldLegCouponRate::ValueType getLegCouponRate() const { return fieldLegCouponRate.getValue( buf ); }
   const char * ptrToLegCouponRate() const { return buf + fieldLegCouponRate.offset; }
   private: FieldLegCouponRate fieldLegCouponRate;

   public:
   bool isSetLegSecurityExchange() const { return fieldLegSecurityExchange.offset >= 0; }
   FieldLegSecurityExchange::ValueType getLegSecurityExchange() const { return fieldLegSecurityExchange.getValue( buf ); }
   const char * ptrToLegSecurityExchange() const { return buf + fieldLegSecurityExchange.offset; }
   private: FieldLegSecurityExchange fieldLegSecurityExchange;

   public:
   bool isSetLegIssuer() const { return fieldLegIssuer.offset >= 0; }
   FieldLegIssuer::ValueType getLegIssuer() const { return fieldLegIssuer.getValue( buf ); }
   const char * ptrToLegIssuer() const { return buf + fieldLegIssuer.offset; }
   private: FieldLegIssuer fieldLegIssuer;

   public:
   bool isSetEncodedLegIssuerLen() const { return fieldEncodedLegIssuerLen.offset >= 0; }
   FieldEncodedLegIssuerLen::ValueType getEncodedLegIssuerLen() const { return fieldEncodedLegIssuerLen.getValue( buf ); }
   const char * ptrToEncodedLegIssuerLen() const { return buf + fieldEncodedLegIssuerLen.offset; }
   private: FieldEncodedLegIssuerLen fieldEncodedLegIssuerLen;

   public:
   bool isSetEncodedLegIssuer() const { return fieldEncodedLegIssuer.offset >= 0; }
   FieldEncodedLegIssuer::ValueType getEncodedLegIssuer() const { return fieldEncodedLegIssuer.getValue( buf ); }
   const char * ptrToEncodedLegIssuer() const { return buf + fieldEncodedLegIssuer.offset; }
   private: FieldEncodedLegIssuer fieldEncodedLegIssuer;

   public:
   bool isSetLegSecurityDesc() const { return fieldLegSecurityDesc.offset >= 0; }
   FieldLegSecurityDesc::ValueType getLegSecurityDesc() const { return fieldLegSecurityDesc.getValue( buf ); }
   const char * ptrToLegSecurityDesc() const { return buf + fieldLegSecurityDesc.offset; }
   private: FieldLegSecurityDesc fieldLegSecurityDesc;

   public:
   bool isSetEncodedLegSecurityDescLen() const { return fieldEncodedLegSecurityDescLen.offset >= 0; }
   FieldEncodedLegSecurityDescLen::ValueType getEncodedLegSecurityDescLen() const { return fieldEncodedLegSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedLegSecurityDescLen() const { return buf + fieldEncodedLegSecurityDescLen.offset; }
   private: FieldEncodedLegSecurityDescLen fieldEncodedLegSecurityDescLen;

   public:
   bool isSetEncodedLegSecurityDesc() const { return fieldEncodedLegSecurityDesc.offset >= 0; }
   FieldEncodedLegSecurityDesc::ValueType getEncodedLegSecurityDesc() const { return fieldEncodedLegSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedLegSecurityDesc() const { return buf + fieldEncodedLegSecurityDesc.offset; }
   private: FieldEncodedLegSecurityDesc fieldEncodedLegSecurityDesc;

   public:
   bool isSetLegRatioQty() const { return fieldLegRatioQty.offset >= 0; }
   FieldLegRatioQty::ValueType getLegRatioQty() const { return fieldLegRatioQty.getValue( buf ); }
   const char * ptrToLegRatioQty() const { return buf + fieldLegRatioQty.offset; }
   private: FieldLegRatioQty fieldLegRatioQty;

   public:
   bool isSetLegSide() const { return fieldLegSide.offset >= 0; }
   FieldLegSide::ValueType getLegSide() const { return fieldLegSide.getValue( buf ); }
   const char * ptrToLegSide() const { return buf + fieldLegSide.offset; }
   private: FieldLegSide fieldLegSide;

   public:
   bool isSetLegCurrency() const { return fieldLegCurrency.offset >= 0; }
   FieldLegCurrency::ValueType getLegCurrency() const { return fieldLegCurrency.getValue( buf ); }
   const char * ptrToLegCurrency() const { return buf + fieldLegCurrency.offset; }
   private: FieldLegCurrency fieldLegCurrency;

   public:
   bool isSetLegPool() const { return fieldLegPool.offset >= 0; }
   FieldLegPool::ValueType getLegPool() const { return fieldLegPool.getValue( buf ); }
   const char * ptrToLegPool() const { return buf + fieldLegPool.offset; }
   private: FieldLegPool fieldLegPool;

   public:
   bool isSetLegDatedDate() const { return fieldLegDatedDate.offset >= 0; }
   FieldLegDatedDate::ValueType getLegDatedDate() const { return fieldLegDatedDate.getValue( buf ); }
   const char * ptrToLegDatedDate() const { return buf + fieldLegDatedDate.offset; }
   private: FieldLegDatedDate fieldLegDatedDate;

   public:
   bool isSetLegContractSettlMonth() const { return fieldLegContractSettlMonth.offset >= 0; }
   FieldLegContractSettlMonth::ValueType getLegContractSettlMonth() const { return fieldLegContractSettlMonth.getValue( buf ); }
   const char * ptrToLegContractSettlMonth() const { return buf + fieldLegContractSettlMonth.offset; }
   private: FieldLegContractSettlMonth fieldLegContractSettlMonth;

   public:
   bool isSetLegInterestAccrualDate() const { return fieldLegInterestAccrualDate.offset >= 0; }
   FieldLegInterestAccrualDate::ValueType getLegInterestAccrualDate() const { return fieldLegInterestAccrualDate.getValue( buf ); }
   const char * ptrToLegInterestAccrualDate() const { return buf + fieldLegInterestAccrualDate.offset; }
   private: FieldLegInterestAccrualDate fieldLegInterestAccrualDate;

   public:
   bool isSetLegQty() const { return fieldLegQty.offset >= 0; }
   FieldLegQty::ValueType getLegQty() const { return fieldLegQty.getValue( buf ); }
   const char * ptrToLegQty() const { return buf + fieldLegQty.offset; }
   private: FieldLegQty fieldLegQty;

   public:
   bool isSetLegSwapType() const { return fieldLegSwapType.offset >= 0; }
   FieldLegSwapType::ValueType getLegSwapType() const { return fieldLegSwapType.getValue( buf ); }
   const char * ptrToLegSwapType() const { return buf + fieldLegSwapType.offset; }
   private: FieldLegSwapType fieldLegSwapType;

   public:
   bool isSetNoLegStipulations() const { return fieldNoLegStipulations.offset >= 0; }
   FieldNoLegStipulations::ValueType getNoLegStipulations() const { return fieldNoLegStipulations.getValue( buf ); }
   const char * ptrToNoLegStipulations() const { return buf + fieldNoLegStipulations.offset; }
   private: FieldNoLegStipulations fieldNoLegStipulations;
  
   public:
   size_t getGroupCountLegStipulations() const { return groupsLegStipulations.size(); } 
   const GroupLegStipulations & getGroupLegStipulations( size_t idx ) const { return groupsLegStipulations[ idx ]; } 
   private: GroupLegStipulations::Array groupsLegStipulations{ 10 };

   public:
   bool isSetLegPositionEffect() const { return fieldLegPositionEffect.offset >= 0; }
   FieldLegPositionEffect::ValueType getLegPositionEffect() const { return fieldLegPositionEffect.getValue( buf ); }
   const char * ptrToLegPositionEffect() const { return buf + fieldLegPositionEffect.offset; }
   private: FieldLegPositionEffect fieldLegPositionEffect;

   public:
   bool isSetLegCoveredOrUncovered() const { return fieldLegCoveredOrUncovered.offset >= 0; }
   FieldLegCoveredOrUncovered::ValueType getLegCoveredOrUncovered() const { return fieldLegCoveredOrUncovered.getValue( buf ); }
   const char * ptrToLegCoveredOrUncovered() const { return buf + fieldLegCoveredOrUncovered.offset; }
   private: FieldLegCoveredOrUncovered fieldLegCoveredOrUncovered;

   public:
   bool isSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0; }
   FieldNoNestedPartyIDs::ValueType getNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.getValue( buf ); }
   const char * ptrToNoNestedPartyIDs() const { return buf + fieldNoNestedPartyIDs.offset; }
   private: FieldNoNestedPartyIDs fieldNoNestedPartyIDs;
  
   public:
   size_t getGroupCountNestedPartyIDs() const { return groupsNestedPartyIDs.size(); } 
   const GroupNestedPartyIDs & getGroupNestedPartyIDs( size_t idx ) const { return groupsNestedPartyIDs[ idx ]; } 
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
   bool isSetLegSettlType() const { return fieldLegSettlType.offset >= 0; }
   FieldLegSettlType::ValueType getLegSettlType() const { return fieldLegSettlType.getValue( buf ); }
   const char * ptrToLegSettlType() const { return buf + fieldLegSettlType.offset; }
   private: FieldLegSettlType fieldLegSettlType;

   public:
   bool isSetLegSettlDate() const { return fieldLegSettlDate.offset >= 0; }
   FieldLegSettlDate::ValueType getLegSettlDate() const { return fieldLegSettlDate.getValue( buf ); }
   const char * ptrToLegSettlDate() const { return buf + fieldLegSettlDate.offset; }
   private: FieldLegSettlDate fieldLegSettlDate;

   public:
   bool isSetLegLastPx() const { return fieldLegLastPx.offset >= 0; }
   FieldLegLastPx::ValueType getLegLastPx() const { return fieldLegLastPx.getValue( buf ); }
   const char * ptrToLegLastPx() const { return buf + fieldLegLastPx.offset; }
   private: FieldLegLastPx fieldLegLastPx;

};

class GroupQuoteEntries : public MessageBase
{
  
// Methods
   public:
   GroupQuoteEntries();
   typedef std::vector<GroupQuoteEntries> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSymbolSfx() const { return fieldSymbolSfx.offset >= 0; }
   FieldSymbolSfx::ValueType getSymbolSfx() const { return fieldSymbolSfx.getValue( buf ); }
   const char * ptrToSymbolSfx() const { return buf + fieldSymbolSfx.offset; }
   private: FieldSymbolSfx fieldSymbolSfx;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSecurityIDSource() const { return fieldSecurityIDSource.offset >= 0; }
   FieldSecurityIDSource::ValueType getSecurityIDSource() const { return fieldSecurityIDSource.getValue( buf ); }
   const char * ptrToSecurityIDSource() const { return buf + fieldSecurityIDSource.offset; }
   private: FieldSecurityIDSource fieldSecurityIDSource;

   public:
   bool isSetNoSecurityAltID() const { return fieldNoSecurityAltID.offset >= 0; }
   FieldNoSecurityAltID::ValueType getNoSecurityAltID() const { return fieldNoSecurityAltID.getValue( buf ); }
   const char * ptrToNoSecurityAltID() const { return buf + fieldNoSecurityAltID.offset; }
   private: FieldNoSecurityAltID fieldNoSecurityAltID;
  
   public:
   size_t getGroupCountSecurityAltID() const { return groupsSecurityAltID.size(); } 
   const GroupSecurityAltID & getGroupSecurityAltID( size_t idx ) const { return groupsSecurityAltID[ idx ]; } 
   private: GroupSecurityAltID::Array groupsSecurityAltID{ 10 };

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetSecuritySubType() const { return fieldSecuritySubType.offset >= 0; }
   FieldSecuritySubType::ValueType getSecuritySubType() const { return fieldSecuritySubType.getValue( buf ); }
   const char * ptrToSecuritySubType() const { return buf + fieldSecuritySubType.offset; }
   private: FieldSecuritySubType fieldSecuritySubType;

   public:
   bool isSetMaturityMonthYear() const { return fieldMaturityMonthYear.offset >= 0; }
   FieldMaturityMonthYear::ValueType getMaturityMonthYear() const { return fieldMaturityMonthYear.getValue( buf ); }
   const char * ptrToMaturityMonthYear() const { return buf + fieldMaturityMonthYear.offset; }
   private: FieldMaturityMonthYear fieldMaturityMonthYear;

   public:
   bool isSetMaturityDate() const { return fieldMaturityDate.offset >= 0; }
   FieldMaturityDate::ValueType getMaturityDate() const { return fieldMaturityDate.getValue( buf ); }
   const char * ptrToMaturityDate() const { return buf + fieldMaturityDate.offset; }
   private: FieldMaturityDate fieldMaturityDate;

   public:
   bool isSetPutOrCall() const { return fieldPutOrCall.offset >= 0; }
   FieldPutOrCall::ValueType getPutOrCall() const { return fieldPutOrCall.getValue( buf ); }
   const char * ptrToPutOrCall() const { return buf + fieldPutOrCall.offset; }
   private: FieldPutOrCall fieldPutOrCall;

   public:
   bool isSetCouponPaymentDate() const { return fieldCouponPaymentDate.offset >= 0; }
   FieldCouponPaymentDate::ValueType getCouponPaymentDate() const { return fieldCouponPaymentDate.getValue( buf ); }
   const char * ptrToCouponPaymentDate() const { return buf + fieldCouponPaymentDate.offset; }
   private: FieldCouponPaymentDate fieldCouponPaymentDate;

   public:
   bool isSetIssueDate() const { return fieldIssueDate.offset >= 0; }
   FieldIssueDate::ValueType getIssueDate() const { return fieldIssueDate.getValue( buf ); }
   const char * ptrToIssueDate() const { return buf + fieldIssueDate.offset; }
   private: FieldIssueDate fieldIssueDate;

   public:
   bool isSetRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.offset >= 0; }
   FieldRepoCollateralSecurityType::ValueType getRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToRepoCollateralSecurityType() const { return buf + fieldRepoCollateralSecurityType.offset; }
   private: FieldRepoCollateralSecurityType fieldRepoCollateralSecurityType;

   public:
   bool isSetRepurchaseTerm() const { return fieldRepurchaseTerm.offset >= 0; }
   FieldRepurchaseTerm::ValueType getRepurchaseTerm() const { return fieldRepurchaseTerm.getValue( buf ); }
   const char * ptrToRepurchaseTerm() const { return buf + fieldRepurchaseTerm.offset; }
   private: FieldRepurchaseTerm fieldRepurchaseTerm;

   public:
   bool isSetRepurchaseRate() const { return fieldRepurchaseRate.offset >= 0; }
   FieldRepurchaseRate::ValueType getRepurchaseRate() const { return fieldRepurchaseRate.getValue( buf ); }
   const char * ptrToRepurchaseRate() const { return buf + fieldRepurchaseRate.offset; }
   private: FieldRepurchaseRate fieldRepurchaseRate;

   public:
   bool isSetFactor() const { return fieldFactor.offset >= 0; }
   FieldFactor::ValueType getFactor() const { return fieldFactor.getValue( buf ); }
   const char * ptrToFactor() const { return buf + fieldFactor.offset; }
   private: FieldFactor fieldFactor;

   public:
   bool isSetCreditRating() const { return fieldCreditRating.offset >= 0; }
   FieldCreditRating::ValueType getCreditRating() const { return fieldCreditRating.getValue( buf ); }
   const char * ptrToCreditRating() const { return buf + fieldCreditRating.offset; }
   private: FieldCreditRating fieldCreditRating;

   public:
   bool isSetInstrRegistry() const { return fieldInstrRegistry.offset >= 0; }
   FieldInstrRegistry::ValueType getInstrRegistry() const { return fieldInstrRegistry.getValue( buf ); }
   const char * ptrToInstrRegistry() const { return buf + fieldInstrRegistry.offset; }
   private: FieldInstrRegistry fieldInstrRegistry;

   public:
   bool isSetCountryOfIssue() const { return fieldCountryOfIssue.offset >= 0; }
   FieldCountryOfIssue::ValueType getCountryOfIssue() const { return fieldCountryOfIssue.getValue( buf ); }
   const char * ptrToCountryOfIssue() const { return buf + fieldCountryOfIssue.offset; }
   private: FieldCountryOfIssue fieldCountryOfIssue;

   public:
   bool isSetStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.offset >= 0; }
   FieldStateOrProvinceOfIssue::ValueType getStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToStateOrProvinceOfIssue() const { return buf + fieldStateOrProvinceOfIssue.offset; }
   private: FieldStateOrProvinceOfIssue fieldStateOrProvinceOfIssue;

   public:
   bool isSetLocaleOfIssue() const { return fieldLocaleOfIssue.offset >= 0; }
   FieldLocaleOfIssue::ValueType getLocaleOfIssue() const { return fieldLocaleOfIssue.getValue( buf ); }
   const char * ptrToLocaleOfIssue() const { return buf + fieldLocaleOfIssue.offset; }
   private: FieldLocaleOfIssue fieldLocaleOfIssue;

   public:
   bool isSetRedemptionDate() const { return fieldRedemptionDate.offset >= 0; }
   FieldRedemptionDate::ValueType getRedemptionDate() const { return fieldRedemptionDate.getValue( buf ); }
   const char * ptrToRedemptionDate() const { return buf + fieldRedemptionDate.offset; }
   private: FieldRedemptionDate fieldRedemptionDate;

   public:
   bool isSetStrikePrice() const { return fieldStrikePrice.offset >= 0; }
   FieldStrikePrice::ValueType getStrikePrice() const { return fieldStrikePrice.getValue( buf ); }
   const char * ptrToStrikePrice() const { return buf + fieldStrikePrice.offset; }
   private: FieldStrikePrice fieldStrikePrice;

   public:
   bool isSetStrikeCurrency() const { return fieldStrikeCurrency.offset >= 0; }
   FieldStrikeCurrency::ValueType getStrikeCurrency() const { return fieldStrikeCurrency.getValue( buf ); }
   const char * ptrToStrikeCurrency() const { return buf + fieldStrikeCurrency.offset; }
   private: FieldStrikeCurrency fieldStrikeCurrency;

   public:
   bool isSetOptAttribute() const { return fieldOptAttribute.offset >= 0; }
   FieldOptAttribute::ValueType getOptAttribute() const { return fieldOptAttribute.getValue( buf ); }
   const char * ptrToOptAttribute() const { return buf + fieldOptAttribute.offset; }
   private: FieldOptAttribute fieldOptAttribute;

   public:
   bool isSetContractMultiplier() const { return fieldContractMultiplier.offset >= 0; }
   FieldContractMultiplier::ValueType getContractMultiplier() const { return fieldContractMultiplier.getValue( buf ); }
   const char * ptrToContractMultiplier() const { return buf + fieldContractMultiplier.offset; }
   private: FieldContractMultiplier fieldContractMultiplier;

   public:
   bool isSetCouponRate() const { return fieldCouponRate.offset >= 0; }
   FieldCouponRate::ValueType getCouponRate() const { return fieldCouponRate.getValue( buf ); }
   const char * ptrToCouponRate() const { return buf + fieldCouponRate.offset; }
   private: FieldCouponRate fieldCouponRate;

   public:
   bool isSetSecurityExchange() const { return fieldSecurityExchange.offset >= 0; }
   FieldSecurityExchange::ValueType getSecurityExchange() const { return fieldSecurityExchange.getValue( buf ); }
   const char * ptrToSecurityExchange() const { return buf + fieldSecurityExchange.offset; }
   private: FieldSecurityExchange fieldSecurityExchange;

   public:
   bool isSetIssuer() const { return fieldIssuer.offset >= 0; }
   FieldIssuer::ValueType getIssuer() const { return fieldIssuer.getValue( buf ); }
   const char * ptrToIssuer() const { return buf + fieldIssuer.offset; }
   private: FieldIssuer fieldIssuer;

   public:
   bool isSetEncodedIssuerLen() const { return fieldEncodedIssuerLen.offset >= 0; }
   FieldEncodedIssuerLen::ValueType getEncodedIssuerLen() const { return fieldEncodedIssuerLen.getValue( buf ); }
   const char * ptrToEncodedIssuerLen() const { return buf + fieldEncodedIssuerLen.offset; }
   private: FieldEncodedIssuerLen fieldEncodedIssuerLen;

   public:
   bool isSetEncodedIssuer() const { return fieldEncodedIssuer.offset >= 0; }
   FieldEncodedIssuer::ValueType getEncodedIssuer() const { return fieldEncodedIssuer.getValue( buf ); }
   const char * ptrToEncodedIssuer() const { return buf + fieldEncodedIssuer.offset; }
   private: FieldEncodedIssuer fieldEncodedIssuer;

   public:
   bool isSetSecurityDesc() const { return fieldSecurityDesc.offset >= 0; }
   FieldSecurityDesc::ValueType getSecurityDesc() const { return fieldSecurityDesc.getValue( buf ); }
   const char * ptrToSecurityDesc() const { return buf + fieldSecurityDesc.offset; }
   private: FieldSecurityDesc fieldSecurityDesc;

   public:
   bool isSetEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.offset >= 0; }
   FieldEncodedSecurityDescLen::ValueType getEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedSecurityDescLen() const { return buf + fieldEncodedSecurityDescLen.offset; }
   private: FieldEncodedSecurityDescLen fieldEncodedSecurityDescLen;

   public:
   bool isSetEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.offset >= 0; }
   FieldEncodedSecurityDesc::ValueType getEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedSecurityDesc() const { return buf + fieldEncodedSecurityDesc.offset; }
   private: FieldEncodedSecurityDesc fieldEncodedSecurityDesc;

   public:
   bool isSetPool() const { return fieldPool.offset >= 0; }
   FieldPool::ValueType getPool() const { return fieldPool.getValue( buf ); }
   const char * ptrToPool() const { return buf + fieldPool.offset; }
   private: FieldPool fieldPool;

   public:
   bool isSetContractSettlMonth() const { return fieldContractSettlMonth.offset >= 0; }
   FieldContractSettlMonth::ValueType getContractSettlMonth() const { return fieldContractSettlMonth.getValue( buf ); }
   const char * ptrToContractSettlMonth() const { return buf + fieldContractSettlMonth.offset; }
   private: FieldContractSettlMonth fieldContractSettlMonth;

   public:
   bool isSetCPProgram() const { return fieldCPProgram.offset >= 0; }
   FieldCPProgram::ValueType getCPProgram() const { return fieldCPProgram.getValue( buf ); }
   const char * ptrToCPProgram() const { return buf + fieldCPProgram.offset; }
   private: FieldCPProgram fieldCPProgram;

   public:
   bool isSetCPRegType() const { return fieldCPRegType.offset >= 0; }
   FieldCPRegType::ValueType getCPRegType() const { return fieldCPRegType.getValue( buf ); }
   const char * ptrToCPRegType() const { return buf + fieldCPRegType.offset; }
   private: FieldCPRegType fieldCPRegType;

   public:
   bool isSetNoEvents() const { return fieldNoEvents.offset >= 0; }
   FieldNoEvents::ValueType getNoEvents() const { return fieldNoEvents.getValue( buf ); }
   const char * ptrToNoEvents() const { return buf + fieldNoEvents.offset; }
   private: FieldNoEvents fieldNoEvents;
  
   public:
   size_t getGroupCountEvents() const { return groupsEvents.size(); } 
   const GroupEvents & getGroupEvents( size_t idx ) const { return groupsEvents[ idx ]; } 
   private: GroupEvents::Array groupsEvents{ 10 };

   public:
   bool isSetDatedDate() const { return fieldDatedDate.offset >= 0; }
   FieldDatedDate::ValueType getDatedDate() const { return fieldDatedDate.getValue( buf ); }
   const char * ptrToDatedDate() const { return buf + fieldDatedDate.offset; }
   private: FieldDatedDate fieldDatedDate;

   public:
   bool isSetInterestAccrualDate() const { return fieldInterestAccrualDate.offset >= 0; }
   FieldInterestAccrualDate::ValueType getInterestAccrualDate() const { return fieldInterestAccrualDate.getValue( buf ); }
   const char * ptrToInterestAccrualDate() const { return buf + fieldInterestAccrualDate.offset; }
   private: FieldInterestAccrualDate fieldInterestAccrualDate;

   public:
   bool isSetAgreementDesc() const { return fieldAgreementDesc.offset >= 0; }
   FieldAgreementDesc::ValueType getAgreementDesc() const { return fieldAgreementDesc.getValue( buf ); }
   const char * ptrToAgreementDesc() const { return buf + fieldAgreementDesc.offset; }
   private: FieldAgreementDesc fieldAgreementDesc;

   public:
   bool isSetAgreementID() const { return fieldAgreementID.offset >= 0; }
   FieldAgreementID::ValueType getAgreementID() const { return fieldAgreementID.getValue( buf ); }
   const char * ptrToAgreementID() const { return buf + fieldAgreementID.offset; }
   private: FieldAgreementID fieldAgreementID;

   public:
   bool isSetAgreementDate() const { return fieldAgreementDate.offset >= 0; }
   FieldAgreementDate::ValueType getAgreementDate() const { return fieldAgreementDate.getValue( buf ); }
   const char * ptrToAgreementDate() const { return buf + fieldAgreementDate.offset; }
   private: FieldAgreementDate fieldAgreementDate;

   public:
   bool isSetAgreementCurrency() const { return fieldAgreementCurrency.offset >= 0; }
   FieldAgreementCurrency::ValueType getAgreementCurrency() const { return fieldAgreementCurrency.getValue( buf ); }
   const char * ptrToAgreementCurrency() const { return buf + fieldAgreementCurrency.offset; }
   private: FieldAgreementCurrency fieldAgreementCurrency;

   public:
   bool isSetTerminationType() const { return fieldTerminationType.offset >= 0; }
   FieldTerminationType::ValueType getTerminationType() const { return fieldTerminationType.getValue( buf ); }
   const char * ptrToTerminationType() const { return buf + fieldTerminationType.offset; }
   private: FieldTerminationType fieldTerminationType;

   public:
   bool isSetStartDate() const { return fieldStartDate.offset >= 0; }
   FieldStartDate::ValueType getStartDate() const { return fieldStartDate.getValue( buf ); }
   const char * ptrToStartDate() const { return buf + fieldStartDate.offset; }
   private: FieldStartDate fieldStartDate;

   public:
   bool isSetEndDate() const { return fieldEndDate.offset >= 0; }
   FieldEndDate::ValueType getEndDate() const { return fieldEndDate.getValue( buf ); }
   const char * ptrToEndDate() const { return buf + fieldEndDate.offset; }
   private: FieldEndDate fieldEndDate;

   public:
   bool isSetDeliveryType() const { return fieldDeliveryType.offset >= 0; }
   FieldDeliveryType::ValueType getDeliveryType() const { return fieldDeliveryType.getValue( buf ); }
   const char * ptrToDeliveryType() const { return buf + fieldDeliveryType.offset; }
   private: FieldDeliveryType fieldDeliveryType;

   public:
   bool isSetMarginRatio() const { return fieldMarginRatio.offset >= 0; }
   FieldMarginRatio::ValueType getMarginRatio() const { return fieldMarginRatio.getValue( buf ); }
   const char * ptrToMarginRatio() const { return buf + fieldMarginRatio.offset; }
   private: FieldMarginRatio fieldMarginRatio;

   public:
   bool isSetNoUnderlyings() const { return fieldNoUnderlyings.offset >= 0; }
   FieldNoUnderlyings::ValueType getNoUnderlyings() const { return fieldNoUnderlyings.getValue( buf ); }
   const char * ptrToNoUnderlyings() const { return buf + fieldNoUnderlyings.offset; }
   private: FieldNoUnderlyings fieldNoUnderlyings;
  
   public:
   size_t getGroupCountUnderlyings() const { return groupsUnderlyings.size(); } 
   const GroupUnderlyings & getGroupUnderlyings( size_t idx ) const { return groupsUnderlyings[ idx ]; } 
   private: GroupUnderlyings::Array groupsUnderlyings{ 10 };

   public:
   bool isSetNoLegs() const { return fieldNoLegs.offset >= 0; }
   FieldNoLegs::ValueType getNoLegs() const { return fieldNoLegs.getValue( buf ); }
   const char * ptrToNoLegs() const { return buf + fieldNoLegs.offset; }
   private: FieldNoLegs fieldNoLegs;
  
   public:
   size_t getGroupCountLegs() const { return groupsLegs.size(); } 
   const GroupLegs & getGroupLegs( size_t idx ) const { return groupsLegs[ idx ]; } 
   private: GroupLegs::Array groupsLegs{ 10 };

};

class GroupQuoteSets : public MessageBase
{
  
// Methods
   public:
   GroupQuoteSets();
   typedef std::vector<GroupQuoteSets> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetQuoteSetID() const { return fieldQuoteSetID.offset >= 0; }
   FieldQuoteSetID::ValueType getQuoteSetID() const { return fieldQuoteSetID.getValue( buf ); }
   const char * ptrToQuoteSetID() const { return buf + fieldQuoteSetID.offset; }
   private: FieldQuoteSetID fieldQuoteSetID;

   public:
   bool isSetUnderlyingSymbol() const { return fieldUnderlyingSymbol.offset >= 0; }
   FieldUnderlyingSymbol::ValueType getUnderlyingSymbol() const { return fieldUnderlyingSymbol.getValue( buf ); }
   const char * ptrToUnderlyingSymbol() const { return buf + fieldUnderlyingSymbol.offset; }
   private: FieldUnderlyingSymbol fieldUnderlyingSymbol;

   public:
   bool isSetUnderlyingSymbolSfx() const { return fieldUnderlyingSymbolSfx.offset >= 0; }
   FieldUnderlyingSymbolSfx::ValueType getUnderlyingSymbolSfx() const { return fieldUnderlyingSymbolSfx.getValue( buf ); }
   const char * ptrToUnderlyingSymbolSfx() const { return buf + fieldUnderlyingSymbolSfx.offset; }
   private: FieldUnderlyingSymbolSfx fieldUnderlyingSymbolSfx;

   public:
   bool isSetUnderlyingSecurityID() const { return fieldUnderlyingSecurityID.offset >= 0; }
   FieldUnderlyingSecurityID::ValueType getUnderlyingSecurityID() const { return fieldUnderlyingSecurityID.getValue( buf ); }
   const char * ptrToUnderlyingSecurityID() const { return buf + fieldUnderlyingSecurityID.offset; }
   private: FieldUnderlyingSecurityID fieldUnderlyingSecurityID;

   public:
   bool isSetUnderlyingSecurityIDSource() const { return fieldUnderlyingSecurityIDSource.offset >= 0; }
   FieldUnderlyingSecurityIDSource::ValueType getUnderlyingSecurityIDSource() const { return fieldUnderlyingSecurityIDSource.getValue( buf ); }
   const char * ptrToUnderlyingSecurityIDSource() const { return buf + fieldUnderlyingSecurityIDSource.offset; }
   private: FieldUnderlyingSecurityIDSource fieldUnderlyingSecurityIDSource;

   public:
   bool isSetNoUnderlyingSecurityAltID() const { return fieldNoUnderlyingSecurityAltID.offset >= 0; }
   FieldNoUnderlyingSecurityAltID::ValueType getNoUnderlyingSecurityAltID() const { return fieldNoUnderlyingSecurityAltID.getValue( buf ); }
   const char * ptrToNoUnderlyingSecurityAltID() const { return buf + fieldNoUnderlyingSecurityAltID.offset; }
   private: FieldNoUnderlyingSecurityAltID fieldNoUnderlyingSecurityAltID;
  
   public:
   size_t getGroupCountUnderlyingSecurityAltID() const { return groupsUnderlyingSecurityAltID.size(); } 
   const GroupUnderlyingSecurityAltID & getGroupUnderlyingSecurityAltID( size_t idx ) const { return groupsUnderlyingSecurityAltID[ idx ]; } 
   private: GroupUnderlyingSecurityAltID::Array groupsUnderlyingSecurityAltID{ 10 };

   public:
   bool isSetUnderlyingProduct() const { return fieldUnderlyingProduct.offset >= 0; }
   FieldUnderlyingProduct::ValueType getUnderlyingProduct() const { return fieldUnderlyingProduct.getValue( buf ); }
   const char * ptrToUnderlyingProduct() const { return buf + fieldUnderlyingProduct.offset; }
   private: FieldUnderlyingProduct fieldUnderlyingProduct;

   public:
   bool isSetUnderlyingCFICode() const { return fieldUnderlyingCFICode.offset >= 0; }
   FieldUnderlyingCFICode::ValueType getUnderlyingCFICode() const { return fieldUnderlyingCFICode.getValue( buf ); }
   const char * ptrToUnderlyingCFICode() const { return buf + fieldUnderlyingCFICode.offset; }
   private: FieldUnderlyingCFICode fieldUnderlyingCFICode;

   public:
   bool isSetUnderlyingSecurityType() const { return fieldUnderlyingSecurityType.offset >= 0; }
   FieldUnderlyingSecurityType::ValueType getUnderlyingSecurityType() const { return fieldUnderlyingSecurityType.getValue( buf ); }
   const char * ptrToUnderlyingSecurityType() const { return buf + fieldUnderlyingSecurityType.offset; }
   private: FieldUnderlyingSecurityType fieldUnderlyingSecurityType;

   public:
   bool isSetUnderlyingSecuritySubType() const { return fieldUnderlyingSecuritySubType.offset >= 0; }
   FieldUnderlyingSecuritySubType::ValueType getUnderlyingSecuritySubType() const { return fieldUnderlyingSecuritySubType.getValue( buf ); }
   const char * ptrToUnderlyingSecuritySubType() const { return buf + fieldUnderlyingSecuritySubType.offset; }
   private: FieldUnderlyingSecuritySubType fieldUnderlyingSecuritySubType;

   public:
   bool isSetUnderlyingMaturityMonthYear() const { return fieldUnderlyingMaturityMonthYear.offset >= 0; }
   FieldUnderlyingMaturityMonthYear::ValueType getUnderlyingMaturityMonthYear() const { return fieldUnderlyingMaturityMonthYear.getValue( buf ); }
   const char * ptrToUnderlyingMaturityMonthYear() const { return buf + fieldUnderlyingMaturityMonthYear.offset; }
   private: FieldUnderlyingMaturityMonthYear fieldUnderlyingMaturityMonthYear;

   public:
   bool isSetUnderlyingMaturityDate() const { return fieldUnderlyingMaturityDate.offset >= 0; }
   FieldUnderlyingMaturityDate::ValueType getUnderlyingMaturityDate() const { return fieldUnderlyingMaturityDate.getValue( buf ); }
   const char * ptrToUnderlyingMaturityDate() const { return buf + fieldUnderlyingMaturityDate.offset; }
   private: FieldUnderlyingMaturityDate fieldUnderlyingMaturityDate;

   public:
   bool isSetUnderlyingPutOrCall() const { return fieldUnderlyingPutOrCall.offset >= 0; }
   FieldUnderlyingPutOrCall::ValueType getUnderlyingPutOrCall() const { return fieldUnderlyingPutOrCall.getValue( buf ); }
   const char * ptrToUnderlyingPutOrCall() const { return buf + fieldUnderlyingPutOrCall.offset; }
   private: FieldUnderlyingPutOrCall fieldUnderlyingPutOrCall;

   public:
   bool isSetUnderlyingCouponPaymentDate() const { return fieldUnderlyingCouponPaymentDate.offset >= 0; }
   FieldUnderlyingCouponPaymentDate::ValueType getUnderlyingCouponPaymentDate() const { return fieldUnderlyingCouponPaymentDate.getValue( buf ); }
   const char * ptrToUnderlyingCouponPaymentDate() const { return buf + fieldUnderlyingCouponPaymentDate.offset; }
   private: FieldUnderlyingCouponPaymentDate fieldUnderlyingCouponPaymentDate;

   public:
   bool isSetUnderlyingIssueDate() const { return fieldUnderlyingIssueDate.offset >= 0; }
   FieldUnderlyingIssueDate::ValueType getUnderlyingIssueDate() const { return fieldUnderlyingIssueDate.getValue( buf ); }
   const char * ptrToUnderlyingIssueDate() const { return buf + fieldUnderlyingIssueDate.offset; }
   private: FieldUnderlyingIssueDate fieldUnderlyingIssueDate;

   public:
   bool isSetUnderlyingRepoCollateralSecurityType() const { return fieldUnderlyingRepoCollateralSecurityType.offset >= 0; }
   FieldUnderlyingRepoCollateralSecurityType::ValueType getUnderlyingRepoCollateralSecurityType() const { return fieldUnderlyingRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToUnderlyingRepoCollateralSecurityType() const { return buf + fieldUnderlyingRepoCollateralSecurityType.offset; }
   private: FieldUnderlyingRepoCollateralSecurityType fieldUnderlyingRepoCollateralSecurityType;

   public:
   bool isSetUnderlyingRepurchaseTerm() const { return fieldUnderlyingRepurchaseTerm.offset >= 0; }
   FieldUnderlyingRepurchaseTerm::ValueType getUnderlyingRepurchaseTerm() const { return fieldUnderlyingRepurchaseTerm.getValue( buf ); }
   const char * ptrToUnderlyingRepurchaseTerm() const { return buf + fieldUnderlyingRepurchaseTerm.offset; }
   private: FieldUnderlyingRepurchaseTerm fieldUnderlyingRepurchaseTerm;

   public:
   bool isSetUnderlyingRepurchaseRate() const { return fieldUnderlyingRepurchaseRate.offset >= 0; }
   FieldUnderlyingRepurchaseRate::ValueType getUnderlyingRepurchaseRate() const { return fieldUnderlyingRepurchaseRate.getValue( buf ); }
   const char * ptrToUnderlyingRepurchaseRate() const { return buf + fieldUnderlyingRepurchaseRate.offset; }
   private: FieldUnderlyingRepurchaseRate fieldUnderlyingRepurchaseRate;

   public:
   bool isSetUnderlyingFactor() const { return fieldUnderlyingFactor.offset >= 0; }
   FieldUnderlyingFactor::ValueType getUnderlyingFactor() const { return fieldUnderlyingFactor.getValue( buf ); }
   const char * ptrToUnderlyingFactor() const { return buf + fieldUnderlyingFactor.offset; }
   private: FieldUnderlyingFactor fieldUnderlyingFactor;

   public:
   bool isSetUnderlyingCreditRating() const { return fieldUnderlyingCreditRating.offset >= 0; }
   FieldUnderlyingCreditRating::ValueType getUnderlyingCreditRating() const { return fieldUnderlyingCreditRating.getValue( buf ); }
   const char * ptrToUnderlyingCreditRating() const { return buf + fieldUnderlyingCreditRating.offset; }
   private: FieldUnderlyingCreditRating fieldUnderlyingCreditRating;

   public:
   bool isSetUnderlyingInstrRegistry() const { return fieldUnderlyingInstrRegistry.offset >= 0; }
   FieldUnderlyingInstrRegistry::ValueType getUnderlyingInstrRegistry() const { return fieldUnderlyingInstrRegistry.getValue( buf ); }
   const char * ptrToUnderlyingInstrRegistry() const { return buf + fieldUnderlyingInstrRegistry.offset; }
   private: FieldUnderlyingInstrRegistry fieldUnderlyingInstrRegistry;

   public:
   bool isSetUnderlyingCountryOfIssue() const { return fieldUnderlyingCountryOfIssue.offset >= 0; }
   FieldUnderlyingCountryOfIssue::ValueType getUnderlyingCountryOfIssue() const { return fieldUnderlyingCountryOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingCountryOfIssue() const { return buf + fieldUnderlyingCountryOfIssue.offset; }
   private: FieldUnderlyingCountryOfIssue fieldUnderlyingCountryOfIssue;

   public:
   bool isSetUnderlyingStateOrProvinceOfIssue() const { return fieldUnderlyingStateOrProvinceOfIssue.offset >= 0; }
   FieldUnderlyingStateOrProvinceOfIssue::ValueType getUnderlyingStateOrProvinceOfIssue() const { return fieldUnderlyingStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingStateOrProvinceOfIssue() const { return buf + fieldUnderlyingStateOrProvinceOfIssue.offset; }
   private: FieldUnderlyingStateOrProvinceOfIssue fieldUnderlyingStateOrProvinceOfIssue;

   public:
   bool isSetUnderlyingLocaleOfIssue() const { return fieldUnderlyingLocaleOfIssue.offset >= 0; }
   FieldUnderlyingLocaleOfIssue::ValueType getUnderlyingLocaleOfIssue() const { return fieldUnderlyingLocaleOfIssue.getValue( buf ); }
   const char * ptrToUnderlyingLocaleOfIssue() const { return buf + fieldUnderlyingLocaleOfIssue.offset; }
   private: FieldUnderlyingLocaleOfIssue fieldUnderlyingLocaleOfIssue;

   public:
   bool isSetUnderlyingRedemptionDate() const { return fieldUnderlyingRedemptionDate.offset >= 0; }
   FieldUnderlyingRedemptionDate::ValueType getUnderlyingRedemptionDate() const { return fieldUnderlyingRedemptionDate.getValue( buf ); }
   const char * ptrToUnderlyingRedemptionDate() const { return buf + fieldUnderlyingRedemptionDate.offset; }
   private: FieldUnderlyingRedemptionDate fieldUnderlyingRedemptionDate;

   public:
   bool isSetUnderlyingStrikePrice() const { return fieldUnderlyingStrikePrice.offset >= 0; }
   FieldUnderlyingStrikePrice::ValueType getUnderlyingStrikePrice() const { return fieldUnderlyingStrikePrice.getValue( buf ); }
   const char * ptrToUnderlyingStrikePrice() const { return buf + fieldUnderlyingStrikePrice.offset; }
   private: FieldUnderlyingStrikePrice fieldUnderlyingStrikePrice;

   public:
   bool isSetUnderlyingStrikeCurrency() const { return fieldUnderlyingStrikeCurrency.offset >= 0; }
   FieldUnderlyingStrikeCurrency::ValueType getUnderlyingStrikeCurrency() const { return fieldUnderlyingStrikeCurrency.getValue( buf ); }
   const char * ptrToUnderlyingStrikeCurrency() const { return buf + fieldUnderlyingStrikeCurrency.offset; }
   private: FieldUnderlyingStrikeCurrency fieldUnderlyingStrikeCurrency;

   public:
   bool isSetUnderlyingOptAttribute() const { return fieldUnderlyingOptAttribute.offset >= 0; }
   FieldUnderlyingOptAttribute::ValueType getUnderlyingOptAttribute() const { return fieldUnderlyingOptAttribute.getValue( buf ); }
   const char * ptrToUnderlyingOptAttribute() const { return buf + fieldUnderlyingOptAttribute.offset; }
   private: FieldUnderlyingOptAttribute fieldUnderlyingOptAttribute;

   public:
   bool isSetUnderlyingContractMultiplier() const { return fieldUnderlyingContractMultiplier.offset >= 0; }
   FieldUnderlyingContractMultiplier::ValueType getUnderlyingContractMultiplier() const { return fieldUnderlyingContractMultiplier.getValue( buf ); }
   const char * ptrToUnderlyingContractMultiplier() const { return buf + fieldUnderlyingContractMultiplier.offset; }
   private: FieldUnderlyingContractMultiplier fieldUnderlyingContractMultiplier;

   public:
   bool isSetUnderlyingCouponRate() const { return fieldUnderlyingCouponRate.offset >= 0; }
   FieldUnderlyingCouponRate::ValueType getUnderlyingCouponRate() const { return fieldUnderlyingCouponRate.getValue( buf ); }
   const char * ptrToUnderlyingCouponRate() const { return buf + fieldUnderlyingCouponRate.offset; }
   private: FieldUnderlyingCouponRate fieldUnderlyingCouponRate;

   public:
   bool isSetUnderlyingSecurityExchange() const { return fieldUnderlyingSecurityExchange.offset >= 0; }
   FieldUnderlyingSecurityExchange::ValueType getUnderlyingSecurityExchange() const { return fieldUnderlyingSecurityExchange.getValue( buf ); }
   const char * ptrToUnderlyingSecurityExchange() const { return buf + fieldUnderlyingSecurityExchange.offset; }
   private: FieldUnderlyingSecurityExchange fieldUnderlyingSecurityExchange;

   public:
   bool isSetUnderlyingIssuer() const { return fieldUnderlyingIssuer.offset >= 0; }
   FieldUnderlyingIssuer::ValueType getUnderlyingIssuer() const { return fieldUnderlyingIssuer.getValue( buf ); }
   const char * ptrToUnderlyingIssuer() const { return buf + fieldUnderlyingIssuer.offset; }
   private: FieldUnderlyingIssuer fieldUnderlyingIssuer;

   public:
   bool isSetEncodedUnderlyingIssuerLen() const { return fieldEncodedUnderlyingIssuerLen.offset >= 0; }
   FieldEncodedUnderlyingIssuerLen::ValueType getEncodedUnderlyingIssuerLen() const { return fieldEncodedUnderlyingIssuerLen.getValue( buf ); }
   const char * ptrToEncodedUnderlyingIssuerLen() const { return buf + fieldEncodedUnderlyingIssuerLen.offset; }
   private: FieldEncodedUnderlyingIssuerLen fieldEncodedUnderlyingIssuerLen;

   public:
   bool isSetEncodedUnderlyingIssuer() const { return fieldEncodedUnderlyingIssuer.offset >= 0; }
   FieldEncodedUnderlyingIssuer::ValueType getEncodedUnderlyingIssuer() const { return fieldEncodedUnderlyingIssuer.getValue( buf ); }
   const char * ptrToEncodedUnderlyingIssuer() const { return buf + fieldEncodedUnderlyingIssuer.offset; }
   private: FieldEncodedUnderlyingIssuer fieldEncodedUnderlyingIssuer;

   public:
   bool isSetUnderlyingSecurityDesc() const { return fieldUnderlyingSecurityDesc.offset >= 0; }
   FieldUnderlyingSecurityDesc::ValueType getUnderlyingSecurityDesc() const { return fieldUnderlyingSecurityDesc.getValue( buf ); }
   const char * ptrToUnderlyingSecurityDesc() const { return buf + fieldUnderlyingSecurityDesc.offset; }
   private: FieldUnderlyingSecurityDesc fieldUnderlyingSecurityDesc;

   public:
   bool isSetEncodedUnderlyingSecurityDescLen() const { return fieldEncodedUnderlyingSecurityDescLen.offset >= 0; }
   FieldEncodedUnderlyingSecurityDescLen::ValueType getEncodedUnderlyingSecurityDescLen() const { return fieldEncodedUnderlyingSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedUnderlyingSecurityDescLen() const { return buf + fieldEncodedUnderlyingSecurityDescLen.offset; }
   private: FieldEncodedUnderlyingSecurityDescLen fieldEncodedUnderlyingSecurityDescLen;

   public:
   bool isSetEncodedUnderlyingSecurityDesc() const { return fieldEncodedUnderlyingSecurityDesc.offset >= 0; }
   FieldEncodedUnderlyingSecurityDesc::ValueType getEncodedUnderlyingSecurityDesc() const { return fieldEncodedUnderlyingSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedUnderlyingSecurityDesc() const { return buf + fieldEncodedUnderlyingSecurityDesc.offset; }
   private: FieldEncodedUnderlyingSecurityDesc fieldEncodedUnderlyingSecurityDesc;

   public:
   bool isSetUnderlyingCPProgram() const { return fieldUnderlyingCPProgram.offset >= 0; }
   FieldUnderlyingCPProgram::ValueType getUnderlyingCPProgram() const { return fieldUnderlyingCPProgram.getValue( buf ); }
   const char * ptrToUnderlyingCPProgram() const { return buf + fieldUnderlyingCPProgram.offset; }
   private: FieldUnderlyingCPProgram fieldUnderlyingCPProgram;

   public:
   bool isSetUnderlyingCPRegType() const { return fieldUnderlyingCPRegType.offset >= 0; }
   FieldUnderlyingCPRegType::ValueType getUnderlyingCPRegType() const { return fieldUnderlyingCPRegType.getValue( buf ); }
   const char * ptrToUnderlyingCPRegType() const { return buf + fieldUnderlyingCPRegType.offset; }
   private: FieldUnderlyingCPRegType fieldUnderlyingCPRegType;

   public:
   bool isSetUnderlyingCurrency() const { return fieldUnderlyingCurrency.offset >= 0; }
   FieldUnderlyingCurrency::ValueType getUnderlyingCurrency() const { return fieldUnderlyingCurrency.getValue( buf ); }
   const char * ptrToUnderlyingCurrency() const { return buf + fieldUnderlyingCurrency.offset; }
   private: FieldUnderlyingCurrency fieldUnderlyingCurrency;

   public:
   bool isSetUnderlyingQty() const { return fieldUnderlyingQty.offset >= 0; }
   FieldUnderlyingQty::ValueType getUnderlyingQty() const { return fieldUnderlyingQty.getValue( buf ); }
   const char * ptrToUnderlyingQty() const { return buf + fieldUnderlyingQty.offset; }
   private: FieldUnderlyingQty fieldUnderlyingQty;

   public:
   bool isSetUnderlyingPx() const { return fieldUnderlyingPx.offset >= 0; }
   FieldUnderlyingPx::ValueType getUnderlyingPx() const { return fieldUnderlyingPx.getValue( buf ); }
   const char * ptrToUnderlyingPx() const { return buf + fieldUnderlyingPx.offset; }
   private: FieldUnderlyingPx fieldUnderlyingPx;

   public:
   bool isSetUnderlyingDirtyPrice() const { return fieldUnderlyingDirtyPrice.offset >= 0; }
   FieldUnderlyingDirtyPrice::ValueType getUnderlyingDirtyPrice() const { return fieldUnderlyingDirtyPrice.getValue( buf ); }
   const char * ptrToUnderlyingDirtyPrice() const { return buf + fieldUnderlyingDirtyPrice.offset; }
   private: FieldUnderlyingDirtyPrice fieldUnderlyingDirtyPrice;

   public:
   bool isSetUnderlyingEndPrice() const { return fieldUnderlyingEndPrice.offset >= 0; }
   FieldUnderlyingEndPrice::ValueType getUnderlyingEndPrice() const { return fieldUnderlyingEndPrice.getValue( buf ); }
   const char * ptrToUnderlyingEndPrice() const { return buf + fieldUnderlyingEndPrice.offset; }
   private: FieldUnderlyingEndPrice fieldUnderlyingEndPrice;

   public:
   bool isSetUnderlyingStartValue() const { return fieldUnderlyingStartValue.offset >= 0; }
   FieldUnderlyingStartValue::ValueType getUnderlyingStartValue() const { return fieldUnderlyingStartValue.getValue( buf ); }
   const char * ptrToUnderlyingStartValue() const { return buf + fieldUnderlyingStartValue.offset; }
   private: FieldUnderlyingStartValue fieldUnderlyingStartValue;

   public:
   bool isSetUnderlyingCurrentValue() const { return fieldUnderlyingCurrentValue.offset >= 0; }
   FieldUnderlyingCurrentValue::ValueType getUnderlyingCurrentValue() const { return fieldUnderlyingCurrentValue.getValue( buf ); }
   const char * ptrToUnderlyingCurrentValue() const { return buf + fieldUnderlyingCurrentValue.offset; }
   private: FieldUnderlyingCurrentValue fieldUnderlyingCurrentValue;

   public:
   bool isSetUnderlyingEndValue() const { return fieldUnderlyingEndValue.offset >= 0; }
   FieldUnderlyingEndValue::ValueType getUnderlyingEndValue() const { return fieldUnderlyingEndValue.getValue( buf ); }
   const char * ptrToUnderlyingEndValue() const { return buf + fieldUnderlyingEndValue.offset; }
   private: FieldUnderlyingEndValue fieldUnderlyingEndValue;

   public:
   bool isSetNoUnderlyingStips() const { return fieldNoUnderlyingStips.offset >= 0; }
   FieldNoUnderlyingStips::ValueType getNoUnderlyingStips() const { return fieldNoUnderlyingStips.getValue( buf ); }
   const char * ptrToNoUnderlyingStips() const { return buf + fieldNoUnderlyingStips.offset; }
   private: FieldNoUnderlyingStips fieldNoUnderlyingStips;
  
   public:
   size_t getGroupCountUnderlyingStips() const { return groupsUnderlyingStips.size(); } 
   const GroupUnderlyingStips & getGroupUnderlyingStips( size_t idx ) const { return groupsUnderlyingStips[ idx ]; } 
   private: GroupUnderlyingStips::Array groupsUnderlyingStips{ 10 };

   public:
   bool isSetTotNoQuoteEntries() const { return fieldTotNoQuoteEntries.offset >= 0; }
   FieldTotNoQuoteEntries::ValueType getTotNoQuoteEntries() const { return fieldTotNoQuoteEntries.getValue( buf ); }
   const char * ptrToTotNoQuoteEntries() const { return buf + fieldTotNoQuoteEntries.offset; }
   private: FieldTotNoQuoteEntries fieldTotNoQuoteEntries;

   public:
   bool isSetLastFragment() const { return fieldLastFragment.offset >= 0; }
   FieldLastFragment::ValueType getLastFragment() const { return fieldLastFragment.getValue( buf ); }
   const char * ptrToLastFragment() const { return buf + fieldLastFragment.offset; }
   private: FieldLastFragment fieldLastFragment;

   public:
   bool isSetNoQuoteEntries() const { return fieldNoQuoteEntries.offset >= 0; }
   FieldNoQuoteEntries::ValueType getNoQuoteEntries() const { return fieldNoQuoteEntries.getValue( buf ); }
   const char * ptrToNoQuoteEntries() const { return buf + fieldNoQuoteEntries.offset; }
   private: FieldNoQuoteEntries fieldNoQuoteEntries;
  
   public:
   size_t getGroupCountQuoteEntries() const { return groupsQuoteEntries.size(); } 
   const GroupQuoteEntries & getGroupQuoteEntries( size_t idx ) const { return groupsQuoteEntries[ idx ]; } 
   private: GroupQuoteEntries::Array groupsQuoteEntries{ 10 };

};

class GroupSecurityTypes : public MessageBase
{
  
// Methods
   public:
   GroupSecurityTypes();
   typedef std::vector<GroupSecurityTypes> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetSecuritySubType() const { return fieldSecuritySubType.offset >= 0; }
   FieldSecuritySubType::ValueType getSecuritySubType() const { return fieldSecuritySubType.getValue( buf ); }
   const char * ptrToSecuritySubType() const { return buf + fieldSecuritySubType.offset; }
   private: FieldSecuritySubType fieldSecuritySubType;

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

};

class GroupNested3PartyIDs : public MessageBase
{
  
// Methods
   public:
   GroupNested3PartyIDs();
   typedef std::vector<GroupNested3PartyIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetNested3PartyID() const { return fieldNested3PartyID.offset >= 0; }
   FieldNested3PartyID::ValueType getNested3PartyID() const { return fieldNested3PartyID.getValue( buf ); }
   const char * ptrToNested3PartyID() const { return buf + fieldNested3PartyID.offset; }
   private: FieldNested3PartyID fieldNested3PartyID;

   public:
   bool isSetNested3PartyIDSource() const { return fieldNested3PartyIDSource.offset >= 0; }
   FieldNested3PartyIDSource::ValueType getNested3PartyIDSource() const { return fieldNested3PartyIDSource.getValue( buf ); }
   const char * ptrToNested3PartyIDSource() const { return buf + fieldNested3PartyIDSource.offset; }
   private: FieldNested3PartyIDSource fieldNested3PartyIDSource;

   public:
   bool isSetNested3PartyRole() const { return fieldNested3PartyRole.offset >= 0; }
   FieldNested3PartyRole::ValueType getNested3PartyRole() const { return fieldNested3PartyRole.getValue( buf ); }
   const char * ptrToNested3PartyRole() const { return buf + fieldNested3PartyRole.offset; }
   private: FieldNested3PartyRole fieldNested3PartyRole;

   public:
   bool isSetNoNested3PartySubIDs() const { return fieldNoNested3PartySubIDs.offset >= 0; }
   FieldNoNested3PartySubIDs::ValueType getNoNested3PartySubIDs() const { return fieldNoNested3PartySubIDs.getValue( buf ); }
   const char * ptrToNoNested3PartySubIDs() const { return buf + fieldNoNested3PartySubIDs.offset; }
   private: FieldNoNested3PartySubIDs fieldNoNested3PartySubIDs;
  
   public:
   size_t getGroupCountNested3PartySubIDs() const { return groupsNested3PartySubIDs.size(); } 
   const GroupNested3PartySubIDs & getGroupNested3PartySubIDs( size_t idx ) const { return groupsNested3PartySubIDs[ idx ]; } 
   private: GroupNested3PartySubIDs::Array groupsNested3PartySubIDs{ 10 };

};

class GroupPositions : public MessageBase
{
  
// Methods
   public:
   GroupPositions();
   typedef std::vector<GroupPositions> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetPosType() const { return fieldPosType.offset >= 0; }
   FieldPosType::ValueType getPosType() const { return fieldPosType.getValue( buf ); }
   const char * ptrToPosType() const { return buf + fieldPosType.offset; }
   private: FieldPosType fieldPosType;

   public:
   bool isSetLongQty() const { return fieldLongQty.offset >= 0; }
   FieldLongQty::ValueType getLongQty() const { return fieldLongQty.getValue( buf ); }
   const char * ptrToLongQty() const { return buf + fieldLongQty.offset; }
   private: FieldLongQty fieldLongQty;

   public:
   bool isSetShortQty() const { return fieldShortQty.offset >= 0; }
   FieldShortQty::ValueType getShortQty() const { return fieldShortQty.getValue( buf ); }
   const char * ptrToShortQty() const { return buf + fieldShortQty.offset; }
   private: FieldShortQty fieldShortQty;

   public:
   bool isSetPosQtyStatus() const { return fieldPosQtyStatus.offset >= 0; }
   FieldPosQtyStatus::ValueType getPosQtyStatus() const { return fieldPosQtyStatus.getValue( buf ); }
   const char * ptrToPosQtyStatus() const { return buf + fieldPosQtyStatus.offset; }
   private: FieldPosQtyStatus fieldPosQtyStatus;

   public:
   bool isSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0; }
   FieldNoNestedPartyIDs::ValueType getNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.getValue( buf ); }
   const char * ptrToNoNestedPartyIDs() const { return buf + fieldNoNestedPartyIDs.offset; }
   private: FieldNoNestedPartyIDs fieldNoNestedPartyIDs;
  
   public:
   size_t getGroupCountNestedPartyIDs() const { return groupsNestedPartyIDs.size(); } 
   const GroupNestedPartyIDs & getGroupNestedPartyIDs( size_t idx ) const { return groupsNestedPartyIDs[ idx ]; } 
   private: GroupNestedPartyIDs::Array groupsNestedPartyIDs{ 10 };

};

class GroupAffectedOrders : public MessageBase
{
  
// Methods
   public:
   GroupAffectedOrders();
   typedef std::vector<GroupAffectedOrders> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetOrigClOrdID() const { return fieldOrigClOrdID.offset >= 0; }
   FieldOrigClOrdID::ValueType getOrigClOrdID() const { return fieldOrigClOrdID.getValue( buf ); }
   const char * ptrToOrigClOrdID() const { return buf + fieldOrigClOrdID.offset; }
   private: FieldOrigClOrdID fieldOrigClOrdID;

   public:
   bool isSetAffectedOrderID() const { return fieldAffectedOrderID.offset >= 0; }
   FieldAffectedOrderID::ValueType getAffectedOrderID() const { return fieldAffectedOrderID.getValue( buf ); }
   const char * ptrToAffectedOrderID() const { return buf + fieldAffectedOrderID.offset; }
   private: FieldAffectedOrderID fieldAffectedOrderID;

   public:
   bool isSetAffectedSecondaryOrderID() const { return fieldAffectedSecondaryOrderID.offset >= 0; }
   FieldAffectedSecondaryOrderID::ValueType getAffectedSecondaryOrderID() const { return fieldAffectedSecondaryOrderID.getValue( buf ); }
   const char * ptrToAffectedSecondaryOrderID() const { return buf + fieldAffectedSecondaryOrderID.offset; }
   private: FieldAffectedSecondaryOrderID fieldAffectedSecondaryOrderID;

};

class GroupExecs : public MessageBase
{
  
// Methods
   public:
   GroupExecs();
   typedef std::vector<GroupExecs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetLastQty() const { return fieldLastQty.offset >= 0; }
   FieldLastQty::ValueType getLastQty() const { return fieldLastQty.getValue( buf ); }
   const char * ptrToLastQty() const { return buf + fieldLastQty.offset; }
   private: FieldLastQty fieldLastQty;

   public:
   bool isSetExecID() const { return fieldExecID.offset >= 0; }
   FieldExecID::ValueType getExecID() const { return fieldExecID.getValue( buf ); }
   const char * ptrToExecID() const { return buf + fieldExecID.offset; }
   private: FieldExecID fieldExecID;

   public:
   bool isSetSecondaryExecID() const { return fieldSecondaryExecID.offset >= 0; }
   FieldSecondaryExecID::ValueType getSecondaryExecID() const { return fieldSecondaryExecID.getValue( buf ); }
   const char * ptrToSecondaryExecID() const { return buf + fieldSecondaryExecID.offset; }
   private: FieldSecondaryExecID fieldSecondaryExecID;

   public:
   bool isSetLastPx() const { return fieldLastPx.offset >= 0; }
   FieldLastPx::ValueType getLastPx() const { return fieldLastPx.getValue( buf ); }
   const char * ptrToLastPx() const { return buf + fieldLastPx.offset; }
   private: FieldLastPx fieldLastPx;

   public:
   bool isSetLastParPx() const { return fieldLastParPx.offset >= 0; }
   FieldLastParPx::ValueType getLastParPx() const { return fieldLastParPx.getValue( buf ); }
   const char * ptrToLastParPx() const { return buf + fieldLastParPx.offset; }
   private: FieldLastParPx fieldLastParPx;

   public:
   bool isSetLastCapacity() const { return fieldLastCapacity.offset >= 0; }
   FieldLastCapacity::ValueType getLastCapacity() const { return fieldLastCapacity.getValue( buf ); }
   const char * ptrToLastCapacity() const { return buf + fieldLastCapacity.offset; }
   private: FieldLastCapacity fieldLastCapacity;

};

class GroupMsgTypes : public MessageBase
{
  
// Methods
   public:
   GroupMsgTypes();
   typedef std::vector<GroupMsgTypes> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetRefMsgType() const { return fieldRefMsgType.offset >= 0; }
   FieldRefMsgType::ValueType getRefMsgType() const { return fieldRefMsgType.getValue( buf ); }
   const char * ptrToRefMsgType() const { return buf + fieldRefMsgType.offset; }
   private: FieldRefMsgType fieldRefMsgType;

   public:
   bool isSetMsgDirection() const { return fieldMsgDirection.offset >= 0; }
   FieldMsgDirection::ValueType getMsgDirection() const { return fieldMsgDirection.getValue( buf ); }
   const char * ptrToMsgDirection() const { return buf + fieldMsgDirection.offset; }
   private: FieldMsgDirection fieldMsgDirection;

};

class GroupBidComponents : public MessageBase
{
  
// Methods
   public:
   GroupBidComponents();
   typedef std::vector<GroupBidComponents> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetListID() const { return fieldListID.offset >= 0; }
   FieldListID::ValueType getListID() const { return fieldListID.getValue( buf ); }
   const char * ptrToListID() const { return buf + fieldListID.offset; }
   private: FieldListID fieldListID;

   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetTradingSessionID() const { return fieldTradingSessionID.offset >= 0; }
   FieldTradingSessionID::ValueType getTradingSessionID() const { return fieldTradingSessionID.getValue( buf ); }
   const char * ptrToTradingSessionID() const { return buf + fieldTradingSessionID.offset; }
   private: FieldTradingSessionID fieldTradingSessionID;

   public:
   bool isSetTradingSessionSubID() const { return fieldTradingSessionSubID.offset >= 0; }
   FieldTradingSessionSubID::ValueType getTradingSessionSubID() const { return fieldTradingSessionSubID.getValue( buf ); }
   const char * ptrToTradingSessionSubID() const { return buf + fieldTradingSessionSubID.offset; }
   private: FieldTradingSessionSubID fieldTradingSessionSubID;

   public:
   bool isSetNetGrossInd() const { return fieldNetGrossInd.offset >= 0; }
   FieldNetGrossInd::ValueType getNetGrossInd() const { return fieldNetGrossInd.getValue( buf ); }
   const char * ptrToNetGrossInd() const { return buf + fieldNetGrossInd.offset; }
   private: FieldNetGrossInd fieldNetGrossInd;

   public:
   bool isSetSettlType() const { return fieldSettlType.offset >= 0; }
   FieldSettlType::ValueType getSettlType() const { return fieldSettlType.getValue( buf ); }
   const char * ptrToSettlType() const { return buf + fieldSettlType.offset; }
   private: FieldSettlType fieldSettlType;

   public:
   bool isSetSettlDate() const { return fieldSettlDate.offset >= 0; }
   FieldSettlDate::ValueType getSettlDate() const { return fieldSettlDate.getValue( buf ); }
   const char * ptrToSettlDate() const { return buf + fieldSettlDate.offset; }
   private: FieldSettlDate fieldSettlDate;

   public:
   bool isSetAccount() const { return fieldAccount.offset >= 0; }
   FieldAccount::ValueType getAccount() const { return fieldAccount.getValue( buf ); }
   const char * ptrToAccount() const { return buf + fieldAccount.offset; }
   private: FieldAccount fieldAccount;

   public:
   bool isSetAcctIDSource() const { return fieldAcctIDSource.offset >= 0; }
   FieldAcctIDSource::ValueType getAcctIDSource() const { return fieldAcctIDSource.getValue( buf ); }
   const char * ptrToAcctIDSource() const { return buf + fieldAcctIDSource.offset; }
   private: FieldAcctIDSource fieldAcctIDSource;

};

class GroupSettlInst : public MessageBase
{
  
// Methods
   public:
   GroupSettlInst();
   typedef std::vector<GroupSettlInst> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSettlInstID() const { return fieldSettlInstID.offset >= 0; }
   FieldSettlInstID::ValueType getSettlInstID() const { return fieldSettlInstID.getValue( buf ); }
   const char * ptrToSettlInstID() const { return buf + fieldSettlInstID.offset; }
   private: FieldSettlInstID fieldSettlInstID;

   public:
   bool isSetSettlInstTransType() const { return fieldSettlInstTransType.offset >= 0; }
   FieldSettlInstTransType::ValueType getSettlInstTransType() const { return fieldSettlInstTransType.getValue( buf ); }
   const char * ptrToSettlInstTransType() const { return buf + fieldSettlInstTransType.offset; }
   private: FieldSettlInstTransType fieldSettlInstTransType;

   public:
   bool isSetSettlInstRefID() const { return fieldSettlInstRefID.offset >= 0; }
   FieldSettlInstRefID::ValueType getSettlInstRefID() const { return fieldSettlInstRefID.getValue( buf ); }
   const char * ptrToSettlInstRefID() const { return buf + fieldSettlInstRefID.offset; }
   private: FieldSettlInstRefID fieldSettlInstRefID;

   public:
   bool isSetNoPartyIDs() const { return fieldNoPartyIDs.offset >= 0; }
   FieldNoPartyIDs::ValueType getNoPartyIDs() const { return fieldNoPartyIDs.getValue( buf ); }
   const char * ptrToNoPartyIDs() const { return buf + fieldNoPartyIDs.offset; }
   private: FieldNoPartyIDs fieldNoPartyIDs;
  
   public:
   size_t getGroupCountPartyIDs() const { return groupsPartyIDs.size(); } 
   const GroupPartyIDs & getGroupPartyIDs( size_t idx ) const { return groupsPartyIDs[ idx ]; } 
   private: GroupPartyIDs::Array groupsPartyIDs{ 10 };

   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

   public:
   bool isSetEffectiveTime() const { return fieldEffectiveTime.offset >= 0; }
   FieldEffectiveTime::ValueType getEffectiveTime() const { return fieldEffectiveTime.getValue( buf ); }
   const char * ptrToEffectiveTime() const { return buf + fieldEffectiveTime.offset; }
   private: FieldEffectiveTime fieldEffectiveTime;

   public:
   bool isSetExpireTime() const { return fieldExpireTime.offset >= 0; }
   FieldExpireTime::ValueType getExpireTime() const { return fieldExpireTime.getValue( buf ); }
   const char * ptrToExpireTime() const { return buf + fieldExpireTime.offset; }
   private: FieldExpireTime fieldExpireTime;

   public:
   bool isSetLastUpdateTime() const { return fieldLastUpdateTime.offset >= 0; }
   FieldLastUpdateTime::ValueType getLastUpdateTime() const { return fieldLastUpdateTime.getValue( buf ); }
   const char * ptrToLastUpdateTime() const { return buf + fieldLastUpdateTime.offset; }
   private: FieldLastUpdateTime fieldLastUpdateTime;

   public:
   bool isSetSettlDeliveryType() const { return fieldSettlDeliveryType.offset >= 0; }
   FieldSettlDeliveryType::ValueType getSettlDeliveryType() const { return fieldSettlDeliveryType.getValue( buf ); }
   const char * ptrToSettlDeliveryType() const { return buf + fieldSettlDeliveryType.offset; }
   private: FieldSettlDeliveryType fieldSettlDeliveryType;

   public:
   bool isSetStandInstDbType() const { return fieldStandInstDbType.offset >= 0; }
   FieldStandInstDbType::ValueType getStandInstDbType() const { return fieldStandInstDbType.getValue( buf ); }
   const char * ptrToStandInstDbType() const { return buf + fieldStandInstDbType.offset; }
   private: FieldStandInstDbType fieldStandInstDbType;

   public:
   bool isSetStandInstDbName() const { return fieldStandInstDbName.offset >= 0; }
   FieldStandInstDbName::ValueType getStandInstDbName() const { return fieldStandInstDbName.getValue( buf ); }
   const char * ptrToStandInstDbName() const { return buf + fieldStandInstDbName.offset; }
   private: FieldStandInstDbName fieldStandInstDbName;

   public:
   bool isSetStandInstDbID() const { return fieldStandInstDbID.offset >= 0; }
   FieldStandInstDbID::ValueType getStandInstDbID() const { return fieldStandInstDbID.getValue( buf ); }
   const char * ptrToStandInstDbID() const { return buf + fieldStandInstDbID.offset; }
   private: FieldStandInstDbID fieldStandInstDbID;

   public:
   bool isSetNoDlvyInst() const { return fieldNoDlvyInst.offset >= 0; }
   FieldNoDlvyInst::ValueType getNoDlvyInst() const { return fieldNoDlvyInst.getValue( buf ); }
   const char * ptrToNoDlvyInst() const { return buf + fieldNoDlvyInst.offset; }
   private: FieldNoDlvyInst fieldNoDlvyInst;
  
   public:
   size_t getGroupCountDlvyInst() const { return groupsDlvyInst.size(); } 
   const GroupDlvyInst & getGroupDlvyInst( size_t idx ) const { return groupsDlvyInst[ idx ]; } 
   private: GroupDlvyInst::Array groupsDlvyInst{ 10 };

   public:
   bool isSetPaymentMethod() const { return fieldPaymentMethod.offset >= 0; }
   FieldPaymentMethod::ValueType getPaymentMethod() const { return fieldPaymentMethod.getValue( buf ); }
   const char * ptrToPaymentMethod() const { return buf + fieldPaymentMethod.offset; }
   private: FieldPaymentMethod fieldPaymentMethod;

   public:
   bool isSetPaymentRef() const { return fieldPaymentRef.offset >= 0; }
   FieldPaymentRef::ValueType getPaymentRef() const { return fieldPaymentRef.getValue( buf ); }
   const char * ptrToPaymentRef() const { return buf + fieldPaymentRef.offset; }
   private: FieldPaymentRef fieldPaymentRef;

   public:
   bool isSetCardHolderName() const { return fieldCardHolderName.offset >= 0; }
   FieldCardHolderName::ValueType getCardHolderName() const { return fieldCardHolderName.getValue( buf ); }
   const char * ptrToCardHolderName() const { return buf + fieldCardHolderName.offset; }
   private: FieldCardHolderName fieldCardHolderName;

   public:
   bool isSetCardNumber() const { return fieldCardNumber.offset >= 0; }
   FieldCardNumber::ValueType getCardNumber() const { return fieldCardNumber.getValue( buf ); }
   const char * ptrToCardNumber() const { return buf + fieldCardNumber.offset; }
   private: FieldCardNumber fieldCardNumber;

   public:
   bool isSetCardStartDate() const { return fieldCardStartDate.offset >= 0; }
   FieldCardStartDate::ValueType getCardStartDate() const { return fieldCardStartDate.getValue( buf ); }
   const char * ptrToCardStartDate() const { return buf + fieldCardStartDate.offset; }
   private: FieldCardStartDate fieldCardStartDate;

   public:
   bool isSetCardExpDate() const { return fieldCardExpDate.offset >= 0; }
   FieldCardExpDate::ValueType getCardExpDate() const { return fieldCardExpDate.getValue( buf ); }
   const char * ptrToCardExpDate() const { return buf + fieldCardExpDate.offset; }
   private: FieldCardExpDate fieldCardExpDate;

   public:
   bool isSetCardIssNum() const { return fieldCardIssNum.offset >= 0; }
   FieldCardIssNum::ValueType getCardIssNum() const { return fieldCardIssNum.getValue( buf ); }
   const char * ptrToCardIssNum() const { return buf + fieldCardIssNum.offset; }
   private: FieldCardIssNum fieldCardIssNum;

   public:
   bool isSetPaymentDate() const { return fieldPaymentDate.offset >= 0; }
   FieldPaymentDate::ValueType getPaymentDate() const { return fieldPaymentDate.getValue( buf ); }
   const char * ptrToPaymentDate() const { return buf + fieldPaymentDate.offset; }
   private: FieldPaymentDate fieldPaymentDate;

   public:
   bool isSetPaymentRemitterID() const { return fieldPaymentRemitterID.offset >= 0; }
   FieldPaymentRemitterID::ValueType getPaymentRemitterID() const { return fieldPaymentRemitterID.getValue( buf ); }
   const char * ptrToPaymentRemitterID() const { return buf + fieldPaymentRemitterID.offset; }
   private: FieldPaymentRemitterID fieldPaymentRemitterID;

};

class GroupInstrAttrib : public MessageBase
{
  
// Methods
   public:
   GroupInstrAttrib();
   typedef std::vector<GroupInstrAttrib> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetInstrAttribType() const { return fieldInstrAttribType.offset >= 0; }
   FieldInstrAttribType::ValueType getInstrAttribType() const { return fieldInstrAttribType.getValue( buf ); }
   const char * ptrToInstrAttribType() const { return buf + fieldInstrAttribType.offset; }
   private: FieldInstrAttribType fieldInstrAttribType;

   public:
   bool isSetInstrAttribValue() const { return fieldInstrAttribValue.offset >= 0; }
   FieldInstrAttribValue::ValueType getInstrAttribValue() const { return fieldInstrAttribValue.getValue( buf ); }
   const char * ptrToInstrAttribValue() const { return buf + fieldInstrAttribValue.offset; }
   private: FieldInstrAttribValue fieldInstrAttribValue;

};

class GroupMiscFees : public MessageBase
{
  
// Methods
   public:
   GroupMiscFees();
   typedef std::vector<GroupMiscFees> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetMiscFeeAmt() const { return fieldMiscFeeAmt.offset >= 0; }
   FieldMiscFeeAmt::ValueType getMiscFeeAmt() const { return fieldMiscFeeAmt.getValue( buf ); }
   const char * ptrToMiscFeeAmt() const { return buf + fieldMiscFeeAmt.offset; }
   private: FieldMiscFeeAmt fieldMiscFeeAmt;

   public:
   bool isSetMiscFeeCurr() const { return fieldMiscFeeCurr.offset >= 0; }
   FieldMiscFeeCurr::ValueType getMiscFeeCurr() const { return fieldMiscFeeCurr.getValue( buf ); }
   const char * ptrToMiscFeeCurr() const { return buf + fieldMiscFeeCurr.offset; }
   private: FieldMiscFeeCurr fieldMiscFeeCurr;

   public:
   bool isSetMiscFeeType() const { return fieldMiscFeeType.offset >= 0; }
   FieldMiscFeeType::ValueType getMiscFeeType() const { return fieldMiscFeeType.getValue( buf ); }
   const char * ptrToMiscFeeType() const { return buf + fieldMiscFeeType.offset; }
   private: FieldMiscFeeType fieldMiscFeeType;

   public:
   bool isSetMiscFeeBasis() const { return fieldMiscFeeBasis.offset >= 0; }
   FieldMiscFeeBasis::ValueType getMiscFeeBasis() const { return fieldMiscFeeBasis.getValue( buf ); }
   const char * ptrToMiscFeeBasis() const { return buf + fieldMiscFeeBasis.offset; }
   private: FieldMiscFeeBasis fieldMiscFeeBasis;

};

class GroupQuoteQualifiers : public MessageBase
{
  
// Methods
   public:
   GroupQuoteQualifiers();
   typedef std::vector<GroupQuoteQualifiers> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetQuoteQualifier() const { return fieldQuoteQualifier.offset >= 0; }
   FieldQuoteQualifier::ValueType getQuoteQualifier() const { return fieldQuoteQualifier.getValue( buf ); }
   const char * ptrToQuoteQualifier() const { return buf + fieldQuoteQualifier.offset; }
   private: FieldQuoteQualifier fieldQuoteQualifier;

};

class GroupDistribInsts : public MessageBase
{
  
// Methods
   public:
   GroupDistribInsts();
   typedef std::vector<GroupDistribInsts> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetDistribPaymentMethod() const { return fieldDistribPaymentMethod.offset >= 0; }
   FieldDistribPaymentMethod::ValueType getDistribPaymentMethod() const { return fieldDistribPaymentMethod.getValue( buf ); }
   const char * ptrToDistribPaymentMethod() const { return buf + fieldDistribPaymentMethod.offset; }
   private: FieldDistribPaymentMethod fieldDistribPaymentMethod;

   public:
   bool isSetDistribPercentage() const { return fieldDistribPercentage.offset >= 0; }
   FieldDistribPercentage::ValueType getDistribPercentage() const { return fieldDistribPercentage.getValue( buf ); }
   const char * ptrToDistribPercentage() const { return buf + fieldDistribPercentage.offset; }
   private: FieldDistribPercentage fieldDistribPercentage;

   public:
   bool isSetCashDistribCurr() const { return fieldCashDistribCurr.offset >= 0; }
   FieldCashDistribCurr::ValueType getCashDistribCurr() const { return fieldCashDistribCurr.getValue( buf ); }
   const char * ptrToCashDistribCurr() const { return buf + fieldCashDistribCurr.offset; }
   private: FieldCashDistribCurr fieldCashDistribCurr;

   public:
   bool isSetCashDistribAgentName() const { return fieldCashDistribAgentName.offset >= 0; }
   FieldCashDistribAgentName::ValueType getCashDistribAgentName() const { return fieldCashDistribAgentName.getValue( buf ); }
   const char * ptrToCashDistribAgentName() const { return buf + fieldCashDistribAgentName.offset; }
   private: FieldCashDistribAgentName fieldCashDistribAgentName;

   public:
   bool isSetCashDistribAgentCode() const { return fieldCashDistribAgentCode.offset >= 0; }
   FieldCashDistribAgentCode::ValueType getCashDistribAgentCode() const { return fieldCashDistribAgentCode.getValue( buf ); }
   const char * ptrToCashDistribAgentCode() const { return buf + fieldCashDistribAgentCode.offset; }
   private: FieldCashDistribAgentCode fieldCashDistribAgentCode;

   public:
   bool isSetCashDistribAgentAcctNumber() const { return fieldCashDistribAgentAcctNumber.offset >= 0; }
   FieldCashDistribAgentAcctNumber::ValueType getCashDistribAgentAcctNumber() const { return fieldCashDistribAgentAcctNumber.getValue( buf ); }
   const char * ptrToCashDistribAgentAcctNumber() const { return buf + fieldCashDistribAgentAcctNumber.offset; }
   private: FieldCashDistribAgentAcctNumber fieldCashDistribAgentAcctNumber;

   public:
   bool isSetCashDistribPayRef() const { return fieldCashDistribPayRef.offset >= 0; }
   FieldCashDistribPayRef::ValueType getCashDistribPayRef() const { return fieldCashDistribPayRef.getValue( buf ); }
   const char * ptrToCashDistribPayRef() const { return buf + fieldCashDistribPayRef.offset; }
   private: FieldCashDistribPayRef fieldCashDistribPayRef;

   public:
   bool isSetCashDistribAgentAcctName() const { return fieldCashDistribAgentAcctName.offset >= 0; }
   FieldCashDistribAgentAcctName::ValueType getCashDistribAgentAcctName() const { return fieldCashDistribAgentAcctName.getValue( buf ); }
   const char * ptrToCashDistribAgentAcctName() const { return buf + fieldCashDistribAgentAcctName.offset; }
   private: FieldCashDistribAgentAcctName fieldCashDistribAgentAcctName;

};

class GroupTrdRegTimestamps : public MessageBase
{
  
// Methods
   public:
   GroupTrdRegTimestamps();
   typedef std::vector<GroupTrdRegTimestamps> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetTrdRegTimestamp() const { return fieldTrdRegTimestamp.offset >= 0; }
   FieldTrdRegTimestamp::ValueType getTrdRegTimestamp() const { return fieldTrdRegTimestamp.getValue( buf ); }
   const char * ptrToTrdRegTimestamp() const { return buf + fieldTrdRegTimestamp.offset; }
   private: FieldTrdRegTimestamp fieldTrdRegTimestamp;

   public:
   bool isSetTrdRegTimestampType() const { return fieldTrdRegTimestampType.offset >= 0; }
   FieldTrdRegTimestampType::ValueType getTrdRegTimestampType() const { return fieldTrdRegTimestampType.getValue( buf ); }
   const char * ptrToTrdRegTimestampType() const { return buf + fieldTrdRegTimestampType.offset; }
   private: FieldTrdRegTimestampType fieldTrdRegTimestampType;

   public:
   bool isSetTrdRegTimestampOrigin() const { return fieldTrdRegTimestampOrigin.offset >= 0; }
   FieldTrdRegTimestampOrigin::ValueType getTrdRegTimestampOrigin() const { return fieldTrdRegTimestampOrigin.getValue( buf ); }
   const char * ptrToTrdRegTimestampOrigin() const { return buf + fieldTrdRegTimestampOrigin.offset; }
   private: FieldTrdRegTimestampOrigin fieldTrdRegTimestampOrigin;

};

class GroupAltMDSource : public MessageBase
{
  
// Methods
   public:
   GroupAltMDSource();
   typedef std::vector<GroupAltMDSource> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetAltMDSourceID() const { return fieldAltMDSourceID.offset >= 0; }
   FieldAltMDSourceID::ValueType getAltMDSourceID() const { return fieldAltMDSourceID.getValue( buf ); }
   const char * ptrToAltMDSourceID() const { return buf + fieldAltMDSourceID.offset; }
   private: FieldAltMDSourceID fieldAltMDSourceID;

};

class GroupSides : public MessageBase
{
  
// Methods
   public:
   GroupSides();
   typedef std::vector<GroupSides> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSide() const { return fieldSide.offset >= 0; }
   FieldSide::ValueType getSide() const { return fieldSide.getValue( buf ); }
   const char * ptrToSide() const { return buf + fieldSide.offset; }
   private: FieldSide fieldSide;

   public:
   bool isSetOrigClOrdID() const { return fieldOrigClOrdID.offset >= 0; }
   FieldOrigClOrdID::ValueType getOrigClOrdID() const { return fieldOrigClOrdID.getValue( buf ); }
   const char * ptrToOrigClOrdID() const { return buf + fieldOrigClOrdID.offset; }
   private: FieldOrigClOrdID fieldOrigClOrdID;

   public:
   bool isSetClOrdID() const { return fieldClOrdID.offset >= 0; }
   FieldClOrdID::ValueType getClOrdID() const { return fieldClOrdID.getValue( buf ); }
   const char * ptrToClOrdID() const { return buf + fieldClOrdID.offset; }
   private: FieldClOrdID fieldClOrdID;

   public:
   bool isSetSecondaryClOrdID() const { return fieldSecondaryClOrdID.offset >= 0; }
   FieldSecondaryClOrdID::ValueType getSecondaryClOrdID() const { return fieldSecondaryClOrdID.getValue( buf ); }
   const char * ptrToSecondaryClOrdID() const { return buf + fieldSecondaryClOrdID.offset; }
   private: FieldSecondaryClOrdID fieldSecondaryClOrdID;

   public:
   bool isSetClOrdLinkID() const { return fieldClOrdLinkID.offset >= 0; }
   FieldClOrdLinkID::ValueType getClOrdLinkID() const { return fieldClOrdLinkID.getValue( buf ); }
   const char * ptrToClOrdLinkID() const { return buf + fieldClOrdLinkID.offset; }
   private: FieldClOrdLinkID fieldClOrdLinkID;

   public:
   bool isSetOrigOrdModTime() const { return fieldOrigOrdModTime.offset >= 0; }
   FieldOrigOrdModTime::ValueType getOrigOrdModTime() const { return fieldOrigOrdModTime.getValue( buf ); }
   const char * ptrToOrigOrdModTime() const { return buf + fieldOrigOrdModTime.offset; }
   private: FieldOrigOrdModTime fieldOrigOrdModTime;

   public:
   bool isSetNoPartyIDs() const { return fieldNoPartyIDs.offset >= 0; }
   FieldNoPartyIDs::ValueType getNoPartyIDs() const { return fieldNoPartyIDs.getValue( buf ); }
   const char * ptrToNoPartyIDs() const { return buf + fieldNoPartyIDs.offset; }
   private: FieldNoPartyIDs fieldNoPartyIDs;
  
   public:
   size_t getGroupCountPartyIDs() const { return groupsPartyIDs.size(); } 
   const GroupPartyIDs & getGroupPartyIDs( size_t idx ) const { return groupsPartyIDs[ idx ]; } 
   private: GroupPartyIDs::Array groupsPartyIDs{ 10 };

   public:
   bool isSetTradeOriginationDate() const { return fieldTradeOriginationDate.offset >= 0; }
   FieldTradeOriginationDate::ValueType getTradeOriginationDate() const { return fieldTradeOriginationDate.getValue( buf ); }
   const char * ptrToTradeOriginationDate() const { return buf + fieldTradeOriginationDate.offset; }
   private: FieldTradeOriginationDate fieldTradeOriginationDate;

   public:
   bool isSetTradeDate() const { return fieldTradeDate.offset >= 0; }
   FieldTradeDate::ValueType getTradeDate() const { return fieldTradeDate.getValue( buf ); }
   const char * ptrToTradeDate() const { return buf + fieldTradeDate.offset; }
   private: FieldTradeDate fieldTradeDate;

   public:
   bool isSetOrderQty() const { return fieldOrderQty.offset >= 0; }
   FieldOrderQty::ValueType getOrderQty() const { return fieldOrderQty.getValue( buf ); }
   const char * ptrToOrderQty() const { return buf + fieldOrderQty.offset; }
   private: FieldOrderQty fieldOrderQty;

   public:
   bool isSetCashOrderQty() const { return fieldCashOrderQty.offset >= 0; }
   FieldCashOrderQty::ValueType getCashOrderQty() const { return fieldCashOrderQty.getValue( buf ); }
   const char * ptrToCashOrderQty() const { return buf + fieldCashOrderQty.offset; }
   private: FieldCashOrderQty fieldCashOrderQty;

   public:
   bool isSetOrderPercent() const { return fieldOrderPercent.offset >= 0; }
   FieldOrderPercent::ValueType getOrderPercent() const { return fieldOrderPercent.getValue( buf ); }
   const char * ptrToOrderPercent() const { return buf + fieldOrderPercent.offset; }
   private: FieldOrderPercent fieldOrderPercent;

   public:
   bool isSetRoundingDirection() const { return fieldRoundingDirection.offset >= 0; }
   FieldRoundingDirection::ValueType getRoundingDirection() const { return fieldRoundingDirection.getValue( buf ); }
   const char * ptrToRoundingDirection() const { return buf + fieldRoundingDirection.offset; }
   private: FieldRoundingDirection fieldRoundingDirection;

   public:
   bool isSetRoundingModulus() const { return fieldRoundingModulus.offset >= 0; }
   FieldRoundingModulus::ValueType getRoundingModulus() const { return fieldRoundingModulus.getValue( buf ); }
   const char * ptrToRoundingModulus() const { return buf + fieldRoundingModulus.offset; }
   private: FieldRoundingModulus fieldRoundingModulus;

   public:
   bool isSetComplianceID() const { return fieldComplianceID.offset >= 0; }
   FieldComplianceID::ValueType getComplianceID() const { return fieldComplianceID.getValue( buf ); }
   const char * ptrToComplianceID() const { return buf + fieldComplianceID.offset; }
   private: FieldComplianceID fieldComplianceID;

   public:
   bool isSetText() const { return fieldText.offset >= 0; }
   FieldText::ValueType getText() const { return fieldText.getValue( buf ); }
   const char * ptrToText() const { return buf + fieldText.offset; }
   private: FieldText fieldText;

   public:
   bool isSetEncodedTextLen() const { return fieldEncodedTextLen.offset >= 0; }
   FieldEncodedTextLen::ValueType getEncodedTextLen() const { return fieldEncodedTextLen.getValue( buf ); }
   const char * ptrToEncodedTextLen() const { return buf + fieldEncodedTextLen.offset; }
   private: FieldEncodedTextLen fieldEncodedTextLen;

   public:
   bool isSetEncodedText() const { return fieldEncodedText.offset >= 0; }
   FieldEncodedText::ValueType getEncodedText() const { return fieldEncodedText.getValue( buf ); }
   const char * ptrToEncodedText() const { return buf + fieldEncodedText.offset; }
   private: FieldEncodedText fieldEncodedText;

};

class GroupRoutingIDs : public MessageBase
{
  
// Methods
   public:
   GroupRoutingIDs();
   typedef std::vector<GroupRoutingIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetRoutingType() const { return fieldRoutingType.offset >= 0; }
   FieldRoutingType::ValueType getRoutingType() const { return fieldRoutingType.getValue( buf ); }
   const char * ptrToRoutingType() const { return buf + fieldRoutingType.offset; }
   private: FieldRoutingType fieldRoutingType;

   public:
   bool isSetRoutingID() const { return fieldRoutingID.offset >= 0; }
   FieldRoutingID::ValueType getRoutingID() const { return fieldRoutingID.getValue( buf ); }
   const char * ptrToRoutingID() const { return buf + fieldRoutingID.offset; }
   private: FieldRoutingID fieldRoutingID;

};

class GroupPosAmt : public MessageBase
{
  
// Methods
   public:
   GroupPosAmt();
   typedef std::vector<GroupPosAmt> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetPosAmtType() const { return fieldPosAmtType.offset >= 0; }
   FieldPosAmtType::ValueType getPosAmtType() const { return fieldPosAmtType.getValue( buf ); }
   const char * ptrToPosAmtType() const { return buf + fieldPosAmtType.offset; }
   private: FieldPosAmtType fieldPosAmtType;

   public:
   bool isSetPosAmt() const { return fieldPosAmt.offset >= 0; }
   FieldPosAmt::ValueType getPosAmt() const { return fieldPosAmt.getValue( buf ); }
   const char * ptrToPosAmt() const { return buf + fieldPosAmt.offset; }
   private: FieldPosAmt fieldPosAmt;

};

class GroupLinesOfText : public MessageBase
{
  
// Methods
   public:
   GroupLinesOfText();
   typedef std::vector<GroupLinesOfText> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetText() const { return fieldText.offset >= 0; }
   FieldText::ValueType getText() const { return fieldText.getValue( buf ); }
   const char * ptrToText() const { return buf + fieldText.offset; }
   private: FieldText fieldText;

   public:
   bool isSetEncodedTextLen() const { return fieldEncodedTextLen.offset >= 0; }
   FieldEncodedTextLen::ValueType getEncodedTextLen() const { return fieldEncodedTextLen.getValue( buf ); }
   const char * ptrToEncodedTextLen() const { return buf + fieldEncodedTextLen.offset; }
   private: FieldEncodedTextLen fieldEncodedTextLen;

   public:
   bool isSetEncodedText() const { return fieldEncodedText.offset >= 0; }
   FieldEncodedText::ValueType getEncodedText() const { return fieldEncodedText.getValue( buf ); }
   const char * ptrToEncodedText() const { return buf + fieldEncodedText.offset; }
   private: FieldEncodedText fieldEncodedText;

};

class GroupIOIQualifiers : public MessageBase
{
  
// Methods
   public:
   GroupIOIQualifiers();
   typedef std::vector<GroupIOIQualifiers> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetIOIQualifier() const { return fieldIOIQualifier.offset >= 0; }
   FieldIOIQualifier::ValueType getIOIQualifier() const { return fieldIOIQualifier.getValue( buf ); }
   const char * ptrToIOIQualifier() const { return buf + fieldIOIQualifier.offset; }
   private: FieldIOIQualifier fieldIOIQualifier;

};

class GroupDates : public MessageBase
{
  
// Methods
   public:
   GroupDates();
   typedef std::vector<GroupDates> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetTradeDate() const { return fieldTradeDate.offset >= 0; }
   FieldTradeDate::ValueType getTradeDate() const { return fieldTradeDate.getValue( buf ); }
   const char * ptrToTradeDate() const { return buf + fieldTradeDate.offset; }
   private: FieldTradeDate fieldTradeDate;

   public:
   bool isSetTransactTime() const { return fieldTransactTime.offset >= 0; }
   FieldTransactTime::ValueType getTransactTime() const { return fieldTransactTime.getValue( buf ); }
   const char * ptrToTransactTime() const { return buf + fieldTransactTime.offset; }
   private: FieldTransactTime fieldTransactTime;

};

class GroupMDEntryTypes : public MessageBase
{
  
// Methods
   public:
   GroupMDEntryTypes();
   typedef std::vector<GroupMDEntryTypes> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetMDEntryType() const { return fieldMDEntryType.offset >= 0; }
   FieldMDEntryType::ValueType getMDEntryType() const { return fieldMDEntryType.getValue( buf ); }
   const char * ptrToMDEntryType() const { return buf + fieldMDEntryType.offset; }
   private: FieldMDEntryType fieldMDEntryType;

};

class GroupRelatedSym : public MessageBase
{
  
// Methods
   public:
   GroupRelatedSym();
   typedef std::vector<GroupRelatedSym> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSymbolSfx() const { return fieldSymbolSfx.offset >= 0; }
   FieldSymbolSfx::ValueType getSymbolSfx() const { return fieldSymbolSfx.getValue( buf ); }
   const char * ptrToSymbolSfx() const { return buf + fieldSymbolSfx.offset; }
   private: FieldSymbolSfx fieldSymbolSfx;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSecurityIDSource() const { return fieldSecurityIDSource.offset >= 0; }
   FieldSecurityIDSource::ValueType getSecurityIDSource() const { return fieldSecurityIDSource.getValue( buf ); }
   const char * ptrToSecurityIDSource() const { return buf + fieldSecurityIDSource.offset; }
   private: FieldSecurityIDSource fieldSecurityIDSource;

   public:
   bool isSetNoSecurityAltID() const { return fieldNoSecurityAltID.offset >= 0; }
   FieldNoSecurityAltID::ValueType getNoSecurityAltID() const { return fieldNoSecurityAltID.getValue( buf ); }
   const char * ptrToNoSecurityAltID() const { return buf + fieldNoSecurityAltID.offset; }
   private: FieldNoSecurityAltID fieldNoSecurityAltID;
  
   public:
   size_t getGroupCountSecurityAltID() const { return groupsSecurityAltID.size(); } 
   const GroupSecurityAltID & getGroupSecurityAltID( size_t idx ) const { return groupsSecurityAltID[ idx ]; } 
   private: GroupSecurityAltID::Array groupsSecurityAltID{ 10 };

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetSecuritySubType() const { return fieldSecuritySubType.offset >= 0; }
   FieldSecuritySubType::ValueType getSecuritySubType() const { return fieldSecuritySubType.getValue( buf ); }
   const char * ptrToSecuritySubType() const { return buf + fieldSecuritySubType.offset; }
   private: FieldSecuritySubType fieldSecuritySubType;

   public:
   bool isSetMaturityMonthYear() const { return fieldMaturityMonthYear.offset >= 0; }
   FieldMaturityMonthYear::ValueType getMaturityMonthYear() const { return fieldMaturityMonthYear.getValue( buf ); }
   const char * ptrToMaturityMonthYear() const { return buf + fieldMaturityMonthYear.offset; }
   private: FieldMaturityMonthYear fieldMaturityMonthYear;

   public:
   bool isSetMaturityDate() const { return fieldMaturityDate.offset >= 0; }
   FieldMaturityDate::ValueType getMaturityDate() const { return fieldMaturityDate.getValue( buf ); }
   const char * ptrToMaturityDate() const { return buf + fieldMaturityDate.offset; }
   private: FieldMaturityDate fieldMaturityDate;

   public:
   bool isSetPutOrCall() const { return fieldPutOrCall.offset >= 0; }
   FieldPutOrCall::ValueType getPutOrCall() const { return fieldPutOrCall.getValue( buf ); }
   const char * ptrToPutOrCall() const { return buf + fieldPutOrCall.offset; }
   private: FieldPutOrCall fieldPutOrCall;

   public:
   bool isSetCouponPaymentDate() const { return fieldCouponPaymentDate.offset >= 0; }
   FieldCouponPaymentDate::ValueType getCouponPaymentDate() const { return fieldCouponPaymentDate.getValue( buf ); }
   const char * ptrToCouponPaymentDate() const { return buf + fieldCouponPaymentDate.offset; }
   private: FieldCouponPaymentDate fieldCouponPaymentDate;

   public:
   bool isSetIssueDate() const { return fieldIssueDate.offset >= 0; }
   FieldIssueDate::ValueType getIssueDate() const { return fieldIssueDate.getValue( buf ); }
   const char * ptrToIssueDate() const { return buf + fieldIssueDate.offset; }
   private: FieldIssueDate fieldIssueDate;

   public:
   bool isSetRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.offset >= 0; }
   FieldRepoCollateralSecurityType::ValueType getRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToRepoCollateralSecurityType() const { return buf + fieldRepoCollateralSecurityType.offset; }
   private: FieldRepoCollateralSecurityType fieldRepoCollateralSecurityType;

   public:
   bool isSetRepurchaseTerm() const { return fieldRepurchaseTerm.offset >= 0; }
   FieldRepurchaseTerm::ValueType getRepurchaseTerm() const { return fieldRepurchaseTerm.getValue( buf ); }
   const char * ptrToRepurchaseTerm() const { return buf + fieldRepurchaseTerm.offset; }
   private: FieldRepurchaseTerm fieldRepurchaseTerm;

   public:
   bool isSetRepurchaseRate() const { return fieldRepurchaseRate.offset >= 0; }
   FieldRepurchaseRate::ValueType getRepurchaseRate() const { return fieldRepurchaseRate.getValue( buf ); }
   const char * ptrToRepurchaseRate() const { return buf + fieldRepurchaseRate.offset; }
   private: FieldRepurchaseRate fieldRepurchaseRate;

   public:
   bool isSetFactor() const { return fieldFactor.offset >= 0; }
   FieldFactor::ValueType getFactor() const { return fieldFactor.getValue( buf ); }
   const char * ptrToFactor() const { return buf + fieldFactor.offset; }
   private: FieldFactor fieldFactor;

   public:
   bool isSetCreditRating() const { return fieldCreditRating.offset >= 0; }
   FieldCreditRating::ValueType getCreditRating() const { return fieldCreditRating.getValue( buf ); }
   const char * ptrToCreditRating() const { return buf + fieldCreditRating.offset; }
   private: FieldCreditRating fieldCreditRating;

   public:
   bool isSetInstrRegistry() const { return fieldInstrRegistry.offset >= 0; }
   FieldInstrRegistry::ValueType getInstrRegistry() const { return fieldInstrRegistry.getValue( buf ); }
   const char * ptrToInstrRegistry() const { return buf + fieldInstrRegistry.offset; }
   private: FieldInstrRegistry fieldInstrRegistry;

   public:
   bool isSetCountryOfIssue() const { return fieldCountryOfIssue.offset >= 0; }
   FieldCountryOfIssue::ValueType getCountryOfIssue() const { return fieldCountryOfIssue.getValue( buf ); }
   const char * ptrToCountryOfIssue() const { return buf + fieldCountryOfIssue.offset; }
   private: FieldCountryOfIssue fieldCountryOfIssue;

   public:
   bool isSetStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.offset >= 0; }
   FieldStateOrProvinceOfIssue::ValueType getStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToStateOrProvinceOfIssue() const { return buf + fieldStateOrProvinceOfIssue.offset; }
   private: FieldStateOrProvinceOfIssue fieldStateOrProvinceOfIssue;

   public:
   bool isSetLocaleOfIssue() const { return fieldLocaleOfIssue.offset >= 0; }
   FieldLocaleOfIssue::ValueType getLocaleOfIssue() const { return fieldLocaleOfIssue.getValue( buf ); }
   const char * ptrToLocaleOfIssue() const { return buf + fieldLocaleOfIssue.offset; }
   private: FieldLocaleOfIssue fieldLocaleOfIssue;

   public:
   bool isSetRedemptionDate() const { return fieldRedemptionDate.offset >= 0; }
   FieldRedemptionDate::ValueType getRedemptionDate() const { return fieldRedemptionDate.getValue( buf ); }
   const char * ptrToRedemptionDate() const { return buf + fieldRedemptionDate.offset; }
   private: FieldRedemptionDate fieldRedemptionDate;

   public:
   bool isSetStrikePrice() const { return fieldStrikePrice.offset >= 0; }
   FieldStrikePrice::ValueType getStrikePrice() const { return fieldStrikePrice.getValue( buf ); }
   const char * ptrToStrikePrice() const { return buf + fieldStrikePrice.offset; }
   private: FieldStrikePrice fieldStrikePrice;

   public:
   bool isSetStrikeCurrency() const { return fieldStrikeCurrency.offset >= 0; }
   FieldStrikeCurrency::ValueType getStrikeCurrency() const { return fieldStrikeCurrency.getValue( buf ); }
   const char * ptrToStrikeCurrency() const { return buf + fieldStrikeCurrency.offset; }
   private: FieldStrikeCurrency fieldStrikeCurrency;

   public:
   bool isSetOptAttribute() const { return fieldOptAttribute.offset >= 0; }
   FieldOptAttribute::ValueType getOptAttribute() const { return fieldOptAttribute.getValue( buf ); }
   const char * ptrToOptAttribute() const { return buf + fieldOptAttribute.offset; }
   private: FieldOptAttribute fieldOptAttribute;

   public:
   bool isSetContractMultiplier() const { return fieldContractMultiplier.offset >= 0; }
   FieldContractMultiplier::ValueType getContractMultiplier() const { return fieldContractMultiplier.getValue( buf ); }
   const char * ptrToContractMultiplier() const { return buf + fieldContractMultiplier.offset; }
   private: FieldContractMultiplier fieldContractMultiplier;

   public:
   bool isSetCouponRate() const { return fieldCouponRate.offset >= 0; }
   FieldCouponRate::ValueType getCouponRate() const { return fieldCouponRate.getValue( buf ); }
   const char * ptrToCouponRate() const { return buf + fieldCouponRate.offset; }
   private: FieldCouponRate fieldCouponRate;

   public:
   bool isSetSecurityExchange() const { return fieldSecurityExchange.offset >= 0; }
   FieldSecurityExchange::ValueType getSecurityExchange() const { return fieldSecurityExchange.getValue( buf ); }
   const char * ptrToSecurityExchange() const { return buf + fieldSecurityExchange.offset; }
   private: FieldSecurityExchange fieldSecurityExchange;

   public:
   bool isSetIssuer() const { return fieldIssuer.offset >= 0; }
   FieldIssuer::ValueType getIssuer() const { return fieldIssuer.getValue( buf ); }
   const char * ptrToIssuer() const { return buf + fieldIssuer.offset; }
   private: FieldIssuer fieldIssuer;

   public:
   bool isSetEncodedIssuerLen() const { return fieldEncodedIssuerLen.offset >= 0; }
   FieldEncodedIssuerLen::ValueType getEncodedIssuerLen() const { return fieldEncodedIssuerLen.getValue( buf ); }
   const char * ptrToEncodedIssuerLen() const { return buf + fieldEncodedIssuerLen.offset; }
   private: FieldEncodedIssuerLen fieldEncodedIssuerLen;

   public:
   bool isSetEncodedIssuer() const { return fieldEncodedIssuer.offset >= 0; }
   FieldEncodedIssuer::ValueType getEncodedIssuer() const { return fieldEncodedIssuer.getValue( buf ); }
   const char * ptrToEncodedIssuer() const { return buf + fieldEncodedIssuer.offset; }
   private: FieldEncodedIssuer fieldEncodedIssuer;

   public:
   bool isSetSecurityDesc() const { return fieldSecurityDesc.offset >= 0; }
   FieldSecurityDesc::ValueType getSecurityDesc() const { return fieldSecurityDesc.getValue( buf ); }
   const char * ptrToSecurityDesc() const { return buf + fieldSecurityDesc.offset; }
   private: FieldSecurityDesc fieldSecurityDesc;

   public:
   bool isSetEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.offset >= 0; }
   FieldEncodedSecurityDescLen::ValueType getEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedSecurityDescLen() const { return buf + fieldEncodedSecurityDescLen.offset; }
   private: FieldEncodedSecurityDescLen fieldEncodedSecurityDescLen;

   public:
   bool isSetEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.offset >= 0; }
   FieldEncodedSecurityDesc::ValueType getEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedSecurityDesc() const { return buf + fieldEncodedSecurityDesc.offset; }
   private: FieldEncodedSecurityDesc fieldEncodedSecurityDesc;

   public:
   bool isSetPool() const { return fieldPool.offset >= 0; }
   FieldPool::ValueType getPool() const { return fieldPool.getValue( buf ); }
   const char * ptrToPool() const { return buf + fieldPool.offset; }
   private: FieldPool fieldPool;

   public:
   bool isSetContractSettlMonth() const { return fieldContractSettlMonth.offset >= 0; }
   FieldContractSettlMonth::ValueType getContractSettlMonth() const { return fieldContractSettlMonth.getValue( buf ); }
   const char * ptrToContractSettlMonth() const { return buf + fieldContractSettlMonth.offset; }
   private: FieldContractSettlMonth fieldContractSettlMonth;

   public:
   bool isSetCPProgram() const { return fieldCPProgram.offset >= 0; }
   FieldCPProgram::ValueType getCPProgram() const { return fieldCPProgram.getValue( buf ); }
   const char * ptrToCPProgram() const { return buf + fieldCPProgram.offset; }
   private: FieldCPProgram fieldCPProgram;

   public:
   bool isSetCPRegType() const { return fieldCPRegType.offset >= 0; }
   FieldCPRegType::ValueType getCPRegType() const { return fieldCPRegType.getValue( buf ); }
   const char * ptrToCPRegType() const { return buf + fieldCPRegType.offset; }
   private: FieldCPRegType fieldCPRegType;

   public:
   bool isSetNoEvents() const { return fieldNoEvents.offset >= 0; }
   FieldNoEvents::ValueType getNoEvents() const { return fieldNoEvents.getValue( buf ); }
   const char * ptrToNoEvents() const { return buf + fieldNoEvents.offset; }
   private: FieldNoEvents fieldNoEvents;
  
   public:
   size_t getGroupCountEvents() const { return groupsEvents.size(); } 
   const GroupEvents & getGroupEvents( size_t idx ) const { return groupsEvents[ idx ]; } 
   private: GroupEvents::Array groupsEvents{ 10 };

   public:
   bool isSetDatedDate() const { return fieldDatedDate.offset >= 0; }
   FieldDatedDate::ValueType getDatedDate() const { return fieldDatedDate.getValue( buf ); }
   const char * ptrToDatedDate() const { return buf + fieldDatedDate.offset; }
   private: FieldDatedDate fieldDatedDate;

   public:
   bool isSetInterestAccrualDate() const { return fieldInterestAccrualDate.offset >= 0; }
   FieldInterestAccrualDate::ValueType getInterestAccrualDate() const { return fieldInterestAccrualDate.getValue( buf ); }
   const char * ptrToInterestAccrualDate() const { return buf + fieldInterestAccrualDate.offset; }
   private: FieldInterestAccrualDate fieldInterestAccrualDate;

};

class GroupContraBrokers : public MessageBase
{
  
// Methods
   public:
   GroupContraBrokers();
   typedef std::vector<GroupContraBrokers> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetContraBroker() const { return fieldContraBroker.offset >= 0; }
   FieldContraBroker::ValueType getContraBroker() const { return fieldContraBroker.getValue( buf ); }
   const char * ptrToContraBroker() const { return buf + fieldContraBroker.offset; }
   private: FieldContraBroker fieldContraBroker;

   public:
   bool isSetContraTrader() const { return fieldContraTrader.offset >= 0; }
   FieldContraTrader::ValueType getContraTrader() const { return fieldContraTrader.getValue( buf ); }
   const char * ptrToContraTrader() const { return buf + fieldContraTrader.offset; }
   private: FieldContraTrader fieldContraTrader;

   public:
   bool isSetContraTradeQty() const { return fieldContraTradeQty.offset >= 0; }
   FieldContraTradeQty::ValueType getContraTradeQty() const { return fieldContraTradeQty.getValue( buf ); }
   const char * ptrToContraTradeQty() const { return buf + fieldContraTradeQty.offset; }
   private: FieldContraTradeQty fieldContraTradeQty;

   public:
   bool isSetContraTradeTime() const { return fieldContraTradeTime.offset >= 0; }
   FieldContraTradeTime::ValueType getContraTradeTime() const { return fieldContraTradeTime.getValue( buf ); }
   const char * ptrToContraTradeTime() const { return buf + fieldContraTradeTime.offset; }
   private: FieldContraTradeTime fieldContraTradeTime;

   public:
   bool isSetContraLegRefID() const { return fieldContraLegRefID.offset >= 0; }
   FieldContraLegRefID::ValueType getContraLegRefID() const { return fieldContraLegRefID.getValue( buf ); }
   const char * ptrToContraLegRefID() const { return buf + fieldContraLegRefID.offset; }
   private: FieldContraLegRefID fieldContraLegRefID;

};

class GroupTrades : public MessageBase
{
  
// Methods
   public:
   GroupTrades();
   typedef std::vector<GroupTrades> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetTradeReportID() const { return fieldTradeReportID.offset >= 0; }
   FieldTradeReportID::ValueType getTradeReportID() const { return fieldTradeReportID.getValue( buf ); }
   const char * ptrToTradeReportID() const { return buf + fieldTradeReportID.offset; }
   private: FieldTradeReportID fieldTradeReportID;

   public:
   bool isSetSecondaryTradeReportID() const { return fieldSecondaryTradeReportID.offset >= 0; }
   FieldSecondaryTradeReportID::ValueType getSecondaryTradeReportID() const { return fieldSecondaryTradeReportID.getValue( buf ); }
   const char * ptrToSecondaryTradeReportID() const { return buf + fieldSecondaryTradeReportID.offset; }
   private: FieldSecondaryTradeReportID fieldSecondaryTradeReportID;

};

class GroupStrikes : public MessageBase
{
  
// Methods
   public:
   GroupStrikes();
   typedef std::vector<GroupStrikes> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetSymbol() const { return fieldSymbol.offset >= 0; }
   FieldSymbol::ValueType getSymbol() const { return fieldSymbol.getValue( buf ); }
   const char * ptrToSymbol() const { return buf + fieldSymbol.offset; }
   private: FieldSymbol fieldSymbol;

   public:
   bool isSetSymbolSfx() const { return fieldSymbolSfx.offset >= 0; }
   FieldSymbolSfx::ValueType getSymbolSfx() const { return fieldSymbolSfx.getValue( buf ); }
   const char * ptrToSymbolSfx() const { return buf + fieldSymbolSfx.offset; }
   private: FieldSymbolSfx fieldSymbolSfx;

   public:
   bool isSetSecurityID() const { return fieldSecurityID.offset >= 0; }
   FieldSecurityID::ValueType getSecurityID() const { return fieldSecurityID.getValue( buf ); }
   const char * ptrToSecurityID() const { return buf + fieldSecurityID.offset; }
   private: FieldSecurityID fieldSecurityID;

   public:
   bool isSetSecurityIDSource() const { return fieldSecurityIDSource.offset >= 0; }
   FieldSecurityIDSource::ValueType getSecurityIDSource() const { return fieldSecurityIDSource.getValue( buf ); }
   const char * ptrToSecurityIDSource() const { return buf + fieldSecurityIDSource.offset; }
   private: FieldSecurityIDSource fieldSecurityIDSource;

   public:
   bool isSetNoSecurityAltID() const { return fieldNoSecurityAltID.offset >= 0; }
   FieldNoSecurityAltID::ValueType getNoSecurityAltID() const { return fieldNoSecurityAltID.getValue( buf ); }
   const char * ptrToNoSecurityAltID() const { return buf + fieldNoSecurityAltID.offset; }
   private: FieldNoSecurityAltID fieldNoSecurityAltID;
  
   public:
   size_t getGroupCountSecurityAltID() const { return groupsSecurityAltID.size(); } 
   const GroupSecurityAltID & getGroupSecurityAltID( size_t idx ) const { return groupsSecurityAltID[ idx ]; } 
   private: GroupSecurityAltID::Array groupsSecurityAltID{ 10 };

   public:
   bool isSetProduct() const { return fieldProduct.offset >= 0; }
   FieldProduct::ValueType getProduct() const { return fieldProduct.getValue( buf ); }
   const char * ptrToProduct() const { return buf + fieldProduct.offset; }
   private: FieldProduct fieldProduct;

   public:
   bool isSetCFICode() const { return fieldCFICode.offset >= 0; }
   FieldCFICode::ValueType getCFICode() const { return fieldCFICode.getValue( buf ); }
   const char * ptrToCFICode() const { return buf + fieldCFICode.offset; }
   private: FieldCFICode fieldCFICode;

   public:
   bool isSetSecurityType() const { return fieldSecurityType.offset >= 0; }
   FieldSecurityType::ValueType getSecurityType() const { return fieldSecurityType.getValue( buf ); }
   const char * ptrToSecurityType() const { return buf + fieldSecurityType.offset; }
   private: FieldSecurityType fieldSecurityType;

   public:
   bool isSetSecuritySubType() const { return fieldSecuritySubType.offset >= 0; }
   FieldSecuritySubType::ValueType getSecuritySubType() const { return fieldSecuritySubType.getValue( buf ); }
   const char * ptrToSecuritySubType() const { return buf + fieldSecuritySubType.offset; }
   private: FieldSecuritySubType fieldSecuritySubType;

   public:
   bool isSetMaturityMonthYear() const { return fieldMaturityMonthYear.offset >= 0; }
   FieldMaturityMonthYear::ValueType getMaturityMonthYear() const { return fieldMaturityMonthYear.getValue( buf ); }
   const char * ptrToMaturityMonthYear() const { return buf + fieldMaturityMonthYear.offset; }
   private: FieldMaturityMonthYear fieldMaturityMonthYear;

   public:
   bool isSetMaturityDate() const { return fieldMaturityDate.offset >= 0; }
   FieldMaturityDate::ValueType getMaturityDate() const { return fieldMaturityDate.getValue( buf ); }
   const char * ptrToMaturityDate() const { return buf + fieldMaturityDate.offset; }
   private: FieldMaturityDate fieldMaturityDate;

   public:
   bool isSetPutOrCall() const { return fieldPutOrCall.offset >= 0; }
   FieldPutOrCall::ValueType getPutOrCall() const { return fieldPutOrCall.getValue( buf ); }
   const char * ptrToPutOrCall() const { return buf + fieldPutOrCall.offset; }
   private: FieldPutOrCall fieldPutOrCall;

   public:
   bool isSetCouponPaymentDate() const { return fieldCouponPaymentDate.offset >= 0; }
   FieldCouponPaymentDate::ValueType getCouponPaymentDate() const { return fieldCouponPaymentDate.getValue( buf ); }
   const char * ptrToCouponPaymentDate() const { return buf + fieldCouponPaymentDate.offset; }
   private: FieldCouponPaymentDate fieldCouponPaymentDate;

   public:
   bool isSetIssueDate() const { return fieldIssueDate.offset >= 0; }
   FieldIssueDate::ValueType getIssueDate() const { return fieldIssueDate.getValue( buf ); }
   const char * ptrToIssueDate() const { return buf + fieldIssueDate.offset; }
   private: FieldIssueDate fieldIssueDate;

   public:
   bool isSetRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.offset >= 0; }
   FieldRepoCollateralSecurityType::ValueType getRepoCollateralSecurityType() const { return fieldRepoCollateralSecurityType.getValue( buf ); }
   const char * ptrToRepoCollateralSecurityType() const { return buf + fieldRepoCollateralSecurityType.offset; }
   private: FieldRepoCollateralSecurityType fieldRepoCollateralSecurityType;

   public:
   bool isSetRepurchaseTerm() const { return fieldRepurchaseTerm.offset >= 0; }
   FieldRepurchaseTerm::ValueType getRepurchaseTerm() const { return fieldRepurchaseTerm.getValue( buf ); }
   const char * ptrToRepurchaseTerm() const { return buf + fieldRepurchaseTerm.offset; }
   private: FieldRepurchaseTerm fieldRepurchaseTerm;

   public:
   bool isSetRepurchaseRate() const { return fieldRepurchaseRate.offset >= 0; }
   FieldRepurchaseRate::ValueType getRepurchaseRate() const { return fieldRepurchaseRate.getValue( buf ); }
   const char * ptrToRepurchaseRate() const { return buf + fieldRepurchaseRate.offset; }
   private: FieldRepurchaseRate fieldRepurchaseRate;

   public:
   bool isSetFactor() const { return fieldFactor.offset >= 0; }
   FieldFactor::ValueType getFactor() const { return fieldFactor.getValue( buf ); }
   const char * ptrToFactor() const { return buf + fieldFactor.offset; }
   private: FieldFactor fieldFactor;

   public:
   bool isSetCreditRating() const { return fieldCreditRating.offset >= 0; }
   FieldCreditRating::ValueType getCreditRating() const { return fieldCreditRating.getValue( buf ); }
   const char * ptrToCreditRating() const { return buf + fieldCreditRating.offset; }
   private: FieldCreditRating fieldCreditRating;

   public:
   bool isSetInstrRegistry() const { return fieldInstrRegistry.offset >= 0; }
   FieldInstrRegistry::ValueType getInstrRegistry() const { return fieldInstrRegistry.getValue( buf ); }
   const char * ptrToInstrRegistry() const { return buf + fieldInstrRegistry.offset; }
   private: FieldInstrRegistry fieldInstrRegistry;

   public:
   bool isSetCountryOfIssue() const { return fieldCountryOfIssue.offset >= 0; }
   FieldCountryOfIssue::ValueType getCountryOfIssue() const { return fieldCountryOfIssue.getValue( buf ); }
   const char * ptrToCountryOfIssue() const { return buf + fieldCountryOfIssue.offset; }
   private: FieldCountryOfIssue fieldCountryOfIssue;

   public:
   bool isSetStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.offset >= 0; }
   FieldStateOrProvinceOfIssue::ValueType getStateOrProvinceOfIssue() const { return fieldStateOrProvinceOfIssue.getValue( buf ); }
   const char * ptrToStateOrProvinceOfIssue() const { return buf + fieldStateOrProvinceOfIssue.offset; }
   private: FieldStateOrProvinceOfIssue fieldStateOrProvinceOfIssue;

   public:
   bool isSetLocaleOfIssue() const { return fieldLocaleOfIssue.offset >= 0; }
   FieldLocaleOfIssue::ValueType getLocaleOfIssue() const { return fieldLocaleOfIssue.getValue( buf ); }
   const char * ptrToLocaleOfIssue() const { return buf + fieldLocaleOfIssue.offset; }
   private: FieldLocaleOfIssue fieldLocaleOfIssue;

   public:
   bool isSetRedemptionDate() const { return fieldRedemptionDate.offset >= 0; }
   FieldRedemptionDate::ValueType getRedemptionDate() const { return fieldRedemptionDate.getValue( buf ); }
   const char * ptrToRedemptionDate() const { return buf + fieldRedemptionDate.offset; }
   private: FieldRedemptionDate fieldRedemptionDate;

   public:
   bool isSetStrikePrice() const { return fieldStrikePrice.offset >= 0; }
   FieldStrikePrice::ValueType getStrikePrice() const { return fieldStrikePrice.getValue( buf ); }
   const char * ptrToStrikePrice() const { return buf + fieldStrikePrice.offset; }
   private: FieldStrikePrice fieldStrikePrice;

   public:
   bool isSetStrikeCurrency() const { return fieldStrikeCurrency.offset >= 0; }
   FieldStrikeCurrency::ValueType getStrikeCurrency() const { return fieldStrikeCurrency.getValue( buf ); }
   const char * ptrToStrikeCurrency() const { return buf + fieldStrikeCurrency.offset; }
   private: FieldStrikeCurrency fieldStrikeCurrency;

   public:
   bool isSetOptAttribute() const { return fieldOptAttribute.offset >= 0; }
   FieldOptAttribute::ValueType getOptAttribute() const { return fieldOptAttribute.getValue( buf ); }
   const char * ptrToOptAttribute() const { return buf + fieldOptAttribute.offset; }
   private: FieldOptAttribute fieldOptAttribute;

   public:
   bool isSetContractMultiplier() const { return fieldContractMultiplier.offset >= 0; }
   FieldContractMultiplier::ValueType getContractMultiplier() const { return fieldContractMultiplier.getValue( buf ); }
   const char * ptrToContractMultiplier() const { return buf + fieldContractMultiplier.offset; }
   private: FieldContractMultiplier fieldContractMultiplier;

   public:
   bool isSetCouponRate() const { return fieldCouponRate.offset >= 0; }
   FieldCouponRate::ValueType getCouponRate() const { return fieldCouponRate.getValue( buf ); }
   const char * ptrToCouponRate() const { return buf + fieldCouponRate.offset; }
   private: FieldCouponRate fieldCouponRate;

   public:
   bool isSetSecurityExchange() const { return fieldSecurityExchange.offset >= 0; }
   FieldSecurityExchange::ValueType getSecurityExchange() const { return fieldSecurityExchange.getValue( buf ); }
   const char * ptrToSecurityExchange() const { return buf + fieldSecurityExchange.offset; }
   private: FieldSecurityExchange fieldSecurityExchange;

   public:
   bool isSetIssuer() const { return fieldIssuer.offset >= 0; }
   FieldIssuer::ValueType getIssuer() const { return fieldIssuer.getValue( buf ); }
   const char * ptrToIssuer() const { return buf + fieldIssuer.offset; }
   private: FieldIssuer fieldIssuer;

   public:
   bool isSetEncodedIssuerLen() const { return fieldEncodedIssuerLen.offset >= 0; }
   FieldEncodedIssuerLen::ValueType getEncodedIssuerLen() const { return fieldEncodedIssuerLen.getValue( buf ); }
   const char * ptrToEncodedIssuerLen() const { return buf + fieldEncodedIssuerLen.offset; }
   private: FieldEncodedIssuerLen fieldEncodedIssuerLen;

   public:
   bool isSetEncodedIssuer() const { return fieldEncodedIssuer.offset >= 0; }
   FieldEncodedIssuer::ValueType getEncodedIssuer() const { return fieldEncodedIssuer.getValue( buf ); }
   const char * ptrToEncodedIssuer() const { return buf + fieldEncodedIssuer.offset; }
   private: FieldEncodedIssuer fieldEncodedIssuer;

   public:
   bool isSetSecurityDesc() const { return fieldSecurityDesc.offset >= 0; }
   FieldSecurityDesc::ValueType getSecurityDesc() const { return fieldSecurityDesc.getValue( buf ); }
   const char * ptrToSecurityDesc() const { return buf + fieldSecurityDesc.offset; }
   private: FieldSecurityDesc fieldSecurityDesc;

   public:
   bool isSetEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.offset >= 0; }
   FieldEncodedSecurityDescLen::ValueType getEncodedSecurityDescLen() const { return fieldEncodedSecurityDescLen.getValue( buf ); }
   const char * ptrToEncodedSecurityDescLen() const { return buf + fieldEncodedSecurityDescLen.offset; }
   private: FieldEncodedSecurityDescLen fieldEncodedSecurityDescLen;

   public:
   bool isSetEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.offset >= 0; }
   FieldEncodedSecurityDesc::ValueType getEncodedSecurityDesc() const { return fieldEncodedSecurityDesc.getValue( buf ); }
   const char * ptrToEncodedSecurityDesc() const { return buf + fieldEncodedSecurityDesc.offset; }
   private: FieldEncodedSecurityDesc fieldEncodedSecurityDesc;

   public:
   bool isSetPool() const { return fieldPool.offset >= 0; }
   FieldPool::ValueType getPool() const { return fieldPool.getValue( buf ); }
   const char * ptrToPool() const { return buf + fieldPool.offset; }
   private: FieldPool fieldPool;

   public:
   bool isSetContractSettlMonth() const { return fieldContractSettlMonth.offset >= 0; }
   FieldContractSettlMonth::ValueType getContractSettlMonth() const { return fieldContractSettlMonth.getValue( buf ); }
   const char * ptrToContractSettlMonth() const { return buf + fieldContractSettlMonth.offset; }
   private: FieldContractSettlMonth fieldContractSettlMonth;

   public:
   bool isSetCPProgram() const { return fieldCPProgram.offset >= 0; }
   FieldCPProgram::ValueType getCPProgram() const { return fieldCPProgram.getValue( buf ); }
   const char * ptrToCPProgram() const { return buf + fieldCPProgram.offset; }
   private: FieldCPProgram fieldCPProgram;

   public:
   bool isSetCPRegType() const { return fieldCPRegType.offset >= 0; }
   FieldCPRegType::ValueType getCPRegType() const { return fieldCPRegType.getValue( buf ); }
   const char * ptrToCPRegType() const { return buf + fieldCPRegType.offset; }
   private: FieldCPRegType fieldCPRegType;

   public:
   bool isSetNoEvents() const { return fieldNoEvents.offset >= 0; }
   FieldNoEvents::ValueType getNoEvents() const { return fieldNoEvents.getValue( buf ); }
   const char * ptrToNoEvents() const { return buf + fieldNoEvents.offset; }
   private: FieldNoEvents fieldNoEvents;
  
   public:
   size_t getGroupCountEvents() const { return groupsEvents.size(); } 
   const GroupEvents & getGroupEvents( size_t idx ) const { return groupsEvents[ idx ]; } 
   private: GroupEvents::Array groupsEvents{ 10 };

   public:
   bool isSetDatedDate() const { return fieldDatedDate.offset >= 0; }
   FieldDatedDate::ValueType getDatedDate() const { return fieldDatedDate.getValue( buf ); }
   const char * ptrToDatedDate() const { return buf + fieldDatedDate.offset; }
   private: FieldDatedDate fieldDatedDate;

   public:
   bool isSetInterestAccrualDate() const { return fieldInterestAccrualDate.offset >= 0; }
   FieldInterestAccrualDate::ValueType getInterestAccrualDate() const { return fieldInterestAccrualDate.getValue( buf ); }
   const char * ptrToInterestAccrualDate() const { return buf + fieldInterestAccrualDate.offset; }
   private: FieldInterestAccrualDate fieldInterestAccrualDate;

};

class GroupBidDescriptors : public MessageBase
{
  
// Methods
   public:
   GroupBidDescriptors();
   typedef std::vector<GroupBidDescriptors> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetBidDescriptorType() const { return fieldBidDescriptorType.offset >= 0; }
   FieldBidDescriptorType::ValueType getBidDescriptorType() const { return fieldBidDescriptorType.getValue( buf ); }
   const char * ptrToBidDescriptorType() const { return buf + fieldBidDescriptorType.offset; }
   private: FieldBidDescriptorType fieldBidDescriptorType;

   public:
   bool isSetBidDescriptor() const { return fieldBidDescriptor.offset >= 0; }
   FieldBidDescriptor::ValueType getBidDescriptor() const { return fieldBidDescriptor.getValue( buf ); }
   const char * ptrToBidDescriptor() const { return buf + fieldBidDescriptor.offset; }
   private: FieldBidDescriptor fieldBidDescriptor;

   public:
   bool isSetSideValueInd() const { return fieldSideValueInd.offset >= 0; }
   FieldSideValueInd::ValueType getSideValueInd() const { return fieldSideValueInd.getValue( buf ); }
   const char * ptrToSideValueInd() const { return buf + fieldSideValueInd.offset; }
   private: FieldSideValueInd fieldSideValueInd;

   public:
   bool isSetLiquidityValue() const { return fieldLiquidityValue.offset >= 0; }
   FieldLiquidityValue::ValueType getLiquidityValue() const { return fieldLiquidityValue.getValue( buf ); }
   const char * ptrToLiquidityValue() const { return buf + fieldLiquidityValue.offset; }
   private: FieldLiquidityValue fieldLiquidityValue;

   public:
   bool isSetLiquidityNumSecurities() const { return fieldLiquidityNumSecurities.offset >= 0; }
   FieldLiquidityNumSecurities::ValueType getLiquidityNumSecurities() const { return fieldLiquidityNumSecurities.getValue( buf ); }
   const char * ptrToLiquidityNumSecurities() const { return buf + fieldLiquidityNumSecurities.offset; }
   private: FieldLiquidityNumSecurities fieldLiquidityNumSecurities;

   public:
   bool isSetLiquidityPctLow() const { return fieldLiquidityPctLow.offset >= 0; }
   FieldLiquidityPctLow::ValueType getLiquidityPctLow() const { return fieldLiquidityPctLow.getValue( buf ); }
   const char * ptrToLiquidityPctLow() const { return buf + fieldLiquidityPctLow.offset; }
   private: FieldLiquidityPctLow fieldLiquidityPctLow;

   public:
   bool isSetLiquidityPctHigh() const { return fieldLiquidityPctHigh.offset >= 0; }
   FieldLiquidityPctHigh::ValueType getLiquidityPctHigh() const { return fieldLiquidityPctHigh.getValue( buf ); }
   const char * ptrToLiquidityPctHigh() const { return buf + fieldLiquidityPctHigh.offset; }
   private: FieldLiquidityPctHigh fieldLiquidityPctHigh;

   public:
   bool isSetEFPTrackingError() const { return fieldEFPTrackingError.offset >= 0; }
   FieldEFPTrackingError::ValueType getEFPTrackingError() const { return fieldEFPTrackingError.getValue( buf ); }
   const char * ptrToEFPTrackingError() const { return buf + fieldEFPTrackingError.offset; }
   private: FieldEFPTrackingError fieldEFPTrackingError;

   public:
   bool isSetFairValue() const { return fieldFairValue.offset >= 0; }
   FieldFairValue::ValueType getFairValue() const { return fieldFairValue.getValue( buf ); }
   const char * ptrToFairValue() const { return buf + fieldFairValue.offset; }
   private: FieldFairValue fieldFairValue;

   public:
   bool isSetOutsideIndexPct() const { return fieldOutsideIndexPct.offset >= 0; }
   FieldOutsideIndexPct::ValueType getOutsideIndexPct() const { return fieldOutsideIndexPct.getValue( buf ); }
   const char * ptrToOutsideIndexPct() const { return buf + fieldOutsideIndexPct.offset; }
   private: FieldOutsideIndexPct fieldOutsideIndexPct;

   public:
   bool isSetValueOfFutures() const { return fieldValueOfFutures.offset >= 0; }
   FieldValueOfFutures::ValueType getValueOfFutures() const { return fieldValueOfFutures.getValue( buf ); }
   const char * ptrToValueOfFutures() const { return buf + fieldValueOfFutures.offset; }
   private: FieldValueOfFutures fieldValueOfFutures;

};

class GroupCompIDs : public MessageBase
{
  
// Methods
   public:
   GroupCompIDs();
   typedef std::vector<GroupCompIDs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetRefCompID() const { return fieldRefCompID.offset >= 0; }
   FieldRefCompID::ValueType getRefCompID() const { return fieldRefCompID.getValue( buf ); }
   const char * ptrToRefCompID() const { return buf + fieldRefCompID.offset; }
   private: FieldRefCompID fieldRefCompID;

   public:
   bool isSetRefSubID() const { return fieldRefSubID.offset >= 0; }
   FieldRefSubID::ValueType getRefSubID() const { return fieldRefSubID.getValue( buf ); }
   const char * ptrToRefSubID() const { return buf + fieldRefSubID.offset; }
   private: FieldRefSubID fieldRefSubID;

   public:
   bool isSetLocationID() const { return fieldLocationID.offset >= 0; }
   FieldLocationID::ValueType getLocationID() const { return fieldLocationID.getValue( buf ); }
   const char * ptrToLocationID() const { return buf + fieldLocationID.offset; }
   private: FieldLocationID fieldLocationID;

   public:
   bool isSetDeskID() const { return fieldDeskID.offset >= 0; }
   FieldDeskID::ValueType getDeskID() const { return fieldDeskID.getValue( buf ); }
   const char * ptrToDeskID() const { return buf + fieldDeskID.offset; }
   private: FieldDeskID fieldDeskID;

};

class GroupLegAllocs : public MessageBase
{
  
// Methods
   public:
   GroupLegAllocs();
   typedef std::vector<GroupLegAllocs> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetLegAllocAccount() const { return fieldLegAllocAccount.offset >= 0; }
   FieldLegAllocAccount::ValueType getLegAllocAccount() const { return fieldLegAllocAccount.getValue( buf ); }
   const char * ptrToLegAllocAccount() const { return buf + fieldLegAllocAccount.offset; }
   private: FieldLegAllocAccount fieldLegAllocAccount;

   public:
   bool isSetLegIndividualAllocID() const { return fieldLegIndividualAllocID.offset >= 0; }
   FieldLegIndividualAllocID::ValueType getLegIndividualAllocID() const { return fieldLegIndividualAllocID.getValue( buf ); }
   const char * ptrToLegIndividualAllocID() const { return buf + fieldLegIndividualAllocID.offset; }
   private: FieldLegIndividualAllocID fieldLegIndividualAllocID;

   public:
   bool isSetNoNested2PartyIDs() const { return fieldNoNested2PartyIDs.offset >= 0; }
   FieldNoNested2PartyIDs::ValueType getNoNested2PartyIDs() const { return fieldNoNested2PartyIDs.getValue( buf ); }
   const char * ptrToNoNested2PartyIDs() const { return buf + fieldNoNested2PartyIDs.offset; }
   private: FieldNoNested2PartyIDs fieldNoNested2PartyIDs;
  
   public:
   size_t getGroupCountNested2PartyIDs() const { return groupsNested2PartyIDs.size(); } 
   const GroupNested2PartyIDs & getGroupNested2PartyIDs( size_t idx ) const { return groupsNested2PartyIDs[ idx ]; } 
   private: GroupNested2PartyIDs::Array groupsNested2PartyIDs{ 10 };

   public:
   bool isSetLegAllocQty() const { return fieldLegAllocQty.offset >= 0; }
   FieldLegAllocQty::ValueType getLegAllocQty() const { return fieldLegAllocQty.getValue( buf ); }
   const char * ptrToLegAllocQty() const { return buf + fieldLegAllocQty.offset; }
   private: FieldLegAllocQty fieldLegAllocQty;

   public:
   bool isSetLegAllocAcctIDSource() const { return fieldLegAllocAcctIDSource.offset >= 0; }
   FieldLegAllocAcctIDSource::ValueType getLegAllocAcctIDSource() const { return fieldLegAllocAcctIDSource.getValue( buf ); }
   const char * ptrToLegAllocAcctIDSource() const { return buf + fieldLegAllocAcctIDSource.offset; }
   private: FieldLegAllocAcctIDSource fieldLegAllocAcctIDSource;

   public:
   bool isSetLegSettlCurrency() const { return fieldLegSettlCurrency.offset >= 0; }
   FieldLegSettlCurrency::ValueType getLegSettlCurrency() const { return fieldLegSettlCurrency.getValue( buf ); }
   const char * ptrToLegSettlCurrency() const { return buf + fieldLegSettlCurrency.offset; }
   private: FieldLegSettlCurrency fieldLegSettlCurrency;

};

class GroupRegistDtls : public MessageBase
{
  
// Methods
   public:
   GroupRegistDtls();
   typedef std::vector<GroupRegistDtls> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetRegistDtls() const { return fieldRegistDtls.offset >= 0; }
   FieldRegistDtls::ValueType getRegistDtls() const { return fieldRegistDtls.getValue( buf ); }
   const char * ptrToRegistDtls() const { return buf + fieldRegistDtls.offset; }
   private: FieldRegistDtls fieldRegistDtls;

   public:
   bool isSetRegistEmail() const { return fieldRegistEmail.offset >= 0; }
   FieldRegistEmail::ValueType getRegistEmail() const { return fieldRegistEmail.getValue( buf ); }
   const char * ptrToRegistEmail() const { return buf + fieldRegistEmail.offset; }
   private: FieldRegistEmail fieldRegistEmail;

   public:
   bool isSetMailingDtls() const { return fieldMailingDtls.offset >= 0; }
   FieldMailingDtls::ValueType getMailingDtls() const { return fieldMailingDtls.getValue( buf ); }
   const char * ptrToMailingDtls() const { return buf + fieldMailingDtls.offset; }
   private: FieldMailingDtls fieldMailingDtls;

   public:
   bool isSetMailingInst() const { return fieldMailingInst.offset >= 0; }
   FieldMailingInst::ValueType getMailingInst() const { return fieldMailingInst.getValue( buf ); }
   const char * ptrToMailingInst() const { return buf + fieldMailingInst.offset; }
   private: FieldMailingInst fieldMailingInst;

   public:
   bool isSetNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.offset >= 0; }
   FieldNoNestedPartyIDs::ValueType getNoNestedPartyIDs() const { return fieldNoNestedPartyIDs.getValue( buf ); }
   const char * ptrToNoNestedPartyIDs() const { return buf + fieldNoNestedPartyIDs.offset; }
   private: FieldNoNestedPartyIDs fieldNoNestedPartyIDs;
  
   public:
   size_t getGroupCountNestedPartyIDs() const { return groupsNestedPartyIDs.size(); } 
   const GroupNestedPartyIDs & getGroupNestedPartyIDs( size_t idx ) const { return groupsNestedPartyIDs[ idx ]; } 
   private: GroupNestedPartyIDs::Array groupsNestedPartyIDs{ 10 };

   public:
   bool isSetOwnerType() const { return fieldOwnerType.offset >= 0; }
   FieldOwnerType::ValueType getOwnerType() const { return fieldOwnerType.getValue( buf ); }
   const char * ptrToOwnerType() const { return buf + fieldOwnerType.offset; }
   private: FieldOwnerType fieldOwnerType;

   public:
   bool isSetDateOfBirth() const { return fieldDateOfBirth.offset >= 0; }
   FieldDateOfBirth::ValueType getDateOfBirth() const { return fieldDateOfBirth.getValue( buf ); }
   const char * ptrToDateOfBirth() const { return buf + fieldDateOfBirth.offset; }
   private: FieldDateOfBirth fieldDateOfBirth;

   public:
   bool isSetInvestorCountryOfResidence() const { return fieldInvestorCountryOfResidence.offset >= 0; }
   FieldInvestorCountryOfResidence::ValueType getInvestorCountryOfResidence() const { return fieldInvestorCountryOfResidence.getValue( buf ); }
   const char * ptrToInvestorCountryOfResidence() const { return buf + fieldInvestorCountryOfResidence.offset; }
   private: FieldInvestorCountryOfResidence fieldInvestorCountryOfResidence;

};

class GroupContAmts : public MessageBase
{
  
// Methods
   public:
   GroupContAmts();
   typedef std::vector<GroupContAmts> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetContAmtType() const { return fieldContAmtType.offset >= 0; }
   FieldContAmtType::ValueType getContAmtType() const { return fieldContAmtType.getValue( buf ); }
   const char * ptrToContAmtType() const { return buf + fieldContAmtType.offset; }
   private: FieldContAmtType fieldContAmtType;

   public:
   bool isSetContAmtValue() const { return fieldContAmtValue.offset >= 0; }
   FieldContAmtValue::ValueType getContAmtValue() const { return fieldContAmtValue.getValue( buf ); }
   const char * ptrToContAmtValue() const { return buf + fieldContAmtValue.offset; }
   private: FieldContAmtValue fieldContAmtValue;

   public:
   bool isSetContAmtCurr() const { return fieldContAmtCurr.offset >= 0; }
   FieldContAmtCurr::ValueType getContAmtCurr() const { return fieldContAmtCurr.getValue( buf ); }
   const char * ptrToContAmtCurr() const { return buf + fieldContAmtCurr.offset; }
   private: FieldContAmtCurr fieldContAmtCurr;

};

class GroupMDEntries : public MessageBase
{
  
// Methods
   public:
   GroupMDEntries();
   typedef std::vector<GroupMDEntries> Array;
   void reset();
   static const char * getMessageName();
   static offset_t scan( Array & arr, const char * fix, unsigned len );
   static offset_t skip( const char * fix, unsigned len );
   const char * getFieldValue( unsigned tag ) const;
   static FieldDepth getFieldDepth( raw_tag_t tag );
   static const std::vector<unsigned> & getKnownFields();
   private: static GetDepthMethod groupGetDepthMethods[];
   
   public:
   bool isSetMDEntryType() const { return fieldMDEntryType.offset >= 0; }
   FieldMDEntryType::ValueType getMDEntryType() const { return fieldMDEntryType.getValue( buf ); }
   const char * ptrToMDEntryType() const { return buf + fieldMDEntryType.offset; }
   private: FieldMDEntryType fieldMDEntryType;

   public:
   bool isSetMDEntryPx() const { return fieldMDEntryPx.offset >= 0; }
   FieldMDEntryPx::ValueType getMDEntryPx() const { return fieldMDEntryPx.getValue( buf ); }
   const char * ptrToMDEntryPx() const { return buf + fieldMDEntryPx.offset; }
   private: FieldMDEntryPx fieldMDEntryPx;

   public:
   bool isSetCurrency() const { return fieldCurrency.offset >= 0; }
   FieldCurrency::ValueType getCurrency() const { return fieldCurrency.getValue( buf ); }
   const char * ptrToCurrency() const { return buf + fieldCurrency.offset; }
   private: FieldCurrency fieldCurrency;

   public:
   bool isSetMDEntrySize() const { return fieldMDEntrySize.offset >= 0; }
   FieldMDEntrySize::ValueType getMDEntrySize() const { return fieldMDEntrySize.getValue( buf ); }
   const char * ptrToMDEntrySize() const { return buf + fieldMDEntrySize.offset; }
   private: FieldMDEntrySize fieldMDEntrySize;

   public:
   bool isSetMDEntryDate() const { return fieldMDEntryDate.offset >= 0; }
   FieldMDEntryDate::ValueType getMDEntryDate() const { return fieldMDEntryDate.getValue( buf ); }
   const char * ptrToMDEntryDate() const { return buf + fieldMDEntryDate.offset; }
   private: FieldMDEntryDate fieldMDEntryDate;

   public:
   bool isSetMDEntryTime() const { return fieldMDEntryTime.offset >= 0; }
   FieldMDEntryTime::ValueType getMDEntryTime() const { return fieldMDEntryTime.getValue( buf ); }
   const char * ptrToMDEntryTime() const { return buf + fieldMDEntryTime.offset; }
   private: FieldMDEntryTime fieldMDEntryTime;

   public:
   bool isSetTickDirection() const { return fieldTickDirection.offset >= 0; }
   FieldTickDirection::ValueType getTickDirection() const { return fieldTickDirection.getValue( buf ); }
   const char * ptrToTickDirection() const { return buf + fieldTickDirection.offset; }
   private: FieldTickDirection fieldTickDirection;

   public:
   bool isSetMDMkt() const { return fieldMDMkt.offset >= 0; }
   FieldMDMkt::ValueType getMDMkt() const { return fieldMDMkt.getValue( buf ); }
   const char * ptrToMDMkt() const { return buf + fieldMDMkt.offset; }
   private: FieldMDMkt fieldMDMkt;

   public:
   bool isSetTradingSessionID() const { return fieldTradingSessionID.offset >= 0; }
   FieldTradingSessionID::ValueType getTradingSessionID() const { return fieldTradingSessionID.getValue( buf ); }
   const char * ptrToTradingSessionID() const { return buf + fieldTradingSessionID.offset; }
   private: FieldTradingSessionID fieldTradingSessionID;

   public:
   bool isSetTradingSessionSubID() const { return fieldTradingSessionSubID.offset >= 0; }
   FieldTradingSessionSubID::ValueType getTradingSessionSubID() const { return fieldTradingSessionSubID.getValue( buf ); }
   const char * ptrToTradingSessionSubID() const { return buf + fieldTradingSessionSubID.offset; }
   private: FieldTradingSessionSubID fieldTradingSessionSubID;

   public:
   bool isSetQuoteCondition() const { return fieldQuoteCondition.offset >= 0; }
   FieldQuoteCondition::ValueType getQuoteCondition() const { return fieldQuoteCondition.getValue( buf ); }
   const char * ptrToQuoteCondition() const { return buf + fieldQuoteCondition.offset; }
   private: FieldQuoteCondition fieldQuoteCondition;

   public:
   bool isSetTradeCondition() const { return fieldTradeCondition.offset >= 0; }
   FieldTradeCondition::ValueType getTradeCondition() const { return fieldTradeCondition.getValue( buf ); }
   const char * ptrToTradeCondition() const { return buf + fieldTradeCondition.offset; }
   private: FieldTradeCondition fieldTradeCondition;

   public:
   bool isSetMDEntryOriginator() const { return fieldMDEntryOriginator.offset >= 0; }
   FieldMDEntryOriginator::ValueType getMDEntryOriginator() const { return fieldMDEntryOriginator.getValue( buf ); }
   const char * ptrToMDEntryOriginator() const { return buf + fieldMDEntryOriginator.offset; }
   private: FieldMDEntryOriginator fieldMDEntryOriginator;

   public:
   bool isSetLocationID() const { return fieldLocationID.offset >= 0; }
   FieldLocationID::ValueType getLocationID() const { return fieldLocationID.getValue( buf ); }
   const char * ptrToLocationID() const { return buf + fieldLocationID.offset; }
   private: FieldLocationID fieldLocationID;

   public:
   bool isSetDeskID() const { return fieldDeskID.offset >= 0; }
   FieldDeskID::ValueType getDeskID() const { return fieldDeskID.getValue( buf ); }
   const char * ptrToDeskID() const { return buf + fieldDeskID.offset; }
   private: FieldDeskID fieldDeskID;

   public:
   bool isSetOpenCloseSettlFlag() const { return fieldOpenCloseSettlFlag.offset >= 0; }
   FieldOpenCloseSettlFlag::ValueType getOpenCloseSettlFlag() const { return fieldOpenCloseSettlFlag.getValue( buf ); }
   const char * ptrToOpenCloseSettlFlag() const { return buf + fieldOpenCloseSettlFlag.offset; }
   private: FieldOpenCloseSettlFlag fieldOpenCloseSettlFlag;

   public:
   bool isSetTimeInForce() const { return fieldTimeInForce.offset >= 0; }
   FieldTimeInForce::ValueType getTimeInForce() const { return fieldTimeInForce.getValue( buf ); }
   const char * ptrToTimeInForce() const { return buf + fieldTimeInForce.offset; }
   private: FieldTimeInForce fieldTimeInForce;

   public:
   bool isSetExpireDate() const { return fieldExpireDate.offset >= 0; }
   FieldExpireDate::ValueType getExpireDate() const { return fieldExpireDate.getValue( buf ); }
   const char * ptrToExpireDate() const { return buf + fieldExpireDate.offset; }
   private: FieldExpireDate fieldExpireDate;

   public:
   bool isSetExpireTime() const { return fieldExpireTime.offset >= 0; }
   FieldExpireTime::ValueType getExpireTime() const { return fieldExpireTime.getValue( buf ); }
   const char * ptrToExpireTime() const { return buf + fieldExpireTime.offset; }
   private: FieldExpireTime fieldExpireTime;

   public:
   bool isSetMinQty() const { return fieldMinQty.offset >= 0; }
   FieldMinQty::ValueType getMinQty() const { return fieldMinQty.getValue( buf ); }
   const char * ptrToMinQty() const { return buf + fieldMinQty.offset; }
   private: FieldMinQty fieldMinQty;

   public:
   bool isSetExecInst() const { return fieldExecInst.offset >= 0; }
   FieldExecInst::ValueType getExecInst() const { return fieldExecInst.getValue( buf ); }
   const char * ptrToExecInst() const { return buf + fieldExecInst.offset; }
   private: FieldExecInst fieldExecInst;

   public:
   bool isSetSellerDays() const { return fieldSellerDays.offset >= 0; }
   FieldSellerDays::ValueType getSellerDays() const { return fieldSellerDays.getValue( buf ); }
   const char * ptrToSellerDays() const { return buf + fieldSellerDays.offset; }
   private: FieldSellerDays fieldSellerDays;

   public:
   bool isSetOrderID() const { return fieldOrderID.offset >= 0; }
   FieldOrderID::ValueType getOrderID() const { return fieldOrderID.getValue( buf ); }
   const char * ptrToOrderID() const { return buf + fieldOrderID.offset; }
   private: FieldOrderID fieldOrderID;

   public:
   bool isSetQuoteEntryID() const { return fieldQuoteEntryID.offset >= 0; }
   FieldQuoteEntryID::ValueType getQuoteEntryID() const { return fieldQuoteEntryID.getValue( buf ); }
   const char * ptrToQuoteEntryID() const { return buf + fieldQuoteEntryID.offset; }
   private: FieldQuoteEntryID fieldQuoteEntryID;

   public:
   bool isSetMDEntryBuyer() const { return fieldMDEntryBuyer.offset >= 0; }
   FieldMDEntryBuyer::ValueType getMDEntryBuyer() const { return fieldMDEntryBuyer.getValue( buf ); }
   const char * ptrToMDEntryBuyer() const { return buf + fieldMDEntryBuyer.offset; }
   private: FieldMDEntryBuyer fieldMDEntryBuyer;

   public:
   bool isSetMDEntrySeller() const { return fieldMDEntrySeller.offset >= 0; }
   FieldMDEntrySeller::ValueType getMDEntrySeller() const { return fieldMDEntrySeller.getValue( buf ); }
   const char * ptrToMDEntrySeller() const { return buf + fieldMDEntrySeller.offset; }
   private: FieldMDEntrySeller fieldMDEntrySeller;

   public:
   bool isSetNumberOfOrders() const { return fieldNumberOfOrders.offset >= 0; }
   FieldNumberOfOrders::ValueType getNumberOfOrders() const { return fieldNumberOfOrders.getValue( buf ); }
   const char * ptrToNumberOfOrders() const { return buf + fieldNumberOfOrders.offset; }
   private: FieldNumberOfOrders fieldNumberOfOrders;

   public:
   bool isSetMDEntryPositionNo() const { return fieldMDEntryPositionNo.offset >= 0; }
   FieldMDEntryPositionNo::ValueType getMDEntryPositionNo() const { return fieldMDEntryPositionNo.getValue( buf ); }
   const char * ptrToMDEntryPositionNo() const { return buf + fieldMDEntryPositionNo.offset; }
   private: FieldMDEntryPositionNo fieldMDEntryPositionNo;

   public:
   bool isSetScope() const { return fieldScope.offset >= 0; }
   FieldScope::ValueType getScope() const { return fieldScope.getValue( buf ); }
   const char * ptrToScope() const { return buf + fieldScope.offset; }
   private: FieldScope fieldScope;

   public:
   bool isSetPriceDelta() const { return fieldPriceDelta.offset >= 0; }
   FieldPriceDelta::ValueType getPriceDelta() const { return fieldPriceDelta.getValue( buf ); }
   const char * ptrToPriceDelta() const { return buf + fieldPriceDelta.offset; }
   private: FieldPriceDelta fieldPriceDelta;

   public:
   bool isSetText() const { return fieldText.offset >= 0; }
   FieldText::ValueType getText() const { return fieldText.getValue( buf ); }
   const char * ptrToText() const { return buf + fieldText.offset; }
   private: FieldText fieldText;

   public:
   bool isSetEncodedTextLen() const { return fieldEncodedTextLen.offset >= 0; }
   FieldEncodedTextLen::ValueType getEncodedTextLen() const { return fieldEncodedTextLen.getValue( buf ); }
   const char * ptrToEncodedTextLen() const { return buf + fieldEncodedTextLen.offset; }
   private: FieldEncodedTextLen fieldEncodedTextLen;

   public:
   bool isSetEncodedText() const { return fieldEncodedText.offset >= 0; }
   FieldEncodedText::ValueType getEncodedText() const { return fieldEncodedText.getValue( buf ); }
   const char * ptrToEncodedText() const { return buf + fieldEncodedText.offset; }
   private: FieldEncodedText fieldEncodedText;

};
