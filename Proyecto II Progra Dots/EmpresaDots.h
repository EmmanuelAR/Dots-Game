#pragma once
#include"Jugador.h"
#include"Lista.h"
#include"Juego.h"
#include"Consola.h"

class EmpresaDots
{
private:
	Lista<Jugador>* jugadores;
	string codigo;
	int dia;
	Juego* juego;
public:
	EmpresaDots();
	virtual ~EmpresaDots();
	void attach(Jugador* j);
	void notify();
	void cambioDia();
	string toString();
	string generarCodigo();
	Lista<Jugador>* getJugadores();
	string toStringSubscribtores();
	Juego* getJuego();
	string getCodigo();
	
};

