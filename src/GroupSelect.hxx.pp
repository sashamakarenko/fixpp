<com> Generated

<com> -------------------------------------- select ----------------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
template< typename... FIELDS > \
offset_t Group##NAME::select( Array & arr, const char * fix, unsigned len ){\
<nl> Group##NAME * group = nullptr; \
<nl> offset_t prev = 0, pos = 0, gpos = 0;\
<nl> if( loadRawTag( fix, gpos ) != Field##FIRST_FIELD::RAW_TAG ) return 0;\
<nl> const char * groupBuf = fix; \
<nl> unsigned groupCount = 0; \
<nl> while( pos < (int)len ) { \
<n1>  bool posIsOnNextField = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  gpos = pos - (groupBuf - fix);\
<n1>  switch( tag ){\
<n1>  case Field##FIRST_FIELD::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(FIRST_FIELD)\
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    group = groupCount < arr.size() ? & arr[ groupCount ] : & arr.emplace_back();\
<n2>    if constexpr ( wanted<Field##FIRST_FIELD,FIELDS...>() ) group->field##FIRST_FIELD.offset = pos - prev;\
<n2>    groupBuf = fix+prev;\
<n2>    group->_fixPtr = groupBuf;\
<n2>    ++groupCount;\
<n2>    break;\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(NAME)\
<n2>    if constexpr ( wanted<Field##NAME,FIELDS...>() ) group->field##NAME.offset = gpos;\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(No##NAME)\
<n2>    if constexpr ( wanted<FieldNo##NAME,FIELDS...>() ) group->fieldNo##NAME.offset = gpos;\
<n2>    posIsOnNextField = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::select<FIELDS...>( group->groups##NAME, fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_GROUP_END \
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    if( group ) group->_fixLength = gpos;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! posIsOnNextField ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  if( group ) group->_fixLength = gpos;\
<nl>  return pos;\
<nl>}\

#include <Groups.def>
