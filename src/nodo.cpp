#include "nodo.h"
#include <iostream>

Nodo::Nodo(int id, Empleado * nuevoEmpleado)
{
    this->id = id;
    this->empleado = nuevoEmpleado;
     std::clog << "Nuevo nodo con el empleado " << nuevoEmpleado << std::endl;
}

Nodo::~Nodo()
{
    std::clog << "Borrando nodo " << this->id << std::endl;

   
    delete this->empleado;
    
    for (Nodo* hijo : this->subordinados)
    {
        delete hijo;
    }

    std::clog << "Termina de borrar nodo " << this->id << std::endl;
}

void Nodo::AgregarHijo(Nodo *hijo) {
    this->subordinados.push_back(hijo);
}

std::ostream& operator << (std::ostream &o, const Nodo &nodo)
{
    // Imprimir información del nodo
    o << "Nodo: ";
    o << nodo.id;
    o << ". Valor: ";
    o << nodo.empleado;
    o << std::endl;

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.subordinados)
    {
        o << *nodoHijo;
    }

    return o;
}