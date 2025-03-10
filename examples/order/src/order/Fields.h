// Generated by https://github.com/sashamakarenko/fixpp
// Copyright (c) 2021 sashamakarenko
// https://github.com/sashamakarenko/fixpp/blob/main/LICENSE
#pragma once
#ifndef order_FIELDS_H
#define order_FIELDS_H

#include <order/FixApi.h>

#include <iostream>
#include <map>

namespace order
{

struct FieldDepth
{
    int16_t depth          = -1;
    int16_t isFirstInGroup = false;

    const FieldDepth & inc()
    {
        ++depth;
        return *this;
    }
};

typedef FieldDepth (*GetDepthMethod)( raw_tag_t );

extern const std::map< raw_tag_t  , const char * const >           & RAW_TAG_TO_NAME;
extern const std::map< tag_t      , const char * const >           & TAG_TO_NAME;
extern const std::map< raw_tag_t  , const FieldEnumsBase * const > & RAW_TO_ENUM;
extern const std::map< tag_t      , const FieldEnumsBase * const > & TAG_TO_ENUM;
extern const std::map< std::string, tag_t >                        & FIELD_NAME_TO_TAG;
extern const std::map< tag_t      , FieldType >                    & TAG_TO_FIELD_TYPE;
extern const std::map< tag_t      , const std::string >            & TAG_TO_FIELD_TYPE_NAME;

tag_t getFieldTag( const std::string & fieldName );

const char * getFieldName( tag_t tagValue );

FieldType getFieldType( tag_t tagValue );

const std::string & getFieldTypeName( tag_t tagValue );

bool isHeaderField( tag_t tagValue );

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
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType UNITS;
   static constexpr ValueType ITEM_UNITS = 0;
   static const ItemType CONTRACTS;
   static constexpr ValueType ITEM_CONTRACTS = 1;
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct ProductEnums final: FieldEnumsBase {
   typedef FieldProduct::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const ProductEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType AGENCY;
   static constexpr ValueType ITEM_AGENCY = 1;
   static const ItemType COMMODITY;
   static constexpr ValueType ITEM_COMMODITY = 2;
   static const ItemType CORPORATE;
   static constexpr ValueType ITEM_CORPORATE = 3;
   static const ItemType CURRENCY;
   static constexpr ValueType ITEM_CURRENCY = 4;
   static const ItemType EQUITY;
   static constexpr ValueType ITEM_EQUITY = 5;
   static const ItemType GOVERNMENT;
   static constexpr ValueType ITEM_GOVERNMENT = 6;
   static const ItemType INDEX;
   static constexpr ValueType ITEM_INDEX = 7;
   static const ItemType LOAN;
   static constexpr ValueType ITEM_LOAN = 8;
   static const ItemType MONEYMARKET;
   static constexpr ValueType ITEM_MONEYMARKET = 9;
   static const ItemType MORTGAGE;
   static constexpr ValueType ITEM_MORTGAGE = 10;
   static const ItemType MUNICIPAL;
   static constexpr ValueType ITEM_MUNICIPAL = 11;
   static const ItemType OTHER;
   static constexpr ValueType ITEM_OTHER = 12;
   static const ItemType FINANCING;
   static constexpr ValueType ITEM_FINANCING = 13;
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct MsgTypeEnums final: FieldEnumsBase {
   typedef FieldMsgType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const MsgTypeEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType EXECUTION_REPORT;
   static constexpr ValueType ITEM_EXECUTION_REPORT = SOHSTR(8);
   static const ItemType NEW_ORDER_SINGLE;
   static constexpr ValueType ITEM_NEW_ORDER_SINGLE = SOHSTR(D);
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct OrdStatusEnums final: FieldEnumsBase {
   typedef FieldOrdStatus::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const OrdStatusEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType NEW;
   static constexpr ValueType ITEM_NEW = '0';
   static const ItemType PARTIALLY_FILLED;
   static constexpr ValueType ITEM_PARTIALLY_FILLED = '1';
   static const ItemType FILLED;
   static constexpr ValueType ITEM_FILLED = '2';
   static const ItemType DONE_FOR_DAY;
   static constexpr ValueType ITEM_DONE_FOR_DAY = '3';
   static const ItemType CANCELED;
   static constexpr ValueType ITEM_CANCELED = '4';
   static const ItemType PENDING_CANCEL;
   static constexpr ValueType ITEM_PENDING_CANCEL = '6';
   static const ItemType STOPPED;
   static constexpr ValueType ITEM_STOPPED = '7';
   static const ItemType REJECTED;
   static constexpr ValueType ITEM_REJECTED = '8';
   static const ItemType SUSPENDED;
   static constexpr ValueType ITEM_SUSPENDED = '9';
   static const ItemType PENDING_NEW;
   static constexpr ValueType ITEM_PENDING_NEW = 'A';
   static const ItemType CALCULATED;
   static constexpr ValueType ITEM_CALCULATED = 'B';
   static const ItemType EXPIRED;
   static constexpr ValueType ITEM_EXPIRED = 'C';
   static const ItemType ACCEPTED_FOR_BIDDING;
   static constexpr ValueType ITEM_ACCEPTED_FOR_BIDDING = 'D';
   static const ItemType PENDING_REPLACE;
   static constexpr ValueType ITEM_PENDING_REPLACE = 'E';
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct OrdTypeEnums final: FieldEnumsBase {
   typedef FieldOrdType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const OrdTypeEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType MARKET;
   static constexpr ValueType ITEM_MARKET = '1';
   static const ItemType LIMIT;
   static constexpr ValueType ITEM_LIMIT = '2';
   static const ItemType STOP;
   static constexpr ValueType ITEM_STOP = '3';
   static const ItemType STOP_LIMIT;
   static constexpr ValueType ITEM_STOP_LIMIT = '4';
   static const ItemType WITH_OR_WITHOUT;
   static constexpr ValueType ITEM_WITH_OR_WITHOUT = '6';
   static const ItemType LIMIT_OR_BETTER;
   static constexpr ValueType ITEM_LIMIT_OR_BETTER = '7';
   static const ItemType LIMIT_WITH_OR_WITHOUT;
   static constexpr ValueType ITEM_LIMIT_WITH_OR_WITHOUT = '8';
   static const ItemType ON_BASIS;
   static constexpr ValueType ITEM_ON_BASIS = '9';
   static const ItemType PREVIOUSLY_QUOTED;
   static constexpr ValueType ITEM_PREVIOUSLY_QUOTED = 'D';
   static const ItemType PREVIOUSLY_INDICATED;
   static constexpr ValueType ITEM_PREVIOUSLY_INDICATED = 'E';
   static const ItemType FOREX;
   static constexpr ValueType ITEM_FOREX = 'G';
   static const ItemType FUNARI;
   static constexpr ValueType ITEM_FUNARI = 'I';
   static const ItemType MARKET_IF_TOUCHED;
   static constexpr ValueType ITEM_MARKET_IF_TOUCHED = 'J';
   static const ItemType MARKET_WITH_LEFTOVER_AS_LIMIT;
   static constexpr ValueType ITEM_MARKET_WITH_LEFTOVER_AS_LIMIT = 'K';
   static const ItemType PREVIOUS_FUND_VALUATION_POINT;
   static constexpr ValueType ITEM_PREVIOUS_FUND_VALUATION_POINT = 'L';
   static const ItemType NEXT_FUND_VALUATION_POINT;
   static constexpr ValueType ITEM_NEXT_FUND_VALUATION_POINT = 'M';
   static const ItemType PEGGED;
   static constexpr ValueType ITEM_PEGGED = 'P';
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct SideEnums final: FieldEnumsBase {
   typedef FieldSide::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const SideEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType BUY;
   static constexpr ValueType ITEM_BUY = '1';
   static const ItemType SELL;
   static constexpr ValueType ITEM_SELL = '2';
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct TimeInForceEnums final: FieldEnumsBase {
   typedef FieldTimeInForce::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const TimeInForceEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType DAY;
   static constexpr ValueType ITEM_DAY = '0';
   static const ItemType GOOD_TILL_CANCEL;
   static constexpr ValueType ITEM_GOOD_TILL_CANCEL = '1';
   static const ItemType AT_THE_OPENING;
   static constexpr ValueType ITEM_AT_THE_OPENING = '2';
   static const ItemType IMMEDIATE_OR_CANCEL;
   static constexpr ValueType ITEM_IMMEDIATE_OR_CANCEL = '3';
   static const ItemType FILL_OR_KILL;
   static constexpr ValueType ITEM_FILL_OR_KILL = '4';
   static const ItemType GOOD_TILL_CROSSING;
   static constexpr ValueType ITEM_GOOD_TILL_CROSSING = '5';
   static const ItemType GOOD_TILL_DATE;
   static constexpr ValueType ITEM_GOOD_TILL_DATE = '6';
   static const ItemType AT_THE_CLOSE;
   static constexpr ValueType ITEM_AT_THE_CLOSE = '7';
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct PriceTypeEnums final: FieldEnumsBase {
   typedef FieldPriceType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const PriceTypeEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType PERCENTAGE;
   static constexpr ValueType ITEM_PERCENTAGE = 1;
   static const ItemType PER_UNIT;
   static constexpr ValueType ITEM_PER_UNIT = 2;
   static const ItemType FIXED_AMOUNT;
   static constexpr ValueType ITEM_FIXED_AMOUNT = 3;
   static const ItemType DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR;
   static constexpr ValueType ITEM_DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR = 4;
   static const ItemType PREMIUM_PERCENTAGE_POINTS_OVER_PAR;
   static constexpr ValueType ITEM_PREMIUM_PERCENTAGE_POINTS_OVER_PAR = 5;
   static const ItemType SPREAD;
   static constexpr ValueType ITEM_SPREAD = 6;
   static const ItemType TED_PRICE;
   static constexpr ValueType ITEM_TED_PRICE = 7;
   static const ItemType TED_YIELD;
   static constexpr ValueType ITEM_TED_YIELD = 8;
   static const ItemType YIELD;
   static constexpr ValueType ITEM_YIELD = 9;
   static const ItemType FIXED_CABINET_TRADE_PRICE;
   static constexpr ValueType ITEM_FIXED_CABINET_TRADE_PRICE = 10;
   static const ItemType VARIABLE_CABINET_TRADE_PRICE;
   static constexpr ValueType ITEM_VARIABLE_CABINET_TRADE_PRICE = 11;
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
};

struct SecurityTypeEnums final: FieldEnumsBase {
   typedef FieldSecurityType::ValueType ValueType;
   typedef FieldEnum< ValueType > ItemType;
   static const FieldEnumBase * items[];
   static const FieldEnumMap itemByRaw;
   static const SecurityTypeEnums instance;
   static const FieldEnumBase * findEnum( raw_enum_t raw );
   static const ValueType * findEnumValue( raw_enum_t raw );
   virtual const char * getFieldName() const override;
   virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;
   virtual const FieldEnumMap & getEnumMapByRaw() const override;
   virtual const FieldEnumBase ** getEnums() const override;
   static const ItemType FUTURE;
   static constexpr ValueType ITEM_FUTURE = SOHSTR(FUT);
   static const ItemType OPTION;
   static constexpr ValueType ITEM_OPTION = SOHSTR(OPT);
   static const ItemType EURO_SUPRANATIONAL_COUPONS;
   static constexpr ValueType ITEM_EURO_SUPRANATIONAL_COUPONS = SOHSTR(EUSUPRA);
   static const ItemType FEDERAL_AGENCY_COUPON;
   static constexpr ValueType ITEM_FEDERAL_AGENCY_COUPON = SOHSTR(FAC);
   static const ItemType FEDERAL_AGENCY_DISCOUNT_NOTE;
   static constexpr ValueType ITEM_FEDERAL_AGENCY_DISCOUNT_NOTE = SOHSTR(FADN);
   static const ItemType PRIVATE_EXPORT_FUNDING;
   static constexpr ValueType ITEM_PRIVATE_EXPORT_FUNDING = SOHSTR(PEF);
   static const ItemType USD_SUPRANATIONAL_COUPONS;
   static constexpr ValueType ITEM_USD_SUPRANATIONAL_COUPONS = SOHSTR(SUPRA);
   static const ItemType CORPORATE_BOND;
   static constexpr ValueType ITEM_CORPORATE_BOND = SOHSTR(CORP);
   static const ItemType CORPORATE_PRIVATE_PLACEMENT;
   static constexpr ValueType ITEM_CORPORATE_PRIVATE_PLACEMENT = SOHSTR(CPP);
   static const ItemType CONVERTIBLE_BOND;
   static constexpr ValueType ITEM_CONVERTIBLE_BOND = SOHSTR(CB);
   static const ItemType DUAL_CURRENCY;
   static constexpr ValueType ITEM_DUAL_CURRENCY = SOHSTR(DUAL);
   static const ItemType EURO_CORPORATE_BOND;
   static constexpr ValueType ITEM_EURO_CORPORATE_BOND = SOHSTR(EUCORP);
   static const ItemType INDEXED_LINKED;
   static constexpr ValueType ITEM_INDEXED_LINKED = SOHSTR(XLINKD);
   static const ItemType STRUCTURED_NOTES;
   static constexpr ValueType ITEM_STRUCTURED_NOTES = SOHSTR(STRUCT);
   static const ItemType YANKEE_CORPORATE_BOND;
   static constexpr ValueType ITEM_YANKEE_CORPORATE_BOND = SOHSTR(YANK);
   static const ItemType FOREIGN_EXCHANGE_CONTRACT;
   static constexpr ValueType ITEM_FOREIGN_EXCHANGE_CONTRACT = SOHSTR(FOR);
   static const ItemType COMMON_STOCK;
   static constexpr ValueType ITEM_COMMON_STOCK = SOHSTR(CS);
   static const ItemType PREFERRED_STOCK;
   static constexpr ValueType ITEM_PREFERRED_STOCK = SOHSTR(PS);
   static const ItemType BRADY_BOND;
   static constexpr ValueType ITEM_BRADY_BOND = SOHSTR(BRADY);
   static const ItemType EURO_SOVEREIGNS;
   static constexpr ValueType ITEM_EURO_SOVEREIGNS = SOHSTR(EUSOV);
   static const ItemType US_TREASURY_BOND;
   static constexpr ValueType ITEM_US_TREASURY_BOND = SOHSTR(TBOND);
   static const ItemType INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE;
   static constexpr ValueType ITEM_INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE = SOHSTR(TINT);
   static const ItemType TREASURY_INFLATION_PROTECTED_SECURITIES;
   static constexpr ValueType ITEM_TREASURY_INFLATION_PROTECTED_SECURITIES = SOHSTR(TIPS);
   static const ItemType PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE;
   static constexpr ValueType ITEM_PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE = SOHSTR(TCAL);
   static const ItemType PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE;
   static constexpr ValueType ITEM_PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE = SOHSTR(TPRN);
   static const ItemType US_TREASURY_NOTE_UST;
   static constexpr ValueType ITEM_US_TREASURY_NOTE_UST = SOHSTR(UST);
   static const ItemType US_TREASURY_BILL_USTB;
   static constexpr ValueType ITEM_US_TREASURY_BILL_USTB = SOHSTR(USTB);
   static const ItemType US_TREASURY_NOTE_TNOTE;
   static constexpr ValueType ITEM_US_TREASURY_NOTE_TNOTE = SOHSTR(TNOTE);
   static const ItemType US_TREASURY_BILL_TBILL;
   static constexpr ValueType ITEM_US_TREASURY_BILL_TBILL = SOHSTR(TBILL);
   static const ItemType REPURCHASE;
   static constexpr ValueType ITEM_REPURCHASE = SOHSTR(REPO);
   static const ItemType FORWARD;
   static constexpr ValueType ITEM_FORWARD = SOHSTR(FORWARD);
   static const ItemType BUY_SELLBACK;
   static constexpr ValueType ITEM_BUY_SELLBACK = SOHSTR(BUYSELL);
   static const ItemType SECURITIES_LOAN;
   static constexpr ValueType ITEM_SECURITIES_LOAN = SOHSTR(SECLOAN);
   static const ItemType SECURITIES_PLEDGE;
   static constexpr ValueType ITEM_SECURITIES_PLEDGE = SOHSTR(SECPLEDGE);
   static const ItemType TERM_LOAN;
   static constexpr ValueType ITEM_TERM_LOAN = SOHSTR(TERM);
   static const ItemType REVOLVER_LOAN;
   static constexpr ValueType ITEM_REVOLVER_LOAN = SOHSTR(RVLV);
   static const ItemType REVOLVER_TERM_LOAN;
   static constexpr ValueType ITEM_REVOLVER_TERM_LOAN = SOHSTR(RVLVTRM);
   static const ItemType BRIDGE_LOAN;
   static constexpr ValueType ITEM_BRIDGE_LOAN = SOHSTR(BRIDGE);
   static const ItemType LETTER_OF_CREDIT;
   static constexpr ValueType ITEM_LETTER_OF_CREDIT = SOHSTR(LOFC);
   static const ItemType SWING_LINE_FACILITY;
   static constexpr ValueType ITEM_SWING_LINE_FACILITY = SOHSTR(SWING);
   static const ItemType DEBTOR_IN_POSSESSION;
   static constexpr ValueType ITEM_DEBTOR_IN_POSSESSION = SOHSTR(DINP);
   static const ItemType DEFAULTED;
   static constexpr ValueType ITEM_DEFAULTED = SOHSTR(DEFLTED);
   static const ItemType WITHDRAWN;
   static constexpr ValueType ITEM_WITHDRAWN = SOHSTR(WITHDRN);
   static const ItemType REPLACED;
   static constexpr ValueType ITEM_REPLACED = SOHSTR(REPLACD);
   static const ItemType MATURED;
   static constexpr ValueType ITEM_MATURED = SOHSTR(MATURED);
   static const ItemType AMENDED_RESTATED;
   static constexpr ValueType ITEM_AMENDED_RESTATED = SOHSTR(AMENDED);
   static const ItemType RETIRED;
   static constexpr ValueType ITEM_RETIRED = SOHSTR(RETIRED);
   static const ItemType BANKERS_ACCEPTANCE;
   static constexpr ValueType ITEM_BANKERS_ACCEPTANCE = SOHSTR(BA);
   static const ItemType BANK_NOTES;
   static constexpr ValueType ITEM_BANK_NOTES = SOHSTR(BN);
   static const ItemType BILL_OF_EXCHANGES;
   static constexpr ValueType ITEM_BILL_OF_EXCHANGES = SOHSTR(BOX);
   static const ItemType CERTIFICATE_OF_DEPOSIT;
   static constexpr ValueType ITEM_CERTIFICATE_OF_DEPOSIT = SOHSTR(CD);
   static const ItemType CALL_LOANS;
   static constexpr ValueType ITEM_CALL_LOANS = SOHSTR(CL);
   static const ItemType COMMERCIAL_PAPER;
   static constexpr ValueType ITEM_COMMERCIAL_PAPER = SOHSTR(CP);
   static const ItemType DEPOSIT_NOTES;
   static constexpr ValueType ITEM_DEPOSIT_NOTES = SOHSTR(DN);
   static const ItemType EURO_CERTIFICATE_OF_DEPOSIT;
   static constexpr ValueType ITEM_EURO_CERTIFICATE_OF_DEPOSIT = SOHSTR(EUCD);
   static const ItemType EURO_COMMERCIAL_PAPER;
   static constexpr ValueType ITEM_EURO_COMMERCIAL_PAPER = SOHSTR(EUCP);
   static const ItemType LIQUIDITY_NOTE;
   static constexpr ValueType ITEM_LIQUIDITY_NOTE = SOHSTR(LQN);
   static const ItemType MEDIUM_TERM_NOTES;
   static constexpr ValueType ITEM_MEDIUM_TERM_NOTES = SOHSTR(MTN);
   static const ItemType OVERNIGHT;
   static constexpr ValueType ITEM_OVERNIGHT = SOHSTR(ONITE);
   static const ItemType PROMISSORY_NOTE;
   static constexpr ValueType ITEM_PROMISSORY_NOTE = SOHSTR(PN);
   static const ItemType PLAZOS_FIJOS;
   static constexpr ValueType ITEM_PLAZOS_FIJOS = SOHSTR(PZFJ);
   static const ItemType SHORT_TERM_LOAN_NOTE;
   static constexpr ValueType ITEM_SHORT_TERM_LOAN_NOTE = SOHSTR(STN);
   static const ItemType TIME_DEPOSIT;
   static constexpr ValueType ITEM_TIME_DEPOSIT = SOHSTR(TD);
   static const ItemType EXTENDED_COMM_NOTE;
   static constexpr ValueType ITEM_EXTENDED_COMM_NOTE = SOHSTR(XCN);
   static const ItemType YANKEE_CERTIFICATE_OF_DEPOSIT;
   static constexpr ValueType ITEM_YANKEE_CERTIFICATE_OF_DEPOSIT = SOHSTR(YCD);
   static const ItemType ASSET_BACKED_SECURITIES;
   static constexpr ValueType ITEM_ASSET_BACKED_SECURITIES = SOHSTR(ABS);
   static const ItemType CORP_MORTGAGE_BACKED_SECURITIES;
   static constexpr ValueType ITEM_CORP_MORTGAGE_BACKED_SECURITIES = SOHSTR(CMBS);
   static const ItemType COLLATERALIZED_MORTGAGE_OBLIGATION;
   static constexpr ValueType ITEM_COLLATERALIZED_MORTGAGE_OBLIGATION = SOHSTR(CMO);
   static const ItemType IOETTE_MORTGAGE;
   static constexpr ValueType ITEM_IOETTE_MORTGAGE = SOHSTR(IET);
   static const ItemType MORTGAGE_BACKED_SECURITIES;
   static constexpr ValueType ITEM_MORTGAGE_BACKED_SECURITIES = SOHSTR(MBS);
   static const ItemType MORTGAGE_INTEREST_ONLY;
   static constexpr ValueType ITEM_MORTGAGE_INTEREST_ONLY = SOHSTR(MIO);
   static const ItemType MORTGAGE_PRINCIPAL_ONLY;
   static constexpr ValueType ITEM_MORTGAGE_PRINCIPAL_ONLY = SOHSTR(MPO);
   static const ItemType MORTGAGE_PRIVATE_PLACEMENT;
   static constexpr ValueType ITEM_MORTGAGE_PRIVATE_PLACEMENT = SOHSTR(MPP);
   static const ItemType MISCELLANEOUS_PASS_THROUGH;
   static constexpr ValueType ITEM_MISCELLANEOUS_PASS_THROUGH = SOHSTR(MPT);
   static const ItemType PFANDBRIEFE;
   static constexpr ValueType ITEM_PFANDBRIEFE = SOHSTR(PFAND);
   static const ItemType TO_BE_ANNOUNCED;
   static constexpr ValueType ITEM_TO_BE_ANNOUNCED = SOHSTR(TBA);
   static const ItemType OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC;
   static constexpr ValueType ITEM_OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC = SOHSTR(AN);
   static const ItemType CERTIFICATE_OF_OBLIGATION;
   static constexpr ValueType ITEM_CERTIFICATE_OF_OBLIGATION = SOHSTR(COFO);
   static const ItemType CERTIFICATE_OF_PARTICIPATION;
   static constexpr ValueType ITEM_CERTIFICATE_OF_PARTICIPATION = SOHSTR(COFP);
   static const ItemType GENERAL_OBLIGATION_BONDS;
   static constexpr ValueType ITEM_GENERAL_OBLIGATION_BONDS = SOHSTR(GO);
   static const ItemType MANDATORY_TENDER;
   static constexpr ValueType ITEM_MANDATORY_TENDER = SOHSTR(MT);
   static const ItemType REVENUE_ANTICIPATION_NOTE;
   static constexpr ValueType ITEM_REVENUE_ANTICIPATION_NOTE = SOHSTR(RAN);
   static const ItemType REVENUE_BONDS;
   static constexpr ValueType ITEM_REVENUE_BONDS = SOHSTR(REV);
   static const ItemType SPECIAL_ASSESSMENT;
   static constexpr ValueType ITEM_SPECIAL_ASSESSMENT = SOHSTR(SPCLA);
   static const ItemType SPECIAL_OBLIGATION;
   static constexpr ValueType ITEM_SPECIAL_OBLIGATION = SOHSTR(SPCLO);
   static const ItemType SPECIAL_TAX;
   static constexpr ValueType ITEM_SPECIAL_TAX = SOHSTR(SPCLT);
   static const ItemType TAX_ANTICIPATION_NOTE;
   static constexpr ValueType ITEM_TAX_ANTICIPATION_NOTE = SOHSTR(TAN);
   static const ItemType TAX_ALLOCATION;
   static constexpr ValueType ITEM_TAX_ALLOCATION = SOHSTR(TAXA);
   static const ItemType TAX_EXEMPT_COMMERCIAL_PAPER;
   static constexpr ValueType ITEM_TAX_EXEMPT_COMMERCIAL_PAPER = SOHSTR(TECP);
   static const ItemType TAX_REVENUE_ANTICIPATION_NOTE;
   static constexpr ValueType ITEM_TAX_REVENUE_ANTICIPATION_NOTE = SOHSTR(TRAN);
   static const ItemType VARIABLE_RATE_DEMAND_NOTE;
   static constexpr ValueType ITEM_VARIABLE_RATE_DEMAND_NOTE = SOHSTR(VRDN);
   static const ItemType WARRANT;
   static constexpr ValueType ITEM_WARRANT = SOHSTR(WAR);
   static const ItemType MUTUAL_FUND;
   static constexpr ValueType ITEM_MUTUAL_FUND = SOHSTR(MF);
   static const ItemType MULTI_LEG_INSTRUMENT;
   static constexpr ValueType ITEM_MULTI_LEG_INSTRUMENT = SOHSTR(MLEG);
   static const ItemType NO_SECURITY_TYPE;
   static constexpr ValueType ITEM_NO_SECURITY_TYPE = SOHSTR(NONE);
   static const ItemType BAD_ENUM;
   static constexpr ValueType ITEM_BAD_ENUM = BadEnum<ValueType>::value;
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
constexpr raw_enum_t MsgTypeRaw_NEW_ORDER_SINGLE = (raw_enum_t)'D';
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
