#pragma once
#include "Partida.h"
#include"Jugador.h"
#include"Persona.h"
class Persona_Persona :
	public Partida
{
private:
	Jugador* jugador1;
	Jugador* jugador2;
public:
	Persona_Persona(Jugador* j1 = NULL, Jugador* j2=NULL);
	Persona_Persona(Persona_Persona& );
	virtual ~Persona_Persona();
	virtual Jugador* getJugador1();
	virtual Jugador* getJugador2();
	virtual void guardar();
	virtual void leer(ifstream& in);
};

