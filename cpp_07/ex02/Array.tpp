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

template <class Type>  
Array<Type>::Array()
    :   _array(NULL),
        _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <class Type>
Array<Type>::Array(unsigned int n)
    :   _array(new Type[n]),
        _size(n)
{
    std::cout << "Array constructor called" << std::endl;
}

template <class Type>
Array<Type>::~Array()
{
    std::cout << "Array destructor called" << std::endl;
    delete[] _array;
}

template <class Type>
Array<Type>& Array<Type>::operator=(const Array& obj)
{
    std::cout << "Array copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        delete[] _array;

        _size = obj._size;

        _array = new Type[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = obj._array[i];
    }

    return (*this);
}

template <class Type>
Array<Type>::Array(const Array &obj)
    :   _size(0),
        _array(NULL)
{
    std::cout << "Array copy constructor called" << std::endl;
    *this = obj;
}

template <class Type> 
Type& Array<Type>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return(_array[index]);
}

template <class Type> 
const Type& Array<Type>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of bounds");
    return(_array[index]);
}

template <class Type> 
unsigned int Array<Type>::size() const
{
    return(_size);
}