#pragma once
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#include"Lista.h"
class Excepcion{
	public:
		Excepcion(){}
		virtual ~Excepcion(){}
		static int verificarDato(string, int, int);
		static bool verificarPosCampo(bool);
		static void menuPausa(int _i,int _j);


		template<class T>
		static void verificarLista(Lista<T>* l);

};

class ExcepcionRango  {
protected:
	int min;
	int max;
public:
	ExcepcionRango(int, int);
	virtual ~ExcepcionRango(){}
	string toString();
};

class ExcepcionValor  {
public:
	ExcepcionValor(){}
	virtual ~ExcepcionValor(){}
	string toString();
};


class ExcepcionNULLPTR  {
public:
	ExcepcionNULLPTR(){}
	virtual ~ExcepcionNULLPTR(){}
	string toString();

};

class ExcepcionCampoInvalido {
public:
	ExcepcionCampoInvalido() {}
	virtual ~ExcepcionCampoInvalido() {}
	string toString();
};

class ExcepcionMenu {
public:
	ExcepcionMenu() {}
	virtual ~ExcepcionMenu() {}
	//string toString();
};

template<class T>
inline void Excepcion::verificarLista(Lista<T>* l)
{
	if (l->vacia()) {
		throw new ExcepcionNULLPTR();
	}
}
