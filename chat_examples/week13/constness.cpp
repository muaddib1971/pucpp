#include <iostream>
#include <fstream>
#include <cstdlib>

class constness
{
    int id;

    public:
    const int & foo(const int &i) const
    {
        return id;
    }

    int doit(int i=3) const{
        return i;
    }
};

template <typename T>
struct truth
{
    bool operator()(T& a, T&b)
    {
        return a != b;
    }
};

std::ostream& operator<<(std::ostream& out, const constness& c)
{
    c.doit(3);
    return out;
}

int main(void)
{
    constness myconst;
    myconst.doit(5);
    throw myconst;
    return EXIT_SUCCESS;
}
