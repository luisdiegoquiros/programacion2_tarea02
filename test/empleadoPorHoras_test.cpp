#include <gtest/gtest.h>
#include <string>

#include "../src/empleadoPorHoras.h"

namespace
{
    // Tests para método establecerPago del empleado por horas
    TEST(EmpleadoPorHorasTest, Test_establecerPago)
    {
        EmpleadoPorHoras empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(100, 2);
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(200, actual);
    }

    // Tests para método obtenerMontoPorPagar del empleado por horas
    TEST(EmpleadoPorHorasTest, Test_obtenerMontoPorPagar_1)
    {
        EmpleadoPorHoras empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(0, actual);
    }

    TEST(EmpleadoPorHorasTest, Test_obtenerMontoPorPagar_2)
    {
        EmpleadoPorHoras empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(25,4);
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(100, actual);
    }

    // Tests para método obtenerImpuestosPorRetener del empleado por horas
    TEST(EmpleadoPorHorasTest, Test_obtenerImpuestosPorRetener_1)
    {
        EmpleadoPorHoras empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        int actual = empleadoEjemplo.obtenerImpuestosPorRetener();
        EXPECT_EQ(0, actual);
    }

    TEST(EmpleadoPorHorasTest, Test_obtenerImpuestosPorRetener_2)
    {
        EmpleadoPorHoras empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(100000, 5);
        int actual = empleadoEjemplo.obtenerImpuestosPorRetener();
        EXPECT_EQ(0, actual);
    }

}