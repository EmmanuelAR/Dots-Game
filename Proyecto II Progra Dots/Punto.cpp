#include "Punto.h"

Punto::Punto(int x, int y) :x(x), y(y)
{
	p = 111;
}

Punto::~Punto()
{
}

void Punto::toString()
{
	Consola::textColor(15);
	cout<< string(1, p);
}

int Punto::getX()
{
	return x;
}

int Punto::getY()
{
	return y;
}

char Punto::getP()
{
	return p;
}
