__COPYRIGHT__
#pragma once
#ifndef DSTHEADERGUARD_GROUPS_H
#define DSTHEADERGUARD_GROUPS_H

#include <vector>

#include <DSTINCDIR/Fields.h>

namespace DSTNAMESPACE
{

// One can specialize this value for different group types in a file 'XXX.h'.
// Then -DFIXPP_GROUPS_CPP_INCLUDE=\"XXX.h\"
template< typename GROUP >
constexpr unsigned initialNoGroupsToPreallocate()
{
    return 8;
}

#include <DSTINCDIR/Groups.hxx>

} // namespace DSTNAMESPACE

#endif /* DSTHEADERGUARD_GROUPS_H */

