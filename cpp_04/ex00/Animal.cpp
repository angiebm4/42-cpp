/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:47:20 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/20 16:22:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    _type = "Exotic default";
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    _type = obj._type;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
    }
    return *this;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal making some animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return(_type);
}

void Animal::setType(std::string type)
{
    _type = type;
}