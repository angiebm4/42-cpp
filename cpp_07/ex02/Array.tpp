/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:37:55 by abarrio-          #+#    #+#             */
/*   Updated: 2025/04/16 15:56:58 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

template <class Type> // class =   ? typename
Array<Type>::Array()
    :   _array(NULL),
        _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <class Type>
Array<Type>::Array(unsigned int n)
    :   _array(n),
        _size(n)
{
    std::cout << "Array constructor called" << std::endl;
}

template <class Type>
Array<Type>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
}

template <class Type>
Array<Type>& Array<Type>::operator=(const Array& obj)
{
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this = new Type();
        for(int i = 0; i < obj.getSize(); i++)
            this->_array[i] = new obj._array[i];
    }
}

template <class Type>
Array<Type>::Array(const Array &obj)
{
    std::cout << "Array copy constructor called" << std::endl;
    *this = obj;
}

template <class Type> 
Array<Type>& Array<Type>::operator[](unsigned int index)
{
    
}