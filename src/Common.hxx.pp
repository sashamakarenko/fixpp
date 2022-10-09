
#define FIX_MSG_FIELD(NAME) \
<n1> public:\
<n1> bool isSet##NAME() const { return field##NAME.offset >= 0; }\
<n1> Field##NAME::ValueType get##NAME() const { return field##NAME.getValue( buf ); }\
<n1> const char * ptrTo##NAME() const { return buf + field##NAME.offset; }\
<n1> private: Field##NAME field##NAME;\

#define FIX_MSG_GROUP(NAME) FIX_MSG_FIELD(No##NAME)\
<n1>\
<n1> public:\
<n1> std::size_t getGroupCount##NAME() const { return groups##NAME.size(); } \
<n1> const Group##NAME & getGroup##NAME( std::size_t idx ) const { return groups##NAME[ idx ]; } \
<n1> private: Group##NAME::Array groups##NAME{ 10 };

