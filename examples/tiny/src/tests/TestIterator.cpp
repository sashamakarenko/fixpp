#include <utests/TrivialHelper.h>
#include <tiny/Fields.h>
#include "FixSamples.h"
#include <iostream>

using namespace tiny;

unsigned printBuffer( const char * begin, const char * end = nullptr )
{
    unsigned fieldCount = 0;
    for( Iterator it( begin, end ); it.hasNext(); it.next() )
    {
        raw_tag_t rtag = it.getRawTag();
        if( rtag )
        {
            const auto & field = RAW_TAG_TO_NAME.find( rtag );
            if( field != RAW_TAG_TO_NAME.end() )
            {
                std::cout << field->second << " = " << sohstr( it.getValuePtr() ) << "\n";
                ++fieldCount;
            }
            else
            {
                break;
            }
        }
    }
    return fieldCount;
}

int main( int args, const char ** argv )
{
    HIGHLIGHT( Good );
    unsigned fieldCount = printBuffer( EXAMPLE_EXEC_REPORT );
    CHECK_NOT_EQ( exec report fields, fieldCount, 0 )
    
    HIGHLIGHT( Truncated );
    fieldCount = printBuffer( EXAMPLE_EXEC_REPORT, EXAMPLE_EXEC_REPORT + 40 );
    CHECK_NOT_EQ( truncated fields, fieldCount, 0 )
    
    HIGHLIGHT( Wrong start );
    fieldCount = printBuffer( EXAMPLE_EXEC_REPORT + 1 );
    CHECK_EQ( start + 1 fields, fieldCount, 0 )
    fieldCount = printBuffer( EXAMPLE_EXEC_REPORT + 2 );
    CHECK_EQ( start + 2 fields, fieldCount, 0 )
    fieldCount = printBuffer( EXAMPLE_EXEC_REPORT + 3 );
    CHECK_EQ( start + 3 fields, fieldCount, 0 )

    return 0;
}
