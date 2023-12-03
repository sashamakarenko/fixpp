#include <tiny/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace tiny;

/* experimenting 2-line output
ClOrdID      ExecType OrdStatus        Symbol SecurityType        Side     OrderQty OrdType    Price     Text             TimeInForce LastQty LastPx LeavesQty CumQty AvgPx CheckSum
11=OID123456 150=E    39=A PENDING_NEW 55=XYZ 167=CS COMMON_STOCK 54=1 BUY 38=15    40=2 LIMIT 44=15.001 58=EQUITYTESTING 59=0 DAY    32=0    31=0   151=15    14=0   6=0   10=118
*/
std::ostream & fixToTwoLines( const char * fix, offset_t & pos, std::ostream & os, const FixFormatStyle & style )
{
    MessageHeader header;
    offset_t headerLength = header.scan( fix + pos, strlen( fix + pos ) );
    pos += headerLength;

    std::stringstream upperLine, lowerLine;

    while( fix[pos] )
    {
        unsigned uwidth = 0, lwidth = 0;
        offset_t prev = pos;
        raw_tag_t tag = nextRawTag( fix+pos, pos );

        if( tag == 0 )
        {
            os << style.unknownStart << "[bad tag at " << pos << "]" << style.unknownStop << style.messageEnd;
            return os;
        }

        auto it = rawToTagName.find( tag );
        const FieldEnumsBase * enums = nullptr;
        if( it != rawToTagName.end() )
        {
            uwidth += strlen( it->second );
            upperLine << style.tagNameStart << it->second << style.tagNameStop;

            auto eit = rawToEnum.find( tag );
            if( eit != rawToEnum.end() )
            {
                enums = eit->second;
            }
        }
        else
        {
            uwidth += 7;
            upperLine << style.unknownStart << "Unknown" << style.unknownStop;
        }

        // tag
        lowerLine << style.tagValueStart;
        while( fix[prev] != '=' )
        {
            lowerLine << fix[prev++];
            lwidth++;
        }
        lowerLine << style.tagValueStop << style.equal << style.valueStart;
        lwidth += strlen( style.equal );

        raw_enum_t rawEnum = toRawEnum( fix + pos );

        // value as is
        while( fix[pos] && fix[pos] != FIXPP_SOH)
        {
            lowerLine << fix[pos++];
            lwidth++;
        }

        lowerLine << style.valueStop;

        // enum
        if( enums )
        {
            const char * enumName = enums->getEnumNameByRaw( rawEnum );
            if( enumName )
            {
                lowerLine << style.enumStart << enumName << style.enumStop;
                lwidth += strlen( enumName ) + 1;
            }
            else
            {
                lowerLine << style.unknownStart << " UNKNOWN" << style.unknownStop;
                lwidth += 8;
            }
        }

        while( lwidth < uwidth )
        {
            lowerLine << ' ';
            ++lwidth;
        }
        while( uwidth < lwidth )
        {
            upperLine << ' ';
            ++uwidth;
        }
        upperLine << ' ';
        lowerLine << ' ';

        ++pos;
        if( tag == FieldCheckSum::RAW )
        {
            break;
        }

    }
    os << upperLine.str() << "\n";
    os << lowerLine.str() << "\n";
    return os;
}


const FixFormatStyle htmlRgbStyle =
{
    "<pre>",  //  messageBegin
    "</pre>",  //  messageEnd
    "  ",//  indent
    " &#x2022;",//  groupFirstField;
    " ", //  fieldBegin
    "\n",//  fieldEnd
    "<font color=\"#444444\">",  //  headerTagNameStart
    "</font>",  //  headerTagNameStop
    "<font color=\"black\"><b>",  //  tagNameStart
    "</b></font>",  //  tagNameStop
    "<font color=\"grey\">(", //  tagValueStart
    ")</font>", //  tagValueStop
    " = ", //  equal
    "<font color=\"darkblue\">",  //  valueStart
    "</font>",  //  valueStop
    " <font color=\"darkgreen\">", //  enumStart
    "</font>",  //  enumStop
    "<font color=\"red\">",  //  unknownStart
    "</font>"      //  unknownStop
};

const FixFormatStyle htmlTableRgbStyle =
{
    "<pre><table>",  //  messageBegin
    "</table></pre>",  //  messageEnd
    "&nbsp;&nbsp;",//  indent
    "&nbsp;&#x2022;",//  groupFirstField;
    "<tr><td>", //  fieldBegin
    "</td></tr>\n",//  fieldEnd
    "<font color=\"#444444\">",  //  headerTagNameStart
    "</font>",  //  headerTagNameStop
    "<font color=\"black\"><b>",  //  tagNameStart
    "</b></font>",  //  tagNameStop
    "<font color=\"grey\">(", //  tagValueStart
    ")</font>", //  tagValueStop
    " </td><td> ", //  equal
    "<font color=\"darkblue\">",  //  valueStart
    "</font>",  //  valueStop
    " <font color=\"darkgreen\">", //  enumStart
    "</font>",  //  enumStop
    "<font color=\"red\">",  //  unknownStart
    "</font>"      //  unknownStop
};

int main( int args, const char ** argv )
{
    FixFormatStyle style = ttyRgbStyle;
    style.fieldBegin = "| ";
    style.fieldEnd   = " ";
    style.messageEnd = "|";

    std::cout << fixstr( FIX_BUFFER_MD_FULL_REFRESH, style ) << std::endl;
    std::cout.flush();

    FixFormatStyle twoLineRgb = ttyRgbStyle;
    twoLineRgb.tagValueStart = "";
    twoLineRgb.tagValueStop  = "";
    twoLineRgb.equal  = "=";
    offset_t pos = 0;
    std::cout << std::endl;
    fixToTwoLines( FIX_BUFFER_EXEC_REPORT, pos, std::cout, twoLineRgb ) << std::endl;

    pos = 0;
    std::cout << std::endl;
    fixToTwoLines( FIX_BUFFER_MD_FULL_REFRESH, pos, std::cout, twoLineRgb ) << std::endl;

    std::cout << fixstr( FIX_BUFFER_LOGON, ttyRgbStyle ) << std::endl;

    std::cout << fixstr( FIX_BUFFER_MD_FULL_REFRESH, ttyRgbStyle ) << std::endl;

    std::cout << fixstr( FIX_BUFFER_EXEC_REPORT, ttyRgbSingleLineStyle ) << "\n" << std::endl;
    FixFormatStyle namelessStyle = ttyRgbSingleLineStyle;
    namelessStyle.tagNameStart = nullptr;
    namelessStyle.headerTagNameStart = nullptr;
    namelessStyle.enumStart = nullptr;
    namelessStyle.tagValueStart = "";
    namelessStyle.tagValueStop = "";
    namelessStyle.fieldEnd = " ";
    namelessStyle.tagValueStart = "\e[37;1m";
    namelessStyle.tagValueStop = "\e[0m";
    std::cout << fixstr( FIX_BUFFER_EXEC_REPORT, namelessStyle ) << "\n" << std::endl;

    std::ofstream html;
    html.open( "mdfr.html" );
    html << fixstr( FIX_BUFFER_MD_FULL_REFRESH, htmlRgbStyle ) << std::endl;
    html << fixstr( FIX_BUFFER_LARGE_EXEC_REPORT, htmlTableRgbStyle ) << std::endl;
    html.close();
    html << fixstr( FIX_BUFFER_LARGE_EXEC_REPORT, ttyRgbRawStyle ) << std::endl;

    return 0;
}
