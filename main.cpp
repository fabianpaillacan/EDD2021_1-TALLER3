#include <iostream>
#include <time.h>
#include "RUN.h"
#include "Dosis.h"
#include "Fecha.h"
#include "Paciente.h"

using namespace std;
char digito_verificador_rut(unsigned rut);



int main() {

  RUN *rut;
  Dosis *prueba;
  Fecha *fecha;
  fecha=new Fecha(); //instancia = un objeto de alguna clase
  rut=new RUN(); 
  prueba=new Dosis("sinovac", 78,19,40,1,12435);


  cout<<"---------------------"<<endl;
 //codigo para obtener la fecha 
  
  cout<<fecha->ver()<<endl;
  fecha->setFecha("5-febrero-1970");
   cout<<fecha->ver()<<endl;
   fecha->setFecha("36-febrero-1970");
   cout<<fecha->ver()<<endl;
  
 
}