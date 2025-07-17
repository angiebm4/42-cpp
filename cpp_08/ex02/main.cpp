/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 10:42:44 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}

/*
    top: Devulve la referencia en el tope de la pila 
    push: Agrega un elemento al tope de la pila
    size: Devuleve cuantos elementos hay en la pila
    empty: Devuelve true si la pila esta vacia
    pop: Quita el elemento que esta en el tope de la pila; no devuleve el valor si queire
            saberlo tienes que hacer top antes de borrar
*/
/*
#include <iostream>
#include <string>
#include <list>
#include "MutantStack.hpp"

void testEntero()
{
    std::cout << "\n==================== TEST CON ENTEROS ====================\n";

    MutantStack<int> mstack;

    std::cout << "\nPush + Top + Pop + Size:\n";
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Top después de pop: " << mstack.top() << std::endl;
    std::cout << "Tamaño: " << mstack.size() << std::endl;

    mstack.push(40);
    mstack.push(50);
    mstack.push(60);

    std::cout << "\nIteración del stack:\n";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nConstructor de copia:\n";
    MutantStack<int> copia(mstack);
    for (MutantStack<int>::iterator it = copia.begin(); it != copia.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "\nOperador de asignación:\n";
    MutantStack<int> asignada;
    asignada = mstack;
    for (MutantStack<int>::iterator it = asignada.begin(); it != asignada.end(); ++it)
        std::cout << *it << std::endl;
}

void testStrings()
{
    std::cout << "\n==================== TEST CON STRINGS ====================\n";

    MutantStack<std::string> strStack;
    strStack.push("hola");
    strStack.push("mundo");
    strStack.push("desde");
    strStack.push("MutantStack");

    std::cout << "\nRecorrido con iteradores:\n";
    MutantStack<std::string>::iterator it = strStack.begin();
    MutantStack<std::string>::iterator ite = strStack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << "\nAsignación + recorrido:\n";
    MutantStack<std::string> otra;
    otra = strStack;
    for (MutantStack<std::string>::iterator it = otra.begin(); it != otra.end(); ++it)
        std::cout << *it << std::endl;
}

void testComparacionConList()
{
    std::cout << "\n==================== COMPARACIÓN CON std::list ====================\n";

    std::list<int> lista;
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);

    std::cout << "\nRecorrido de la lista:\n";
    for (std::list<int>::iterator it = lista.begin(); it != lista.end(); ++it)
        std::cout << *it << std::endl;
}

int main()
{
    testEntero();
    testStrings();
    testComparacionConList();

    std::cout << "\nTodas las pruebas completadas con éxito.\n";
    return 0;
}*/

/*
#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl;
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::list<int> s(mstack);
    return 0;
}*/