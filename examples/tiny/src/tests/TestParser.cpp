#include <tiny/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>

#include "Helper.h"

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    std::string checkPrettyPrinting( "text to show in debugger" );
    std::cout << "\n\n -- ExecutionReport --" << std::endl;
    Header header;
    offset_t pos = header.scan( FIX_BUFFER_EXEC_REPORT, strlen( FIX_BUFFER_EXEC_REPORT ) );
    ExecutionReport er;
    pos = er.scan( FIX_BUFFER_EXEC_REPORT + pos, strlen( FIX_BUFFER_EXEC_REPORT ) - pos );
    std::cout << ' ' << FixOrdStatus << " = " << er.getOrdStatus() << " " << computeChecksum( FIX_BUFFER_EXEC_REPORT, er.ptrToCheckSum() )
              << " body length " <<  ( er.ptrToCheckSum() - header.ptrToMsgType() ) << std::endl;

    std::cout << "\n\n -- ExecutionReport (large) --" << std::endl;
    header.reset();
    pos = header.scan( FIX_BUFFER_LARGE_EXEC_REPORT, strlen( FIX_BUFFER_LARGE_EXEC_REPORT ) );
    ExecutionReport ler;
    pos = ler.scan( FIX_BUFFER_LARGE_EXEC_REPORT + pos, strlen( FIX_BUFFER_LARGE_EXEC_REPORT ) - pos );
    std::cout << ' ' << FixOrdStatus << " = " << ler.getOrdStatus() << " " << computeChecksum( FIX_BUFFER_LARGE_EXEC_REPORT, ler.ptrToCheckSum() )
              << " body length " <<  ( ler.ptrToCheckSum() - header.getIfSetMsgType() ) << std::endl;

    std::cout << "- Price as double: " << ler.getPrice() << std::endl;

    for( auto tag : ExecutionReport::getKnownFields() )
    {
        const char * value = ler.getFieldValue( tag );
        if( value )
        {
            std::cout << TAG_TO_NAME.at( tag ) << " is " << sohstr( value );
            const char * enumName = getEnumName( ler.getMessageBuffer(), value - ler.getMessageBuffer() );
            if( enumName ) std::cout << " " << enumName;
            std::cout << "\n";
        }
    }

    if( ler.isSetNoLegs() )
    {
        for( unsigned legIdx = 0 ; legIdx < ler.getNoLegs(); ++legIdx )
        {
            const GroupLegs & leg = ler.getGroupLegs( legIdx );
            for( auto tag : GroupLegs::getKnownFields() )
            {
                const char * value = leg.getFieldValue( tag );
                if( value )
                {
                    std::cout << TAG_TO_NAME.at( tag ) << " is " << sohstr( value );
                    const char * enumName = getEnumName( leg.getMessageBuffer(), value - leg.getMessageBuffer() );
                    if( enumName ) std::cout << " " << enumName;
                    std::cout << "\n";
                }
            }
        }
    }

    std::cout << "\n\n -- MarketDataSnapshotFullRefresh --" << std::endl;
    header.reset();
    pos = header.scan( FIX_BUFFER_MD_FULL_REFRESH, strlen( FIX_BUFFER_MD_FULL_REFRESH ) );
    MarketDataSnapshotFullRefresh mdsfr;
    pos = mdsfr.scan( FIX_BUFFER_MD_FULL_REFRESH + pos, strlen( FIX_BUFFER_MD_FULL_REFRESH ) - pos );

    raw_enum_t msgTypeRaw = toRawEnum( header.ptrToMsgType() );
    auto enumPtr = MsgTypeEnums::findEnum( msgTypeRaw );
    if( enumPtr )
    {
        std::cout << " MsgType = " << enumPtr->name << std::endl;
    }
    std::cout << " sizeof(MessageMarketDataSnapshotFullRefresh)=" << sizeof(mdsfr) << " BodyLength=" << header.getBodyLength() << " SendingTime=" << header.getSendingTime()
              << " " << computeChecksum( FIX_BUFFER_MD_FULL_REFRESH, mdsfr.ptrToCheckSum() )
              << " body length " <<  ( mdsfr.ptrToCheckSum() - header.ptrToMsgType() ) << std::endl;

    switch ( msgTypeRaw )
    {
        case MsgTypeRaw_EXECUTION_REPORT:
            break;

        case MsgTypeRaw_MARKET_DATA_SNAPSHOT_FULL_REFRESH:
            std::cout << " msgTypeRaw = MARKET_DATA_SNAPSHOT_FULL_REFRESH" << std::endl;
            break;

        default:
            break;
    }

    if( SideEnums::BUY.raw == toRawEnum( er.ptrToSide() ) )
    {
        std::cout << " Side=BUY" << std::endl;
    }

    std::cout << "\n\n -- Raw iterating --" << std::endl;
    pos = 0;
    const char * fix = FIX_BUFFER_LARGE_EXEC_REPORT;
    while( fix[pos] )
    {
        raw_tag_t raw = loadRawTag( fix+pos, pos );
        const char * tagName = RAW_TAG_TO_NAME.at( raw );
        std::cout << tagName << " = " << sohstr( fix+pos ) << "\n";
        gotoNextField(fix,pos);
        if( raw == FieldCheckSum::RAW_TAG ) break;
    }

    std::cout << "\n\n -- Pretty Printing --" << std::endl;
    std::cout << fixstr( FIX_BUFFER_EXEC_REPORT      , ttyRgbStyle ) << std::endl;
    std::cout << fixstr( FIX_BUFFER_LARGE_EXEC_REPORT, ttyRgbStyle ) << std::endl;
    std::cout << fixstr( FIX_BUFFER_MD_FULL_REFRESH  , ttyRgbStyle ) << std::endl;

    std::cout << "\n\n -- SecurityDefinition --" << std::endl;
    fix = FIX_BUFFER_SECURITY_DEFINITION;
    header.reset();
    pos = header.scan( fix, strlen( fix ) );
    SecurityDefinition secdef;
    pos = secdef.scan( fix + pos, strlen( fix ) - pos );

    msgTypeRaw = toRawEnum( header.ptrToMsgType() );
    enumPtr = MsgTypeEnums::findEnum( msgTypeRaw );
    if( enumPtr )
    {
        std::cout << " MsgType = " << enumPtr->name << std::endl;
    }
    std::cout << "BodyLength=" << header.getBodyLength()
              << " " << computeChecksum( fix, secdef.ptrToCheckSum() )
              << " body length " <<  ( secdef.ptrToCheckSum() - header.ptrToMsgType() ) << std::endl;

    std::cout << fixstr( fix  , ttyRgbStyle ) << std::endl;

    std::cout << "\n\n -- Logon --" << std::endl;
    header.reset();
    fix = FIX_BUFFER_LOGON;
    pos = header.scan( fix, strlen( fix ) );
    Logon logon;
    pos = logon.scan( fix + pos, strlen( fix ) - pos );

    std::cout << "BodyLength=" << header.getBodyLength()
              << " ResetSeqNumFlag " << logon.getResetSeqNumFlag()
              << " checksum " << computeChecksum( fix, logon.ptrToCheckSum() )
              << " body length " <<  ( logon.ptrToCheckSum() - header.ptrToMsgType() )
              << " strlen " <<  strlen( fix )
              << std::endl;

    std::string_view blv = header.getBodyLengthView();
    CHECK( body length view, blv, == "120" )

    return 0;
}
