#include <stdlib.h>

#include "polygon.h"

Polygon p_global_1(2);
Polygon p_global_2(3);

void farkle()
{
	Polygon p_local_1(3);

	for(int i = 0; i < 42; i++)
		Polygon p_local_2(4);
}

int main(int argc, char *argv[])
{
	Polygon* ptr = new Polygon(3);
	delete ptr;

	p_global_2 = p_global_1;

	return 0;
}

