#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <fstream>

struct student
{
    std::string id;
    std::string name;
    double gpa;
};

int foo() //accepts any number of arguments in c
{
    return -1;
}
using byte = char;
int main(void)
{
    student studarray[2] =   {
        {"dljfldjfdlj", "frederick", 3.5},
        {"dljjalfjdla", "wilma", 4.0}
    };

    /* save to students.bin */
    std::ofstream out("students.bin", std::ios_base::binary);
    std::size_t size;
    for(auto & stud : studarray)
    {
        size = stud.id.size();
        out.write(reinterpret_cast<byte*>(&size), sizeof(std::size_t));
        out.write(stud.id.c_str(), size);

        size = stud.name.size();
        out.write(reinterpret_cast<byte*>(&size), sizeof(std::size_t));
        out.write(stud.name.c_str(), size);
        out.write(reinterpret_cast<byte*>(&stud.gpa), sizeof(double));
    }
    out.close();

    return EXIT_SUCCESS;
}

