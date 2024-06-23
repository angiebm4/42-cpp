/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:40 by angela            #+#    #+#             */
/*   Updated: 2024/06/23 16:22:31 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _health = 10;
    _energy = 5;
    _aaDamage = 0;
    std::cout << "ClapTrap is boorn us a guy called " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << _name << " die" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energy > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target <<
             ", causing " << _aaDamage << " points of damage!!" << std::endl;
        this->_energy -= 1;
    }
    else
        std::cout << _name << " is exausted let her rest" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << _name << " is been attack " << amount << " of damage have taken" << std::endl;
    _health -= amount;
    if (_health <= 0)
    {
        std::cout << _name << " die" << std::endl;   
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy > 0)
    {
        std::cout << "ClapTrap " << _name << " health " << amount <<
             " of life" << std::endl;
        this->_energy -= 1;
        this->_health += amount;
        std::cout << "Now " << _name << " have " << _health << " of health" << std::endl;
    }
    else
        std::cout << _name << " is exausted let her rest" << std::endl;
    
}


