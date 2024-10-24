/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/10/24 12:14:11 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    /* Only the fp_number is used to store the 
    fixed-point number, while Fractional_Bits defines
     how many bits are for the fractional part.*/
    private:
        int fp_number;
        static const int   Fractional_Bits = 8;

    public:
        Fixed(void);
        Fixed(const int);
        Fixed(const float);

        /* copy constructor */
        Fixed(const Fixed &obj);

        /* copy asigment operator */
        Fixed& operator=(const Fixed& obj);

        /* Comparison operators */
        bool operator>(const Fixed& obj);
        bool operator<(const Fixed& obj);
        bool operator>=(const Fixed& obj);
        bool operator<=(const Fixed& obj);
        bool operator==(const Fixed& obj);
        bool operator!=(const Fixed& obj);

        /* Arithmetic operators */
        Fixed operator+(const Fixed& obj);
        Fixed operator-(const Fixed& obj);
        Fixed operator*(const Fixed& obj);
        Fixed operator/(const Fixed& obj);

        /* Increment/decrement operators */
        Fixed operator++(int); /* i++ */
        Fixed& operator++(void); /* ++i */
        Fixed operator--(int); /* i-- */
        Fixed& operator--(void); /* --i */

        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed&, Fixed&);
        static const Fixed& min(const Fixed&, const Fixed&);
        static Fixed& max(Fixed&, Fixed&);
        static const Fixed& max(const Fixed&, const Fixed&);

};
/* Al sobrecargar este operador permite que puedas imprimir directamente una clase */
/* utilizando la salida estandar COUT llamamos a tofloat para que sea el numero */
/* de punto flotante casteado a float el que se imprime */
std::ostream& operator<<(std::ostream &COUT, const Fixed &obj);
#endif