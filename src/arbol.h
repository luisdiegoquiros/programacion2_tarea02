#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"
#include <map>
#include <iostream>

class Arbol {

    private:
    Nodo *director;
    std::map<int, Nodo *> planilla;

    public:
    Arbol();
    ~Arbol();
    void agregarNodo(int id, std::string nombre, std::string apellido, std::string email, int tipoEmpleado, int idSupervisor);


    void cargarPersonas(std::istream &inputStream);

    ///friend std::ostream& operator << (std::ostream &o, const Arbol &arbol);
    ///friend std::istream& operator >> (std::istream &i, Arbol &arbol);
};


#endif