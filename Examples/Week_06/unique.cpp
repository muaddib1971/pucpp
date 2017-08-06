#include <iostream>
#include <memory>

class A
{
public:
	A() { std::cout << "Construct\n"; }
	virtual ~A() { std::cout << "Destruct\n"; }
};

void print(A* a)
{
}

void change_owner(std::unique_ptr<A> && a_owned)
{
}

int main(int argc, char **argv)
{
    int c;
    c=3;
    char * shortened = "fred"+2;
    A a(1);
	auto a = std::make_unique<A>();
    print(a.get());
    change_owner(std::move(a));
	return 0;
}

class unique_ptr<T>
{
    T* data;
    virtual ~(){
        delete data;
    }
};
