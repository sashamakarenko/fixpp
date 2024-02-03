<com> Generated
<com> -------------------------------------- names ----------------------------------------

#define FIX_FIELD_BEGIN_STRING( STR ) const std::string FixBeginStringValue( #STR );


#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
const char * const Fix##NAME = #NAME;

#define FIX_ENUM_BEGIN( NAME )

#define FIX_ENUM_DECL( NAME, E, V ) \
const NAME##Enums::ItemType NAME##Enums::E( #E, V ); \

#define FIX_ENUM_END
        
#include <Fields.def>

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END

#undef FIX_FIELD_BEGIN_STRING
#define FIX_FIELD_BEGIN_STRING( STR )

<com> ------------------------------- enum items and type names -------------------------------------

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
template<> const FieldEnumBase * const * Field##NAME::enumItems = nullptr;\
<nl>template<> FieldType Field##NAME::getType() { return FieldType::TYPE; }\
<nl>template<> const std::string & Field##NAME::getTypeName() { static const std::string fixType{ #TYPE }; return fixType; }

#define FIX_ENUM_BEGIN( NAME ) \
<nl>const char * NAME##Enums::getFieldName() const { return Fix##NAME; }\
<nl>const FieldEnumBase * NAME##Enums::getEnumByRaw( raw_enum_t raw ) const  { auto it = itemByRaw.find(raw); return it == itemByRaw.end() ? nullptr : it->second; }\
<nl>const FieldEnumMap & NAME##Enums::getEnumMapByRaw() const { return NAME##Enums::itemByRaw; }\
<nl>const FieldEnumBase * const * const NAME##Enums::getEnums() const { return items; }\
<nl>const NAME##Enums NAME##Enums::instance;\
<nl>const FieldEnumBase * NAME##Enums::items[] = {\

#define FIX_ENUM_DECL( NAME, E, V ) \
& NAME##Enums::E,\

#define FIX_ENUM_END \
   nullptr \
};

#include <Fields.def>

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END

<com> -------------------------------------- enum maps ----------------------------------------

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) remove-me

#define FIX_ENUM_BEGIN( NAME ) \
const FieldEnumMap NAME##Enums::itemByRaw = { \

#define FIX_ENUM_DECL( NAME, E, V ) \
{ NAME##Enums::E.raw, & NAME##Enums::E }, \

#define FIX_ENUM_END \
};

// { 0, nullptr }

#include <Fields.def>

#undef FIX_FIELD_DECL
#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END

<com> -------------------------------------- init ----------------------------------------
<pragma> GCC push_options
<pragma> GCC optimize("O0")

#define FIX_ENUM_BEGIN( NAME ) <t1>Field##NAME::enumItems = NAME##Enums::items;\
<n1>enumsByRaw.emplace( Field##NAME::RAW, & NAME##Enums::instance );\
<n1>enumsByTag.emplace( Field##NAME::KEY, & NAME##Enums::instance );

#define FIX_ENUM_DECL( NAME, E, V ) remove-me

#define FIX_ENUM_END remove-me

#define FIX_FIELD_DECL( NAME, TAG, TYPE ) \
<n1>tagNameByRaw.emplace( tag_as_raw<TAG>(), Fix##NAME );\
<n1>tagNameByValue.emplace( TAG, Fix##NAME );\
<n1>tagByName.emplace( Fix##NAME, TAG );\
<n1>fieldTypeByValue.emplace( TAG, FieldType::TYPE );\
<n1>fieldTypeNameByValue.emplace( TAG, #TYPE );

<nl>
int initStatics()
{
#include <Fields.def>
  return 1;
}

volatile int initIndicator = initStatics();
<pragma> GCC pop_options

#undef FIX_ENUM_BEGIN
#undef FIX_ENUM_DECL
#undef FIX_ENUM_END
