#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;
#include"EstrategiaPadre.h"


class Jugador
{
protected:
	int numero;
public:
	Jugador();
	virtual ~Jugador();

	virtual string getNombre() = 0;
	virtual string getCedula() = 0;
	virtual string getCodigo() = 0;
	virtual int getCoins() = 0;
	virtual string toString() = 0;
	virtual void updateCodigo(string codigoDelDia) = 0;
	virtual int getNumero() = 0;
	virtual void setNumero(int nu) = 0;
	virtual void setCoins(int coins) = 0;
	friend ostream& operator << (ostream& out, Jugador& p);
	bool operator == (string identificador);
	bool operator == (Jugador&);
	virtual void setEstrategia(EstrategiaPadre* ptr) = 0;
	virtual Jugada* ejecutarEstregia(Elemento*) = 0;
	virtual EstrategiaPadre* getEstrategia() { throw; }
	virtual void setNombre(string n) { throw; }
	virtual void setCedula(string c) { throw; }
	virtual void setCodigo(string c) { throw; }
	virtual void guardar(ofstream& out) = 0;
	virtual void leer(ifstream& in) = 0;
	virtual string getEstrategiaInicial() { throw; }
};

