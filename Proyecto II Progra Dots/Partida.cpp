#include "Partida.h"

Partida::Partida()
{
	campo = new CampoJuego();
	jugadas = new Lista<Jugada>;
	numero = 1;
	numero = generarNumero();
}

Partida::~Partida()
{
	delete campo;
	delete jugadas;
}

Elemento* Partida::getCampo()
{
	return campo;
}

Lista<Jugada>* Partida::getJugadas()
{
	return jugadas;
}

void Partida::toSringCampo()
{
	campo->toString();
}

string Partida::toStringJudadas()
{
	return jugadas->toString();
}
static int n = 1;
int Partida::generarNumero()
{
	return n++;
}



ostream& operator<<(ostream& out, Partida& j)
{
	//x << "|                 LISTA VACIA                   |" << endl;
	out << "| "<<j.numero<<". "<<"Partida: " <<"00" <<j.numero<<"                               |";
	return out;
}

bool Partida::ingresarJugada(int i, int j, int n)
{
	if (this->campo->insertar(i, j, n)) {
		this->jugadas->insertarF(new Jugada(i, j));
		return true;
	}
	return false;
}

void Partida::guardarJugadas(ofstream& out)
{
	Nodo<Jugada>* actual = jugadas->getPrimero();
	int cant = jugadas->getCantidad();
	out << cant << "\t";
	while (actual != NULL) {
		actual->getObj()->guardar(out);
		actual = actual->getSig();
	}
	out << "\n";
}

void Partida::recuperarJugadas(ifstream& in)
{
	string cant1;
	getline(in, cant1, '\t');
	int cant = atoi(cant1.c_str());
	for (int i = 0; i < cant; i++) {
		Jugada j1;
		j1.leer(in);
		jugadas->insertarF(new Jugada(j1.getI(), j1.getJ()));
	}
	string salto;
	getline(in, salto);
}
