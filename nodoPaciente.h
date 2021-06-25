#include "Paciente.h"

using namespace std;

class nodoPaciente{
  public:
    Paciente* paciente;
    nodoPaciente* siguiente;
};
void agregarNodo(nodoPaciente** head_ref, Paciente* paciente);
void printList(nodoPaciente *node);
int  contarNodos(nodoPaciente *node);
