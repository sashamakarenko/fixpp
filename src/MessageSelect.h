__COPYRIGHT__

#include <DSTINCDIR/Messages.h>

namespace DSTNAMESPACE
{

template<typename T, typename ...Types>
constexpr bool wanted()
{
    return ( std::is_same<T,Types>() or ... );
};

template< typename FIELD >
struct StopOn
{
};

struct AllFields
{
};

#include <DSTINCDIR/GroupSelect.hxx>

#include <DSTINCDIR/MessageSelect.hxx>


} // namespace DSTNAMESPACE
