#include <tiny/Messages.h>
#include "FixSamples.h"
#include <pe/Measurement.h>
#include <cstring>
#include <sstream>
#include <memory>

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

    std::cout << "\n - - - - - - - - - -  ExecutionReport: Parse and dispatch   - - - - - - - - - -\n";
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

    std::cout << "\n - - - - - - - - - -  ExecutionReport: Reset and scan   - - - - - - - - - -\n";
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

    std::cout << "\n - - - - - - - - - -  ExecutionReport: Pure scan   - - - - - - - - - -\n";
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

    buffer = EXAMPLE_LARGE_EXEC_REPORT;
    len = std::strlen( buffer );
    std::cout << "\n - - - - - - - - - -  Large ExecutionReport: Pure scan   - - - - - - - - - -\n";
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

    MessageMarketDataSnapshotFullRefresh mdsfr;
    buffer = EXAMPLE_MARKETDATA_FULL_REFRESH;
    len = std::strlen( buffer );
    std::cout << "\n - - - - - - - - - -  MarketDataSnapshotFullRefresh: Pure scan   - - - - - - - - - -\n";
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        offset_t pos = header.scan( buffer, len );
        pos = mdsfr.scan( buffer + pos, len - pos );
        m.stopCapture();
        header.reset();
        mdsfr.reset();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    MessageSecurityDefinition secdef;
    buffer = EXAMPLE_SECURITY_DEFINITION;
    len = std::strlen( buffer );
    std::cout << "\n - - - - - - - - - -  MessageSecurityDefinition: Pure scan   - - - - - - - - - -\n";
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        offset_t pos = header.scan( buffer, len );
        pos = secdef.scan( buffer + pos, len - pos );
        m.stopCapture();
        header.reset();
        secdef.reset();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    std::cout << "\n - - - - - - - - - -   parseYYYYMMDD(y,m,d)  - - - - - - - - - -\n";
    std::unique_ptr<unsigned> yyyy = std::make_unique<unsigned>(1);
    std::unique_ptr<unsigned> mm   = std::make_unique<unsigned>(2);
    std::unique_ptr<unsigned> dd   = std::make_unique<unsigned>(3);
    for( int j = 0; j < 100000000; ++j ) { (*yyyy) *= unsigned(1.2*(double)(*mm)); }
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        parseYYYYMMDD( TIMESTAMPS[j], *yyyy, *mm, *dd );
        m.stopCapture();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    std::cout << "\n - - - - - - - - - -   parseYYYYMMDD  - - - - - - - - - -\n";
    std::unique_ptr<unsigned> ymd = std::make_unique<unsigned>();
    for( int j = 0; j < 10; ++j )
    {
        m.startCapture();
        *ymd = parseYYYYMMDD( TIMESTAMPS[j] );
        m.stopCapture();
    }
    m.prepareResults();
    m.printCaptures();
    m.showAverageValues( std::cout );
    m.rewind();

    return 0;
}
