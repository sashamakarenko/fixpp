__COPYRIGHT__

#include <DSTINCDIR/Fields.h>
#include <set>

std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::sohstr & str )
{
    if( str.ptr )
    {
        for( const char * ptr = str.ptr; (unsigned)*ptr > FIXPP_SOH; ++ptr )
        {
            os << *ptr;
        }
    }
    return os;
}

namespace DSTNAMESPACE
{

FieldEnumsBase::~FieldEnumsBase()
{
}

Iterator::Iterator( const char * begin, const char * end )
: _begin      { begin }
, _end        { end }
, _pos        { 0 }
, _valueOffset{ 0 }
{
    ptrdiff_t len = _end - _begin;
    if( _begin != nullptr and _begin[_pos] != 0 and ( _end == nullptr or len < (ptrdiff_t)std::numeric_limits< offset_t >::max() ) )
    {
        update();
    }
}

bool Iterator::hasNext() const
{
    return _valueOffset > 0;
}

bool Iterator::next()
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

const char * Iterator::getTagPtr() const
{
    return _begin + _pos;
}

const char * Iterator::getValuePtr() const
{
    return _valueOffset ? _begin + _valueOffset : nullptr;
}

raw_tag_t Iterator::getRawTag() const
{
    if( _valueOffset )
    {
        offset_t len = 0;
        return loadRawTag( _begin + _pos, len );
    }
    return 0;
}

raw_tag_t Iterator::update()
{
    _valueOffset = _pos;
    raw_tag_t tag = loadRawTag( _begin + _pos, _valueOffset );
    if( tag == 0 )
    {
        _valueOffset = 0;
    }
    return tag;
}


std::map< raw_tag_t  , const char * const >           tagNameByRaw;
std::map< tag_t      , const char * const >           tagNameByValue;
std::map< raw_tag_t  , const FieldEnumsBase * const > enumsByRaw;
std::map< tag_t      , const FieldEnumsBase * const > enumsByTag;
std::map< std::string, tag_t >                        tagByName;
std::map< tag_t      , FieldType >                    fieldTypeByValue;
std::map< tag_t      , const std::string & >          fieldTypeNameByValue;

const std::map< raw_tag_t  , const char * const >           & RAW_TAG_TO_NAME        = tagNameByRaw;
const std::map< tag_t      , const char * const >           & TAG_TO_NAME            = tagNameByValue;
const std::map< raw_tag_t  , const FieldEnumsBase * const > & RAW_TO_ENUM            = enumsByRaw;
const std::map< tag_t      , const FieldEnumsBase * const > & TAG_TO_ENUM            = enumsByTag;
const std::map< std::string, tag_t >                        & FIELD_NAME_TO_TAG      = tagByName;
const std::map< tag_t      , FieldType >                    & TAG_TO_FIELD_TYPE      = fieldTypeByValue;
const std::map< tag_t      , const std::string & >          & TAG_TO_FIELD_TYPE_NAME = fieldTypeNameByValue;

tag_t getFieldTag( const std::string & fieldName )
{
    auto it = tagByName.find( fieldName );
    return it != tagByName.end() ? it->second : 0;
}

const char * getFieldName( tag_t tagValue )
{
    auto it = tagNameByValue.find( tagValue );
    return it != tagNameByValue.end() ? it->second : nullptr;
}

FieldType getFieldType( tag_t tagValue )
{
    auto it = fieldTypeByValue.find( tagValue );
    return it != fieldTypeByValue.end() ? it->second : FieldType::UNKNOWN;
}

const std::string & getFieldTypeName( tag_t tagValue )
{
    static std::string unknown{ "UNKNOWN" };
    auto it = fieldTypeNameByValue.find( tagValue );
    return it != fieldTypeNameByValue.end() ? it->second : unknown;
}

std::set< tag_t > headerTags =
{
#include <DSTINCDIR/Header.cxx>
};

bool isHeaderField( tag_t tagValue )
{
    return headerTags.find( tagValue ) != headerTags.end();
}


const std::string fixTypeName_AMT                 { "AMT" };
const std::string fixTypeName_BOOLEAN             { "BOOLEAN" };
const std::string fixTypeName_CHAR                { "CHAR" };
const std::string fixTypeName_COUNTRY             { "COUNTRY" };
const std::string fixTypeName_CURRENCY            { "CURRENCY" };
const std::string fixTypeName_DATA                { "DATA" };
const std::string fixTypeName_EXCHANGE            { "EXCHANGE" };
const std::string fixTypeName_FLOAT               { "FLOAT" };
const std::string fixTypeName_INT                 { "INT" };
const std::string fixTypeName_LENGTH              { "LENGTH" };
const std::string fixTypeName_LOCALMKTDATE        { "LOCALMKTDATE" };
const std::string fixTypeName_LOCALMKTTIME        { "LOCALMKTTIME" };
const std::string fixTypeName_DAYOFMONTH          { "DAYOFMONTH" };
const std::string fixTypeName_MONTHYEAR           { "MONTHYEAR" };
const std::string fixTypeName_MULTIPLEVALUESTRING { "MULTIPLEVALUESTRING" };
const std::string fixTypeName_NUMINGROUP          { "NUMINGROUP" };
const std::string fixTypeName_PERCENTAGE          { "PERCENTAGE" };
const std::string fixTypeName_PRICE               { "PRICE" };
const std::string fixTypeName_PRICEOFFSET         { "PRICEOFFSET" };
const std::string fixTypeName_QTY                 { "QTY" };
const std::string fixTypeName_SEQNUM              { "SEQNUM" };
const std::string fixTypeName_STRING              { "STRING" };
const std::string fixTypeName_MULTIPLECHARVALUE   { "MULTIPLECHARVALUE" };
const std::string fixTypeName_MULTIPLESTRINGVALUE { "MULTIPLESTRINGVALUE" };
const std::string fixTypeName_UTCDATEONLY         { "UTCDATEONLY" };
const std::string fixTypeName_UTCTIMEONLY         { "UTCTIMEONLY" };
const std::string fixTypeName_UTCTIMESTAMP        { "UTCTIMESTAMP" };
const std::string fixTypeName_UTCDATE             { "UTCDATE" };
const std::string fixTypeName_TZTIMEONLY          { "TZTIMEONLY" };
const std::string fixTypeName_LANGUAGE            { "LANGUAGE" };
const std::string fixTypeName_TZTIMESTAMP         { "TZTIMESTAMP" };
const std::string fixTypeName_XMLDATA             { "XMLDATA" };
const std::string fixTypeName_XID                 { "XID" };
const std::string fixTypeName_XIDREF              { "XIDREF" };
const std::string fixTypeName_EURIBOR             { "EURIBOR" };
const std::string fixTypeName_TAGNUM              { "TAGNUM" };

#include <DSTINCDIR/Fields.cxx>

// May be used to check whther raw_enum_t to hold uniquely all enum items for each enum field.
void checkEnums()
{
    for( auto it : enumsByRaw )
    {
        const FieldEnumsBase * enums = it.second;
        const FieldEnumMap & emap =  enums->getEnumMapByRaw();
        auto mapSz = emap.size();
        std::size_t enumCount = 0;
        for( const FieldEnumBase * const * eptr = enums->getEnums(); eptr && *eptr; ++eptr )
        {
            ++enumCount;
        }

        if( enumCount != mapSz )
        {
            std::cerr << "Enum size mismatch " << enums->getFieldName() << " no.items=" << enumCount << " map.size=" << mapSz << std::endl;
            FieldEnumMap knownEnums;
            for( const FieldEnumBase * const * eptr = enums->getEnums(); eptr && *eptr; ++eptr )
            {
                auto it = knownEnums.find( (*eptr)->raw );
                if( it == knownEnums.end() )
                {
                    knownEnums[ (*eptr)->raw ] = *eptr;
                }
                else
                {
                    std::cerr << " - " << (*eptr)->name << " : " << (*eptr)->raw << "    |    " << it->second->name << " : " << it->second->raw << std::endl;
                }
            }
        }
    }
}

} // namespace DSTNAMESPACE
