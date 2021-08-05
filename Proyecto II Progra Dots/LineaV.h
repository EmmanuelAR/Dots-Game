#pragma once
#include "Linea.h"

class LineaV :
	public Linea
{
public:
	LineaV(int, int);
	virtual ~LineaV();
	virtual void toString();
	//Aplicando Composite
	virtual bool insertar(int i, int j, int n) { throw; }
	virtual bool insertarNumero(int n) { throw; }
	virtual bool lleno() { throw; }
	virtual int ganador() { throw; }
	virtual int getTamFila() { throw; }
	virtual int getTamColumna() { throw; }
	virtual void crearMatriz() { throw; }
};
