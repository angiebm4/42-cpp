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
    _type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &obj): Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    _type = obj._type;
}

Dog& Dog::operator=(const Dog& obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
    }
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "guau" << std::endl;
}