__COPYRIGHT__
#pragma once
#ifndef DSTHEADERGUARD_FIELDS_H
#define DSTHEADERGUARD_FIELDS_H

#include <DSTINCDIR/FixApi.h>

#include <iostream>
#include <map>
#include <tuple>

namespace DSTNAMESPACE
{

template< typename Any >
using typeExists = bool;

template< typename Msg, typename Field >
struct hasField { using type = typeExists< typename Msg::Field >; static constexpr bool value = true; };

template< typename MsgType, unsigned idx, typename... Fields >
void buildTuple( const MsgType & msg, std::tuple<typename Fields::ValueType...> & tpl )
{
    if( msg.isFieldSet( std::tuple_element_t<idx,std::tuple<Fields...> > ::TAG ) )
    {
        std::get<idx>(tpl) = msg.template get< std::tuple_element_t<idx,std::tuple<Fields...> > >();
    }
    if constexpr ( idx + 1 < sizeof...(Fields) )
    {
        buildTuple<MsgType,idx+1,Fields...>( msg, tpl );
    }
}

template< typename MsgType, unsigned idx, typename... Fields >
void buildPresenceTuple( const MsgType & msg, std::tuple<typeExists<Fields>...> & tpl )
{
    std::get<idx>(tpl) = msg.isFieldSet( std::tuple_element_t<idx,std::tuple<Fields...> > ::TAG );
    if constexpr ( idx + 1 < sizeof...(Fields) )
    {
        buildPresenceTuple<MsgType,idx+1,Fields...>( msg, tpl );
    }
}

struct FieldDepth
{
    int16_t depth          = -1;
    int16_t isFirstInGroup = false;

    const FieldDepth & inc()
    {
        ++depth;
        return *this;
    }
};

typedef FieldDepth (*GetDepthMethod)( raw_tag_t );

extern const std::map< raw_tag_t  , const char * const >           & RAW_TAG_TO_NAME;
extern const std::map< tag_t      , const char * const >           & TAG_TO_NAME;
extern const std::map< raw_tag_t  , const FieldEnumsBase * const > & RAW_TO_ENUM;
extern const std::map< tag_t      , const FieldEnumsBase * const > & TAG_TO_ENUM;
extern const std::map< std::string, tag_t >                        & FIELD_NAME_TO_TAG;
extern const std::map< tag_t      , FieldType >                    & TAG_TO_FIELD_TYPE;
extern const std::map< tag_t      , const std::string >            & TAG_TO_FIELD_TYPE_NAME;

tag_t getFieldTag( const std::string & fieldName );

const char * getFieldName( tag_t tagValue );

FieldType getFieldType( tag_t tagValue );

const std::string & getFieldTypeName( tag_t tagValue );

bool isHeaderField( tag_t tagValue );

#include <DSTINCDIR/Fields.hxx>

void checkEnums();

}  // namespace DSTNAMESPACE


// Uncomment this to debug parser
// #define FIXPP_DEBUG_PARSER

#ifdef FIXPP_DEBUG_PARSER
#define FIXPP_PRINT_FIELD(NAME) std::cout << Field##NAME::tagName() << "(" << Field##NAME::tagKey() << ") = " << sohstr( fix+pos ) << std::endl;
#define FIXPP_PRINT_UNKNOWN_FIELD std::cout << "- unknown " << tag << " in " << getMessageName() << ":" << pos << " " << sohstr( fix+prev ) << std::endl;
#else
#define FIXPP_PRINT_FIELD(NAME)
#define FIXPP_PRINT_UNKNOWN_FIELD
#endif


#endif // DSTHEADERGUARD_FIELDS_H
