#pragma once
#include"Elemento.h"
#include"Punto.h"
#include"LineaH.h"
#include"LineaV.h"
#include"Numero.h"

class CampoAbs:public Elemento {
protected:
	Elemento*** m;
public:
	CampoAbs() { m = NULL; }
	virtual ~CampoAbs() {}
	//Aplicando Composite
	virtual bool insertar(int i, int j, int n) { throw; }
	virtual void toString() = 0;
	virtual bool insertarNumero(int n) = 0;
	virtual bool lleno() = 0;
	virtual int ganador() = 0;
	virtual int getTamFila() = 0;
	virtual int getTamColumna() = 0;
	virtual void crearMatriz() = 0;
	virtual void agregar(Elemento* ele) { throw; }
	virtual Elemento*** getMatriz() { return m; }
};
