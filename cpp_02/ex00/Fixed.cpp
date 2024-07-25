/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:14 by angela            #+#    #+#             */
/*   Updated: 2024/07/25 12:53:49 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
    fp_number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) 
{
    fp_number = obj.fp_number;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) 
        fp_number = obj.fp_number;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fp_number);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << raw << std::endl;
}