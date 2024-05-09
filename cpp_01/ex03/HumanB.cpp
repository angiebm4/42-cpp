/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:13:06 by angela            #+#    #+#             */
/*   Updated: 2024/05/09 14:39:26 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    _weapon = NULL;
    _name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
   _weapon = &weapon;
    _name = name;
}

HumanB::~HumanB()
{
    std::cout << "human b termino" << std::endl;
}

void    HumanB::attack()
{
    if (_weapon == NULL)
        std::cout << _name << " attacks with their hands" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}