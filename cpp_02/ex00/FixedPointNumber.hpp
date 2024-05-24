/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/05/24 12:22:12 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_POINT_NUMBER_HPP
# define FIXED_POINT_NUMBER_HPP

class FixedPointNumber
{
    private:
        int fp_number;
        const int   Fractional_Bits = 8;
    public:
        FixedPointNumber(void);
        ~FixedPointNumber(void);
        int getRawBits(void);
        void setRawBits(int const raw);
        
};
#endif