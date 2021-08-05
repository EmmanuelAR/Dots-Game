#pragma once
#include "EstrategiaPadre.h"
class EstrategiaIslas :
	public EstrategiaPadre
{
private:
	Jugada** posibilidades;
	int cant;
	int tam;
	int n;

public:
	EstrategiaIslas();
	virtual ~EstrategiaIslas();
	virtual Jugada* retornarJugada(Elemento*);
	virtual Jugada* analizarCampo(Elemento*);
	virtual string getNombre();
	Jugada* buscarJugadaMasCercana(); //este tiene todoos los metodos de buscar 
	//
	void estaArriba();
	void estaAbajo();
	void estaDerecha();
	void estaIzquierda();
	//
	//metodos del vector
	void agregarPosibilidad(Jugada*);
	string mostrarPosibilidades();
	Jugada* analizaVector();
	bool  existe(Jugada*);
	void limpiarVector();

};

