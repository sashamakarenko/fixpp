#include <tiny/Messages.h>
#include "FixSamples.h"
#include <cstring>
#include <sstream>

using namespace tiny;

class MyProcessor: public ParserDispatcher
{
    protected:

        virtual void unprocessedMessage( raw_enum_t msgType, MessageBase & msg ) override
        {
            auto it = MsgTypeEnums::itemByRaw.find( msgType );
            const char * typeName = it != MsgTypeEnums::itemByRaw.end() ? it->second->name : "unknown";
            std::cout << "unprocessed " << typeName << " " << msgType << std::endl;
        }

        virtual void onMessage( MessageMarketDataSnapshotFullRefresh & msg ) override
        {
            std::cout << "processed " << getCurrentHeader().getMsgType() << " " << msg.getMessageName() << std::endl;
        }

};

int main( int args, const char ** argv )
{
    const char * buffer = allGoodExamples;

    std::size_t len = std::strlen( buffer );
    const char * cursor = buffer;

    MyProcessor mp;
    while( ( cursor = mp.parseAndDipatch( cursor, len - ( cursor - buffer ) ) ) != nullptr )
    {
    }
    
    std::istringstream source( buffer ); // could be file or socket
    constexpr unsigned begStrAndBodyLenBytes = MESSAGE_BEGIN_MIN_BYTES_TO_READ; // reasonably large initial number of bytes to read
    std::vector<char> recvbuffer( 200 );
    while( source.read( &recvbuffer[0], begStrAndBodyLenBytes ) )
    {
        unsigned msgTypeOffset;
        len = parseMessageLength( &recvbuffer[0], msgTypeOffset ) + CHECKSUM_FIELD_LENGTH;
        if( recvbuffer.size() < len + msgTypeOffset )
        {
            recvbuffer.insert( recvbuffer.end(), len + msgTypeOffset - recvbuffer.size() + 100, 0 );
        }
        // read the remaining bytes
        if( source.read( & recvbuffer[begStrAndBodyLenBytes], len - begStrAndBodyLenBytes + msgTypeOffset ) )
        {
            mp.parseAndDipatch( &recvbuffer[0], len + msgTypeOffset );
        }
        else
        {
            break;
        }
        
    }
    return 0;
}
