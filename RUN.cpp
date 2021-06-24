#include "RUN.h"
#include <iostream>
#include <string.h>

using namespace std;

RUN::RUN() { //constructor 
  this -> run = ""; //esta vacio
}
RUN::~RUN() {

}

int RUN::setRUN(string x) {

  if (validador(x) == 1) {

    this -> run = x;
    return 1;
  }
  return 0;
}

bool RUN::validador(string x) {
  string verificador;
  int digitoVerificador = RUN::getDigito(x);
  int rutSinDigito = RUN::getRutSindigito(x);
  int token;
  verificador = RUN::digito_verificador_rut(rutSinDigito);

  token = atoi(verificador.c_str());

  return token == digitoVerificador;

}

string RUN::getRUN() {
  return this -> run;
}

int RUN::getRutSindigito(string s) {

  string delimiter = "-";
  int ini, fin, rutSinDigito;
  string token;

  ini = 0;
  fin = s.find(delimiter);
  token = s.substr(ini, fin);
  rutSinDigito = atoi(token.c_str());

  return rutSinDigito;
}

int RUN::getDigito(string s) {

  string delimiter = "-";
  int ini, fin, digitoVerificador;
  string token;

  ini = s.find(delimiter) + 1;
  fin = ini + 2;
  token = s.substr(ini, fin);
  digitoVerificador = atoi(token.c_str());

  return digitoVerificador;

}

string RUN::ver() {
  return this -> run;

}

char RUN::digito_verificador_rut(unsigned rut) { //verifica si el rut es valido

  unsigned sum = 0, factor = 2;
  while (rut) {
    sum += (rut % 10) * factor;
    rut /= 10;
    factor = factor == 7 ? 2 : factor + 1;
  }
  const unsigned res = 11 - sum % 11;

  return res == 11 ? '0' : res == 10 ? 'k' : res + '0';
}