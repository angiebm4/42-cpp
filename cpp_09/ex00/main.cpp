/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 17:33:54 by abarrio-         ###   ########.fr       */
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
    */



int main(int argc, char*argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Only one argument accepted" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    std::ifstream   file(argv[1]);
    

    if (!file.is_open())
    {
        std::cerr << "Error: " << argv[1] << " file, cant open" << std::endl;
        return 1;
    }




    try
    {
        

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}