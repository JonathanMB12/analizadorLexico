#include <cstdlib>
#include <iostream>
#include <string>

#include "lexico.h"

using namespace std;

int main(){


    Lexico lexico;
    string cadena;
    cout <<"Dame la cadena para analizar: ";
    getline(cin, cadena);
    lexico.entrada(cadena);

    cout << "Resultado del Analisis Lexico" << endl << endl;
    cout << "Simbolo\t\tTipo" << endl;

    while ( !lexico.terminado() ){
          lexico.sigSimbolo();
            if(lexico.terminado())
            {
                cout <<  lexico.getEntrada() << "\t\t" << lexico.tipoAcad(lexico.tipo) << endl;
            }

    }



    return 0;
}
