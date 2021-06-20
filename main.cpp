#include <iostream>
#include "RUN.h"
#include "Dosis.h"

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
  rut=new RUN();
  prueba=new Dosis("sinovac", 78,19,40,1,12435);

  cout<<prueba->ver();
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