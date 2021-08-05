#include "Juego.h"

Juego::Juego()
{
	partidas = new Lista<Partida>;
	recuperarPartidas();
}

Juego::~Juego()
{
	delete partidas;
}

Lista<Partida>* Juego::getPartidas()
{
	return partidas;
}

string Juego::toStringPartidas()
{
	string x;
	x += " _______________________________________________\n";
	x += "|           LISTA DE PARTIDAS GUARDADAS         |\n";
	x += "|_______________________________________________|\n";
	x +=  partidas->toString();
	x += "|_______________________________________________|\n";
	return x;
}

void Juego::recuperarPartidas()
{
	string tipo;
	ifstream in("../Partidas.txt");
	Partida* pp = NULL;
	Partida* pm = NULL;
	if (in) {
		while (!in.eof()) {
			if (!in.eof()) {
				tipo = "";
				getline(in, tipo, '\t');
				if (tipo == "PERSONA-PERSONA") {
					pp = new Persona_Persona();
					pp->leer(in);
					partidas->insertarF(pp);
				}
				if (tipo == "PERSONA-MAQUINA") {
					pm = new Persona_Maquina();
					pm->leer(in);
					partidas->insertarF(pm);
				}
			}
		}
	}
	in.close();
}
