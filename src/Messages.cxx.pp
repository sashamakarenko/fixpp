<com> Generated
<com> -------------------------- getMessageName getMessageType -------------------------

const std::string EMPTY_STRING;

#define FIX_FIELD_BEGIN_STRING( STR )

#define FIX_MSG_BEGIN(NAME,TYPE) \
const char * Message##NAME::getMessageName(){\
<n2> return #NAME;\
<nl>}\
<nl>\
<nl>const std::string & Message##NAME::getMessageType(){\
<n2> return MsgTypeEnums::TYPE.str;\
<nl>}

#define FIX_MSG_FIELD(NAME)
#define FIX_MSG_GROUP(NAME)
#define FIX_MSG_END

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- field depth ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
GetDepthMethod Message##NAME::groupGetDepthMethods[] = {

#define FIX_MSG_FIELD(NAME) <remove-me>

#define FIX_MSG_GROUP(NAME) \
<t1>Group##NAME::getFieldDepth,

#define FIX_MSG_END \
<t1>nullptr };\

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<nl>

#define FIX_MSG_BEGIN(NAME,TYPE) \
FieldDepth Message##NAME::getFieldDepth( raw_tag_t tag ){\
<n1>  FieldDepth ret;\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::RAW_TAG :

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::RAW_TAG :

#define FIX_MSG_END \
<t2>  case FieldCheckSum::RAW_TAG :\
<n2>  ret.depth = 0; \
<n2>  return ret; \
<n1>  }\
<n1>  for( auto m : groupGetDepthMethods ) if( m ){\
<n2>      FieldDepth gdepth = (*m)( tag ); \
<n2>      if( gdepth.depth >= 0 ) { return gdepth.inc(); }\
<n1>  }\
<n1>  return ret;\
<nl>}\


#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<nl>

<com> ---------------------------------- get<field> ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
<def> FIXPP_MSG_CLASS Message##NAME

#define FIX_MSG_FIELD(NAME) \
template<> Field##NAME::ValueType FIXPP_MSG_CLASS::get<Field##NAME>() const { return get##NAME(); }

#define FIX_MSG_GROUP(NAME) \
template<> FieldNo##NAME::ValueType FIXPP_MSG_CLASS::get<FieldNo##NAME>() const { return getNo##NAME(); }

#define FIX_MSG_END \
<undef> FIXPP_MSG_CLASS

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- getFieldValue ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
const char * Message##NAME::getFieldValue( unsigned tag ) const {\
<n1>  if( _fixPtr == nullptr ) return nullptr;\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::TAG : return field##NAME.offset > 0 ? _fixPtr + field##NAME.offset : nullptr; \

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::TAG : return fieldNo##NAME.offset > 0 ? _fixPtr + fieldNo##NAME.offset : nullptr; \

#define FIX_MSG_END \
<t2>  case FieldCheckSum::TAG : return fieldCheckSum.offset > 0 ? _fixPtr + fieldCheckSum.offset : nullptr; \
<n2>  default :  return nullptr; \
<n1>  }\
<n1>  return nullptr;\
<nl>}\


#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- isFieldSet ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
bool Message##NAME::isFieldSet( unsigned tag ) const {\
<n1>  if( _fixPtr == nullptr ) return false;\
<n1>  switch( tag ){\

#define FIX_MSG_FIELD(NAME) \
<t2>  case Field##NAME::TAG : return field##NAME.offset > 0; \

#define FIX_MSG_GROUP(NAME) \
<t2>  case FieldNo##NAME::TAG : return fieldNo##NAME.offset > 0; \

#define FIX_MSG_END \
<t2>  case FieldCheckSum::TAG : return fieldCheckSum.offset > 0; \
<n2>  default :  return false; \
<n1>  }\
<n1>  return false;\
<nl>}\

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> ---------------------------------- getKnownFields ---------------------------------

#define FIX_MSG_BEGIN(NAME,TYPE) \
const std::vector<tag_t> NAME##_knownFields = {

#define FIX_MSG_FIELD(NAME) Field##NAME::TAG,

#define FIX_MSG_GROUP(NAME) FieldNo##NAME::TAG,

#define FIX_MSG_END FieldCheckSum::TAG };

namespace {
#include <Messages.def>

}

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<nl>
#define FIX_MSG_BEGIN(NAME,TYPE) \
const std::vector<tag_t> & Message##NAME::getKnownFields(){ return NAME##_knownFields; }

#define FIX_MSG_FIELD(NAME) <remove-me>
#define FIX_MSG_GROUP(NAME) <remove-me>
#define FIX_MSG_END <remove-me>

#include <Messages.def>

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<nl>

#define FIX_MSG_BEGIN(NAME,TYPE) \
<t1> case MsgTypeRaw_##TYPE :\
<n2> return Message##NAME::getFieldDepth;

#define FIX_MSG_FIELD(NAME)  <remove-me>
#define FIX_MSG_GROUP(NAME)  <remove-me>
#define FIX_MSG_END <remove-me>

GetDepthMethod getTagDepthMethodByRawMsgType( raw_enum_t rawMsgType ){
  switch( rawMsgType ){
#include <Messages.def>
  }
  return nullptr;
}

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- ParserDispatcher ----------------------------------------

#define FIX_MSG_FIELD(NAME)
#define FIX_MSG_GROUP(NAME)
#define FIX_MSG_END

const char * ParserDispatcher::parseAndDipatch( const char * buf, unsigned len, bool resetMessage )
{
    if( resetMessage )
    {
        _msgHeader.reset();
    }
    offset_t pos = _msgHeader.scan( buf, len );

    unsigned bodyLength = _msgHeader.getBodyLength();
    const char * endOfMessage = _msgHeader.ptrToMsgType() + bodyLength + 4; <icom> 7 for checkSum - 3 for msg type tag
    if( endOfMessage - buf > (std::ptrdiff_t)len )
    {
        return nullptr;
    }

    const raw_enum_t msgType = toRawEnum( _msgHeader.ptrToMsgType() );
    if( ignoreMessage( msgType ) )
    {
      return endOfMessage;
    }

    buf += pos;
    switch( msgType )
    {
#undef FIX_MSG_BEGIN
#define FIX_MSG_BEGIN(NAME,TYPE) \
<com> case-begin-TYPE\
<com> After generation one can sed this out if TYPE is not incoming message\
<n3>case MsgTypeRaw_##TYPE : {\
<n3>  if( resetMessage ) _msg##NAME.reset();\
<n3>  pos = _msg##NAME.scan( buf, len - pos );\
<n3>  onMessage( _msg##NAME );\
<n3>  break;\
<n3>}\
<com> case-end-TYPE
#include <Messages.def>
      default:
        onUnknownMessage( msgType );
        return endOfMessage;
    }
    return buf + pos;
}

#undef FIX_MSG_BEGIN
#define FIX_MSG_BEGIN(NAME,TYPE)\
<com> on-message-begin-TYPE\
<com> After generation one can sed this out if TYPE is not incoming message\
<nl>void ParserDispatcher::onMessage( Message##NAME & msg )\
<nl>{\
<n1>  unprocessedMessage( MsgTypeRaw_##TYPE, msg ); \
<n1>  msg.reset(); \
<nl>}\
<com> on-message-end-TYPE

#include <Messages.def>
