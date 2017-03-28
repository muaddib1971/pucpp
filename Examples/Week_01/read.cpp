#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using byte=char;
int main()
{
        std::ifstream ints_reader("ints.txt", std::ios::in | 
                std::ios::binary);
        std::vector<int> ints;
        while(ints_reader)
        {
                int i;
                ints_reader.read((byte*)&i, sizeof(int));
                if(!ints_reader)
                        break;
                ints.push_back(i);
        }
        return EXIT_SUCCESS;
}
