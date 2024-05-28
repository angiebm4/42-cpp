/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:14 by angela            #+#    #+#             */
/*   Updated: 2024/05/27 18:27:49 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed new) 
{
    
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;

}
void Fixed::setRawBits(int const raw)
{
    std::cout << "" << std::endl;
    
}