#include <tiny/Messages.h>
#include "FixSamples.h"
#include <pe/Measurement.h>
#include <cstring>
#include <sstream>

using namespace tiny;

class MyProcessor: public ParserDispatcher
{
    protected:

        virtual void unprocessedMessage( raw_enum_t msgType, MessageBase & msg ) override
        {
        }

        virtual void onMessage( MessageMarketDataSnapshotFullRefresh & msg ) override
        {
        }

};

#define REPEAT10(X) X X X X X X X X X X
#define REPEAT100(X) REPEAT10(REPEAT10(X))

const char * execReports100 = REPEAT10( EXAMPLE_EXEC_REPORT );

int main( int args, const char ** argv )
{
    pe::Measurement m;
    m.pinToCpuCore( 3 );
    m.addEvent( pe::EventType::cpuCycles );
    m.addEvent( pe::EventType::hwInstructions );
    m.addEvent( pe::EventType::branchInstructions );
    m.addEvent( pe::EventType::llCacheReadMisses );
    m.addEvent( pe::EventType::branchMisses );
    m.addEvent( pe::EventType::memory );
    m.initialize( 100 );
    
    const char * buffer = execReports100;

    std::size_t len = std::strlen( buffer );
    MyProcessor mp;

    std::cout << "\n - - - - - - - - - -  Parse and dispatch   - - - - - - - - - -\n";
    for( int iter = 0; iter < 2; ++iter )
    {
        const char * cursor = buffer;
        for( int j = 0; j < 10; ++j )
        {
            m.startCapture();
            cursor = mp.parseAndDipatch( cursor, len - ( cursor - buffer ) );
            m.stopCapture();
        }
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    MessageHeader header;
    MessageExecutionReport er;

    std::cout << "\n - - - - - - - - - -  Reset and scan   - - - - - - - - - -\n";
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        header.reset();
        er.reset();
        offset_t pos = header.scan( buffer, len );
        pos = er.scan( buffer + pos, len - pos );
        m.stopCapture();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    std::cout << "\n - - - - - - - - - -  Pure scan   - - - - - - - - - -\n";
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        offset_t pos = header.scan( buffer, len );
        pos = er.scan( buffer + pos, len - pos );
        m.stopCapture();
        header.reset();
        er.reset();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    return 0;
}
