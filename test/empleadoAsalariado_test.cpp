#include <gtest/gtest.h>
#include <string>

#include "../src/empleadoAsalariado.h"

namespace
{
    // Tests para método establecerPago del empleado asalariado
    TEST(EmpleadoAsalariadoTest, Test_establecerPago)
    {
        EmpleadoAsalariado empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(100);
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(93, actual);
    }

    // Tests para método obtenerMontoPorPagar del empleado asalariado
    TEST(EmpleadoAsalariadoTest, Test_obtenerMontoPorPagar_1)
    {
        EmpleadoAsalariado empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(0, actual);
    }

    TEST(EmpleadoAsalariadoTest, Test_obtenerMontoPorPagar_2)
    {
        EmpleadoAsalariado empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(100000);
        int actual = empleadoEjemplo.obtenerMontoPorPagar();
        EXPECT_EQ(93000, actual);
    }

    // Tests para método obtenerImpuestosPorRetener del empleado asalariado
    TEST(EmpleadoAsalariadoTest, Test_obtenerImpuestosPorRetener_1)
    {
        EmpleadoAsalariado empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        int actual = empleadoEjemplo.obtenerImpuestosPorRetener();
        EXPECT_EQ(0, actual);
    }

    TEST(EmpleadoAsalariadoTest, Test_obtenerImpuestosPorRetener_2)
    {
        EmpleadoAsalariado empleadoEjemplo{"Luis", "Quiros", "luis@gmail.com"};
        empleadoEjemplo.establecerPago(100000);
        int actual = empleadoEjemplo.obtenerImpuestosPorRetener();
        EXPECT_EQ(7000, actual);
    }

}