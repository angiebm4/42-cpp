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
    _Brain = new Brain();
    _type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete(_Brain);
}

Dog::Dog(const Dog &obj): Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    _type = obj._type;
    _Brain = new Brain();
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
        _Brain = new Brain();
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
    return(_Brain->getIdea(index));
}

void Dog::setIdea(std::string idea, int index) const
{
    _Brain->setIdea(idea, index);
}
