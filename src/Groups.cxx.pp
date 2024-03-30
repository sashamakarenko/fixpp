<com> Generated
<com> -------------------------------------- getMessageName -------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
const char * Group##NAME::getMessageName(){\
<n2> return #NAME;\
<nl>}

#define FIX_MSG_FIELD(NAME)
#define FIX_MSG_GROUP(NAME)
#define FIX_MSG_GROUP_END 

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- constructor ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
Group##NAME::Group##NAME(){

#define FIX_MSG_FIELD(NAME) remove-me

#define FIX_MSG_GROUP(NAME) \
<n2>    groups##NAME.assign( 10, {} );

#define FIX_MSG_GROUP_END \
<nl>}\

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- scan ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
offset_t Group##NAME::scan( Array & arr, const char * fix, unsigned len ){\
<nl> Group##NAME * group = nullptr; \
<nl> offset_t prev = 0, pos = 0, gpos = 0;\
<nl> const char * groupBuf = fix; \
<nl> unsigned groupCount = 0; \
<nl> while( pos < (int)len ) { \
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  gpos = pos - (groupBuf - fix);\
<n1>  switch( tag ){\
<n1>  case Field##FIRST_FIELD::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(FIRST_FIELD)\
<n2>    group = groupCount < arr.size() ? & arr[ groupCount ] : & arr.emplace_back();\
<n2>    group->field##FIRST_FIELD.offset = pos - prev;\
<n2>    group->buf = fix+prev;\
<n2>    groupBuf = fix+prev;\
<n2>    ++groupCount;\
<n2>    break;\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(NAME)\
<n2>    group->field##NAME.offset = gpos;\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(No##NAME)\
<n2>    group->fieldNo##NAME.offset = gpos;\
<n2>    isGroupStart = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::scan( group->groups##NAME, fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_GROUP_END \
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  return pos;\
<nl>}\

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP
        
<com> -------------------------------------- skip ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
offset_t Group##NAME::skip( const char * fix, unsigned len ){\
<nl> offset_t prev = 0, pos = 0; \
<nl> while( pos < (int)len ) { \
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  switch( tag ){\
<n1>  case Field##FIRST_FIELD::RAW_TAG :\
<n2>    break;\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    isGroupStart = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::skip( fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_GROUP_END \
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  return pos;\
<nl>}\

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- getFieldDepth ---------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
GetDepthMethod Group##NAME::groupGetDepthMethods[] = {

#define FIX_MSG_FIELD(NAME) <remove-me>

#define FIX_MSG_GROUP(NAME)\
<t1> Group##NAME::getFieldDepth,

#define FIX_MSG_GROUP_END \
<t1> nullptr };\

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<nl>

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
FieldDepth Group##NAME::getFieldDepth( raw_tag_t tag ){\
<n1>  FieldDepth ret;\
<n1>  switch( tag ){\
<n2>  case Field##FIRST_FIELD::RAW_TAG :\
<n2>     ret.isFirstInGroup = true;\
<n2>     [[fallthrough]];

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::RAW_TAG :

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::RAW_TAG :

#define FIX_MSG_GROUP_END \
<n2>  case 0: \
<n2>  ret.depth = 0;\
<n2>  return ret;\
<n1>  }\
<n1>  for( auto m : groupGetDepthMethods ) if( m ){\
<n2>      FieldDepth gdepth = (*m)( tag ); \
<n2>      if( gdepth.depth >= 0 ) { return gdepth.inc(); }\
<n1>  }\
<n1>  return ret;\
<nl>}\

#include <Groups.def>
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD ) \
const char * Group##NAME::getFieldValue( unsigned tag ) const {\
<n1>  if( buf == nullptr ) return nullptr;\
<n1>  switch( tag ){\
<n2>  case Field##FIRST_FIELD::TAG : return field##FIRST_FIELD.offset >= 0 ? buf + field##FIRST_FIELD.offset : nullptr;

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::TAG : return field##NAME.offset >= 0 ? buf + field##NAME.offset : nullptr; \

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::TAG : return fieldNo##NAME.offset >= 0 ? buf + fieldNo##NAME.offset : nullptr; \

#define FIX_MSG_GROUP_END \
<n2>  default :  return nullptr; \
<n1>  }\
<n1>  return nullptr;\
<nl>}\


#include <Groups.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<nl>

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD ) \
const std::vector<unsigned> NAME##_knownFields = { Field##FIRST_FIELD::TAG

#define FIX_MSG_FIELD(NAME) , Field##NAME::TAG

#define FIX_MSG_GROUP(NAME) , FieldNo##NAME::TAG

#define FIX_MSG_GROUP_END };

namespace {
#include <Groups.def>

}

#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<nl>
#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD ) \
const std::vector<unsigned> & Group##NAME::getKnownFields(){ return NAME##_knownFields; }

#define FIX_MSG_FIELD(NAME) <remove-me>
#define FIX_MSG_GROUP(NAME) <remove-me>
#define FIX_MSG_GROUP_END <remove-me>

#include <Groups.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<nl>

<com> -------------------------------------- reset ----------------------------------------


#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
void Group##NAME::reset(){\
<n2>    buf = nullptr;
        
#define FIX_MSG_FIELD(NAME) <t2> field##NAME.offset = -1;

#define FIX_MSG_GROUP(NAME) \
<t2> for( auto g = groups##NAME.begin(); g != groups##NAME.end() and g->getMessageBuffer(); ++g ) g->reset();

#define FIX_MSG_GROUP_END }


#include <Groups.def>
