#include <iostream>
#ifndef NODOINOCULACION_H
#define NODOINOCULACION_H
#include "Inoculacion.h"
using namespace std;

 class nodoInoculacion{
  public:
  Inoculacion *inoculacion;

  nodoInoculacion* siguiente;
  
};

void agregarNodoInoculacion(nodoInoculacion** head_ref, Inoculacion* inoculacion);
int buscarRut(nodoInoculacion* node, string run);
void printList(nodoInoculacion *node);
int  contarNodos(nodoInoculacion *node);
void buscarNodo(nodoInoculacion* node);
int contarDosisUsadas(nodoInoculacion* node, string marca);

#endif