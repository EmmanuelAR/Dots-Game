#include "EstrategiaCentral.h"


EstrategiaCentral::EstrategiaCentral()
{
	
	this->nombre = "Juego Central";
	vecRango = new Jugada * [40];
	tam = 40;
	cant = 0;
	for (int i = 0; i < tam; i++) {
		vecRango[i] = NULL;
	}
	//varibles de rango
	derecha = 0;
	izquierda = 0;
	abajo = 0;
	arriba = 0;
	banderaPunto = true;
}

EstrategiaCentral::~EstrategiaCentral()
{
	for (int i = 0; i < cant; i++) {
		delete vecRango[i];
	}
	delete[] vecRango;
}

Jugada* EstrategiaCentral::retornarJugada(Elemento* a)
{
	this->setCampo(a);
	return analizarCampo(a);
}



Jugada* EstrategiaCentral::analizarCampo(Elemento* a)
{
	Jugada* jugada = NULL;

	actualizarNoP();
	jugada = this->cerrarJugada();
	if (jugada) {
		return jugada;
	}

	if (banderaPunto == true) { //la primera vez
		banderaPunto == false;
		this->busquedaPuntoMedio();
		if (m[arriba][derecha] == NULL) {
			jugada = new Jugada(arriba, derecha);
			return jugada;
		}
		else {
			actulizarRango();
			actualizarVector();
			jugada = analizaVector();
			if (jugada) {
				return jugada;
			}
		}
	}

	do {
		actualizarVector();
		jugada = analizaVector();
		if (jugada) {
			return jugada;
		}
		else {
			actulizarRango();

		}
	} while (!siP->vacia());

	if (siP->vacia()) {
		jugada = jugarAleatorio_Inteligente();
		return jugada;
	}

	return jugada;
}

string EstrategiaCentral::getNombre()
{
	return nombre;
}




void EstrategiaCentral::agregarPosibilidad(Jugada* a)
{
	if (cant < tam) {
		if (!this->existe(a)) {
			vecRango[cant++] = a;
		}
		else {
			delete a;
		}
	}
}

string EstrategiaCentral::mostrarVecRango()
{
	stringstream s;
	for (int i = 0; i < cant; i++) {
		s << vecRango[i]->toString() << endl;
	}
	return s.str();
}




Jugada* EstrategiaCentral::analizaVector()
{
	int i = 0;
	int j = 0;
	Jugada* jugada = NULL;
	if (vectorVacio()) {
		return jugada;
	}
	else {
		for (int z = 0; z < cant; z++) {
			i = vecRango[z]->getI();
			j = vecRango[z]->getJ();
			if (esPermitida(i, j) && esInsertable(i, j)) {
				return new Jugada(*vecRango[z]);
			}
		}
	}
	return jugada;
}







bool EstrategiaCentral::existe(Jugada* a)
{
	for (int i = 0; i < cant; i++) {
		if (*a == *vecRango[i]) {
			return true;
		}
	}
	return false;
}

void EstrategiaCentral::limpiarVector()
{
	for (int i = 0; i < cant; i++) {
		delete vecRango[i];
		vecRango[i] = NULL;
	}
	cant = 0;
}

void EstrategiaCentral::busquedaPuntoMedio()//sacamos el punto medio de la matriz
{
	if (f == 5) {
		arriba = 2;
		abajo = 2;
	}
	else if (f > 5) {
		abajo = 4;
		arriba = 4;
	}
	izquierda = c / 2;
	derecha = c / 2;


}

void EstrategiaCentral::actualizarVector()
{
	//this->actulizarRango();
	this->limpiarVector();
	for (int i = arriba; i <= abajo; i++) {
		for (int j = izquierda; j <= derecha; j++) {
			if (esPermitida(i, j) && esInsertable(i, j)) {
				this->agregarPosibilidad(new Jugada(i, j));
			}
		}
	}



}

void EstrategiaCentral::actulizarRango()
{

	if (arriba >= 0) {
		arriba--;
	}
	if (abajo <= f - 1) {
		abajo++;
	}
	if (derecha <= c - 1) {
		derecha++;
	}
	if (izquierda >= 0) {
		izquierda--;
	}
}

bool EstrategiaCentral::vectorVacio()
{
	return cant == 0;
}
