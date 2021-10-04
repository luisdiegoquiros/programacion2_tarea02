#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado
{

protected:
    Empleado(std::string nombre, std::string apellido, std::string email);

public:
    ~Empleado();
    std::string obtenerNombreCompleto();
    virtual void establecerPago(float salario) {};
    virtual void establecerPago(float montoPorHora, int horasLaboradas){};

private:
    std::string nombre;
    std::string apellido;
    std::string email;
};

#endif