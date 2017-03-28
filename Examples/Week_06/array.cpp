#include <iostream>
#include <memory>

class Array
{
public:
	int n;
	std::unique_ptr<int[]> data;
	std::shared_ptr<int> otherData;

	Array(int n = 0) : n(n)
	{
		std::cout << "Construct\n";
		data = std::unique_ptr<int[]>(new int[n]);
		otherData = std::shared_ptr<int>(new int[n], std::default_delete<int[]>());
	}
	~Array() { std::cout << "Destruct\n"; }
};

int main(int argc, char **argv)
{
	Array a(100);
	return 0;
}

