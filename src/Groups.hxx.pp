<com> Generated

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
class Group##NAME : public MessageBase\
<nl>{\
<n1><com>  Methods\
<n1>    public:\
<n1>    Group##NAME();\
<n1>    typedef std::vector<Group##NAME> Array;\
<n1>    void reset();\
<n1>    static const char * getMessageName();\
<n1>    static offset_t scan( Array & arr, const char * fix, unsigned len );\
<n1>    static offset_t scanSafely( Array & arr, const char * fix, unsigned len, unsigned & groupCount, const char * & badFieldPtr );\
<n1>    static offset_t skip( const char * fix, unsigned len );\
<n1>    const char * getFieldValue( unsigned tag ) const;\
<n1>    const char * findBadField() const;\
<n1>    const char * findBadGroup( unsigned & noExpected, unsigned & noReceived ) const;\
<n1>    const char * findBadEnum() const;\
<n1>    static FieldDepth getFieldDepth( raw_tag_t tag );\
<n1>    static const std::vector<unsigned> & getKnownFields();\
<n1>    private: static GetDepthMethod groupGetDepthMethods[];\
<n1>    FIX_MSG_FIELD(FIRST_FIELD)\

#include <src/Common.hxx.pp>

#define FIX_MSG_GROUP_END \
<nl>};

#include <Groups.def>

