#pragma once
#ifndef fix44_FIELDS_H
#define fix44_FIELDS_H

#include <fix44/FixApi.h>

#include <iostream>
#include <map>

std::ostream & operator << ( std::ostream & os, const fix44::sohstr & str );

namespace fix44
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

#include <fix44/Fields.hxx>

void checkEnums();

}

#endif // fix44_FIELDS_H
