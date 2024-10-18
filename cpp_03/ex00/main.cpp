/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:37 by angela            #+#    #+#             */
/*   Updated: 2024/10/18 12:46:06 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main(void)
{
    ClapTrap    angie("angie");
    
    angie.attack("her sister");
    angie.beRepaired(20);
    angie.takeDamage(100);
    angie.beRepaired(5);
    
    ClapTrap    sofia("sofia");
    sofia.attack("uwu angie uwur");

    sofia.beRepaired(20);
    sofia.takeDamage(100);
    sofia.beRepaired(5);

    sofia = angie;

    sofia.attack("uwu angie uwur");

    sofia.beRepaired(200);
    sofia.takeDamage(100);
    sofia.beRepaired(5);
    
}