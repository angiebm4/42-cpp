/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:53 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/15 09:51:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    _Brain = new Brain();
    _type = "Cat";
    setIdeaCat("uwu", 2);
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

std::string Cat::getIdeaCat(int index) const
{
    return(_Brain->getIdea(index));
}

void Cat::setIdeaCat(std::string idea, int index)
{
    _Brain->setIdea(idea, index);
}
