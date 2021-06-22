#include <iostream>
#include <time.h>

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
 
}