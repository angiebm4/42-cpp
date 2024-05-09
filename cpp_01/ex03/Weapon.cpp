/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:32 by angela            #+#    #+#             */
/*   Updated: 2024/05/09 13:54:34 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* CONSTRUCTOR */

Weapon::Weapon(void)
{

}

Weapon::Weapon(std::string type)
{
    _type = type;
}

/* DESTRUCTOR */

Weapon::~Weapon()
{

}

/* GETTER */

std::string Weapon::getType()
{
    return(_type);
}

/* SETTER */

void Weapon::setType(std::string type)
{
    _type = type;
}
