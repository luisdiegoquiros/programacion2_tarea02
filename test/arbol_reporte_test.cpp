#include <gtest/gtest.h>
#include <string>

#include "../src/arbol.h"

namespace
{
    //Test para la generación del reporte
    TEST(ArbolTests, Test_generarReporte)
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

        //Salida
        std::ostringstream streamSalida{};
        arbol->generarReporte(streamSalida);
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "1,Denis Tyler,Denis Tyler,6" << std::endl;
        streamSalidaEsperada << "2,Clarissa Parker,Denis Tyler,10" << std::endl;
        streamSalidaEsperada << "3,Harmony Rycroft,Denis Tyler,85" << std::endl;
        streamSalidaEsperada << "4,Johnny Walton,Harmony Rycroft,200" << std::endl;
        streamSalidaEsperada << "5,Darlene Johnson,Harmony Rycroft,300" << std::endl;
        streamSalidaEsperada << "601,0,601";
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

}