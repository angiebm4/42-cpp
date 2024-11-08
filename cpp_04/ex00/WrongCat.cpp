/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:18:53 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/04 12:20:00 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj): WrongAnimal()
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    _type = obj._type;
}

WrongCat& WrongCat::operator=(const WrongCat& obj)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _type = obj._type;
    }
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "sssssshhh" << std::endl;
}
