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

bool    isFormatOk(const std::string& date)
{
    if (date.length() != 10)
        return false;
    for(int i = 0; i < date.length(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else if (!isdigit(date[i]))
            return false;
    }
    return true;
}

bool    isValidDate(const std::string& date)
{
    if (isFormatOk(date) == false)
        return false;
        
    int year    = std::atoi(date.substr(0,4).c_str());
    int month   = std::atoi(date.substr(5,2).c_str());
    int day     = std::atoi(date.substr(8, 2).c_str());

    std::tm tm  = {};
    tm.tm_year  = year - 1900;  //Años desde 1900
    tm.tm_mon   = month - 1;    // Mes del 0 al 11 
    tm.tm_mday  = day;

    std::time_t time = std::mktime(&tm);

    if (time == -1)
        return false;   // No es una fecha valida
    if (tm.tm_year != year - 1900 || tm.tm_mon != month - 1 || tm.tm_mday != day)
        return false;   // mktime ha corregido la fecha => no es válida
                        //checkeamos que siga siendo la misma fecha mktime ajusta la fecha a algo coherente
    if (time > std::time(0))
        return false;   // Mira si la fecha es del futuro
        
    return true;
}

void    parseFile(BitcoinExchange& exchange, std::ifstream& file)
{
    std::string line;

    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error: Invalid file Header");

    while(std::getline(file, line))
    {

        if (isValidDate(date) == false)
            throw std::runtime_error("Error: Invalid date");
    }
}

int main(int argc, char*argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: Only one argument accepted" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    std::ifstream   file(argv[1]);
    std::ifstream   fileExchange("exchangeFile.csv");

    if (!file.is_open())
    {
        std::cerr << "Error: " << argv[1] << " file, cant open" << std::endl;
    }


    try
    {
        parseFile(exchange, file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}