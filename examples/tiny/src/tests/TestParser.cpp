#include <tiny/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>

#include <utests/TrivialHelper.h>

using namespace tiny;
using namespace tiny::field;
using namespace tiny::message;

int main( int args, const char ** argv )
{
    Header header;
    offset_t pos, safepos;
    const char * fix;
    auto parse = [&]<typename MSG>( const char * buffer, MSG & msg )
    {
        fix = buffer;
        header.reset();
        pos = header.scan( fix, strlen( fix ) );
        msg.reset();
        pos = msg.scan( fix + pos, strlen( fix ) - pos );
    };

    auto parseSafely = [&]<typename MSG>( const char * buffer, MSG & msg )
    {
        fix = buffer;
        header.reset();
        safepos = header.scanSafely( fix, strlen( fix ) );
        msg.reset();
        safepos = msg.scanSafely( fix + safepos, strlen( fix ) - safepos );
    };

    std::string checkPrettyPrinting( "text to show in debugger" );
    std::cout << "\n\n -- ExecutionReport --" << std::endl;
    ExecutionReport er;
    parse( FIX_BUFFER_EXEC_REPORT, er );
    CHECK_EQ( header length, (ssize_t)header.getMessageLength(), er.ptrToTagClOrdID() - fix )
    const char * badFieldPtr = header.findBadField();
    CHECK( no bad fields in header, badFieldPtr == nullptr, == true )
    CHECK_EQ( exec report length, er.getMessageLength(), size_t(pos) )
    CHECK_NOT_EQ( exec report security type is not brady bod, er.getSecurityType(), SecurityTypeEnums::BRADY_BOND )
    unsigned noExpected = 0, noReceived = 0;
    const char * badGroupPtr = er.findBadGroup( noExpected, noReceived );
    CHECK( no bad group in exec report, badGroupPtr == nullptr, == true )
    CHECK_EQ( exec report order status, er.getOrdStatus(), OrdStatusEnums::PENDING_NEW )
    CHECK_EQ( exec report fix length, header.getMessageLength() + er.getMessageLength(), strlen( fix ) )
    CHECK_EQ( exec report body length, header.getBodyLength(), header.getMessageLength() + er.getMessageLength() - ( header.ptrToTagMsgType() - header.getMessageBuffer() ) - CHECKSUM_FIELD_LENGTH )
    CHECK_EQ( exec report check sum, er.getCheckSum(), (int)computeChecksum( fix, er.ptrToTagCheckSum() ) )

    std::cout << "\n\n -- ExecutionReport (large) --" << std::endl;
    ExecutionReport ler;
    parse( FIX_BUFFER_LARGE_EXEC_REPORT, ler );
    CHECK_EQ( large exec report order status, ler.getOrdStatus(), OrdStatusEnums::PENDING_NEW )
    CHECK_EQ( large exec report fix length, header.getMessageLength() + ler.getMessageLength(), strlen( fix ) )
    CHECK_EQ( large exec report body length, header.getBodyLength(), ler.ptrToTagCheckSum() - header.ptrToTagMsgType() )
    CHECK_EQ( large exec report check sum, ler.getCheckSum(), (int)computeChecksum( fix, ler.ptrToTagCheckSum() ) )
    parseSafely( FIX_BUFFER_LARGE_EXEC_REPORT, ler );
    CHECK_EQ( safely large exec report order status, ler.getOrdStatus(), OrdStatusEnums::PENDING_NEW )
    CHECK_EQ( safely large exec report fix length, header.getMessageLength() + ler.getMessageLength(), strlen( fix ) )
    CHECK_EQ( safely large exec report body length, header.getBodyLength(), ler.ptrToTagCheckSum() - header.ptrToTagMsgType() )
    CHECK_EQ( safely large exec report check sum, ler.getCheckSum(), (int)computeChecksum( fix, ler.ptrToTagCheckSum() ) )

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
    MarketDataSnapshotFullRefresh mdsfr;
    parse( FIX_BUFFER_MD_FULL_REFRESH, mdsfr );
    raw_enum_t msgTypeRaw = toRawEnum( header.ptrToMsgType() );
    auto enumPtr = MsgTypeEnums::findEnum( msgTypeRaw );
    CHECK_NOT_EQ( mdsfr msg type found, enumPtr, nullptr )
    CHECK_EQ( mdsfr msg type, enumPtr->name, MsgTypeEnums::MARKET_DATA_SNAPSHOT_FULL_REFRESH.name )
    CHECK_EQ( mdsfr check sum, mdsfr.getCheckSum(), (int)computeChecksum( fix, mdsfr.ptrToTagCheckSum() ) )
    CHECK_EQ( mdsfr report body length, header.getMessageLength() + mdsfr.getMessageLength(), uint64_t( header.getBodyLength() + ( header.ptrToTagMsgType() - header.getMessageBuffer() ) ) + CHECKSUM_FIELD_LENGTH )

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

    CHECK_EQ( enum raw Side == BUY, SideEnums::BUY.raw, toRawEnum( er.ptrToSide() ) )
    CHECK_EQ( enum Side == BUY, er.getSide(), SideEnums::BUY )
    CHECK_EQ( enum BUY == Side, SideEnums::BUY, er.getSide() )

    std::cout << "\n\n -- Raw iterating --" << std::endl;
    pos = 0;
    fix = FIX_BUFFER_LARGE_EXEC_REPORT;
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
    SecurityDefinition secdef;
    parse( FIX_BUFFER_SECURITY_DEFINITION, secdef );
    msgTypeRaw = toRawEnum( header.ptrToMsgType() );
    enumPtr = MsgTypeEnums::findEnum( msgTypeRaw );
    CHECK_NOT_EQ( secdef msg type found, enumPtr, nullptr )
    CHECK_EQ( secdef msg type, enumPtr->name, MsgTypeEnums::SECURITY_DEFINITION.name )
    CHECK_EQ( secdef check sum, secdef.getCheckSum(), (int)computeChecksum( fix, secdef.ptrToTagCheckSum() ) )
    CHECK_EQ( secdef report body length, header.getMessageLength() + secdef.getMessageLength(), uint64_t( header.getBodyLength() + ( header.ptrToTagMsgType() - header.getMessageBuffer() ) ) + CHECKSUM_FIELD_LENGTH )

    std::cout << fixstr( fix  , ttyRgbStyle ) << std::endl;

    std::cout << "\n\n -- Logon --" << std::endl;
    Logon logon;
    parse( FIX_BUFFER_LOGON, logon );
    CHECK_EQ( logon msg type, header.getMsgType(), MsgTypeEnums::LOGON )
    CHECK_EQ( logon msg type, logon.getResetSeqNumFlag(), true )
    CHECK_EQ( logon check sum, logon.getCheckSum(), (int)computeChecksum( fix, logon.ptrToTagCheckSum() ) )
    CHECK_EQ( logon check sum, logon.getCheckSum(), (int)computeChecksum( fix, fix + strlen( fix ) - CHECKSUM_FIELD_LENGTH ) )
    CHECK_EQ( logon report body length, header.getMessageLength() + logon.getMessageLength(), uint64_t( header.getBodyLength() + ( header.ptrToTagMsgType() - header.getMessageBuffer() ) ) + CHECKSUM_FIELD_LENGTH )

    std::string_view blv = header.getBodyLengthView();
    CHECK( body length view, blv, == "120" )

    parse( FIX_BUFFER_BAD_GROUP_LARGE_EXEC_REPORT, er );
    badGroupPtr = er.findBadGroup( noExpected, noReceived );
    CHECK( bad group exec report, badGroupPtr != nullptr, == true )
    CHECK_EQ( bad group exec report tag, parseTag( badGroupPtr ), field::NoNestedPartyIDs::TAG )
    CHECK_EQ( bad group exec report expected, noExpected, 1 )
    CHECK_EQ( bad group exec report received, noReceived, 2 )

    parse( FIX_BUFFER_BAD_GROUP_MD_FULL_REFRESH, mdsfr );
    badGroupPtr = mdsfr.findBadGroup( noExpected, noReceived );
    CHECK( bad group md full refresh, badGroupPtr != nullptr, == true )
    CHECK_EQ( bad group md full refresh tag, parseTag( badGroupPtr ), field::NoMDEntries::TAG )
    CHECK_EQ( bad group md full refresh expected, noExpected, 10 )
    CHECK_EQ( bad group md full refresh received, noReceived, 6 )
    parseSafely( FIX_BUFFER_BAD_GROUP_MD_FULL_REFRESH, mdsfr );

    parse( FIX_BUFFER_BAD_SIDE_EXAMPLE_EXEC_REPORT, er );
    badFieldPtr = er.findBadEnum();
    CHECK( bad enum in exec report, badFieldPtr != nullptr, == true )
    CHECK_EQ( bad enum field report tag, parseTag( badFieldPtr ), field::Side::TAG )

    fix = FIX_BUFFER_BAD_SENDER_COMP_ID_XX_EXAMPLE_LOGON;
    header.reset();
    pos = header.scan( fix, strlen( fix ) );
    CHECK( bad tag XX in sender comp id, header.getMessageLength(), < 40 )

    fix = FIX_BUFFER_BAD_SENDER_COMP_ID_EMPTY_EXAMPLE_LOGON;
    header.reset();
    pos = header.scan( fix, strlen( fix ) );
    badFieldPtr = header.findBadField();
    CHECK( empty sender comp id, badFieldPtr != nullptr, == true )
    CHECK_EQ( empty sender comp id tag, parseTag( badFieldPtr ), field::SenderCompID::TAG )

    parse( FIX_BUFFER_BAD_BODY_LENGTH_EXAMPLE_LOGON, logon );
    CHECK( logon message length, strlen( FIX_BUFFER_BAD_BODY_LENGTH_EXAMPLE_LOGON ), == header.getMessageLength() + logon.getMessageLength() )
    CHECK( bad body length in logon, header.getMessageLength() + logon.getMessageLength(), < header.getBodyLength() )

    fix = "8=FIX.4.4" I I "9=1000" I "35=A" I;
    header.reset();
    pos = header.scan( fix, 100 );
    CHECK_EQ( mal formatted | |, header.getMessageLength(), 10 )

    fix = "8=FIX.4.4" "9=1000" I "35=A" I;
    header.reset();
    pos = header.scan( fix, 100 );
    CHECK_EQ( mal formatted 8=FIX.4.49=, header.isSetBodyLength(), false )

    fix = "=FIX.4.4" I "9=1000" I "35=A" I;
    header.reset();
    pos = header.scan( fix, 100 );
    CHECK_EQ( mal formatted =FIX.4.4, header.getMessageLength(), 0 )

    fix = "8=FIX.4.4" I "9=" I "35=A" I;
    header.reset();
    pos = header.scan( fix, 100 );
    CHECK_EQ( mal formatted 9=, header.getBodyLength(), 0 )

    return 0;
}
