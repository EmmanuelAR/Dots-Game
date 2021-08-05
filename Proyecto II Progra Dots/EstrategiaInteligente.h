#pragma once
//EstrategiaInteligente
#pragma once
#include "EstrategiaPadre.h"
class EstrategiaInteligente :
	public EstrategiaPadre
{
public:
	EstrategiaInteligente();
	virtual Jugada* retornarJugada(Elemento*);
	virtual Jugada* analizarCampo(Elemento*);
	virtual string getNombre();
};

