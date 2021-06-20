#include <iostream>
#include "RUN.h"

using namespace std;
char digito_verificador_rut(unsigned rut);
class dosis {

  private:
    string variante_comercial;
  int edadMinima;
  int edadMaxima;
  int numeroIdentificador;
  int utilizada;

  public:

};


class Paciente {
  int fecha_nacimiento;
  string RUN;
  string nombre_apellido;

  public:

};


int main() {

  RUN *rut;
  rut=new RUN();

  cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-4");
   cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-3");
  cout<<""<<rut->ver()<<endl;
  rut->~RUN();
   cout<<""<<rut->ver()<<endl;
 
}