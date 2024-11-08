/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:50:55 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/04 12:16:32 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    _type = "Exotic not animal default";
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
    _type = obj._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
    }
    return *this;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal making some not animal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return(_type);
}

void WrongAnimal::setType(std::string type)
{
    _type = type;
}