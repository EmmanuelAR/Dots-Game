#pragma once
#include "EstrategiaPadre.h"
class EstrategiaCentral :
	public EstrategiaPadre
{
private:
	Jugada** vecRango;
	int cant;
	int tam;
	//Variables del rango
	int derecha;
	int izquierda;
	int abajo;
	int arriba;
	bool banderaPunto;

public:
	EstrategiaCentral();
	virtual ~EstrategiaCentral();
	virtual Jugada* retornarJugada(Elemento*);
	virtual Jugada* analizarCampo(Elemento*);
	virtual string getNombre();

	//metodos del vector
	void agregarPosibilidad(Jugada*);
	string mostrarVecRango();
	Jugada* analizaVector();
	bool  existe(Jugada*);
	void limpiarVector();
	//metodos de estrategia
	void busquedaPuntoMedio();
	void actualizarVector();
	void actulizarRango();
	bool vectorVacio();

};
