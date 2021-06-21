#include <iostream> 

using namespace std;

class Paciente {
  private: 
  int fecha_nacimiento;
  string RUN;
  string nombre_apellido;

  public:
  Paciente();
  ~Paciente();
  int edad();//calcula la edad del paciente
  void getFecha_nacimiento();
  string getRUN();
  string getnombre_apellido();

};
