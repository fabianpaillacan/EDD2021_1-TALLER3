#include "Dosis.h"


Dosis::Dosis(string variante_comercial, int edadMaxima,int edadMinima, int stock, int utilizada, int numeroIdentificador){
  
  this->variante_comercial=variante_comercial;
  this->edadMinima=edadMinima;
  this->edadMaxima=edadMaxima;
  this->stock=stock;
  this->utilizada=utilizada;
  this->numeroIdentificador=numeroIdentificador;

}

Dosis::~Dosis(){

}

string Dosis:: ver(){
  return "variantecomercial: "+ variante_comercial
  +"\nedadMinima: "+to_string(edadMinima)
  +"\nedadMaxima: "+to_string(edadMaxima)
  +"\nstock: "+to_string(stock)+
  +"\nutilizada: "+to_string(utilizada)
  +"\nnumeroIdentificador: "+to_string(numeroIdentificador);

}
string Dosis::getVariante_comercial(){
  return this->variante_comercial;
}
int Dosis::getedadMinima(){
  return this->edadMinima;
}
int Dosis::getedadMaxima(){
  return this->edadMaxima;
}
int Dosis::getstock(){
  return this->stock;
}
int Dosis::getutilizada(){
  return this->utilizada;
}
int Dosis::getnumeroIdentificador(){
  return this->numeroIdentificador;
}
//----------------
//funciones set ->
void Dosis::setVariante_comercial(string variante_comercial){
  this->variante_comercial=variante_comercial;
}
void Dosis::setedadMinima(int edadMinima){
   this->edadMinima=edadMinima;
}
void Dosis::setedadMaxima(int edadMaxima){
   this->edadMaxima=edadMaxima;
}
void Dosis::setstock(int stock){
  this->stock=stock;
}
void Dosis::setutilizada(int utilizada){
   this->utilizada=utilizada;
}
void Dosis::setnumeroIdentificador(int numeroIdentificador){
   this->numeroIdentificador=numeroIdentificador;
}
