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
int agregarDatos(string nombreFile, nodoPaciente ** listaPacientes);

#define delimitador ","

int agregarDatos(string nombreFile, nodoPaciente ** listaPacientes) {

    Paciente * paciente;

    string apellidoPaterno;
    string fecha_nacimiento;
    string nombre;
    string genero;
    string apellidoMaterno;

    ifstream archivo;
    string rut;
    string linea_paciente;

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
    return contLineas;

}

void inicializarListaDosis(nodoDosis ** listaDosis) {
    string AstraZenecastr = "AstraZeneca";
    string Sinovacstr = "Sinovac";
    string Pfizerstr = "Pfizer";
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
    cout << "Stock inicial Sinovac-> 90" << endl;
    cout << "Stock inicial Pfizer-> 120" << endl;
    cout << "Stock inicial AstraZeneca-> 70" << endl;

}
int verificacionCondicionVacuna(nodoPaciente * nodoPaciente, nodoDosis * nodoDosis) {
    string marca = nodoDosis -> dosis -> getVariante_comercial();

    string AstraZeneca = "AstraZeneca";
    string genero = nodoPaciente -> paciente -> getgenero();
    string f = "f";

    if (nodoDosis -> dosis -> getutilizada() == 1) {

        return 0;
    }
    if (marca.compare(AstraZeneca) == 0) {

        if (genero.compare(f) == 0) {

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

    nodoPaciente * ptrPaciente;
    nodoDosis * ptrDosis;
    string rutPaciente;
    int verificacionVacuna = 0;
    int edad0_18 = 0, edad19_25 = 0, edad45_65 = 0, edad25_35 = 0, edad65 = 0, edad36_44 = 0, total = 0;
    ptrPaciente = listaPaciente;

    while (ptrPaciente != NULL) {
        rutPaciente = ptrPaciente -> paciente -> getrun();
        ptrDosis = listaDosis;
        while (ptrDosis != NULL) {

            if (verificacionCondicionVacuna(ptrPaciente, ptrDosis) == 1 && buscarRut( * listaInoculados, rutPaciente) == 0) {

                int edadPaciente = ptrPaciente -> paciente -> edad();
                string marca = ptrDosis -> dosis -> getVariante_comercial();

                Inoculacion * inoculado;
                Fecha * fecha;
                fecha = new Fecha();
                fecha -> setFechaActual();
                inoculado = new Inoculacion(fecha, ptrPaciente -> paciente, ptrDosis -> dosis);
                int usadas = contarDosisUsadas( * listaInoculados, marca);
                if (usadas < ptrDosis -> dosis -> getstock()) {
                    ptrDosis -> dosis -> setutilizada(1);
                    agregarNodoInoculacion(listaInoculados, inoculado);

                    if (edadPaciente < 18) {
                        edad0_18++;
                    } else if (edadPaciente >= 19 && edadPaciente <= 25) {
                        edad19_25++;
                    } else if (edadPaciente > 25 && edadPaciente <= 35) {
                        edad25_35++;
                    } else if (edadPaciente >= 45 && edadPaciente < 65) {
                        edad45_65++;
                    } else if (edadPaciente > 65) {
                        edad65++;
                    } else {
                        edad36_44++;
                    }

                }

            }
            ptrDosis = ptrDosis -> siguiente;
        }
        ptrPaciente = ptrPaciente -> siguiente;

    }

    string AstraZeneca = "AstraZeneca";
    string Sinovac = "Sinovac";
    string Pfizer = "Pfizer";
    int stockAstraZeneca = obtenerStockMarca(listaDosis, AstraZeneca);
    int stockSinovac = obtenerStockMarca(listaDosis, Sinovac);
    int stockPfizer = obtenerStockMarca(listaDosis, Pfizer);
    int SinovacUsadas = contarDosisUsadas( * listaInoculados, Sinovac);
    int PfizerUsadas = contarDosisUsadas( * listaInoculados, Pfizer);
    int AstraZenecaUsadas = contarDosisUsadas( * listaInoculados, AstraZeneca);

    cout << "Vacunas Sinovac: " << endl;
    cout << "Stock -> " << stockSinovac << endl;
    cout << "Usadas -> " << SinovacUsadas << endl;
    cout << "Disponibles -> " << stockSinovac - SinovacUsadas << endl;
    cout << "--------------------------------------------\n";

    cout << "Vacunas Pfizer: " << endl;
    cout << "Stock-> " << stockPfizer << endl;
    cout << "Usadas -> " << PfizerUsadas << endl;
    cout << "Disponibles -> " << stockPfizer - PfizerUsadas << endl;
    cout << "--------------------------------------------\n";

    cout << "Vacunas  AstraZeneca : " << endl;
    cout << "Stock ->" << stockAstraZeneca << endl;
    cout << "Usadas -> " << AstraZenecaUsadas << endl;
    cout << "Disponibles -> " << stockAstraZeneca - AstraZenecaUsadas << endl;

    cout << "--------------------------------------------\n";
    cout << "Vacunados de 0 a 18 anios -> " << edad0_18 << endl;
    cout << "Vacunados de 19 a 25 anios -> " << edad19_25 << endl;
    cout << "Vacunados de 25 a 35 anios -> " << edad25_35 << endl;
    cout << "Vacunados de 36 a 44 anios -> " << edad36_44 << endl;
    cout << "Vacunados de 45 a 65 anios -> " << edad45_65 << endl;
    cout << "Vacunados 65+ anios -> " << edad65 << endl;
    total = edad0_18 + edad19_25 + edad25_35 + edad36_44 + edad45_65 + edad65;
    cout << "Total vacunados-> " << total << endl;

}

void pacientesNoVacunados(nodoPaciente * listaPacientes, nodoInoculacion * listaInoculados) {
    nodoPaciente * headPaciente;
    nodoInoculacion * headInoculado;

    headPaciente = listaPacientes;
    headInoculado = listaInoculados;

    while (headPaciente != NULL) {
        string rut = headPaciente -> paciente -> getrun();
        int encontrado = buscarRutInoculacion(listaInoculados, rut);
        if (encontrado == 0) {
            cout << headPaciente -> paciente -> ver();
            cout << "\n";
            cout << "-------------------------\n";
        }
        headPaciente = headPaciente -> siguiente;
    }

}

int main() {
    nodoPaciente * listaPacientes = NULL;
    nodoDosis * listaDosis = NULL;
    nodoInoculacion * listaInoculados = NULL;
    int retornoInoculados = 0;
    int contLineas = 0;
    int opc = 0;

    while (opc < 8)

    {
        cout << "................................................................";
        cout << "\n                                                          .\n";
        cout << "|1| Informar fecha actual.\n";
        cout << "|2| Cargar base de datos pacientes.CSV.\n";
        cout << "|3| Resultado de la carga de datos.\n";
        cout << "|4| Inicializar Lista Dosis.\n";

        cout << "|5| Iniciar Vacunacion.\n";
        cout << "|6| Consultar Paciente.\n";
        cout << "|7| Pacientes no vacunados.\n";

        cout << "|8| Salir.                                               .\n";
        cout << "................................................................\n";
        cin >> opc;
        switch (opc) {
        case 1: {
            system("clear");
            int dia, mes, anio;
            Fecha * fecha;
            fecha = new Fecha();
            dia = fecha -> getdiaActual();
            mes = fecha -> getmesActual();
            anio = fecha -> getanioActual();
            cout << "La fecha del dia de hoy es -> ";
            cout << dia;
            cout << "/" << mes;
            cout << "/" << anio << endl;

            break;
        }
        case 2: {

            contLineas = agregarDatos("Pacientes.csv", & listaPacientes);
            cout << "Se ha cargado correctamente." << endl;
            getchar();
            getchar();
            system("clear");
            break;
        }
        case 3: {
            cout << "procesados: " << contLineas << endl;
            cout << "se han cargado: " << contarNodos(listaPacientes) << endl;
            getchar();
            getchar();
            system("clear");
            break;
        }
        case 4: {

            inicializarListaDosis( & listaDosis);
            getchar();
            getchar();
            system("clear");
            break;
        }
        case 5: {

            IniciarVacunacion( & listaInoculados, listaPacientes, listaDosis);
           
           
            break;
        }
        case 6: {
            
            retornoInoculados = buscarRutInoculacionInput(listaInoculados);
            getchar();
            getchar();
            system("clear");
            break;
        }
        case 7: {
            pacientesNoVacunados(listaPacientes, listaInoculados);
            getchar();
            getchar();
            system("clear");
            break;
        }
        default:
            return 0;
        }

    }

    return 0;
}