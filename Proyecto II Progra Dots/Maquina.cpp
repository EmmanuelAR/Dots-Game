#include "Maquina.h"

Maquina::Maquina() :Jugador()
{
	est = NULL;
	estrategiaInicial = "";
	bandera = true;
}

Maquina::~Maquina()
{
}

void Maquina::setEstrategia(EstrategiaPadre* ptr)
{
	if(this->est != NULL){
		delete est;
		est = NULL;
	}
	this->est = ptr;
	if (bandera) {
		estrategiaInicial = typeid(*est).name();
		bandera = false;
	}
}

Jugada* Maquina::ejecutarEstregia(Elemento* a)
{
	return est->retornarJugada(a);

}

EstrategiaPadre* Maquina::getEstrategia()
{
	return est;
}

void Maquina::guardar(ofstream& out)
{
	out << estrategiaInicial << "\t";
}

void Maquina::leer(ifstream& in)
{
	string estra;
	getline(in, estra, '\t');
	if (estra == "class EstrategiaAleatoria") {
		est = new EstrategiaAleatoria();
	}
	if (estra == "class EstrategiaCentral") {
		est = new EstrategiaCentral();
	}
	if (estra == "class EstrategiaCercana") {
		est = new EstrategiaCercana();
	}
	if (estra == "class EstrategiaInteligente") {
		est = new EstrategiaInteligente();
	}
	if (estra == "class EstrategiaIslas") {
		est = new EstrategiaIslas();
	}
	if (estra == "class EstrategiaPeriferica") {
		est = new EstrategiaPeriferica();
	}
}

string Maquina::getEstrategiaInicial()
{
	return estrategiaInicial;
}
