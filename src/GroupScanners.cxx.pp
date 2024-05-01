<com> Generated

<com> -------------------------------------- scan ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
offset_t Group##NAME::scan( Array & arr, const char * fix, unsigned len ){\
<nl> Group##NAME * group = nullptr; \
<nl> offset_t prev = 0, pos = 0, gpos = 0;\
<nl> if( loadRawTag( fix, gpos ) != Field##FIRST_FIELD::RAW_TAG ) return 0;\
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
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    group = groupCount < arr.size() ? & arr[ groupCount ] : & arr.emplace_back();\
<n2>    group->field##FIRST_FIELD.offset = pos - prev;\
<n2>    groupBuf = fix+prev;\
<n2>    group->_fixPtr = groupBuf;\
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
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  if( group ) group->_fixLength = gpos;\
<nl>  return pos;\
<nl>}\

#include <Groups.def>

#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- scanSafely ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
offset_t Group##NAME::scanSafely( Array & arr, const char * fix, unsigned len, unsigned & groupCount, const char * & badFieldPtr ){\
<nl> Group##NAME * group = nullptr; \
<nl> offset_t prev = 0, pos = 0, gpos = 0;\
<nl> groupCount = 0; \
<nl> if( loadRawTag( fix, gpos ) != Field##FIRST_FIELD::RAW_TAG ) return 0;\
<nl> const char * groupBuf = fix; \
<nl>while( pos < (int)len ) {\
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  if( not isGoodTag( fix+pos ) ) {badFieldPtr = fix + pos; break; }\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  if( fix[pos] == 1 ) { if( group ) group->_fixLength = prev; badFieldPtr = fix + prev; return pos; }\
<n1>  gpos = pos - (groupBuf - fix);\
<n1>  switch( tag ){\
<n1>  case Field##FIRST_FIELD::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(FIRST_FIELD)\
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    group = groupCount < arr.size() ? & arr[ groupCount ] : & arr.emplace_back();\
<n2>    group->field##FIRST_FIELD.offset = pos - prev;\
<n2>    groupBuf = fix+prev;\
<n2>    group->_fixPtr = groupBuf;\
<n2>    ++groupCount;\
<n2>    break;\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(NAME)\
<n2>    if( group->field##NAME.offset < 0 ) group->field##NAME.offset = gpos;\
<n2>    else { group->_fixLength = prev; badFieldPtr = fix + prev; return pos; }\
<n2>    break;\

#define FIX_MSG_ENUM_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(NAME) \
<n2>    if( group->field##NAME.offset < 0 ) {\
<n3>      group->field##NAME.offset = gpos;\
<n3>      if( NAME##Enums::findEnum( toRawEnum( group->_fixPtr + gpos ) ) == nullptr )\
<n3>       { group->_fixLength = prev;  badFieldPtr = fix + prev; return pos; }\
<n2>    }\
<n2>    else { group->_fixLength = prev; return pos; }\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(No##NAME) \
<n2>    if( group->fieldNo##NAME.offset < 0 ){\
<n3>    group->fieldNo##NAME.offset = gpos;\
<n3>    isGroupStart = true;\
<n3>    {\
<n3>    int groupExpected = parseGroupNoValue( fix + pos );\
<n3>    unsigned groupFound = 0;\
<n3>    gotoNextField( fix, pos );\
<n3>    pos += Group##NAME::scanSafely( group->groups##NAME, fix+pos, len - pos, groupFound, badFieldPtr );\
<n3>    if( badFieldPtr != nullptr ) { group->_fixLength = badFieldPtr - fix; return pos; }\
<n3>    if( (int)groupFound != groupExpected ) { group->_fixLength = prev; badFieldPtr = fix + prev; return pos; }\
<n3>    }\
<n2>    } else { group->_fixLength = prev;  badFieldPtr = fix + prev; return pos; }\
<n2>    break;\

#define FIX_MSG_GROUP_END \
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  if( group ) group->_fixLength = gpos;\
<nl>  return pos;\
<nl>}\

#include <GroupEnums.tmp>

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

<nl>

<com> -------------------------------------- reset ----------------------------------------


#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
void Group##NAME::reset(){\
<n2>    _fixPtr = nullptr;\
<n2>    _fixLength = 0;

#define FIX_MSG_FIELD(NAME) <t2> field##NAME.offset = -1;

#define FIX_MSG_GROUP(NAME) \
<t2> fieldNo##NAME.offset = -1;\
<n2> for( auto g = groups##NAME.begin(); g != groups##NAME.end() and g->getMessageBuffer(); ++g ) g->reset();

#define FIX_MSG_GROUP_END }


#include <Groups.def>
