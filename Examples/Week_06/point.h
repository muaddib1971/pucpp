#pragma once

#include "igobject.h"
#include <vector>

class Point : public IGObject
{
private:
	float x, y;

public:
	virtual void draw() {}

	Point(float x = 0, float y = 0) : x(x), y(y) {}

	virtual ~Point() {}
};

typedef std::vector<Point> Plist;

