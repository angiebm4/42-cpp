/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 17:40:00 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
# include <iostream>
# include <cstddef>

template <typename Type>
class    Array 
{
    private:
        Type* _array;  // Puntero al array dinamico
        unsigned int _size; //Tamaño del array 
        
    public:
        Array();
        Array(unsigned int);
        ~Array();
        Array& operator=(const Array& obj);
        Array(const Array &obj);

        Type& operator[](unsigned int index);
        const Type& operator[](unsigned int index) const; //para usar con arrays constantes

        unsigned int size() const; //este metodo devuelve el tamaño de array al no modificar el objeto se ppone como const
        
};

# include "Array.tpp"


#endif