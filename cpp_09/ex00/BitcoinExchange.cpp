/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/30 11:23:28 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
    int day     = std::atoi(date.substr(8,2).c_str());

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

void isValidRate(const std::string& str, float& outValue, int flag)
{
    outValue = atof(str.c_str());

    if (flag == 0 && outValue < MIN_VALUE)
        throw std::runtime_error("not a positive number.");
    else if (flag == 0 && outValue > MAX_VALUE)
        throw std::runtime_error("too large a number.");
    else if (flag == 1 && outValue < MIN_VALUE)
        throw std::runtime_error("negative rate, in data base");
    else
        return ;
}

void    BitcoinExchange::makeDataBase(const std::string& fileName)
{
    std::ifstream   file(fileName.c_str());

    if (!file.is_open())
        throw std::runtime_error("data.csv file, cant open");

    std::string line;
    
    std::getline(file, line);

    if (line != "date,exchange_rate")
        throw std::runtime_error("Invalid file Header");

    while(std::getline(file, line))
    {
        float rate = 0;
        size_t pos = line.find(',');

        if (pos == std::string::npos)
            throw std::runtime_error("There is not a separator in line, in data base");

        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);

        isValidRate(rateStr, rate, 1);

        if (!isValidDate(date))
            throw std::runtime_error("Invalid date, in data base");

        dataBase[date] = rate;
    }
}

BitcoinExchange::BitcoinExchange() 
{
    makeDataBase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
    :   dataBase(obj.dataBase)  {}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    if (this != &obj)
        this->dataBase = obj.dataBase;
    return *this;
}

std::map<std::string, float> BitcoinExchange::getDataBase()
{
    return dataBase;
}
/*
    - Si la clave exacta existe → usar ese valor.
    - Si no existe → usar la clave anterior más cercana 
        (la más grande que sea menor que date).
*/

float   BitcoinExchange::calculateNewRate(std::string date, float rate)
{
    float newRate;
    std::map<std::string, float>::iterator it = dataBase.lower_bound(date);

    // Clave exacta existe
    if (it != dataBase.end() && it->first == date)
        newRate = it->second;
    // Clave
    else if (it == dataBase.begin())
        newRate = it->second;
    // Clave no existe
    else
    {
        --it;
        newRate = it->second;
    }

    return rate * newRate;
}

std::string removeSpaces(const std::string& str)
{
    std::string result;

    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
            result += str[i];
    }
    return result;
}

void    BitcoinExchange::exchangeData(const std::string line)
{
    try
    {
        float rate = 0;
        size_t pos = line.find('|');

        if (pos == std::string::npos)
            throw std::runtime_error("There is not a separator in line");

        std::string date = line.substr(0, pos - 1);
        std::string rateStr = line.substr(pos + 2);

        isValidRate(rateStr, rate, 0);

        if (!isValidDate(date))
            throw std::runtime_error("bad input => " + date);

        float newRate = calculateNewRate(date, rate);

        std::cout << date << " => " << rate << " = " << newRate << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
}
