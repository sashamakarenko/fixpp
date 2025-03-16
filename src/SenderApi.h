__COPYRIGHT__
#pragma once
#ifndef DSTHEADERGUARD_SENDERAPI_H
#define DSTHEADERGUARD_SENDERAPI_H

#include <DSTINCDIR/Messages.h>
#include <cstring>
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

// Suitable for seqnums and message length.
// value < 1000000
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

// Formats value from right to left.
// @return next left most position.
inline char * reverseUIntToString( char * ptr, unsigned value )
{
    do
    {
        *(--ptr) = '0' + ( value % 10 );
        value /= 10;
    } while ( value > 0 );
    return ptr;
}

// Formats value from right to left and computes check sum of the inserted string.
// @return next left most position.
inline char * reverseUIntToString( char * ptr, unsigned value, unsigned & chksum )
{
    do
    {
        char c = '0' + ( value % 10 );
        *(--ptr) = c;
        chksum += (unsigned)c;
        value /= 10;
    } while ( value > 0 );
    return ptr;
}

// Formats value from right to left, zero pads it if necessary, and computes check sum of the inserted string.
// @return next left most position.
inline char * reversePaddedUIntToString( char * ptr, unsigned value, unsigned width, unsigned & chksum )
{
    char * oldptr = ptr;
    ptr = reverseUIntToString( ptr, value, chksum );
    for( unsigned insertedWidth = (unsigned)( oldptr - ptr ); insertedWidth < width; ++insertedWidth )
    {
        *(--ptr) = '0';
        chksum += (unsigned)'0';
    }
    return ptr;
}

class TimestampKeeper;
using ClockType = std::chrono::system_clock;
using TimePoint = std::chrono::time_point<ClockType>;

enum class ClockPrecision: unsigned
{
    SECONDS      = 0,
    MILLISECONDS = 3,
    MICROSECONDS = 6,
    NANOSECONDS  = 9
};

// Used to build FIX messages.
class FixBufferStream
{
    public:

        explicit FixBufferStream( char * buf )
        : _begin{ buf }
        , _end  { buf }
        {
        }

        template< typename FIELD >
        FixBufferStream & pushTag()
        {
            _end = insert<FIELD>( _end );
            return *this;
        }

        FixBufferStream & pushTag( unsigned tag )
        {
            *_end++ = FIXPP_SOH;
            pushValue( tag );
            *_end++ = '=';
            return *this;
        }

        FixBufferStream & pushValue( const char * src, unsigned len )
        {
            memcpy( _end, src, len );
            _end += len;
            return *this;
        }

        FixBufferStream & pushValue( const char * src )
        {
            while( *src )
            {
                *_end++ = *src++;
            }
            return *this;
        }

        FixBufferStream & pushValue( const std::string & src )
        {
            return pushValue( src.c_str(), src.size() );
        }

        FixBufferStream & pushValue( const std::string_view & src )
        {
            return pushValue( src.data(), src.size() );
        }

        FixBufferStream & pushValue( const sohstr & src )
        {
            for( const char * ptr = src.ptr; *ptr != FIXPP_SOH and *ptr; )
            {
                *_end++ = *ptr++;
            }
            return *this;
        }

        FixBufferStream & pushValue( char v )
        {
            *_end++ = v;
            return *this;
        }

        FixBufferStream & pushValue( bool v )
        {
            *_end++ = v ? 'Y' : 'N';
            return *this;
        }

        FixBufferStream & pushValue( unsigned v )
        {
            _end += uintWidth( v );
            reverseUIntToString( _end, v );
            return *this;
        }

        FixBufferStream & pushValue( long unsigned v )
        {
            _end += uintWidth( v );
            reverseUIntToString( _end, v );
            return *this;
        }

        FixBufferStream & pushValue( int v )
        {
            unsigned uv = v;
            if( v < 0 )
            {
                uv = -v;
                *_end++ = '-';
            }
            _end += uintWidth( uv );
            reverseUIntToString( _end, uv );
            return *this;
        }

        FixBufferStream & pushValue( double v, unsigned precision )
        {
            if( v < 0 )
            {
                *_end++ = '-';
                v = -v;
            }
            unsigned i = (unsigned)v;
            _end += uintWidth( i );
            reverseUIntToString( _end, i );
            *_end++ = '.';
            char * first = _end;
            i = ( v - i ) * uintPow10[ precision ] + 0.5;
            _end += precision;
            for( char * last = reverseUIntToString( _end, i ) - 1; last >= first; --last )
            {
                *last = '0';
            }
            return *this;
        }

        FixBufferStream & pushValue( const Float & v )
        {
            _end = v.format( _end );
            return *this;
        }

        inline FixBufferStream & pushValue( TimestampKeeper & tk, const TimePoint & tp );

        char * span( unsigned length )
        {
            char * oldEnd = _end;
            _end += length;
            return oldEnd;
        }

        template< typename FIELD >
        FixBufferStream & append( const char * v, unsigned len )
        {
            _end = insert<FIELD>( _end );
            return pushValue( v, len );
        }

        template< typename FIELD, typename VALUE >
        FixBufferStream & append( const VALUE & v )
        {
            _end = insert<FIELD>( _end );
            return pushValue( v );
        }

        template< typename FIELD >
        FixBufferStream & append( double v, unsigned precision )
        {
            _end = insert<FIELD>( _end );
            return pushValue( v, precision );
        }

        template< typename FIELD >
        FixBufferStream & append( TimestampKeeper & v, const TimePoint & tp = ClockType::now() )
        {
            _end = insert<FIELD>( _end );
            return pushValue( v, tp );
        }

        template< typename FIELD >
        FixBufferStream & append( const FieldEnum< typename FIELD::ValueType > & item  )
        {
            return append<FIELD>( item.value );
        }

        // not efficient
        template< typename FIELD >
        FixBufferStream & append( const TimePoint & tp, ClockPrecision precision );

        char * begin() const
        {
            return _begin;
        }

        char * end() const
        {
            return _end;
        }

        std::ptrdiff_t length() const
        {
            return _end - _begin;
        }

    protected:

        friend class ReusableMessageBuilder;

        char * _begin;
        char * _end;
};

constexpr unsigned BODY_LENGTH_OFFSET = FixBeginStringInsertableTagLength + FieldBodyLength::INSERTABLE_TAG_WIDTH;

// Precompute Header per session and msg type and insert as a single memcpy only if seqnum width changes.
//
//  buffer   start                msgType                                    sendingTime                  body
//  |        |                    |                                          |                            |
//  "..."   "8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "..."
//           ----------------***  -------------------------------------****              --------========
//
class HeaderTemplate: public FixBufferStream
{
    public:

        HeaderTemplate( unsigned capacity, const std::string & msgType )
        : FixBufferStream( nullptr )
        , _buffer( capacity, (char)0 )
        , _chksum( 0 )
        , _countableLength( 0 )
        {
            _begin = _end = & _buffer[0];
            _end = insert<FieldBeginString>( _end );
            _end = insert<FieldBodyLength>( _end );
            append<FieldMsgType>( msgType );
        }

        HeaderTemplate()
        : FixBufferStream( nullptr )
        , _buffer()
        , _chksum( 0 )
        , _countableLength( 0 )
        {
        }

        // Returns countable body length [I 35=.....34=]
        unsigned finalize()
        {
            if( *( _end - FieldMsgSeqNum::INSERTABLE_TAG_WIDTH ) != FIXPP_SOH or
                parseTag( _end - FieldMsgSeqNum::TAG_WIDTH - 1 ) != FieldMsgSeqNum::TAG )
            {
                pushTag<FieldMsgSeqNum>();
            }
            _chksum = computeChecksum( _begin, _end );
            return _countableLength = ( _end - _begin ) - BODY_LENGTH_OFFSET;
        }

    protected:

        friend class ReusableMessageBuilder;

        std::vector<char> _buffer;
        unsigned          _chksum;
        unsigned          _countableLength;
};

// Reusable timestamp strcuture.
// Updates only changed values - mostly time since date doesn't change often.
class TimestampKeeper
{

    public:

        using Precision = ClockPrecision;

        // YYYYMMDD-HH:MM:SS.mmmnnnuuu
        constexpr static unsigned DATE_LENGTH              = 8;
        constexpr static unsigned DATE_TIME_SECONDS_LENGTH = 17;
        constexpr static unsigned DATE_TIME_MILLIS_LENGTH  = 21;
        constexpr static unsigned DATE_TIME_MICROS_LENGTH  = 24;
        constexpr static unsigned DATE_TIME_NANOS_LENGTH   = 27;
        constexpr static const char * const PLACE_HOLDER   = "11112233-44:55:66.777888999";

        static unsigned precisionToLength( Precision precision )
        {
            return DATE_TIME_SECONDS_LENGTH + ( precision != Precision::SECONDS ? 1 : 0 ) + (unsigned)precision;
        }

        unsigned length() const
        {
            return precisionToLength( _precision );
        }

        explicit TimestampKeeper( char * buffer = nullptr, Precision precision = Precision::SECONDS )
        : _startOfDay  { 0 }
        , _endOfDay    { 0 }
        , _begin       { buffer }
        , _lastSecond  { 0 }
        , _lastFraction{ 0 }
        , _precision   { precision }
        {
        }

        void reset()
        {
            _startOfDay   = 0;
            _endOfDay     = 0;
            _begin        = nullptr;
            _lastSecond   = 0;
            _lastFraction = 0;
            _precision  = Precision::SECONDS;
        }

        unsigned fill( char * buffer, Precision precision, const TimePoint & tp = ClockType::now() )
        {
            if( _begin != buffer or _precision != precision )
            {
                _begin        = buffer;
                _precision    = precision;
                _startOfDay   = 0;
                _endOfDay     = 0;
                _lastSecond   = 0;
                _lastFraction = 0;
            }
            if( buffer )
            {
                update( tp );
                return length();
            }
            return 0;
        }

        unsigned setup( char * buffer, Precision precision )
        {
            _begin = buffer;
            _precision = precision;
            if( buffer )
            {
                memcpy( buffer, PLACE_HOLDER, length() );
                update();
            }
            return length();
        }

        char * update( const TimePoint & tp = ClockType::now() )
        {
            const std::time_t tpt = ClockType::to_time_t( tp );
            if( tpt < _startOfDay or tpt >= _endOfDay )
            {
                _startOfDay = tpt - ( tpt % ( 3600 * 24 ) );
                _endOfDay = _startOfDay + 3600 * 24;
                std::tm tm;
                gmtime_r( &tpt, &tm );
                std::strftime( _begin, 64, "%Y%m%d-%H:%M:%S", &tm );
            }

            unsigned diff = tpt - _startOfDay;
            if( _lastSecond != diff )
            {
                uint16_t hours   = diff / 3600;
                uint16_t minutes = ( ( diff / 60 ) % 60 );
                uint16_t seconds = ( diff % 60 );
                char * ptr = _begin + DATE_LENGTH + 1;
                ptr[0] = hours   / 10 + '0';
                ptr[1] = hours   % 10 + '0';
                ptr[3] = minutes / 10 + '0';
                ptr[4] = minutes % 10 + '0';
                ptr[6] = seconds / 10 + '0';
                ptr[7] = seconds % 10 + '0';
                _lastSecond = diff;
            }

            if( _precision != Precision::SECONDS )
            {
                _begin[DATE_TIME_SECONDS_LENGTH] = '.';
                unsigned fraction = 0;
                if( _precision == Precision::MILLISECONDS )
                {
                    fraction = std::chrono::time_point_cast<std::chrono::milliseconds>(tp).time_since_epoch().count() % 1000;
                }
                else if( _precision == Precision::MICROSECONDS )
                {
                    fraction = std::chrono::time_point_cast<std::chrono::microseconds>(tp).time_since_epoch().count() % 1000'000;
                }
                else // nanos
                {
                    fraction = std::chrono::time_point_cast<std::chrono::nanoseconds>(tp).time_since_epoch().count() % 1000'000'000;
                }
                if( fraction != _lastFraction )
                {
                    char * first = _begin + DATE_TIME_SECONDS_LENGTH + 1;
                    for( char * last = reverseUIntToString( first + (unsigned)_precision, fraction ) - 1; last >= first; --last )
                    {
                        *last = '0';
                    }
                    _lastFraction = fraction;
                }
            }
            unsigned len = DATE_TIME_SECONDS_LENGTH + 1 + (unsigned)_precision;
            _begin[len] = FIXPP_SOH;
            return _begin + len;
        }

        Precision getPrecision() const
        {
            return _precision;
        }

        void setPrecision( Precision precision )
        {
            _precision = precision;
        }

        char * data() const
        {
            return  _begin;
        }

    private:

        friend class ReusableMessageBuilder;

        time_t    _startOfDay;
        time_t    _endOfDay;
        char    * _begin;
        unsigned  _lastSecond;
        unsigned  _lastFraction;
        Precision _precision;
};

FixBufferStream & FixBufferStream::pushValue( TimestampKeeper & tk, const TimePoint & tp )
{
    tk.fill( _end, tk.getPrecision(), tp );
    _end += tk.length();
    return *this;
}

template< typename FIELD >
inline FixBufferStream & FixBufferStream::append( const TimePoint & tp, ClockPrecision precision )
{
    _end = insert<FIELD>( _end );
    TimestampKeeper tmp( nullptr, precision );
    return pushValue( tmp, tp );
}

// basic types
template< typename VALUE >
constexpr unsigned valueMaxLength( const VALUE & v )
{
    return 16;
}

inline unsigned valueMaxLength( const std::string & v )
{
    return v.size();
}

inline unsigned valueMaxLength( const std::string_view & v )
{
    return v.size();
}

inline unsigned valueMaxLength( const TimestampKeeper & v )
{
    return v.length();
}

inline unsigned valueMaxLength( const sohstr & v )
{
    offset_t pos = 0;
    gotoNextField( v.ptr, pos );
    return pos-1;
}

inline unsigned valueMaxLength( const Float & v )
{
    return Float::MAX_DIGITS + 5;
}

inline unsigned valueMaxLength( const char * & v )
{
    return strlen(v);
}

/*

Convenience class to reuse header, timestamps and the buffer.

         messageBegin()
         |
_buffer  _start               _msgType                                   _sendingTime                 _body
|        |                    |                                          |                            |
"..."   "8=FIX.4.4" I "9=315" I "35=W" I "49=foo" I "56=bar" I "34=1234" I "52=20190101-01:01:01.000" I "..."
                         ---                                       ----  |                            |
                         | body length and seqno will be updated   |     _begin                       _end
                                                                         |                            |
                                                                         bodyBegin()                  end()

Since header length depends on seqnum and body length, start is not usable before calling setSeqnumAndUpdateHeaderAndChecksum().
*/
class ReusableMessageBuilder: public FixBufferStream
{
    public:

        ReusableMessageBuilder( const std::string & messageType, unsigned maxBodyLength, unsigned headerTemplateCapacity = 128 )
        : FixBufferStream     ( nullptr )
        , _msgType            ( messageType )
        , _buffer             ( headerTemplateCapacity + maxBodyLength + 1, (char)0 )
        , _start              ( nullptr )
        , _lastSeqnumWidth    ( 0 )
        , _minSeqnumWidth     ( 1 )
        , _lastBodyLengthWidth( 0 )
        , _minBodyLengthWidth ( 2 )
        , _bufferGrowChunk    ( 1024 )
        , _header             ( headerTemplateCapacity, messageType )
        {
            _begin = _end = &_buffer[0] + headerTemplateCapacity;
            for( unsigned i = 0; i < NO_TIMES; ++i )
            {
                _userTime[i].reset();
            }
        }

        ReusableMessageBuilder( const ReusableMessageBuilder & ) = delete;

        void setupSendingTime( ClockPrecision precision )
        {
            append<FieldSendingTime>( TimestampKeeper::PLACE_HOLDER, TimestampKeeper::precisionToLength( precision ) );
            _sendingTime.setup( _end - TimestampKeeper::precisionToLength( precision ), precision );
            _sendingTime.update();
        }

        char * messageBegin() const
        {
            return _start;
        }

        char * bodyBegin() const
        {
            return _begin;
        }

        std::ptrdiff_t totalLength() const
        {
            return _end - _start;
        }

        std::ptrdiff_t bodyLength() const
        {
            return _end - _begin;
        }

        static constexpr unsigned NO_TIMES = 5;

        TimestampKeeper & userTime( unsigned idx )
        {
            return _userTime[ idx ];
        }

        TimestampKeeper & sendingTime()
        {
            return _sendingTime;
        }

        // To be called just before sending.
        // Header is supposed to be updated by this time.
        const char * setSeqnumAndUpdateHeaderAndChecksum( unsigned seqnum )
        {
            unsigned chksum      = _header._chksum;
            char   * ptr         = reversePaddedUIntToString( _begin, seqnum, _minSeqnumWidth, chksum );
            unsigned seqnumWidth = _begin - ptr;
            unsigned bodyLength  = _header._countableLength + seqnumWidth + ( _end - _begin );
            char   * msgTypePtr  = _begin - _header._countableLength - seqnumWidth;
            ptr = reversePaddedUIntToString( msgTypePtr, bodyLength, _minBodyLengthWidth, chksum );
            unsigned bodyLengthWidth = msgTypePtr - ptr;

            _start = _begin - seqnumWidth - _header._countableLength - bodyLengthWidth - BODY_LENGTH_OFFSET;
            if( unlikely( seqnumWidth != _lastSeqnumWidth ) )
            {
                _lastBodyLengthWidth = bodyLengthWidth;
                _lastSeqnumWidth = seqnumWidth;
                memcpy( _start, _header._begin, BODY_LENGTH_OFFSET );
                memcpy( msgTypePtr, _header._begin + BODY_LENGTH_OFFSET, _header._countableLength );
            }
            else if( unlikely( bodyLengthWidth != _lastBodyLengthWidth ) )
            {
                _lastBodyLengthWidth = bodyLengthWidth;
                memcpy( _start, _header._begin, BODY_LENGTH_OFFSET );
            }
            chksum += computeChecksum( _begin, _end ) + 1; // 1 = last SOH not inserted yet
            pushTag<FieldCheckSum>();
            chksum = chksum & 0xff;
            _end[0] = '0' + chksum / 100;
            _end[1] = '0' + ( chksum / 10 ) % 10;
            _end[2] = '0' + chksum % 10;
            _end[3] = 1;
            _end += 4;
            return _start;
        }

        void rewind( unsigned pos = 0 )
        {
            _end = _begin + pos;
        }

        // Resizes the buffer if necessary to receive next value.
        // start will be updated in setSeqnumAndUpdateHeaderAndChecksum().
        void resizeIfNecessary( unsigned valueLength )
        {
            valueLength += 8; // max "|tag=" length ?
            auto endOffset = _end - &_buffer[0];
            if( endOffset + (ssize_t)valueLength >= (ssize_t)_buffer.size() )
            {
                auto beginOffset = _begin - &_buffer[0];
                ssize_t userTimeOffset[NO_TIMES] = {};
                for( unsigned i = 0; i < NO_TIMES; ++i )
                {
                    if( _userTime[i]._begin )
                    {
                        userTimeOffset[i] = _userTime[i]._begin - &_buffer[0];
                    }
                }
                _buffer.resize( ( 1 + ( endOffset + valueLength ) / _bufferGrowChunk ) * _bufferGrowChunk );
                _begin = &_buffer[0] + beginOffset;
                _end   = &_buffer[0] + endOffset;
                for( unsigned i = 0; i < 5; ++i )
                {
                    if( _userTime[i]._begin )
                    {
                        _userTime[i]._begin = &_buffer[0] + userTimeOffset[i];
                    }
                }
            }
        }

        // Methods resizing the buffer if necessary.
        // Otherwise use FixBufferStream::append().

        template< typename FIELD >
        FixBufferStream & appendSafely( const char * v, unsigned len )
        {
            resizeIfNecessary( len );
            _end = insert<FIELD>( _end );
            return pushValue( v, len );
        }

        template< typename FIELD, typename VALUE >
        FixBufferStream & appendSafely( const VALUE & v )
        {
            resizeIfNecessary( valueMaxLength(v) );
            _end = insert<FIELD>( _end );
            return pushValue( v );
        }

        template< typename FIELD >
        FixBufferStream & appendSafely( double v, unsigned precision )
        {
            resizeIfNecessary( 16 ); // formatted floating point max length ?
            _end = insert<FIELD>( _end );
            return pushValue( v, precision );
        }

        template< typename FIELD >
        FixBufferStream & appendSafely( TimestampKeeper & v, const TimePoint & tp = ClockType::now() )
        {
            resizeIfNecessary( TimestampKeeper::DATE_TIME_NANOS_LENGTH );
            _end = insert<FIELD>( _end );
            return pushValue( v, tp );
        }

        template< typename FIELD >
        FixBufferStream & appendSafely( const FieldEnum< typename FIELD::ValueType > & item  )
        {
            resizeIfNecessary( valueMaxLength( item.value ) );
            return append<FIELD>( item.value );
        }

        template< typename FIELD >
        char * spanSafely( unsigned valueLength )
        {
            resizeIfNecessary( valueLength );
            _end = insert<FIELD>( _end );
            return span( valueLength );
        }

        bool setBufferGrowChunkSize( unsigned chunkSize )
        {
            if( chunkSize >= 8 and chunkSize <= ( 1 << 20 ) )
            {
                _bufferGrowChunk = chunkSize;
                return true;
            }
            return false;
        }

        unsigned getBufferGrowChunkSize() const
        {
            return _bufferGrowChunk;
        }

        HeaderTemplate & header()
        {
            return _header;
        }

        void setMinSeqnumWidth( unsigned width )
        {
            _minSeqnumWidth = width;
        }

        unsigned getMinSeqnumWidth() const
        {
            return _minSeqnumWidth;
        }

        void setMinBodyLengthWidth( unsigned width )
        {
            _minBodyLengthWidth = width;
        }

        unsigned getMinBodyLengthWidth() const
        {
            return _minBodyLengthWidth;
        }

    protected:

        const std::string             _msgType;
        std::vector<char>             _buffer;
        char                        * _start;
        unsigned                      _lastSeqnumWidth;
        unsigned                      _minSeqnumWidth;
        unsigned                      _lastBodyLengthWidth;
        unsigned                      _minBodyLengthWidth;
        unsigned                      _bufferGrowChunk;
        HeaderTemplate                _header;

        union
        {
        TimestampKeeper               _sendingTime;
        TimestampKeeper               _userTime[NO_TIMES];
        };

};

}

#endif // DSTHEADERGUARD_SENDERAPI_H
