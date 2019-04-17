#include <fstream>
#include <iostream>

int main(void) {
    std::fstream out("foo", std::ios::out | std::ios::app | std::ios::ate);
    out << "foo bar baz"
        << "\n";
}
