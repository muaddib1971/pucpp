#include <iostream>
#include <typeinfo>
class parent {
    virtual void doit() {}
};

class child : public parent {
    child(const parent& par) {
        // assign parent data
        // assign defaults for child data
    }

    void doit() {}

    inline void increment(int i) {}

#define INCREMENT(I) \
    {}

}

void child::doit() {
}

class sister {};

int main(void) {
    parent p;
    child c;
    auto s = sister{};
    auto t = sister{};
    auto u = parent{};
    child ch = p;

    parent* test = dynamic_cast<parent*>(&p);
    std::cout << test << "\n";
    test = dynamic_cast<parent*>(&c);
    std::cout << test << "\n";

    test = dynamic_cast<child*>(&p);
    std::cout << (void*)test << "\n";

    std::cout << typeid(s).name() << "\n";
    if (typeid(s) == typeid(t)) {
        std::cout << "s and t are the same type.\n";
    }
    std::cout << std::boolalpha << (typeid(t) == typeid(u)) << "\n";
}
