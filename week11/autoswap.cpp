#include <iostream>

/* this code will become valid under c++ 20 - auto type deduction of parameeters
 * appears to be a planned c++20 feature
 */

void swap(auto& a, auto& b)
{
        auto temp = a;
        a = b;
        b = temp;
}

int main()
{
        int a = 5, b = 3;
        swap(b, a);
        std::cout << a << " " << b << "\n";
}
