#include <iostream>
#include <memory>

class A
{
public:
	A() { std::cout << "Construct\n"; }
	~A() { std::cout << "Destruct\n"; }
};

std::shared_ptr<A> func()
{
	return std::shared_ptr<A>(new A);
}

int main(int argc, char **argv)
{
	func();

	std::shared_ptr<A> a;
	std::weak_ptr<A> w = a;

	if (w.expired())
		std::cout << "null\n";

	a = func();
	w = a;

	if (!w.expired())
		std::cout << "not null\n";

	return 0;
}

