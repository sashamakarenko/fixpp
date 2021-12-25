#include <tiny/Fields.h>
#include <cstring>

using namespace tiny;

template< typename FIELD >
inline char * insert( char * p )
{
    *reinterpret_cast<insertable_tag_t*>(p) = FIELD::INSERTABLE_TAG;
    return p + FIELD::tagWidth() + 2;
}

template<>
inline char * insert<FieldBeginString>( char * p )
{
    memcpy( p, FixBeginStringInsertableTag, FixBeginStringInsertableTagLength );
    return p + FixBeginStringInsertableTagLength;
}

template< typename FIELD >
struct StreamTag
{
};

struct MessageBuilder
{
    MessageBuilder( char * buf, int endOffest = 0 ): begin{buf}, end{buf+ endOffest} {}

    template< typename FIELD >
    MessageBuilder & tag()
    {
        end = insert<FIELD>(end); return *this;
    }

    MessageBuilder & value( const char * src, unsigned len )
    {
        memcpy( end, src, len );
        end += len;
        return *this;
    }

    template< typename FIELD, typename VALUE >
    MessageBuilder & field( const VALUE & v, unsigned len = 0 )
    {
        end = insert<FIELD>(end);
        return value( v, len );
    }

    char * begin;
    char * end;
};

int main( int args, const char ** argv )
{
    char buf[1024];
    char * p = buf;
    p = insert<FieldBeginString>(p);
    p = insert<FieldMsgType>(p);
    p = insert<FieldAccount>(p);
    p = insert<FieldAvgPx>(p);
    *p = 0;
    std::cout << buf << "\n";

    MessageBuilder mb( buf );
    mb.tag<FieldBeginString>().tag<FieldBodyLength>().field<FieldAccount>( "trader", 6 );
    *mb.end = 0;
    std::cout << buf << "\n";

    return 0;
}
