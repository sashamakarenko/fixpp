#include <fixdump/fix42/Messages.h>
#include <fixdump/fix44/Messages.h>
#include <cstring>

int main( int argc, const char ** argv )
{
    for( int i = 1; i < argc; ++i )
    {
        if( std::strncmp( argv[i], fixdump::fix44::FixBeginStringInsertableTag, fixdump::fix44::FixBeginStringInsertableTagLength ) == 0 )
        {
            fixdump::fix44::offset_t pos = 0;
            fixdump::fix44::fixToHuman( argv[i], pos, std::cout, fixdump::fix44::ttyRgbStyle ) << std::endl;
        }
        else if( std::strncmp( argv[i], fixdump::fix42::FixBeginStringInsertableTag, fixdump::fix42::FixBeginStringInsertableTagLength ) == 0 )
        {
            fixdump::fix42::offset_t pos = 0;
            fixdump::fix42::fixToHuman( argv[i], pos, std::cout, fixdump::fix42::ttyRgbStyle ) << std::endl;
        }
        else
        {
            std::cerr << "Not supported FIX version: " << fixdump::fix44::sohstr( argv[i] ) << std::endl;
        }
    }
    return 0;
}
