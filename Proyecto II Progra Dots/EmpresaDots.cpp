#include "EmpresaDots.h"

EmpresaDots::EmpresaDots()
{
	jugadores = new Lista<Jugador>;
	codigo = generarCodigo();
	dia = 1;
	juego = new Juego();
}
EmpresaDots::~EmpresaDots()
{
	delete jugadores;
}

void EmpresaDots::attach(Jugador* j)
{
	jugadores->insertarF(j);
	notify();
}

void EmpresaDots::notify()
{
	Nodo<Jugador>* actual = jugadores->getPrimero();
	Jugador* j = NULL;
	while (actual!=NULL) {
		j = actual->getObj();
		j->updateCodigo(codigo);
		actual = actual->getSig();
	}
}

void EmpresaDots::cambioDia()
{
	codigo = generarCodigo();
	dia++;
	jugadores->limpiar(); //CAMBIO
}

string EmpresaDots::toString()
{
	stringstream x;
	x << " _______________________________________________" << endl;
	x << "|                EMPRESA DOTS                   |" << endl;
	x << "|_______________________________________________|" << endl;
	x << "| \tDia: " << dia << "\t\t\t\t        |" << endl;
	x << "| \tCodigo del dia: " << codigo << "\t\t        |" << endl;
	x << "|_______________________________________________|" << endl;
	x << toStringSubscribtores();
	return x.str();
}

string EmpresaDots::generarCodigo()
{
	return to_string(rand() % 10000 + 99999);
}

Lista<Jugador>* EmpresaDots::getJugadores()
{
	return jugadores;
}

string EmpresaDots::toStringSubscribtores()
{
	string x;
	x += " _______________________________________________ \n";
	x += "|                SUBSCRIPTORES                  |\n";
	x += "|_______________________________________________|\n";
	if (!jugadores->vacia()) {
	x += "|    Cedula \tNombre \tCoins\tCodigo          |\n";
	}
	x += jugadores->toString();
	x += "|_______________________________________________|\n";
	return x;
}

Juego* EmpresaDots::getJuego()
{
	return juego;
}

string EmpresaDots::getCodigo()
{
	return codigo;
}

