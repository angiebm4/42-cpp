/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter3.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:07:27 by abarrio-          #+#    #+#             */
/*   Updated: 2025/05/02 15:07:27 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cctype>
#include <iomanip>

// value != value → NaN
// value >= DBL_MAX || value <= -DBL_MAX → Infinito

void toFloat(double value)
{
    if ((errno == ERANGE || (value > FLT_MAX || value < -FLT_MAX))
         && (value < DBL_MAX && value > -DBL_MAX))
        std::cout << "Error: float out of range" << std::endl;
    else
    {
        float f = static_cast<float>(value);
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
}

void toDouble(double value)
{
    if (errno == ERANGE)
        std::cout << "Error: double out of range" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void toInt(double value)
{
    if (value != value || value >= DBL_MAX || value <= -DBL_MAX || value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void toChar(double value)
{
   if (value != value || value >= DBL_MAX || value <= -DBL_MAX || value < 0 ||
        value > 255 || value != static_cast<int>(value))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);

    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: not displayable" << std::endl;
}

Type detectType(const std::string& number)
{
    if (number.length() == 1 && std::isprint(number[0]) && !std::isdigit(number[0]))
        return TYPE_CHAR;

    if (number == "nan" || number == "nanf" ||
        number == "+inf" || number == "-inf" ||
        number == "inf" || number == "+inff" ||
        number == "-inff" || number == "inff")
        return TYPE_SPECIAL;
    
    char* endptr; /* para verificar si la conversion fallo o fue parcial */
    /*  errno es una variable global ya creada, dentro de la biblioteca
        estandar, que se cambia de valor en caso de
        que una funcion de dicha biblioteca falle ,
        por ejemplo detecte errores como ERANGE
        hay que resetearlo siempre antes de usarlo */
    errno = 0; /* para verificar si esta fura de rango con ERANGE */
    std::strtod(number.c_str(), &endptr);

    if (*endptr == 'f' && *(endptr + 1) == '\0')
        return TYPE_FLOAT;

    if (*endptr != '\0')
        return TYPE_INVALID;

    size_t i = 0;
    
    if (number[i] == '+' || number[i] == '-')
        i++;

    bool hasDot = false;

    for (; i < number.length(); ++i)
    {
        if (number[i] == '.')
        {
            hasDot = true;
            continue;
        }
        if (!std::isdigit(number[i]))
            return TYPE_INVALID; 
    }
    if (hasDot)
        return TYPE_DOUBLE;

    return TYPE_INT;
}

void ScalarConverter::convert(const std::string &number)
{
    Type type = detectType(number);
    
    double value = 0;

    switch (type)
    {
        case TYPE_CHAR:
            value = number[0];
            break;
        
        case TYPE_DOUBLE:
        case TYPE_FLOAT:
        case TYPE_SPECIAL:
        case TYPE_INT:
            errno = 0;
            value = std::strtod(number.c_str(), NULL);
            break;

        case TYPE_INVALID:
            std::cout << "Error: invalid input" << std::endl;
            return;
    }
    toFloat(value);
    toDouble(value);
    toInt(value);
    toChar(value);
}