#pragma once
#include<iostream>
#include<string>
#include <sstream>
using namespace std;
#include"Consola.h"

template<class T>
class Nodo {
private:
	T* obj;		//puntero dinamico
	Nodo* sig;	//enlace al otro posible Nodo
public:
	Nodo(T*, Nodo<T>*);		//Constructor de Nodo
	virtual ~Nodo();	//Destructor
	T* getObj();
	Nodo* getSig();		//No me deja retornar Nodo*
	void setObj(T*);
	void setSig(Nodo<T>*);
	
};

template <class T>
class Lista { //Lsta o contenedor generico
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
public:
	Lista();
	~Lista();
	void insertarI(T*);
	void insertarF(T*);
	T* retornarElemento(int lug);
	string toString();
	T* buscar(string);
	T* buscarE(int);
	bool vacia();
	Nodo<T>* getPrimero();
	int getCantidad();
	void limpiar();
	//metodos nuevos
	void iniciarlizarActual();
	void siguienteNodo();
	T* getDato();
	bool contiene(T* );
	void eliminar(T*);
	void operator - (Lista<T>&);
};
//---------------------------------------------------
template<class T>
Nodo<T>::Nodo(T* obj, Nodo<T>* sig) :obj(obj), sig(sig) {}
template<class T>
Nodo<T>::~Nodo() {
	delete obj;
}
template<class T>
T* Nodo<T>::getObj() {
	return obj;
}
//------------PROBLEMA
template<class T>
Nodo<T>* Nodo<T>::getSig() {
	return sig;
}		//No me deja retornar Nodo*
//-----------PROBLEMA
template<class T>
void Nodo<T>::setObj(T* obj) {
	this->obj = obj;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* sig) {
	this->sig = sig;
}
//------------------------------------------------------------------
template<class T>
Lista<T>::Lista() {
	primero = NULL;
	actual = NULL;
}
template<class T>
Lista<T>::~Lista() {
	limpiar();
}
template<class T>
void Lista<T>::insertarI(T* obj) {
	primero = new Nodo<T>(obj, primero);
}
template<class T>
void Lista<T>::insertarF(T* obj) {
	actual = primero;
	if (actual == NULL) {  //lista vacia
		insertarI(obj);
	}
	else { //me envia al final de la lista
		while (actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(new Nodo<T>(obj, NULL));
	}
}
template<class T>
T* Lista<T>::retornarElemento(int lug) {
	actual = primero;
	int cont = 1;
	while (actual != NULL) {
		if (cont == lug) {
			return actual->getObj();
		}
		actual = actual->getSig();
		cont++;
	}
	return NULL;
}
template<class T>
string Lista<T>::toString() {
	stringstream x;
	actual = primero;
	if (primero == NULL) {
		x << "|                 LISTA VACIA                   |" << endl;
	}
	else {
		while (actual != NULL) {
			x << *(actual->getObj()) << endl;
			actual = actual->getSig();
		}
	}
	return x.str();
}
template<class T>

T* Lista<T>::buscar(string identificador)
{
	if (!vacia()) {//esta validacion solo funciona para este juego, ya que si una lista
					//esta vacia deberia saltar una excepcion porque no va a buscar en
					//una lista vacia
		actual = primero;
		while (actual != NULL) {
			if (*actual->getObj() == identificador) {
				return actual->getObj();
			}
			actual = actual->getSig();
		}
	}
	return NULL;
}
template<class T>
T* Lista<T>::buscarE(int identificador)
{
	actual = primero;
	while (actual != NULL) {
		if (*actual->getObj() == identificador) {
			return actual->getObj();
		}
		actual = actual->getSig();
	}
	return NULL;
}
template<class T>
bool Lista<T>::vacia()
{
	return (primero == NULL);
}
template<class T>
inline Nodo<T>* Lista<T>::getPrimero()
{
	return primero;
}
template<class T>
inline int Lista<T>::getCantidad()
{
	actual = primero;
	int cant = 0;
	while (actual != NULL) {
		cant++;
		actual = actual->getSig();
	}
	return cant;
}

template<class T>
inline void Lista<T>::limpiar()
{
	actual = primero;
	Nodo<T>* aux = NULL;
	while (actual != NULL) {
		aux = actual->getSig();
		delete actual;
		actual = aux;
	}
	primero = actual;
}

template <class T>
void Lista<T>::iniciarlizarActual() {
	actual = primero;
}


template <class T>
void Lista<T>::siguienteNodo() {
	actual = actual->getSig();
}

template <class T>
T* Lista<T>::getDato() {
	T* a = actual->getObj();
	return a;
}

template<class T>
inline bool Lista<T>::contiene(T* o)
{
	Nodo<T>* actual = primero;
	while (actual != NULL) {
		if (*actual->getObj() == *o) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
inline void Lista<T>::eliminar(T* x)
{
	Nodo<T>* panterior = NULL;
	Nodo<T>* actual = primero;

	if (primero == NULL)//Si  la lista esta vacia
	{
		return false;
	}

	if (primero->getObj() == x) // si es el primero
	{
		actual = actual->getSig();
		delete (primero);
		primero = actual;
		return true;
	}

	//Si no es el primero, hay que avanzar para buscarlo
	while (actual != NULL && !(actual->getObj() == x)) {
		panterior = actual;
		actual = actual->getSig();
	}

	if (actual == NULL) { return false; }//Si no lo encontro	
	else {// el Nodo fue encontrado
		panterior->setSig(actual->getSig());
		delete actual;
		return true;
	}
	return false;
}

template<class T>
inline void Lista<T>::operator-(Lista<T>& l2)
{
	Nodo<T>* actual = l2.primero;
	while (actual != NULL) {
		if (this->contiene(actual->getObj())) {
			this->eliminar(actual->getObj());
		}
		actual = actual->getSig();
	}
}
