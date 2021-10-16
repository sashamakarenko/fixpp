#include <fixdump/fix44/Messages.h>
#include <cstring>

int main( int argc, const char ** argv )
{
    for( int i = 1; i < argc; ++i )
    {
        fixdump::fix44::offset_t pos = 0;
        fixdump::fix44::fixToHuman( argv[i], pos, std::cout, fixdump::fix44::ttyRgbStyle ) << std::endl;
    }
    return 0;
}
