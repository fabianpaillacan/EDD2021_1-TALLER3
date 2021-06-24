#include "Inoculacion.h"
#include "Fecha.h"
#include "Paciente.h"
#include "Dosis.h"

using namespace std;

Inoculacion::Inoculacion (Fecha *fechaInoculacion, Paciente *paciente, Dosis *dosis){
  this->fechaInoculacion=fechaInoculacion;
  this->paciente=paciente;
  this->dosis=dosis;
}
Inoculacion::~Inoculacion(){

}
 Fecha *Inoculacion::getfechaInoculacion(){
   return this->fechaInoculacion;
 } 
 Paciente *Inoculacion::getpaciente(){
   return this->paciente;
 }
 Dosis *Inoculacion::getdosis(){
   return this->dosis;
 }
 string Inoculacion::ver(){
   return "\nFecha Inoculacion: "+this->fechaInoculacion->ver()+"\nInformacion del paciente "+this->paciente->ver()+"\nInformacion Vacuna"+this->dosis->ver();
 }
 
  