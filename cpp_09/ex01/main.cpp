/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 12:03:14 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

/*
std::stack para manejar los operandos.

std::istringstream para dividir el input (#include <sstream>).

std::cerr << "Error" << std::endl; para errores.

std::isdigit() para comprobar si un token es número.

std::string y std::stringstream para parsear.

*/

/* Si es número (isdigit): lo agrega a la pila.

Si es operador (+, -, *, /): aplica la operación.

Si es algo inválido: muestra error y termina.*/

int main(int argc, char*argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Please enter only one argument with the operation you want to do" << std::endl;
        return 1;
    }

    std::string input = argv[1];
    std::istringstream stream(input);
    std::string token;
    RPN    container;

    while (stream >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
            container.addNb(token);
        else if (token == "+" || token == "-" || token == "*" || token == "/")
            container.applyOperator(token);
        else
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    container.checkStack();
    return 0;
}