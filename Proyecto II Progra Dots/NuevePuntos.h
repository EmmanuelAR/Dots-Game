#pragma once
#include "CampoAbs.h"
class NuevePuntos :
	public CampoAbs
{
private:
	int f;
	int c;
public:
	NuevePuntos();
	virtual ~NuevePuntos();
	virtual bool insertar(int x, int y, int n);
	virtual void toString();
	virtual bool insertarNumero(int n);
	virtual bool lleno();
	virtual int ganador();
	virtual int getTamFila();
	virtual int getTamColumna();
	virtual void crearMatriz() { throw; }
};
