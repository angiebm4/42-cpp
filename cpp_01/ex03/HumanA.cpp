/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:07:42 by angela            #+#    #+#             */
/*   Updated: 2024/05/09 14:18:01 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    _weapon = weapon.getType();
    _name = name;
}

HumanA::~HumanA()
{
    std::cout << "human a termino" << std::endl;
}

void    HumanA::attack()
{
    std::cout << _name << " attcks with their " << _weapon.getType() << std::endl;
}
