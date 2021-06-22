#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
#include "nodoPaciente.h"
#include "Dosis.h"
#include  "Fecha.h"
#include  "Paciente.h"
#include  "Inoculacion.h"





using namespace std;


int main() {
  Inoculacion *inoculacion;

  Fecha *fecha;
  Dosis *dosis;
  Paciente *paciente;
  paciente=new Paciente ("Maite","Vega","Ortega", "f", "07-enero-1997", "20922297-3");
  fecha=new Fecha();
  dosis=new Dosis("sinovac", 70, 18, 50, 1, 1288238);
  inoculacion=new Inoculacion(fecha, paciente, dosis);

  cout<<inoculacion->ver()<<endl;
  
  cout<<"---------------------"<<endl;
 
  /*Nodo* head= NULL;
  head=new Nodo();
  head->paciente=paciente;
  head->siguiente=NULL;
  cout<<head->paciente->ver();*/
  
  nodoPaciente* head2=NULL;
  agregarNodo(&head2, paciente);
 //cout<<head2->paciente->ver();
   
    Paciente *paciente3;
   paciente3=new Paciente ("ignacio","Vega","Ortega", "f", "03-enero-2005", "20922297-3");
    agregarNodo(&head2, paciente3);
    printList(head2);
    cout<<"\nNodos: "+to_string(contarNodos(head2));

}