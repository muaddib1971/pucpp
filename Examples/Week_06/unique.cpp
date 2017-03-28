#include <iostream>
#include <memory>

class A
{
public:
	A() { std::cout << "Construct\n"; }
	~A() { std::cout << "Destruct\n"; }
};


int main(int argc, char **argv)
{
	auto a = std::unique_ptr<A>(new A);
	return 0;
}

