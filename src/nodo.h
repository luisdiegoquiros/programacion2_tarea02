#ifndef NODO_H
#define NODO_H

#include "empleado.h"
#include <vector>
#include <iostream>

class Nodo {

    int id;
    Nodo* nodoSupervisor;
    Empleado *empleado;
    std::vector<Nodo *> subordinados;
    
    public:
    Nodo(int id, Empleado *empleado, Nodo* nodoSupervisor);
    ~Nodo();

    Empleado* obtenerEmpleado ();

    void AgregarHijo(Nodo *hijo);
    float obtenerTotalPorPagar();
    float obtenerImpuestosPorRetener();

    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif