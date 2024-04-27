<com> Generated

<com> -------------------------------------- scan ----------------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
offset_t Message##NAME::scan( const char * fix, unsigned len ){\
<nl>_fixPtr = fix;\
<nl>offset_t prev = 0, pos = 0;\
<nl>while( pos < (int)len ) {\
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(NAME) \
<n2>    field##NAME.offset = pos;\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(No##NAME) \
<n2>    fieldNo##NAME.offset = pos;\
<n2>    isGroupStart = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::scan( groups##NAME, fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_END \
<n1>  case FieldCheckSum::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(CheckSum) \
<n2>    fieldCheckSum.offset = pos;\
<n2>    gotoNextField( fix, pos );\
<n2>    _fixLength = pos;\
<n2>    return pos;\
<nl>\
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    _fixLength = prev;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  _fixLength = pos;\
<nl>  return pos;\
<nl>}\

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- scanSafely ----------------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
offset_t Message##NAME::scanSafely( const char * fix, unsigned len ){\
<nl>_fixPtr = fix;\
<nl>offset_t prev = 0, pos = 0;\
<nl>bool keepScanning = true;\
<nl>while( pos < (int)len and keepScanning ) {\
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  if( not isGoodTag( fix+pos ) ) break;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  if( fix[pos] == 1 ) break;\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(NAME) \
<n2>    if( field##NAME.offset < 0 ) field##NAME.offset = pos;\
<n2>    else keepScanning = false;\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(No##NAME) \
<n2>    if( fieldNo##NAME.offset < 0 ){\
<n3>    fieldNo##NAME.offset = pos;\
<n3>    isGroupStart = true;\
<n3>    {\
<n3>    int groupExpected = parseGroupNoValue( fix + pos );\
<n3>    unsigned groupFound = 0;\
<n3>    gotoNextField( fix, pos );\
<n3>    pos += Group##NAME::scanSafely( groups##NAME, fix+pos, len - pos, groupFound );\
<n3>    if( (int)groupFound != groupExpected ) keepScanning = false;\
<n3>    }\
<n2>    } else keepScanning = false;\
<n2>    break;\

#define FIX_MSG_END \
<n1>  case FieldCheckSum::RAW_TAG :\
<n2>    FIXPP_PRINT_FIELD(CheckSum) \
<n2>    fieldCheckSum.offset = pos;\
<n2>    gotoNextField( fix, pos );\
<n2>    _fixLength = pos;\
<n2>    return pos;\
<nl>\
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    _fixLength = prev;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  _fixLength = pos;\
<nl>  return pos;\
<nl>}\

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- skip ----------------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
offset_t Message##NAME::skip( const char * fix, unsigned len ) const\
<nl>{\
<nl>offset_t prev = 0, pos = 0;\
<nl>gotoNextField( fix, pos );\
<nl>while( pos < (int)len ) {\
<n1>  bool isGroupStart = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG :\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG :\
<n2>    isGroupStart = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::skip( fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_END \
<n1>  case FieldCheckSum::RAW_TAG :\
<n2>    gotoNextField( fix, pos );\
<n2>    return pos;\
<nl>\
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! isGroupStart ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  return pos;\
<nl>}\

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- reset ----------------------------------------


#define FIX_MSG_BEGIN(NAME,TYPE) \
void Message##NAME::reset(){\
<n2> _fixPtr = nullptr;\
<n2> _fixLength = 0;

#define FIX_MSG_FIELD(NAME) <t2> field##NAME.offset = -1;

#define FIX_MSG_GROUP(NAME) \
<t2> for( auto g = groups##NAME.begin(); g != groups##NAME.end() and g->getMessageBuffer(); ++g ) g->reset();

#define FIX_MSG_END \
<t2> fieldCheckSum.offset = -1;\
<nl>}\

#include <Messages.def>
