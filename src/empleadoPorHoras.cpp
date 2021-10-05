#include "empleadoPorHoras.h"

EmpleadoPorHoras::EmpleadoPorHoras(std::string nombre,
                                       std::string apellido,
                                       std::string email) : Empleado(nombre, apellido, email)
{
    
}


 void EmpleadoPorHoras::establecerPago(float montoPorHora, int horasLaboradas){
     this->tarifaPorHoras = montoPorHora;
     this->horasLaboradas = horasLaboradas;
 }

 float EmpleadoPorHoras::obtenerMontoPorPagar(){
     return tarifaPorHoras*horasLaboradas;
 }