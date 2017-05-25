#include "student.h"
#include <array>
#include <fstream>
#include <iostream>

#define NUMSTUDENTS 3
int main(void)
{
	std::array<student, NUMSTUDENTS> students;
	//assume data is inserted into a student array.
	std::ofstream out("students.bin");
	while(out)
	{
        std::size_t num_students = NUMSTUDENTS;
		//write the number of students
        out.write(reinterpret_cast<char*>(&num_students), 
            sizeof(std::size_t));
        std::size_t count;
        for(count = 0; count < num_students; ++count)
        {
            //write the non-grade data for each student (id and name).
            std::size_t char_length;
            char_length = students[count].id.size();
            out.write(reinterpret_cast<char*>(&char_length), 
                sizeof(std::size_t));
            out.write(students[count].id.c_str(), char_length);
            char_length = students[count].name.size();
            out.write(reinterpret_cast<char*>(&char_length), 
                sizeof(std::size_t));
            out.write(students[count].name.c_str(), char_length);
            //write out each pair using a single write request  
            for(grade& g : students[count].results)
            {
                coursecode code = g.first;
                int result = g.second;
                char_length = code.size();
                out.write(reinterpret_cast<char*>(char_length),
                    sizeof(std::size_t));
                out.write(code.c_str(), char_length);
                out.write(reinterpret_cast<char*>(result), 
                    sizeof(int));
            }
        }
	}
}
