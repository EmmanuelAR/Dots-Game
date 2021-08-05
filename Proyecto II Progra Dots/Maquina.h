#pragma once
#include "Jugador.h"
#include"EstrategiaPadre.h"
#include"EstrategiaAleatoria.h"
#include"EstrategiaCentral.h"
#include"EstrategiaCercana.h"
#include"EstrategiaInteligente.h"
#include"EstrategiaIslas.h"
#include"EstrategiaPeriferica.h"

class Maquina :
	public Jugador
{
private:
		EstrategiaPadre* est;
		string estrategiaInicial;
		bool bandera;
public:
	Maquina();
	virtual ~Maquina();
	virtual string getNombre() { return "Maquina"; }
	virtual string getCedula() { throw; }
	virtual string getCodigo() { throw; }
	virtual int getCoins() { throw; }
	virtual string toString() { throw; }
	virtual void updateCodigo(string codigoDelDia) { throw; }
	virtual int getNumero() { throw; }
	virtual void setNumero(int nu) { throw; }
	virtual void setCoins(int coins) { throw; }
	//Metodos de estrategia
	virtual void setEstrategia(EstrategiaPadre* ptr);
	virtual Jugada* ejecutarEstregia(Elemento*);
	virtual EstrategiaPadre* getEstrategia();
	virtual void guardar(ofstream& out);
	virtual void leer(ifstream& in);
	virtual string getEstrategiaInicial();
};

