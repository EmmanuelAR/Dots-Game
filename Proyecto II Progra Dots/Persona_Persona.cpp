#include "Persona_Persona.h"

Persona_Persona::Persona_Persona(Jugador* j1, Jugador* j2) :
	jugador1(j1), jugador2(j2),Partida()
{
}

Persona_Persona::Persona_Persona(Persona_Persona& pp)
{
	this->jugador1 = pp.jugador1;
	this->jugador2 = pp.jugador2;
	this->campo = pp.campo;
}

Persona_Persona::~Persona_Persona()
{
	delete jugador1;
	delete jugador2;
}

Jugador* Persona_Persona::getJugador1()
{
	return jugador1;
}

Jugador* Persona_Persona::getJugador2()
{
	return jugador2;
}

void Persona_Persona::guardar()
{
	ofstream out;
	out.open("../Partidas.txt", ios::app);
	out << "PERSONA-PERSONA" << "\t";
	jugador1->guardar(out);
	jugador2->guardar(out);
	campo->guardar(out);
	guardarJugadas(out);
	out.close();
}

void Persona_Persona::leer(ifstream& in)
{
	Persona p1, p2;
	p1.leer(in);
	p2.leer(in);

	jugador1 = new Persona(p1.getNombre(), p1.getCedula());
	jugador1->setNumero(p1.getNumero());
	jugador1->setCoins(p1.getCoins());
	
	jugador2 = new Persona(p2.getNombre(), p2.getCedula());
	jugador2->setNumero(p2.getNumero());
	jugador2->setCoins(p2.getCoins());
	campo->leer(in);
	recuperarJugadas(in);
}
