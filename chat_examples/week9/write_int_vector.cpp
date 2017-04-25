#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using byte=char;
int main(void)
{
	std::string outfile = "out.bin";
	std::vector<int> ints {1,2,3,5,7,9,1};
	
	std::ofstream out(outfile);
	out.exceptions(std::ios_base::badbit | std::ios_base::failbit);
	try
	{
		int size = ints.size();
		out.write((byte*)(&size),sizeof(int));
		out.write((byte*)(&ints[0]), 
					sizeof(int) * ints.size());
	}
	catch(std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
