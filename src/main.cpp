#ifndef UNIT_TEST

#include "empleadoAsalariado.h"
#include "empleadoPorHoras.h"
#include "arbol.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    //Crea el árbol
    Arbol *arbol = new Arbol();

    //Carga la información de todas las personas que trabajan en la compañia.
    std::ifstream archivoPersonas("Personas.txt", std::ifstream::in);

    if (!archivoPersonas.is_open())
    {
        std::cerr << "Error leyendo archivo Personas.txt" << std::endl;
        return -1;
    }

    arbol->cargarPersonas(archivoPersonas);

    archivoPersonas.close();

    //Carga la información de los salarios de los empleados asalariados.
    std::ifstream archivoNomina("Nomina.txt", std::ifstream::in);

    if (!archivoNomina.is_open())
    {
        std::cerr << "Error leyendo archivo Nomina.txt" << std::endl;
        return -1;
    }

    arbol->cargarSalarios(archivoNomina);
    archivoNomina.close();
    //Carga la información de las horas y tarifas para los empleados por horas.
    std::ifstream archivoHorasTrabajadas("HorasTrabajadas.txt", std::ifstream::in);

    if (!archivoHorasTrabajadas.is_open())
    {
        std::cerr << "Error leyendo archivo HorasTrabajadas.txt" << std::endl;
        return -1;
    }

    arbol->cargarHorasTrabajadas(archivoHorasTrabajadas);
    archivoHorasTrabajadas.close();


    //Archivo de Salida

    std::ofstream file("reporte.csv", std::ofstream::out);

   arbol->generarReporte(file);
  
    file.close();
    delete arbol;

    return 0;
}

#endif