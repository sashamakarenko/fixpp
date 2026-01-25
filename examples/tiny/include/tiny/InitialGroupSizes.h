namespace tiny
{

template<>
constexpr unsigned initialNoGroupsToPreallocate<GroupMDEntries>()
{
    return 20;
}

}
