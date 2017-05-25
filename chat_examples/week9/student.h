#include <string>
#include <utility>
#include <list>

#pragma once
using coursecode = std::string;
using grade = std::pair<coursecode, int>;
struct student
{
	std::string id;
	std::string name;
	std::list<grade> results;
	public: 
        student(void) : id(), name(), results()
        {
        }
		student(std::string id_, std::string name_)
			: id(std::move(id_)), name(std::move(name_)) 
		{
		}

		bool add_grade(const grade & new_grade)
		{
			results.push_back(new_grade);
            return true;
		}
};
