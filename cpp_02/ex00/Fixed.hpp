/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/05/27 18:28:42 by angela           ###   ########.fr       */
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
        Fixed(Fixed);
        ~Fixed(void);
        int getRawBits(void);
        void setRawBits(int const raw);
        
};
#endif