/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:43:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/27 12:43:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
    _type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete(_brain);
}

Dog::Dog(const Dog &obj): Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    _type = obj._type;
    this->_brain = new Brain(*obj._brain);
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->_type = obj._type;
        this->_brain = new Brain(*obj._brain);
    }
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "guau" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    std::cout << "Dog idea nº " << index << " is: ";
    return(_brain->getIdea(index));
}

void Dog::setIdea(std::string idea, int index) const
{
    _brain->setIdea(idea, index);
}
