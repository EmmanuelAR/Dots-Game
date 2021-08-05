#pragma once
#include "Elemento.h"//
#include "Punto.h"
#include"SeisPuntos.h"
#include"NuevePuntos.h"
#include"QuincePuntos.h"
class Integrador
{
private:
	Elemento** vec;
	int cant;
	int &f;
	int &c;
public:
	Integrador(Elemento** vecCJ,int validos,int &f,int &c);
	virtual ~Integrador();
	Elemento*** integrar();
	void insertarNulos(Elemento*** m);
	Elemento*** crearMatriz();
	void tamMatriz();
	Elemento*** matrizResultante();
	bool existeMatrizQuinceP();
	bool todosSonMatrizQuinceP();
};

