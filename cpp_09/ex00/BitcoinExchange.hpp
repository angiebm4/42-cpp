/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/13 14:24:44 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <stdexcept>
# include <fstream>
# include <string>
# include <ctime>
#include <cstdlib>

# define MIN_VALUE 0.0f
# define MAX_VALUE 1000.0f

class BitcoinExchange
{
    private:
        std::map<std::string, float>    dataBase;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &obj);
        BitcoinExchange operator=(const BitcoinExchange& obj);
        void    makeDataBase(const std::string& file);
        std::map<std::string, float>    getDataBase();
        void    exchangeData(std::string line);
        float   calculateNewRate(std::string date, float rate);
};

# endif