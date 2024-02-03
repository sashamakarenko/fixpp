#include <tiny/Fields.h>
#include "FixSamples.h"
#include <iostream>

using namespace tiny;

void printBuffer( const char * begin, const char * end = nullptr )
{
    for( Iterator it( begin, end ); it.hasNext(); it.next() )
    {
        raw_tag_t rtag = it.getRawTag();
        if( rtag )
        {
            const auto & field = RAW_TAG_TO_NAME.find( rtag );
            if( field != RAW_TAG_TO_NAME.end() )
            {
                std::cout << field->second << " = " << sohstr( it.getValuePtr() ) << "\n";
            }
            else
            {
                break;
            }
        }
    }
}

int main( int args, const char ** argv )
{
    std::cout << "\n\n -- Good --" << std::endl;
    printBuffer( EXAMPLE_EXEC_REPORT );

    std::cout << "\n\n -- Truncated --" << std::endl;
    printBuffer( EXAMPLE_EXEC_REPORT, EXAMPLE_EXEC_REPORT + 40 );

    std::cout << "\n\n -- Wrong start --" << std::endl;
    printBuffer( EXAMPLE_EXEC_REPORT + 1 );
    printBuffer( EXAMPLE_EXEC_REPORT + 2 );
    printBuffer( EXAMPLE_EXEC_REPORT + 3 );

    return 0;
}
