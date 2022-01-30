#include <DSTNAMESPACE/Messages.h>
#include <cstring>
#include <type_traits>
#include <chrono>

#ifndef likely
#define likely(x)      __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
#define unlikely(x)    __builtin_expect(!!(x), 0)
#endif

namespace DSTNAMESPACE
{

// in below inserts we admit 1 byte overflow which is supposed to be overwritten by the value

// "\1" "1="
// "\1" "12="
template< typename FIELD, std::enable_if_t< (FIELD::INSERTABLE_TAG_WIDTH<5), int > = 0 >
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

int uintWidth2( unsigned value )
{
    if( value < 100000U )
    {
        if( value < 10U )
        {
            return 1;
        }
        if( value < 100U )
        {
            return 2;
        }
        if( value < 1000U )
        {
            return 3;
        }
        if( value < 10000U )
        {
            return 4;
        }
        return 5;
    }
    if( value < 1000000U )
    {
        return 6;
    }
    if( value < 10000000U )
    {
        return 7;
    }
    if( value < 100000000U )
    {
        return 8;
    }
    if( value < 1000000000U )
    {
        return 9;
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

inline char * reverseUIntToString( char * ptr, unsigned value )
{
    do
    {
        *(--ptr) = '0' + (value % 10);
        value /= 10;
    } while ( value > 0 );
    return ptr;
}

inline char * reverseUIntToString( char * ptr, unsigned value, unsigned & chksum )
{
    do
    {
        char c = '0' + (value % 10);
        *(--ptr) = c;
        chksum += (unsigned)c;
        value /= 10;
    } while ( value > 0 );
    return ptr;
}

struct FixBufferStream
{
    FixBufferStream( char * buf ): begin{buf}, end{buf} {}

    template< typename FIELD >
    FixBufferStream & pushTag()
    {
        end = insert<FIELD>(end);
        return *this;
    }

    FixBufferStream & pushValue( const char * src, unsigned len )
    {
        memcpy( end, src, len );
        end += len;
        return *this;
    }

    FixBufferStream & pushValue( const char * src )
    {
        while( *src )
        {
            *end++ = *src++;
        }
        return *this;
    }

    FixBufferStream & pushValue( char v )
    {
        *end++ = v;
        return *this;
    }

    FixBufferStream & pushValue( unsigned v )
    {
        end += uintWidth( v );
        reverseUIntToString( end, v );
        return *this;
    }

    FixBufferStream & pushValue( int v )
    {
        unsigned uv = v;
        if( v < 0 )
        {
            uv = -v;
            *end++ = '-';
        }
        end += uintWidth( uv );
        reverseUIntToString( end, uv );
        return *this;
    }

    // todo: negatives
    FixBufferStream & pushValue( double v, unsigned precision )
    {
        unsigned i = (unsigned)v;
        end += uintWidth( i );
        reverseUIntToString( end, i );
        *end++ = '.';
        char * first = end;
        i = ( v - i ) * uintPow10[ precision ] + 0.5;
        end += precision;
        for( char * last = reverseUIntToString( end, i ) - 1; last >= first; --last )
        {
            *last = '0';
        }
        return *this;
    }

    template< typename FIELD >
    FixBufferStream & append( const char * v, unsigned len )
    {
        end = insert<FIELD>(end);
        return pushValue( v, len );
    }

    template< typename FIELD, typename VALUE >
    FixBufferStream & append( const VALUE & v )
    {
        end = insert<FIELD>(end);
        return pushValue( v );
    }

    template< typename FIELD >
    FixBufferStream & append( double v, unsigned precision )
    {
        end = insert<FIELD>(end);
        return pushValue( v, precision );
    }

    char * begin;
    char * end;
};

//  buffer   start                msgType                                    sendingTime                  body
//  |        |                    |                                          |                            |
//  "..."   "8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "..."
//           ----------------***  -------------------------------------****              --------========
//           precompute per session and msg type and insert as a single
//           memcpy only if seqnum width changes
//

constexpr unsigned BODY_LENGTH_OFFSET = FixBeginStringInsertableTagLength + FieldBodyLength::INSERTABLE_TAG_WIDTH;
struct HeaderTemplate: FixBufferStream
{
    HeaderTemplate( unsigned capacity, const std::string & msgType ):
        FixBufferStream( nullptr ),
        buffer( capacity, (char)0 ),
        chksum( 0 )
    {
        begin = end = &buffer[0];
        end = insert<FieldBeginString>( end );
        end = insert<FieldBodyLength>( end );
        end = insert<FieldMsgType>( end );
        memcpy( end, msgType.data(), msgType.size() );
        end += msgType.size();
    }

    HeaderTemplate():
        FixBufferStream( nullptr ),
        buffer(),
        chksum( 0 )
    {
    }

    // returns countable body length [I 35=.....34=]
    unsigned finalize()
    {
        chksum = computeChecksum( begin, end );
        return countableLength = ( end - begin ) - BODY_LENGTH_OFFSET;
    }

    std::vector<char> buffer;
    unsigned          chksum, countableLength;
};

struct TimestampKeeper
{
    enum class Precision: unsigned
    {
        SECONDS      = 0,
        MILLISECONDS = 3,
        MICROSECONDS = 6,
        NANOSECONDS  = 9
    };

    // YYYYMMDD-HH:MM:SS.mmmnnnuuu
    constexpr static unsigned DATE_LENGTH              = 8;
    constexpr static unsigned DATE_TIME_SECONDS_LENGTH = 17;
    constexpr static unsigned DATE_TIME_MILLIS_LENGTH  = 21;
    constexpr static unsigned DATE_TIME_MICROS_LENGTH  = 24;
    constexpr static unsigned DATE_TIME_NANOS_LENGTH   = 27;
    constexpr static const char * const PLACE_HOLDER = "11112233-44:55:66.777888999";

    TimestampKeeper( char * buffer = nullptr, Precision secPrecision = Precision::SECONDS ):
        startOfDay( 0 ),
        endOfDay( 0 ),
        begin( buffer ), 
        lastSecond( 0 ),
        lastFraction( 0 ),
        secFraction( secPrecision )
    {
    }

    unsigned getWidth() const
    {
        return DATE_TIME_SECONDS_LENGTH + 1 + (unsigned)secFraction;
    }

    unsigned setup( char * buffer, Precision secPrecision )
    {
        begin = buffer;
        secFraction = secPrecision;
        if( buffer )
        {
            memcpy( buffer, PLACE_HOLDER, getWidth() );
            update();
        }
        return getWidth();
    }

    char * update( const std::chrono::time_point<std::chrono::system_clock> & now = std::chrono::system_clock::now() )
    {
        const std::time_t tnow = std::chrono::system_clock::to_time_t(now);
        if( tnow < startOfDay or tnow >= endOfDay )
        {
            startOfDay = tnow - ( tnow % ( 3600 * 24 ) );
            endOfDay = startOfDay + 3600 * 24;
            std::tm tm = * std::gmtime( & tnow );
            std::strftime( begin, 64, "%Y%m%d-%H:%M:%S", &tm );
        }

        unsigned diff = tnow - startOfDay;
        if( lastSecond != diff )
        {
            uint16_t hours   = diff / 3600;
            uint16_t minutes = ( ( diff / 60 ) % 60 );
            uint16_t seconds = ( diff % 60 );
            char * ptr = begin + DATE_LENGTH + 1;
            ptr[0] = hours   / 10 + '0';
            ptr[1] = hours   % 10 + '0';
            ptr[3] = minutes / 10 + '0';
            ptr[4] = minutes % 10 + '0';
            ptr[6] = seconds / 10 + '0';
            ptr[7] = seconds % 10 + '0';
            lastSecond = diff;
        }

        if( secFraction != Precision::SECONDS )
        {
            begin[DATE_TIME_SECONDS_LENGTH] = '.';
            unsigned fraction = 0;
            if( secFraction == Precision::MILLISECONDS )
            {
                fraction = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count() % 1000;
            }
            else if( secFraction == Precision::MICROSECONDS )
            {
                fraction = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count() % 1000'000;
            }
            else // nanos
            {
                fraction = std::chrono::time_point_cast<std::chrono::nanoseconds>(now).time_since_epoch().count() % 1000'000'000;
            }
            if( fraction != lastFraction )
            {
                char * first = begin + DATE_TIME_SECONDS_LENGTH + 1;
                for( char * last = reverseUIntToString( first + (unsigned)secFraction, fraction ) - 1; last >= first; --last )
                {
                    *last = '0';
                }
                lastFraction = fraction;
            }
        }
        unsigned len = DATE_TIME_SECONDS_LENGTH + 1 + (unsigned)secFraction;
        begin[len] = FIXPP_SOH;
        return begin + len;
    }

    time_t    startOfDay, endOfDay;
    char    * begin;
    unsigned  lastSecond, lastFraction;
    Precision secFraction;
};

/*

buffer   start                msgType                                    sendingTime                  body
|        |                    |                                          |                            |
"..."   "8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "..."
                         ---                                       ----  |                            | 
                         | body length and seqno will be updated   |     begin                        end

*/
struct ReusableMessageBuilder: FixBufferStream
{
    ReusableMessageBuilder( const std::string & messageType, unsigned maxBodyLength, unsigned headerTemplateCapacity = 128 ):
        FixBufferStream( nullptr ),
        buffer( maxBodyLength + 1, (char)0 ),
        start( nullptr ),
        lastSeqnumWidth( 0 ),
        lastBodyLengthWidth( 0 ),
        header( headerTemplateCapacity, messageType ),
        msgType( messageType )
    {
        begin = end = &buffer[0] + headerTemplateCapacity;
    }

    const char * setSeqnumAndUpdateHeaderAndChecksum( unsigned seqnum )
    {
        unsigned chksum = header.chksum;
        char * ptr = reverseUIntToString( begin, seqnum, chksum );
        unsigned seqnumWidth = begin - ptr;
        unsigned bodyLength = header.countableLength + seqnumWidth + ( end - begin ) + 7; // 7 = checksum width

        char * msgTypePtr = begin - header.countableLength - seqnumWidth;
        ptr = reverseUIntToString( msgTypePtr, bodyLength, chksum );
        unsigned bodyLengthWidth = msgTypePtr - ptr;

        start = begin - seqnumWidth - header.countableLength - bodyLengthWidth - BODY_LENGTH_OFFSET;
        if( unlikely( seqnumWidth != lastSeqnumWidth ) )
        {
            lastBodyLengthWidth = bodyLengthWidth;
            lastSeqnumWidth = seqnumWidth;
            memcpy( start, header.begin, BODY_LENGTH_OFFSET );
            memcpy( msgTypePtr, header.begin + BODY_LENGTH_OFFSET, header.countableLength );
        }
        else if( unlikely( bodyLengthWidth != lastBodyLengthWidth ) )
        {
            lastBodyLengthWidth = bodyLengthWidth;
            memcpy( start, header.begin, BODY_LENGTH_OFFSET );
        }
        chksum += computeChecksum( begin, end );
        pushTag<FieldCheckSum>();
        chksum = chksum & 0xff;
        end[0] = '0' + chksum / 100;
        end[1] = '0' + ( chksum / 10 ) % 10;
        end[2] = '0' + chksum % 10;
        end[3] = 0;
        end += 4;
        return start;
    }

    void rewind( unsigned pos = 0 )
    {
        end = begin + pos;
    }

    std::vector<char>             buffer;
    char                        * start;
    unsigned                      lastSeqnumWidth, lastBodyLengthWidth;
    HeaderTemplate                header;
    TimestampKeeper               sendingTime;
    const std::string             msgType;
};

}
