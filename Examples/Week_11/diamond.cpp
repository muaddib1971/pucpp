#include <iostream>

#if 0

struct Top
{
public:
	int a;
};

struct Left : public Top
{
public:
	int b;
};

struct Right : public Top
{
public:
	int c;
};

struct Bottom : public Left, public Right
{
public:
	int d;
};



int main(int argc, char **argv)
{
	Left *left = new Left();
	Top *top = left;
	std::cout << "Left: " << left << ", Top: " << top << "\n";

	Bottom *bottom = new Bottom();
	left = bottom;
	Right *right = bottom;
	std::cout << "Bottom: " << bottom << ", Left: " << left << ", Right: " << right << "\n";

	Top *topL = (Left*) bottom;
	Top *topR = (Right*) bottom;
	std::cout << "Left: " << left << ", TopL: " << topL << "\n";
	std::cout << "Right: " << right << ", TopR: " << topR << "\n";
    std::cout << bottom->a;

	return 0;
}

#else

struct Top
{
public:
	int a;
	Top() { a = -1; }
	Top(int a) : a(a) {}
	virtual ~Top() {}
};

struct Left : public virtual Top
{
public:
	int b;
	Left() { b = -2; }
	Left(int a, int b) : Top(a), b(b) {}
};

struct Right : public virtual Top
{
public:
	int c;
	Right() { c = -3; }
	Right(int a, int c) : Top(a), c(c) {}
};

struct Bottom : public Left, public Right
{
public:
	int d;
	Bottom() { d = -4; }
	Bottom(int a, int b, int c, int d) : Left(a, b), Right(a, c), d(d) {}
};

struct AnotherBottom : public Left, public Right
{
public:
	int e;
	int f;
};



int main(int argc, char **argv)
{
	Bottom *bottom = new Bottom();
	Left *left = bottom;
	Right *right = bottom;
	std::cout << "Bottom: " << bottom << ", Left: " << left << ", Right: " << right << "\n";

	if (right == bottom)
		std::cout << "Equal!\n";

	Top *topL = (Left*) bottom;
	Top *topR = (Right*) bottom;
	std::cout << "Left: " << left << ", TopL: " << topL << "\n";
	std::cout << "Right: " << right << ", TopR: " << topR << "\n";

	Bottom *bottom1 = new Bottom();
	AnotherBottom *bottom2 = new AnotherBottom();
	Top *top1 = bottom1;
	Top *top2 = bottom2;

	left = dynamic_cast<Left*>(top1);

	Bottom b(1, 2, 3, 4);
	std::cout << b.a << " " << b.b << " " << b.c << " " << b.d << "\n";
	
	return 0;
}

#endif

