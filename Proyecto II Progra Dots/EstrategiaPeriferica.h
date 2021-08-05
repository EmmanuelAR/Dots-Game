#pragma once
#include "EstrategiaPadre.h"
class EstrategiaPeriferica :
	public EstrategiaPadre
{
private:
	int bordeDisponible;
public:
	EstrategiaPeriferica();
	virtual Jugada* retornarJugada(Elemento*);
	virtual Jugada* analizarCampo(Elemento*);
	virtual string getNombre();
	bool esBorde(int i,int j);
	bool hayBordeLibre();
	int contarBordeDisponible();
};

