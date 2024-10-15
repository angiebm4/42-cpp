/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:40 by angela            #+#    #+#             */
/*   Updated: 2024/09/18 15:51:58 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _health = 10;
    _energy = 10;
    _aaDamage = 0;
    std::cout << "ClapTrap is boorn us a guy called " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    _name = obj._name;
    _health = obj._health;
    _energy = obj._energy;
    _aaDamage = obj._aaDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _health = obj._health;
        _energy = obj._energy;
        _aaDamage = obj._aaDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << _name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_health <= 0)
    {
        std::cout << "ClapTrap " << _name << " is death" << std::endl;
        return;
    }
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
    if (this->_health <= 0)
    {
        std::cout << "ClapTrap " << _name << " is death" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " is been attack " << amount << " of damage have taken" << std::endl;
    _health -= amount;
    if (_health <= 0)
    {
        std::cout << "ClapTrap " << _name << " die" << std::endl;   
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_health <= 0)
    {
        std::cout << "ClapTrap " << _name << " is death" << std::endl;
        return;
    }
    if (this->_energy > 0)
    {
        std::cout << "ClapTrap " << _name << " health " << amount <<
             " of life" << std::endl;
        this->_energy -= 1;
        this->_health += amount;
        std::cout << "ClapTrap " << _name << " have " << _health << " of health" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " is exausted let her rest" << std::endl;
    
}
