#pragma once
#include "EstrategiaPadre.h"
class EstrategiaAleatoria :
	public EstrategiaPadre
{
	public:
		EstrategiaAleatoria();
		virtual Jugada* retornarJugada(Elemento*);
		virtual Jugada* analizarCampo(Elemento*);
		virtual string getNombre();
};

