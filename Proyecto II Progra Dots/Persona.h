#pragma once
#include"Jugador.h"
class Persona:public Jugador
{
private:
	string nombre;
	string cedula;
	string codigo;
	int coins;
public:
	Persona(string = "",string = "");
	Persona(Persona& p2);
	virtual ~Persona();
	virtual string getNombre();
	virtual string getCedula();
	virtual string getCodigo();
	virtual int getCoins();
	virtual string toString();
	virtual void updateCodigo(string codigoDelDia);
	virtual int getNumero();
	virtual void setNumero(int nu);
	virtual void setCoins(int coins);
	// bool operator == (string identificador);
	virtual void setEstrategia(EstrategiaPadre* ptr) { throw; }
	virtual Jugada* ejecutarEstregia(Elemento*) { throw; }
	virtual void guardar(ofstream& out);
	virtual void leer(ifstream& in);
	
};

