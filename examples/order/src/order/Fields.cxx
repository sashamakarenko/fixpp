
// Generated

// -------------------------------------- names ----------------------------------------
const std::string FixBeginStringValue( "FIX.4.4" );

const char * const FixAccount = "Account";
const char * const FixAvgPx = "AvgPx";
const char * const FixBeginString = "BeginString";
const char * const FixBodyLength = "BodyLength";
const char * const FixCheckSum = "CheckSum";
const char * const FixClOrdID = "ClOrdID";
const char * const FixCumQty = "CumQty";
const char * const FixCurrency = "Currency";
const char * const FixExecID = "ExecID";
const char * const FixExecInst = "ExecInst";
const char * const FixLastPx = "LastPx";
const char * const FixLastQty = "LastQty";
const char * const FixMsgSeqNum = "MsgSeqNum";
const char * const FixMsgType = "MsgType";
const char * const FixOrderID = "OrderID";
const char * const FixOrderQty = "OrderQty";
const char * const FixOrdStatus = "OrdStatus";
const char * const FixOrdType = "OrdType";
const char * const FixOrigClOrdID = "OrigClOrdID";
const char * const FixPrice = "Price";
const char * const FixSecurityID = "SecurityID";
const char * const FixSenderCompID = "SenderCompID";
const char * const FixSendingTime = "SendingTime";
const char * const FixSide = "Side";
const char * const FixSymbol = "Symbol";
const char * const FixTargetCompID = "TargetCompID";
const char * const FixText = "Text";
const char * const FixTimeInForce = "TimeInForce";
const char * const FixTransactTime = "TransactTime";
const char * const FixStopPx = "StopPx";
const char * const FixOrdRejReason = "OrdRejReason";
const char * const FixExecType = "ExecType";
const char * const FixLeavesQty = "LeavesQty";
const char * const FixSecurityType = "SecurityType";
const char * const FixPriceType = "PriceType";
const char * const FixProduct = "Product";
const char * const FixQtyType = "QtyType";
const char * const FixNoLegs = "NoLegs";
const char * const FixLegPositionEffect = "LegPositionEffect";
const char * const FixLegPrice = "LegPrice";
const char * const FixLegSymbol = "LegSymbol";
const char * const FixLegSide = "LegSide";
const char * const FixLegLastPx = "LegLastPx";
const char * const FixLegRefID = "LegRefID";
const char * const FixNoLegStipulations = "NoLegStipulations";
const char * const FixLegQty = "LegQty";
const char * const FixLegStipulationType = "LegStipulationType";
const char * const FixLegStipulationValue = "LegStipulationValue";
const char * const FixNestedPartyID = "NestedPartyID";
const char * const FixNestedPartyIDSource = "NestedPartyIDSource";
const char * const FixNestedPartyRole = "NestedPartyRole";
const char * const FixNoNestedPartyIDs = "NoNestedPartyIDs";
const char * const FixNestedPartySubID = "NestedPartySubID";
const char * const FixNoNestedPartySubIDs = "NoNestedPartySubIDs";
const char * const FixNestedPartySubIDType = "NestedPartySubIDType";


const QtyTypeEnums::ItemType QtyTypeEnums::UNITS( "UNITS", 0 );
const QtyTypeEnums::ItemType QtyTypeEnums::CONTRACTS( "CONTRACTS", 1 );


const ProductEnums::ItemType ProductEnums::AGENCY( "AGENCY", 1 );
const ProductEnums::ItemType ProductEnums::COMMODITY( "COMMODITY", 2 );
const ProductEnums::ItemType ProductEnums::CORPORATE( "CORPORATE", 3 );
const ProductEnums::ItemType ProductEnums::CURRENCY( "CURRENCY", 4 );
const ProductEnums::ItemType ProductEnums::EQUITY( "EQUITY", 5 );
const ProductEnums::ItemType ProductEnums::GOVERNMENT( "GOVERNMENT", 6 );
const ProductEnums::ItemType ProductEnums::INDEX( "INDEX", 7 );
const ProductEnums::ItemType ProductEnums::LOAN( "LOAN", 8 );
const ProductEnums::ItemType ProductEnums::MONEYMARKET( "MONEYMARKET", 9 );
const ProductEnums::ItemType ProductEnums::MORTGAGE( "MORTGAGE", 10 );
const ProductEnums::ItemType ProductEnums::MUNICIPAL( "MUNICIPAL", 11 );
const ProductEnums::ItemType ProductEnums::OTHER( "OTHER", 12 );
const ProductEnums::ItemType ProductEnums::FINANCING( "FINANCING", 13 );


const MsgTypeEnums::ItemType MsgTypeEnums::HEARTBEAT( "HEARTBEAT", SOHSTR(0) );
const MsgTypeEnums::ItemType MsgTypeEnums::TEST_REQUEST( "TEST_REQUEST", SOHSTR(1) );
const MsgTypeEnums::ItemType MsgTypeEnums::RESEND_REQUEST( "RESEND_REQUEST", SOHSTR(2) );
const MsgTypeEnums::ItemType MsgTypeEnums::REJECT( "REJECT", SOHSTR(3) );
const MsgTypeEnums::ItemType MsgTypeEnums::SEQUENCE_RESET( "SEQUENCE_RESET", SOHSTR(4) );
const MsgTypeEnums::ItemType MsgTypeEnums::LOGOUT( "LOGOUT", SOHSTR(5) );
const MsgTypeEnums::ItemType MsgTypeEnums::EXECUTION_REPORT( "EXECUTION_REPORT", SOHSTR(8) );
const MsgTypeEnums::ItemType MsgTypeEnums::LOGON( "LOGON", SOHSTR(A) );
const MsgTypeEnums::ItemType MsgTypeEnums::ORDER_SINGLE( "ORDER_SINGLE", SOHSTR(D) );
const MsgTypeEnums::ItemType MsgTypeEnums::MARKET_DATA_REQUEST( "MARKET_DATA_REQUEST", SOHSTR(V) );
const MsgTypeEnums::ItemType MsgTypeEnums::MARKET_DATA_SNAPSHOT_FULL_REFRESH( "MARKET_DATA_SNAPSHOT_FULL_REFRESH", SOHSTR(W) );
const MsgTypeEnums::ItemType MsgTypeEnums::MARKET_DATA_INCREMENTAL_REFRESH( "MARKET_DATA_INCREMENTAL_REFRESH", SOHSTR(X) );
const MsgTypeEnums::ItemType MsgTypeEnums::MARKET_DATA_REQUEST_REJECT( "MARKET_DATA_REQUEST_REJECT", SOHSTR(Y) );
const MsgTypeEnums::ItemType MsgTypeEnums::COLLATERAL_INQUIRY_ACK( "COLLATERAL_INQUIRY_ACK", SOHSTR(BG) );
const MsgTypeEnums::ItemType MsgTypeEnums::CONFIRMATION_REQUEST( "CONFIRMATION_REQUEST", SOHSTR(BH) );
const MsgTypeEnums::ItemType MsgTypeEnums::SECURITY_DEFINITION( "SECURITY_DEFINITION", SOHSTR(d) );


const OrdStatusEnums::ItemType OrdStatusEnums::NEW( "NEW", '0' );
const OrdStatusEnums::ItemType OrdStatusEnums::PARTIALLY_FILLED( "PARTIALLY_FILLED", '1' );
const OrdStatusEnums::ItemType OrdStatusEnums::FILLED( "FILLED", '2' );
const OrdStatusEnums::ItemType OrdStatusEnums::DONE_FOR_DAY( "DONE_FOR_DAY", '3' );
const OrdStatusEnums::ItemType OrdStatusEnums::CANCELED( "CANCELED", '4' );
const OrdStatusEnums::ItemType OrdStatusEnums::PENDING_CANCEL( "PENDING_CANCEL", '6' );
const OrdStatusEnums::ItemType OrdStatusEnums::STOPPED( "STOPPED", '7' );
const OrdStatusEnums::ItemType OrdStatusEnums::REJECTED( "REJECTED", '8' );
const OrdStatusEnums::ItemType OrdStatusEnums::SUSPENDED( "SUSPENDED", '9' );
const OrdStatusEnums::ItemType OrdStatusEnums::PENDING_NEW( "PENDING_NEW", 'A' );
const OrdStatusEnums::ItemType OrdStatusEnums::CALCULATED( "CALCULATED", 'B' );
const OrdStatusEnums::ItemType OrdStatusEnums::EXPIRED( "EXPIRED", 'C' );
const OrdStatusEnums::ItemType OrdStatusEnums::ACCEPTED_FOR_BIDDING( "ACCEPTED_FOR_BIDDING", 'D' );
const OrdStatusEnums::ItemType OrdStatusEnums::PENDING_REPLACE( "PENDING_REPLACE", 'E' );


const OrdTypeEnums::ItemType OrdTypeEnums::MARKET( "MARKET", '1' );
const OrdTypeEnums::ItemType OrdTypeEnums::LIMIT( "LIMIT", '2' );
const OrdTypeEnums::ItemType OrdTypeEnums::STOP( "STOP", '3' );
const OrdTypeEnums::ItemType OrdTypeEnums::STOP_LIMIT( "STOP_LIMIT", '4' );
const OrdTypeEnums::ItemType OrdTypeEnums::WITH_OR_WITHOUT( "WITH_OR_WITHOUT", '6' );
const OrdTypeEnums::ItemType OrdTypeEnums::LIMIT_OR_BETTER( "LIMIT_OR_BETTER", '7' );
const OrdTypeEnums::ItemType OrdTypeEnums::LIMIT_WITH_OR_WITHOUT( "LIMIT_WITH_OR_WITHOUT", '8' );
const OrdTypeEnums::ItemType OrdTypeEnums::ON_BASIS( "ON_BASIS", '9' );
const OrdTypeEnums::ItemType OrdTypeEnums::PREVIOUSLY_QUOTED( "PREVIOUSLY_QUOTED", 'D' );
const OrdTypeEnums::ItemType OrdTypeEnums::PREVIOUSLY_INDICATED( "PREVIOUSLY_INDICATED", 'E' );
const OrdTypeEnums::ItemType OrdTypeEnums::FOREX( "FOREX", 'G' );
const OrdTypeEnums::ItemType OrdTypeEnums::FUNARI( "FUNARI", 'I' );
const OrdTypeEnums::ItemType OrdTypeEnums::MARKET_IF_TOUCHED( "MARKET_IF_TOUCHED", 'J' );
const OrdTypeEnums::ItemType OrdTypeEnums::MARKET_WITH_LEFTOVER_AS_LIMIT( "MARKET_WITH_LEFTOVER_AS_LIMIT", 'K' );
const OrdTypeEnums::ItemType OrdTypeEnums::PREVIOUS_FUND_VALUATION_POINT( "PREVIOUS_FUND_VALUATION_POINT", 'L' );
const OrdTypeEnums::ItemType OrdTypeEnums::NEXT_FUND_VALUATION_POINT( "NEXT_FUND_VALUATION_POINT", 'M' );
const OrdTypeEnums::ItemType OrdTypeEnums::PEGGED( "PEGGED", 'P' );


const SideEnums::ItemType SideEnums::BUY( "BUY", '1' );
const SideEnums::ItemType SideEnums::SELL( "SELL", '2' );


const TimeInForceEnums::ItemType TimeInForceEnums::DAY( "DAY", '0' );
const TimeInForceEnums::ItemType TimeInForceEnums::GOOD_TILL_CANCEL( "GOOD_TILL_CANCEL", '1' );
const TimeInForceEnums::ItemType TimeInForceEnums::AT_THE_OPENING( "AT_THE_OPENING", '2' );
const TimeInForceEnums::ItemType TimeInForceEnums::IMMEDIATE_OR_CANCEL( "IMMEDIATE_OR_CANCEL", '3' );
const TimeInForceEnums::ItemType TimeInForceEnums::FILL_OR_KILL( "FILL_OR_KILL", '4' );
const TimeInForceEnums::ItemType TimeInForceEnums::GOOD_TILL_CROSSING( "GOOD_TILL_CROSSING", '5' );
const TimeInForceEnums::ItemType TimeInForceEnums::GOOD_TILL_DATE( "GOOD_TILL_DATE", '6' );
const TimeInForceEnums::ItemType TimeInForceEnums::AT_THE_CLOSE( "AT_THE_CLOSE", '7' );


const PriceTypeEnums::ItemType PriceTypeEnums::PERCENTAGE( "PERCENTAGE", 1 );
const PriceTypeEnums::ItemType PriceTypeEnums::PER_UNIT( "PER_UNIT", 2 );
const PriceTypeEnums::ItemType PriceTypeEnums::FIXED_AMOUNT( "FIXED_AMOUNT", 3 );
const PriceTypeEnums::ItemType PriceTypeEnums::DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR( "DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR", 4 );
const PriceTypeEnums::ItemType PriceTypeEnums::PREMIUM_PERCENTAGE_POINTS_OVER_PAR( "PREMIUM_PERCENTAGE_POINTS_OVER_PAR", 5 );
const PriceTypeEnums::ItemType PriceTypeEnums::SPREAD( "SPREAD", 6 );
const PriceTypeEnums::ItemType PriceTypeEnums::TED_PRICE( "TED_PRICE", 7 );
const PriceTypeEnums::ItemType PriceTypeEnums::TED_YIELD( "TED_YIELD", 8 );
const PriceTypeEnums::ItemType PriceTypeEnums::YIELD( "YIELD", 9 );
const PriceTypeEnums::ItemType PriceTypeEnums::FIXED_CABINET_TRADE_PRICE( "FIXED_CABINET_TRADE_PRICE", 10 );
const PriceTypeEnums::ItemType PriceTypeEnums::VARIABLE_CABINET_TRADE_PRICE( "VARIABLE_CABINET_TRADE_PRICE", 11 );


const SecurityTypeEnums::ItemType SecurityTypeEnums::FUTURE( "FUTURE", SOHSTR(FUT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::OPTION( "OPTION", SOHSTR(OPT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EURO_SUPRANATIONAL_COUPONS( "EURO_SUPRANATIONAL_COUPONS", SOHSTR(EUSUPRA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::FEDERAL_AGENCY_COUPON( "FEDERAL_AGENCY_COUPON", SOHSTR(FAC) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::FEDERAL_AGENCY_DISCOUNT_NOTE( "FEDERAL_AGENCY_DISCOUNT_NOTE", SOHSTR(FADN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PRIVATE_EXPORT_FUNDING( "PRIVATE_EXPORT_FUNDING", SOHSTR(PEF) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::USD_SUPRANATIONAL_COUPONS( "USD_SUPRANATIONAL_COUPONS", SOHSTR(SUPRA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CORPORATE_BOND( "CORPORATE_BOND", SOHSTR(CORP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CORPORATE_PRIVATE_PLACEMENT( "CORPORATE_PRIVATE_PLACEMENT", SOHSTR(CPP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CONVERTIBLE_BOND( "CONVERTIBLE_BOND", SOHSTR(CB) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::DUAL_CURRENCY( "DUAL_CURRENCY", SOHSTR(DUAL) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EURO_CORPORATE_BOND( "EURO_CORPORATE_BOND", SOHSTR(EUCORP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::INDEXED_LINKED( "INDEXED_LINKED", SOHSTR(XLINKD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::STRUCTURED_NOTES( "STRUCTURED_NOTES", SOHSTR(STRUCT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::YANKEE_CORPORATE_BOND( "YANKEE_CORPORATE_BOND", SOHSTR(YANK) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::FOREIGN_EXCHANGE_CONTRACT( "FOREIGN_EXCHANGE_CONTRACT", SOHSTR(FOR) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::COMMON_STOCK( "COMMON_STOCK", SOHSTR(CS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PREFERRED_STOCK( "PREFERRED_STOCK", SOHSTR(PS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BRADY_BOND( "BRADY_BOND", SOHSTR(BRADY) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EURO_SOVEREIGNS( "EURO_SOVEREIGNS", SOHSTR(EUSOV) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::US_TREASURY_BOND( "US_TREASURY_BOND", SOHSTR(TBOND) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE( "INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE", SOHSTR(TINT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TREASURY_INFLATION_PROTECTED_SECURITIES( "TREASURY_INFLATION_PROTECTED_SECURITIES", SOHSTR(TIPS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE( "PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE", SOHSTR(TCAL) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE( "PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE", SOHSTR(TPRN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::US_TREASURY_NOTE_UST( "US_TREASURY_NOTE_UST", SOHSTR(UST) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::US_TREASURY_BILL_USTB( "US_TREASURY_BILL_USTB", SOHSTR(USTB) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::US_TREASURY_NOTE_TNOTE( "US_TREASURY_NOTE_TNOTE", SOHSTR(TNOTE) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::US_TREASURY_BILL_TBILL( "US_TREASURY_BILL_TBILL", SOHSTR(TBILL) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REPURCHASE( "REPURCHASE", SOHSTR(REPO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::FORWARD( "FORWARD", SOHSTR(FORWARD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BUY_SELLBACK( "BUY_SELLBACK", SOHSTR(BUYSELL) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SECURITIES_LOAN( "SECURITIES_LOAN", SOHSTR(SECLOAN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SECURITIES_PLEDGE( "SECURITIES_PLEDGE", SOHSTR(SECPLEDGE) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TERM_LOAN( "TERM_LOAN", SOHSTR(TERM) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REVOLVER_LOAN( "REVOLVER_LOAN", SOHSTR(RVLV) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REVOLVER_TERM_LOAN( "REVOLVER_TERM_LOAN", SOHSTR(RVLVTRM) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BRIDGE_LOAN( "BRIDGE_LOAN", SOHSTR(BRIDGE) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::LETTER_OF_CREDIT( "LETTER_OF_CREDIT", SOHSTR(LOFC) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SWING_LINE_FACILITY( "SWING_LINE_FACILITY", SOHSTR(SWING) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::DEBTOR_IN_POSSESSION( "DEBTOR_IN_POSSESSION", SOHSTR(DINP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::DEFAULTED( "DEFAULTED", SOHSTR(DEFLTED) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::WITHDRAWN( "WITHDRAWN", SOHSTR(WITHDRN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REPLACED( "REPLACED", SOHSTR(REPLACD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MATURED( "MATURED", SOHSTR(MATURED) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::AMENDED_RESTATED( "AMENDED_RESTATED", SOHSTR(AMENDED) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::RETIRED( "RETIRED", SOHSTR(RETIRED) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BANKERS_ACCEPTANCE( "BANKERS_ACCEPTANCE", SOHSTR(BA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BANK_NOTES( "BANK_NOTES", SOHSTR(BN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::BILL_OF_EXCHANGES( "BILL_OF_EXCHANGES", SOHSTR(BOX) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CERTIFICATE_OF_DEPOSIT( "CERTIFICATE_OF_DEPOSIT", SOHSTR(CD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CALL_LOANS( "CALL_LOANS", SOHSTR(CL) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::COMMERCIAL_PAPER( "COMMERCIAL_PAPER", SOHSTR(CP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::DEPOSIT_NOTES( "DEPOSIT_NOTES", SOHSTR(DN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EURO_CERTIFICATE_OF_DEPOSIT( "EURO_CERTIFICATE_OF_DEPOSIT", SOHSTR(EUCD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EURO_COMMERCIAL_PAPER( "EURO_COMMERCIAL_PAPER", SOHSTR(EUCP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::LIQUIDITY_NOTE( "LIQUIDITY_NOTE", SOHSTR(LQN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MEDIUM_TERM_NOTES( "MEDIUM_TERM_NOTES", SOHSTR(MTN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::OVERNIGHT( "OVERNIGHT", SOHSTR(ONITE) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PROMISSORY_NOTE( "PROMISSORY_NOTE", SOHSTR(PN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PLAZOS_FIJOS( "PLAZOS_FIJOS", SOHSTR(PZFJ) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SHORT_TERM_LOAN_NOTE( "SHORT_TERM_LOAN_NOTE", SOHSTR(STN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TIME_DEPOSIT( "TIME_DEPOSIT", SOHSTR(TD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::EXTENDED_COMM_NOTE( "EXTENDED_COMM_NOTE", SOHSTR(XCN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::YANKEE_CERTIFICATE_OF_DEPOSIT( "YANKEE_CERTIFICATE_OF_DEPOSIT", SOHSTR(YCD) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::ASSET_BACKED_SECURITIES( "ASSET_BACKED_SECURITIES", SOHSTR(ABS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CORP_MORTGAGE_BACKED_SECURITIES( "CORP_MORTGAGE_BACKED_SECURITIES", SOHSTR(CMBS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::COLLATERALIZED_MORTGAGE_OBLIGATION( "COLLATERALIZED_MORTGAGE_OBLIGATION", SOHSTR(CMO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::IOETTE_MORTGAGE( "IOETTE_MORTGAGE", SOHSTR(IET) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MORTGAGE_BACKED_SECURITIES( "MORTGAGE_BACKED_SECURITIES", SOHSTR(MBS) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MORTGAGE_INTEREST_ONLY( "MORTGAGE_INTEREST_ONLY", SOHSTR(MIO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MORTGAGE_PRINCIPAL_ONLY( "MORTGAGE_PRINCIPAL_ONLY", SOHSTR(MPO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MORTGAGE_PRIVATE_PLACEMENT( "MORTGAGE_PRIVATE_PLACEMENT", SOHSTR(MPP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MISCELLANEOUS_PASS_THROUGH( "MISCELLANEOUS_PASS_THROUGH", SOHSTR(MPT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::PFANDBRIEFE( "PFANDBRIEFE", SOHSTR(PFAND) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TO_BE_ANNOUNCED( "TO_BE_ANNOUNCED", SOHSTR(TBA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC( "OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC", SOHSTR(AN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CERTIFICATE_OF_OBLIGATION( "CERTIFICATE_OF_OBLIGATION", SOHSTR(COFO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::CERTIFICATE_OF_PARTICIPATION( "CERTIFICATE_OF_PARTICIPATION", SOHSTR(COFP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::GENERAL_OBLIGATION_BONDS( "GENERAL_OBLIGATION_BONDS", SOHSTR(GO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MANDATORY_TENDER( "MANDATORY_TENDER", SOHSTR(MT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REVENUE_ANTICIPATION_NOTE( "REVENUE_ANTICIPATION_NOTE", SOHSTR(RAN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::REVENUE_BONDS( "REVENUE_BONDS", SOHSTR(REV) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SPECIAL_ASSESSMENT( "SPECIAL_ASSESSMENT", SOHSTR(SPCLA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SPECIAL_OBLIGATION( "SPECIAL_OBLIGATION", SOHSTR(SPCLO) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::SPECIAL_TAX( "SPECIAL_TAX", SOHSTR(SPCLT) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TAX_ANTICIPATION_NOTE( "TAX_ANTICIPATION_NOTE", SOHSTR(TAN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TAX_ALLOCATION( "TAX_ALLOCATION", SOHSTR(TAXA) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TAX_EXEMPT_COMMERCIAL_PAPER( "TAX_EXEMPT_COMMERCIAL_PAPER", SOHSTR(TECP) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::TAX_REVENUE_ANTICIPATION_NOTE( "TAX_REVENUE_ANTICIPATION_NOTE", SOHSTR(TRAN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::VARIABLE_RATE_DEMAND_NOTE( "VARIABLE_RATE_DEMAND_NOTE", SOHSTR(VRDN) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::WARRANT( "WARRANT", SOHSTR(WAR) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MUTUAL_FUND( "MUTUAL_FUND", SOHSTR(MF) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::MULTI_LEG_INSTRUMENT( "MULTI_LEG_INSTRUMENT", SOHSTR(MLEG) );
const SecurityTypeEnums::ItemType SecurityTypeEnums::NO_SECURITY_TYPE( "NO_SECURITY_TYPE", SOHSTR(NONE) );


// -------------------------------------- enum items ----------------------------------------


template<> const FieldEnumBase * const * FieldAccount::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldAvgPx::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldBeginString::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldBodyLength::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldCheckSum::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldClOrdID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldCumQty::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldCurrency::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldExecID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldExecInst::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLastPx::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLastQty::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldMsgSeqNum::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldMsgType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrderID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrderQty::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrdStatus::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrdType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrigClOrdID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldPrice::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSecurityID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSenderCompID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSendingTime::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSide::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSymbol::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldTargetCompID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldText::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldTimeInForce::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldTransactTime::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldStopPx::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldOrdRejReason::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldExecType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLeavesQty::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldSecurityType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldPriceType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldProduct::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldQtyType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNoLegs::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegPositionEffect::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegPrice::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegSymbol::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegSide::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegLastPx::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegRefID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNoLegStipulations::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegQty::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegStipulationType::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldLegStipulationValue::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNestedPartyID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNestedPartyIDSource::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNestedPartyRole::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNoNestedPartyIDs::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNestedPartySubID::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNoNestedPartySubIDs::enumItems = nullptr;
template<> const FieldEnumBase * const * FieldNestedPartySubIDType::enumItems = nullptr;


const char * QtyTypeEnums::getFieldName() const { return FixQtyType; }
const FieldEnumBase * QtyTypeEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & QtyTypeEnums::getEnumMapByRaw() const { return QtyTypeEnums::itemByRaw; }
const FieldEnumBase * const * const QtyTypeEnums::getEnums() const { return items; }
const QtyTypeEnums QtyTypeEnums::instance;
const FieldEnumBase * QtyTypeEnums::items[] = {
& QtyTypeEnums::UNITS,
& QtyTypeEnums::CONTRACTS,
nullptr };


const char * ProductEnums::getFieldName() const { return FixProduct; }
const FieldEnumBase * ProductEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & ProductEnums::getEnumMapByRaw() const { return ProductEnums::itemByRaw; }
const FieldEnumBase * const * const ProductEnums::getEnums() const { return items; }
const ProductEnums ProductEnums::instance;
const FieldEnumBase * ProductEnums::items[] = {
& ProductEnums::AGENCY,
& ProductEnums::COMMODITY,
& ProductEnums::CORPORATE,
& ProductEnums::CURRENCY,
& ProductEnums::EQUITY,
& ProductEnums::GOVERNMENT,
& ProductEnums::INDEX,
& ProductEnums::LOAN,
& ProductEnums::MONEYMARKET,
& ProductEnums::MORTGAGE,
& ProductEnums::MUNICIPAL,
& ProductEnums::OTHER,
& ProductEnums::FINANCING,
nullptr };


const char * MsgTypeEnums::getFieldName() const { return FixMsgType; }
const FieldEnumBase * MsgTypeEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & MsgTypeEnums::getEnumMapByRaw() const { return MsgTypeEnums::itemByRaw; }
const FieldEnumBase * const * const MsgTypeEnums::getEnums() const { return items; }
const MsgTypeEnums MsgTypeEnums::instance;
const FieldEnumBase * MsgTypeEnums::items[] = {
& MsgTypeEnums::HEARTBEAT,
& MsgTypeEnums::TEST_REQUEST,
& MsgTypeEnums::RESEND_REQUEST,
& MsgTypeEnums::REJECT,
& MsgTypeEnums::SEQUENCE_RESET,
& MsgTypeEnums::LOGOUT,
& MsgTypeEnums::EXECUTION_REPORT,
& MsgTypeEnums::LOGON,
& MsgTypeEnums::ORDER_SINGLE,
& MsgTypeEnums::MARKET_DATA_REQUEST,
& MsgTypeEnums::MARKET_DATA_SNAPSHOT_FULL_REFRESH,
& MsgTypeEnums::MARKET_DATA_INCREMENTAL_REFRESH,
& MsgTypeEnums::MARKET_DATA_REQUEST_REJECT,
& MsgTypeEnums::COLLATERAL_INQUIRY_ACK,
& MsgTypeEnums::CONFIRMATION_REQUEST,
& MsgTypeEnums::SECURITY_DEFINITION,
nullptr };


const char * OrdStatusEnums::getFieldName() const { return FixOrdStatus; }
const FieldEnumBase * OrdStatusEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & OrdStatusEnums::getEnumMapByRaw() const { return OrdStatusEnums::itemByRaw; }
const FieldEnumBase * const * const OrdStatusEnums::getEnums() const { return items; }
const OrdStatusEnums OrdStatusEnums::instance;
const FieldEnumBase * OrdStatusEnums::items[] = {
& OrdStatusEnums::NEW,
& OrdStatusEnums::PARTIALLY_FILLED,
& OrdStatusEnums::FILLED,
& OrdStatusEnums::DONE_FOR_DAY,
& OrdStatusEnums::CANCELED,
& OrdStatusEnums::PENDING_CANCEL,
& OrdStatusEnums::STOPPED,
& OrdStatusEnums::REJECTED,
& OrdStatusEnums::SUSPENDED,
& OrdStatusEnums::PENDING_NEW,
& OrdStatusEnums::CALCULATED,
& OrdStatusEnums::EXPIRED,
& OrdStatusEnums::ACCEPTED_FOR_BIDDING,
& OrdStatusEnums::PENDING_REPLACE,
nullptr };


const char * OrdTypeEnums::getFieldName() const { return FixOrdType; }
const FieldEnumBase * OrdTypeEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & OrdTypeEnums::getEnumMapByRaw() const { return OrdTypeEnums::itemByRaw; }
const FieldEnumBase * const * const OrdTypeEnums::getEnums() const { return items; }
const OrdTypeEnums OrdTypeEnums::instance;
const FieldEnumBase * OrdTypeEnums::items[] = {
& OrdTypeEnums::MARKET,
& OrdTypeEnums::LIMIT,
& OrdTypeEnums::STOP,
& OrdTypeEnums::STOP_LIMIT,
& OrdTypeEnums::WITH_OR_WITHOUT,
& OrdTypeEnums::LIMIT_OR_BETTER,
& OrdTypeEnums::LIMIT_WITH_OR_WITHOUT,
& OrdTypeEnums::ON_BASIS,
& OrdTypeEnums::PREVIOUSLY_QUOTED,
& OrdTypeEnums::PREVIOUSLY_INDICATED,
& OrdTypeEnums::FOREX,
& OrdTypeEnums::FUNARI,
& OrdTypeEnums::MARKET_IF_TOUCHED,
& OrdTypeEnums::MARKET_WITH_LEFTOVER_AS_LIMIT,
& OrdTypeEnums::PREVIOUS_FUND_VALUATION_POINT,
& OrdTypeEnums::NEXT_FUND_VALUATION_POINT,
& OrdTypeEnums::PEGGED,
nullptr };


const char * SideEnums::getFieldName() const { return FixSide; }
const FieldEnumBase * SideEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & SideEnums::getEnumMapByRaw() const { return SideEnums::itemByRaw; }
const FieldEnumBase * const * const SideEnums::getEnums() const { return items; }
const SideEnums SideEnums::instance;
const FieldEnumBase * SideEnums::items[] = {
& SideEnums::BUY,
& SideEnums::SELL,
nullptr };


const char * TimeInForceEnums::getFieldName() const { return FixTimeInForce; }
const FieldEnumBase * TimeInForceEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & TimeInForceEnums::getEnumMapByRaw() const { return TimeInForceEnums::itemByRaw; }
const FieldEnumBase * const * const TimeInForceEnums::getEnums() const { return items; }
const TimeInForceEnums TimeInForceEnums::instance;
const FieldEnumBase * TimeInForceEnums::items[] = {
& TimeInForceEnums::DAY,
& TimeInForceEnums::GOOD_TILL_CANCEL,
& TimeInForceEnums::AT_THE_OPENING,
& TimeInForceEnums::IMMEDIATE_OR_CANCEL,
& TimeInForceEnums::FILL_OR_KILL,
& TimeInForceEnums::GOOD_TILL_CROSSING,
& TimeInForceEnums::GOOD_TILL_DATE,
& TimeInForceEnums::AT_THE_CLOSE,
nullptr };


const char * PriceTypeEnums::getFieldName() const { return FixPriceType; }
const FieldEnumBase * PriceTypeEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & PriceTypeEnums::getEnumMapByRaw() const { return PriceTypeEnums::itemByRaw; }
const FieldEnumBase * const * const PriceTypeEnums::getEnums() const { return items; }
const PriceTypeEnums PriceTypeEnums::instance;
const FieldEnumBase * PriceTypeEnums::items[] = {
& PriceTypeEnums::PERCENTAGE,
& PriceTypeEnums::PER_UNIT,
& PriceTypeEnums::FIXED_AMOUNT,
& PriceTypeEnums::DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR,
& PriceTypeEnums::PREMIUM_PERCENTAGE_POINTS_OVER_PAR,
& PriceTypeEnums::SPREAD,
& PriceTypeEnums::TED_PRICE,
& PriceTypeEnums::TED_YIELD,
& PriceTypeEnums::YIELD,
& PriceTypeEnums::FIXED_CABINET_TRADE_PRICE,
& PriceTypeEnums::VARIABLE_CABINET_TRADE_PRICE,
nullptr };


const char * SecurityTypeEnums::getFieldName() const { return FixSecurityType; }
const FieldEnumBase * SecurityTypeEnums::getEnumByRaw( raw_enum_t raw ) const { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }
const FieldEnumMap & SecurityTypeEnums::getEnumMapByRaw() const { return SecurityTypeEnums::itemByRaw; }
const FieldEnumBase * const * const SecurityTypeEnums::getEnums() const { return items; }
const SecurityTypeEnums SecurityTypeEnums::instance;
const FieldEnumBase * SecurityTypeEnums::items[] = {
& SecurityTypeEnums::FUTURE,
& SecurityTypeEnums::OPTION,
& SecurityTypeEnums::EURO_SUPRANATIONAL_COUPONS,
& SecurityTypeEnums::FEDERAL_AGENCY_COUPON,
& SecurityTypeEnums::FEDERAL_AGENCY_DISCOUNT_NOTE,
& SecurityTypeEnums::PRIVATE_EXPORT_FUNDING,
& SecurityTypeEnums::USD_SUPRANATIONAL_COUPONS,
& SecurityTypeEnums::CORPORATE_BOND,
& SecurityTypeEnums::CORPORATE_PRIVATE_PLACEMENT,
& SecurityTypeEnums::CONVERTIBLE_BOND,
& SecurityTypeEnums::DUAL_CURRENCY,
& SecurityTypeEnums::EURO_CORPORATE_BOND,
& SecurityTypeEnums::INDEXED_LINKED,
& SecurityTypeEnums::STRUCTURED_NOTES,
& SecurityTypeEnums::YANKEE_CORPORATE_BOND,
& SecurityTypeEnums::FOREIGN_EXCHANGE_CONTRACT,
& SecurityTypeEnums::COMMON_STOCK,
& SecurityTypeEnums::PREFERRED_STOCK,
& SecurityTypeEnums::BRADY_BOND,
& SecurityTypeEnums::EURO_SOVEREIGNS,
& SecurityTypeEnums::US_TREASURY_BOND,
& SecurityTypeEnums::INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE,
& SecurityTypeEnums::TREASURY_INFLATION_PROTECTED_SECURITIES,
& SecurityTypeEnums::PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE,
& SecurityTypeEnums::PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE,
& SecurityTypeEnums::US_TREASURY_NOTE_UST,
& SecurityTypeEnums::US_TREASURY_BILL_USTB,
& SecurityTypeEnums::US_TREASURY_NOTE_TNOTE,
& SecurityTypeEnums::US_TREASURY_BILL_TBILL,
& SecurityTypeEnums::REPURCHASE,
& SecurityTypeEnums::FORWARD,
& SecurityTypeEnums::BUY_SELLBACK,
& SecurityTypeEnums::SECURITIES_LOAN,
& SecurityTypeEnums::SECURITIES_PLEDGE,
& SecurityTypeEnums::TERM_LOAN,
& SecurityTypeEnums::REVOLVER_LOAN,
& SecurityTypeEnums::REVOLVER_TERM_LOAN,
& SecurityTypeEnums::BRIDGE_LOAN,
& SecurityTypeEnums::LETTER_OF_CREDIT,
& SecurityTypeEnums::SWING_LINE_FACILITY,
& SecurityTypeEnums::DEBTOR_IN_POSSESSION,
& SecurityTypeEnums::DEFAULTED,
& SecurityTypeEnums::WITHDRAWN,
& SecurityTypeEnums::REPLACED,
& SecurityTypeEnums::MATURED,
& SecurityTypeEnums::AMENDED_RESTATED,
& SecurityTypeEnums::RETIRED,
& SecurityTypeEnums::BANKERS_ACCEPTANCE,
& SecurityTypeEnums::BANK_NOTES,
& SecurityTypeEnums::BILL_OF_EXCHANGES,
& SecurityTypeEnums::CERTIFICATE_OF_DEPOSIT,
& SecurityTypeEnums::CALL_LOANS,
& SecurityTypeEnums::COMMERCIAL_PAPER,
& SecurityTypeEnums::DEPOSIT_NOTES,
& SecurityTypeEnums::EURO_CERTIFICATE_OF_DEPOSIT,
& SecurityTypeEnums::EURO_COMMERCIAL_PAPER,
& SecurityTypeEnums::LIQUIDITY_NOTE,
& SecurityTypeEnums::MEDIUM_TERM_NOTES,
& SecurityTypeEnums::OVERNIGHT,
& SecurityTypeEnums::PROMISSORY_NOTE,
& SecurityTypeEnums::PLAZOS_FIJOS,
& SecurityTypeEnums::SHORT_TERM_LOAN_NOTE,
& SecurityTypeEnums::TIME_DEPOSIT,
& SecurityTypeEnums::EXTENDED_COMM_NOTE,
& SecurityTypeEnums::YANKEE_CERTIFICATE_OF_DEPOSIT,
& SecurityTypeEnums::ASSET_BACKED_SECURITIES,
& SecurityTypeEnums::CORP_MORTGAGE_BACKED_SECURITIES,
& SecurityTypeEnums::COLLATERALIZED_MORTGAGE_OBLIGATION,
& SecurityTypeEnums::IOETTE_MORTGAGE,
& SecurityTypeEnums::MORTGAGE_BACKED_SECURITIES,
& SecurityTypeEnums::MORTGAGE_INTEREST_ONLY,
& SecurityTypeEnums::MORTGAGE_PRINCIPAL_ONLY,
& SecurityTypeEnums::MORTGAGE_PRIVATE_PLACEMENT,
& SecurityTypeEnums::MISCELLANEOUS_PASS_THROUGH,
& SecurityTypeEnums::PFANDBRIEFE,
& SecurityTypeEnums::TO_BE_ANNOUNCED,
& SecurityTypeEnums::OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC,
& SecurityTypeEnums::CERTIFICATE_OF_OBLIGATION,
& SecurityTypeEnums::CERTIFICATE_OF_PARTICIPATION,
& SecurityTypeEnums::GENERAL_OBLIGATION_BONDS,
& SecurityTypeEnums::MANDATORY_TENDER,
& SecurityTypeEnums::REVENUE_ANTICIPATION_NOTE,
& SecurityTypeEnums::REVENUE_BONDS,
& SecurityTypeEnums::SPECIAL_ASSESSMENT,
& SecurityTypeEnums::SPECIAL_OBLIGATION,
& SecurityTypeEnums::SPECIAL_TAX,
& SecurityTypeEnums::TAX_ANTICIPATION_NOTE,
& SecurityTypeEnums::TAX_ALLOCATION,
& SecurityTypeEnums::TAX_EXEMPT_COMMERCIAL_PAPER,
& SecurityTypeEnums::TAX_REVENUE_ANTICIPATION_NOTE,
& SecurityTypeEnums::VARIABLE_RATE_DEMAND_NOTE,
& SecurityTypeEnums::WARRANT,
& SecurityTypeEnums::MUTUAL_FUND,
& SecurityTypeEnums::MULTI_LEG_INSTRUMENT,
& SecurityTypeEnums::NO_SECURITY_TYPE,
nullptr };


// -------------------------------------- enum maps ----------------------------------------


const FieldEnumMap QtyTypeEnums::itemByRaw = {
{ QtyTypeEnums::UNITS.raw, & QtyTypeEnums::UNITS },
{ QtyTypeEnums::CONTRACTS.raw, & QtyTypeEnums::CONTRACTS },
};

const FieldEnumMap ProductEnums::itemByRaw = {
{ ProductEnums::AGENCY.raw, & ProductEnums::AGENCY },
{ ProductEnums::COMMODITY.raw, & ProductEnums::COMMODITY },
{ ProductEnums::CORPORATE.raw, & ProductEnums::CORPORATE },
{ ProductEnums::CURRENCY.raw, & ProductEnums::CURRENCY },
{ ProductEnums::EQUITY.raw, & ProductEnums::EQUITY },
{ ProductEnums::GOVERNMENT.raw, & ProductEnums::GOVERNMENT },
{ ProductEnums::INDEX.raw, & ProductEnums::INDEX },
{ ProductEnums::LOAN.raw, & ProductEnums::LOAN },
{ ProductEnums::MONEYMARKET.raw, & ProductEnums::MONEYMARKET },
{ ProductEnums::MORTGAGE.raw, & ProductEnums::MORTGAGE },
{ ProductEnums::MUNICIPAL.raw, & ProductEnums::MUNICIPAL },
{ ProductEnums::OTHER.raw, & ProductEnums::OTHER },
{ ProductEnums::FINANCING.raw, & ProductEnums::FINANCING },
};

const FieldEnumMap MsgTypeEnums::itemByRaw = {
{ MsgTypeEnums::HEARTBEAT.raw, & MsgTypeEnums::HEARTBEAT },
{ MsgTypeEnums::TEST_REQUEST.raw, & MsgTypeEnums::TEST_REQUEST },
{ MsgTypeEnums::RESEND_REQUEST.raw, & MsgTypeEnums::RESEND_REQUEST },
{ MsgTypeEnums::REJECT.raw, & MsgTypeEnums::REJECT },
{ MsgTypeEnums::SEQUENCE_RESET.raw, & MsgTypeEnums::SEQUENCE_RESET },
{ MsgTypeEnums::LOGOUT.raw, & MsgTypeEnums::LOGOUT },
{ MsgTypeEnums::EXECUTION_REPORT.raw, & MsgTypeEnums::EXECUTION_REPORT },
{ MsgTypeEnums::LOGON.raw, & MsgTypeEnums::LOGON },
{ MsgTypeEnums::ORDER_SINGLE.raw, & MsgTypeEnums::ORDER_SINGLE },
{ MsgTypeEnums::MARKET_DATA_REQUEST.raw, & MsgTypeEnums::MARKET_DATA_REQUEST },
{ MsgTypeEnums::MARKET_DATA_SNAPSHOT_FULL_REFRESH.raw, & MsgTypeEnums::MARKET_DATA_SNAPSHOT_FULL_REFRESH },
{ MsgTypeEnums::MARKET_DATA_INCREMENTAL_REFRESH.raw, & MsgTypeEnums::MARKET_DATA_INCREMENTAL_REFRESH },
{ MsgTypeEnums::MARKET_DATA_REQUEST_REJECT.raw, & MsgTypeEnums::MARKET_DATA_REQUEST_REJECT },
{ MsgTypeEnums::COLLATERAL_INQUIRY_ACK.raw, & MsgTypeEnums::COLLATERAL_INQUIRY_ACK },
{ MsgTypeEnums::CONFIRMATION_REQUEST.raw, & MsgTypeEnums::CONFIRMATION_REQUEST },
{ MsgTypeEnums::SECURITY_DEFINITION.raw, & MsgTypeEnums::SECURITY_DEFINITION },
};

const FieldEnumMap OrdStatusEnums::itemByRaw = {
{ OrdStatusEnums::NEW.raw, & OrdStatusEnums::NEW },
{ OrdStatusEnums::PARTIALLY_FILLED.raw, & OrdStatusEnums::PARTIALLY_FILLED },
{ OrdStatusEnums::FILLED.raw, & OrdStatusEnums::FILLED },
{ OrdStatusEnums::DONE_FOR_DAY.raw, & OrdStatusEnums::DONE_FOR_DAY },
{ OrdStatusEnums::CANCELED.raw, & OrdStatusEnums::CANCELED },
{ OrdStatusEnums::PENDING_CANCEL.raw, & OrdStatusEnums::PENDING_CANCEL },
{ OrdStatusEnums::STOPPED.raw, & OrdStatusEnums::STOPPED },
{ OrdStatusEnums::REJECTED.raw, & OrdStatusEnums::REJECTED },
{ OrdStatusEnums::SUSPENDED.raw, & OrdStatusEnums::SUSPENDED },
{ OrdStatusEnums::PENDING_NEW.raw, & OrdStatusEnums::PENDING_NEW },
{ OrdStatusEnums::CALCULATED.raw, & OrdStatusEnums::CALCULATED },
{ OrdStatusEnums::EXPIRED.raw, & OrdStatusEnums::EXPIRED },
{ OrdStatusEnums::ACCEPTED_FOR_BIDDING.raw, & OrdStatusEnums::ACCEPTED_FOR_BIDDING },
{ OrdStatusEnums::PENDING_REPLACE.raw, & OrdStatusEnums::PENDING_REPLACE },
};

const FieldEnumMap OrdTypeEnums::itemByRaw = {
{ OrdTypeEnums::MARKET.raw, & OrdTypeEnums::MARKET },
{ OrdTypeEnums::LIMIT.raw, & OrdTypeEnums::LIMIT },
{ OrdTypeEnums::STOP.raw, & OrdTypeEnums::STOP },
{ OrdTypeEnums::STOP_LIMIT.raw, & OrdTypeEnums::STOP_LIMIT },
{ OrdTypeEnums::WITH_OR_WITHOUT.raw, & OrdTypeEnums::WITH_OR_WITHOUT },
{ OrdTypeEnums::LIMIT_OR_BETTER.raw, & OrdTypeEnums::LIMIT_OR_BETTER },
{ OrdTypeEnums::LIMIT_WITH_OR_WITHOUT.raw, & OrdTypeEnums::LIMIT_WITH_OR_WITHOUT },
{ OrdTypeEnums::ON_BASIS.raw, & OrdTypeEnums::ON_BASIS },
{ OrdTypeEnums::PREVIOUSLY_QUOTED.raw, & OrdTypeEnums::PREVIOUSLY_QUOTED },
{ OrdTypeEnums::PREVIOUSLY_INDICATED.raw, & OrdTypeEnums::PREVIOUSLY_INDICATED },
{ OrdTypeEnums::FOREX.raw, & OrdTypeEnums::FOREX },
{ OrdTypeEnums::FUNARI.raw, & OrdTypeEnums::FUNARI },
{ OrdTypeEnums::MARKET_IF_TOUCHED.raw, & OrdTypeEnums::MARKET_IF_TOUCHED },
{ OrdTypeEnums::MARKET_WITH_LEFTOVER_AS_LIMIT.raw, & OrdTypeEnums::MARKET_WITH_LEFTOVER_AS_LIMIT },
{ OrdTypeEnums::PREVIOUS_FUND_VALUATION_POINT.raw, & OrdTypeEnums::PREVIOUS_FUND_VALUATION_POINT },
{ OrdTypeEnums::NEXT_FUND_VALUATION_POINT.raw, & OrdTypeEnums::NEXT_FUND_VALUATION_POINT },
{ OrdTypeEnums::PEGGED.raw, & OrdTypeEnums::PEGGED },
};


const FieldEnumMap SideEnums::itemByRaw = {
{ SideEnums::BUY.raw, & SideEnums::BUY },
{ SideEnums::SELL.raw, & SideEnums::SELL },
};

const FieldEnumMap TimeInForceEnums::itemByRaw = {
{ TimeInForceEnums::DAY.raw, & TimeInForceEnums::DAY },
{ TimeInForceEnums::GOOD_TILL_CANCEL.raw, & TimeInForceEnums::GOOD_TILL_CANCEL },
{ TimeInForceEnums::AT_THE_OPENING.raw, & TimeInForceEnums::AT_THE_OPENING },
{ TimeInForceEnums::IMMEDIATE_OR_CANCEL.raw, & TimeInForceEnums::IMMEDIATE_OR_CANCEL },
{ TimeInForceEnums::FILL_OR_KILL.raw, & TimeInForceEnums::FILL_OR_KILL },
{ TimeInForceEnums::GOOD_TILL_CROSSING.raw, & TimeInForceEnums::GOOD_TILL_CROSSING },
{ TimeInForceEnums::GOOD_TILL_DATE.raw, & TimeInForceEnums::GOOD_TILL_DATE },
{ TimeInForceEnums::AT_THE_CLOSE.raw, & TimeInForceEnums::AT_THE_CLOSE },
};

const FieldEnumMap PriceTypeEnums::itemByRaw = {
{ PriceTypeEnums::PERCENTAGE.raw, & PriceTypeEnums::PERCENTAGE },
{ PriceTypeEnums::PER_UNIT.raw, & PriceTypeEnums::PER_UNIT },
{ PriceTypeEnums::FIXED_AMOUNT.raw, & PriceTypeEnums::FIXED_AMOUNT },
{ PriceTypeEnums::DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR.raw, & PriceTypeEnums::DISCOUNT_PERCENTAGE_POINTS_BELOW_PAR },
{ PriceTypeEnums::PREMIUM_PERCENTAGE_POINTS_OVER_PAR.raw, & PriceTypeEnums::PREMIUM_PERCENTAGE_POINTS_OVER_PAR },
{ PriceTypeEnums::SPREAD.raw, & PriceTypeEnums::SPREAD },
{ PriceTypeEnums::TED_PRICE.raw, & PriceTypeEnums::TED_PRICE },
{ PriceTypeEnums::TED_YIELD.raw, & PriceTypeEnums::TED_YIELD },
{ PriceTypeEnums::YIELD.raw, & PriceTypeEnums::YIELD },
{ PriceTypeEnums::FIXED_CABINET_TRADE_PRICE.raw, & PriceTypeEnums::FIXED_CABINET_TRADE_PRICE },
{ PriceTypeEnums::VARIABLE_CABINET_TRADE_PRICE.raw, & PriceTypeEnums::VARIABLE_CABINET_TRADE_PRICE },
};

const FieldEnumMap SecurityTypeEnums::itemByRaw = {
{ SecurityTypeEnums::FUTURE.raw, & SecurityTypeEnums::FUTURE },
{ SecurityTypeEnums::OPTION.raw, & SecurityTypeEnums::OPTION },
{ SecurityTypeEnums::EURO_SUPRANATIONAL_COUPONS.raw, & SecurityTypeEnums::EURO_SUPRANATIONAL_COUPONS },
{ SecurityTypeEnums::FEDERAL_AGENCY_COUPON.raw, & SecurityTypeEnums::FEDERAL_AGENCY_COUPON },
{ SecurityTypeEnums::FEDERAL_AGENCY_DISCOUNT_NOTE.raw, & SecurityTypeEnums::FEDERAL_AGENCY_DISCOUNT_NOTE },
{ SecurityTypeEnums::PRIVATE_EXPORT_FUNDING.raw, & SecurityTypeEnums::PRIVATE_EXPORT_FUNDING },
{ SecurityTypeEnums::USD_SUPRANATIONAL_COUPONS.raw, & SecurityTypeEnums::USD_SUPRANATIONAL_COUPONS },
{ SecurityTypeEnums::CORPORATE_BOND.raw, & SecurityTypeEnums::CORPORATE_BOND },
{ SecurityTypeEnums::CORPORATE_PRIVATE_PLACEMENT.raw, & SecurityTypeEnums::CORPORATE_PRIVATE_PLACEMENT },
{ SecurityTypeEnums::CONVERTIBLE_BOND.raw, & SecurityTypeEnums::CONVERTIBLE_BOND },
{ SecurityTypeEnums::DUAL_CURRENCY.raw, & SecurityTypeEnums::DUAL_CURRENCY },
{ SecurityTypeEnums::EURO_CORPORATE_BOND.raw, & SecurityTypeEnums::EURO_CORPORATE_BOND },
{ SecurityTypeEnums::INDEXED_LINKED.raw, & SecurityTypeEnums::INDEXED_LINKED },
{ SecurityTypeEnums::STRUCTURED_NOTES.raw, & SecurityTypeEnums::STRUCTURED_NOTES },
{ SecurityTypeEnums::YANKEE_CORPORATE_BOND.raw, & SecurityTypeEnums::YANKEE_CORPORATE_BOND },
{ SecurityTypeEnums::FOREIGN_EXCHANGE_CONTRACT.raw, & SecurityTypeEnums::FOREIGN_EXCHANGE_CONTRACT },
{ SecurityTypeEnums::COMMON_STOCK.raw, & SecurityTypeEnums::COMMON_STOCK },
{ SecurityTypeEnums::PREFERRED_STOCK.raw, & SecurityTypeEnums::PREFERRED_STOCK },
{ SecurityTypeEnums::BRADY_BOND.raw, & SecurityTypeEnums::BRADY_BOND },
{ SecurityTypeEnums::EURO_SOVEREIGNS.raw, & SecurityTypeEnums::EURO_SOVEREIGNS },
{ SecurityTypeEnums::US_TREASURY_BOND.raw, & SecurityTypeEnums::US_TREASURY_BOND },
{ SecurityTypeEnums::INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE.raw, & SecurityTypeEnums::INTEREST_STRIP_FROM_ANY_BOND_OR_NOTE },
{ SecurityTypeEnums::TREASURY_INFLATION_PROTECTED_SECURITIES.raw, & SecurityTypeEnums::TREASURY_INFLATION_PROTECTED_SECURITIES },
{ SecurityTypeEnums::PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE.raw, & SecurityTypeEnums::PRINCIPAL_STRIP_OF_A_CALLABLE_BOND_OR_NOTE },
{ SecurityTypeEnums::PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE.raw, & SecurityTypeEnums::PRINCIPAL_STRIP_FROM_A_NON_CALLABLE_BOND_OR_NOTE },
{ SecurityTypeEnums::US_TREASURY_NOTE_UST.raw, & SecurityTypeEnums::US_TREASURY_NOTE_UST },
{ SecurityTypeEnums::US_TREASURY_BILL_USTB.raw, & SecurityTypeEnums::US_TREASURY_BILL_USTB },
{ SecurityTypeEnums::US_TREASURY_NOTE_TNOTE.raw, & SecurityTypeEnums::US_TREASURY_NOTE_TNOTE },
{ SecurityTypeEnums::US_TREASURY_BILL_TBILL.raw, & SecurityTypeEnums::US_TREASURY_BILL_TBILL },
{ SecurityTypeEnums::REPURCHASE.raw, & SecurityTypeEnums::REPURCHASE },
{ SecurityTypeEnums::FORWARD.raw, & SecurityTypeEnums::FORWARD },
{ SecurityTypeEnums::BUY_SELLBACK.raw, & SecurityTypeEnums::BUY_SELLBACK },
{ SecurityTypeEnums::SECURITIES_LOAN.raw, & SecurityTypeEnums::SECURITIES_LOAN },
{ SecurityTypeEnums::SECURITIES_PLEDGE.raw, & SecurityTypeEnums::SECURITIES_PLEDGE },
{ SecurityTypeEnums::TERM_LOAN.raw, & SecurityTypeEnums::TERM_LOAN },
{ SecurityTypeEnums::REVOLVER_LOAN.raw, & SecurityTypeEnums::REVOLVER_LOAN },
{ SecurityTypeEnums::REVOLVER_TERM_LOAN.raw, & SecurityTypeEnums::REVOLVER_TERM_LOAN },
{ SecurityTypeEnums::BRIDGE_LOAN.raw, & SecurityTypeEnums::BRIDGE_LOAN },
{ SecurityTypeEnums::LETTER_OF_CREDIT.raw, & SecurityTypeEnums::LETTER_OF_CREDIT },
{ SecurityTypeEnums::SWING_LINE_FACILITY.raw, & SecurityTypeEnums::SWING_LINE_FACILITY },
{ SecurityTypeEnums::DEBTOR_IN_POSSESSION.raw, & SecurityTypeEnums::DEBTOR_IN_POSSESSION },
{ SecurityTypeEnums::DEFAULTED.raw, & SecurityTypeEnums::DEFAULTED },
{ SecurityTypeEnums::WITHDRAWN.raw, & SecurityTypeEnums::WITHDRAWN },
{ SecurityTypeEnums::REPLACED.raw, & SecurityTypeEnums::REPLACED },
{ SecurityTypeEnums::MATURED.raw, & SecurityTypeEnums::MATURED },
{ SecurityTypeEnums::AMENDED_RESTATED.raw, & SecurityTypeEnums::AMENDED_RESTATED },
{ SecurityTypeEnums::RETIRED.raw, & SecurityTypeEnums::RETIRED },
{ SecurityTypeEnums::BANKERS_ACCEPTANCE.raw, & SecurityTypeEnums::BANKERS_ACCEPTANCE },
{ SecurityTypeEnums::BANK_NOTES.raw, & SecurityTypeEnums::BANK_NOTES },
{ SecurityTypeEnums::BILL_OF_EXCHANGES.raw, & SecurityTypeEnums::BILL_OF_EXCHANGES },
{ SecurityTypeEnums::CERTIFICATE_OF_DEPOSIT.raw, & SecurityTypeEnums::CERTIFICATE_OF_DEPOSIT },
{ SecurityTypeEnums::CALL_LOANS.raw, & SecurityTypeEnums::CALL_LOANS },
{ SecurityTypeEnums::COMMERCIAL_PAPER.raw, & SecurityTypeEnums::COMMERCIAL_PAPER },
{ SecurityTypeEnums::DEPOSIT_NOTES.raw, & SecurityTypeEnums::DEPOSIT_NOTES },
{ SecurityTypeEnums::EURO_CERTIFICATE_OF_DEPOSIT.raw, & SecurityTypeEnums::EURO_CERTIFICATE_OF_DEPOSIT },
{ SecurityTypeEnums::EURO_COMMERCIAL_PAPER.raw, & SecurityTypeEnums::EURO_COMMERCIAL_PAPER },
{ SecurityTypeEnums::LIQUIDITY_NOTE.raw, & SecurityTypeEnums::LIQUIDITY_NOTE },
{ SecurityTypeEnums::MEDIUM_TERM_NOTES.raw, & SecurityTypeEnums::MEDIUM_TERM_NOTES },
{ SecurityTypeEnums::OVERNIGHT.raw, & SecurityTypeEnums::OVERNIGHT },
{ SecurityTypeEnums::PROMISSORY_NOTE.raw, & SecurityTypeEnums::PROMISSORY_NOTE },
{ SecurityTypeEnums::PLAZOS_FIJOS.raw, & SecurityTypeEnums::PLAZOS_FIJOS },
{ SecurityTypeEnums::SHORT_TERM_LOAN_NOTE.raw, & SecurityTypeEnums::SHORT_TERM_LOAN_NOTE },
{ SecurityTypeEnums::TIME_DEPOSIT.raw, & SecurityTypeEnums::TIME_DEPOSIT },
{ SecurityTypeEnums::EXTENDED_COMM_NOTE.raw, & SecurityTypeEnums::EXTENDED_COMM_NOTE },
{ SecurityTypeEnums::YANKEE_CERTIFICATE_OF_DEPOSIT.raw, & SecurityTypeEnums::YANKEE_CERTIFICATE_OF_DEPOSIT },
{ SecurityTypeEnums::ASSET_BACKED_SECURITIES.raw, & SecurityTypeEnums::ASSET_BACKED_SECURITIES },
{ SecurityTypeEnums::CORP_MORTGAGE_BACKED_SECURITIES.raw, & SecurityTypeEnums::CORP_MORTGAGE_BACKED_SECURITIES },
{ SecurityTypeEnums::COLLATERALIZED_MORTGAGE_OBLIGATION.raw, & SecurityTypeEnums::COLLATERALIZED_MORTGAGE_OBLIGATION },
{ SecurityTypeEnums::IOETTE_MORTGAGE.raw, & SecurityTypeEnums::IOETTE_MORTGAGE },
{ SecurityTypeEnums::MORTGAGE_BACKED_SECURITIES.raw, & SecurityTypeEnums::MORTGAGE_BACKED_SECURITIES },
{ SecurityTypeEnums::MORTGAGE_INTEREST_ONLY.raw, & SecurityTypeEnums::MORTGAGE_INTEREST_ONLY },
{ SecurityTypeEnums::MORTGAGE_PRINCIPAL_ONLY.raw, & SecurityTypeEnums::MORTGAGE_PRINCIPAL_ONLY },
{ SecurityTypeEnums::MORTGAGE_PRIVATE_PLACEMENT.raw, & SecurityTypeEnums::MORTGAGE_PRIVATE_PLACEMENT },
{ SecurityTypeEnums::MISCELLANEOUS_PASS_THROUGH.raw, & SecurityTypeEnums::MISCELLANEOUS_PASS_THROUGH },
{ SecurityTypeEnums::PFANDBRIEFE.raw, & SecurityTypeEnums::PFANDBRIEFE },
{ SecurityTypeEnums::TO_BE_ANNOUNCED.raw, & SecurityTypeEnums::TO_BE_ANNOUNCED },
{ SecurityTypeEnums::OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC.raw, & SecurityTypeEnums::OTHER_ANTICIPATION_NOTES_BAN_GAN_ETC },
{ SecurityTypeEnums::CERTIFICATE_OF_OBLIGATION.raw, & SecurityTypeEnums::CERTIFICATE_OF_OBLIGATION },
{ SecurityTypeEnums::CERTIFICATE_OF_PARTICIPATION.raw, & SecurityTypeEnums::CERTIFICATE_OF_PARTICIPATION },
{ SecurityTypeEnums::GENERAL_OBLIGATION_BONDS.raw, & SecurityTypeEnums::GENERAL_OBLIGATION_BONDS },
{ SecurityTypeEnums::MANDATORY_TENDER.raw, & SecurityTypeEnums::MANDATORY_TENDER },
{ SecurityTypeEnums::REVENUE_ANTICIPATION_NOTE.raw, & SecurityTypeEnums::REVENUE_ANTICIPATION_NOTE },
{ SecurityTypeEnums::REVENUE_BONDS.raw, & SecurityTypeEnums::REVENUE_BONDS },
{ SecurityTypeEnums::SPECIAL_ASSESSMENT.raw, & SecurityTypeEnums::SPECIAL_ASSESSMENT },
{ SecurityTypeEnums::SPECIAL_OBLIGATION.raw, & SecurityTypeEnums::SPECIAL_OBLIGATION },
{ SecurityTypeEnums::SPECIAL_TAX.raw, & SecurityTypeEnums::SPECIAL_TAX },
{ SecurityTypeEnums::TAX_ANTICIPATION_NOTE.raw, & SecurityTypeEnums::TAX_ANTICIPATION_NOTE },
{ SecurityTypeEnums::TAX_ALLOCATION.raw, & SecurityTypeEnums::TAX_ALLOCATION },
{ SecurityTypeEnums::TAX_EXEMPT_COMMERCIAL_PAPER.raw, & SecurityTypeEnums::TAX_EXEMPT_COMMERCIAL_PAPER },
{ SecurityTypeEnums::TAX_REVENUE_ANTICIPATION_NOTE.raw, & SecurityTypeEnums::TAX_REVENUE_ANTICIPATION_NOTE },
{ SecurityTypeEnums::VARIABLE_RATE_DEMAND_NOTE.raw, & SecurityTypeEnums::VARIABLE_RATE_DEMAND_NOTE },
{ SecurityTypeEnums::WARRANT.raw, & SecurityTypeEnums::WARRANT },
{ SecurityTypeEnums::MUTUAL_FUND.raw, & SecurityTypeEnums::MUTUAL_FUND },
{ SecurityTypeEnums::MULTI_LEG_INSTRUMENT.raw, & SecurityTypeEnums::MULTI_LEG_INSTRUMENT },
{ SecurityTypeEnums::NO_SECURITY_TYPE.raw, & SecurityTypeEnums::NO_SECURITY_TYPE },
};


// -------------------------------------- init ----------------------------------------
#pragma GCC push_options
#pragma GCC optimize("O0")


int initStatics()
{


  tagNameByRaw.emplace( tag_as_raw<1>(), FixAccount );
  tagNameByValue.emplace( 1, FixAccount );

  tagNameByRaw.emplace( tag_as_raw<6>(), FixAvgPx );
  tagNameByValue.emplace( 6, FixAvgPx );

  tagNameByRaw.emplace( tag_as_raw<8>(), FixBeginString );
  tagNameByValue.emplace( 8, FixBeginString );

  tagNameByRaw.emplace( tag_as_raw<9>(), FixBodyLength );
  tagNameByValue.emplace( 9, FixBodyLength );

  tagNameByRaw.emplace( tag_as_raw<10>(), FixCheckSum );
  tagNameByValue.emplace( 10, FixCheckSum );

  tagNameByRaw.emplace( tag_as_raw<11>(), FixClOrdID );
  tagNameByValue.emplace( 11, FixClOrdID );

  tagNameByRaw.emplace( tag_as_raw<14>(), FixCumQty );
  tagNameByValue.emplace( 14, FixCumQty );

  tagNameByRaw.emplace( tag_as_raw<15>(), FixCurrency );
  tagNameByValue.emplace( 15, FixCurrency );

  tagNameByRaw.emplace( tag_as_raw<17>(), FixExecID );
  tagNameByValue.emplace( 17, FixExecID );

  tagNameByRaw.emplace( tag_as_raw<18>(), FixExecInst );
  tagNameByValue.emplace( 18, FixExecInst );

  tagNameByRaw.emplace( tag_as_raw<31>(), FixLastPx );
  tagNameByValue.emplace( 31, FixLastPx );

  tagNameByRaw.emplace( tag_as_raw<32>(), FixLastQty );
  tagNameByValue.emplace( 32, FixLastQty );

  tagNameByRaw.emplace( tag_as_raw<34>(), FixMsgSeqNum );
  tagNameByValue.emplace( 34, FixMsgSeqNum );

  tagNameByRaw.emplace( tag_as_raw<35>(), FixMsgType );
  tagNameByValue.emplace( 35, FixMsgType );

  tagNameByRaw.emplace( tag_as_raw<37>(), FixOrderID );
  tagNameByValue.emplace( 37, FixOrderID );

  tagNameByRaw.emplace( tag_as_raw<38>(), FixOrderQty );
  tagNameByValue.emplace( 38, FixOrderQty );

  tagNameByRaw.emplace( tag_as_raw<39>(), FixOrdStatus );
  tagNameByValue.emplace( 39, FixOrdStatus );

  tagNameByRaw.emplace( tag_as_raw<40>(), FixOrdType );
  tagNameByValue.emplace( 40, FixOrdType );

  tagNameByRaw.emplace( tag_as_raw<41>(), FixOrigClOrdID );
  tagNameByValue.emplace( 41, FixOrigClOrdID );

  tagNameByRaw.emplace( tag_as_raw<44>(), FixPrice );
  tagNameByValue.emplace( 44, FixPrice );

  tagNameByRaw.emplace( tag_as_raw<48>(), FixSecurityID );
  tagNameByValue.emplace( 48, FixSecurityID );

  tagNameByRaw.emplace( tag_as_raw<49>(), FixSenderCompID );
  tagNameByValue.emplace( 49, FixSenderCompID );

  tagNameByRaw.emplace( tag_as_raw<52>(), FixSendingTime );
  tagNameByValue.emplace( 52, FixSendingTime );

  tagNameByRaw.emplace( tag_as_raw<54>(), FixSide );
  tagNameByValue.emplace( 54, FixSide );

  tagNameByRaw.emplace( tag_as_raw<55>(), FixSymbol );
  tagNameByValue.emplace( 55, FixSymbol );

  tagNameByRaw.emplace( tag_as_raw<56>(), FixTargetCompID );
  tagNameByValue.emplace( 56, FixTargetCompID );

  tagNameByRaw.emplace( tag_as_raw<58>(), FixText );
  tagNameByValue.emplace( 58, FixText );

  tagNameByRaw.emplace( tag_as_raw<59>(), FixTimeInForce );
  tagNameByValue.emplace( 59, FixTimeInForce );

  tagNameByRaw.emplace( tag_as_raw<60>(), FixTransactTime );
  tagNameByValue.emplace( 60, FixTransactTime );

  tagNameByRaw.emplace( tag_as_raw<99>(), FixStopPx );
  tagNameByValue.emplace( 99, FixStopPx );

  tagNameByRaw.emplace( tag_as_raw<103>(), FixOrdRejReason );
  tagNameByValue.emplace( 103, FixOrdRejReason );

  tagNameByRaw.emplace( tag_as_raw<150>(), FixExecType );
  tagNameByValue.emplace( 150, FixExecType );

  tagNameByRaw.emplace( tag_as_raw<151>(), FixLeavesQty );
  tagNameByValue.emplace( 151, FixLeavesQty );

  tagNameByRaw.emplace( tag_as_raw<167>(), FixSecurityType );
  tagNameByValue.emplace( 167, FixSecurityType );

  tagNameByRaw.emplace( tag_as_raw<423>(), FixPriceType );
  tagNameByValue.emplace( 423, FixPriceType );

  tagNameByRaw.emplace( tag_as_raw<460>(), FixProduct );
  tagNameByValue.emplace( 460, FixProduct );

  tagNameByRaw.emplace( tag_as_raw<854>(), FixQtyType );
  tagNameByValue.emplace( 854, FixQtyType );

  tagNameByRaw.emplace( tag_as_raw<555>(), FixNoLegs );
  tagNameByValue.emplace( 555, FixNoLegs );

  tagNameByRaw.emplace( tag_as_raw<564>(), FixLegPositionEffect );
  tagNameByValue.emplace( 564, FixLegPositionEffect );

  tagNameByRaw.emplace( tag_as_raw<566>(), FixLegPrice );
  tagNameByValue.emplace( 566, FixLegPrice );

  tagNameByRaw.emplace( tag_as_raw<600>(), FixLegSymbol );
  tagNameByValue.emplace( 600, FixLegSymbol );

  tagNameByRaw.emplace( tag_as_raw<624>(), FixLegSide );
  tagNameByValue.emplace( 624, FixLegSide );

  tagNameByRaw.emplace( tag_as_raw<637>(), FixLegLastPx );
  tagNameByValue.emplace( 637, FixLegLastPx );

  tagNameByRaw.emplace( tag_as_raw<654>(), FixLegRefID );
  tagNameByValue.emplace( 654, FixLegRefID );

  tagNameByRaw.emplace( tag_as_raw<683>(), FixNoLegStipulations );
  tagNameByValue.emplace( 683, FixNoLegStipulations );

  tagNameByRaw.emplace( tag_as_raw<687>(), FixLegQty );
  tagNameByValue.emplace( 687, FixLegQty );

  tagNameByRaw.emplace( tag_as_raw<688>(), FixLegStipulationType );
  tagNameByValue.emplace( 688, FixLegStipulationType );

  tagNameByRaw.emplace( tag_as_raw<689>(), FixLegStipulationValue );
  tagNameByValue.emplace( 689, FixLegStipulationValue );

  tagNameByRaw.emplace( tag_as_raw<524>(), FixNestedPartyID );
  tagNameByValue.emplace( 524, FixNestedPartyID );

  tagNameByRaw.emplace( tag_as_raw<525>(), FixNestedPartyIDSource );
  tagNameByValue.emplace( 525, FixNestedPartyIDSource );

  tagNameByRaw.emplace( tag_as_raw<538>(), FixNestedPartyRole );
  tagNameByValue.emplace( 538, FixNestedPartyRole );

  tagNameByRaw.emplace( tag_as_raw<539>(), FixNoNestedPartyIDs );
  tagNameByValue.emplace( 539, FixNoNestedPartyIDs );

  tagNameByRaw.emplace( tag_as_raw<545>(), FixNestedPartySubID );
  tagNameByValue.emplace( 545, FixNestedPartySubID );

  tagNameByRaw.emplace( tag_as_raw<804>(), FixNoNestedPartySubIDs );
  tagNameByValue.emplace( 804, FixNoNestedPartySubIDs );

  tagNameByRaw.emplace( tag_as_raw<805>(), FixNestedPartySubIDType );
  tagNameByValue.emplace( 805, FixNestedPartySubIDType );


  FieldQtyType::enumItems = QtyTypeEnums::items;
  enumsByRaw.emplace( FieldQtyType::RAW, & QtyTypeEnums::instance );

  FieldProduct::enumItems = ProductEnums::items;
  enumsByRaw.emplace( FieldProduct::RAW, & ProductEnums::instance );

  FieldMsgType::enumItems = MsgTypeEnums::items;
  enumsByRaw.emplace( FieldMsgType::RAW, & MsgTypeEnums::instance );

  FieldOrdStatus::enumItems = OrdStatusEnums::items;
  enumsByRaw.emplace( FieldOrdStatus::RAW, & OrdStatusEnums::instance );

  FieldOrdType::enumItems = OrdTypeEnums::items;
  enumsByRaw.emplace( FieldOrdType::RAW, & OrdTypeEnums::instance );


  FieldSide::enumItems = SideEnums::items;
  enumsByRaw.emplace( FieldSide::RAW, & SideEnums::instance );

  FieldTimeInForce::enumItems = TimeInForceEnums::items;
  enumsByRaw.emplace( FieldTimeInForce::RAW, & TimeInForceEnums::instance );

  FieldPriceType::enumItems = PriceTypeEnums::items;
  enumsByRaw.emplace( FieldPriceType::RAW, & PriceTypeEnums::instance );

  FieldSecurityType::enumItems = SecurityTypeEnums::items;
  enumsByRaw.emplace( FieldSecurityType::RAW, & SecurityTypeEnums::instance );
  return 1;
}

volatile int initIndicator = initStatics();
#pragma GCC pop_options
