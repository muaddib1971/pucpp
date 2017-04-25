#include "student.h"

int main(void)
{
	std::array<student, 3> students;
	//assume data is inserted into a student array.
	std::ofstream out("students.bin");
	while(out)
	{
		//write the number of students
		//write the non-grade data for each student (id and name).
		//write out each pair using a single write request  
	}
}
