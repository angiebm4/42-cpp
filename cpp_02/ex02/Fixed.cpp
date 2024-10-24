/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:14 by angela            #+#    #+#             */
/*   Updated: 2024/10/24 12:18:19 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    fp_number = 0;
}

Fixed::Fixed(const int fp_number)
{
    std::cout << "Int constructor called" << std::endl;
    this->fp_number = fp_number << Fractional_Bits;
}

Fixed::Fixed(const float fp_number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fp_number = roundf(fp_number * (1 << Fractional_Bits));
}

/* CONSTRUCTOR DE COPIA */
Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    fp_number = obj.fp_number;
}

/* copy Asigment operator */
Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        fp_number = obj.getRawBits();
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

/* Comparison operators */

bool Fixed::operator>(const Fixed& obj)
{
    return (this->fp_number > obj.fp_number);
}

bool Fixed::operator<(const Fixed& obj)
{
    return (this->fp_number < obj.fp_number);
}

bool Fixed::operator>=(const Fixed& obj)
{
    return (this->toFloat() >= obj.fp_number);
}

bool Fixed::operator<=(const Fixed& obj)
{
    return (this->fp_number <= obj.fp_number);
}

bool Fixed::operator==(const Fixed& obj)
{
    return (this->fp_number == obj.fp_number);
}

bool Fixed::operator!=(const Fixed& obj)
{
    return (this->fp_number != obj.fp_number);
}

/* Arithmetic operators */

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed   Result(this->toFloat() + obj.toFloat());

    return (Result);
}

Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed   Result(this->toFloat() - obj.toFloat());

    return (Result);
}

Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed   Result(this->toFloat() * obj.toFloat());

    return (Result);
}

Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed   Result(this->toFloat() / obj.toFloat());

    return (Result);
}

/* Increment/decrement operators */

Fixed Fixed::operator++(int) /* i++ */
{
    Fixed result = *this;

    this->fp_number++;

    return (result);
}

Fixed& Fixed::operator++(void) /* ++i */
{
    this->fp_number++;
    return (*this);
}

Fixed Fixed::operator--(int) /* i-- */
{
    Fixed result = *this;

    this->fp_number--;

    return (result);
}

Fixed& Fixed::operator--(void) /* --i */
{
    this->fp_number--;
    return (*this);
}


/*-----------------------------------------------------------------------*/

/* convierte un int en float dividiendo ntr  2^Fractional_Bits*/
float Fixed::toFloat(void) const
{
    return (float)fp_number / (1 << Fractional_Bits);
}

/* convirte de float a int moviendo los bits a la derecha por fractional_bits*/
int Fixed::toInt(void) const
{
    return fp_number >> Fractional_Bits;
}

void Fixed::setRawBits(int const raw)
{
    this->fp_number = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fp_number);
}

Fixed& Fixed::min(Fixed& fixed_1, Fixed& fixed_2)
{
    if (fixed_1.toFloat() < fixed_2.toFloat())
        return (fixed_1);
    return (fixed_2);
}

const Fixed& Fixed::min(const Fixed& fixed_1, const Fixed& fixed_2)
{
    if (fixed_1.toFloat() < fixed_2.toFloat())
        return (fixed_1);
    return (fixed_2);
}

Fixed& Fixed::max(Fixed& fixed_1, Fixed& fixed_2)
{
    if (fixed_1.toFloat() > fixed_2.toFloat())
        return (fixed_1);
    return (fixed_2);
}

const Fixed& Fixed::max(const Fixed& fixed_1, const Fixed& fixed_2)
{
    if (fixed_1.toFloat() > fixed_2.toFloat())
        return (fixed_1);
    return (fixed_2);
}

std::ostream& operator<<(std::ostream &COUT, const Fixed &obj)
{
    COUT << obj.toFloat();
    return COUT;
}