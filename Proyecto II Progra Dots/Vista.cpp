#include "Vista.h"

void Vista::presentacion()
{
    string p;
   // int tam = 0;
    Consola::inicializarColor();
    p += " ____________________________________________\n" ;//1
    p += "|                                            |\n";//2
    p += "|   ||||||   ||||  |||||||||||    ||||       |\n";//3
    p += "|   ||  ||| ||  ||     |||     |||    ||     |\n";//4
    p += "|   ||  ||| ||  ||     |||     |||           |\n";//5
    p += "|   ||  ||| ||  ||     |||     |||           |\n";//6
    p += "|   ||  ||| ||  ||     |||     ||||||||      |\n";//7
    p += "|   ||  ||| ||  ||     |||           |||     |\n";//8
    p += "|   ||  ||| ||  ||     |||           |||     |\n";//9
    p += "|   ||  ||| ||  ||     |||     ||    |||     |\n";//10
    p += "|   ||||||   ||||      |||       ||||     || |\n";//11
    p += "|____________________________________________|\n";//12
    Consola::textColor(6);
    for (int i = 0; i < size(p); i++) {
        cout << p[i];
        Sleep(1);
    }
    cout << "               By DotsCompany" << endl;
    Consola::textColor(15);
    Sleep(5000);
}

void Vista::fin()
{
    system("cls");
    Consola::textColor(6);
    cout << " ______________________________________________" << endl;
    cout << "|       GRACIAS POR UTILIZAR EL JUEGO DOTS     |" << endl;
    cout << "| CREADORES:                                   |"<<endl;
    cout << "|  => Emmanuel Aguero                          |" << endl;
    cout << "|  => Johan Blanco                             |" << endl;
    cout << "|______________________________________________|" << endl;
    Consola::textColor(15);
  
}

int Vista::menuPrincipal()
{
    int opcion;
    string p;
    system("cls");
    p += " _______________________________________________\n";
    p += "|                MENU PRINCIPAL                 |\n";
    p += "|_______________________________________________|\n";
    p += "| 1) MENU SUBSCRIPTOR                           |\n";
    p += "| 2) MENU PARTIDAS                              |\n";
    p += "| 3) SALIR                                      |\n";
    p += "|_______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    opcion = Excepcion::verificarDato("Opcion: ", 1, 3);
    return opcion;
}

int Vista::menuSubscriptor()
{
    int opcion;
    string p;
    system("cls");
    p += " _______________________________________________\n";
    p += "|              MENU SUBCRIPTOR                  |\n";
    p += "|_______________________________________________|\n";
    p += "| 1) SUBSCRIBIRSE A LA EMPRESA                  |\n";
    p += "| 2) MOSTRAR SUBSCRIPTORES Y CODIGO DEL DIA     |\n";
    p += "| 3) CAMBIO DE DIA                              |\n";
    p += "| 4) VOLVER AL MENU PRINCIPAL                   |\n";
    p += "|_______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    opcion = Excepcion::verificarDato("Opcion: ", 1, 4);
    return opcion;
}

int Vista::menuPartidas()
{
    int opcion;
    string p;
    system("cls");
    p += " _______________________________________________\n";
    p += "|                MENU PARTIDAS                  |\n";
    p += "|_______________________________________________|\n";
    p += "| 1) CREAR UNA PARTIDA                          |\n";
    p += "| 2) VER PARTIDAS GUARDADAS                     |\n";
    p += "| 3) RECREAR UNA PARTIDA                        |\n";
    p += "| 4) VOLVER AL MENU PRINCIPAL                   |\n";
    p += "|_______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    opcion = Excepcion::verificarDato("Opcion: ", 1, 4);
    return opcion;
}


Jugador* Vista::esSubscritor(EmpresaDots* e)
{
    system("cls");
    string p;

    Jugador* j = NULL;
    p += " _______________________________________________\n";
    p += "|   INGRESO DE CREDENCIALES DEL SUBSCRIPTOR     |\n";
    p += "|_______________________________________________|\n";
    p += "| NOTA: PARA CREAR UNA PARTIDA DEBE ESTAR       |\n";
    p += "| SUBSCRITO A LA EMPRESA DOTS                   |\n";
    p += "| - POR FAVOR DIGITE SU CEDULA PARA             |\n";
    p += "| IDENTIFICARLO COMO SUBSCRIPTOR                |\n";
    p += "|_______________________________________________|\n";

    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    string cedula;
    cout << "Cedula: "; getline(cin, cedula);
    j = e->getJugadores()->buscar(cedula);
    if (j) {
        Consola::textColor(2);
        cout << "\n<<< LA PERSONA CON CEDULA " << cedula << ", ESTA SUBSCRITO >>>" << endl;
        Consola::textColor(15);
        Sleep(2000);
        return j;
    }
    Consola::textColor(4);
    cout << "\n<<< LA PERSONA CON CEDULA " << cedula << ", NO ESTA SUBSCRITO >>>" << endl;
    Consola::textColor(6);
    cout << "<<< DEBE SUBSCRIBIRSE PARA CREAR UNA PARTIDA >>>" << endl;
    Consola::textColor(15);
    Sleep(5000);
    return j;

}


void Vista::imprimir(string s)
{
    cout << s;
}

void Vista::sleeP(int t)
{
    Sleep(t);
}

void Vista::subscribirse(EmpresaDots* e)
{
    system("cls");
    string p;
   
    string cedula, nombre;
    Jugador* subscriptor = NULL;
    bool s;
    p += " _______________________________________________\n";
    p += "|         SUBSCRIPCION A LA EMPRESA DOTS        |\n";
    p += "|_______________________________________________|\n";
    p += "| NOTA: PARA SUBSCRIBIRSE DEBE PAGAR UNA MODICA |\n";
    p += "| SUMA DE 500 COLONES, DESEA PAGAR?             |\n";
    p += "|             SI => 1     NO =>  0              |\n";
    p += "|_______________________________________________|\n";

    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    s = Excepcion::verificarDato("Decision: ", 0, 1);
    if (s) {
        Consola::textColor(2);
        cout << "<<< PAGADO EXITOSAMENTE >>>" << endl;
        Sleep(1000);
        system("cls");
        p = " _______________________________________________\n";
        p += "|   INGRESO DE CREDENCIALES DEL SUBSCRIPTOR     |\n";
        p += "|_______________________________________________|\n";
        p += "|   AHORA SE LE SOLICITARA SU NOMBRE Y CEDULA   |\n";
        p += "|_______________________________________________|\n";
       
        for (int i = 0; i < size(p); i++) {
            (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
            cout << p[i];
        }
        cout << "Cedula: "; getline(cin, cedula);
        cout << "Nombre: "; getline(cin, nombre);
        subscriptor = new Persona(nombre, cedula);
        subscriptor->setCoins(500);
        e->attach(subscriptor);
        Consola::textColor(2);
        cout << "<<< PERSONA SUBSCRITA CON EXITO!!! >>>" << endl;
        Sleep(1000);
    }
    else {
        Consola::textColor(4);
        cout << "<<< PERSONA NO SUBSCRITA >>>" << endl;
        Sleep(1000);
    }

}
 
bool Vista::validarCodigo(Jugador* j, EmpresaDots* e)
{
    system("cls");
    string p, codigo;
  
    p += " _______________________________________________\n";
    p += "|     CODIGO DEL DIA: " + e->getCodigo() + "                    |\n";
    p += "|_______________________________________________|\n";
    p += "| NOTA: SI USTED ES SUBSCRIPTOR DEBE TENER      |\n";
    p += "| ASIGNADO EL MISMO CODIGO, POR FAVOR INGRESELO |\n";
    p += "|_______________________________________________|\n";

    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    cout << "Codigo: "; getline(cin, codigo);
    if (e->getCodigo() == codigo && codigo == j->getCodigo()) {
        Consola::textColor(2);
        cout << "\n<<< CODIGO VALIDO!!! >>>" << endl;
        Sleep(2000);
        return true;
    }
    else {
        Consola::textColor(4);
        cout << "\n<<< CODIGO IVALIDO!!! >>>" << endl;
        Consola::textColor(15);
        cout << "El codigo ingresado es: " << codigo << endl;
        cout << "El codigo del dia es: " << e->getCodigo() << endl;
        cout << "El codigo del que se le asigno es: " << j->getCodigo() << endl;
        Sleep(5000);
    }
    return false;
}

int Vista::escogerTipoDePartida()
{
    int opcion;
    string p;

    system("cls");
    p += " _______________________________________________\n";
    p += "|              TIPO DE PARTIDA                 |\n";
    p += "|_______________________________________________|\n";
    p += "| 1) PERSONA-PERSONA                            |\n";
    p += "| 2) PERSONA-MAQUINA                            |\n";
    p += "|_______________________________________________|\n";

    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    opcion = Excepcion::verificarDato("Opcion: ",1,2);
    return opcion;
}



Partida* Vista::crearPartida(EmpresaDots* e)
{
    Jugador* j = esSubscritor(e);
    string p, codigo;
    int tam = 0;
    int tipoP = 0;
    Partida* partida = NULL;
    if (j) {
        if (validarCodigo(j,e)) {
            tipoP = escogerTipoDePartida();
            if (tipoP == 1) {
                partida = partidaPersona_Persona(e);
            }
            else {
                partida = partidaPersona_Maquina(e);
            }
        }
    }
    //validar que haya minimo 2 jugadores para poder jugar y que no sea el mimo jugador
    return partida;
}
Partida* Vista::partidaPersona_Persona(EmpresaDots* e)
{
    
    Jugador* j1 = NULL;
    Jugador* j2 = NULL;
    int num = 1;
    Elemento* campo = NULL;
    Partida* partida = NULL;
    if (e->getJugadores()->getCantidad() >= 2) {
        do {
            j1 = escogerSubscriptor(e,num++);
            j2 = escogerSubscriptor(e,num++);
            if (j1 == j2) {
                Consola::textColor(4);
                cout << "\n<<< LOS JUGADORES NO PUEDEN SER LOS MISMOS, POR FAVOR ESCOJA DOS JUGADORES DE NUEVO >>>" << endl;
                Consola::textColor(15);
                system("pause");
                num = 1;
            }
        } while (j1 == j2);
        j1->setNumero(1);
        j2->setNumero(2);
        //PROBANDO HASTA AQUI......
        partida = new Persona_Persona(new Persona(*(Persona*)j1), new Persona(*(Persona*)j2));
    }
    else {
        Consola::textColor(4);
        cout << "\n<<< NO HAY SUFICIENTES SUBSCRIPTORES PARA JUGAR >>>" << endl;
        Consola::textColor(15);
        system("pause");
    }
    return partida;
}

Partida* Vista::partidaPersona_Maquina(EmpresaDots* e)
{
    Jugador* j1 = NULL;
    int num = 1;
    Elemento* campo = NULL;
    Partida* partida = NULL;
    if (e->getJugadores()->getCantidad() >= 1) {
        j1 = escogerSubscriptor(e, num++);
        j1->setNumero(1);
        partida = new Persona_Maquina(new Persona(*(Persona*)j1));
    }
    else {
        Consola::textColor(4);
        cout << "\n<<< NO HAY SUFICIENTES SUBSCRIPTORES PARA JUGAR >>>" << endl;
        Consola::textColor(15);
        system("pause");
    }
    return partida;
}

Jugador* Vista::escogerSubscriptor(EmpresaDots* e, int num)
{
    string p, codigo,cedula;

    system("cls");
    p = e->toStringSubscribtores();
    p += "|          ESCOJA UN JUGADOR POR CEDULA         |\n";
    p += "|_______________________________________________|\n";

    Jugador* j = NULL;
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    do {
        cout << "Cedula Jugador "<<num<<": "; getline(cin, cedula);
        j = e->getJugadores()->buscar(cedula);
        if (!j) {
            Consola::textColor(4);
            cout << "<<< SUBSCRIPTOR NO EXISTENTE >>>" << endl;
            Consola::textColor(15);
        }
    } while (!j);
    return j;
}

void Vista::escogerCampo(Partida* partida)
{
    string z = "";
    bool escoger = true;
    string opcion;
    string combinacion;
    string p;
    int cont = 0;
    do {
        system("cls");
        p += " _______________________________________________\n";
        p += "|    ESCOJA UNO O VARIOS CAMPOS PARA ARMAR SU   |\n";
        p += "|    CAMPO DE JUEGO RESULTANTE                  |\n";
        p += "|_______________________________________________|\n";
        p += "|          o o       o o o        o o o         |\n";
        p += "|          o o       o o o        o o o         |\n";
        p += "|          o o       o o o        o o o         |\n";
        p += "|                                 o o o         |\n";
        p += "|                                 o o o         |\n";
        p += "|           X          Y            Z           |\n";
        p += "|_______________________________________________|\n";
        p += "Combinacion: " + combinacion + "\n";

        for (int i = 0; i < size(p); i++) {
            (p[i] == '_' || p[i] == '|' || p[i] == 'X' || p[i] == 'Y' || p[i] == 'Z') ? Consola::textColor(3) : Consola::textColor(15);
            cout << p[i];
        }
        cout << "Opcion: "; getline(cin, opcion);
        if (opcion == "X") {
            p = "";
            combinacion += opcion;
            p += " _______________________________________________\n";
            p += "|           DESEA ESCOGER OTRO CAMPO?           |\n";
            p += "|             SI => 1     NO => 0               |\n";
            p += "|_______________________________________________|\n";

            for (int i = 0; i < size(p); i++) {
                (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
                cout << p[i];
            }
            escoger = Excepcion::verificarDato("Decision: ", 0, 1);
            p = "";
            partida->getCampo()->agregar(new SeisPuntos());
            p = "";
        }
        else if (opcion == "Y") {
            p = "";
            combinacion += opcion;
            p += " _______________________________________________\n";
            p += "|           DESEA ESCOGER OTRO CAMPO?           |\n";
            p += "|             SI => 1     NO => 0               |\n";
            p += "|_______________________________________________|\n";

            for (int i = 0; i < size(p); i++) {
                (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
                cout << p[i];
            }
            escoger = Excepcion::verificarDato("Decision: ", 0, 1);
            p = "";
            partida->getCampo()->agregar(new NuevePuntos());
            p += "";
        }
        else if (opcion == "Z") {
            p = "";
            combinacion += opcion;
            p += " _______________________________________________\n";
            p += "|           DESEA ESCOGER OTRO CAMPO?           |\n";
            p += "|             SI => 1     NO => 0               |\n";
            p += "|_______________________________________________|\n";

            for (int i = 0; i < size(p); i++) {
                (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
                cout << p[i];
            }
            escoger = Excepcion::verificarDato("Decision: ", 0, 1);
            p = "";
            partida->getCampo()->agregar(new QuincePuntos());
            p += "";
        }
        else {
            p = "";
            Consola::textColor(4);
            cout << "\n<<< OPCION NO VALIDA >>>" << endl;
            Consola::textColor(15);
            Sleep(1000);
            escoger = true;
        }
        cont++;
    } while (escoger&&cont<10);
    if (cont == 10) { 
        Consola::textColor(6);
        cout << "<<< EL MAXIMO PERMITIDO DE COMBINACIONES ES 10 >>>";
        Consola::textColor(15);
        Sleep(2000);
    }
    partida->getCampo()->crearMatriz();
    Consola::textColor(2);
    cout << "\n<<< MATRIZ CREADA CON EXITO >>>" << endl;
    Consola::textColor(15);
    Sleep(1000);
}


void Vista::mostrarSubs(EmpresaDots* e)
{
    string p;

    system("cls");
    p = e->toStringSubscribtores();
    p += "CODIGO DEL DIA: " + e->getCodigo()+'\n';
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    system("pause");
}


void Vista::miniDots()
{
    system("cls");
    string p;
    p += " ______________________________________________\n";
    p += "|                   DOTS                       |\n";
    p += "|______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(6) : Consola::textColor(15);
        cout << p[i];
    }
    Consola::textColor(15);
}

void Vista::datosJugador(int n, Jugador* j)
{
    string p;
    p += "==> Jugador #" + to_string(n) + " : "+j->getNombre();
    //poner el nombre de la estrategia
    (dynamic_cast<Maquina*>(j)) ? p += " : " + j->getEstrategia()->getNombre() + '\n' : p += '\n';
    for (int i = 0; i < size(p); i++) {
        if (p[i] =='=' || p[i] == '>') {
            (n==1)?Consola::textColor(3) : Consola::textColor(12);
        }
        else {
            Consola::textColor(15);
        }
        cout << p[i];
    }
    Consola::textColor(15);
}
void Vista::jugarPP(Partida* partida, EmpresaDots* e)
{

    Elemento* campo = partida->getCampo();
    //
    int x, y;
    int n = 1;
    while (!campo->lleno()) {
        miniDots();
        cout << endl;
        (n == 1) ? datosJugador(n, partida->getJugador1()) : datosJugador(n, partida->getJugador2()); // hay que hacer el getJugador()
        campo->toString();
        cout << "\n\n";
        cout << "PAUSA: [I]->0 , [J]->0" << endl;
        x = Excepcion::verificarDato("[I] = ", 0, campo->getTamFila() - 1);
        y = Excepcion::verificarDato("[J] = ", 0, campo->getTamColumna() - 1);
        try {
            Excepcion::menuPausa(x, y);
        }
        catch (ExcepcionMenu *) {
            system("cls");
            pausa();
            system("pause");
        }
       
        if (Excepcion::verificarPosCampo(partida->ingresarJugada(x, y,n))) {
            if (!(x==0&&y==0)) {
                if (!campo->insertarNumero(n)) {
                    n++;
                }
            }
        }
        if (n == 3) { n = 1; }
    }
   // cout << "Jugador #" << n << endl;
    system("cls");
    miniDots();
    cout << endl;
    partidaFinalizada();
    campo->toString();
    cout << "\n\n";
    int ganador = campo->ganador();
    if (ganador == 1) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        cout << partida->getJugador1()->getNombre() << endl;
        

    }
    else if (ganador == 2) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        cout << partida->getJugador2()->getNombre() << endl;
    }
    else {
        Consola::textColor(10);
        cout << "EMPATE!!!: " << endl;
        Consola::textColor(15);
    }
    system("pause");
    guardarPartida(partida, e);
    cout << endl;
}

void Vista::jugarPM(Partida* partida, EmpresaDots* e)
{
   
    Jugador* maquina = partida->getMaquina();
    maquina->setEstrategia(menuEstrategia(partida,NULL,false));
    Elemento* campo = partida->getCampo();
    partida->getMaquina()->getEstrategia()->setCampo(campo);//NUEVO
    Jugada* maquinaRespuesta = NULL;
    //
    int x, y;
    int n = 1;
    bool bandera = true;
    while (!campo->lleno()) {
        miniDots();
        cout << endl;
        (n == 1) ? datosJugador(n, partida->getJugador1()) : datosJugador(n, partida->getMaquina());
        campo->toString();
        cout << "\n\n";
        cout << "CAMBIAR ESTRATEGIA: [I]->0 , [J]->0" << endl;
        if (n == 2) {
            maquinaRespuesta = maquina->ejecutarEstregia(campo);
            //partida->getMaquina()->getEstrategia()->setUltimaJugada(maquinaRespuesta);                      //SET  ULTIMA JUGADA
            x = maquinaRespuesta->getI();
            y = maquinaRespuesta->getJ();
            cout << "[I] = ";
            Sleep(500);
            cout << x;
            cout << endl;
            cout << "[J] = ";
            Sleep(500);
            cout << y;
            cout << endl;
            Sleep(2000);
            //nuevo 08-06

            if (dynamic_cast<EstrategiaIslas*> (partida->getMaquina()->getEstrategia())) {

                partida->getMaquina()->getEstrategia()->setUltimaJugada(new Jugada(x, y));
            }



        }
        else {
            x = Excepcion::verificarDato("[I] = ", 0, campo->getTamFila() - 1);

            y = Excepcion::verificarDato("[J] = ", 0, campo->getTamColumna() - 1);

            if (x != 0 && y != 0) { 
                if (! (dynamic_cast<EstrategiaIslas*> (partida->getMaquina()->getEstrategia()) )) {
                    partida->getMaquina()->getEstrategia()->setUltimaJugada(new Jugada(x, y));
                }
            }
        }

        try {
            Excepcion::menuPausa(x, y);
        }
        catch (ExcepcionMenu *) {
            system("cls");
            partida->getJugadas()->insertarF(new Jugada(0, 0));
            maquina->setEstrategia(menuEstrategia(partida, NULL, false));
            bandera = false;
        }
        if (bandera) {//NUEVO
            if (Excepcion::verificarPosCampo(partida->ingresarJugada(x, y, n))) {
                if (!(x == 0 && y == 0)) {

                    //nuevo 08-06
                    if (dynamic_cast<EstrategiaCercana*> (partida->getMaquina()->getEstrategia())) {
                        partida->getMaquina()->getEstrategia()->setUltimaJugada(new Jugada(x, y));
                    }
                    //
                    if (!campo->insertarNumero(n)) {
                        n++;

                    }
                }
            }
            if (n == 3) { n = 1; }
        }
        bandera = true;
    }
    // cout << "Jugador #" << n << endl;
    system("cls");
    miniDots();
    cout << endl;
    partidaFinalizada();
    campo->toString();
    cout << "\n\n";
    int ganador = campo->ganador();
    if (ganador == 1) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        cout << partida->getJugador1()->getNombre() << endl;


    }
    else if (ganador == 2) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        cout << partida->getMaquina()->getNombre() << endl;
    }
    else {
        Consola::textColor(10);
        cout << "EMPATE!!!: " << endl;
        Consola::textColor(15);
    }
    system("pause");
    guardarPartida(partida, e);
    cout << endl;
}

void Vista::guardarPartida(Partida* partida, EmpresaDots* e)
{
    system("cls");
    string p;
    bool s = true;
    p += " _______________________________________________\n";
    p += "|              PARTIDA FINALIZADA               |\n";
    p += "|_______________________________________________|\n";
    p += "|           DESEA GUARDAR LA PARTIDA?           |\n";
    p += "|             SI => 1     NO => 0               |\n";
    p += "|_______________________________________________|\n";

    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    s = Excepcion::verificarDato("Decision: ", 0, 1);
    if (s) {
        e->getJuego()->getPartidas()->insertarF(partida);

        partida->guardar();//NUEVO................

        Consola::textColor(10);
        cout << "\n<<< PARTIDA GUARDADA CON EXITO >>>" << endl;
        Consola::textColor(15);
    }
    else {
        delete partida;
        Consola::textColor(6);
        cout << "\n<<< PARTIDA NO GUARDADA >>>" << endl;
        Consola::textColor(15);
    }
    Sleep(1000);
}

void Vista::mostrarPartidasGuardadas(EmpresaDots* e)
{
    string p;
    system("cls");
    p = e->getJuego()->toStringPartidas();
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    system("pause");
}

void Vista::recrearPartida(EmpresaDots* e){
    string p;
    int pos;
    system("cls");
    p = e->getJuego()->toStringPartidas();
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    cout << endl;
    Excepcion::verificarLista(e->getJuego()->getPartidas());
    pos = Excepcion::verificarDato("Ingrese la posicion de la partida a recrear: ", 1, e->getJuego()->getPartidas()->getCantidad());
    Partida* partidaAux = e->getJuego()->getPartidas()->retornarElemento(pos);
    
    if (dynamic_cast<Persona_Maquina*>(partidaAux)) {
        string estra = partidaAux->getMaquina()->getEstrategiaInicial();
        if (estra == "class EstrategiaAleatoria") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaAleatoria());
        }
        if (estra == "class EstrategiaCentral") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaCentral());
        }
        if (estra == "class EstrategiaCercana") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaCercana());
        }
        if (estra == "class EstrategiaInteligente") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaInteligente());
            
        }
        if (estra == "class EstrategiaIslas") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaIslas());
        }
        if (estra == "class EstrategiaPeriferica") {
            partidaAux->getMaquina()->setEstrategia(new EstrategiaPeriferica());
        }
   }


    Lista<Jugada>* jugadasAux = partidaAux->getJugadas();
    Elemento* campo = new CampoJuego( *(CampoJuego*)   partidaAux->getCampo());
    int x, y;
    int n = 1;
    int contador = 0;
    Jugada* jugadaAux = NULL;
    Nodo<Jugada>* actual = jugadasAux->getPrimero();
        while (actual!=NULL) {
            contador++;
            jugadaAux = actual->getObj();
            miniDots();
            cout << endl;
            if (n == 1) {
                datosJugador(n, partidaAux->getJugador1());
            }
            else if( n==2 && dynamic_cast<Persona_Maquina*>  (partidaAux) ) {
                datosJugador(n, partidaAux->getMaquina());
            }
            else {
                datosJugador(n, partidaAux->getJugador2());
            }
            //(n == 1) ? datosJugador(n, partidaAux->getJugador1()) : datosJugador(n, partidaAux->getJugador2());
            campo->toString();
            cout << "\n\n";
            //
            (dynamic_cast<Persona_Maquina*>(partidaAux)) ? cout << "CAMBIAR ESTRAEGIA: [I]->0 , [J]->0" << endl : cout << "PAUSA: [I]->0 , [J]->0" << endl;
            cout << "[I] = ";
            Sleep(500);
            cout<< jugadaAux->getI();
            cout << endl;
            cout << "[J] = ";
            Sleep(500);
            cout << jugadaAux->getJ();
            cout << endl;
            x = jugadaAux->getI();
            y = jugadaAux->getJ();
            Sleep(2000);
            if (campo->insertar(x, y,n)) {
                if (!(x == 0 && y == 0)) {
                    if (!campo->insertarNumero(n)) {
                        n++;
                    }
                }
                if (x == 0 && y == 0&&dynamic_cast<Persona_Maquina*>(partidaAux)) {
                    actual = actual->getSig();
                    partidaAux->getMaquina()->setEstrategia(menuEstrategia(partidaAux, actual->getObj(), true));
                    Sleep(1000);
                }
                actual = actual->getSig();
            }
            if (n == 3) { n = 1; }
        }
        
    system("cls");
    miniDots();
    cout << endl;
    partidaFinalizada();
    campo->toString();
    cout << "\n\n";
    int ganador = campo->ganador();
    if (ganador == 1) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        cout << partidaAux->getJugador1()->getNombre() << endl;
    }
    else if (ganador == 2) {
        Consola::textColor(10);
        cout << "GANADOR: ";
        Consola::textColor(15);
        if (dynamic_cast<Persona_Maquina*>(partidaAux)) {
            cout << partidaAux->getMaquina()->getNombre() << endl;
        }
        else {
            cout << partidaAux->getJugador2()->getNombre() << endl;
        }
    }
    else {
        Consola::textColor(10);
        cout << "EMPATE!!!: " << endl;
        Consola::textColor(15);
    }
    system("pause");

    delete campo;
}

void Vista::systemPause()
{
    system("pause");
}

EstrategiaPadre* Vista::menuEstrategia(Partida* partida,Jugada* jugada, bool reproduciendo)
{
    int opcion;
    string p;
    EstrategiaPadre* estra = NULL;
    system("cls");
    p += " _______________________________________________\n";
    p += "|                 MENU ESTRATEGIA               |\n";
    p += "|_______________________________________________|\n";
    p += "| ESCOJA LA ESTRATEGIA DE LA MAQUINA            |\n";
    p += "|_______________________________________________|\n";
    p += "| 1) JUEGO ALEATORIO TONTO                      |\n";
    p += "| 2) JUEGO ALETORIO INTELIGENTE                 |\n";
    p += "| 3) JUEGO CERCANO                              |\n";
    p += "| 4) JUEGO PERIFERICO                           |\n";
    p += "| 5) JUEGO CENTRAL                              |\n";
    p += "| 6) JUEGO ISLAS                                |\n";
    p += "|_______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
    if (!reproduciendo) {
        opcion = Excepcion::verificarDato("Opcion: ", 1, 6);
        switch (opcion)
        {
        case 1: { estra = new EstrategiaAleatoria(); }break;
        case 2: { estra = new EstrategiaInteligente(); }break;
        case 3: { estra = new EstrategiaCercana(); }break;
        case 4: { estra = new EstrategiaPeriferica(); }break;
        case 5: { estra = new EstrategiaCentral(); }break;
        case 6: { estra = new EstrategiaIslas(); }break;
 
        default:
            break;
        }
        if (!partida->getJugadas()->vacia()) {
            partida->getJugadas()->insertarF(new Jugada(opcion, 0));
        }
    }
    else {
        cout << "Opcion: ";
        Sleep(500);
        opcion = jugada->getI();
        cout << opcion;
        switch (opcion)
        {
        case 1: { estra = new EstrategiaAleatoria(); }break;
        case 2: { estra = new EstrategiaInteligente(); }break;
        case 3: { estra = new EstrategiaCercana(); }break;
        case 4: { estra = new EstrategiaPeriferica(); }break;
        case 5: { estra = new EstrategiaCentral(); }break;
        case 6: { estra = new EstrategiaIslas(); }break;
        default:
            break;
        }
    }
    return estra;
   
}

void Vista::partidaFinalizada()
{
    string p;
    p += "==> PARTIDA FINALIZADA\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '=' || p[i] == '>')?Consola::textColor(6):Consola::textColor(15);
        cout << p[i];
    }
    Consola::textColor(15);
}

void Vista::pausa()
{
    string p;
    EstrategiaPadre* estra = NULL;
    system("cls");
    p += " _______________________________________________\n";
    p += "|                 MENU PAUSA                    |\n";
    p += "|_______________________________________________|\n";
    p += "|   PRESIONE CUALQUIER TECLA PARA CONTINUAR     |\n";
    p += "|_______________________________________________|\n";
    for (int i = 0; i < size(p); i++) {
        (p[i] == '_' || p[i] == '|') ? Consola::textColor(3) : Consola::textColor(15);
        cout << p[i];
    }
}





