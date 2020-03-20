#include <cstdlib>
#include <iostream>
#include <memory>

struct basic {
    int i;
    basic(int _i) : i(_i) {}

    ~basic() { std::cerr << "hello from basic destructor\n"; }
};
int main() {
    std::unique_ptr<int> intptr = std::make_unique<int>(5);
    std::unique_ptr<basic> abasic = std::make_unique<basic>(4);
}
