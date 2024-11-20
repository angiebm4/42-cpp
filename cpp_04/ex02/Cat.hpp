/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:16:17 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/20 16:44:53 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain*  _brain;
    public:
        Cat();
        virtual ~Cat(void);
        Cat& operator=(const Cat& obj);
        Cat(const Cat &obj);
        
        void makeSound(void) const;
        std::string getIdea(int) const;
        void setIdea(std::string, int) const;
};

# endif