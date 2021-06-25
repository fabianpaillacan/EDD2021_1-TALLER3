#include <iostream>
#include "Dosis.h"
using namespace std;

 class nodoDosis{
   public:
  Dosis* dosis;
  nodoDosis* siguiente;
  
};

void agregarNodoDosis(nodoDosis** head_ref, Dosis* dosis);
void printList(nodoDosis *node);
int  contarNodos(nodoDosis *node);
int obtenerStockMarca(nodoDosis* node, string marca);
