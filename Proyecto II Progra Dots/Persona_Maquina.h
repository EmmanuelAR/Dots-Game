#pragma once
#include "Partida.h"
#include"Jugador.h"
#include"Maquina.h"
#include"Persona.h"

class Persona_Maquina :
	public Partida
{
private:
	Jugador* persona;
	Jugador* maquina;
public:
	Persona_Maquina(Jugador* j1=NULL);
	Persona_Maquina(Persona_Maquina& pm);
	virtual ~Persona_Maquina();
	Jugador* getPersona();
	virtual Jugador* getMaquina();
	virtual Jugador* getJugador1();
	virtual void guardar();
	virtual void leer(ifstream& in);

};
