#include <DSTINCDIR/Fields.h>

std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::sohstr & str )
{
    for( const char * ptr = str.ptr; *ptr != FIXPP_SOH; ++ptr )
    {
        os << *ptr;
    }
    return os;
}

namespace DSTNAMESPACE
{

constexpr bool isNotDecDigit( char c )
{
    return c < '0';
}

constexpr static const unsigned uintPow10[] =
{
    1U,
    10U,
    100U,
    1000U,
    10000U,
    100000U,
    1000000U,
    10000000U,
    100000000U
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

// used to scan uint
template<unsigned N>
constexpr unsigned dec_zeros()
{
    return ( dec_zeros<N-1>() * 10 ) + unsigned( '0' );
}

template<>
constexpr unsigned dec_zeros<0U>()
{
    return 0;
}

unsigned parseUInt( const char * ptr, unsigned & len )
{
    if( isNotDecDigit( ptr[0] ) )
    {
        return 0;
    }
    if( isNotDecDigit( ptr[1] ) )
    {
        len += 1;
        return unsigned( ptr[0] ) - dec_zeros<1>();
    }
    if( isNotDecDigit( ptr[2] ) )
    {
        len += 2;
        return unsigned( ptr[0] ) * 10 + unsigned( ptr[1] ) - dec_zeros<2>();
    }
    if( isNotDecDigit( ptr[3] ) )
    {
        len += 3;
        return unsigned( ptr[0] ) * 100 + unsigned( ptr[1] ) * 10 + unsigned( ptr[2] ) - dec_zeros<3>();
    }
    if( isNotDecDigit( ptr[4] ) )
    {
        len += 4;
        return unsigned( ptr[0] ) * 1000 + unsigned( ptr[1] ) * 100 + unsigned( ptr[2] ) * 10 + unsigned( ptr[3] ) - dec_zeros<4>();
    }
    
    unsigned tmp = unsigned( ptr[0] ) * 10000 + 
                   unsigned( ptr[1] ) * 1000 + 
                   unsigned( ptr[2] ) * 100 + 
                   unsigned( ptr[3] ) * 10 + 
                   unsigned( ptr[4] ) - dec_zeros<5>();
    if( isNotDecDigit( ptr[5] ) )
    {
        len += 5;
        return tmp;
    }

    unsigned tmplen = 0;
    unsigned next = parseUInt( ptr + 5, tmplen );
    len += tmplen + 5;
    return tmp * uintPow10[ tmplen ] + next;
}


double parseDouble( const char * ptr )
{
    unsigned intlen = 0;
    unsigned integer = parseUInt( ptr, intlen );
    double mantissa = 0.0;
    if( ptr[intlen] == '.' )
    {
        unsigned mantissaLength = 0;
        mantissa = parseUInt( ptr + intlen + 1, mantissaLength );
        mantissa *= div10Pow[ mantissaLength ];
    }
    return (double)integer + mantissa;
}

std::map< raw_tag_t, const char * const >           tagNameByRaw;
std::map< unsigned, const char * const >            tagNameByValue;
std::map< raw_tag_t, const FieldEnumsBase * const > enumsByRaw;

const std::map< raw_tag_t, const char * const >           & rawToTagName   = tagNameByRaw;
const std::map< unsigned, const char * const >            & valueToTagName = tagNameByValue;
const std::map< raw_tag_t, const FieldEnumsBase * const > & rawToEnum      = enumsByRaw;

#include <DSTINCDIR/Fields.cxx>

void checkEnums()
{
    for( auto it : enumsByRaw )
    {
        const FieldEnumsBase * enums = it.second;
        const FieldEnumMap & emap =  enums->getEnumMapByRaw();
        auto mapSz = emap.size();
        size_t enumCount = 0;
        for( const FieldEnumBase * const * eptr = enums->getEnums(); eptr && *eptr; ++eptr )
        {
            ++enumCount;
        }
        
        if( enumCount != mapSz )
        {
            std::cerr << "Enum size missmatch " << enums->getFieldName() << " no.items=" << enumCount << " map.size=" << mapSz << std::endl;
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

}
