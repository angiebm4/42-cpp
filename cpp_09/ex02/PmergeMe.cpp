/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/19 17:20:04 by abarrio-         ###   ########.fr       */
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
    :   _deque(obj._deque),
        _list(obj._list)
{

}

PmergeMe& PmergeMe::operator=(const  PmergeMe& obj)
{
    if (this != &obj)
    {
        this->_deque = obj._deque;
        this->_list = obj._list;
    }   
    return *this;
}

void printDeque(const std::deque<int>& d, const std::string& label = "")
{
    if (!label.empty())
        std::cout << label << ": ";

    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

void    PmergeMe::mergeInsertSortDeque(std::deque<int>& container)
{
    // Si solo tiene un elemento ya esta ordenado
    if (container.size() <= 1)
        return ;

    printDeque(container, "uwu ->");

    // Divide la secuencia en pares y ordena cada par
    std::deque<std::pair<int, int> >     pairs;
    std::deque<int>                     unpair;
    size_t i = 0;

    while (i < container.size())
    {
        if (i + 1 < container.size())
        {
            int a = container[i];
            int b = container[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
            unpair.push_back(container[i]);
        i += 2;
    }
    // separa los mayores de cada par (estos se ordenan recursivamente)

    std::deque<int> sorted;
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);
        
    mergeInsertSortDeque(sorted);

    // Insertar los menores uno a uno
    // Los menores se insertan uno a uno en el sitio correcto
    for (size_t i = 0; i < pairs.size(); ++i) {
        int toInsert = pairs[i].first;
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), toInsert);
        sorted.insert(pos, toInsert);
    }

    // Insertar el sobrante si había alguno
    // Si hay un elemento sin pareja tambien se inserta
    if (!unpair.empty()) {
        int last = unpair.front();
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
        sorted.insert(pos, last);
    }


    container = sorted;
    printDeque(container, "owo ->");
}

void PmergeMe::doS()
{
    printDeque(_deque, "Start deque -> ");

    clock_t start = clock();
    mergeInsertSortDeque(_deque);
    clock_t end = clock();

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time deque: " << time << " us" << std::endl;

    printDeque(_deque, "End deque -> ");
    
    start = clock();
    mergeInsertSortDeque(_deque);
    end = clock();

    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time list: " << time << " us" << std::endl;
}