#include "Numero.h"

Numero::Numero(int n) :n(n)
{
}

Numero::~Numero()
{
}

int Numero::getN()
{
	return n;
}

void  Numero::toString()
{
	Consola::textColor(15);
	cout<< to_string(n);
}
