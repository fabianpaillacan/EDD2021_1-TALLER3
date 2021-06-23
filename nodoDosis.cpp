#include <iostream>
#include "nodoDosis.h"
#include "Dosis.h"

using namespace std;


void agregarNodoDosis(nodoDosis** head_ref, Dosis* dosis){
  nodoDosis* new_node = new nodoDosis();
 
    nodoDosis *last = *head_ref;
    new_node->dosis = dosis;
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
void printList(nodoDosis *node){
  while (node != NULL)
    {
        cout<<" "<<node->dosis->ver()<<endl;
        cout<<"--------------------\n";
        node = node->siguiente;
    }
}
int contarNodos(nodoDosis *node){
    int cont=0;
    while (node!=NULL){
        cont++;
        node=node->siguiente;
    }
    return cont;
}

int obtenerStockMarca(nodoDosis* node, string marca){
  

    while (node!=NULL){
      string marcaNodo=node->dosis-> getVariante_comercial();
      if(marcaNodo.compare(marca)==0){
        return node->dosis->getstock();
      } 
      node=node->siguiente;
    }
    return 0;
}