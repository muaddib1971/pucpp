template <typename T>
class A
{
    T t;
    /* do stuff */
};

template<>
class A <bool>
{
    bool b;
    /* specialised implementation of A for bool here */
};

int factorial(int n)
{
    if (n <= 1 ) 
    {
        return 1;
    }
    return n * factorial (n-1);
}

template <int n>
struct factorial
{
    enum { value = n * factorial <n-1>::value };
};

template<>
struct factorial<0>
{
    enum { value = 1 };
};

/* illegal because memory allocation happens at runtime */
constexpr std::string s = "foo";

constexpr int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n * factorial(n-1);
}

int i = factorial (10);
int j;
std::cin >> j;
int k = factorial(j);

