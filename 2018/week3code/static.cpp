#include "static.h"
#include <iostream>
std::string stat::mystring;

int main(void)
{
        stat s;
        s.set_string("foo");
        std::cout << s.get_string() << '\n';
}
