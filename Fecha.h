#include <iostream>

using namespace std;
class Fecha{
 private: 
 
 int anio;
 int dia;
 int mes;
 void setdia(int dia);
 void setanio(int anio);
 void setmes(int mes);
 bool validarFecha(string stringFecha);

 public: 
  
  Fecha();
  ~Fecha();
  void setFecha(string stringFecha);
  int getdia();
  int getanio();
  int getmes();
  int extraer_anio(string stringFecha);
  int extraer_mes(string stringFecha);
  int extraer_dia(string stringFecha);


  string ver();
};