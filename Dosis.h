#include <iostream>

#include <string.h>

using namespace std;

class Dosis {

  private:
  string variante_comercial;
  int edadMinima;
  int stock;
  int edadMaxima;
  int numeroIdentificador;
  int utilizada;

  public:

  Dosis(string variante_comercial, int edadMaxima, int edadMinima, int stock, int utilizada, int numeroIdentificador); //constructor  
  ~Dosis();
  //void setRUN(string x);
  string getVariante_comercial();
  int getedadMinima();
  int getedadMaxima();
  int getstock();
  int getutilizada();
  int getnumeroIdentificador();

  void setVariante_comercial(string variante_comercial);
  void setedadMinima(int edadMinima);
  void setedadMaxima(int edadMaxima);
  void setstock(int stock);
  void setutilizada(int utilizada);
  void setnumeroIdentificador(int numeroIdentificador);

  string ver();


};
