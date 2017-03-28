#pragma once

#include <iostream>

class IGObject
{
public:
	virtual void draw() = 0;

	virtual ~IGObject()
	{
		std::cout << "Deleting object " << this << std::endl;
	}
};

