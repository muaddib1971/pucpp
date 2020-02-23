#include <iostream>
#include <cstdlib>

template <typename T>
void swap(T & a, T & b)
{
    T temp = a;
    a = b;
    b = temp;
}


int main()
{
    int ia = 3, ib = 5;
    swap(ia,ib);
    std::cout << "a: " << ia << ", b: " << ib << std::endl;
    double da=3.4, db=5.6;
    swap(da, db);
    std::cout << "a: " << da << ", b: " << db << std::endl;
    return EXIT_SUCCESS;
}
