#include "EstrategiaPeriferica.h"



EstrategiaPeriferica::EstrategiaPeriferica()
{
	this->nombre = "Juego Periferico";
}

Jugada* EstrategiaPeriferica::retornarJugada(Elemento* a)
{
	this->setCampo(a);
	bordeDisponible = contarBordeDisponible();
	// BREAKPOINT AQUI...
	return analizarCampo(a);
}

Jugada* EstrategiaPeriferica::analizarCampo(Elemento* a)
{
	Jugada* jugada = NULL;
	bool bandera = true;
	int i = 0;
	int j = 0;
	actualizarNoP();
//
//	system("pause");
	jugada = cerrarJugada();
	if (jugada) {
		return jugada;
	}
	else if(hayBordeLibre()) {
		while(hayBordeLibre()) {
			i = 0 + rand() % f;
			j = 0 + rand() % c;
			if (esInsertable(i, j) && esBorde(i, j) && esPermitida(i, j)) {
				jugada = new Jugada(i, j);
				return jugada;
			}
		}
	}
	if(jugada==NULL){
		jugada = jugarAleatorio_Inteligente();
		if (jugada) {
			return jugada;
		}
	}
	
	// BREAKPOINT AQUI....
	return jugada;
}

bool EstrategiaPeriferica::esBorde(int i, int j)
{
	if (i==0||j==0||i==f-1||j==c-1) {
		//bordeDisponible--;
		return true;
	}
	else if (i==4&&(m[i+2][j-1]==NULL||m[i+2][j+1]==NULL)) {
		//bordeDisponible--;
		return true;
	}
	else if ((i == 5 || i == 7) && (m[i + 1][j - 2] == NULL|| m[i + 1][j + 2] == NULL)){
		//bordeDisponible--;
		return true;
	}
	else {
		return false;
	}
}

bool EstrategiaPeriferica::hayBordeLibre()
{

	return (contarBordeDisponible() != 0);
}

int EstrategiaPeriferica::contarBordeDisponible()
{
	int cont = 0;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if ((i == 0||i==f-1) && j % 2 == 1) {
				if (dynamic_cast<Punto*>(m[i][j - 1])&& dynamic_cast<Punto*>(m[i][j + 1])) {
					if (m[i][j] == NULL) {
						//NUEVO
						if (esPermitida(i, j)) {
							cont++;
						}
					}
				}
			}
			else if (i % 2 == 1 && (j == 0||j == c-1)) {
				if (dynamic_cast<Punto*>(m[i-1][j]) && dynamic_cast<Punto*>(m[i+1][j])) {
					if (m[i][j] == NULL) {
						//NUEVO
						if (esPermitida(i, j)) {
							cont++;
						}
					}
				}
			}
			else if (i == 4 && j % 2==1) {
				if (m[i + 2][j - 1] == NULL) {
					if (m[i][j] == NULL) {
						//NUEVO
						if (esPermitida(i, j)) {
							cont++;
						}
					}
				}
			}
			//SOLO FALTA ESTE.....
			else if ((i==5||i==7)&&j%2==0 && j!=0&&j!=c-1) {
				if (m[i+1][j-2]==NULL|| m[i + 1][j + 2] == NULL) {
					if (dynamic_cast<Punto*>(m[i - 1][j]) && dynamic_cast<Punto*>(m[i + 1][j])) {
						if (m[i][j] == NULL) {
							//NUEVO
							if (esPermitida(i, j)) {
								cont++;
							}
						}
					}
				}
			}
		}
	}
	return cont;
}

string EstrategiaPeriferica::getNombre()
{
	return nombre;
}

