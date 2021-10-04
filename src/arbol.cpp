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
    std::cout << "Se crea el arbol vació" << std::endl;
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
        EmpleadoAsalariado *empleado = new EmpleadoAsalariado(nombre, apellido, email);
    }
    else if (tipoEmpleado == 2)
    {
        EmpleadoPorHoras *empleado = new EmpleadoPorHoras(nombre, apellido, email);
    }
    else
    {
        //Si el tipo de empleado no es ni 1 ni 2 se asume que es empleado asalariado.
        EmpleadoAsalariado *empleado = new EmpleadoAsalariado(nombre, apellido, email);
    }

    Nodo *nodo = new Nodo(id, empleado);

    // Si idPadre = 0, es el nodo raíz
    if (idSupervisor == 0)
    {
        this->director = nodo;
    }
    else
    {
        // Buscar ese nodo supervisor
        Nodo *nodoSupervisor = this->planilla.at(idSupervisor);
        nodoSupervisor->AgregarHijo(nodo);
    }

    // Agregar nodo al índice
    this->planilla.insert(std::pair<int, Nodo *>(id, nodo));
}

void Arbol::cargarPersonas(std::istream &inputStream)
{
    std::cout << "Se inicia la carga de personas" << std::endl;
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

        std::cout << "Datos del empleado a añadir: " << std::endl;
        std::cout << idEmpleado << " * " << nombre << " * " << apellido << " * " << email << " * " << tipoEmpleado << " * " << idSupervisor << std::endl;

        this->agregarNodo(idEmpleado, nombre, apellido, email, tipoEmpleado, idSupervisor);
    }
}

/*

std::ostream &operator<<(std::ostream &o, const Arbol &arbol)
{
    Nodo *raiz = arbol.director;
    o << *(raiz);

    return o;
}

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