#include "EstrategiaInteligente.h"
//EstrategiaInteligente

EstrategiaInteligente::EstrategiaInteligente()
{
	this->nombre = "Juego Aleatorio Inteligente";
}

Jugada* EstrategiaInteligente::retornarJugada(Elemento* a)
{
	this->setCampo(a);
	return analizarCampo(a);
}

Jugada* EstrategiaInteligente::analizarCampo(Elemento* a)
{
	Jugada* jugada = NULL;
	actualizarNoP();
	jugada = cerrarJugada();
	if (jugada) {
		return jugada;
	}
	jugada = jugarAleatorio_Inteligente();
	return jugada;
}

string EstrategiaInteligente::getNombre()
{
	return nombre;
}

