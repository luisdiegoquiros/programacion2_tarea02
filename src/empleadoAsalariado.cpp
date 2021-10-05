#include "empleadoAsalariado.h"
#include <iostream>

EmpleadoAsalariado::EmpleadoAsalariado(std::string nombre,
                                       std::string apellido,
                                       std::string email) : Empleado(nombre, apellido, email)
{
}

void EmpleadoAsalariado::establecerSalarioBruto(float salario)
{
    this->salarioBruto = salario;
    std::cout << "Se establece el salario de " << this->obtenerNombreCompleto() << " en " << this->salarioBruto << std::endl;
}

void EmpleadoAsalariado::establecerPago(float salario)
{
    this->establecerSalarioBruto(salario);
}

float EmpleadoAsalariado::obtenerMontoPorPagar(){
    return salarioBruto * 0.93; //Si se retiene el 7%, el salario neto es el 93%
}