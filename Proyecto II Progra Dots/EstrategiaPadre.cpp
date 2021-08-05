#include "EstrategiaPadre.h"

EstrategiaPadre::EstrategiaPadre()
{
	nombre = "";
	campo = NULL;
	ultimaJugada = NULL;
	f = 0;
	c = 0;
	m = NULL;
	this->noP = new Lista<Jugada>;
	this->siP = new Lista<Jugada>;
}

EstrategiaPadre::~EstrategiaPadre()
{
}

void EstrategiaPadre::setCampo(Elemento* a)
{
	campo = (CampoJuego*)a;
	f = campo->getTamFila();
	c = campo->getTamColumna();
	m = campo->getMatriz();
}

void EstrategiaPadre::setUltimaJugada(Jugada* j)
{
	if (ultimaJugada != NULL) {
		delete ultimaJugada;
		ultimaJugada = NULL;
	}

	ultimaJugada = j;
}

bool EstrategiaPadre::esInsertable(int i, int j)
{
	if (i >= 0 && j >= 0 && i < f && j < c && (!(i % 2 == 1 && j % 2 == 1))) {
		if (m[i][j] == NULL) {
			if (i % 2 == 0 && j % 2 == 1) {
				if (dynamic_cast<Punto*>(m[i][j - 1]) && dynamic_cast<Punto*>(m[i][j + 1])) {
					return true; //puede insertar 
				}
			}
			if (i % 2 == 1 && j % 2 == 0) {
				if (dynamic_cast<Punto*>(m[i - 1][j]) && dynamic_cast<Punto*>(m[i + 1][j])) {
					return true; //puede insertar 
				}
			}
		}
	}
	return false;
}



Jugada* EstrategiaPadre::jugarInteligente()
{
	Jugada* jugada = NULL;
	jugada = rectanguloInteligente();
	if (jugada) {
		return jugada;
	}
	else {
		jugada = cerrarCuadradoInteligente();
		if (jugada) {
			return jugada;
		}
	}
	jugada = buscarCuadradoVacioInteligente();
	if (jugada) {
		return jugada;
	}
	jugada = cerrarSemiCuadradoInteligente();
	if (jugada) {
		return jugada;
	}
	return jugada;
}

Jugada* EstrategiaPadre::rectanguloInteligente()
{
	Jugada* jugada = NULL;
	if (c >= 5) {
		for (int i = 1; i <= f - 2; i += 2) {
			for (int j = 1; j <= c - 4; j += 2) {
				if (m[i - 1][j] != NULL && m[i + 1][j] != NULL && m[i - 1][j + 2] != NULL && m[i + 1][j+2] != NULL&&
					m[i][j-1]!=NULL && m[i][j+3]!=NULL&&m[i][j+1]==NULL) {
					if (esInsertable(i, (j + 1))) {
						jugada =  new Jugada(i, (j + 1));
						return jugada;
					}
					else {
						jugada = NULL;
					}
				}
			}
		}
	}
	if (f >= 5 && jugada == NULL) {
		for (int j = 1; j <= c - 2; j += 2) {
			for (int i = 1; i <= f - 4; i += 2) {
				if (m[i][j - 1] != NULL && m[i][j + 1] != NULL && m[i + 2][j - 1] != NULL && m[i + 2][j + 1] != NULL &&
					m[i - 1][j] != NULL && m[i + 3][j] != NULL && m[i + 1][j] == NULL) {
					if (esInsertable((i+1), j)) {
						jugada = new Jugada((i+1), j);
						return jugada;
					}
					else {
						jugada = NULL;
					}
				}
			}
		}
	}
	return jugada;
}

Jugada* EstrategiaPadre::cerrarCuadradoInteligente()
{
	Jugada* jugada = NULL;
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			cont = 0;
			if (m[i - 1][j] != NULL) {
				if (dynamic_cast<LineaH*>(m[i - 1][j])) {
					cont++;
				}
			}
			if (m[i + 1][j] != NULL) {
				if (dynamic_cast<LineaH*>(m[i + 1][j])) {
					cont++;
				}
			}
			if (m[i][j - 1] != NULL) {
				if (dynamic_cast<LineaV*>(m[i][j - 1])) {
					cont++;
				}
			}
			if (m[i][j + 1] != NULL) {
				if (dynamic_cast<LineaV*>(m[i][j + 1])) {
					cont++;
				}
			}

			if (cont == 3) {
				if (m[i - 1][j] == NULL) {
					if (esInsertable(i-1, j)) {
						jugada = new Jugada(i - 1, j);
						return jugada;
					}
				}
				else if (m[i + 1][j]==NULL) {
					if (esInsertable(i+1, j)) {
						jugada = new Jugada(i + 1, j);
						return jugada;
					}
				}
				else if (m[i][j - 1]==NULL) {
					if (esInsertable(i, j-1)) {
						jugada = new Jugada(i, j - 1);
						return jugada;
					}
				}
				else if (m[i][j + 1]==NULL) {
					if (esInsertable(i, j+1)) {
						jugada = new Jugada(i, j + 1);
						return jugada;
					}
				}
			}
		}
	}
	return jugada;
}

Jugada* EstrategiaPadre::cerrarSemiCuadradoInteligente()
{
	Jugada* jugada = NULL;
	int cont = 0;
	int numAleatorio = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			cont = 0;
			if (m[i - 1][j] != NULL) {
				if (dynamic_cast<LineaH*>(m[i - 1][j])) {
					cont++;
				}
			}
			if (m[i + 1][j] != NULL) {
				if (dynamic_cast<LineaH*>(m[i + 1][j])) {
					cont++;
				}
			}
			if (m[i][j - 1] != NULL) {
				if (dynamic_cast<LineaV*>(m[i][j - 1])) {
					cont++;
				}
			}
			if (m[i][j + 1] != NULL) {
				if (dynamic_cast<LineaV*>(m[i][j + 1])) {
					cont++;
				}
			}
			if (cont == 1) {
				if (m[i - 1][j] == NULL) {
					//numAleatorio = 0 + rand() % 1;
					if (esInsertable(i - 1, j)) {
						//if (numAleatorio == 1) {
							jugada = new Jugada(i - 1, j);
							return jugada;
						//}
					}
				}
				else if (m[i + 1][j] == NULL) {
					//numAleatorio = 0 + rand() % 1;
					if (esInsertable(i + 1, j)) {
						//if (numAleatorio == 1) {
							jugada = new Jugada(i + 1, j);
							return jugada;
						//}
					}
				}
				else if (m[i][j - 1] == NULL) {
					//numAleatorio = 0 + rand() % 1;
					if (esInsertable(i, j - 1)) {
						//if (numAleatorio == 1) {
							jugada = new Jugada(i, j - 1);
							return jugada;
						//}
					}
				}
				else if (m[i][j + 1] == NULL) {
					//numAleatorio = 0 + rand() % 1;
					if (esInsertable(i, j + 1)) {
						//if (numAleatorio == 1) {
							jugada = new Jugada(i, j + 1);
							return jugada;
						//}
					}
				}
			}
		}
	}
	return jugada;
}


Jugada* EstrategiaPadre::jugarAleatorio_Tonto()
{
	Jugada* jugada = NULL;
	bool bandera = false;
	int i = 0;
	int j = 0;
	while (!bandera) {
		i = 0 + rand() % f;
		j = 0 + rand() % c;
		bandera = esInsertable(i, j);
	}
	return  new Jugada(i, j);  //Jugada tonta
}

Jugada* EstrategiaPadre::cerrarJugada()
{
	Jugada* jugada = NULL;
	jugada = rectanguloInteligente();
	if (jugada) {
		return jugada;
	}
	else {
		jugada = cerrarCuadradoInteligente();
		if (jugada) {
			return jugada;
		}
	}
	return jugada;
}

Jugada* EstrategiaPadre::buscarCuadradoVacioInteligente()
{
	Jugada* jugada = NULL;
	int i = 0;
	int j = 0;
	int a = 0;
	bool bandera = true;
	if (hayCuadradosVacio()) {
		while (bandera) {
			i = 1 + rand() % f - 2;
			j = 1 + rand() % c - 2;
			if (i % 2 == 1 && j % 2 == 1) {
				if (esCuadradoVacio(i, j)) {
					bandera = false;
					a = 1 + rand() % 4;
					if (a == 1) {
						jugada =  new Jugada(i - 1, j);
					}
					else if (a == 2) {
						jugada =  new Jugada(i + 1, j);
					}
					else if (a == 3) {
					    jugada = new Jugada(i, j - 1);
					}
					else if (a == 4) {
						jugada =  new Jugada(i, j + 1);
					}
				}
			}
		}
	}
	return jugada;
}


int EstrategiaPadre::contarCudradosVacios()
{
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			if (esCuadradoVacio(i, j)) {
				cont++;
			}
		}
	}
	return cont;
}


bool EstrategiaPadre::esCuadradoNulo(int i, int j)
{
	if (m[i + 1][j - 1] == NULL || m[i + 1][j + 1 ] == NULL) {
		return true;
	}
	return false;
}

bool EstrategiaPadre::esCuadradoVacio(int i, int j)
{
	if (!esCuadradoNulo(i,j)) {
		if (m[i-1][j]==NULL ){
			if (m[i + 1][j] == NULL) {
				if (m[i][j - 1] == NULL) {
					if (m[i][j + 1]==NULL) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool EstrategiaPadre::hayCuadradosVacio()
{
	return (contarCudradosVacios() != 0);
}

bool EstrategiaPadre::esPermitida(int i, int j)//es permitida si no esta en la lista
{
	Nodo<Jugada>* actual = siP->getPrimero();
	Jugada* jugada2 = new Jugada(i, j);
	while (actual != NULL) {
		if (*actual->getObj() == *jugada2) {
			return true;
		}
		actual = actual->getSig();
	}
	delete jugada2;
	return false;
}

void EstrategiaPadre::actualizarNoP()
{
	noP->limpiar();
	siP->limpiar();
	Jugada* jugada = NULL;
	int cont = 0;
	int numAleatorio = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			cont = 0;
			if (!esCuadradoNulo(i, j)) {
				if (m[i - 1][j] != NULL) {
					if (dynamic_cast<LineaH*>(m[i - 1][j])) {
						cont++;
					}
				}
				if (m[i + 1][j] != NULL) {
					if (dynamic_cast<LineaH*>(m[i + 1][j])) {
						cont++;
					}
				}
				if (m[i][j - 1] != NULL) {
					if (dynamic_cast<LineaV*>(m[i][j - 1])) {
						cont++;
					}
				}
				if (m[i][j + 1] != NULL) {
					if (dynamic_cast<LineaV*>(m[i][j + 1])) {
						cont++;
					}
				}
				if (cont == 2) {
					if (m[i - 1][j] == NULL) {
						if (esInsertable(i - 1, j) && !estaEnNoP(i-1,j)) {
							jugada = new Jugada(i - 1, j);
							noP->insertarF(jugada);
						}
					}
					if (m[i + 1][j] == NULL) {
						if (esInsertable(i + 1, j) && !estaEnNoP(i + 1, j)) {
							jugada = new Jugada(i + 1, j);
							noP->insertarF(jugada);
						}
					}
					if (m[i][j - 1] == NULL) {
						if (esInsertable(i, j - 1) && !estaEnNoP(i, j - 1)) {
							jugada = new Jugada(i, j - 1);
							noP->insertarF(jugada);
						}
					}
					if (m[i][j + 1] == NULL) {
						if (esInsertable(i, j + 1) && !estaEnNoP(i, j + 1)) {
							jugada = new Jugada(i, j + 1);
							noP->insertarF(jugada);
						}
					}
				}
			}
		}
	}

	actualizarSiP();
}

bool EstrategiaPadre::estaEnNoP(int i, int j)
{
	return (noP->contiene(new Jugada(i, j)));
}


Jugada* EstrategiaPadre::jugarAleatorio_Inteligente()
{
	Jugada* jugada = NULL;
	bool bandera = false;
	int i = 0;
	int j = 0;
	if (!siP->vacia()) {
		while (!bandera) {
			i = 0 + rand() % f;
			j = 0 + rand() % c;
			if (esPermitida(i, j) && esInsertable(i, j)) {
				bandera = true;
				jugada = new Jugada(i, j);
				return jugada;
			}
		}
	}

	jugada = jugarAleatorio_Tonto();
	if (jugada) {
		return jugada;
	}

	return jugada;
}

void EstrategiaPadre::actualizarSiP()
{
	for (int i = 0; i < f ; i++) {
		for (int j = 0; j < c; j++) {
			if (!this->estaEnNoP(i, j)) {
				if (esInsertable(i, j)) {
					siP->insertarF(new Jugada(i, j));
				}
			}
		}
	} 
}
void EstrategiaPadre::sPMnP()
{
}