#include "Consola.h"

HANDLE h;
int k;
static int x = 2;
static int y = 0;


void Consola::inicializarColor()
{
	//system("Color F0");
	h = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Consola::textColor(int z)
{
	setK(z);
	SetConsoleTextAttribute(h, k);
}

void Consola::setK(int z)
{
	if (z >=1 && z <= 253) {
		k = z;
	}
}
