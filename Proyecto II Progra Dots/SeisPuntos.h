#pragma once
#include "CampoAbs.h"
class SeisPuntos :
	public CampoAbs
{
private:
	int f;
	int c;
public:
	SeisPuntos();
	virtual ~SeisPuntos();
	virtual bool insertar(int i, int j, int n);
	virtual void toString();
	virtual bool insertarNumero(int n);
	virtual bool lleno();
	virtual int ganador();
	virtual int getTamFila();
	virtual int getTamColumna();
	virtual void crearMatriz() { throw; }
};

