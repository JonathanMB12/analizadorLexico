#include <cstdlib>
#include <iostream>
#include <cstring>
#include "lexico.h"
#include "pila.h"

int idReglas[2]= { 2, 2};
int lonReglas[2]= {3, 0};

using namespace std;
//tabla ejercicio1
/*
int tablaLR[5][4] = {
        2,0,0,1,
        0,0,-1,0,
        0,3,0,0,
        4,0,0,0,
        0,0,-2,0
};
*/
//tabla ejercicio 2
int tablaLR[5][4] = {
        2,0,0,1,
        0,0,-1,0,
        0,3,-3,0,
        2,0,0,4,
        0,0,-2,0
};
void ejercicio1();
void ejercicio2();
void recursividad(char c);
int main(){

    cout << "Resultado del Analisis Sintactico" << endl << endl;

    //ejercicio1();
    ejercicio2();
    cin.get();

    return 0;
}

void ejercicio1()
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion = false;
    string cadena;
    Lexico lexico;
    lexico.entrada("hola+mundo");

    pila.push(TipoSimbolo::PESOS);
    pila.push(0);
    cout<< lexico.sigSimbolo() << endl;

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];
    pila.muestra();

    while(lexico.simbolo.compare("a") != 0)
    {
        cadena = cadena + lexico.simbolo;
        lexico.sigSimbolo();
    }
    cout << "entrada: " << cadena + lexico.simbolo<<endl;
    cout << "accion: " << accion <<endl;



    pila.push(lexico.tipo);
    pila.push(accion);

    pila.muestra();
    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    cout << "entrada: " <<lexico.simbolo<<endl;
    cout << "accion: "<<accion<<endl;

    pila.push(lexico.tipo);
    pila.push(accion);

    pila.muestra();

    lexico.sigSimbolo();

    cadena = "";
    while(lexico.simbolo.compare("o")!=0)
    {
        cadena = cadena + lexico.simbolo;
        lexico.sigSimbolo();
    }
    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    cout << "entrada: " << cadena + lexico.simbolo<<endl;
    cout << "accion: " << accion <<endl;

    pila.push(lexico.tipo);
    pila.push(accion);

    pila.muestra();

    lexico.sigSimbolo();

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];

    cout << "entrada: " << lexico.simbolo<<endl;
    cout << "accion: " << accion <<endl;

    pila.pop();
    pila.pop();
    pila.pop();

    fila = pila.top();
    columna = 2;
    accion = tablaLR[fila][columna];

    pila.push( 2 ); //el 2 es el entero que representa el no terminal E
    pila.push( accion );
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    aceptacion= accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;


}

void ejercicio2()
{
    Pila pila;
    int fila, columna, accion;
    bool aceptacion = false;
    string cadena;
    char c;
    Lexico lexico;
    lexico.entrada("a+b+c+d+e+f");

    pila.push(TipoSimbolo::PESOS);
    pila.push(0);

    while(!lexico.terminado())
    {
        cout<< lexico.sigSimbolo() << endl;

        fila = pila.top();
        columna = lexico.tipo;
        accion = tablaLR[fila][columna];

        if(accion > 0){

        pila.push(lexico.tipo);
        pila.push(accion);

        pila.muestra();

        cout << "entrada: " << lexico.simbolo << endl;
        cout << "accion: " << accion << endl << endl;

        }
        else if (accion < 0)
        {

            break;
        }

    }
    cout<< lexico.sigSimbolo() << endl;

    fila = pila.top();
    columna = lexico.tipo;
    accion = tablaLR[fila][columna];
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    pila.pop();
    pila.pop();
    pila.pop();

    fila = pila.top();
    columna = 2;
    accion = tablaLR[fila][columna];

    pila.push( 2 ); //el 2 es el entero que representa el no terminal E
    pila.push( accion );
    pila.muestra();
    cout << "entrada: " << lexico.simbolo << endl;
    cout << "accion: " << accion << endl << endl;

    aceptacion= accion == -1;
    if (aceptacion) cout << "aceptacion" << endl;
    else cout <<"No terminal" <<endl;

}


