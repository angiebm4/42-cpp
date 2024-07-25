/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/07/25 12:50:00 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int fp_number;
        static const int   Fractional_Bits = 8;

    public:
        Fixed(void);

        /* copy constructor */
        Fixed(const Fixed &obj);

        /* copy asigment operator */
        Fixed& operator=(const Fixed& obj);

        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        
};
#endif