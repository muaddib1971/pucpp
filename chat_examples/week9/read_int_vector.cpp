#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using byte=char;
int main(void)
{
	std::string outfile = "out.bin";
	std::vector<int> ints;
	
	std::ifstream in(outfile);
	in.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	try
	{
		size_t size;
		in.read((byte*)(&size),sizeof(size_t));
		ints.resize(size);
		in.read((byte*)(&ints[0]), 
					sizeof(int) * size);

		std::cout << ints.size() << std::endl;
		std::cout << size << std::endl;
		int count;
		//for(count = 0; count < size ; ++count)
		for(auto num : ints)
		{
			std::cout << num << std::endl;
		}
	}
	catch(std::exception& ex)
	{
		if(!in.eof())
		{
			std::cerr << ex.what() << std::endl;
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}
