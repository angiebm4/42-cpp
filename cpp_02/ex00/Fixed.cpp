/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:14 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 10:55:55 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    fp_number = 0;
}

Fixed::Fixed(int fp_number)
{
    std::cout << "Parameterized constructor called" << std::endl;
    this->fp_number = fp_number;
}

/* CONSTRUCTOR DE COPIA */
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    fp_number = obj.getRawBits();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fp_number);
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        fp_number = obj.getRawBits();
    return *this; /* es el objeto que acabamos de cambiar devuelve la direccion del objeto que acabamos de modificar */
}

void Fixed::setRawBits(int const raw)
{
    std::cout << raw << std::endl;
}