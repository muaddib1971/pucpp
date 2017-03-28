#include <iostream>
#include "overloading.h"

using namespace std;

int main(int argc, char **argv)
{
	EventLog c1(42);
	EventLog c2;

	cout << c2.increment() << '\n';
	cout << c1.increment() << '\n';

	c1.set();
	c2.set(42);

	cout << c2.increment() << '\n';
	cout << c1.increment() << '\n';

	return 0;
}
