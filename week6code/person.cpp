#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#pragma pack(1)

struct person
{
        std::string fname, lname;
        int age;
};

struct string
{
        char* data;
        int len;
};

int main(void)
{
        std::vector<person> persons = { { "Fred", "Flinstone", 23 },
                                        { "Barney", "Rubble", 25 },
                                        { "Wilma", "Flinstone", 27 } };
        std::string filename = "persons.bin";
        std::ofstream out(filename, std::ios::binary);
        std::size_t size = persons.size();
        out.write(reinterpret_cast<char*>(&size), sizeof(std::size_t));
        for (auto& pers : persons)
        {
                size = pers.fname.size();
                out.write(reinterpret_cast<char*>(&size), sizeof(std::size_t));
                out.write(pers.fname.c_str(), size);
                size = pers.lname.size();
                out.write(reinterpret_cast<char*>(&size), sizeof(std::size_t));
                out.write(pers.lname.c_str(), size);
                size = sizeof(int);
                out.write(reinterpret_cast<char*>(&size), sizeof(std::size_t));
                out.write(reinterpret_cast<char*>(&pers.age), size);
        }
        out.close();
}
