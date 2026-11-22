<com> Generated

<com> -------------------------------------- select ----------------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
template< typename... FIELDS > \
<nl>offset_t Message##NAME::select( const char * fix, unsigned len ){\
<nl>_fixPtr = fix;\
<nl>offset_t prev = 0, pos = 0;\
<nl>while( pos < (int)len ) {\
<n1>  bool posIsOnNextField = false;\
<n1>  prev = pos;\
<n1>  raw_tag_t tag = loadRawTag( fix+pos, pos );\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<n1>  case Field##NAME::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(NAME) \
<n2>    if constexpr ( wanted<Field##NAME,FIELDS...>() or wanted<AllFields,FIELDS...>() ) field##NAME.offset = pos;\
<n2>    if constexpr ( wanted<StopOn<Field##NAME>,FIELDS...>() ) return pos;\
<n2>    break;\

#define FIX_MSG_GROUP(NAME) \
<n1>  case FieldNo##NAME::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(No##NAME) \
<n2>    if constexpr ( wanted<FieldNo##NAME,FIELDS...>() or wanted<AllFields,FIELDS...>() ) fieldNo##NAME.offset = pos;\
<n2>    if constexpr ( wanted<StopOn<FieldNo##NAME>,FIELDS...>() ) return pos;\
<n2>    posIsOnNextField = true;\
<n2>    gotoNextField( fix, pos );\
<n2>    pos += Group##NAME::select<FIELDS...>( groups##NAME, fix+pos, len - pos );\
<n2>    break;\

#define FIX_MSG_END \
<n1>  case FieldCheckSum::RAW_TAG:\
<n2>    FIXPP_PRINT_FIELD(CheckSum) \
<n2>    if constexpr ( wanted<FieldCheckSum,FIELDS...>() or wanted<AllFields,FIELDS...>() ) fieldCheckSum.offset = pos;\
<n2>    gotoNextField( fix, pos );\
<n2>    _fixLength = pos;\
<n2>    return pos;\
<nl>\
<n1>  default: FIXPP_PRINT_UNKNOWN_FIELD\
<n2>    _fixLength = prev;\
<n2>    return prev;\
<n1>    }\
<n1>  if( ! posIsOnNextField ) gotoNextField( fix, pos );\
<nl>  }\
<nl>  _fixLength = pos;\
<nl>  return pos;\
<nl>}\

#include <Messages.def>

