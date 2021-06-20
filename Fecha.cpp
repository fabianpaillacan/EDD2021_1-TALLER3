#include "Fecha.h"
#include <iostream>
#include <string.h>
using namespace std;

Fecha::Fecha(){
  this->dia=01;
  this->mes=01;
  this->anio=1900;
}
  bool Fecha::validarFecha(string stringFecha){

  }
  Fecha::~Fecha(){

  }
  int Fecha::getdia(){
    return this->dia;
  }
   int Fecha::getmes(){
    return this->mes;
  }

  int Fecha::getanio(){
    return this->anio;
  }
 
  void Fecha::setdia(int dia){
    this->dia=dia;
  }
  void Fecha::setmes(int mes){
    this->mes=mes;
  }
  void Fecha::setanio(int anio){
    this->anio=anio;
  }
  
  void Fecha::setFecha(string stringFecha){
    
    if (validarFecha(stringFecha)==1){

    }

  }
  //14-septiembre-1969
  int Fecha::extraer_dia(string stringFecha){
     
  int ini, fin,dia;
  string delimitador="-";
  string token;
 
    ini = 0;
    fin =  stringFecha.find(delimitador);
    token =  stringFecha.substr(ini, fin);
    dia= atoi(token.c_str());    
    return dia;              // dato año

  }

   int Fecha::extraer_mes(string stringFecha){
     
  int ini, fin;
  string mes;
  string delimitador="-";
  string nuevoString;
  string token;
  

   
    ini=  stringFecha.find(delimitador);
    nuevoString=stringFecha.substr(ini+1);
    ini=0;
   fin=  nuevoString.find(delimitador);
    mes =  nuevoString.substr(ini, fin);

    cout<<mes;

    /*switch (mes){
      case "enero": return 1; 
      case "febrero": return 1; 
      case "marzo": return 1; 
      case "abril": return 1; 
      case "mayo": return 1; 
      case "junio": return 1; 
      case "julio": return 1; 
      case "agosto": return 1; 
      case "septiembre": return 1; 
      case "octubre": return 1; 
      case "noviembre": return 1; 
      case "diciembre": return 1; 
    }*/



               // dato año
    return 1;
  }

  int Fecha::extraer_anio(string stringFecha){
     
  int ini, fin;
  int anio;
  string delimitador="-";
  string nuevoString;
  string token;
  

   
    ini=  stringFecha.find(delimitador);
    nuevoString=stringFecha.substr(ini+1);
    ini=  nuevoString.find(delimitador)+1;
    fin=ini+4;
    token=  nuevoString.substr(ini, fin);
    anio=atoi(token.c_str());
    return anio;
  }

  string Fecha::ver(){
    return to_string(this->dia)+"/"+to_string(this->mes)+"/"+to_string(this->anio);
  }