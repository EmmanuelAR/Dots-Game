#include "Jugador.h"

Jugador::Jugador(): 
  numero(0)
{
}

Jugador::~Jugador()
{
}

ostream& operator<<(ostream& out, Jugador& p)
{
	out << "|    " << p.getCedula() << " \t" << p.getNombre() << " \t" << p.getCoins()<<"\t" <<p.getCodigo() <<"   \t|";
	return out;
}

bool Jugador::operator==(string identificador)
{
	return (getCedula() == identificador);
}

bool Jugador::operator==(Jugador& j)
{
	if (this->getCedula() == j.getCedula() && this->getNombre() == j.getNombre()) {
		return true;
	}
	return false;
}

