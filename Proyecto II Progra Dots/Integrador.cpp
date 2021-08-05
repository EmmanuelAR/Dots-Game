#include "Integrador.h"
//

Integrador::Integrador(Elemento** vecCJ, int validos,int &f, int &c):f(f),c(c)
{
	this->f = f;
	this->c = c;
	vec = vecCJ;
	cant = validos;
}

Integrador::~Integrador()
{
}

Elemento*** Integrador::integrar()
{
	Elemento*** m = NULL;
	tamMatriz();
	m = crearMatriz();
	return m;
}



Elemento*** Integrador::crearMatriz()
{
	
	Elemento*** m = new Elemento * *[f];
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
	return m;
}

void Integrador::tamMatriz()
{
	int cont = cant;
	int aux = 0;
	//auxiliar va a ser igual al tamanio de filas mayor
	while (cont > 0) {
		if (vec[cont-1]->getTamFila()>aux) {
			aux = vec[cont - 1]->getTamFila();
		}
		cont--;
	}
	//aqui le da el tamanio de filas a la matriz
	f = aux;
	cont = cant;
	while (cont > 0) {
		c += vec[cont - 1]->getTamColumna();
		cont--;
	}
	//if (cant == 2) { c += 1; }
	//if (cant == 3) { c += 2; }
	if (cant != 1) { c += cant-1; }
}

Elemento*** Integrador::matrizResultante()
{
	Elemento*** m = NULL;
	if (cant == 1) {
		m = integrar();
	}
	if (cant >1) {//cant==2
		if (!existeMatrizQuinceP()) {
			m = integrar();
		}
		else {
			m = integrar();
			insertarNulos(m);
		}
	}
	return m;
}

bool Integrador::existeMatrizQuinceP()
{
	int cont = cant;
	while (cont > 0) {
		if (dynamic_cast<QuincePuntos*>(vec[cont - 1])) {
			return true;
		}
		cont--;
	}
	return false;
}

bool Integrador::todosSonMatrizQuinceP()
{
	int cont = cant;
	int aux = 0;
	while (cont > 0) {
		if (dynamic_cast<QuincePuntos*>(vec[cont - 1])) {
			aux++;
		}
		cont--;
	}
	return (aux > 1) ? true : false;
}

void Integrador::insertarNulos(Elemento*** m)//linea 81
{
	int fila = 6;
	int pos = 0;
	int hacer = 0;
	int cont = 0;
	bool bandera = false;
	int aux = 0;
	//cout << "Tamaniovec[" << 0 << "]" <<vec[0]->getTamColumna()<< endl;
	//cout << "Tamaniovec[" << 1 << "]" << vec[0]->getTamColumna() << endl;
	//cout << "Tamaniovec[" << 2 << "]" << vec[0]->getTamColumna() << endl;
	//cout << "Cant: " << cant << endl << endl;
	while (fila!=8&&cont!=c+1) {
		if (dynamic_cast<NuevePuntos*>(vec[pos])) {
			hacer = 3;
			bandera = true;
		}
		if (dynamic_cast<SeisPuntos*>(vec[pos])) {
			hacer = 5;
			bandera = true;
		}
		fila = 6;
		while (bandera) {
			if (m[fila][cont] != NULL) {
				//cout << "delete m[" << fila << "][" << cont << "]" << endl;
				delete m[fila][cont];
				m[fila][cont] = NULL;
			}
			if (fila == 8) { bandera = false; }
			fila += 2;
		}
		cont++;
		aux++;
		if (aux == vec[pos]->getTamColumna()) {
			pos++;
			cont ++;
			aux = 0;
		}
	}
}