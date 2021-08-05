#include "NuevePuntos.h"

NuevePuntos::NuevePuntos() :CampoAbs()
{
	this->f = 5;
	this->c = 5;
	m = new Elemento * *[f];
	for (int i = 0; i < f; i++) {
		m[i] = new Elemento * [c];
	}
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			m[i][j] = NULL;
		}
	}
	int cont = 0;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (cont % 2 == 0 && j % 2 == 0) { m[i][j] = new Punto(i, j); }
		}
		cont++;
	}
}

NuevePuntos::~NuevePuntos()
{
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] != NULL) {
				delete m[i][j];
			}
		}
	}
	for (int i = 0; i < f; i++) {
		delete m[i];
	}
	delete[] m;
}

bool NuevePuntos::insertar(int x, int y, int n)
{
	Elemento* ele = NULL;
	(x % 2 == 0) ? ele = new LineaH(x, y) : ele = new LineaV(x, y);

	if (x >= 0 && y >= 0 && x < f && y < c && (!(x % 2 == 1 && y % 2 == 1))) {
		if (m[x][y] == NULL) { m[x][y] = ele; return true; }
	}
	return false;
}

void NuevePuntos::toString()
{
	cout << "  ";
	for (int j = 0; j < c; j++) {
		cout << j << " ";
	}
	cout << "Y" << endl;
	for (int i = 0; i < f; i++) {
		cout << i << " ";
		for (int j = 0; j < c; j++) {
			if (i % 2 == 1 && j % 2 == 1 && m[i][j] != NULL) {
				cout << " ";
				m[i][j]->toString();
				cout << " ";
			}
			else if (m[i][j] != NULL) {
				m[i][j]->toString();
			}
			else if (j % 2 == 1) { cout << "   "; }
			if (j % 2 == 0 && m[i][j] == NULL) { cout << " "; }
		}
		cout << endl;
	}
	cout << "X" << endl;
}

bool NuevePuntos::insertarNumero(int n)
{
	Elemento* nu = NULL;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (i % 2 == 1 && j % 2 == 1) {
				if (m[i - 1][j] != NULL && m[i + 1][j] != NULL &&
					m[i][j - 1] != NULL && m[i][j + 1] != NULL) {
					if (m[i][j] == NULL) {
						m[i][j] = new Numero(n);
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool NuevePuntos::lleno()
{
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] == NULL) {
				return false;
			}
		}
	}
	return true;
}

int NuevePuntos::ganador()
{
	Numero* num = NULL;
	int cont1 = 0, cont2 = 0;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (i % 2 == 1 && j % 2 == 1) {
				num = (Numero*)m[i][j];
				(num->getN() == 1) ? cont1++ : cont2++;
			}
		}
	}

	if (cont1 > cont2) { return 1; }
	if (cont2 < cont1) { return 2; }
	return 3;
}

int NuevePuntos::getTamFila()
{
	return f;
}

int NuevePuntos::getTamColumna()
{
	return c;
}
