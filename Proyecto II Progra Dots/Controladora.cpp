#include "Controladora.h"

Controladora::Controladora(){
	e = new EmpresaDots();
}

Controladora::~Controladora()
{
	delete e;
}

void Controladora::principal()
{
	int opcion;
	Vista::presentacion();
	do {
		opcion = Vista::menuPrincipal();
		switch (opcion) {
		case 1: menuSubscriptor(); break;
		case 2: menuPartidas(); break; //crear Partida
		default: break;
		}
	} while (opcion != 3);
	Vista::fin();
}

void Controladora::menuSubscriptor()
{
	int opcion;
	do {
		opcion = Vista::menuSubscriptor();
		switch (opcion) {
		case 1: subscribirse(); break;
		case 2: mostrarSubs(); break;
		case 3: cambioDia(); break;
		default: break;
		}
	} while (opcion != 4);
}

void Controladora::menuPartidas()
{
	int opcion;
	do {
		opcion = Vista::menuPartidas();
		switch (opcion) {
		case 1: crearPartida(); break;
		case 2: Vista::mostrarPartidasGuardadas(e); break;
		case 3: recrearPartida(); break;
		default: break;
		}
	} while (opcion != 4);
}


EmpresaDots* Controladora::getEmpresa()
{
	return e;
}

void Controladora::cambioDia()
{
	e->cambioDia();
	Consola::textColor(2);
	Vista::imprimir("\n<<< EL DIA CAMBIO CON EXITO!!! >>>");
	Sleep(2000);
}

void Controladora::subscribirse()
{
	Vista::subscribirse(e);
}

void Controladora::crearPartida()
{
	Partida* partida = Vista::crearPartida(e);
	if (partida) { 
		Vista::escogerCampo(partida);
		if (dynamic_cast<Persona_Persona*>(partida)) {
			Vista::jugarPP(partida,e);
		}
		else if (dynamic_cast<Persona_Maquina*>(partida)) {
			Vista::jugarPM(partida, e);
		}
	}
}

void Controladora::mostrarSubs()
{
	Vista::mostrarSubs(e);
}

void Controladora::recrearPartida()
{
	try {
		Vista::recrearPartida(e);

	}
	catch (ExcepcionNULLPTR * e) {
		Vista::imprimir(e->toString());
		Consola::textColor(15);
		Vista::systemPause();
	}
}




