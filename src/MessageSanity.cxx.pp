<com> Generated

<com> ---------------------------------- findBadField ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
const char * Message##NAME::findBadField() const {\
<n1>  if( _fixPtr == nullptr ) return nullptr;

#define FIX_MSG_FIELD(NAME) \
<t1>  if( field##NAME.offset > 0 ){\
<n3>      const char * tagPtr = _fixPtr + field##NAME.offset - 1 - Field##NAME::tagWidth();\
<n3>      if( not isGoodTag( tagPtr ) or _fixPtr[field##NAME.offset] == 1 ) return tagPtr;\
<n1>  }

#define FIX_MSG_GROUP(NAME) \
<t1>  if( fieldNo##NAME.offset > 0 ){\
<n2>    const char * tagPtr = _fixPtr + fieldNo##NAME.offset - 1 - FieldNo##NAME::tagWidth();\
<n2>    if( not isGoodTag( tagPtr ) or _fixPtr[fieldNo##NAME.offset] == 1 ) return tagPtr;\
<n2>    for( auto & g : groups##NAME ){\
<n3>      if( g.getMessageBuffer() == nullptr ) break;\
<n3>      tagPtr = g.findBadField();\
<n3>      if( tagPtr ) return tagPtr;\
<n2>    }\
<n1> }

#define FIX_MSG_END \
<t1>  return nullptr;\
<nl>}

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- findBadGroup ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
const char * Message##NAME::findBadGroup( unsigned & noExpected, unsigned & noReceived ) const {\
<n1>  if( _fixPtr == nullptr ) return nullptr;

#define FIX_MSG_FIELD(NAME) <remove-me>

#define FIX_MSG_GROUP(NAME) \
<t1>  if( fieldNo##NAME.offset > 0 ){\
<n2>    unsigned expected = fromString<unsigned>( _fixPtr + fieldNo##NAME.offset );\
<n2>    unsigned received = 0;\
<n2>    for( auto & g : groups##NAME ){\
<n3>      if( g.getMessageBuffer() == nullptr ) break;\
<n3>      const char * badSubgroup = g.findBadGroup( noExpected, noReceived );\
<n3>      if( badSubgroup ) return badSubgroup;\
<n3>      ++received;\
<n2>    }\
<n2>    if( expected != received ) { noExpected = expected; noReceived = received; return _fixPtr + fieldNo##NAME.offset - 1 - FieldNo##NAME::tagWidth(); }\
<n1> }

#define FIX_MSG_END \
<t1>  return nullptr;\
<nl>}

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- findBadEnum ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
const char * Message##NAME::findBadEnum() const {\
<n1>  if( _fixPtr == nullptr ) return nullptr;

#define FIX_MSG_FIELD(NAME) <remove-me>

#define FIX_MSG_ENUM_FIELD(NAME) \
<t1>  if( field##NAME.offset > 0 and NAME##Enums::findEnum( toRawEnum( _fixPtr + field##NAME.offset ) ) == nullptr ){\
<n3>      return _fixPtr + field##NAME.offset - 1 - Field##NAME::tagWidth();\
<n1>  }

#define FIX_MSG_GROUP(NAME) \
<t1>  if( fieldNo##NAME.offset > 0 ){\
<n2>    for( auto & g : groups##NAME ){\
<n3>      if( g.getMessageBuffer() == nullptr ) break;\
<n3>      const char * tagPtr = g.findBadEnum();\
<n3>      if( tagPtr ) return tagPtr;\
<n2>    }\
<n1> }

#define FIX_MSG_END \
<t1>  return nullptr;\
<nl>}

#include <MessageEnums.tmp>


