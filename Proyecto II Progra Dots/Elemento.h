#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#include"Consola.h"

class Elemento
{
protected:
	int color;
public:
	Elemento(){ color = 0; }
	virtual ~Elemento() {}
	virtual void toString() = 0;
	virtual bool insertar(int i, int j,int n) = 0;
	virtual bool insertarNumero(int n) = 0;
	virtual bool lleno() = 0;
	virtual int ganador() = 0;
	virtual int getTamFila() = 0;
	virtual int getTamColumna() = 0;
	virtual void crearMatriz() = 0;
	virtual void agregar(Elemento* ele) { throw; }//
	virtual Elemento*** getMatriz() { throw; }
	virtual int getMovimientosDisponibles() { throw; }
	virtual int getDisponibles() { throw; }
	virtual void setColor(int color) { throw; }//
	virtual Elemento** getVec() { throw; }
	virtual int getCantVec() { throw; }
	virtual void guardar(ofstream& out) { throw; }
	virtual void leer(ifstream& in) { throw; }
};

