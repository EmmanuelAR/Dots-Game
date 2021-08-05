#include "EstrategiaAleatoria.h"



EstrategiaAleatoria::EstrategiaAleatoria()
{
	this->nombre = "Juego Aleatorio Tonto";
}

Jugada* EstrategiaAleatoria::retornarJugada(Elemento* a)
{
	this->setCampo(a);
	return analizarCampo(a);
}

Jugada* EstrategiaAleatoria::analizarCampo(Elemento* a)
{
	bool bandera = false;
	int i = 0; 
	int j = 0;
	while (!bandera) {
		i = 0 + rand() % f;
		j = 0 + rand() % c;
		bandera = esInsertable(i,j);
	}
	return new Jugada(i, j);
}

string EstrategiaAleatoria::getNombre()
{
	return nombre;
}
