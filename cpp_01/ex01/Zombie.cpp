/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:25:08 by angela            #+#    #+#             */
/*   Updated: 2024/05/08 11:30:22 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

/* CONTRUCTOR */

Zombie::Zombie()
{
    return ;
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " was 2 much rotten and died" << std::endl;
    // hay que eliminar los zombies
}

void    Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
    _name = name;
}