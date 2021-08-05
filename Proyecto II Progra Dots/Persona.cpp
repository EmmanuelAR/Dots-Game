#include "Persona.h"

Persona::Persona(string n, string c):
nombre(n),cedula(c),codigo(""),coins(0),Jugador()
{
}

Persona::Persona(Persona& p2)
{
	this->cedula = p2.cedula;
	this->nombre = p2.nombre;
	this->codigo = p2.codigo;
	this->coins = p2.coins;
	this->numero = p2.numero;
}

Persona::~Persona()
{
}

string Persona::getNombre()
{
	return nombre;
}

string Persona::getCedula()
{
	return cedula;
}

string Persona::getCodigo()
{
	return codigo;
}

int Persona::getCoins()
{
	return coins;
}

string Persona::toString()
{
	stringstream x;
	x << "Persona ";
	(numero != 0) ? x << numero << endl : x << endl;
	x << "Nombre: " << nombre << endl;
	x << "Cedula: " << cedula << endl;
	x << "Coins: " << coins << endl;
	//
	// Probando update
	x << "Codigo: " << codigo << endl;
	return x.str();
}

void Persona::updateCodigo(string codigoDelDia)
{
	this->codigo = codigoDelDia;
}

int Persona::getNumero()
{
	return numero;
}

void Persona::setNumero(int nu)
{
	numero = nu;
}

void Persona::setCoins(int coins)
{
	this->coins = coins;
}
void Persona::guardar(ofstream& out)
{
	out << numero << "\t" << nombre << "\t" << cedula << "\t" << codigo << "\t" << coins << "\t";
}
void Persona::leer(ifstream& in)
{
	string num, nom, ced, cod, coi;

	getline(in, num, '\t');
	getline(in, nom, '\t');
	getline(in, ced, '\t');
	getline(in, cod, '\t');
	getline(in, coi, '\t');
	numero = atoi(num.c_str());
	nombre = nom;
	cedula = ced;
	codigo = cod;
	coins = atoi(coi.c_str());
}

