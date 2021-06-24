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
  Paciente(string nombre,string apellidoPaterno, string apellidoMaterno, string genero);
  ~Paciente();
  int edad();//calcula la edad del paciente
  string getFecha_nacimiento();
  //string getRUN();
  string getnombre_apellido();
  string getrun();
  RUN* getRunObj();
  string getnombre();
  string getapellidoPaterno();
  string getapellidoMaterno();
  string getgenero();
  Fecha* getfechaObj();
  int setRun(string rut);
  int setfecha_nacimiento(string fecha_nacimiento);

  string ver();
 
};
#endif