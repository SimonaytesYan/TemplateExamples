#ifndef SYM_TEMPLATES
#define SYM_TEMPLATES

template <typename ReturnT, typename T, typename ...Types> T my_sum();

template <typename ReturnT> ReturnT my_sum();

template <typename ReturnT, typename T, typename ...Types> 
ReturnT my_sum(T a, Types... other)
{
    return a + my_sum<ReturnT, Types...>(other...);
}

template <typename ReturnT>
ReturnT my_sum()
{
    return 0;
}

#endif // SYM_TEMPLATES