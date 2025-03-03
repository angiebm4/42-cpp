
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>

/* te complican la vida con c++11 es mucho mas simple ._. ya tiene sus propias
funciones que mandan el error correspondiente si falla el casteo */

int toInt(std::string number)
{
    char* endptr; /* para verificar si la conversion fallo o fue parcial */
    /* errno es una variable global ya creada, dentro de la biblioteca
        estandar, que se cambia de valor en caso de
        que una funcion de dicha biblioteca falle ,
        por ejemplo detecte errores como ERANGE
        hay que resetearlo siempre antes de usarlo */
    errno = 0; /* para verificar si esta fura de rango con ERANGE */
    long     intValue = std::strtol(number.c_str(), &endptr, 10);

    if (errno == ERANGE)
        std::cout << "Error: int out of range" << std::endl;
    else if (*endptr != '\0')
        std::cout << "Error: int convert fail" << std::endl;
    /* la funcion std::strtol devuelve un long para una correcta implementacion
        hay que chekear que la strng no se salga del valos de long y que luego el long
        este dentro de los limites del int para poderlo castear a int si perdidas de valor o desbordamientos*/
    else if (intValue > INT_MAX || intValue < INT_MIN)
        std::cout << "Error: int out of range" << std::endl;
    else
    {
        int i = static_cast<int>(intValue);
        std::cout << "int: " << i << std::endl;
    }
    return (static_cast<int>(intValue));
}

void toFloat(std::string number)
{
    char* endptr;
    errno = 0;
    double   floatValue = std::strtod(number.c_str(), &endptr);

    if (errno == ERANGE)
        std::cout << "Error: float out of range" << std::endl;
    else if (*endptr != '\0')
        std::cout << "Error: float convert fail" << std::endl;
    else if ((floatValue > FLT_MAX || floatValue < -FLT_MAX) 
            && floatValue != HUGE_VAL && floatValue != -HUGE_VAL)
        std::cout << "Error: float out of range" << std::endl;
    else
    {
        float f = static_cast<float>(floatValue);
        std::cout << "float: " << f << "f" << std::endl;
    }
}

void    toDouble(std::string number)
{
    char* endptr;
    errno = 0;
    double  d = std::strtod(number.c_str(), &endptr);
    if (errno == ERANGE)
        std::cout << "Error: double out of range" << std::endl;
    else if (*endptr != '\0')
        std::cout << "Error: double convert fail" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void    toChar(int i)
{
    char    c = static_cast<char>(i);

    /* verificar si c esta dentro del rango de los char imprimibles */
    if (std::isprint(c))
        std::cout << "char: " << c << std::endl;
    else
        std::cout << "char is not displayable" << std::endl;
}

void ScalarConverter::convert(std::string number)
{
    int i = toInt(number);
    toFloat(number);
    toDouble(number);
    toChar(i);
}