#include <iostream>
#include "RUN.h"
#include "Dosis.h"
#include "Fecha.h"
#include "Paciente.h";

using namespace std;
char digito_verificador_rut(unsigned rut);



int main() {

  RUN *rut;
  Dosis *prueba;
  Fecha *fecha;
  fecha=new Fecha();
  rut=new RUN();
  prueba=new Dosis("sinovac", 78,19,40,1,12435);

  cout<<fecha->extraer_dia("1-marzo-1969")<<endl;
  cout<<fecha->extraer_anio("1-marzo-1969")<<endl;
  cout<<fecha->extraer_mes("1-marzo-1969")<<endl;
  /*cout<<prueba->ver();
  prueba->setedadMaxima(90);
  cout<<prueba->ver();s

  /*cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-4");
   cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-3");
  cout<<""<<rut->ver()<<endl;
  rut->~RUN();
   cout<<""<<rut->ver()<<endl;
 */
 
}