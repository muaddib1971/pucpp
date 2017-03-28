#include "polygon.h"

Polygon::Polygon(int init_nv, Plist* init_v) : nv(init_nv), vlist(new Point[init_nv])
{
	// now initialize the points
	if (!init_v) 
		return; // use default vertex initialization

	Point* vi = vlist; // vlist iterator
	Plist::iterator pi = init_v->begin(); // init_v iterator

	while (pi != init_v->end())
	{
		if (vi >= &vlist[nv])
			return; // vlist fully initialized
		*(vi++) = *(pi++); // copy Point
	}
}

Polygon::Polygon(const Polygon& p) : nv(p.nv), vlist(new Point[p.nv])
{
	for(int i = 0; i < nv; i++)
		vlist[i] = p.vlist[i];
}

Polygon& Polygon::operator = (const Polygon& p)
{
	if(this == &p)
		return *this;

	delete [] vlist;
	nv = p.nv;
	vlist = new Point[p.nv];

	for(int i = 0; i < nv; i++)
		vlist[i] = p.vlist[i];

	return *this;
}


