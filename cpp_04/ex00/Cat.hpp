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

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat(void);
        Cat& operator=(const Cat& obj);
        Cat(const Cat &obj);
        
        void makeSound(void);
};

# endif