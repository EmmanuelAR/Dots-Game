#include "Jugada.h"

Jugada::Jugada(int i, int j)
{
	this->i = i;
	this->j = j;
}

Jugada::Jugada(Jugada& j2)
{
	this->i = j2.i;
	this->j = j2.j;
}

Jugada::~Jugada()
{
}

int Jugada::getI()
{
	return i;
}

int Jugada::getJ()
{
	return j;
}

string Jugada::toString()
{
	stringstream x;
	x << "( " << i << " , " << j << " )";
	return x.str();
}

bool Jugada::operator==(Jugada& a)
{
	return (i == a.i && j == a.j);
}


ostream& operator<<(ostream& out, Jugada& j)
{
	out << j.toString();
	return out;
}

void Jugada::guardar(ofstream& out)
{
	out << i << "\t" << j << "\t";
}

void Jugada::leer(ifstream& in)
{
	string i1, j1;
	getline(in, i1, '\t');
	getline(in, j1, '\t');
	this->i =  atoi(i1.c_str());
	this->j = atoi(j1.c_str());
}