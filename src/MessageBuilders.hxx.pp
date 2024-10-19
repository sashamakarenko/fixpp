#define FIX_MSG_FIELD(NAME) \
<t2> void append##NAME( ARGS ){ appendSafely<Field##NAME>( VALUES ); }\
<n2> void append##NAME( ALTARGS ){ appendSafely<Field##NAME>( ALTVALUES ); }\

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
<n2>        static NAME##Builder & Ref( ReusableMessageBuilder & builder ){ return reinterpret_cast<NAME##Builder&>( builder ); }\
<n2>        HeaderBuilder & getHeader-NAME@(){ return reinterpret_cast<HeaderBuilder&>( header ); }\
<n2>        ReusableMessageBuilder & super-NAME@(){ return *this; }\
<n2>        void finalizeWithSeqnum-NAME@( unsigned seqnum ){ setSeqnumAndUpdateHeaderAndChecksum( seqnum ); }

#define FIX_MSG_END \
};


#include <Messages.def>
