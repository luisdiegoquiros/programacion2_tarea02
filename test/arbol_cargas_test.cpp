#include <gtest/gtest.h>
#include <string>

#include "../src/arbol.h"

namespace
{
    //Test para la carga de Personas
    TEST(ArbolTests, Test_cargarPersonas)
    {

        std::ostringstream streamGeneracionEjemplo{};
        streamGeneracionEjemplo << "1 Denis Tyler denis_tyler@biz.com 1" << std::endl;
        streamGeneracionEjemplo << "2 Clarissa Parker clarissa_parker@biz.com 1 1" << std::endl;
        streamGeneracionEjemplo << "3 Harmony Rycroft harmony_rycroft@biz.com 1 1" << std::endl;
        streamGeneracionEjemplo << "4 Johnny Walton Johnny_Walton5439@elnee.tech 2 3" << std::endl;
        streamGeneracionEjemplo << "5 Darlene Johnson Darlene_Johnson5160@irrepsy.com 2 3" << std::endl;
        std::string entradaEjemplo = streamGeneracionEjemplo.str();

        std::istringstream streamEntradaEjemplo{entradaEjemplo};
        Arbol *arbol = new Arbol();
        arbol->cargarPersonas(streamEntradaEjemplo);

        std::ostringstream streamSalida{};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "1,Denis Tyler,Denis Tyler,0" << std::endl;
        streamSalidaEsperada << "2,Clarissa Parker,Denis Tyler,0" << std::endl;
        streamSalidaEsperada << "3,Harmony Rycroft,Denis Tyler,0" << std::endl;
        streamSalidaEsperada << "4,Johnny Walton,Harmony Rycroft,0" << std::endl;
        streamSalidaEsperada << "5,Darlene Johnson,Harmony Rycroft,0" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    //Test para la carga de Salarios
    TEST(ArbolTests, Test_cargarSalarios)
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

        //Salida
        std::ostringstream streamSalida{};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "1,Denis Tyler,Denis Tyler,4278.91" << std::endl;
        streamSalidaEsperada << "2,Clarissa Parker,Denis Tyler,2880.68" << std::endl;
        streamSalidaEsperada << "3,Harmony Rycroft,Denis Tyler,4265.37" << std::endl;
        streamSalidaEsperada << "4,Johnny Walton,Harmony Rycroft,4283.76" << std::endl;
        streamSalidaEsperada << "5,Darlene Johnson,Harmony Rycroft,93" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

    //Test para la carga de Horas Trabajadas
    TEST(ArbolTests, Test_cargarHorasTrabajadas)
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
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        std::ostringstream streamSalidaEsperada{};
        streamSalidaEsperada << "1,Denis Tyler,Denis Tyler,6" << std::endl;
        streamSalidaEsperada << "2,Clarissa Parker,Denis Tyler,10" << std::endl;
        streamSalidaEsperada << "3,Harmony Rycroft,Denis Tyler,85" << std::endl;
        streamSalidaEsperada << "4,Johnny Walton,Harmony Rycroft,200" << std::endl;
        streamSalidaEsperada << "5,Darlene Johnson,Harmony Rycroft,300" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }
}