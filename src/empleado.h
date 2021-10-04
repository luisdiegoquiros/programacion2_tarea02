#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
    
    protected:
        Empleado(std::string nombre, std::string apellido, std::string email);

    public:
        ~Empleado();
        std::string obtenerNombreCompleto();

    private:
        std::string nombre;
        std::string apellido;
        std::string email;
};

#endif