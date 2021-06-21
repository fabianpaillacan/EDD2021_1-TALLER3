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
  fecha=new Fecha();
  rut=new RUN(); 
  prueba=new Dosis("sinovac", 78,19,40,1,12435);

  cout<<fecha->extraer_dia("1-marzo-1969")<<endl;
  cout<<fecha->extraer_anio("1-marzo-1969")<<endl;
  cout<<fecha->extraer_mes("1-marzo-1969")<<endl;

  cout<<"---------------------"<<endl;
 //codigo para obtener la fecha 
  string  dS[7] = {"Domingo","Lunes","Martes","Miercoles",

                  "Jueves","Viernes","Sabado"};
   time_t tSac = time(NULL);       // instante actual
   struct tm* tmP = localtime(&tSac);

   cout << "hh:mm:ss " << tmP->tm_hour-4  << ":" << tmP->tm_min << ":"
                       << tmP->tm_sec << endl;
   cout << "dd-mm-aaaa: " << tmP->tm_mday << "-" << tmP->tm_mon+1 << "-"
                          << tmP->tm_year+1900 << endl;
   cout << "Dia de semana: " << dS[tmP->tm_wday] << endl;
   cout << "Dia del año: " << tmP->tm_yday << endl;
   cout << "Horario de verano: " << (tmP->tm_isdst ? "Si" : "No") << endl;
  
  //--------------------------------
  cout<<"--------------"<<endl;
  cout<<fecha->validarFecha(2, 2021, 35); //aqui se valida la fecha


  /*cout<<prueba->ver();
  prueba->setedadMaxima(90);
  cout<<prueba->ver();s

  cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-4");
   cout<<""<<rut->ver()<<endl;
  rut->setRUN("20922297-3");
  cout<<""<<rut->ver()<<endl;
  rut->~RUN();
   cout<<""<<rut->ver()<<endl;
 */
 
}