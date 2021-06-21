#include "Fecha.h"
#include <iostream>
#include <string.h>
#include  <cstring> 

typedef char cadena[200];
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
    return dia;             

  }

   int Fecha::extraer_mes(string stringFecha){
     
  int ini, fin;
  string mes;
  string delimitador="-";
  string nuevoString;
  string token;

  cadena enero,febrero,marzo,abril, mayo,junio,julio,agosto,septiembre, octubre,noviembre, diciembre;


    strcpy(enero, "enero"); 
    strcpy(febrero, "febrero");
    strcpy(marzo, "marzo");
    strcpy(abril, "abril");
    strcpy(mayo, "mayo");
    strcpy(junio, "junio");
    strcpy(julio, "julio");
    strcpy(agosto, "agosto");
    strcpy(septiembre, "septiembre");
    strcpy(octubre, "octubre");
    strcpy(noviembre, "noviembre");
    strcpy(diciembre, "diciembre");

  char x[100]="";
 
  char *mes1 ;
    ini=  stringFecha.find(delimitador);
    nuevoString=stringFecha.substr(ini+1);
    ini=0;
   fin=  nuevoString.find(delimitador);
    mes =  nuevoString.substr(ini, fin);
    
    mes1=strcpy(x, mes.c_str());

    
    cout<<mes;
    if (strcmp(mes1,enero)==0){
      return 1;
    }
    if (strcmp(mes1,febrero)==0){
      return 2;
    }
    if (strcmp(mes1,marzo)==0){
      return 3;
    }
    if (strcmp(mes1,abril)==0){
      return 4;
    }
    if (strcmp(mes1,mayo)==0){
      return 5;
    }
    if (strcmp(mes1,junio)==0){
      return 6;
    }
    if (strcmp(mes1,julio)==0){
      return 7;
    }
    if (strcmp(mes1,agosto)==0){
      return 8;
    }
    if (strcmp(mes1,septiembre)==0){
      return 9;
    }
    if (strcmp(mes1,octubre)==0){
      return 10;
    }
    if (strcmp(mes1,noviembre)==0){
      return 11;
    }
    if (strcmp(mes1,diciembre)==0){
      return 12;
    }

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