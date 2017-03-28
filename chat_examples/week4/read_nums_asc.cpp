#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <boost/tokenizer.hpp>

int main(void)
{
    std::ifstream in("nums.txt");
    std::string line;
    std::getline(in, line);
    std::vector<int>ints;
    if(!in.good()) /* good, bad, fail, eof */
    {
        /* test for eof */
        /*else */
        /* error */
    }
    boost::char_separator<char> sep{","};
    boost::tokenizer<boost::char_separator<char>> tok(line, sep);
    for(auto item : tok)
    {
        int num = std::stoi(item);
        ints.push_back(num);
    }
    in.close();
    std::ofstream out("nums.bin", std::ios::binary);
    int size = ints.size();
    out.write((const char *)&size, sizeof(std::vector<int>::size_type));
    out.write((const char *)&ints[0], sizeof(int) * ints.size());
    if(!out)
    {
        std::cerr << " io error occured" << std::endl;
    }
    out.close();
    for(int i : ints)
    {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
