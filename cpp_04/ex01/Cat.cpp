/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:53 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/19 19:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    _Brain = new Brain();
    _type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete(_Brain);
}

Cat::Cat(const Cat &obj): Animal()
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    _type = obj._type;
}

Cat& Cat::operator=(const Cat& obj)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
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
    return(_Brain->getIdea(index));
}

void Cat::setIdea(std::string idea, int index) const
{
    _Brain->setIdea(idea, index);
}
