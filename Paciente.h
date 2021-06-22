#include <iostream> 
#include "Fecha.h"
#include "RUN.h"
#ifndef PACIENTE_H
#define PACIENTE_H


using namespace std;

class Paciente {
  private: 
  Fecha *fecha_nacimiento;
  RUN *run;
  string nombre;
  string apellidoPaterno;
  string apellidoMaterno;
  string genero;

  public:
  Paciente(string nombre,string apellidoPaterno, string apellidoMaterno, string genero, string fecha_nacimiento, string run);
  ~Paciente();
  int edad();//calcula la edad del paciente
  string getFecha_nacimiento();
  //string getRUN();
  string getnombre_apellido();
  string getrun();
  string getnombre();
  string getapellidoPaterno();
  string getapellidoMaterno();
  string getgenero();
  string ver();
  


};
#endif