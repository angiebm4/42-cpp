/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:18:12 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 10:46:57 by abarrio-         ###   ########.fr       */
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
        Fixed(int);

        /* copy constructor */
        /* Se usa cuando creas un objeto totalmente nuevo basado en otro objeto*/
        /* pasas la direccion de memoria del objeto original lo pones const para evitar modificarlo por error*/
        /* no se puede pasar el parametro por valor ya que se crea una copia del objeto y para eso hace falta un copy constructor por lo que se crearia un bucle raro*/
        Fixed(const Fixed &obj);

        /* copy asigment operator */
        /* Se usa cuando quieres modificar los valores de un objeto ya creado basado en otro objeto*/
        Fixed& operator=(const Fixed& obj);

        ~Fixed(void);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        
};
#endif