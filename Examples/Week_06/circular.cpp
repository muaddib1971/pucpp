#include <iostream>
#include <memory>

class A
{
public:
	std::shared_ptr<A> circular;

	A() { std::cout << "Construct\n"; }
	~A() { std::cout << "Destruct\n"; }
};

int main(int argc, char **argv)
{
	std::shared_ptr<A> a1 = std::shared_ptr<A>(new A);
	std::shared_ptr<A> a2 = std::shared_ptr<A>(new A);

	a1->circular = a2;
	a2->circular = a1;

	return 0;
}

