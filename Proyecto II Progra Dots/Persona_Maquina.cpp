#include "Persona_Maquina.h"

Persona_Maquina::Persona_Maquina(Jugador* j1) :Partida()
{
	persona = j1;
	maquina = new Maquina();
}

Persona_Maquina::Persona_Maquina(Persona_Maquina& pm)
{
	this->persona = pm.persona;
	if (this->maquina != NULL) {
		delete maquina;
		maquina = NULL;
	}
	maquina = pm.maquina;
	this->campo = pm.campo;
}

Persona_Maquina::~Persona_Maquina()
{
}

Jugador* Persona_Maquina::getPersona()
{
	return persona;
}

Jugador* Persona_Maquina::getMaquina()
{
	return maquina;
}

Jugador* Persona_Maquina::getJugador1()
{
	return persona;
}

void Persona_Maquina::guardar()
{
	ofstream out;
	out.open("../Partidas.txt", ios::app);
	out << "PERSONA-MAQUINA" << "\t";
	persona->guardar(out);
	maquina->guardar(out);
	campo->guardar(out);
	guardarJugadas(out);
	out.close();
}

void Persona_Maquina::leer(ifstream& in)
{
	Persona p1;
	Maquina m1;
	p1.leer(in);
	m1.leer(in);

	persona = new Persona(p1.getNombre(), p1.getCedula());
    persona->setNumero(p1.getNumero());
	persona->setCoins(p1.getCoins());

	maquina = new Maquina();
	maquina->setEstrategia(m1.getEstrategia());
	campo->leer(in);
	recuperarJugadas(in);
}

