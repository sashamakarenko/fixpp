#include <tiny/Fields.h>
#include <cstring>
#include <type_traits>
#include "Helper.h"

using namespace tiny;

constexpr bool is_less(unsigned l, unsigned r){ return l < r; }

// "\1" "12="
template< typename FIELD, std::enable_if_t< is_less(FIELD::INSERTABLE_TAG_WIDTH,5), int > = 0 >
inline char * insert( char * p )
{
    *reinterpret_cast<uint32_t*>(p) = (uint32_t)FIELD::INSERTABLE_TAG;
    return p + FIELD::INSERTABLE_TAG_WIDTH;
}

// "\1" "123= " 5
// "\1" "1234= " 6
template< typename FIELD, std::enable_if_t< FIELD::INSERTABLE_TAG_WIDTH == 5 or FIELD::INSERTABLE_TAG_WIDTH == 6, int > = 0 >
inline char * insert( char * p )
{
    *reinterpret_cast<uint32_t*>(p)   = (uint32_t)FIELD::INSERTABLE_TAG;
    *reinterpret_cast<uint16_t*>(p+4) = (uint16_t)(FIELD::INSERTABLE_TAG>>32);
    return p + FIELD::INSERTABLE_TAG_WIDTH;
}

// "\1" "12345= " 7
template< typename FIELD, std::enable_if_t< is_less(6,FIELD::INSERTABLE_TAG_WIDTH), int > = 0 >
inline char * insert( char * p )
{
    *reinterpret_cast<insertable_tag_t*>(p) = FIELD::INSERTABLE_TAG;
    return p + FIELD::INSERTABLE_TAG_WIDTH;
}

template<>
inline char * insert<FieldBeginString>( char * p )
{
    memcpy( p, FixBeginStringInsertableTag, FixBeginStringInsertableTagLength );
    return p + FixBeginStringInsertableTagLength;
}

inline int uintWidth( unsigned value )
{
    if( value < 1000U )
    {
        if( value < 100U )
        {
            return value < 10U ? 1 : 2;
        }
        return 3;
    }
    else if( value < 1000'000U )
    {
        if( value < 10'000U )
        {
            return 4;
        }
        return value < 100'000U ? 5 : 6;
    }
    else if( value < 1000'000'000U )
    {
        if( value < 10'000'000U )
        {
            return 7;
        }
        return value < 100'000'000U ? 8 : 9;
    }
    return 10;
}

// suitable for seqnums and message length
inline int smallUintWidth( unsigned value )
{
    if( value < 1000U )
    {
        if( value >= 100U )
        {
            return 3;
        }
        return value < 10U ? 1 : 2;
    }
    else if( value < 10'000U )
    {
        return 4;
    }
    else if( value < 1000'000U )
    {
        return value < 100'000U ? 5 : 6;
    }
    return 7;
}

//  begin    start                msgType                                    sendingTime                  body
//  |        |                    |                                          |                            | 
//  "..."   "8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "..."
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
    char * start;
};

int main( int args, const char ** argv )
{
    CHECK( 0, uintWidth(0), == 1 )
    CHECK( 9, uintWidth(9), == 1 )
    CHECK( 10, uintWidth(10), == 2 )
    CHECK( 99, uintWidth(99), == 2 )
    CHECK( 100, uintWidth(100), == 3 )
    CHECK( 999, uintWidth(999), == 3 )
    CHECK( 1000, uintWidth(1000), == 4 )
    CHECK( 9999, uintWidth(9999), == 4 )
    CHECK( 10000, uintWidth(10000), == 5 )
    CHECK( 99999, uintWidth(99999), == 5 )
    CHECK( 100000, uintWidth(100000), == 6 )
    CHECK( 999999, uintWidth(999999), == 6 )
    CHECK( 1000000, uintWidth(1000000), == 7 )
    CHECK( 9999999, uintWidth(9999999), == 7 )
    CHECK( 10000000, uintWidth(10000000), == 8 )
    CHECK( 99999999, uintWidth(99999999), == 8 )
    CHECK( 100000000, uintWidth(100000000), == 9 )
    CHECK( 999999999, uintWidth(999999999), == 9 )


    CHECK( 0, smallUintWidth(0), == 1 )
    CHECK( 9, smallUintWidth(9), == 1 )
    CHECK( 10, smallUintWidth(10), == 2 )
    CHECK( 99, smallUintWidth(99), == 2 )
    CHECK( 100, smallUintWidth(100), == 3 )
    CHECK( 999, smallUintWidth(999), == 3 )
    CHECK( 1000, smallUintWidth(1000), == 4 )
    CHECK( 9999, smallUintWidth(9999), == 4 )
    CHECK( 10000, smallUintWidth(10000), == 5 )
    CHECK( 99999, smallUintWidth(99999), == 5 )
    CHECK( 100000, smallUintWidth(100000), == 6 )
    CHECK( 999999, smallUintWidth(999999), == 6 )
    CHECK( 1000000, smallUintWidth(1000000), == 7 )
    CHECK( 9999999, smallUintWidth(9999999), == 7 )

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
