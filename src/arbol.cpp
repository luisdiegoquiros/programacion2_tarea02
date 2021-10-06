#include <map>
#include "arbol.h"
#include "nodo.h"
#include "empleadoAsalariado.h"
#include "empleadoPorHoras.h"

#include <string>
#include <sstream>

Arbol::Arbol()
{
    this->director = nullptr;
    //std::cout << "Se crea el arbol vació" << std::endl;
}

Arbol::~Arbol()
{

    // Este destructor arranca el proceso de destrucción de los nodos;
    if (this->director != nullptr)
    {
        delete this->director;
    }
}

//Recibe la información del empleado, este método se encarga de crear el nodo y el empleado.
void Arbol::agregarNodo(int id,
                        std::string nombre,
                        std::string apellido,
                        std::string email,
                        int tipoEmpleado,
                        int idSupervisor)
{
    Empleado *empleado = nullptr;
    //Tipo_Empleado será 1 para empleado de nómina y 2 para profesional por horas.
    if (tipoEmpleado == 1)
    {
        empleado = new EmpleadoAsalariado(nombre, apellido, email);
    }
    else if (tipoEmpleado == 2)
    {
        empleado = new EmpleadoPorHoras(nombre, apellido, email);
    }
    else
    {
        //Si el tipo de empleado no es ni 1 ni 2 se asume que es empleado asalariado.
        empleado = new EmpleadoAsalariado(nombre, apellido, email);
    }

    
    Nodo *nodo = nullptr;

    // Si idPadre = 0, es el nodo raíz
    if (idSupervisor == 0)
    {
        nodo = new Nodo(id, empleado, nullptr);
        this->director = nodo;
    }
    else
    {
        // Buscar ese nodo supervisor
        Nodo *nodoSupervisor = this->planilla.at(idSupervisor);

        nodo = new Nodo(id, empleado, nodoSupervisor);
        nodoSupervisor->AgregarHijo(nodo);
    }

    // Agregar nodo al índice
    this->planilla.insert(std::pair<int, Nodo *>(id, nodo));
}

void Arbol::cargarPersonas(std::istream &inputStream)
{
    //std::cout << "Se inicia la carga de personas" << std::endl;
    std::string linea{""};

    int idEmpleado{0};
    std::string nombre{""};
    std::string apellido{""};
    std::string email{""};
    int tipoEmpleado{0};
    int idSupervisor{0};

    while (std::getline(inputStream, linea))
    {

        idEmpleado = 0;
        nombre = "";
        apellido = "";
        email = "";
        tipoEmpleado = 0;
        idSupervisor = 0;

        std::istringstream stream(linea);
        stream >> idEmpleado >> nombre >> apellido >> email >> tipoEmpleado >> idSupervisor;

        //std::cout << "Datos del empleado a cargar: ";
        //std::cout << idEmpleado << " * " << nombre << " * " << apellido << " * " << email << " * " << tipoEmpleado << " * " << idSupervisor << std::endl;

        this->agregarNodo(idEmpleado, nombre, apellido, email, tipoEmpleado, idSupervisor);
    }
}

void Arbol::cargarSalarios(std::istream &inputStream)
{
    std::cout << "Se inicia la carga de salarios" << std::endl;
    std::string linea{""};

    int idEmpleado{0};
    float salario{0.0};

    while (std::getline(inputStream, linea))
    {

        idEmpleado = 0;
        salario = 0.0;

        std::istringstream stream(linea);
        stream >> idEmpleado >> salario;

        std::cout << "Datos del salario a cargar: ";
        std::cout << idEmpleado << " * " << salario << std::endl;

        //Obtiene el nodo y actualiza la información del salario del empleado.
        Nodo *nodo = this->planilla.at(idEmpleado);
        nodo->obtenerEmpleado()->establecerPago(salario);
    }
}

void Arbol::cargarHorasTrabajadas(std::istream &inputStream)
{
    std::cout << "Se inicia la carga de horas trabajadas: " << std::endl;
    std::string linea{""};

    int idEmpleado{0};
    float tarifa{0.0};
    int horas{0};

    while (std::getline(inputStream, linea))
    {

        idEmpleado = 0;
        tarifa = 0.0;
        horas = 0;

        std::istringstream stream(linea);
        stream >> idEmpleado >> tarifa >> horas;

        std::cout << "Datos de las horas a cargar: ";
        std::cout << idEmpleado << " * " << tarifa << " * " << horas << std::endl;

        //Obtiene el nodo y actualiza la información del salario del empleado.
        Nodo *nodo = this->planilla.at(idEmpleado);
        nodo->obtenerEmpleado()->establecerPago(tarifa, horas);
    }
}

void Arbol::generarReporte(std::ostream &outputStream)
{
    outputStream << *(this->director);
    // Imprimir totales
    outputStream << this->obtenerMontoPorPagar();
    outputStream << ",";
    outputStream << this->obtenerImpuestosPorRetener();
    outputStream << ",";
    outputStream << ( this->obtenerMontoPorPagar() + this->obtenerImpuestosPorRetener());
}


float Arbol::obtenerMontoPorPagar(){
    return this->director->obtenerTotalPorPagar();
}

float Arbol::obtenerImpuestosPorRetener(){
    return this->director->obtenerImpuestosPorRetener();
}

std::ostream &operator<<(std::ostream &o, const Arbol &arbol)
{
    Nodo *raiz = arbol.director;
    o << *(raiz);

    return o;
}


/*
std::istream &operator>>(std::istream &i, Arbol &arbol)
{
    std::string linea{""};

    int idNodo{0};
    int valor{0};
    int idPadre{0};

    while (std::getline(i, linea))
    {

        idNodo = 0;
        valor = 0;
        idPadre = 0;

        std::istringstream stream(linea);
        stream >> idNodo >> valor >> idPadre;

        arbol.AgregarNodo(idNodo, valor, idPadre);
    }

    return i;
}

*/