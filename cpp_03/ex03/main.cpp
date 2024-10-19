/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:37 by angela            #+#    #+#             */
/*   Updated: 2024/10/19 19:56:54 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main(void)
{
    ClapTrap    angie("angie");
    
    angie.attack("her sister");
    angie.beRepaired(20);
    angie.takeDamage(100);
    angie.beRepaired(5);
    
    FragTrap    sofia("sofia");
    
    sofia.attack("uwu angie");
    sofia.takeDamage(10);
    sofia.beRepaired(20);
    sofia.beRepaired(5);
    sofia.highFivesGuys();
    
    return (0);
    
}