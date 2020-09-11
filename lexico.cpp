#include "lexico.h"

#define q0 0
#define q1 1
#define q2 2
#define q3 3
#define q4 4
#define error 5

 Lexico::Lexico(string fuente){
    ind= 0;
    this->fuente= fuente;
    palabra = "";
  }

  Lexico::Lexico(){
    ind= 0;
  }

  string Lexico::tipoAcad(int tipo){
         string cad= "";

         switch (tipo){
           case TipoSimbolo::IDENTIFICADOR:
                cad= "Identificador";
                break;

           case TipoSimbolo::OPADIC:
                cad= "Op. Adicion";
                break;

           case TipoSimbolo::OPMULT:
                cad= "Op. Multiplicacion";
                break;

           case TipoSimbolo::PESOS:
                cad= "Fin de la Entrada";
                break;

           case TipoSimbolo::ENTERO:
                cad= "Entero";
                break;
           case TipoSimbolo::REAL:
                cad= "Real";
                break;
           case TipoSimbolo::ERROR:
            cad = "Error";
            break;

         }

         return cad;
  }

  void Lexico::entrada(string fuente){
       ind= 0;
      this->fuente= fuente;
  }
  string Lexico::getEntrada()
  {
      return fuente;
  }

void Lexico::sigSimbolo(){

    estado=0;
    continua= true;
    simbolo= "";

    //Inicio del Automata
    while (continua){
      c= sigCaracter();

      switch(estado)
      {
        case q0:
            if(esLetra(c)) aceptacion(q1);
            else if(esDigito(c)) sigEstado(q2);
            else sigEstado(error);
        break;
        case q1:
            if(esLetra(c) || esDigito(c)) aceptacion(q1);
            else sigEstado(error);
        break;
        case q2:
            if(esPunto(c)) sigEstado(q3);
            else sigEstado(error);
        break;
        case q3:
            if(esDigito(c)) aceptacion(q4);
            else sigEstado(error);
        break;
        case q4:
            if(esDigito(c)) aceptacion(q4);
            else sigEstado(error);
        break;
        case error:
            sigEstado(error);
            continua = false;
            break;

      }

   }
    //Fin del Automata

      switch (estado){

         case q1:
              tipo= TipoSimbolo::IDENTIFICADOR;
              break;

         case q4:
              tipo = TipoSimbolo::REAL;
              break;
        case error:
              tipo= TipoSimbolo::ERROR;


      }

	//return tipo;
}

 char Lexico::sigCaracter(){
      if (terminado()) return '\0';

      return fuente[ind++];
 }

  void Lexico::sigEstado(int estado){
       this->estado= estado;
       simbolo+= c;
       //palabra+=c;
  }

  void Lexico::aceptacion(int estado){
       sigEstado(estado);
       //cout << "Cadena permitida"<<endl;
       if(ind<fuente.length())
        continua = true;
       else
       continua= false;
  }

  bool Lexico::terminado(){//fin de cadena
         return ind >= fuente.length();
  }

   bool Lexico::esLetra(char c){
        return isalpha(c) || c=='_';
   }


   bool Lexico::esDigito(char c){
        return isdigit(c);
   }

   bool Lexico::esEspacio(char c){
        return c== ' ' || c== '\t' || c == '\0';
   }


   void Lexico::retroceso(){
      if ( c != '$') ind--;
        continua= false;
    }
    bool Lexico::esPunto(char c){
        return c == '.';
    }
