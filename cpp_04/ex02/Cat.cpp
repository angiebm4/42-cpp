/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:53 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/20 17:01:29 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
    _type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat &obj): Animal()
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    this->_type = obj._type;
    this->_brain = new Brain(*obj._brain);
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->_type = obj._type;
        this->_brain = new Brain(*obj._brain);
    }
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "miau" << std::endl;
}

std::string Cat::getIdea(int index) const
{
    std::cout << "cat idea nº " << index << " is: ";
    return(_brain->getIdea(index));
}

void Cat::setIdea(std::string idea, int index) const
{
    _brain->setIdea(idea, index);
}
