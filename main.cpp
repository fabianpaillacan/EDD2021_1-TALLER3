#include <iostream>
#include "RUN.h"
#include "Dosis.h"
#include "Fecha.h"


using namespace std;
char digito_verificador_rut(unsigned rut);

class Paciente {
  int fecha_nacimiento;
  string RUN;
  string nombre_apellido;

  public:

};


int main() {

  RUN *rut;
  Dosis *prueba;
  Fecha *fecha;
  fecha=new Fecha();
  rut=new RUN();
  prueba=new Dosis("sinovac", 78,19,40,1,12435);

  cout<<fecha->extraer_dia("1-septiembre-1969");
  cout<<fecha->extraer_anio("1-septiembre-1969")<<endl;
  cout<<fecha->extraer_mes("1-septiembre-1969")<<endl;
  /*cout<<prueba->ver();
  prueba->setedadMaxima(90);
  cout<<prueba->ver();

  /*cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-4");
   cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-3");
  cout<<""<<rut->ver()<<endl;
  rut->~RUN();
   cout<<""<<rut->ver()<<endl;
 */
 
}