#include <memory>

void doit(std::unique_ptr<int>&& anint) {}

std::unique_ptr<int> make_int(int num) {
    std::unique_ptr<int> anint = std::make_unique<int>(num);
    doit(std::move(anint));
    return anint;
}

int main() { auto anint = make_int(5); }
