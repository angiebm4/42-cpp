/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 13:02:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fp_number;
        float   fp_fnumber;
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

        int getInt(void) const;
        void setInt(int const nb);

        float getFloat(void) const;
        void setFloat(float const nb);

        float toFloat( void ) const;
        int toInt( void ) const;
        
};
    
std::ostream& operator<<(std::ostream &COUT, const Fixed &obj);
#endif