#include <iostream>
#include <cstdlib>
#include <vector>
#include "tree.h"
#include <boost/tokenizer.hpp>
#include <fstream>
#include <string>

int main(void)
{
    tree mytree;
    std::ifstream in("nums.csv");
    if(!in.good())
    {
        /* error */
        return EXIT_FAILURE;
    }
    std::string line;
    if(!std::getline(in, line))
    {
        /* error */
    }
    boost::char_separator<char> sep {","};
    boost::tokenizer<boost::char_separator<char>> tok(line, sep);
    for(std::string token : tok)
    {
        int i = stoi(token);
        if(!mytree.add(i))
        {
            std::cerr << "Error: failure to add a number." << std::endl;
            return EXIT_FAILURE;
        }
    }
    mytree.print();
    return EXIT_SUCCESS;
}
