#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
        std::ifstream in("numbers.txt");
        std::ofstream out("somethingelse.txt");
        int i;
        string s;
        
        getline(in, s);
        i = stoi(s);
        out << i <<  std::endl;
}
