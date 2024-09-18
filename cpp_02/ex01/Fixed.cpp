/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:14 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 13:03:37 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    fp_number = 0;
    fp_fnumber = 0.0;
}

Fixed::Fixed(const int fp_number)
{
    std::cout << "Int constructor called" << std::endl;
    this->fp_number = fp_number;
    this->fp_fnumber = 0.0;
}

Fixed::Fixed(const float fp_fnumber)
{
    std::cout << "Float constructor called" << std::endl;
    this->fp_fnumber = fp_fnumber;
    this->fp_number = 0;
}

/* CONSTRUCTOR DE COPIA */
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    fp_number = obj.getInt();
    fp_fnumber = obj.getFloat();
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/* copy Asigment operator */
Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        fp_number = obj.getInt();
        fp_fnumber = obj.getFloat();
    }
    return *this;
}

std::ostream& operator<<(std::ostream &COUT, const Fixed &obj)
{
    if (obj.getInt() != 0)
        COUT << obj.getInt() << std::endl;
    else if (obj.getFloat() != 0)
        COUT << obj.getFloat() << std::endl;
    return COUT;
}

float Fixed::toFloat( void ) const
{
    return 1.1;
}

int Fixed::toInt( void ) const
{
    return 1;
}

int Fixed::getInt(void) const
{
    std::cout << "getInt member function called" << std::endl;
    return (fp_number);
}

void Fixed::setInt(int const nb)
{
    std::cout << nb << std::endl;
}

float Fixed::getFloat(void) const
{
    std::cout << "getFloat member function called" << std::endl;
    return (fp_fnumber);
}

void Fixed::setFloat(float const nb)
{
    std::cout << nb << std::endl;
}