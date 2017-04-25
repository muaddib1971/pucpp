#include <string>
#include <utility>

#pragma once

using grade = std::pair<std::string, int>;
class student
{
	std::string id;
	std::string name;
	std::list<grade> results;
	public: 
		student(std::string id_, std::string name_)
			: id(std::move(id_)), name(std::move(name_)) 
		{
		}

		bool add_grade(const grade & new_grade)
		{
			results.push_back(new_grade);
		}
};

struct list_node
{
	list_node * prev;
	list_node * next;
	grade data;
};
