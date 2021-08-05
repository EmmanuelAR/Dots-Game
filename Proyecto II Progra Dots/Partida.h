#pragma once
//#include"Elemento.h"
#include"Lista.h"
#include"Jugada.h"
#include"CampoJuego.h"
#include"Jugador.h"
class Partida
{
protected:
	int numero;
	Elemento* campo;
	Lista<Jugada>* jugadas;
public:

	Partida();
	virtual ~Partida();
	Elemento* getCampo(); 
	Lista<Jugada>* getJugadas();
	void toSringCampo();
	string toStringJudadas();
	friend ostream& operator << (ostream& out, Partida& j);
	int generarNumero();
	//metodos nuevos 22-05-20
	bool ingresarJugada(int i,int j, int n);
	//metodos de persona maquina
	virtual Jugador* getMaquina() { throw; }
	//metodos de persona persona
	virtual Jugador* getJugador1() { throw; }
	virtual Jugador* getJugador2() { throw; }
	virtual void guardar() = 0;
	virtual void leer(ifstream& in) = 0;
	virtual void guardarJugadas(ofstream& out);
	virtual void recuperarJugadas(ifstream& in);

};

