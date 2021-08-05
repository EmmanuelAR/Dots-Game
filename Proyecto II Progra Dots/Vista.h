#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include<sstream>
using namespace std;

#include"Consola.h"
#include"Excepcion.h"
#include"EmpresaDots.h"
#include"Persona.h"
#include"Persona_Persona.h"
#include"Persona_Maquina.h"
#include"Partida.h"
#include"Integrador.h"
#include"EstrategiaPadre.h"
#include"EstrategiaAleatoria.h"
#include"EstrategiaPeriferica.h"
#include"EstrategiaInteligente.h"
#include"EstrategiaCercana.h"
#include"EstrategiaIslas.h"
#include"EstrategiaCentral.h"
class Vista {
public:
	static void presentacion();
	static void fin();
	static int menuPrincipal();
	static int menuPartidas();
	static int menuSubscriptor();
	//
	static Jugador* esSubscritor(EmpresaDots* e);
	static Partida* crearPartida(EmpresaDots* e);
	static void imprimir(string s);
	static void sleeP(int t);
	static void subscribirse(EmpresaDots* e);
	static bool validarCodigo(Jugador* j, EmpresaDots* e);
	static int escogerTipoDePartida();
	static Partida* partidaPersona_Persona(EmpresaDots* e);
	static Partida* partidaPersona_Maquina(EmpresaDots* e);
	static Jugador* escogerSubscriptor(EmpresaDots* e, int num);
	static void escogerCampo(Partida* p);
	static void jugarPP(Partida* partida, EmpresaDots* e);
	static void jugarPM(Partida* partida, EmpresaDots* e);
	static void mostrarSubs(EmpresaDots* e);
	static void miniDots();
	static void datosJugador(int n,Jugador* );     //cambiando...
	static void guardarPartida(Partida* partida, EmpresaDots* e);
	static void mostrarPartidasGuardadas(EmpresaDots* e);
	static void recrearPartida(EmpresaDots* e);
	static void systemPause();
	static EstrategiaPadre* menuEstrategia(Partida* partida = NULL, Jugada* = NULL, bool = false);
	static void partidaFinalizada();
	static void pausa();
	
};

