#include <iostream>

class parent {
   public:
    parent() {
        std::cout << "hello from parent"
                  << "\n";
    }

    parent(int j) { std::cout << "hello from numbered constructor.\n"; }
    virtual ~parent() {
        std::cout << "goodbye from parent"
                  << "\n";
    }
};

class child : public parent {
    using parent::parent;
    int i;

   public:
    child(int _i) : i(_i) {
        std::cout << "hello from child with int " << i << "\n";
    }
    virtual ~child() {
        std::cout << "goodbye from child with int " << i << "\n";
    }
};

int main(void) { child ch(5); }
