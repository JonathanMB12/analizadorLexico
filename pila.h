#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <list>
#include <iostream>
#include <string>

using namespace std;


class Pila{

   private:
      list <int> lista;

   public:
      void push( int x);
      int top();
      int pop();
      void muestra();

};

#endif // PILA_H_INCLUDED
