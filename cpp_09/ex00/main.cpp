/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 19:36:11 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <ctime>
#include "BitcoinExchange.hpp"

/* 
  - Un ifstream (input file stream) es una clase de la STL 
    que se usa para leer datos desde un archivo de texto.


    - El string tiene formato YYYY-MM-DD y mide 10 
    - La fecha es real desde 1900, y existe en el calendario
    - La fecha es del pasado o presente, no del futuro

    lower_bound(key)
    - Metodo que te devuelve un iterator que apunta
      al elemento cuya clave es = o inmediatamente
      mayor de la key que le pases
    
    it->first para acceder al primer valor
    it->second para acceder al segundo valor
    */



int main(int argc, char*argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    std::ifstream   file(argv[1]);
    
    if (!file.is_open())
    {
        std::cerr << "Error: " << argv[1] << " file, cant open." << std::endl;
        return 1;
    }

    try
    {
        std::string line;
        std::getline(file, line);

        if (line != "date | value")
            throw std::runtime_error("Invalid file Header");

        while (std::getline(file, line))
            exchange.exchangeData(line);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}