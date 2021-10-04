#ifndef EMPLEADOPORHORAS_H
#define EMPLEADOPORHORAS_H

#include "empleado.h"
#include <string>

class EmpleadoPorHoras : public Empleado
{

private:
    float tarifaPorHoras;
    int horasLaboradas;

public:
    EmpleadoPorHoras(std::string nombre, std::string apellido, std::string email);
    void establecerPago(float montoPorHora, int horasLaboradas);
};

#endif