/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:16:46 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 10:44:30 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a); /* b(a) se crea automaticamente o lo puedes crear tu, constructor de copia */
    /* Fixed b = a se llama al constructor de copia no al asigment operator por q es un nuevo objeto*/
    Fixed c;

    /* para hacer un copy asigment operator el objeto tiene que existir*/
    c = b;
    /* c.operator=(b) es lo mismo que lo de arriba*/

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    // Fixed z(42);
    // c = z;

    // std::cout << z.getRawBits() << std::endl;
    // std::cout << c.getRawBits() << std::endl;
    
    return 0;
}
