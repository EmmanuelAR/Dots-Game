#include "LineaH.h"

LineaH::LineaH(int x, int y)
{
	this->x = x;
	this->y = y;
	if (y >= 11) {
		this->p = "=====";
	}
	else {
		this->p = "===";
	}

}

LineaH::~LineaH()
{
}

void LineaH::toString()
{
	(color == 1) ? Consola::textColor(9) : Consola::textColor(12);
	cout << p;
}
