#ifndef NODO_H
#define NODO_H

#include "empleado.h"
#include <vector>
#include <iostream>

class Nodo {

    int id;
    int idSupervisor;
    Empleado *empleado;
    std::vector<Nodo *> subordinados;
    
    public:
    Nodo(int id, Empleado *empleado, int idSupervisor);
    ~Nodo();

    Empleado* obtenerEmpleado ();

    void AgregarHijo(Nodo *hijo);

    friend std::ostream& operator << (std::ostream &o, const Nodo &nodo);
};

#endif