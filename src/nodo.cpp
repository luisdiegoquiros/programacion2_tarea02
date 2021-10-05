#include "nodo.h"
#include <iostream>

Nodo::Nodo(int id, Empleado *nuevoEmpleado, Nodo *nodoSupervisor)
{
    this->id = id;
    this->empleado = nuevoEmpleado;
    this->nodoSupervisor = nodoSupervisor;
}

Nodo::~Nodo()
{
    std::clog << "Borrando nodo " << this->id << std::endl;

    delete this->empleado;

    for (Nodo *hijo : this->subordinados)
    {
        delete hijo;
    }

    std::clog << "Termina de borrar nodo " << this->id << std::endl;
}

void Nodo::AgregarHijo(Nodo *hijo)
{
    this->subordinados.push_back(hijo);
}

std::ostream &operator<<(std::ostream &o, const Nodo &nodo)
{
    // Imprimir información del nodo
    o << nodo.id;
    o << ",";
    o << nodo.empleado->obtenerNombreCompleto();
    o << ",";

    //Sino tiene supervisor, el supervisor es él mismo.
    if (nodo.nodoSupervisor)
        o << nodo.nodoSupervisor->obtenerEmpleado()->obtenerNombreCompleto();
    else
        o << nodo.empleado->obtenerNombreCompleto();

    o << ",";
    o << nodo.empleado->obtenerMontoPorPagar();
    o << std::endl;

    // Imprimir información de cada hijo
    for (Nodo *nodoHijo : nodo.subordinados)
    {
        o << *nodoHijo;
    }

    return o;
}

Empleado *Nodo::obtenerEmpleado()
{
    return this->empleado;
}

float Nodo::obtenerImpuestosPorRetener()
{
    float total = 0;

    total = this->empleado->obtenerImpuestosPorRetener();

    for (Nodo *hijo : this->subordinados)
    {
        total = total + hijo->obtenerImpuestosPorRetener();
    }

    return total;
}

float Nodo::obtenerTotalPorPagar()
{
    float total = 0;

    total = this->empleado->obtenerMontoPorPagar();

    for (Nodo *hijo : this->subordinados)
    {
        total = total + hijo->obtenerTotalPorPagar();
    }

    return total;
}