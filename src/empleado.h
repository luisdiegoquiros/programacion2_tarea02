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
    virtual float obtenerMontoPorPagar()=0;
    virtual float obtenerImpuestosPorRetener()=0;


private:
    std::string nombre;
    std::string apellido;
    std::string email;
};

#endif