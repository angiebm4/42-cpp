/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:00:34 by abarrio-          #+#    #+#             */
/*   Updated: 2025/03/03 01:43:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>

/* te complican la vida con c++11 es mucho mas simple ._. ya tiene sus propias
funciones que mandan el error correspondiente si falla el casteo */

void ScalarConverter::convert(std::string number)
{
    try 
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
            throw std::runtime_error("Error: long out of range");
        if (*endptr != '\0')
            throw std::runtime_error("Error: int convert fail");
        /* la funcion std::strtol devuelve un long para una correcta implementacion
            hay que chekear que la strng no se salga del valos de long y que luego el long
            este dentro de los limites del int para poderlo castear a int si perdidas de valor o desbordamientos*/
        if (intValue > INT_MAX || intValue < INT_MIN)
            throw std::runtime_error("Error: int out of range");
        int i = static_cast<int>(intValue);
        
        char* endptr2;
        errno = 0;
        float   f = std::strtof(number.c_str(), &endptr2);
        if (errno == ERANGE)
            throw std::runtime_error("Error: float out of range");
        if (*endptr2 != '\0')
            throw std::runtime_error("Error: float convert fail");

        char* endptr3;
        errno = 0;
        double  d = std::strtod(number.c_str(), &endprt3);
        if (errno == ERANGE)
            throw std::runtime_error("Error: double out of range");
        if (*endptr3 != '\0')
            throw std::runtime_error("Error: double convert fail");

        char    c = static_cast<char>(i);

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << std::endl;
        std::cout << "double: " << d << std::endl;
        /* verificar si c esta dentro del rango de los char imprimibles */
        if (std::isprint(c))
            std::cout << "char: " << c << std::endl;
        else
            std::cout << "char is not displayable" << std::endl;
    } 
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
