/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:43:38 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 12:43:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain*  _brain;
    public:
        Dog();
        virtual ~Dog(void);
        Dog& operator=(const Dog& obj);
        Dog(const Dog &obj);
        
        std::string getIdea(int) const;
        void setIdea(std::string, int) const;
        void makeSound(void) const;
};

# endif