#include "Fecha.h"
#include <iostream>
#include <string.h>
#include  <cstring>

typedef char cadena[200];
using namespace std;

Fecha::Fecha() {
  this -> dia = 01;
  this -> mes = 01;
  this -> anio = 1900;
  
}
void Fecha::setFechaActual(){
  this -> dia = getdiaActual();
  this -> mes = getmesActual();
  this -> anio = getanioActual();
}
int Fecha::getdiaActual(){
 
  time_t tSac = time(NULL); 
  struct tm * tmP = localtime(&tSac);

  return tmP -> tm_mday;
  
}

int Fecha::getmesActual(){
  
  time_t tSac = time(NULL); 
  struct tm * tmP = localtime( & tSac);

 
  return tmP -> tm_mon + 1;
 
}

int Fecha::getanioActual(){
 
  time_t tSac = time(NULL);
  struct tm * tmP = localtime( & tSac);

  
  return tmP -> tm_year + 1900;
}

bool Fecha::validarFecha(int dia, int mes, int anio) {

  int mesActual, anioActual, diaActual;
 
  diaActual = getdiaActual();
  mesActual = getmesActual();
  anioActual = getanioActual();

  int dias_mes[] = {31, 28,31,30,31,30,31,31, 30,31,30,31};
  if ((anio % 4 == 0 and anio % 100 != 0) or anio % 400 == 0) {
    dias_mes[1]++;
  }
  if (mes < 1 or mes > 12) {
    return false;
  }
  int mes_idx = mes - 1; //posicion de un indice
  if (dia <= 0 or dia > dias_mes[mes_idx]) {
    return false; // es = 0 
  }
  if (anio > anioActual) {
    return false;

  }
  if (anio == anioActual && mes > mesActual) {
    return false;
  }

  if (anio == anioActual && mes == mesActual && dia > diaActual) {
    return false;
  }
  return true; //es =1 
}
Fecha::~Fecha() {

}
int Fecha::getdia() {
  return this -> dia;
}
int Fecha::getmes() {
  return this -> mes;
}

int Fecha::getanio() {
  return this -> anio;
}

void Fecha::setdia(int dia) {
  this -> dia = dia;
}
void Fecha::setmes(int mes) {
  this -> mes = mes;
}
void Fecha::setanio(int anio) {
  this -> anio = anio;
}

int Fecha::setFecha(string stringFecha) {
    int dia, mes, anio;
    dia=extraer_dia(stringFecha);
    mes=extraer_mes(stringFecha);
    anio=extraer_anio(stringFecha);
  
  if (validarFecha(dia,mes,anio)==1){
        setdia(dia);
        setmes(mes);
        setanio(anio);
        return 1;
    }
  return 0;
}
int Fecha::extraer_dia(string stringFecha) {

  int ini, fin, dia;
  string delimitador = "-";
  string token;

  ini = 0;
  fin = stringFecha.find(delimitador);
  token = stringFecha.substr(ini, fin);
  dia = atoi(token.c_str());
  return dia;

}

int Fecha::extraer_mes(string stringFecha) {

  int ini, fin;
  string mes;
  string delimitador = "-";
  string nuevoString;
  string token;

  cadena enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre;

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

  char x[100] = "";

  char * mes1;
  ini = stringFecha.find(delimitador);
  nuevoString = stringFecha.substr(ini + 1);
  ini = 0;
  fin = nuevoString.find(delimitador);
  mes = nuevoString.substr(ini, fin);

  mes1 = strcpy(x, mes.c_str());

  if (strcmp(mes1, enero) == 0) {
    return 1;
  }
  if (strcmp(mes1, febrero) == 0) {
    return 2;
  }
  if (strcmp(mes1, marzo) == 0) {
    return 3;
  }
  if (strcmp(mes1, abril) == 0) {
    return 4;
  }
  if (strcmp(mes1, mayo) == 0) {
    return 5;
  }
  if (strcmp(mes1, junio) == 0) {
    return 6;
  }
  if (strcmp(mes1, julio) == 0) {
    return 7;
  }
  if (strcmp(mes1, agosto) == 0) {
    return 8;
  }
  if (strcmp(mes1, septiembre) == 0) {
    return 9;
  }
  if (strcmp(mes1, octubre) == 0) {
    return 10;
  }
  if (strcmp(mes1, noviembre) == 0) {
    return 11;
  }
  if (strcmp(mes1, diciembre) == 0) {
    return 12;
  }

  return 1;
}

int Fecha::extraer_anio(string stringFecha) {

  int ini, fin;
  int anio;
  string delimitador = "-";
  string nuevoString;
  string token;

  ini = stringFecha.find(delimitador);
  nuevoString = stringFecha.substr(ini + 1);
  ini = nuevoString.find(delimitador) + 1;
  fin = ini + 4;
  token = nuevoString.substr(ini, fin);
  anio = atoi(token.c_str());
  return anio;
}

string Fecha::ver() {
  return to_string(this -> dia) + "/" + to_string(this -> mes) + "/" + to_string(this -> anio);
}