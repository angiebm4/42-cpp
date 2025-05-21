/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/21 13:10:09 by abarrio-         ###   ########.fr       */
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

void printDeque(const std::deque<int>& d, const std::string& msg = "")
{
    if (!msg.empty())
        std::cout << msg << ": ";

    for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}



void    PmergeMe::mergeInsertSortDeque(std::deque<int>& containerD)
{
    // Si solo tiene un elemento ya esta ordenado
    if (containerD.size() <= 1)
        return ;

    // printDeque(containerD, "uwu ->");

    // Divide la secuencia en pares y ordena cada par
    std::deque<std::pair<int, int> >     pairs;
    std::deque<int>                     unpair;
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
    // separa los mayores de cada par (estos se ordenan recursivamente)

    std::deque<int> sorted;
    for (size_t i = 0; i < pairs.size(); ++i)
        sorted.push_back(pairs[i].second);
        
    mergeInsertSortDeque(sorted);

    // Insertar los menores uno a uno
    // Los menores se insertan uno a uno en el sitio correcto
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        int toInsert = pairs[i].first;
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), toInsert);
        sorted.insert(pos, toInsert);
    }

    // Insertar el sobrante si había alguno
    // Si hay un elemento sin pareja tambien se inserta
    if (!unpair.empty()) 
    {
        int last = unpair.front();
        std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), last);
        sorted.insert(pos, last);
    }


    containerD = sorted;
    //printDeque(containerD, "owo ->");
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

    // 4. Insertar menores uno a uno
    for (std::list<std::pair<int, int> >::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
        insertInSortedList(sorted, pit->first);

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