#include "EstrategiaCercana.h"

EstrategiaCercana::EstrategiaCercana()
{
	this->nombre = "Juego Cercano";
	posibilidades = new Jugada * [40];
	tam = 40;
	cant = 0;
	for (int i = 0; i < tam; i++) {
		posibilidades[i] = NULL;
	}
}

EstrategiaCercana::~EstrategiaCercana()
{
	for (int i = 0; i < cant; i++) {
		delete posibilidades[i];
	}
	delete[] posibilidades;
}

Jugada* EstrategiaCercana::retornarJugada(Elemento* a)
{
	this->setCampo(a);
	return analizarCampo(a);
}

Jugada* EstrategiaCercana::analizarCampo(Elemento* a)
{
	Jugada* jugada = NULL;
	actualizarNoP();
	jugada = buscarJugadaMasCercana();
	if (jugada) {
		return jugada;
	}
	else {
		jugada = jugarAleatorio_Inteligente();
	}
	return jugada;

}

string EstrategiaCercana::getNombre()
{
	return nombre;
}

Jugada* EstrategiaCercana::buscarJugadaMasCercana()
{	
	Jugada* jugada = NULL;
	jugada = cerrarJugada();
	if (jugada) {
		return jugada;
	}
	else {
		jugada = analizaVector();
	}
	return jugada;
}



void EstrategiaCercana::estaArriba()
{
	Jugada* jugada = NULL;
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			if (!this->esCuadradoNulo(i, j)) {
				if ((i - 1) == ultimaJugada->getI() && (j) == ultimaJugada->getJ()) {
					cont = 0;
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

					if (cont == 0 || cont == 3) {
						 if (m[i][j - 1] == NULL) {
							if (esInsertable(i, j - 1)) {
								jugada = new Jugada(i, j - 1);
								this->agregarPosibilidad(jugada);
							}
						}
						 if (m[i][j + 1] == NULL) {
							if (esInsertable(i, j + 1)) {
								jugada = new Jugada(i, j + 1);
								this->agregarPosibilidad(jugada);
							}
						}
					}
					//ESTO ES LO NUEVO....
					if (c >= 5) {
						if (j == 1) {
							if (i >= 1 && i <= f - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i - 1][j + 2] == NULL) {
										if (esInsertable(i - 1, j + 2)) {
											jugada = new Jugada(i - 1, j + 2);
											this->agregarPosibilidad(jugada);
										}

									}
								}
							}
						}
						if (j == c - 2) {
							if (i >= 1 && i <= f - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i - 1][j - 2] == NULL) {
										if (esInsertable(i - 1, j - 2)) {
											jugada = new Jugada(i - 1, j - 2);
											this->agregarPosibilidad(jugada);

										}
									}
								}
							}
						}
					}
					if (c >= 11) {
						if (j >= 3 && j <= c - 4) {
							if (!esCuadradoNulo(i, j)) {
								if (m[i - 1][j - 2] == NULL) {
									if (esInsertable(i - 1, j - 2)) {
										jugada = new Jugada(i - 1, j - 2);
										this->agregarPosibilidad(jugada);

									}
								}
								if (m[i - 1][j + 2] == NULL) {
									if (esInsertable(i - 1, j + 2)) {
										jugada = new Jugada(i - 1, j + 2);
										this->agregarPosibilidad(jugada);

									}
								}
							}

						}
					}
				}

			}

		}
	}
}







void EstrategiaCercana::estaAbajo()
{
	Jugada* jugada = NULL;
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			if (!this->esCuadradoNulo(i, j)) {
				if ((i + 1 ) == ultimaJugada->getI() && (j) == ultimaJugada->getJ()) {
					cont = 0;
					if (m[i - 1][j] != NULL) {
						if (dynamic_cast<LineaH*>(m[i - 1][j])) {
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

					if (cont == 0 || cont == 3) {

						 if (m[i][j + 1] == NULL) {
							if (esInsertable(i, j + 1)) {
								jugada = new Jugada(i, j + 1);
								this->agregarPosibilidad(jugada);
							}
						}
						 if (m[i][j - 1] == NULL) {
							if (esInsertable(i, j - 1)) {
								jugada = new Jugada(i, j - 1);
								this->agregarPosibilidad(jugada);
							}
						}
					}
					//NUEVO..............
					if (c >= 5) {
						if (j == 1) {
							if (i >= 1 && i <= f - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i + 1][j + 2] == NULL) {            //m[i-1][i+2]===>m[i+1][i+2]
										if (esInsertable(i + 1, j + 2)) {
											jugada = new Jugada(i + 1, j + 2);
											this->agregarPosibilidad(jugada);
										}

									}
								}
							}
						}
						if (j == c - 2) {
							if (i >= 1 && i <= f - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i + 1][j - 2] == NULL) {
										if (esInsertable(i + 1, j - 2)) {
											jugada = new Jugada(i + 1, j - 2);
											this->agregarPosibilidad(jugada);

										}
									}
								}
							}
						}
					}
					if (c >= 11) {
						if (j >= 3 && j <= c - 4) {
							if (!esCuadradoNulo(i, j)) {
								if (m[i + 1][j - 2] == NULL) {
									if (esInsertable(i + 1, j - 2)) {
										jugada = new Jugada(i + 1, j - 2);
										this->agregarPosibilidad(jugada);

									}
								}
								if (m[i + 1][j + 2] == NULL) {
									if (esInsertable(i + 1, j + 2)) {
										jugada = new Jugada(i + 1, j + 2);
										this->agregarPosibilidad(jugada);

									}
								}
							}

						}
					}
				}

			}

		}
	}
}

void EstrategiaCercana::estaDerecha()
{
	Jugada* jugada = NULL;
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			if (!this->esCuadradoNulo(i, j)) {
				if ((i) == ultimaJugada->getI() && (j+1) == ultimaJugada->getJ()) {
					cont = 0;
					if (m[i - 1][j] != NULL) {
						if (dynamic_cast<LineaH*>(m[i - 1][j])) {
							cont++;
						}
					}
					if (m[i][j - 1] != NULL) {
						if (dynamic_cast<LineaV*>(m[i][j - 1])) {
							cont++;
						}
					}
					if (m[i+1][j] != NULL) {
						if (dynamic_cast<LineaH*>(m[i+1][j])) {
							cont++;
						}
					}

					if (cont == 0 || cont == 3) {

						 if (m[i-1][j ] == NULL) {
							if (esInsertable(i-1,j)) {
								jugada = new Jugada(i - 1, j);
								this->agregarPosibilidad(jugada);
							}
						}
						 if (m[i+1][j] == NULL) {
							if (esInsertable(i+1, j)) {
								jugada = new Jugada(i + 1, j);
								this->agregarPosibilidad(jugada);
							}
						}
					}
					//LO NUEVO...................... DERECHA
					if (f >= 5) { // c>=5   ==> f>=5
						if (i == 1) {
							if (j >= 1 && j <= c - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i + 2][j + 1] == NULL) {            //m[i-1][i+2]===>m[i+1][i+2]
										if (esInsertable(i + 2, j + 1)) {
											jugada = new Jugada(i + 2, j + 1);
											this->agregarPosibilidad(jugada);
										}

									}
								}
							}
						}
						if (i == f - 2) {
							if (j >= 1 && j <= c - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i  - 2][j - 1] == NULL) {
										if (esInsertable(i - 2, j + 1)) {
											jugada = new Jugada(i - 2, j + 1);
											this->agregarPosibilidad(jugada);

										}
									}
								}
							}
						}
					}
					if (f >= 8) {
						if (i >= 3 && i <= f - 4) {
							if (!esCuadradoNulo(i, j)) {
								if (m[i - 2][j + 1] == NULL) {
									if (esInsertable(i - 2, j + 1)) {
										jugada = new Jugada(i - 2, j + 1);
										this->agregarPosibilidad(jugada);

									}
								}
								if (m[i + 2][j + 1] == NULL) {
									if (esInsertable(i + 2, j + 1)) {
										jugada = new Jugada(i + 2, j + 1);
										this->agregarPosibilidad(jugada);

									}
								}
							}

						}
					}
				}

			}

		}
	}
}

void EstrategiaCercana::estaIzquierda()
{
	Jugada* jugada = NULL;
	int cont = 0;
	for (int i = 1; i <= f - 2; i += 2) {
		for (int j = 1; j <= c - 2; j += 2) {
			if (!this->esCuadradoNulo(i, j)) {
				if ((i) == ultimaJugada->getI() && (j - 1) == ultimaJugada->getJ()) {
					cont = 0;
					if (m[i - 1][j] != NULL) {
						if (dynamic_cast<LineaH*>(m[i - 1][j])) {
							cont++;
						}
					}
					if (m[i][j + 1] != NULL) {
						if (dynamic_cast<LineaV*>(m[i][j + 1])) {
							cont++;
						}
					}
					if (m[i + 1][j] != NULL) {
						if (dynamic_cast<LineaH*>(m[i + 1][j])) {
							cont++;
						}
					}

					if (cont == 0 || cont == 3) {

						if (m[i - 1][j] == NULL) {
							if (esInsertable(i - 1, j)) {
								jugada = new Jugada(i - 1, j);
								this->agregarPosibilidad(jugada);
							}
						}
						 if (m[i + 1][j] == NULL) {
							if (esInsertable(i + 1, j)) {
								jugada = new Jugada(i + 1, j);
								this->agregarPosibilidad(jugada);
							}
						}
					}
					//LO NUEVO...................... IZQUIERDA
					if (f >= 5) { // c>=5   ==> f>=5
						if (i == 1) {
							if (j >= 1 && j <= c - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i + 2][j - 1] == NULL) {            //m[i-1][i+2]===>m[i+1][i+2]
										if (esInsertable(i + 2, j - 1)) {
											jugada = new Jugada(i + 2, j - 1);
											this->agregarPosibilidad(jugada);
										}

									}
								}
							}
						}
						if (i == f - 2) {
							if (j >= 1 && j <= c - 2) {
								if (!esCuadradoNulo(i, j)) {
									if (m[i - 2][j - 1] == NULL) {
										if (esInsertable(i - 2, j - 1)) {
											jugada = new Jugada(i - 2, j - 1);
											this->agregarPosibilidad(jugada);

										}
									}
								}
							}
						}
					}
					if (f >= 8) {
						if (i >= 3 && i <= f - 4) {
							if (!esCuadradoNulo(i, j)) {
								if (m[i - 2][j - 1] == NULL) {
									if (esInsertable(i - 2, j - 1)) {
										jugada = new Jugada(i - 2, j - 1);
										this->agregarPosibilidad(jugada);

									}
								}
								if (m[i + 2][j - 1] == NULL) {
									if (esInsertable(i + 2, j - 1)) {
										jugada = new Jugada(i + 2, j - 1);
										this->agregarPosibilidad(jugada);

									}
								}
							}

						}
					}

				}

			}

		}
	}

	
}

void EstrategiaCercana::agregarPosibilidad(Jugada* a)
{
	if (cant < tam) {
		if (!this->existe(a)) {
			posibilidades[cant++] = a;
		}
		else {
			delete a;
		}
	}
}

string EstrategiaCercana::mostrarPosibilidades()
{
	stringstream s;
	for (int i = 0; i < cant; i++) {
		s << posibilidades[i]->toString()<<endl;
	}
	return s.str();
}

Jugada* EstrategiaCercana::analizaVector()
{
	Jugada* jugada = NULL;
	int i = 0;
	int j = 0;
	//LIMPIA
	limpiarVector();
	//LO LLENA
	estaArriba();
	estaAbajo();
	estaDerecha();
	estaIzquierda();

    //ANALIZAR VECTOR
	for (int z = 0; z < cant; z++) {
		i = posibilidades[z]->getI();
		j = posibilidades[z]->getJ();
		if (esPermitida(i, j) && esInsertable(i,j)) {
			return new Jugada(*posibilidades[z]);
		}
	}
	return jugada;
}

bool EstrategiaCercana::existe(Jugada* a)
{
	for (int i = 0; i < cant; i++) {
		if (*a == *posibilidades[i]) {
			return true;
		}
	}
	return false;
}

void EstrategiaCercana::limpiarVector()
{
	for (int i = 0; i < cant; i++) {
		delete posibilidades[i];
		posibilidades[i] = NULL;
	}
	cant = 0;
}
