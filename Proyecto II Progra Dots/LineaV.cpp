#include "LineaV.h"

LineaV::LineaV(int x, int y)
{
	this->x = x;
	this->y = y;
	this->p = (char)186;
}

LineaV::~LineaV()
{
}

void LineaV::toString()
{
	(color == 1) ? Consola::textColor(9) : Consola::textColor(12);
	cout << p;
}
