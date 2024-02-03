__COPYRIGHT__

#include <DSTINCDIR/Fields.h>
#include <set>

std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::sohstr & str )
{
    for( const char * ptr = str.ptr; (unsigned)*ptr > FIXPP_SOH; ++ptr )
    {
        os << *ptr;
    }
    return os;
}

namespace DSTNAMESPACE
{

std::map< raw_tag_t  , const char * const >           tagNameByRaw;
std::map< tag_t      , const char * const >           tagNameByValue;
std::map< raw_tag_t  , const FieldEnumsBase * const > enumsByRaw;
std::map< tag_t      , const FieldEnumsBase * const > enumsByTag;
std::map< std::string, tag_t >                        tagByName;
std::map< tag_t      , FieldType >                    fieldTypeByValue;
std::map< tag_t      , const std::string >            fieldTypeNameByValue;

const std::map< raw_tag_t  , const char * const >           & RAW_TAG_TO_NAME       = tagNameByRaw;
const std::map< tag_t      , const char * const >           & TAG_TO_NAME           = tagNameByValue;
const std::map< raw_tag_t  , const FieldEnumsBase * const > & RAW_TO_ENUM           = enumsByRaw;
const std::map< tag_t      , const FieldEnumsBase * const > & TAG_TO_ENUM           = enumsByTag;
const std::map< std::string, tag_t >                        & FIELD_NAME_TO_TAG     = tagByName;
const std::map< tag_t      , FieldType >                    & TAG_TO_FIELD_TYPE     = fieldTypeByValue;
const std::map< tag_t      , const std::string >            & TAG_TO_FIELD_NAME     = fieldTypeNameByValue;

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

#include <DSTINCDIR/Fields.cxx>

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
