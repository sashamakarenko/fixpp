#pragma once
#ifndef DSTHEADERGUARD_FIELDS_H
#define DSTHEADERGUARD_FIELDS_H

#include <DSTINCDIR/FixApi.h>

#include <iostream>
#include <map>

std::ostream & operator << ( std::ostream & os, const DSTNAMESPACE::sohstr & str );

namespace DSTNAMESPACE
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

#include <DSTINCDIR/Fields.hxx>

void checkEnums();

}  // namespace DSTNAMESPACE

#endif // DSTHEADERGUARD_FIELDS_H
