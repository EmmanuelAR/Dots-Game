#pragma once
#include"Elemento.h"

class Punto :public Elemento
{
private:
	int x;
	int y;
	char p;
public:
	Punto(int x, int y);
	virtual ~Punto();
	virtual void toString();
	int getX();
	int getY();
	char getP();
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
