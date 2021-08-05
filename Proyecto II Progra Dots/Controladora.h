#pragma once
#include"EmpresaDots.h"
#include"Vista.h"

class Controladora
{
	private:
		EmpresaDots* e;
	public:
		Controladora();
		~Controladora();
		void principal();
		void menuPartidas();
		void menuSubscriptor();
		EmpresaDots* getEmpresa();
		void cambioDia();
		void subscribirse();
		void crearPartida();
		void mostrarSubs();
		void recrearPartida();
};

