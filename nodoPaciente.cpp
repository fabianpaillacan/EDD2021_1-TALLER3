#include "nodoPaciente.h"
#include "Paciente.h"
#include <iostream>
#include <string.h>

typedef char cadena[200];

void agregarNodo(nodoPaciente** head_ref, Paciente* paciente){

   
    nodoPaciente* new_node = new nodoPaciente();
 
    nodoPaciente *last = *head_ref;
    new_node->paciente = paciente;
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

void printList(nodoPaciente *node){
{
    while (node != NULL)
    {
        cout<<" "<<node->paciente->ver()<<endl;
        cout<<"--------------------\n";
        node = node->siguiente;
    }
}
    
}

int contarNodos(nodoPaciente *node){
  int cont=0;
    while (node!=NULL){
        cont++;
        node=node->siguiente;
    }
    return cont;
}
