__COPYRIGHT__

#include <DSTINCDIR/Messages.h>

namespace DSTNAMESPACE
{

template<typename T, typename ...Types>
constexpr bool wanted()
{
    return ( std::is_same<T,Types>() or ... );
};

struct AllFields: FieldBase
{
};

template< typename FIELD >
struct StopOn: FieldBase
{
static_assert( std::is_base_of_v<FieldBase,FIELD> or std::is_same_v<FIELD,AllFields>, "not a Field type" ); 
};

#include <DSTINCDIR/GroupSelect.hxx>

#include <DSTINCDIR/MessageSelect.hxx>


} // namespace DSTNAMESPACE
