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

#include "Gato.hpp"

Gato::Gato()
{
    std::cout << "Gato default constructor called" << std::endl;
    type = "Exotic default";
}

Gato::~Gato(void)
{
    std::cout << "Gato destructor called" << std::endl;
}

Gato::Gato(const Gato &obj)
{
    std::cout << "Gato Copy Constructor called" << std::endl;
    type = obj.type;
}
Gato& Gato::operator=(const Gato& obj)
{
    std::cout << "Gato Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
}
