#pragma once
#ifndef order_FIELDS_H
#define order_FIELDS_H

#include <order/FixApi.h>

#include <iostream>
#include <map>

std::ostream & operator << ( std::ostream & os, const order::sohstr & str );

namespace order
{

struct FieldDepth
{
    int16_t depth = -1;
    int16_t isFirstInGroup = false;
    const FieldDepth & inc(){ ++depth; return *this; }
};

typedef FieldDepth (*GetDepthMethod)( raw_tag_t );

extern const std::map< raw_tag_t, const char * const >           & rawToTagName;
extern const std::map< unsigned, const char * const >            & valueToTagName;
extern const std::map< raw_tag_t, const FieldEnumsBase * const > & rawToEnum;

// start of Fields.hxx

// Generated

// -------------------------------------- names ----------------------------------------
extern const std::string FixBeginStringValue; 
constexpr const char * const FixBeginStringInsertableTag = "8=" "FIX.4.4"; 
constexpr const unsigned FixBeginStringInsertableTagLength = 9;

extern const char * const FixAccount;
extern const char * const FixAvgPx;
extern const char * const FixBeginString;
extern const char * const FixBodyLength;
extern const char * const FixCheckSum;
extern const char * const FixClOrdID;
extern const char * const FixCumQty;
extern const char * const FixCurrency;
extern const char * const FixExecID;
extern const char * const FixExecInst;
extern const char * const FixLastPx;
extern const char * const FixLastQty;
extern const char * const FixMsgSeqNum;
extern const char * const FixMsgType;
extern const char * const FixOrderID;
extern const char * const FixOrderQty;
extern const char * const FixOrdStatus;
extern const char * const FixOrdType;
extern const char * const FixOrigClOrdID;
extern const char * const FixPrice;
extern const char * const FixSecurityID;
extern const char * const FixSenderCompID;
extern const char * const FixSendingTime;
extern const char * const FixSide;
extern const char * const FixSymbol;
extern const char * const FixTargetCompID;
extern const char * const FixText;
extern const char * const FixTimeInForce;
extern const char * const FixTransactTime;
extern const char * const FixStopPx;
extern const char * const FixOrdRejReason;
extern const char * const FixExecType;
extern const char * const FixLeavesQty;
extern const char * const FixSecurityType;
extern const char * const FixPriceType;
extern const char * const FixProduct;
extern const char * const FixQtyType;
extern const char * const FixNoLegs;
extern const char * const FixLegPositionEffect;
extern const char * const FixLegPrice;
extern const char * const FixLegSymbol;
extern const char * const FixLegSide;
extern const char * const FixLegLastPx;
extern const char * const FixLegRefID;
extern const char * const FixNoLegStipulations;
extern const char * const FixLegQty;
extern const char * const FixLegStipulationType;
extern const char * const FixLegStipulationValue;
extern const char * const FixNestedPartyID;
extern const char * const FixNestedPartyIDSource;
extern const char * const FixNestedPartyRole;
extern const char * const FixNoNestedPartyIDs;
extern const char * const FixNestedPartySubID;
extern const char * const FixNoNestedPartySubIDs;
extern const char * const FixNestedPartySubIDType;


// -------------------------------------- typedefs and enums ----------------------------------------


typedef Field< FixAccount, 1, STRING > FieldAccount;
typedef Field< FixAvgPx, 6, PRICE > FieldAvgPx;
typedef Field< FixBeginString, 8, STRING > FieldBeginString;
typedef Field< FixBodyLength, 9, LENGTH > FieldBodyLength;
typedef Field< FixCheckSum, 10, STRING > FieldCheckSum;
typedef Field< FixClOrdID, 11, STRING > FieldClOrdID;
typedef Field< FixCumQty, 14, QTY > FieldCumQty;
typedef Field< FixCurrency, 15, CURRENCY > FieldCurrency;
typedef Field< FixExecID, 17, STRING > FieldExecID;
typedef Field< FixExecInst, 18, MULTIPLEVALUESTRING > FieldExecInst;
typedef Field< FixLastPx, 31, PRICE > FieldLastPx;
typedef Field< FixLastQty, 32, QTY > FieldLastQty;
typedef Field< FixMsgSeqNum, 34, SEQNUM > FieldMsgSeqNum;
typedef Field< FixMsgType, 35, STRING > FieldMsgType;
typedef Field< FixOrderID, 37, STRING > FieldOrderID;
typedef Field< FixOrderQty, 38, QTY > FieldOrderQty;
typedef Field< FixOrdStatus, 39, CHAR > FieldOrdStatus;
typedef Field< FixOrdType, 40, CHAR > FieldOrdType;
typedef Field< FixOrigClOrdID, 41, STRING > FieldOrigClOrdID;
typedef Field< FixPrice, 44, PRICE > FieldPrice;
typedef Field< FixSecurityID, 48, STRING > FieldSecurityID;
typedef Field< FixSenderCompID, 49, STRING > FieldSenderCompID;
typedef Field< FixSendingTime, 52, UTCTIMESTAMP > FieldSendingTime;
typedef Field< FixSide, 54, CHAR > FieldSide;
typedef Field< FixSymbol, 55, STRING > FieldSymbol;
typedef Field< FixTargetCompID, 56, STRING > FieldTargetCompID;
typedef Field< FixText, 58, STRING > FieldText;
typedef Field< FixTimeInForce, 59, CHAR > FieldTimeInForce;
typedef Field< FixTransactTime, 60, UTCTIMESTAMP > FieldTransactTime;
typedef Field< FixStopPx, 99, PRICE > FieldStopPx;
typedef Field< FixOrdRejReason, 103, INT > FieldOrdRejReason;
typedef Field< FixExecType, 150, CHAR > FieldExecType;
typedef Field< FixLeavesQty, 151, QTY > FieldLeavesQty;
typedef Field< FixSecurityType, 167, STRING > FieldSecurityType;
typedef Field< FixPriceType, 423, INT > FieldPriceType;
typedef Field< FixProduct, 460, INT > FieldProduct;
typedef Field< FixQtyType, 854, INT > FieldQtyType;
typedef Field< FixNoLegs, 555, NUMINGROUP > FieldNoLegs;
typedef Field< FixLegPositionEffect, 564, CHAR > FieldLegPositionEffect;
typedef Field< FixLegPrice, 566, PRICE > FieldLegPrice;
typedef Field< FixLegSymbol, 600, STRING > FieldLegSymbol;
typedef Field< FixLegSide, 624, CHAR > FieldLegSide;
typedef Field< FixLegLastPx, 637, PRICE > FieldLegLastPx;
typedef Field< FixLegRefID, 654, STRING > FieldLegRefID;
typedef Field< FixNoLegStipulations, 683, NUMINGROUP > FieldNoLegStipulations;
typedef Field< FixLegQty, 687, QTY > FieldLegQty;
typedef Field< FixLegStipulationType, 688, STRING > FieldLegStipulationType;
typedef Field< FixLegStipulationValue, 689, STRING > FieldLegStipulationValue;
typedef Field< FixNestedPartyID, 524, STRING > FieldNestedPartyID;
typedef Field< FixNestedPartyIDSource, 525, CHAR > FieldNestedPartyIDSource;
typedef Field< FixNestedPartyRole, 538, INT > FieldNestedPartyRole;
typedef Field< FixNoNestedPartyIDs, 539, NUMINGROUP > FieldNoNestedPartyIDs;
typedef Field< FixNestedPartySubID, 545, STRING > FieldNestedPartySubID;
typedef Field< FixNoNestedPartySubIDs, 804, NUMINGROUP > FieldNoNestedPartySubIDs;
typedef Field< FixNestedPartySubIDType, 805, INT > FieldNestedPartySubIDType;


struct QtyTypeEnums final: FieldEnumsBase {
   typedef FieldQtyType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const QtyTypeEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType UNITS;
   static const ItemType CONTRACTS;
};

struct ProductEnums final: FieldEnumsBase {
   typedef FieldProduct::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const ProductEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType AGENCY;
   static const ItemType COMMODITY;
   static const ItemType CORPORATE;
   static const ItemType CURRENCY;
   static const ItemType EQUITY;
   static const ItemType GOVERNMENT;
   static const ItemType INDEX;
   static const ItemType LOAN;
   static const ItemType MONEYMARKET;
   static const ItemType MORTGAGE;
   static const ItemType MUNICIPAL;
   static const ItemType OTHER;
   static const ItemType FINANCING;
};

struct MsgTypeEnums final: FieldEnumsBase {
   typedef FieldMsgType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const MsgTypeEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType EXECUTION_REPORT;
   static const ItemType ORDER_SINGLE;
};

struct OrdStatusEnums final: FieldEnumsBase {
   typedef FieldOrdStatus::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const OrdStatusEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType NEW;
   static const ItemType PARTIALLY_FILLED;
   static const ItemType FILLED;
   static const ItemType DONE_FOR_DAY;
   static const ItemType CANCELED;
   static const ItemType PENDING_CANCEL;
   static const ItemType STOPPED;
   static const ItemType REJECTED;
   static const ItemType SUSPENDED;
   static const ItemType PENDING_NEW;
   static const ItemType CALCULATED;
   static const ItemType EXPIRED;
   static const ItemType ACCEPTED_FOR_BIDDING;
   static const ItemType PENDING_REPLACE;
};

struct OrdTypeEnums final: FieldEnumsBase {
   typedef FieldOrdType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const OrdTypeEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType MARKET;
   static const ItemType LIMIT;
   static const ItemType STOP;
   static const ItemType STOP_LIMIT;
   static const ItemType WITH_OR_WITHOUT;
   static const ItemType LIMIT_OR_BETTER;
   static const ItemType LIMIT_WITH_OR_WITHOUT;
   static const ItemType ON_BASIS;
   static const ItemType PREVIOUSLY_QUOTED;
   static const ItemType PREVIOUSLY_INDICATED;
   static const ItemType FOREX;
   static const ItemType FUNARI;
   static const ItemType MARKET_IF_TOUCHED;
   static const ItemType MARKET_WITH_LEFTOVER_AS_LIMIT;
   static const ItemType PREVIOUS_FUND_VALUATION_POINT;
   static const ItemType NEXT_FUND_VALUATION_POINT;
   static const ItemType PEGGED;
};


struct SideEnums final: FieldEnumsBase {
   typedef FieldSide::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const SideEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType BUY;
   static const ItemType SELL;
};

struct TimeInForceEnums final: FieldEnumsBase {
   typedef FieldTimeInForce::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const TimeInForceEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType DAY;
   static const ItemType GOOD_TILL_CANCEL;
   static const ItemType AT_THE_OPENING;
   static const ItemType IMMEDIATE_OR_CANCEL;
   static const ItemType FILL_OR_KILL;
   static const ItemType GOOD_TILL_CROSSING;
   static const ItemType GOOD_TILL_DATE;
   static const ItemType AT_THE_CLOSE;
};

struct PriceTypeEnums final: FieldEnumsBase {
   typedef FieldPriceType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const PriceTypeEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType PERCENTAGE;
   static const ItemType PER_UNIT;
   static const ItemType FIXED_AMOUNT;
   static const ItemType DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR;
   static const ItemType PREMIUM_PERCENTAGE_POINTS_OVER_PAR;
   static const ItemType SPREAD;
   static const ItemType TED_PRICE;
   static const ItemType TED_YIELD;
   static const ItemType YIELD;
   static const ItemType FIXED_CABINET_TRADE_PRICE;
   static const ItemType VARIABLE_CABINET_TRADE_PRICE;
};

struct SecurityTypeEnums final: FieldEnumsBase {
   typedef FieldSecurityType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const SecurityTypeEnums instance;
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase * const * const getEnums() const override;
   static const ItemType FUTURE;
   static const ItemType OPTION;
   static const ItemType EURO_SUPRANATIONAL_COUPONS;
   static const ItemType FEDERAL_AGENCY_COUPON;
   static const ItemType FEDERAL_AGENCY_DISCOUNT_NOTE;
   static const ItemType PRIVATE_EXPORT_FUNDING;
   static const ItemType USD_SUPRANATIONAL_COUPONS;
   static const ItemType CORPORATE_BOND;
   static const ItemType CORPORATE_PRIVATE_PLACEMENT;
   static const ItemType CONVERTIBLE_BOND;
   static const ItemType DUAL_CURRENCY;
   static const ItemType EURO_CORPORATE_BOND;
   static const ItemType INDEXED_LINKED;
   static const ItemType STRUCTURED_NOTES;
   static const ItemType YANKEE_CORPORATE_BOND;
   static const ItemType FOREIGN_EXCHANGE_CONTRACT;
   static const ItemType COMMON_STOCK;
   static const ItemType PREFERRED_STOCK;
   static const ItemType BRADY_BOND;
   static const ItemType EURO_SOVEREIGNS;
   static const ItemType US_TREASURY_BOND;
   static const ItemType INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE;
   static const ItemType TREASURY_INFLATION_PROTECTED_SECURITIES;
   static const ItemType PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE;
   static const ItemType PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE;
   static const ItemType US_TREASURY_NOTE_UST;
   static const ItemType US_TREASURY_BILL_USTB;
   static const ItemType US_TREASURY_NOTE_TNOTE;
   static const ItemType US_TREASURY_BILL_TBILL;
   static const ItemType REPURCHASE;
   static const ItemType FORWARD;
   static const ItemType BUY_SELLBACK;
   static const ItemType SECURITIES_LOAN;
   static const ItemType SECURITIES_PLEDGE;
   static const ItemType TERM_LOAN;
   static const ItemType REVOLVER_LOAN;
   static const ItemType REVOLVER_TERM_LOAN;
   static const ItemType BRIDGE_LOAN;
   static const ItemType LETTER_OF_CREDIT;
   static const ItemType SWING_LINE_FACILITY;
   static const ItemType DEBTOR_IN_POSSESSION;
   static const ItemType DEFAULTED;
   static const ItemType WITHDRAWN;
   static const ItemType REPLACED;
   static const ItemType MATURED;
   static const ItemType AMENDED_RESTATED;
   static const ItemType RETIRED;
   static const ItemType BANKERS_ACCEPTANCE;
   static const ItemType BANK_NOTES;
   static const ItemType BILL_OF_EXCHANGES;
   static const ItemType CERTIFICATE_OF_DEPOSIT;
   static const ItemType CALL_LOANS;
   static const ItemType COMMERCIAL_PAPER;
   static const ItemType DEPOSIT_NOTES;
   static const ItemType EURO_CERTIFICATE_OF_DEPOSIT;
   static const ItemType EURO_COMMERCIAL_PAPER;
   static const ItemType LIQUIDITY_NOTE;
   static const ItemType MEDIUM_TERM_NOTES;
   static const ItemType OVERNIGHT;
   static const ItemType PROMISSORY_NOTE;
   static const ItemType PLAZOS_FIJOS;
   static const ItemType SHORT_TERM_LOAN_NOTE;
   static const ItemType TIME_DEPOSIT;
   static const ItemType EXTENDED_COMM_NOTE;
   static const ItemType YANKEE_CERTIFICATE_OF_DEPOSIT;
   static const ItemType ASSET_BACKED_SECURITIES;
   static const ItemType CORP_MORTGAGE_BACKED_SECURITIES;
   static const ItemType COLLATERALIZED_MORTGAGE_OBLIGATION;
   static const ItemType IOETTE_MORTGAGE;
   static const ItemType MORTGAGE_BACKED_SECURITIES;
   static const ItemType MORTGAGE_INTEREST_ONLY;
   static const ItemType MORTGAGE_PRINCIPAL_ONLY;
   static const ItemType MORTGAGE_PRIVATE_PLACEMENT;
   static const ItemType MISCELLANEOUS_PASS_THROUGH;
   static const ItemType PFANDBRIEFE;
   static const ItemType TO_BE_ANNOUNCED;
   static const ItemType OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC;
   static const ItemType CERTIFICATE_OF_OBLIGATION;
   static const ItemType CERTIFICATE_OF_PARTICIPATION;
   static const ItemType GENERAL_OBLIGATION_BONDS;
   static const ItemType MANDATORY_TENDER;
   static const ItemType REVENUE_ANTICIPATION_NOTE;
   static const ItemType REVENUE_BONDS;
   static const ItemType SPECIAL_ASSESSMENT;
   static const ItemType SPECIAL_OBLIGATION;
   static const ItemType SPECIAL_TAX;
   static const ItemType TAX_ANTICIPATION_NOTE;
   static const ItemType TAX_ALLOCATION;
   static const ItemType TAX_EXEMPT_COMMERCIAL_PAPER;
   static const ItemType TAX_REVENUE_ANTICIPATION_NOTE;
   static const ItemType VARIABLE_RATE_DEMAND_NOTE;
   static const ItemType WARRANT;
   static const ItemType MUTUAL_FUND;
   static const ItemType MULTI_LEG_INSTRUMENT;
   static const ItemType NO_SECURITY_TYPE;
};


// -------------------------------------- convenience field namespace ----------------------------------------
namespace field
{


typedef FieldAccount Account;
typedef FieldAvgPx AvgPx;
typedef FieldBeginString BeginString;
typedef FieldBodyLength BodyLength;
typedef FieldCheckSum CheckSum;
typedef FieldClOrdID ClOrdID;
typedef FieldCumQty CumQty;
typedef FieldCurrency Currency;
typedef FieldExecID ExecID;
typedef FieldExecInst ExecInst;
typedef FieldLastPx LastPx;
typedef FieldLastQty LastQty;
typedef FieldMsgSeqNum MsgSeqNum;
typedef FieldMsgType MsgType;
typedef FieldOrderID OrderID;
typedef FieldOrderQty OrderQty;
typedef FieldOrdStatus OrdStatus;
typedef FieldOrdType OrdType;
typedef FieldOrigClOrdID OrigClOrdID;
typedef FieldPrice Price;
typedef FieldSecurityID SecurityID;
typedef FieldSenderCompID SenderCompID;
typedef FieldSendingTime SendingTime;
typedef FieldSide Side;
typedef FieldSymbol Symbol;
typedef FieldTargetCompID TargetCompID;
typedef FieldText Text;
typedef FieldTimeInForce TimeInForce;
typedef FieldTransactTime TransactTime;
typedef FieldStopPx StopPx;
typedef FieldOrdRejReason OrdRejReason;
typedef FieldExecType ExecType;
typedef FieldLeavesQty LeavesQty;
typedef FieldSecurityType SecurityType;
typedef FieldPriceType PriceType;
typedef FieldProduct Product;
typedef FieldQtyType QtyType;
typedef FieldNoLegs NoLegs;
typedef FieldLegPositionEffect LegPositionEffect;
typedef FieldLegPrice LegPrice;
typedef FieldLegSymbol LegSymbol;
typedef FieldLegSide LegSide;
typedef FieldLegLastPx LegLastPx;
typedef FieldLegRefID LegRefID;
typedef FieldNoLegStipulations NoLegStipulations;
typedef FieldLegQty LegQty;
typedef FieldLegStipulationType LegStipulationType;
typedef FieldLegStipulationValue LegStipulationValue;
typedef FieldNestedPartyID NestedPartyID;
typedef FieldNestedPartyIDSource NestedPartyIDSource;
typedef FieldNestedPartyRole NestedPartyRole;
typedef FieldNoNestedPartyIDs NoNestedPartyIDs;
typedef FieldNestedPartySubID NestedPartySubID;
typedef FieldNoNestedPartySubIDs NoNestedPartySubIDs;
typedef FieldNestedPartySubIDType NestedPartySubIDType;


}

constexpr raw_enum_t MsgTypeRaw__ = (raw_enum_t)0; // Header
constexpr raw_enum_t MsgTypeRaw_EXECUTION_REPORT = (raw_enum_t)'8';
constexpr raw_enum_t MsgTypeRaw_ORDER_SINGLE = (raw_enum_t)'D';
// end of Fields.hxx

void checkEnums();

}  // namespace order


// Uncomment this to debug parser
// #define FIXPP_DEBUG_PARSER

#ifdef FIXPP_DEBUG_PARSER
#define FIXPP_PRINT_FIELD(NAME) std::cout << Field##NAME::tagName() << "(" << Field##NAME::tagKey() << ") = " << sohstr( fix+pos ) << std::endl;
#define FIXPP_PRINT_UNKNOWN_FIELD std::cout << "- unknown " << tag << " in " << getMessageName() << ":" << pos << " " << sohstr( fix+prev ) << std::endl;
#else
#define FIXPP_PRINT_FIELD(NAME)
#define FIXPP_PRINT_UNKNOWN_FIELD
#endif


#endif // order_FIELDS_H
