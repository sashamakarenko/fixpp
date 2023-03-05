#pragma once
#ifndef DSTHEADERGUARD_FIXAPI_H
#define DSTHEADERGUARD_FIXAPI_H

#include <map>
#include <cstdint>
#include <string>
#include <limits>
#include <cstddef>

#define FIXPP_SOH 1U
#define SOHSTR(S) #S "\1"

namespace DSTNAMESPACE
{

// ------------------------------ primitives -----------------------------

// field key or tag type
using tag_t = uint32_t;

// use uint32 if all tags < 10000
using raw_tag_t = uint64_t;

// raw tag surrounded by SOH and =
using insertable_tag_t = uint64_t;

// use 64bits if your venue has wider enum values
// typedef uint64_t raw_enum_t;
using raw_enum_t = uint32_t;

// use 16bits if all your venue messages are short
// typedef int16_t offset_t;
using offset_t = int32_t;


// max 5 decimal digits in tags
constexpr unsigned tag_key_width( tag_t K )
{
    if( K < 10U    ) return 1;
    if( K < 100U   ) return 2;
    if( K < 1000U  ) return 3;
    if( K < 10000U ) return 4;
    return 5;
}


template< tag_t K >
constexpr raw_tag_t tag_as_raw()
{
    if( tag_key_width(K) == 1 )
    {
        return K + raw_tag_t('0');
    }

    return ( ( raw_tag_t('0') + K % 10U ) << ( 8 * ( tag_key_width(K) - 1 ) ) ) + tag_as_raw<K/10U>();
}


// as uint64_t * pointing to "\001" "TAG" "="
template< tag_t K >
constexpr insertable_tag_t tag_as_insertable()
{
    return ( insertable_tag_t('=') << ( 8 * ( tag_key_width(K) + 1 ) ) ) + ( insertable_tag_t(tag_as_raw<K>()) << 8 ) + 1;
}

namespace
{

constexpr static const uint64_t uintPow10[] =
{
    1U,
    10U,
    100U,
    1000U,
    1000'0U,
    1000'00U,
    1000'000U,
    1000'000'0U,
    1000'000'00U,
    1000'000'000U,
    1000'000'000'0U,
    1000'000'000'00U,
    1000'000'000'000U,
};

constexpr static const double div10Pow[] =
{
    1,
    0.1,
    0.01,
    0.001,
    0.0001,
    0.00001,
    0.000001,
    0.0000001,
    0.00000001,
    0.000000001,
    0.0000000001,
    0.00000000001
};

// valid for FIX only
constexpr bool isNotDecDigit( char c )
{
    return c < '0';
}

}

// used to scan integers of type T
template< typename T, T N >
constexpr T dec_zeros()
{
    return ( dec_zeros<T,T(N-1)>() * T(10) ) + T( '0' );
}

template<>
constexpr unsigned short dec_zeros<unsigned short,0U>()
{
    return 0U;
}

template<>
constexpr short dec_zeros<short,0>()
{
    return 0;
}

template<>
constexpr unsigned dec_zeros<unsigned,0U>()
{
    return 0U;
}

template<>
constexpr int dec_zeros<int,0>()
{
    return 0;
}

template<>
constexpr int64_t dec_zeros<int64_t,0L>()
{
    return 0L;
}

template<>
constexpr uint64_t dec_zeros<uint64_t,0UL>()
{
    return 0UL;
}

template< typename T = unsigned >
inline T parseUInt( const char * ptr, unsigned & len )
{
    if( isNotDecDigit( ptr[0] ) )
    {
        return 0;
    }
    if( isNotDecDigit( ptr[1] ) )
    {
        len += 1;
        return T( ptr[0] ) - dec_zeros<T,T(1)>();
    }
    if( isNotDecDigit( ptr[2] ) )
    {
        len += 2;
        return T( ptr[0] ) * 10 + T( ptr[1] ) - dec_zeros<T,T(2)>();
    }
    if( isNotDecDigit( ptr[3] ) )
    {
        len += 3;
        return ( T( ptr[0] ) * 10 + T( ptr[1] ) ) * 10 + T( ptr[2] ) - dec_zeros<T,T(3)>();
    }
    if( isNotDecDigit( ptr[4] ) )
    {
        len += 4;
        return ( (
               T( ptr[0] )   * 10 +
               T( ptr[1] ) ) * 10 +
               T( ptr[2] ) ) * 10 +
               T( ptr[3] ) - dec_zeros<T,T(4)>();
    }
    if( isNotDecDigit( ptr[5] ) )
    {
        len += 5;
        return ( ( (
               T( ptr[0] )   * 10 +
               T( ptr[1] ) ) * 10 +
               T( ptr[2] ) ) * 10 +
               T( ptr[3] ) ) * 10 +
               T( ptr[4] ) - dec_zeros<T,T(5)>();
    }
    if( isNotDecDigit( ptr[6] ) )
    {
        len += 6;
        return ( ( ( (
               T( ptr[0] )   * 10 +
               T( ptr[1] ) ) * 10 +
               T( ptr[2] ) ) * 10 +
               T( ptr[3] ) ) * 10 +
               T( ptr[4] ) ) * 10 +
               T( ptr[5] ) - dec_zeros<T,T(6)>();
    }
    if( isNotDecDigit( ptr[7] ) )
    {
        len += 7;
        return ( ( ( ( (
               T( ptr[0] )   * 10 +
               T( ptr[1] ) ) * 10 +
               T( ptr[2] ) ) * 10 +
               T( ptr[3] ) ) * 10 +
               T( ptr[4] ) ) * 10 +
               T( ptr[5] ) ) * 10 +
               T( ptr[6] ) - dec_zeros<T,T(7)>();
    }
    T tmp =    ( ( ( ( ( (
               T( ptr[0] )   * 10 +
               T( ptr[1] ) ) * 10 +
               T( ptr[2] ) ) * 10 +
               T( ptr[3] ) ) * 10 +
               T( ptr[4] ) ) * 10 +
               T( ptr[5] ) ) * 10 +
               T( ptr[6] ) ) * 10 +
               T( ptr[7] ) - dec_zeros<T,T(8)>();
    if( isNotDecDigit( ptr[8] ) )
    {
        len += 8;
        return tmp;
    }

    unsigned tmplen = 0;
    T next = parseUInt<T>( ptr + 8, tmplen );
    len += tmplen + 8;
    return tmp * (T)uintPow10[ tmplen ] + next;
}

// todo: add pretty printer for Quantity
struct Quantity
{
    template< typename T >
    Quantity( const T & value, bool isInt ): value{ value }, isInteger{ isInt }{}
    union Value
    {
        Value( int64_t  i ): integer{i}{}
        Value( uint64_t i ): integer{(int64_t)i}{}
        Value( double   r ): real{r}{}
        Value( float    r ): real{r}{}
        int64_t integer;
        double  real;
    };

    template< typename T >
    operator T () const { return isInteger ? value.integer : value.real; }

    Value value;
    bool  isInteger;
};

inline Quantity parseQuantity( const char * ptr )
{
    int sign = 1;
    if( *ptr == '-' )
    {
        sign = -1;
        ++ptr;
    }
    unsigned intlen = 0;
    int64_t integer = parseUInt<int64_t>( ptr, intlen );
    if( ptr[intlen] != '.' ) // SOH
    {
       return { sign * integer, true };
    }

    unsigned mantissaLength = 0;
    double mantissa = parseUInt( ptr + intlen + 1, mantissaLength );
    mantissa *= div10Pow[ mantissaLength ];
    return { sign * ( (double)integer + mantissa ), false };
}

inline double parseDouble( const char * ptr )
{
    double sign = 1;
    if( *ptr == '-' )
    {
        sign = -1;
        ++ptr;
    }
    unsigned intlen = 0;
    unsigned integer = parseUInt( ptr, intlen );
    double mantissa = 0.0;
    if( ptr[intlen] == '.' )
    {
        unsigned mantissaLength = 0;
        mantissa = parseUInt( ptr + intlen + 1, mantissaLength );
        mantissa *= div10Pow[ mantissaLength ];
    }
    return sign * ( (double)integer + mantissa );
}

template< typename T = unsigned >
inline const char * parseYYYYMMDD( const char * ptr, T & year, T & month, T & day )
{
    year  = T( ptr[0] ) * 1000 + T( ptr[1] ) * 100 + T( ptr[2] ) * 10 + T( ptr[3] ) - dec_zeros<T,(T)4>();
    month = T( ptr[4] ) * 10   + T( ptr[5] ) - dec_zeros<T,(T)2>();
    day   = T( ptr[6] ) * 10   + T( ptr[7] ) - dec_zeros<T,(T)2>();
    return ptr + 8;
}

template< typename T = unsigned >
inline T parseYYYYMMDD( const char * ptr )
{
    return T( ptr[0] ) * 10000000 + T( ptr[1] ) * 1000000 + T( ptr[2] ) * 100000 + T( ptr[3] ) * 10000 +
           T( ptr[4] ) * 1000     + T( ptr[5] ) * 100 +
           T( ptr[6] ) * 10       + T( ptr[7] ) - dec_zeros<T,(T)8>();
}

// HH:MM:SS[.mmmuuunnn]
template< typename T = unsigned, typename NT = T >
inline const char * parseTime( const char * ptr, T & hour, T & minute, T & second, NT & nanoseconds )
{
    hour   = T( ptr[0] ) * 10   + T( ptr[1] ) - dec_zeros<T,(T)2>();
    minute = T( ptr[3] ) * 10   + T( ptr[4] ) - dec_zeros<T,(T)2>();
    second = T( ptr[6] ) * 10   + T( ptr[7] ) - dec_zeros<T,(T)2>();
    if( ptr[8] == '.' )
    {
        // we trust the venue not to exceed 9 digits
        unsigned len = 0;
        nanoseconds = (NT)parseUInt( ptr + 9, len );
        nanoseconds *= (NT)uintPow10[ 9 - len ];
        return ptr + 9 + len;
    }
    nanoseconds = 0;
    return ptr + 8;
}

template< typename T = unsigned, typename NT = T >
inline const char * parseTimestamp( const char * ptr, T & year, T & month, T & day, T & hour, T & minute, T & second, NT & nanoseconds )
{
    return parseTime( parseYYYYMMDD( ptr, year, month, day ) + 1, hour, minute, second, nanoseconds );
}

// FIXPP_SOH terminated string
struct sohstr
{
    sohstr( const char * buf = nullptr ): ptr( buf ){}
    const char * ptr;
};


template<typename V>
V fromString( const char * ptr );

template<>
inline bool fromString<bool>( const char * ptr )
{
    return 'Y' == *ptr;
}

template<>
inline unsigned fromString<unsigned>( const char * ptr )
{
    unsigned len;
    return parseUInt( ptr, len );
}

template<>
inline int fromString<int>( const char * ptr )
{
    unsigned len;
    if( *ptr == '-' )
    {
        return - (int)parseUInt( ptr+1, len );
    }
    return parseUInt( ptr, len );
}

template<>
inline double fromString<double>( const char * ptr )
{
    return parseDouble( ptr );
}

template<>
inline Quantity fromString<Quantity>( const char * ptr )
{
    return parseQuantity( ptr );
}

template<>
inline char fromString<char>( const char * ptr )
{
    return *ptr;
}

template<>
inline const char * fromString<const char *>( const char * ptr )
{
    return ptr;
}

template<>
inline sohstr fromString<sohstr>( const char * ptr )
{
    return ptr;
}

// "...;123=ABC;56=value;"
//          |
//          ptr
inline unsigned getValueLength( const char * ptr )
{
    unsigned len = 0;
    do
    {
        if( FIXPP_SOH == ptr[0] )
        {
            return len;
        }
        else if( FIXPP_SOH == ptr[1] )
        {
            return len + 1;
        }
        else if( FIXPP_SOH == ptr[2] )
        {
            return len + 2;
        }
        else if( FIXPP_SOH == ptr[3] )
        {
            return len + 3;
        }
        else if( FIXPP_SOH == ptr[4] )
        {
            return len + 4;
        }
        len += 5;
        ptr += 5;
    } while( true );
}

// "...;123=whatever;56=nextvalue;"
//          |        |
//          pos in   pos out
inline void gotoNextField( const char * fix, offset_t & pos )
{
    const char * ptr = fix + pos;
    do
    {
        if( FIXPP_SOH == ptr[0] )
        {
            pos += 1;
            return;
        }
        else if( FIXPP_SOH == ptr[1] )
        {
            pos += 2;
            return;
        }
        else if( FIXPP_SOH == ptr[2] )
        {
            pos += 3;
            return;
        }
        else if( FIXPP_SOH == ptr[3] )
        {
            pos += 4;
            return;
        }
        else if( FIXPP_SOH == ptr[4] )
        {
            pos += 5;
            return;
        }
        else if( FIXPP_SOH == ptr[5] )
        {
            pos += 6;
            return;
        }
        else if( FIXPP_SOH == ptr[6] )
        {
            pos += 7;
            return;
        }
        else if( FIXPP_SOH == ptr[7] )
        {
            pos += 8;
            return;
        }
        pos += 8;
        ptr += 8;
    } while( true );
}

template<typename V>
inline std::string toString( const V & value )
{
    return std::to_string(value);
}

template<>
inline std::string toString<sohstr>( const sohstr & value )
{
    offset_t pos = 0;
    gotoNextField( value.ptr, pos );
    return std::string( value.ptr, (std::size_t)pos-1 );
}

inline unsigned copyRawEnum( const char * from, char * to )
{
    unsigned len = 0;
    for( ; from[len] != FIXPP_SOH && len < sizeof( raw_enum_t ); ++len )
    {
        to[ len ] = from[ len ];
    }
    return len;
}

inline raw_enum_t toRawEnum( char c )
{
    return (raw_enum_t)c;
}

inline raw_enum_t toRawEnum( int i )
{
    unsigned u = (unsigned)i;
    if( tag_key_width(u) == 1 )
    {
        return u + raw_enum_t('0');
    }
    return ( ( raw_enum_t('0') + u % 10U ) << ( 8 * ( tag_key_width(u) - 1 ) ) ) + toRawEnum( i/10 );
}


inline raw_enum_t toRawEnum( const char * str )
{
    raw_enum_t value{0};
    char * to = reinterpret_cast<char *>( &value );
    for( unsigned len = 0; str[len] != FIXPP_SOH && len < sizeof( value ); ++len )
    {
        to[ len ] = str[ len ];
    }
    return value;
}

inline raw_enum_t toRawEnum( const sohstr & str )
{
    return toRawEnum( str.ptr );
}

// ------------------------------ classes -----------------------------

struct FieldEnumBase
{
    FieldEnumBase( const char * const n, raw_enum_t r, const std::string & s ): name{n}, raw{r}, str{s}
    {
    }
    const char * const name;
    const raw_enum_t   raw;
    const std::string  str;
};

template<typename ValueType>
struct FieldEnum: FieldEnumBase
{
    FieldEnum( const char * const name, ValueType v ): FieldEnumBase{ name, toRawEnum(v), toString(v) }, value{v}
    {
    }
    const ValueType value;
};

using FieldEnumMap = std::map< raw_enum_t, const FieldEnumBase * >;

struct FieldEnumsBase
{
    virtual ~FieldEnumsBase(){}

    virtual const char * getFieldName() const = 0;

    virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const = 0;

    virtual const FieldEnumMap & getEnumMapByRaw() const = 0;

    virtual const FieldEnumBase * const * const getEnums() const = 0;

    const char * getEnumNameByRaw( raw_enum_t raw ) const
    {
        const FieldEnumBase * e = getEnumByRaw(raw);
        return e ? e->name : nullptr;
    }
};


struct FieldBase
{
    offset_t offset = -1;
};

template< const char * const & N, tag_t K, typename Type >
struct Field: FieldBase
{
    typedef Type ValueType;

    static constexpr raw_tag_t        RAW = tag_as_raw<K>();
    static constexpr unsigned         TAG_WIDTH = tag_key_width(K);
    static constexpr unsigned         KEY = K;
    static constexpr insertable_tag_t INSERTABLE_TAG = tag_as_insertable<K>();
    static constexpr unsigned         INSERTABLE_TAG_WIDTH = TAG_WIDTH + 2; // SOH + '='

    static constexpr const char * tagName()
    {
        return N;
    }

    static constexpr unsigned tagKey()
    {
        return K;
    }

    static constexpr unsigned tagWidth()
    {
        return tag_key_width(K);
    }

    ValueType getValue( const char * buf ) const
    {
        return fromString<ValueType>( buf + offset );
    }

    unsigned getValueOffset() const
    {
        return tagWidth() + 1;
    }

    typedef FieldEnum<ValueType> EnumType;
    static const FieldEnumBase * const * enumItems;
};

// ";1=value;12=value;..."
//   |
//   ptr
inline raw_tag_t nextRawTag( const char * ptr, offset_t & pos )
{
    raw_tag_t rtag = *reinterpret_cast<const raw_tag_t *>(ptr);
    if( ptr[1] == '=' )
    {
        pos += 2;
        return rtag & 0xff;
    }
    else if( ptr[2] == '=' )
    {
        pos += 3;
        return rtag & 0xff'ff;
    }
    else if( ptr[3] == '=' )
    {
        pos += 4;
        return rtag & 0xff'ff'ff;
    }
    else if( ptr[4] == '=' )
    {
        pos += 5;
        return rtag & 0xff'ff'ff'ff;
    }
    else if( ptr[5] == '=' )
    {
        pos += 6;
        return rtag & 0xff'ff'ff'ff'ff;
    }

    return 0;
}

struct MessageBase
{
    protected: const char * buf = nullptr;
    public: const char * getMessageBuffer() const { return buf; }
};

class Iterator
{
    public:

        Iterator( const char * begin, const char * end = nullptr ):
            _begin( begin ),
            _end( end ),
            _pos( 0 ),
            _valueOffset( 0 )
        {
            ptrdiff_t len = _end - _begin;
            if( _begin != nullptr and _begin[_pos] != 0 and ( _end == nullptr or len < (ptrdiff_t)std::numeric_limits< offset_t >::max() ) )
            {
                update();
            }
        }

        bool hasNext() const
        {
            return _valueOffset > 0;
        }

        bool next()
        {
            if( _valueOffset == 0 or _begin == nullptr or _begin[_pos] == 0 or ( _end != nullptr and _begin + _pos >= _end  ) )
            {
                return false;
            }
            gotoNextField( _begin, _pos );
            if( _end != nullptr and _begin + _pos >= _end )
            {
                _valueOffset = 0;
            }
            else
            {
                update();
            }
            return _valueOffset > 0;
        }

        const char * getTagPtr() const
        {
            return _begin + _pos;
        }

        const char * getValuePtr() const
        {
            return _valueOffset ? _begin + _valueOffset : nullptr;
        }

        raw_tag_t getRawTag() const
        {
            if( _valueOffset )
            {
                offset_t len = 0;
                return nextRawTag( _begin + _pos, len );
            }
            return 0;
        }

    private:

        raw_tag_t update()
        {
            _valueOffset = _pos;
            raw_tag_t tag = nextRawTag( _begin + _pos, _valueOffset );
            if( tag == 0 )
            {
                _valueOffset = 0;
            }
            return tag;
        }

        const char * _begin, * _end;
        offset_t     _pos, _valueOffset;
};


// typedef double     AMT;
typedef Quantity   AMT;
typedef bool       BOOLEAN;
typedef char       CHAR;
typedef sohstr     COUNTRY;
typedef sohstr     CURRENCY;
typedef sohstr     DATA;
typedef sohstr     EXCHANGE;
typedef double     FLOAT;
typedef int        INT;
typedef unsigned   LENGTH;
typedef sohstr     LOCALMKTDATE;
typedef sohstr     DAYOFMONTH;
typedef sohstr     MONTHYEAR;
typedef sohstr     MULTIPLEVALUESTRING;
typedef unsigned   NUMINGROUP;
typedef double     PERCENTAGE;
typedef double     PRICE;
typedef double     PRICEOFFSET;
// typedef double     QTY;
// typedef unsigned   QTY;
typedef Quantity   QTY;
typedef unsigned   SEQNUM;
typedef sohstr     STRING;
typedef sohstr     MULTIPLECHARVALUE;
typedef sohstr     MULTIPLESTRINGVALUE;
typedef sohstr     UTCDATEONLY;
typedef sohstr     UTCTIMEONLY;
typedef sohstr     UTCTIMESTAMP;
typedef sohstr     UTCDATE;
typedef sohstr     TZTIMEONLY;
typedef sohstr     LANGUAGE;
typedef sohstr     TZTIMESTAMP;
typedef sohstr     XMLDATA;

inline DSTNAMESPACE::Quantity operator "" _qty( long double q ){ return DSTNAMESPACE::Quantity( (double)q, false ); }

} // namespace DSTNAMESPACE


namespace std
{
    inline std::string to_string( const DSTNAMESPACE::Quantity & qty ) noexcept 
    {
        return  qty.isInteger ? std::to_string( qty.value.integer ) : std::to_string( qty.value.real );
    }
}

#endif /* DSTHEADERGUARD_FIXAPI_H */

