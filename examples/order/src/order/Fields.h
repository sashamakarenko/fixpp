#pragma once
#ifndef order_FIELDS_H
#define order_FIELDS_H

#include <order/FixApi.h>

#include <iostream>
#include <map>

std::ostream & operator << ( std::ostream & os, const order::sohstr & str );

namespace order
{

struct FieldDepth
{
    int16_t depth = -1;
    int16_t isFirstInGroup = false;
    const FieldDepth & inc(){ ++depth; return *this; }
};

typedef FieldDepth (*GetDepthMethod)( raw_tag_t );

extern const std::map< raw_tag_t, const char * const >           & rawToTagName;
extern const std::map< unsigned, const char * const >            & valueToTagName;
extern const std::map< raw_tag_t, const FieldEnumsBase * const > & rawToEnum;

#include <order/Fields.hxx>

void checkEnums();

}

#endif // order_FIELDS_H
