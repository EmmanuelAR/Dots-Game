#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//
#include"Jugada.h" //se ocupan para ver como reaccionar
#include "Elemento.h"
#include "CampoJuego.h"
#include "Jugada.h"
#include "Lista.h"

class EstrategiaPadre{
protected:
	Elemento* campo;
	string nombre;
	Jugada* ultimaJugada;
	int f;
	int c;
	Elemento*** m;
	Lista<Jugada>* noP;
	Lista<Jugada>* siP;
public:
	EstrategiaPadre();
	virtual ~EstrategiaPadre();
	virtual Jugada* retornarJugada(Elemento*) = 0;
	virtual Jugada* analizarCampo(Elemento*) = 0;
	virtual string getNombre() = 0;
	void setCampo(Elemento* a);
	void setUltimaJugada(Jugada* j);
	bool esInsertable(int x,int y);
	bool esCuadradoNulo(int i, int j);
	bool esCuadradoVacio(int i, int j);
	int contarCudradosVacios();
	bool hayCuadradosVacio();
	//METODO JUGAR ALEATORIO - JUGAR TONTO
	virtual Jugada* jugarAleatorio_Tonto();
	//METODO ESPECIAL PARA CAPTURA DE CUADRADOS
	virtual Jugada* cerrarJugada();
	
	//METODOS PARA JUGAR INTELIGENTE. (ORDEN DE PRIORIDAD)
	/* 0) */ virtual Jugada* jugarInteligente();
	/* 1) */ virtual Jugada* rectanguloInteligente();
	/* 2) */ virtual Jugada* cerrarCuadradoInteligente();//CREO QUE YA NO SON NECESARIOS....
	/* 3) */ virtual Jugada* cerrarSemiCuadradoInteligente();
	/* 4) */ virtual Jugada* buscarCuadradoVacioInteligente();
	//NUEVA INTELIGENCIA......
	/* 0) */ virtual Jugada* jugarAleatorio_Inteligente();

	//METODOS DE LA LISTA
	virtual bool esPermitida(int i, int j);
	virtual void actualizarNoP();
	virtual void actualizarSiP();
	virtual bool estaEnNoP(int i, int j);
	virtual void sPMnP();
	//metodo de estrategia Isla

	
};

