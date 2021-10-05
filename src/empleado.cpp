#include "empleado.h"
#include <string>
#include <iostream>

Empleado::Empleado(std::string nombre, std::string apellido, std::string email){
    //std::clog<< "Se crea empleado de nombre: " << nombre << std::endl;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
}


Empleado::~Empleado() {

    //std::clog<< "Elimina empleado de nombre: " << this->nombre << std::endl;
}


std::string Empleado::obtenerNombreCompleto(){
    std::string nombreCompleto = this->nombre + " " + this->apellido;
    return nombreCompleto;
}



