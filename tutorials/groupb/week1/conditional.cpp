#include <cstdlib>
#include <iostream>
int main() {
#ifndef OPTION
#error OPTION was not defined
#else
    std::cout << "option entered at compile time was " << OPTION << "\n";
#endif
}
