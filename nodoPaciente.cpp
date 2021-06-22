#include "nodoPaciente.h"
#include "Paciente.h"

void agregarNodo(nodoPaciente** head_ref, Paciente* paciente){

    /* 1. allocate nodoPaciente */
    nodoPaciente* new_node = new nodoPaciente();
 
    nodoPaciente *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->paciente = paciente;
 
    /* 3. This new nodoPaciente is going to be
    the last nodoPaciente, so make next of
    it as NULL*/
    new_node->siguiente = NULL;
 
    /* 4. If the Linked List is empty,
    then make the new nodoPaciente as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
  
    /* 5. Else traverse till the last nodoPaciente */
    while (last->siguiente != NULL)
        last = last->siguiente;
 
    /* 6. Change the next of last nodoPaciente */
    last->siguiente = new_node;
    return;
}

void printList(nodoPaciente *node){
{
    while (node != NULL)
    {
        cout<<" "<<node->paciente->ver();
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


















/*Nodo::Nodo(){
    this->paciente=;
}
Nodo::~Nodo(){

}
void Nodo::agregarNodo(){

}
void Nodo::eliminarNodo(){

}
void Nodo::contarNodo(){

}
void Nodo::buscarNodoRut(){

}*/
