/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:26:44 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/19 19:49:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal(void);
        Animal& operator=(const Animal& obj);
        Animal(const Animal &obj);
        
        virtual void makeSound(void) const;

        virtual std::string getIdea(int index) const = 0;
        virtual void setIdea(std::string, int) const = 0;
        std::string getType(void) const;
        void setType(std::string);
        
};

# endif