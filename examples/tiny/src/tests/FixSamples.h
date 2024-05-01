#pragma once

// Lazy: definition and declaration in .h

#define I "\001"

#define EXAMPLE_LOGON \
"8=FIX.4.4" I "9=120" I "35=A" I "34=1" I "49=SampleCompID" I "52=20220616-12:06:31.300" I "56=TargetCompID" I "98=0" I "108=30" I "141=Y" I "553=SampleLogin" I "554=SamplePassword" I "10=017" I

#define EXAMPLE_EXEC_REPORT \
"8=FIX.4.4" I "9=156" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I "54=1" I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I "10=216" I

#define EXAMPLE_LARGE_EXEC_REPORT \
"8=FIX.4.4" I "9=332" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I "54=1" I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I  \
"555=2" I "600=SYM1" I "624=0" I "687=10" I "683=1" I  \
                             "688=A" I "689=a" I  \
                             "564=1" I  \
                             "539=2" I "524=PARTY1" I "525=S" I  \
                                   "524=PARTY2" I "525=S" I  \
                                   "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
      "600=SYM2" I "624=1" I "687=20" I "683=2" I  \
                             "688=A" I "689=a" I  \
                             "688=B" I "689=b" I  \
"10=118" I

#define EXAMPLE_MARKETDATA_FULL_REFRESH \
"8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "55=EUR/USD" I \
"268=6" I "269=1" I "290=1" I "270=1.21" I "15=USD" I "271=1000000" I "269=1" I "290=2" I "270=1.211" I "15=USD" I "271=2000000" I "269=1" I "290=3" I "270=1.221" I "15=USD" I "271=3000000" I "269=1" I "290=4" I "270=1.2315" I "15=USD" I "271=4000000" I "269=0" I "290=5" I "270=1.201" I "15=USD" I "271=1000000" I "269=0" I "290=6" I "270=1.205" I "15=USD" I "271=2000000" I "10=173" I

#define EXAMPLE_SECURITY_DEFINITION \
"8=FIX.4.4" I "9=1704" I "35=d" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I \
"320=SECREQ12345" I "55=VERY_LARGE_STRATEGY" I "15=XYZ" I\
"555=16" I \
"600=SYM1" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SYM2" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SYM3" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SYM4" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SYM5" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SYM6" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SYM7" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SYM8" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SYM9" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SY10" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SY11" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SY12" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SY13" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=2" I "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SY14" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"600=SY15" I "624=0" I "687=10" I "683=1" I  \
             "688=A" I "689=a" I  \
             "564=1" I  \
             "539=16" I \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
                       "524=PARTY1" I "525=S" I  \
                       "524=PARTY2" I "525=S" I  \
             "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
"600=SY16" I "624=1" I "687=20" I "683=2" I  \
             "688=A" I "689=a" I  \
             "688=B" I "689=b" I  \
"10=141" I

#define EXAMPLE_ZERO_GROUP_MARKETDATA_FULL_REFRESH \
"8=FIX.4.4" I "9=0090" I "35=W" I "49=server" I "56=client" I "34=0000037" I "52=20240501-06:32:24.884449" I "262=MDR1" I "55=EUR/USD" I "268=0" I "10=232" I

const char * FIX_BUFFER_LOGON                      = EXAMPLE_LOGON;
const char * FIX_BUFFER_EXEC_REPORT                = EXAMPLE_EXEC_REPORT;
const char * FIX_BUFFER_LARGE_EXEC_REPORT          = EXAMPLE_LARGE_EXEC_REPORT;
const char * FIX_BUFFER_MD_FULL_REFRESH            = EXAMPLE_MARKETDATA_FULL_REFRESH;
const char * FIX_BUFFER_SECURITY_DEFINITION        = EXAMPLE_SECURITY_DEFINITION;
const char * FIX_BUFFER_ZERO_GROUP_MD_FULL_REFRESH = EXAMPLE_ZERO_GROUP_MARKETDATA_FULL_REFRESH;
const char * allGoodExamples = EXAMPLE_EXEC_REPORT EXAMPLE_LARGE_EXEC_REPORT EXAMPLE_MARKETDATA_FULL_REFRESH EXAMPLE_SECURITY_DEFINITION EXAMPLE_ZERO_GROUP_MARKETDATA_FULL_REFRESH;

#define BAD_GROUP_EXAMPLE_LARGE_EXEC_REPORT \
"8=FIX.4.4" I "9=332" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I "54=1" I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I  \
"555=2" I \
      "600=SYM1" I "624=0" I "687=10" I "683=1" I  \
                             "688=A" I "689=a" I  \
                             "564=1" I  \
                             "539=1" /* must be 2 */ I "524=PARTY1" I "525=S" I  \
                                   "524=PARTY2" I "525=S" I  \
                                   "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
      "600=SYM2" I "624=1" I "687=20" I "683=2" I  \
                             "688=A" I "689=a" I  \
                             "688=B" I "689=b" I  \
"10=027" I

#define BAD_DEEP_EMPTY_FIELD_EXAMPLE_LARGE_EXEC_REPORT \
"8=FIX.4.4" I "9=331" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I "54=1" I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I  \
"555=2" I \
      "600=SYM1" I "624=0" I "687=10" I "683=1" I  \
                             "688=A" I "689=a" I  \
                             "564=1" I  \
                             "539=2" I "524=PARTY1" I "525=S" I  \
                                   "524=PARTY2" I "525=S" I  \
                                   "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
      "600=SYM2" I "624=1" I "687=20" I "683=2" I  \
                             "688=A" I "689=a" I  \
                             "688=B" I "689=" I  /* empty*/ \
"10=027" I

#define BAD_FIRST_IN_GROUP_EXAMPLE_LARGE_EXEC_REPORT \
"8=FIX.4.4" I "9=332" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I "54=1" I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I  \
"555=2" I "624=0" I /* 600 must be first */ \
          "600=SYM1" I "687=10" I "683=1" I  \
                             "688=A" I "689=a" I  \
                             "564=1" I  \
                             "539=2" I "524=PARTY1" I "525=S" I  \
                                   "524=PARTY2" I "525=S" I  \
                                   "804=2" I "545=S1" I "805=1" I "545=S2" I "805=2" I  \
      "600=SYM2" I "624=1" I "687=20" I "683=2" I  \
                             "688=A" I "689=a" I  \
                             "688=B" I "689=b" I  \
"10=118" I

#define BAD_GROUP_EXAMPLE_MARKETDATA_FULL_REFRESH \
"8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "55=EUR/USD" I \
"268=10" /* must be 6 */ I "269=1" I "290=1" I "270=1.21" I "15=USD" I "271=1000000" I "269=1" I "290=2" I "270=1.211" I "15=USD" I "271=2000000" I "269=1" I "290=3" I "270=1.221" I "15=USD" I "271=3000000" I "269=1" I "290=4" I "270=1.2315" I "15=USD" I "271=4000000" I "269=0" I "290=5" I "270=1.201" I "15=USD" I "271=1000000" I "269=0" I "290=6" I "270=1.205" I "15=USD" I "271=2000000" I "10=075" I

const char * FIX_BUFFER_BAD_GROUP_LARGE_EXEC_REPORT                    = BAD_GROUP_EXAMPLE_LARGE_EXEC_REPORT;
const char * FIX_BUFFER_BAD_GROUP_MD_FULL_REFRESH                      = BAD_GROUP_EXAMPLE_MARKETDATA_FULL_REFRESH;
const char * FIX_BUFFER_BAD_DEEP_EMPTY_FIELD_EXAMPLE_LARGE_EXEC_REPORT = BAD_DEEP_EMPTY_FIELD_EXAMPLE_LARGE_EXEC_REPORT;
const char * FIX_BUFFER_BAD_FIRST_IN_GROUP_EXAMPLE_LARGE_EXEC_REPORT   = BAD_FIRST_IN_GROUP_EXAMPLE_LARGE_EXEC_REPORT;

#define BAD_SENDER_COMP_ID_XX_EXAMPLE_LOGON \
"8=FIX.4.4" I "9=120" I "35=A" I "34=1" I "XX=SenderCompID" I "52=20220616-12:06:31.300" I "56=TargetCompID" I "98=0" I "108=30" I "141=Y" I "553=SampleLogin" I "554=SamplePassword" I "10=175" I

#define BAD_SENDER_COMP_ID_EMPTY_EXAMPLE_LOGON \
"8=FIX.4.4" I "9=108" I "35=A" I "34=1" I "49=" I "52=20220616-12:06:31.300" I "56=TargetCompID" I "98=0" I "108=30" I "141=Y" I "553=SampleLogin" I "554=SamplePassword" I "10=175" I

#define BAD_BODY_LENGTH_EXAMPLE_LOGON \
"8=FIX.4.4" I "9=1000" I "35=A" I "34=1" I "49=SenderCompID" I "52=20220616-12:06:31.300" I "56=TargetCompID" I "98=0" I "108=30" I "141=Y" I "553=SampleLogin" I "554=SamplePassword" I "10=175" I

#define BAD_SEQNO_TWICE_EXAMPLE_LOGON \
"8=FIX.4.4" I "9=200" I "35=A" I "34=1" I "34=2" I "49=SenderCompID" I "52=20220616-12:06:31.300" I "56=TargetCompID" I "10=175" I

const char * FIX_BUFFER_BAD_SENDER_COMP_ID_XX_EXAMPLE_LOGON    = BAD_SENDER_COMP_ID_XX_EXAMPLE_LOGON;
const char * FIX_BUFFER_BAD_SENDER_COMP_ID_EMPTY_EXAMPLE_LOGON = BAD_SENDER_COMP_ID_EMPTY_EXAMPLE_LOGON;
const char * FIX_BUFFER_BAD_BODY_LENGTH_EXAMPLE_LOGON          = BAD_BODY_LENGTH_EXAMPLE_LOGON;
const char * FIX_BUFFER_BAD_SEQNO_TWICE_EXAMPLE_LOGON          = BAD_SEQNO_TWICE_EXAMPLE_LOGON;

#define BAD_SIDE_EXAMPLE_EXEC_REPORT \
"8=FIX.4.4" I "9=156" I "35=8" I "49=foo" I "56=bar" I "52=20071123-05:30:00.000" I "11=OID123456" I "150=E" I "39=A" I "55=XYZ" I "167=CS" I \
 "54=X" /* bad side */ I "38=15" I "40=2" I "44=15.001" I "58=EQUITYTESTING" I "59=0" I "32=0" I "31=0" I "151=15" I "14=0" I "6=0" I "10=216" I

const char * FIX_BUFFER_BAD_SIDE_EXAMPLE_EXEC_REPORT = BAD_SIDE_EXAMPLE_EXEC_REPORT;

const char * TIMESTAMPS[] =
{
    "20190101-01:01:01.000",
    "20220101-21:01:01.123",
    "20210211-14:02:55.456",
    "20190101-01:01:01.000",
    "20220101-21:01:01.123",
    "20210211-14:02:55.456",
    "20190101-01:01:01.000",
    "20220101-21:01:01.123",
    "20210211-14:02:55.456",
    "20190101-01:01:01.000",
    "20220101-21:01:01.123",
    "20210211-14:02:55.456"
};
