#include <iostream>
#ifndef RUN_H
#define RUN_H

using namespace std;

class RUN {
  private:
  
  int  getRutSindigito(string s);
  bool validador (string x);
  int getDigito(string s);
  char digito_verificador_rut(unsigned rut);
  
  public:
  
  string run;
  RUN(); //constructor  
  ~RUN();
  int setRUN(string x);
  string getRUN();
  string ver();
 
};
#endif
