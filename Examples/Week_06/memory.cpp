#include <cstdio>
#include <cstdlib>

struct A
{
	A(int i) : i(i) { printf("Constructing<%d>...\n", i); }
	~A()            { printf("Destructing<%d>...\n", i); }
	int i;
	A& operator=(const A& a)
		{
			i = a.i;
			return *this;
		}
};


A *a = new A(1);
int main(int argc, char **argv)
{
	printf("======\n");
	a = new A(3);
	printf("======\n");
	a = new A(5);
	printf("======\n");

	return EXIT_SUCCESS;
}
