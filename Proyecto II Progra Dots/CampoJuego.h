#pragma once
#include"CampoAbs.h"
#include"Integrador.h"//
#include"Consola.h"
#include"fstream"
class CampoJuego :
	public CampoAbs
{
private:
	Elemento** vec;
	Integrador* integrador;
	int cant;
	int tam;
	int f;
	int c;
	int disponibles;
public:
	CampoJuego();
	virtual ~CampoJuego();
	CampoJuego(CampoJuego& c2);
	//Metodos del Vector
	virtual void agregar(Elemento* ele);
	virtual Elemento** getVec();
	virtual int getCantVec();
	//
	//Aplicando Composite
	virtual void toString();
	virtual bool insertar(int i, int j, int n);
	virtual bool insertarNumero(int n);
	virtual bool lleno();
	virtual int ganador();
	virtual void crearMatriz();
	virtual int getTamFila();
	virtual int getTamColumna();
	virtual int getMovimientosDisponibles();
	virtual int getDisponibles();
	virtual void guardar(ofstream& out);
	virtual void leer(ifstream& in);
	//Sets //Gets
	
};

