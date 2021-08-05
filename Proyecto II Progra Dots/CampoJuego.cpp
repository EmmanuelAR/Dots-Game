#include "CampoJuego.h"

CampoJuego::CampoJuego()
{
	tam = 10;
	cant = 0;
	f = 0;
	c = 0;
	m = NULL;
	disponibles = 0;
	integrador = NULL;
	vec = new Elemento * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
}

CampoJuego::~CampoJuego()
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




CampoJuego::CampoJuego(CampoJuego& c2)
{
	this->tam = 10;
	this->cant = 0;
	this->f = 0;
	this->c = 0;
	this->m = NULL;
	this->disponibles = 0;
	this->integrador = NULL;
	this->vec = new Elemento * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
	for (int i = 0; i < c2.cant; i++) {
		if (dynamic_cast<NuevePuntos*>(c2.vec[i])) {
			this->agregar(new NuevePuntos());
		}
		if (dynamic_cast<SeisPuntos*>(c2.vec[i])) {
			this->agregar(new SeisPuntos());
		}
		if (dynamic_cast<QuincePuntos*>(c2.vec[i])) {
			this->agregar(new QuincePuntos());
		}
	}
	this->crearMatriz();
}



void CampoJuego::agregar(Elemento* ele)
{
	if (cant < tam) {
		vec[cant++] = ele;
	}
}
Elemento** CampoJuego::getVec()
{
	return vec;
}
int CampoJuego::getCantVec()
{
	return cant;
}

bool CampoJuego::insertar(int x, int y, int n)
{
	Elemento* ele = NULL;
	(x % 2 == 0) ? ele = new LineaH(x, y) : ele = new LineaV(x, y);
	
	if (x >= 0 && y >= 0 && x < f && y < c && (!(x % 2 == 1 && y % 2 == 1))) {

		if (x == 0 && y == 0) {
			return true;
		}


		if (m[x][y] == NULL) {
			ele->setColor(n);
			if (color == 3) { color = 1; }
			if (x % 2 == 0 && y % 2 == 1) {
				if (dynamic_cast<Punto*>(m[x][y - 1]) && dynamic_cast<Punto*>(m[x][y + 1])) {
					m[x][y] = ele;
					disponibles--;
					
					return true;
				}
			}
			if (x % 2 == 1 && y % 2 == 0) {
				if (dynamic_cast<Punto*>(m[x - 1][y]) && dynamic_cast<Punto*>(m[x + 1][y])) {
					m[x][y] = ele;
					disponibles--;
					
					return true;
				}
			}
		}
	}
	return false;
}

void CampoJuego::toString()
{
	cout<< "Movientos Disponibles: " << disponibles<< endl;
	cout<< "  ";
	for (int j = 0; j < c; j++) {
		cout<< j << " ";
	}
	cout<< "[J]" << endl;
	for (int i = 0; i < f; i++) {
		Consola::textColor(15);
		cout<< i << " ";
		for (int j = 0; j < c; j++) {
			//
			
			//
			if (i % 2 == 1 && j % 2 == 1 && m[i][j] != NULL) {
				if (j < 11) {
					cout << " ";
					m[i][j]->toString();

					cout << " ";
				}
				else {
					cout << "  ";
					m[i][j]->toString();

					cout << "  ";
				}

			}
			else if (m[i][j] != NULL) { 
				m[i][j]->toString();

			}
			//ESTE ESTA BUENO
			/*else if (j % 2 == 1) { 
				cout<< "   ";
			}*/
			//BORRAR ESTE
			else if (j % 2 == 1) {
				if (j >= 11) {
					cout<< "     ";
				}
				else {
					cout<< "   ";
				}
			
			}
			if (j % 2 == 0 && m[i][j] == NULL) { cout<< " "; }
		}
		cout<< endl;
	}
	cout<< "[I]" << endl;

}

bool CampoJuego::insertarNumero(int n)
{
	Elemento* nu = NULL;
	bool bandera = false;;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (i % 2 == 1 && j % 2 == 1) {
				if (m[i - 1][j] != NULL && m[i + 1][j] != NULL &&
					m[i][j - 1] != NULL && m[i][j + 1] != NULL) {
					if (m[i][j] == NULL) {
						m[i][j] = new Numero(n);
						bandera = true;
					}
				}
			}
		}
	}
	return bandera;
}

bool CampoJuego::lleno()
{
	return (disponibles == 0);
}

int CampoJuego::ganador()
{
	Numero* num = NULL;
	int cont1 = 0, cont2 = 0;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (i % 2 == 1 && j % 2 == 1&&(dynamic_cast<Numero*>(m[i][j]))) {
				num = (Numero*)m[i][j];
				(num->getN() == 1) ? cont1++ : cont2++;
			}
		}
	}

	if (cont1 > cont2) { return 1; }
	if (cont2 > cont1) { return 2; }
	return 3;
}

void CampoJuego::crearMatriz()
{
	integrador = new Integrador(vec,cant,f,c);
	m = integrador->matrizResultante();
	disponibles = getMovimientosDisponibles();
}

int CampoJuego::getTamFila()
{
	return f;
}

int CampoJuego::getTamColumna()
{
	return c;
}

int CampoJuego::getMovimientosDisponibles()
{
	int cont = 0;
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			if (m[i][j] == NULL) {
				if (i % 2 == 0 && j % 2 == 1) {
					if (dynamic_cast<Punto*>(m[i][j - 1]) && dynamic_cast<Punto*>(m[i][j + 1])) {
						cont++;
					}
				}
				if (i % 2 == 1 && j % 2 == 0) {
					if (dynamic_cast<Punto*>(m[i-1][j]) && dynamic_cast<Punto*>(m[i+1][j])) {
						cont++;
					}
				}
			}
		}
	}
	return cont;
}

int CampoJuego::getDisponibles()
{
	return disponibles;
}

void CampoJuego::guardar(ofstream& out)
{
	out << cant << "\t";
	for (int i = 0; i < cant; i++) {
		if (dynamic_cast<SeisPuntos*>(vec[i])) {
			out << typeid(*vec[i]).name() << "\t";
		}
		if (dynamic_cast<NuevePuntos*>(vec[i])) {
			out << typeid(*vec[i]).name() << "\t";
		}
		if (dynamic_cast<QuincePuntos*>(vec[i])) {
			out << typeid(*vec[i]).name() << "\t";
		}
	}

}

void CampoJuego::leer(ifstream& in)
{
	string cant1, campo;
	getline(in, cant1, '\t');
	tam = 10;
	cant = 0;
	f = 0;
	c = 0;
	m = NULL;
	disponibles = 0;
	integrador = NULL;
	vec = new Elemento * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = NULL;
	}
	for (int i = 0; i < atoi(cant1.c_str()); i++) {
		getline(in, campo, '\t');
		if (campo == "class SeisPuntos") {
			agregar(new SeisPuntos());
		}
		if (campo == "class NuevePuntos") {
			agregar(new NuevePuntos());
		}
		if (campo == "class QuincePuntos") {
			agregar(new QuincePuntos());
		}
	}
	this->crearMatriz();
}

