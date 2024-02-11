#include <odd/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>
#include <fstream>

using namespace odd;

int main( int args, const char ** argv )
{
    
    std::cout << "\n\n -- MessageExecutionReport --" << std::endl;
    MessageHeader header;
    offset_t pos = header.scan( FIX_BUFFER_EXEC_REPORT, strlen( FIX_BUFFER_EXEC_REPORT ) );
    MessageExecutionReport er;
    pos = er.scan( FIX_BUFFER_EXEC_REPORT + pos, strlen( FIX_BUFFER_EXEC_REPORT ) - pos );
    std::cout << ' ' << FixOrdStatus << " = " << er.getOrdStatus() << " " << computeChecksum( FIX_BUFFER_EXEC_REPORT, er.ptrToCheckSum() ) 
              << " body length " <<  ( er.ptrToCheckSum() - header.ptrToMsgType() ) << std::endl;
    
    std::cout << "\n\n -- MessageExecutionReport (large) --" << std::endl;
    header.reset();
    pos = header.scan( FIX_BUFFER_LARGE_EXEC_REPORT, strlen( FIX_BUFFER_LARGE_EXEC_REPORT ) );
    MessageExecutionReport ler;
    pos = ler.scan( FIX_BUFFER_LARGE_EXEC_REPORT + pos, strlen( FIX_BUFFER_LARGE_EXEC_REPORT ) - pos );
    std::cout << ' ' << FixOrdStatus << " = " << ler.getOrdStatus() << " " << computeChecksum( FIX_BUFFER_LARGE_EXEC_REPORT, ler.ptrToCheckSum() ) 
              << " body length " <<  ( ler.ptrToCheckSum() - header.ptrToMsgType() ) << std::endl;
    
    for( auto tag : MessageExecutionReport::getKnownFields() )
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

    std::cout << "\n\n -- Raw iterating --" << std::endl;
    pos = 0;
    const char * fix = FIX_BUFFER_LARGE_EXEC_REPORT;
    while( fix[pos] )
    {
        raw_tag_t raw = loadRawTag( fix+pos, pos );
        auto it = RAW_TAG_TO_NAME.find( raw );
        const char * tagName = it != RAW_TAG_TO_NAME.end() ? it->second : "Unknown";
        std::cout << tagName << " = " << sohstr( fix+pos ) << "\n";
        gotoNextField(fix,pos);
        if( raw == FieldCheckSum::RAW_TAG ) break;
    }

    std::cout << "\n\n -- Pretty Printing --" << std::endl;
    
    std::cout << fixstr( FIX_BUFFER_EXEC_REPORT      , ttyRgbStyle ) << std::endl;
    std::cout << fixstr( FIX_BUFFER_LARGE_EXEC_REPORT, ttyRgbStyle ) << std::endl;
    std::cout << fixstr( FIX_BUFFER_MD_FULL_REFRESH  , ttyRgbStyle ) << std::endl;

    return 0;
}
