#pragma once
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
using namespace std;

class Jugada
{
private:
	int i;
	int j;
public:
	Jugada(int i = 0, int j = 0);
	Jugada(Jugada& j2);
	virtual ~Jugada();
	int getI();
	int getJ();
	string toString();
	friend ostream& operator << (ostream& out, Jugada& j);
	bool operator ==(Jugada&);
	//ARCHIVOS
	void guardar(ofstream& out);
	void leer(ifstream& in);
};

