__COPYRIGHT__
#pragma once
#ifndef DSTHEADERGUARD_FIXAPI_H
#define DSTHEADERGUARD_FIXAPI_H

#include <map>

#include <DSTINCDIR/FixFloat.h>

std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::sohstr & str );

namespace DSTNAMESPACE
{

using Quantity = Float;

template<>
inline Float fromString<Float>( const char * ptr )
{
    return Float( ptr );
}

// ------------------------------ classes -----------------------------


// Base structure for an enum item.
// Ex: for SideEnums::BUY( "BUY", '1' )
// name = "BUY"
// raw  = \0 \0 \0 '1'
// str  = "1"
struct FieldEnumBase
{
    FieldEnumBase( const char * const n, raw_enum_t r, const std::string & s )
    : name{n}
    , raw {r}
    , str {s}
    {
    }
    const char * const name;
    const raw_enum_t   raw;
    const std::string  str;
};

template<typename ValueType>
struct FieldEnum: FieldEnumBase
{
    FieldEnum( const char * const name, ValueType v )
    : FieldEnumBase{ name, toRawEnum(v), toString(v) }
    , value{v}
    {
    }
    const ValueType & operator() () const
    {
        return value;
    }
    const ValueType value;
};

template< typename VT >
inline bool operator == ( const VT & v, const FieldEnum<VT> & fe )
{
    return v == fe.value;
}

template< typename VT >
inline bool operator == ( const FieldEnum<VT> & fe, const VT & v )
{
    return fe.value == v;
}

template< typename VT >
inline bool operator != ( const VT & v, const FieldEnum<VT> & fe )
{
    return v != fe.value;
}

template< typename VT >
inline bool operator != ( const FieldEnum<VT> & fe, const VT & v )
{
    return fe.value != v;
}

template< typename VT >
inline std::string toString( const FieldEnum< VT > & item )
{
    return toString( item.value );
}

template<typename T>
struct BadEnum{ static constexpr T value = std::numeric_limits<T>::max(); };

template<>
struct BadEnum<sohstr>{ static constexpr sohstr value{nullptr}; };

using FieldEnumMap = std::map< raw_enum_t, const FieldEnumBase * >;

// Base structure for all field enums.
struct FieldEnumsBase
{
    // implementation is in Fields.cpp
    virtual ~FieldEnumsBase();

    virtual const char * getFieldName() const = 0;

    virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const = 0;

    virtual const FieldEnumMap & getEnumMapByRaw() const = 0;

    virtual const FieldEnumBase ** getEnums() const = 0;

    const char * getEnumNameByRaw( raw_enum_t raw ) const
    {
        const FieldEnumBase * e = getEnumByRaw( raw );
        return e ? e->name : nullptr;
    }
};


enum class FieldType: unsigned
{
    UNKNOWN,
    AMT,
    BOOLEAN,
    CHAR,
    COUNTRY,
    CURRENCY,
    DATA,
    EXCHANGE,
    FLOAT,
    INT,
    LENGTH,
    LOCALMKTDATE,
    LOCALMKTTIME,
    DAYOFMONTH,
    MONTHYEAR,
    MULTIPLEVALUESTRING,
    NUMINGROUP,
    PERCENTAGE,
    PRICE,
    PRICEOFFSET,
    QTY,
    SEQNUM,
    STRING,
    MULTIPLECHARVALUE,
    MULTIPLESTRINGVALUE,
    UTCDATEONLY,
    UTCTIMEONLY,
    UTCTIMESTAMP,
    UTCDATE,
    TZTIMEONLY,
    LANGUAGE,
    TZTIMESTAMP,
    XMLDATA,
    XID,
    XIDREF,
    EURIBOR,
    TAGNUM
};

// Field offset within the message or -1 if not found,
struct FieldBase
{
    offset_t offset = -1;
};

// N = name, T = tag, V = value type
template< const char * const & N, tag_t T, typename V >
struct Field: FieldBase
{
    typedef V ValueType;

    static constexpr raw_tag_t        RAW_TAG              = tag_as_raw<T>();
    static constexpr unsigned         TAG                  = T;
    static constexpr unsigned         TAG_WIDTH            = tag_width<T>();
    static constexpr insertable_tag_t INSERTABLE_TAG       = tag_as_insertable<T>();
    static constexpr unsigned         INSERTABLE_TAG_WIDTH = TAG_WIDTH + 2; // SOH + '='

    static constexpr const char * tagName()
    {
        return N;
    }

    static constexpr unsigned tagKey()
    {
        return T;
    }

    static constexpr unsigned tagWidth()
    {
        return tag_width<T>();
    }

    static FieldType getType();

    static const std::string & getTypeName();

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


// Base class for parsing messages and groups.
// _fixPtr points to the beginning of the FIX message or group within the originally scanned buffer (no copy is done).
class MessageBase
{
    public:

        const char * getMessageBuffer() const
        {
            return _fixPtr;
        }

        std::size_t getMessageLength() const
        {
            return _fixLength;
        }

        const char * getMessageEnd() const
        {
            return _fixPtr + _fixLength;
        }

    protected:

        MessageBase()  = default;
        ~MessageBase() = default;

        const char * _fixPtr    = nullptr;
        std::size_t  _fixLength = 0;
};

// Helper class for walking through a FIX message.
class Iterator
{
    // implementation is in Fields.cpp
    public:

        explicit Iterator( const char * begin, const char * end = nullptr );

        Iterator( const Iterator & ) = default;

        bool hasNext() const;

        bool next();

        const char * getTagPtr() const;

        const char * getValuePtr() const;

        raw_tag_t getRawTag() const;

    private:

        raw_tag_t update();

        const char * _begin;
        const char * _end;
        offset_t     _pos;
        offset_t     _valueOffset;
};

// underlying types :
typedef Float      AMT;
typedef bool       BOOLEAN;
typedef char       CHAR;
typedef sohstr     COUNTRY;
typedef sohstr     CURRENCY;
typedef sohstr     DATA;
typedef sohstr     EXCHANGE;
typedef Float      FLOAT;
typedef int        INT;
typedef unsigned   LENGTH;
typedef sohstr     LOCALMKTDATE;
typedef sohstr     LOCALMKTTIME;
typedef sohstr     DAYOFMONTH;
typedef sohstr     MONTHYEAR;
typedef sohstr     MULTIPLEVALUESTRING;
typedef unsigned   NUMINGROUP;
typedef Float      PERCENTAGE;
typedef Float      PRICE;
typedef Float      PRICEOFFSET;
typedef Float      QTY;
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
typedef sohstr     XID;
typedef sohstr     XIDREF;
typedef sohstr     EURIBOR;
typedef unsigned   TAGNUM;

template<FieldType FT>
struct field_traits
{
};

template<> struct field_traits<FieldType::AMT>                { using native_type = AMT; };
template<> struct field_traits<FieldType::BOOLEAN>            { using native_type = BOOLEAN; };
template<> struct field_traits<FieldType::CHAR>               { using native_type = CHAR; };
template<> struct field_traits<FieldType::COUNTRY>            { using native_type = COUNTRY; };
template<> struct field_traits<FieldType::CURRENCY>           { using native_type = CURRENCY; };
template<> struct field_traits<FieldType::DATA>               { using native_type = DATA; };
template<> struct field_traits<FieldType::EXCHANGE>           { using native_type = EXCHANGE; };
template<> struct field_traits<FieldType::FLOAT>              { using native_type = FLOAT; };
template<> struct field_traits<FieldType::INT>                { using native_type = INT; };
template<> struct field_traits<FieldType::LENGTH>             { using native_type = LENGTH; };
template<> struct field_traits<FieldType::LOCALMKTDATE>       { using native_type = LOCALMKTDATE; };
template<> struct field_traits<FieldType::LOCALMKTTIME>       { using native_type = LOCALMKTTIME; };
template<> struct field_traits<FieldType::DAYOFMONTH>         { using native_type = DAYOFMONTH; };
template<> struct field_traits<FieldType::MONTHYEAR>          { using native_type = MONTHYEAR; };
template<> struct field_traits<FieldType::MULTIPLEVALUESTRING>{ using native_type = MULTIPLEVALUESTRING; };
template<> struct field_traits<FieldType::NUMINGROUP>         { using native_type = NUMINGROUP; };
template<> struct field_traits<FieldType::PERCENTAGE>         { using native_type = PERCENTAGE; };
template<> struct field_traits<FieldType::PRICE>              { using native_type = PRICE; };
template<> struct field_traits<FieldType::PRICEOFFSET>        { using native_type = PRICEOFFSET; };
template<> struct field_traits<FieldType::QTY>                { using native_type = QTY; };
template<> struct field_traits<FieldType::SEQNUM>             { using native_type = SEQNUM; };
template<> struct field_traits<FieldType::STRING>             { using native_type = STRING; };
template<> struct field_traits<FieldType::MULTIPLECHARVALUE>  { using native_type = MULTIPLECHARVALUE; };
template<> struct field_traits<FieldType::MULTIPLESTRINGVALUE>{ using native_type = MULTIPLESTRINGVALUE; };
template<> struct field_traits<FieldType::UTCDATEONLY>        { using native_type = UTCDATEONLY; };
template<> struct field_traits<FieldType::UTCTIMEONLY>        { using native_type = UTCTIMEONLY; };
template<> struct field_traits<FieldType::UTCTIMESTAMP>       { using native_type = UTCTIMESTAMP; };
template<> struct field_traits<FieldType::UTCDATE>            { using native_type = UTCDATE; };
template<> struct field_traits<FieldType::TZTIMEONLY>         { using native_type = TZTIMEONLY; };
template<> struct field_traits<FieldType::LANGUAGE>           { using native_type = LANGUAGE; };
template<> struct field_traits<FieldType::TZTIMESTAMP>        { using native_type = TZTIMESTAMP; };
template<> struct field_traits<FieldType::XMLDATA>            { using native_type = XMLDATA; };
template<> struct field_traits<FieldType::XID>                { using native_type = XID; };
template<> struct field_traits<FieldType::XIDREF>             { using native_type = XIDREF; };
template<> struct field_traits<FieldType::EURIBOR>            { using native_type = EURIBOR; };
template<> struct field_traits<FieldType::TAGNUM>             { using native_type = TAGNUM; };


inline Quantity operator "" _qty( long double q )
{
    return Quantity( (double)q, false );
}

constexpr unsigned MESSAGE_BEGIN_MIN_BYTES_TO_READ = 20;
constexpr unsigned CHECKSUM_FIELD_LENGTH = 7;

} // namespace DSTNAMESPACE

template< typename VT >
inline std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::FieldEnum< VT > & item )
{
    return os << item.value;
}

#endif /* DSTHEADERGUARD_FIXAPI_H */

