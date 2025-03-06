/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 19:08:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <stdint.h>

/* uintptr_t es un tipo de dato entero sin signo que tiene el mismo tamaño
que un puntero, por lo que se puede almacenar un puntero dentro sin perder informacion*/
/* A value of any integral or enumeration type can be converted to a pointer type. A pointer converted to 
an integer of sufficient size and back to the same pointer type is guaranteed 
to have its original value, otherwise the resulting pointer cannot be dereferenced safely*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}


