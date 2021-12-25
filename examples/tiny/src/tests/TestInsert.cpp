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

    MessageBuilder & value( const int & v )
    {
        value( "todo-int", 8 );
        return *this;
    }

    template< typename FIELD >
    MessageBuilder & field( const char * v, unsigned len )
    {
        end = insert<FIELD>(end);
        return value( v, len );
    }

    template< typename FIELD, typename VALUE >
    MessageBuilder & field( const VALUE & v )
    {
        end = insert<FIELD>(end);
        return value( v );
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
    mb.tag<FieldBeginString>().tag<FieldBodyLength>().field<FieldAccount>( "trader", 6 ).field<FieldNoLegs>(679);
    *mb.end = 0;
    std::cout << buf << "\n";

    return 0;
}
