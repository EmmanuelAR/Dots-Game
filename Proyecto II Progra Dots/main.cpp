
#include"Controladora.h"
#include<stdlib.h>
#include<time.h>

int main() {

	srand((unsigned int)(time(NULL)));		//La semilla ayuda a generar numeros aleatorios diferentes cada vez que se emplea y debe realizarse desde el main
	Controladora* c = new Controladora();

	c->principal();
	return 0;
}