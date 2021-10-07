#include <gtest/gtest.h>
#include <string>

#include "../src/arbol.h"

namespace
{
    // Tests para arbol con un solo nodo
    TEST(ArbolTests, Test_AgregarNodo)
    {

        Arbol *arbol = new Arbol();
        arbol->agregarNodo(1, "Diego", "Quiros", "luis@gmail.com", 1, 0);

        std::ostringstream streamSalida{};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        EXPECT_EQ("1,Diego Quiros,Diego Quiros,0\n", actual);
    }

    // Tests para arbol con tres nodos. Nivel 1: 1 y Nivel 2: 2
    TEST(ArbolTests, Test_AgregarNodo_2_Niveles)
    {

        Arbol *arbol = new Arbol();
        arbol->agregarNodo(1, "Diego", "Quiros", "diego@gmail.com", 1, 0);
        arbol->agregarNodo(2, "David", "Gomez", "david@gmail.com", 1, 1);
        arbol->agregarNodo(3, "Carlos", "Jimenez", "carlos@gmail.com", 1, 1);

        std::ostringstream streamSalida{};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        //Salida esperada:
        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1,Diego Quiros,Diego Quiros,0" << std::endl;
        streamSalidaEsperada << "2,David Gomez,Diego Quiros,0" << std::endl;
        streamSalidaEsperada << "3,Carlos Jimenez,Diego Quiros,0" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }


    // Tests para arbol con 5 nodos. 
    TEST(ArbolTests, Test_AgregarNodo_3_Niveles)
    {

        Arbol *arbol = new Arbol();
        arbol->agregarNodo(1, "Diego", "Quiros", "diego@gmail.com", 1, 0);
        arbol->agregarNodo(2, "David", "Gomez", "david@gmail.com", 1, 1);
        arbol->agregarNodo(3, "Antoine", "Hubbard", "antoine@gmail.com", 1, 1);
        arbol->agregarNodo(4, "Elizabeth", "Dildy", "elizabeth@gmail.com", 1, 2);
        arbol->agregarNodo(5, "Lisa", "Tanner", "lisa@gmail.com", 1, 2);


        std::ostringstream streamSalida{};
        streamSalida << *arbol;
        std::string actual = streamSalida.str();

        delete arbol;

        //Salida esperada:
        std::ostringstream streamSalidaEsperada {};
        streamSalidaEsperada << "1,Diego Quiros,Diego Quiros,0" << std::endl;
        streamSalidaEsperada << "2,David Gomez,Diego Quiros,0" << std::endl;
        streamSalidaEsperada << "4,Elizabeth Dildy,David Gomez,0" << std::endl;
        streamSalidaEsperada << "5,Lisa Tanner,David Gomez,0" << std::endl;
        streamSalidaEsperada << "3,Antoine Hubbard,Diego Quiros,0" << std::endl;
        std::string esperada = streamSalidaEsperada.str();

        EXPECT_EQ(esperada, actual);
    }

}