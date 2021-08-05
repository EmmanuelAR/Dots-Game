#pragma once
#include"Elemento.h"
class Linea :public Elemento
{
protected:
	int x;
	int y;
	string p;
public:
	Linea() { x = 0; y = 0; p = ""; }
	virtual ~Linea() {}
	virtual void toString() = 0;
	int getX() { return x; }
	int getY() { return y; }
	string getP() { return p; }
	//Aplicando Composite
	virtual bool insertar(int i, int j, int n) = 0;
	virtual bool insertarNumero(int n) = 0;
	virtual bool lleno() = 0;
	virtual int ganador() = 0;
	virtual int getTamFila() = 0;
	virtual int getTamColumna() = 0;
	virtual void crearMatriz() = 0;
	virtual void setColor(int color) { this->color = color; }
};

