/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gato.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:53 by abarrio-          #+#    #+#             */
/*   Updated: 2024/10/25 12:20:18 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    _type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
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

void Cat::makeSound(void)
{
    std::cout << "miau" << std::endl;
}
