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

void toFloat(double value)
{
    if ((errno == ERANGE || (value > FLT_MAX || value < -FLT_MAX)) && !std::isinf(value) )
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
    if (value > INT_MAX || value < INT_MIN || std::isnan(value) || std::isinf(value) || value != static_cast<int>(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void toChar(double value)
{
    if (value < 0 || value > 255 || std::isnan(value) || std::isinf(value) || value != static_cast<int>(value))
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

void ScalarConverter::convert(const std::string &number)
{
    char* endptr;
    errno = 0;
    double value = std::strtod(number.c_str(), &endptr);
    
    if (*endptr != '\0' && std::string(endptr) != "f")
    {
        std::cout << "Error: invalid input" << std::endl;
        return;
    }
    
    toFloat(value);
    toDouble(value);
    toInt(value);
    toChar(value);
}

