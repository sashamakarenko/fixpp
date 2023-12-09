__COPYRIGHT__

#include <DSTINCDIR/Fields.h>

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
std::map< std::string, tag_t >                        tagByName;

const std::map< raw_tag_t  , const char * const >           & rawToTagName   = tagNameByRaw;
const std::map< tag_t      , const char * const >           & valueToTagName = tagNameByValue;
const std::map< raw_tag_t  , const FieldEnumsBase * const > & rawToEnum      = enumsByRaw;
const std::map< std::string, tag_t >                        & nameToTag      = tagByName;

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
