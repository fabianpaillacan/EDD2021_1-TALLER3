#include <iostream>
#include "nodoInoculacion.h"
#include "Paciente.h"


void agregarNodoInoculacion(nodoInoculacion** head_ref, Inoculacion* inoculacion){
  nodoInoculacion* new_node = new nodoInoculacion();
 
    nodoInoculacion *last = *head_ref;
    new_node->inoculacion = inoculacion;
    new_node->siguiente = NULL;
 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
  
    while (last->siguiente != NULL)
      
      last = last->siguiente;
      last->siguiente = new_node;
   
    return;
}
void printList(nodoInoculacion *node){
  while (node != NULL)
    {
        cout<<" "<<node->inoculacion->ver()<<endl;
        cout<<"--------------------\n";
        node = node->siguiente;
    }
}
int contarNodos(nodoInoculacion *node){
    int cont=0;
    while (node!=NULL){
        cont++;
        node=node->siguiente;
    }
    return cont;
}
int buscarRut(nodoInoculacion* node, string run){
   while (node != NULL)
    {
        if (run==node->inoculacion->getpaciente()->getrun()){
          return 1;
        }
        
        node = node->siguiente;
    }
    return 0;
}
int contarDosisUsadas(nodoInoculacion* node, string marca){
  

  int cont=0;
    while (node!=NULL){
      string marcaNodo=node->inoculacion->getdosis() -> getVariante_comercial();
      if(marcaNodo.compare(marca)==0){
        cont++; 
      } 
      node=node->siguiente;
    }
    return cont;
}


