#include <gtest/gtest.h>
#include <string>

#include "../src/arbol.h"

namespace
{
    //Test para obtenerMontoPorPagar
    TEST(ArbolTests, Test_obtenerMontoPorPagar)
    {
        //Primero se deben de cargar las personas
        std::ostringstream streamGeneracionEjemplo{};
        streamGeneracionEjemplo << "1 Denis Tyler denis_tyler@biz.com 2" << std::endl;
        streamGeneracionEjemplo << "2 Clarissa Parker clarissa_parker@biz.com 2 1" << std::endl;
        streamGeneracionEjemplo << "3 Harmony Rycroft harmony_rycroft@biz.com 2 1" << std::endl;
        streamGeneracionEjemplo << "4 Johnny Walton Johnny_Walton5439@elnee.tech 2 3" << std::endl;
        streamGeneracionEjemplo << "5 Darlene Johnson Darlene_Johnson5160@irrepsy.com 2 3" << std::endl;
        std::string entradaEjemplo = streamGeneracionEjemplo.str();

        std::istringstream streamEntradaEjemplo{entradaEjemplo};
        Arbol *arbol = new Arbol();
        arbol->cargarPersonas(streamEntradaEjemplo);

        //Después se cargan las horas trabajadas
        std::ostringstream streamGeneracionHoras{};
        streamGeneracionHoras << "1 2 3" << std::endl;
        streamGeneracionHoras << "2 2.5 4" << std::endl;
        streamGeneracionHoras << "3 8.5 10" << std::endl;
        streamGeneracionHoras << "4 25 8" << std::endl;
        streamGeneracionHoras << "5 100.00 3" << std::endl;
        std::string entradaEjemploHoras = streamGeneracionHoras.str();

        std::istringstream streamEntradaEjemploHoras{entradaEjemploHoras};
        arbol->cargarHorasTrabajadas(streamEntradaEjemploHoras);

        //Calcular monto por pagar
        float actual = arbol->obtenerMontoPorPagar();

        delete arbol;

        EXPECT_FLOAT_EQ(601, actual);
    }

    //Test para obtenerImpuestosPorRetener
    TEST(ArbolTests, Test_obtenerImpuestosPorRetener)
    {
        //Primero se deben de cargar las personas
        std::ostringstream streamGeneracionEjemplo{};
        streamGeneracionEjemplo << "1 Denis Tyler denis_tyler@biz.com 1" << std::endl;
        streamGeneracionEjemplo << "2 Clarissa Parker clarissa_parker@biz.com 1 1" << std::endl;
        streamGeneracionEjemplo << "3 Harmony Rycroft harmony_rycroft@biz.com 1 1" << std::endl;
        streamGeneracionEjemplo << "4 Johnny Walton Johnny_Walton5439@elnee.tech 1 3" << std::endl;
        streamGeneracionEjemplo << "5 Darlene Johnson Darlene_Johnson5160@irrepsy.com 1 3" << std::endl;
        std::string entradaEjemplo = streamGeneracionEjemplo.str();

        std::istringstream streamEntradaEjemplo{entradaEjemplo};
        Arbol *arbol = new Arbol();
        arbol->cargarPersonas(streamEntradaEjemplo);

        //Después se cargan los salarios
        std::ostringstream streamGeneracionSalarios{};
        streamGeneracionSalarios << "1 4600.98" << std::endl;
        streamGeneracionSalarios << "2 3097.50" << std::endl;
        streamGeneracionSalarios << "3 4586.42" << std::endl;
        streamGeneracionSalarios << "4 4606.19" << std::endl;
        streamGeneracionSalarios << "5 100.00" << std::endl;
        std::string entradaEjemploSalario = streamGeneracionSalarios.str();

        std::istringstream streamEntradaEjemploSalario{entradaEjemploSalario};
        arbol->cargarSalarios(streamEntradaEjemploSalario);

        //Calcular monto por pagar
        float actual = arbol->obtenerImpuestosPorRetener();

        delete arbol;

        EXPECT_FLOAT_EQ(1189.3762, actual);
    }

}