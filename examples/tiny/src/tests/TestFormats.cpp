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
        raw_tag_t tag = loadRawTag( fix+pos, pos );

        if( tag == 0 )
        {
            os << style.unknownStart << "[bad tag at " << pos << "]" << style.unknownStop << style.messageEnd;
            return os;
        }

        auto it = RAW_TAG_TO_NAME.find( tag );
        const FieldEnumsBase * enums = nullptr;
        if( it != RAW_TAG_TO_NAME.end() )
        {
            uwidth += strlen( it->second );
            upperLine << style.tagNameStart << it->second << style.tagNameStop;

            auto eit = RAW_TO_ENUM.find( tag );
            if( eit != RAW_TO_ENUM.end() )
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
        if( tag == FieldCheckSum::RAW_TAG )
        {
            break;
        }

    }
    os << upperLine.str() << "\n";
    os << lowerLine.str() << "\n";
    return os;
}

std::ostream & fixToFlatJson( const char * fix, offset_t & pos, std::ostream & os, 
                              const char * tagKey, const char * valueKey, const char * nameKey = nullptr, 
                              const char * enumKey = nullptr, const char * typeKey = nullptr )
{
    os << '[';

    while( fix[pos] )
    {
        offset_t prev = pos;
        const raw_tag_t tag = loadRawTag( fix+pos, pos );

        os << "{\"" << tagKey << "\":";
        while( fix[prev] != '=' )
        {
            os << fix[prev++];
        }
        os << ",";
        if( nameKey )
        {
            os << "\"" << nameKey << "\":\"";
            auto it = RAW_TAG_TO_NAME.find( tag );
            if( it != RAW_TAG_TO_NAME.end() )
            {
                os << it->second;
            }
            os << "\",";
        }
        if( typeKey )
        {
            os << "\"" << typeKey << "\":\"";
            auto it = TAG_TO_FIELD_TYPE_NAME.find( raw_to_tag(tag) );
            if( it != TAG_TO_FIELD_TYPE_NAME.end() )
            {
                os << it->second;
            }
            os << "\",";
        }

        raw_enum_t rawEnum = toRawEnum( fix + pos );
        os << "\"" << valueKey << "\":\"";
        while( fix[pos] and fix[pos] != FIXPP_SOH )
        {
            os << fix[pos++];
        }
        os << "\"";

        if( enumKey )
        {
            auto it = RAW_TO_ENUM.find( tag );
            if( it != RAW_TO_ENUM.end() )
            {
                os << ",\"" << enumKey << "\":\"";
                const char * enumName = it->second->getEnumNameByRaw( rawEnum );
                if( enumName )
                {
                    os << enumName;
                }
                else
                {
                    os << "UNKNOWN";
                }
                os << "\"";
            }
        }
        os << '}';

        ++pos;
        if( tag == FieldCheckSum::RAW_TAG )
        {
            break;
        }
        os << ',';
    }
    os << ']';
    return os;
}

const FixFormatStyle htmlRgbStyle =
{
    .messageBegin =       "<pre>",
    .messageEnd =         "</pre>",
    .indent =             "  ",
    .groupFirstField =    " &#x2022;",
    .fieldBegin =         " ",
    .fieldEnd =           "\n",
    .headerTagNameStart = "<font color=\"#444444\">",
    .headerTagNameStop =  "</font>",
    .tagNameStart =       "<font color=\"black\"><b>",
    .tagNameStop =        "</b></font>",
    .tagValueStart =      "<font color=\"grey\">(",
    .tagValueStop =       ")</font>",
    .equal =              " = ",
    .valueStart =         "<font color=\"darkblue\">",
    .valueStop =          "</font>",
    .enumStart =          " <font color=\"darkgreen\">",
    .enumStop =           "</font>",
    .unknownStart =       "<font color=\"red\">",
    .unknownStop =        "</font>"
};

const FixFormatStyle htmlTableRgbStyle =
{
    .messageBegin       = "<pre><table>",
    .messageEnd         = "</table></pre>",
    .indent             = "&nbsp;&nbsp;",
    .groupFirstField    = "&nbsp;&#x2022;",
    .fieldBegin         = "<tr><td>",
    .fieldEnd           = "</td></tr>\n",
    .headerTagNameStart = "<font color=\"#444444\">",
    .headerTagNameStop  = "</font>",
    .tagNameStart       = "<font color=\"black\"><b>",
    .tagNameStop        = "</b></font>",
    .tagValueStart      = "<font color=\"grey\">(",
    .tagValueStop       = ")</font>",
    .equal              = " </td><td> ",
    .valueStart         = "<font color=\"darkblue\">",
    .valueStop          = "</font>",
    .enumStart          = " <font color=\"darkgreen\">" ,
    .enumStop           = "</font>",
    .unknownStart       = "<font color=\"red\">",
    .unknownStop        = "</font>"
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

    pos = 0;
    fixToFlatJson( FIX_BUFFER_EXEC_REPORT, pos, std::cout, "field", "value" ) << '\n' << std::endl;

    pos = 0;
    fixToFlatJson( FIX_BUFFER_EXEC_REPORT, pos, std::cout, "f", "v", "n", "e", "t" ) << '\n' << std::endl;

    std::cout << fixstr( FIX_BUFFER_LOGON_WITH_RAWDATA, ttyRgbStyle ) << std::endl;

    return 0;
}
