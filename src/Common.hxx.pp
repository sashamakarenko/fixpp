
#define FIX_MSG_FIELD(NAME) \
<n1> public:\
<n1> bool isSet##NAME() const { return field##NAME.offset > 0; }\
<n1> Field##NAME::ValueType get##NAME() const { return field##NAME.getValue( _fixPtr ); }\
<n1> std::string_view get##NAME##View() const { return field##NAME.offset > 0 ? std::string_view{ _fixPtr + field##NAME.offset, getValueLength( _fixPtr + field##NAME.offset ) } : std::string_view{}; }\
<n1> const char * ptrTo##NAME() const { return _fixPtr + field##NAME.offset; }\
<n1> const char * ptrToTag##NAME() const { return _fixPtr + field##NAME.offset - 1 - Field##NAME::tagWidth(); }\
<n1> const char * getIfSet##NAME() const { return field##NAME.offset > 0 ? _fixPtr + field##NAME.offset : nullptr; }\
<n1> private: Field##NAME field##NAME;\

#define FIX_MSG_GROUP(NAME) FIX_MSG_FIELD(No##NAME)\
<n1>\
<n1> public:\
<n1> std::size_t getGroupCount##NAME() const { return groups##NAME.size(); } \
<n1> const Group##NAME & getGroup##NAME( std::size_t idx ) const { return groups##NAME[ idx ]; } \
<n1> private: Group##NAME::Array groups##NAME{ 10 };

