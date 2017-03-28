class foo
{
	int i;
};

class bar : public foo
{
	int b;
};


int main()
{
	foo f;
	bar b;
	foo cast_b = (foo)b;
}

constexpr inline int add(int a, int b)
{
	return a + b;
}

#define ADD(A,B) \
	{					\
		((A)+(B))			\
	}
