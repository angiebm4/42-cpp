/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 15:04:12 by abarrio-         ###   ########.fr       */
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

        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;
        
};
    
std::ostream& operator<<(std::ostream &COUT, const Fixed &obj);
#endif