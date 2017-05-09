#include <iostream>
#include <cstdlib>
/* illegal function prototype until possibly c++ 20 */
void swap(auto& lhs, auto& rhs)
{
}

template <typename T>
void swap(T & lhs, T& rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main(void)
{
    int i = 5, j = 10;

    double d = 5.5, e = 6.6;

    swap(i,j);
    swap(d,e);

    swap(i, d);

    std::cout << i << "\t" << j << std::endl;
    std::cout << d << "\t" << e << std::endl;

    return EXIT_SUCCESS;
}
