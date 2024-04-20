<com> Generated

#define FIX_FIELD_BEGIN_STRING( STR )

#define FIX_MSG_BEGIN(NAME,TYPE) \
class Message##NAME: public MessageBase\
<nl>{\
<n1><com>  Methods\
<nl>\
<n1>    public:\
<n1>    static const char * getMessageName();\
<n1>    static const std::string & getMessageType();\
<n1>    offset_t scan( const char * fix, unsigned len );\
<n1>    offset_t skip( const char * fix, unsigned len ) const;\
<n1>    void reset();\
<n1>    const char * getFieldValue( tag_t tag ) const;\
<n1>    const char * findBadField() const;\
<n1>    const char * findBadGroup( unsigned & noExpected, unsigned & noReceived ) const;\
<n1>    static FieldDepth getFieldDepth( raw_tag_t tag );\
<n1>    static const std::vector<tag_t> & getKnownFields();\
<n1>    private: static GetDepthMethod groupGetDepthMethods[];\
<nl>\
<com>   Fields\

#include <src/Common.hxx.pp>

#define FIX_MSG_END \
<nl>    FIX_MSG_FIELD( CheckSum )\
<nl>};

#include <Messages.def>

#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP

#define FIX_MSG_FIELD(NAME)
#define FIX_MSG_GROUP(NAME)
#define FIX_MSG_END

<nl>
class ParserDispatcher
{
   public:

     virtual const char * parseAndDipatch( const char * buf, unsigned len, bool resetMessage = true );

   protected:

     ParserDispatcher();

     virtual ~ParserDispatcher() = 0;

     virtual void onUnknownMessage( raw_enum_t msgType );

     virtual bool ignoreMessage( raw_enum_t msgType ) const;

     virtual void unprocessedMessage( raw_enum_t msgType, MessageBase & msg );

     inline MessageHeader & getCurrentHeader() { return _msgHeader; }

<t2> <com> dispatching
 <com> onHeader will never be called
#define FIX_MSG_BEGIN(NAME,TYPE) \
 <t2> virtual void onMessage( Message##NAME & msg );

#include <Messages.def>

   private:

#undef FIX_MSG_BEGIN

#define FIX_MSG_BEGIN(NAME,TYPE) \
 <t2> Message##NAME _msg##NAME;

#include <Messages.def>

};

#undef FIX_MSG_FIELD
#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_GROUP

<com> -------------------------------------- convenience message namespace ----------------------------------------

#define FIX_FIELD_BEGIN_STRING( STR )

#define FIX_MSG_BEGIN(NAME,TYPE) \
typedef Message##NAME NAME;

#define FIX_MSG_FIELD(NAME)
#define FIX_MSG_GROUP(NAME)
#define FIX_MSG_END

namespace message
{
#include <Messages.def>
}

#undef FIX_MSG_BEGIN
#undef FIX_MSG_END
#undef FIX_MSG_FIELD
#undef FIX_MSG_GROUP
