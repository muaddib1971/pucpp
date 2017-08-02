#include <vector>

int main(void)
{
    std:: ifstream in("filename");
    std::vector<int>ints;
    ints.push_back(5);
    ints.push_back(9);
    ints.push_back(3);
    std::vector<std::vector<std::vector<int>>> create_matrix();
    auto mat = creat_matrix();
    while(in.good())
    {
        std::string line;
        std::getline(line, in);
        /* process the line */
    }
    for(auto it = ints.begin(); it != ints.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    for(int i : ints){
        std::cout << i << std::endl;
    }
}
