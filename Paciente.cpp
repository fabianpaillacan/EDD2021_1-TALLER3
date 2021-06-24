#include "Paciente.h"

#include <iostream>

using namespace std;

Paciente::Paciente(string nombre, string apellidoPaterno, string apellidoMaterno, string genero) {

    this -> fecha_nacimiento = new Fecha();
    this -> run = new RUN();
    this -> nombre = nombre;
    this -> apellidoPaterno = apellidoPaterno;
    this -> apellidoMaterno = apellidoMaterno;
    this -> genero = genero;

}

Paciente::~Paciente() {

}

string Paciente::getFecha_nacimiento() {
    return this -> fecha_nacimiento -> ver();
}

string Paciente::getrun() {
    return this -> run -> RUN::getRUN();
}
string Paciente::getnombre() {
    return this -> nombre;
}
string Paciente::getapellidoPaterno() {
    return this -> apellidoPaterno;
}
string Paciente::getapellidoMaterno() {
    return this -> apellidoMaterno;
}
string Paciente::getgenero() {
    return this -> genero;
}

string Paciente::ver() {
    return "\nFecha_nacimiento: " + this -> getFecha_nacimiento() +
        "\nEdad: " + to_string(this -> Paciente::edad()) +
        "\nRun: " + this -> Paciente::getrun() +
        "\nNombre: " + this -> getnombre() +
        "\nApellido Paterno: " + this -> getapellidoPaterno() +
        +"\nApellido Materno: " + this -> getapellidoMaterno() +
        "\nGenero: " + this -> getgenero();
}

int Paciente::edad() {

    int aniosCumplidos = 0;
    int diaPaciente = this -> fecha_nacimiento -> getdia();
    int mesPaciente = this -> fecha_nacimiento -> getmes();
    int anioPaciente = this -> fecha_nacimiento -> getanio();

    int mesActual, anioActual, diaActual, respFech, respMes;

    diaActual = this -> fecha_nacimiento -> getdiaActual();
    mesActual = this -> fecha_nacimiento -> getmesActual();
    anioActual = this -> fecha_nacimiento -> getanioActual();

    if (diaActual < diaPaciente) {
        diaActual = diaActual + 30;
        mesActual = mesActual - 1;
        respFech = diaActual - diaPaciente;
    } else
        respFech = diaActual - diaPaciente;

    if (mesActual < mesPaciente) {
        mesActual = mesActual + 12;
        anioActual = anioActual - 1;
        respMes = mesActual - mesPaciente;
    } else
        respMes = mesActual - mesPaciente;

    aniosCumplidos = anioActual - anioPaciente;

    return aniosCumplidos;
}
RUN * Paciente::getRunObj() {

    return this -> run;
}
Fecha * Paciente::getfechaObj() {

    return this -> fecha_nacimiento;
}
int Paciente::setRun(string rut) {
    int success = this -> run -> setRUN(rut);
    return success;
}
int Paciente::setfecha_nacimiento(string fecha_nacimiento) {
    return this -> fecha_nacimiento -> setFecha(fecha_nacimiento);
}