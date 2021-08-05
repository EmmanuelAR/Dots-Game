#pragma once
#include "EstrategiaPadre.h"
class EstrategiaCercana :
	public EstrategiaPadre
{
private:
	Jugada** posibilidades;
	int cant;
	int tam;

public:
	EstrategiaCercana();
	virtual ~EstrategiaCercana();
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
