#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include "empleado.h"
#include <string>

class EmpleadoAsalariado : public Empleado
{

private:
    float salarioBruto;

public:
    EmpleadoAsalariado(std::string nombre, std::string apellido, std::string email);
    void establecerSalarioBruto(float salario);
    void establecerPago(float salario);
    float obtenerMontoPorPagar();
};

#endif