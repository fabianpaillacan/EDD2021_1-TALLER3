#include <iostream>

#include <bits/stdc++.h>

#include <time.h>

#include "nodoPaciente.h"

#include "nodoInoculacion.h"

#include "nodoDosis.h"

#include "Dosis.h"

#include  "Fecha.h"

#include  "Paciente.h"

#include  "Inoculacion.h"

using namespace std;
void agregarDatos(string nombreFile, nodoPaciente ** listaPacientes);

#define delimitador ","

void agregarDatos(string nombreFile, nodoPaciente ** listaPacientes) {

    Paciente * paciente;

    string apellidoPaterno;
    string fecha_nacimiento;
    string nombre;
    string genero;
    string apellidoMaterno;

    ifstream archivo;
    string rut;
    string linea_paciente;
    string token;
    int ini, fin;
    int j;

    archivo.open(nombreFile, ios:: in );
    if (archivo.fail()) {
        cout << "falla al iniciar la lectura";
        exit(1);
    }
    int contLineas = 0;
    getline(archivo, rut);
    while (archivo.good()) {

        Paciente * paciente;

        getline(archivo, rut, ',');
        getline(archivo, apellidoPaterno, ',');
        getline(archivo, apellidoMaterno, ',');
        getline(archivo, nombre, ',');
        getline(archivo, genero, ',');
        getline(archivo, fecha_nacimiento, '\n');
        contLineas++;
        paciente = new Paciente(nombre, apellidoMaterno, apellidoPaterno, genero);

        int successRun, successFecha;
        successRun = paciente -> setRun(rut);
        successFecha = paciente -> setfecha_nacimiento(fecha_nacimiento);
        if (successRun != 0 && successFecha != 0) {
            agregarNodo(listaPacientes, paciente);
        }

    }
    cout << "se han cargado: " << contarNodos( * listaPacientes) << endl;
    cout << "procesados: " << contLineas << endl;

}

void inicializarListaDosis(nodoDosis ** listaDosis) {
  string AstraZenecastr="AstraZeneca";
    string Sinovacstr="Sinovac";
    string Pfizerstr="Pfizer";
    int numero_de_serie = 10000;
    for (int i = 0; i <= 90; i++) //sinovac
    {
        Dosis * sinovac;
        numero_de_serie = numero_de_serie + 3;
        sinovac = new Dosis(Sinovacstr, 80, 18, 90, 0, numero_de_serie);
        agregarNodoDosis(listaDosis, sinovac);
    }

    for (int i = 0; i <= 120; i++) //pzifer
    {
        Dosis * Pfizer;
        numero_de_serie = numero_de_serie + 7;
        Pfizer = new Dosis(Pfizerstr, 55, 15, 120, 0, numero_de_serie);
        agregarNodoDosis(listaDosis, Pfizer);
    }
    for (int i = 0; i <= 70; i++) //sinovac
    {
        Dosis * AstraZeneca;
        numero_de_serie = numero_de_serie + 5;
        AstraZeneca = new Dosis(AstraZenecastr, 41, 18, 70, 0, numero_de_serie);
        agregarNodoDosis(listaDosis, AstraZeneca);
    }

}
int verificacionCondicionVacuna(nodoPaciente* nodoPaciente, nodoDosis * nodoDosis) {
 string marca=nodoDosis->dosis -> getVariante_comercial();
 
 string AstraZeneca="AstraZeneca";
  string genero=nodoPaciente -> paciente -> getgenero();
  string f="f";
  


    if (nodoDosis -> dosis -> getutilizada() == 1) {
      
        return 0;
    }
    if (marca.compare(AstraZeneca)==0) {
       
       
        if (genero.compare(f)==0) {
         
            if (nodoPaciente -> paciente -> edad() > 41) {
                return 1;
            } else {
                return 0;
            }

        } else {
            if (nodoPaciente -> paciente -> edad() > 18) {
                return 1;
            } else {
                return 0;
            }
        }

    }

    if (nodoPaciente -> paciente -> edad() >= nodoDosis -> dosis -> getedadMinima() && nodoPaciente -> paciente -> edad() <= nodoDosis -> dosis -> getedadMaxima()) {
        return 1;
    }
    return 0;
}

void IniciarVacunacion(nodoInoculacion ** listaInoculados, nodoPaciente * listaPaciente, nodoDosis * listaDosis) {
  
  nodoPaciente* ptrPaciente;
  nodoDosis* ptrDosis;
  string rutPaciente;
  int verificacionVacuna=0;

  ptrPaciente=listaPaciente;
  
    while (ptrPaciente != NULL) {
      rutPaciente=ptrPaciente->paciente->getrun();
      //cout<<ptrPaciente->paciente->ver()<<endl;
      ptrDosis=listaDosis;
        while (ptrDosis != NULL) {
        
            /*verificacionVacuna=verificacionCondicionVacuna(ptrPaciente, ptrDosis);

            if (verificacionVacuna==1){
           
            }*/

            if (verificacionCondicionVacuna(ptrPaciente, ptrDosis)==1 && buscarRut(*listaInoculados, rutPaciente)==0){
             
              string marca= ptrDosis->dosis->getVariante_comercial();
              
              Inoculacion* inoculado;
              Fecha* fecha;
              fecha=new Fecha();
              inoculado=new Inoculacion(fecha, ptrPaciente->paciente, ptrDosis->dosis);
               int usadas=contarDosisUsadas(*listaInoculados, marca);
              if (usadas<ptrDosis->dosis->getstock()){
              ptrDosis->dosis->setutilizada(1);
              agregarNodoInoculacion(listaInoculados, inoculado);
              }
              
              
            }
            ptrDosis=ptrDosis->siguiente;
        }
        ptrPaciente=ptrPaciente->siguiente;
    
    }

    string AstraZeneca="AstraZeneca";
    string Sinovac="Sinovac";
    string Pfizer="Pfizer";
    int stockAstraZeneca=obtenerStockMarca(listaDosis, AstraZeneca);
    int stockSinovac=obtenerStockMarca(listaDosis, Sinovac);
    int stockPfizer=obtenerStockMarca(listaDosis, Pfizer);
    int SinovacUsadas=contarDosisUsadas(*listaInoculados, Sinovac);
    int PfizerUsadas=contarDosisUsadas(*listaInoculados,Pfizer);
    int AstraZenecaUsadas=contarDosisUsadas(*listaInoculados, AstraZeneca);

    cout<<"cantidad de Sinovac disponibles -> "<<stockSinovac-SinovacUsadas<<endl;
  cout<<"cantidad de Pfizer disponibles -> "<<stockPfizer-PfizerUsadas<<endl;
  cout<<"cantidad de AstraZeneca disponibles -> "<<stockAstraZeneca-AstraZenecaUsadas<<endl;
  
   cout<<"cantidad de Sinovac usadas -> "<<SinovacUsadas<<endl;
  cout<<"cantidad de Pfizer usadas -> "<<PfizerUsadas<<endl;
  cout<<"cantidad de AstraZeneca usadas -> "<<AstraZenecaUsadas<<endl;

  cout<<"cantidad de Sinovac -> "<<stockSinovac<<endl;
  cout<<"cantidad de Pfizer-> "<<stockPfizer<<endl;
  cout<<"cantidad de AstraZeneca -> "<<stockAstraZeneca<<endl;
}

int main() {
   
    nodoDosis * listaDosis = NULL;
    inicializarListaDosis( & listaDosis); 
   
    
    
   // printList(listaDosis);
    
    nodoPaciente * listaPacientes = NULL;
    agregarDatos("Pacientes.csv", & listaPacientes);
    //printList(*listaPacientes);
    nodoInoculacion * listaInoculados = NULL;
    IniciarVacunacion( & listaInoculados, listaPacientes, listaDosis);
    //printList(listaInoculados);
    //contarDosisUsadas(listaInoculados, "Sinovac");

   /* cout<<"utilizadas AstraZeneca: "<<to_string(contarDosisUsadas(listaInoculados, AstraZeneca));*/

}




 



