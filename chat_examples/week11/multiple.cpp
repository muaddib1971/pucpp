template<typename T, typename S>
struct pair
{
    T first;
    S second;
};

template<typename T>
struct less
{
    bool operator < (T& lhs, T& rhs);
};

template<typename T>
T& max(T& lhs, T& rhs)
{
    return lhs > rhs ? lhs : rhs;
}

#define MAX(LHS, RHS) (((LHS) > (RHS)) ? (LHS) : (RHS))
