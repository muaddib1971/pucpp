#include <iostream>

struct A
{
	template <typename T>
	static T staticTemplateFunc()
	{
		std::cout << "static\n";
	}

	template <typename T>
	T memberTemplateFunc()
	{
		std::cout << "local\n";
	}
};

template <typename T>
void func()
{
	//T::staticTemplateFunc<int>();          // ambiguous
	T::template staticTemplateFunc<int>(); // ok

	T t;
	//t.memberTemplateFunc<int>();          // ambiguous
	t.template memberTemplateFunc<int>(); // ok
}

int main(int argc, char **argv)
{
	func<A>();
	return 0;
}
