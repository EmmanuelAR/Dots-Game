#pragma once
#include "CampoAbs.h"
class QuincePuntos :
	public CampoAbs
{
private:
	int f;
	int c;
public:
	QuincePuntos();
	virtual ~QuincePuntos();
	virtual bool insertar(int x, int y,int n);
	virtual void toString();
	virtual bool insertarNumero(int n);
	virtual bool lleno();
	virtual int ganador();
	virtual int getTamFila();
	virtual int getTamColumna();
	virtual void crearMatriz() { throw; }

};