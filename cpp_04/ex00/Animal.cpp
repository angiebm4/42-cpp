/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:47:20 by abarrio-          #+#    #+#             */
/*   Updated: 2024/10/25 12:23:05 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
    type = "Exotic default";
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy Constructor called" << std::endl;
    type = obj.type;
}

Animal& Animal::operator=(const Animal& obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}



