#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class TipoSimbolo{
public:
 static const int ERROR= -1;
 static const int IDENTIFICADOR= 0;
 static const int OPADIC= 1;
 static const int OPMULT= 2;
 static const int PESOS= 3;
 static const int ENTERO= 4;
 static const int REAL = 5;
};


class Lexico{
      private:
       string fuente;

       int ind;
       bool continua;
       char c;
       int estado;

       char sigCaracter();
       void sigEstado(int estado);
       void aceptacion(int estado);
       bool esLetra(char c);
       bool esDigito(char c);
       bool esEspacio(char c);
       bool esPunto(char c);
       void retroceso();

      public:
       string simbolo;
       string palabra;
       int tipo;

       Lexico(string fuente);
       Lexico();

       void entrada(string fuente);
       string getEntrada();
       string tipoAcad(int tipo);

       void sigSimbolo();
       bool terminado();

};


#endif // LEXICO_H_INCLUDED
