<com> Generated

#define FIX_MSG_FIELD(NAME) \
<t2> void append##NAME( ARGS ){ appendSafely<Field##NAME>( VALUES ); }

#define FIX_MSG_GROUP(NAME) \
<t2> NAME##Builder & appendNo##NAME( unsigned count ) { appendSafely<FieldNo##NAME>( count ); return *reinterpret_cast<NAME##Builder*>( this ); }

#define FIX_MSG_GROUP_BEGIN( NAME, FIRST_FIELD )\
<com> Group NAME\
<nl>class NAME##Builder : protected ReusableMessageBuilder\
<nl>{\
<n1>    public:\
<nl>FIX_MSG_FIELD(FIRST_FIELD)

#define FIX_MSG_GROUP_END \
};

#include <Groups.def>

#define FIX_MSG_BEGIN(NAME,TYPE) \
<com> Message NAME\
<nl>class NAME##Builder: protected ReusableMessageBuilder\
<nl>{\
<n1>    public:\
<nl>\
<n2>        static NAME##Builder & New( ReusableMessageBuilder & builder ){ return reinterpret_cast<NAME##Builder&>( builder ); }\
<n2>        HeaderBuilder & getHeader-NAME@(){ return reinterpret_cast<HeaderBuilder&>( header ); }

#define FIX_MSG_END \
};


#include <Messages.def>
