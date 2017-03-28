class A
{
public:
	struct SubA {};
};

template <typename T>
class B
{
public:
	// g++ will not compile without typename declared here, but msvc++ will, both are valid
	typename T::SubA subA;
};


int main(int argc, char **argv)
{
	B<A> b;
	return 0;
}
