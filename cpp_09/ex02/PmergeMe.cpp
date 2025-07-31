/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 13:36:12 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm> 
#include <vector>
#include <set>

// iss = Input String Stream

// Genera la secuencia Jacobsthal hasta el tamaño n
std::vector<size_t> generateJacobsthal(size_t n)
{
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);

    // Generar hasta superar n
    while (true)
    {
        size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
        if (next >= n)
            break;
        jacob.push_back(next);
    }

    // Quitamos el primer 0
    jacob.erase(jacob.begin());

    return jacob;
}

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

void printDeque(const std::deque<int>& d, const std::string& msg = "")
{
    if (!msg.empty())
        std::cout << msg << ": ";

    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& containerD)
{
    if (containerD.size() <= 1)
        return;

    // 1. Dividir en pares
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> unpair;
    size_t i = 0;

    while (i < containerD.size())
    {
        if (i + 1 < containerD.size())
        {
            int a = containerD[i];
            int b = containerD[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        }
        else
            unpair.push_back(containerD[i]);
        i += 2;
    }

    // 2. Extraer los mayores y ordenarlos recursivamente
    std::deque<int> sorted;
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);

    mergeInsertSortDeque(sorted);

    // 3. Insertar los menores en orden Jacobsthal
    std::vector<size_t> jacob = generateJacobsthal(pairs.size());
    std::set<size_t> inserted; // para evitar duplicados

    // Inserción siguiendo Jacobsthal
    for (size_t k = 0; k < jacob.size(); ++k)
    {
        size_t index = jacob[k];
        if (index < pairs.size() && inserted.find(index) == inserted.end())
        {
            int toInsert = pairs[index].first;
            std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), toInsert);
            sorted.insert(pos, toInsert);
            inserted.insert(index);
        }
    }

    // Inserción de los restantes no cubiertos por Jacobsthal
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (inserted.find(i) == inserted.end())
        {
            int toInsert = pairs[i].first;
            std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), toInsert);
            sorted.insert(pos, toInsert);
            inserted.insert(i);
        }
    }

    // 4. Insertar el sobrante si había alguno
    if (!unpair.empty())
    {
        int last = unpair.front();
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
        sorted.insert(pos, last);
    }

    containerD = sorted;
}

void printList(const std::list<int>& l, const std::string& msg = "")
{
    if (!msg.empty())
        std::cout << msg << ": ";

    for (std::list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

void PmergeMe::insertInSortedList(std::list<int>& sorted, int value)
{
    std::list<int>::iterator it = sorted.begin();
    while (it != sorted.end() && *it < value)
        ++it;

    sorted.insert(it, value);
}

void PmergeMe::mergeInsertSortList(std::list<int>& containerL)
{
    // 1. Caso base
    if (containerL.size() <= 1)
        return;

    // 2. Dividir en pares y ordenarlos internamente
    std::list<std::pair<int, int> > pairs;
    std::list<int> unpaired;

    std::list<int>::iterator it = containerL.begin();

    while (it != containerL.end())
    {
        int a = *it;
        ++it;

        if (it != containerL.end()) 
        {
            int b = *it;
            ++it;

            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        } 
        else
            unpaired.push_back(a); // elemento sin pareja
    }

    // 3. Extraer mayores y ordenarlos recursivamente
    std::list<int> sorted;

    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        sorted.push_back(pit->second);

    mergeInsertSortList(sorted); // recursivo sobre los máximos

    // 4. Inserción con Jacobsthal
    std::vector<size_t> jacob = generateJacobsthal(pairs.size());

    // Convertir pairs a vector para indexar fácilmente
    std::vector<std::pair<int,int> > pairsVec(pairs.begin(), pairs.end());
    std::set<size_t> inserted; // para controlar duplicados

    // Insertar siguiendo la secuencia Jacobsthal
    for (size_t k = 0; k < jacob.size(); ++k)
    {
        size_t index = jacob[k];
        if (index < pairsVec.size() && inserted.find(index) == inserted.end())
        {
            insertInSortedList(sorted, pairsVec[index].first);
            inserted.insert(index);
        }
    }

    // Insertar los menores que no estaban en Jacobsthal
    for (size_t i = 0; i < pairsVec.size(); ++i)
    {
        if (inserted.find(i) == inserted.end())
        {
            insertInSortedList(sorted, pairsVec[i].first);
            inserted.insert(i);
        }
    }

    // 5. Insertar sobrante si lo hay
    if (!unpaired.empty())
        insertInSortedList(sorted, unpaired.front());

    // 6. Reemplazar la lista original
    containerL = sorted;
}

void PmergeMe::doS()
{
    printDeque(_deque, "Start deque -> ");

    clock_t start = clock();
    mergeInsertSortDeque(_deque);
    clock_t end = clock();
    
    printDeque(_deque, "End deque -> ");

    double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time deque: " << time << " us" << std::endl;

    printList(_list, "Start list -> ");

    start = clock();
    mergeInsertSortList(_list);
    end = clock();

    printList(_list, "End list -> ");

    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time list: " << time << " us" << std::endl;
}