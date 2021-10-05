#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(std::string nombre,
                                   std::string apellido,
                                   std::string email) : Empleado(nombre, apellido, email)
{
    this->tarifaPorHoras = 0;
    this->horasLaboradas = 0;
}

void EmpleadoPorHoras::establecerPago(float montoPorHora, int horasLaboradas)
{
    this->tarifaPorHoras = montoPorHora;
    this->horasLaboradas = horasLaboradas;
}

float EmpleadoPorHoras::obtenerMontoPorPagar()
{
    return tarifaPorHoras * horasLaboradas;
}

float EmpleadoPorHoras::obtenerImpuestosPorRetener()
{
    return 0;
}