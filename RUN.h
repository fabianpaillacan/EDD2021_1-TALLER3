#include <iostream>

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
  void setRUN(string x);
  string getRUN();
  string ver();

  
};
