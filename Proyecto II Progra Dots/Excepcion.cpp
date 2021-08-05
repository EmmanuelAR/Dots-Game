#include "Excepcion.h"

int Excepcion::verificarDato(string etiqueta, int min, int max)
{
    int n;
    while (true) {
        cout << etiqueta;
        try {
            if (cin >> n) {
                if (n < min || n > max) {
                    cin.clear();
                    cin.ignore(1024, '\n');
                    throw new ExcepcionRango(min, max);
                }
                cin.clear();
                cin.ignore(1024, '\n');
                return n;
            }
            else {
                cin.clear();
                cin.ignore(1024, '\n');
                throw new ExcepcionValor();
            }
        }
        catch (ExcepcionRango * e) {
            cout << e->toString();
            Consola::textColor(15);
        }
        catch (ExcepcionValor * e) {
            cout << e->toString();
            Consola::textColor(15);
        }
    }
    Consola::textColor(15);
}

bool Excepcion::verificarPosCampo(bool a){
    try {
        if (a == false) {
            throw new ExcepcionCampoInvalido();
        }
    }
    catch (ExcepcionCampoInvalido * e) {
        cout << e->toString();
        Sleep(1000);
        Consola::textColor(15);
        return false;
    }
    Consola::textColor(15);
    return true;
    

}

void Excepcion::menuPausa(int i, int j){
    if (i == 0 && j == 0) {
        throw new ExcepcionMenu();
    }
    Consola::textColor(4);
}

ExcepcionRango::ExcepcionRango(int min, int max){
    this->min = min;
    this->max = max;
}

string ExcepcionRango::toString()
{
    Consola::textColor(4);
    return ("<<< RANGO PERMITIDO " + to_string(min) + "-" + to_string(max) + " >>>\n");
}

string ExcepcionValor::toString()
{
    Consola::textColor(4);
    return "<<< DATO INVALIDO >>>\n";
}

string ExcepcionNULLPTR::toString()
{
    Consola::textColor(6);
    return "<<< INGRESE DATOS A LA LISTA PARA REALIZAR LA ACCION >>>\n";
}

string ExcepcionCampoInvalido::toString()
{
    Consola::textColor(4);
    return "<<< POSICION INVALIDA  >>>\n";
}
//
//string ExcepcionMenu::toString()
//{
//    return string();
//}
