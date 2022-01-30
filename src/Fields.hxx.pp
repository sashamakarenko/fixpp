<com> Generated
<com> -------------------------------------- names ----------------------------------------

#define FIX_FIELD_BEGIN_STRING( STR ) extern const std::string FixBeginStringValue; \
<nl>constexpr const char * const FixBeginStringInsertableTag = "8=" #STR; \
<nl>constexpr const unsigned FixBeginStringInsertableTagLength = BEGIN_STRING_LENGTH; \

#define FIX_ENUM_BEGIN( NAME )
#define FIX_ENUM_DECL( NAME, E, V )
#define FIX_ENUM_END

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
extern const char * const Fix##NAME;

#include <Fields.def>

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END

#undef FIX_FIELD_BEGIN_STRING
#define FIX_FIELD_BEGIN_STRING( STR )

<com> -------------------------------------- typedefs and enums ----------------------------------------

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
typedef Field< Fix##NAME, TAG, TYPE > Field##NAME;

#define FIX_ENUM_BEGIN( NAME ) \
struct NAME##Enums final: FieldEnumsBase {\
<n1>    typedef Field##NAME::ValueType ValueType;\
<n1>    typedef FieldEnum< ValueType > ItemType;\
<n1>    static const FieldEnumBase * items[];\
<n1>    static const FieldEnumMap itemByRaw;\
<n1>    static const NAME##Enums instance;\
<n1>    virtual const char * getFieldName() const override;\
<n1>    virtual const FieldEnumBase * getEnumByRaw( raw_enum_t raw ) const override;\
<n1>    virtual const FieldEnumMap & getEnumMapByRaw() const override;\
<n1>    virtual const FieldEnumBase * const * const getEnums() const override;


#define FIX_ENUM_DECL( NAME, E, V ) \
<t1> static const ItemType E;

#define FIX_ENUM_END \
};

#include <Fields.def>

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END

<com> -------------------------------------- convenience field namespace ----------------------------------------

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
typedef Field##NAME NAME;

#define FIX_ENUM_BEGIN( NAME )
#define FIX_ENUM_DECL( NAME, E, V )
#define FIX_ENUM_END

namespace field
{
#include <Fields.def>
}

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END
