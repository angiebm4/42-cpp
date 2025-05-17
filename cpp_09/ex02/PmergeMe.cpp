/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/17 19:53:09 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm> 

// iss = Input String Stream

bool checkduplicateNb(const std::list<int>& list, int number)
{
    if (std::find(list.begin(), list.end(), number) != list.end()) 
        return true;
    return false;
}

void    PmergeMe::initContainers(char* argv[])
{
    int i = 1;
    
    while (argv[i])
    {
        std::string str(argv[i]);

        for (size_t j = 0; j < str.size(); ++j) 
        {
            if (!std::isdigit(str[j])) 
            {
                std::cerr << "Error: invalid argument (non-digit)" << std::endl;
                exit(1);
            }
        }
        
        std::istringstream iss(str);
        int number;
        iss >> number;

        // Falló la conversión o es negativo o había caracteres extra
        if (iss.fail() || number < 0 || !iss.eof())
        {
            std::cerr << "Error: invalid argument" << std::endl;
            exit (1);
        }

        if (checkduplicateNb(_list, number))
        {
            std::cerr << "Error: duplicate number" << std::endl;
            exit(1);
        }
        
        _list.push_back(number);
        _deque.push_back(number);
        ++i;

    }

}

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(char* argv[])
{
    initContainers(argv);
}

PmergeMe::~PmergeMe()
{

}
PmergeMe::PmergeMe(const  PmergeMe &obj)
{

}

PmergeMe& PmergeMe::operator=(const  PmergeMe& obj)
{
    if (this != &obj)
    {
    }   
    return *this;
}