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

#define DEBUG_PARSERx

#ifdef DEBUG_PARSER
#define PRINT_FIELD(NAME) std::cout << Field##NAME::tagName() << "(" << Field##NAME::tagKey() << ") = " << sohstr( fix+pos ) << std::endl;
#define PRINT_UNKNOWN std::cout << "- unknown " << tag << " in " << getMessageName() << ":" << pos << " " << sohstr( fix+prev ) << std::endl;
#else
#define PRINT_FIELD(NAME)
#define PRINT_UNKNOWN
#endif


#endif // DSTHEADERGUARD_FIELDS_H
