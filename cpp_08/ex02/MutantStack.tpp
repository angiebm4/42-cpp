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

#include "MutantStack.hpp"

template    <typename T>
MutantStack<T>::MutantStack()
{
    std::cout << "MutantStack default costructor called" << std::endl;
}

template    <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "default constructor called" << std::endl;
}

template    <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &obj)
    :   std::stack<T>(obj) // llamamos al cosntructor copida de la clase base y delegamos la copia
{
    std::cout << "Copy constructor called" << std::endl;
}

template    <typename T>
MutantStack<T>&  MutantStack<T>::operator=(const MutantStack<T>& obj)
{
    std::cout << " Copy asigment operator called" << std::endl;
    if (this != &obj)
    {
        std::stack<T>::operator=(obj); // delegamos en el operador = de la clase base
    }
    return(*this);
}

/* c es el atributo protegido de std::stack que contiene el contenedor real deque<T>
    begin y end son metodos de deque<T>*/

template    <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template    <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}