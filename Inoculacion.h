#include <iostream>
#include "Dosis.h"
#include "Fecha.h"
#include "Paciente.h"
#ifndef INOCULACION_H
#define INOCULACION_H

class Inoculacion{

  private:
    Fecha *fechaInoculacion;
    Paciente *paciente;
    Dosis *dosis;

  public:

    Inoculacion (Fecha *fechaInoculacion, Paciente *paciente, Dosis *dosis);
    
    ~Inoculacion();
    Fecha *getfechaInoculacion();
    Paciente *getpaciente();
    Dosis *getdosis();
    string ver();

};
#endif
