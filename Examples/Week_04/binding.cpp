#include <cstdlib>
#include <iostream>
#include <typeinfo>

class Foo
{
public:
	void printStatic()
	{
		std::cout << "Foo\n";
	}

	virtual void printVirtual()
	{
		std::cout << "Foo\n";
	}

	virtual void noPrinting() = 0;
};

class Bar : public Foo
{
public:
	void printStatic()
	{
		std::cout << "Bar\n";
	}

	virtual void printVirtual()
	{
		std::cout << "Bar\n";
	}

	virtual void noPrinting()
	{
		std::cout << "Pure virtual method\n";
	}
};

class OtherBar : public Foo { };

int main(int argc, char **argv)
{
	Foo *foo = new Bar();
	foo->printVirtual();
	foo->printStatic();

	Bar *a = dynamic_cast<Bar*>(foo);
	OtherBar *b = dynamic_cast<OtherBar*>(foo);

	if (a) std::cout << "Bar object\n";
	if (b) std::cout << "OtherBar object\n";

	std::cout << typeid(*a).name() << "\n";

	return EXIT_SUCCESS;
}
