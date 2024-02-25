__COPYRIGHT__
#pragma once
#ifndef DSTHEADERGUARD_FIXAPI_H
#define DSTHEADERGUARD_FIXAPI_H

#include <map>

#include <DSTINCDIR/FixFloat.h>

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
inline std::string toString( const FieldEnum< VT > & item )
{
    return toString( item.value );
}

using FieldEnumMap = std::map< raw_enum_t, const FieldEnumBase * >;

// Base structure for all field enums.
struct FieldEnumsBase
{
    // implementation is in Fields.cpp
    virtual ~FieldEnumsBase();

    virtual const char * getFieldName() const = 0;

    virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const = 0;

    virtual const FieldEnumMap & getEnumMapByRaw() const = 0;

    virtual const FieldEnumBase * const * const getEnums() const = 0;

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


// Base structure for parsing messages and groups.
// buf points to the begining of the FIX message or group within the originally scanned string (no copy is done).
struct MessageBase
{
    const char * getMessageBuffer() const
    {
        return buf;
    }

    protected:

        const char * buf = nullptr;
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
// typedef double     AMT;
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
typedef double     PERCENTAGE;
typedef Float      PRICE;
typedef Float      PRICEOFFSET;
// typedef double     QTY;
// typedef unsigned   QTY;
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

inline DSTNAMESPACE::Quantity operator "" _qty( long double q )
{
    return DSTNAMESPACE::Quantity( (double)q, false );
}

constexpr unsigned MESSAGE_BEGIN_MIN_BYTES_TO_READ = 20;
constexpr unsigned CHECKSUM_FIELD_LENGTH = 7;

} // namespace DSTNAMESPACE

#endif /* DSTHEADERGUARD_FIXAPI_H */

