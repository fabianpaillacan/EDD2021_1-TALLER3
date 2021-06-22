#include <iostream>
#include <time.h>
#include "Paciente.h"

using namespace std;
char digito_verificador_rut(unsigned rut);



int main() {
  Paciente *paciente;
  paciente=new Paciente ("Maite","Vega","Ortega", "f", "07-enero-1997", "4968692-k");
  cout<<paciente->ver()<<endl;
  
  cout<<"---------------------"<<endl;
 
}