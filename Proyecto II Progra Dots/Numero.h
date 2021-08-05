#pragma once
#include "Elemento.h"
class Numero :
	public Elemento
{
private:
	int n;
public:
	Numero(int n);
	virtual ~Numero();
	int getN();
	virtual void toString();
	//Aplicando Composite
	virtual bool insertar(int i, int j, int n) { throw; }
	virtual bool insertarNumero(int n) { throw; }
	virtual bool lleno() { throw; }
	virtual int ganador() { throw; }
	virtual int getTamFila() { throw; }
	virtual int getTamColumna() { throw; }
	virtual void crearMatriz() { throw; }
	virtual void setColor(int color) { this->color = color; }
};
