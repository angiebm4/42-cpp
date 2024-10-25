/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gato.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:17 by abarrio-          #+#    #+#             */
/*   Updated: 2024/10/25 12:18:43 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GATO_HPP
# define GATO_HPP

# include <iostream>
# include "Animal.hpp"

class Gato : public Animal
{
    public:
        Gato();
        virtual ~Gato(void);
        Gato& operator=(const Gato& obj);
        Gato(const Gato &obj);
        
        virtual void makeSound(void);
};


# endif