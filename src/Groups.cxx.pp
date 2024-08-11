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

<com> ---------------------------------- getFieldValue ---------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD ) \
const char * Group##NAME::getFieldValue( unsigned tag ) const {\
<n1>  if( _fixPtr == nullptr ) return nullptr;\
<n1>  switch( tag ){\
<n2>  case Field##FIRST_FIELD::TAG : return field##FIRST_FIELD.offset > 0 ? _fixPtr + field##FIRST_FIELD.offset : nullptr;

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::TAG : return field##NAME.offset > 0 ? _fixPtr + field##NAME.offset : nullptr; \

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::TAG : return fieldNo##NAME.offset > 0 ? _fixPtr + fieldNo##NAME.offset : nullptr; \

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

<com> ---------------------------------- isFieldSet ---------------------------------

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD ) \
bool Group##NAME::isFieldSet( unsigned tag ) const {\
<n1>  if( _fixPtr == nullptr ) return false;\
<n1>  switch( tag ){\
<n2>  case Field##FIRST_FIELD::TAG : return field##FIRST_FIELD.offset > 0 ;

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::TAG : return field##NAME.offset > 0; \

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::TAG : return fieldNo##NAME.offset > 0; \

#define FIX_MSG_GROUP_END \
<n2>  default :  return false; \
<n1>  }\
<n1>  return false;\
<nl>}\


#include <Groups.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP_BEGIN
#undef FIX_MSG_GROUP_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- getKnownFields ---------------------------------

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
