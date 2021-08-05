#pragma once
#include"Partida.h"
#include"Persona_Persona.h"
#include"Persona_Maquina.h"
#include"fstream"
class Juego
{
private:
	Lista<Partida>* partidas;
public:
	Juego();
	virtual ~Juego();
	Lista<Partida>* getPartidas();
	string toStringPartidas();
	void recuperarPartidas();
};

