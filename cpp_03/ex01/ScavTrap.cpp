/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:29 by abarrio-          #+#    #+#             */
/*   Updated: 2024/10/23 15:08:25 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ClapTrap bot")
{
    std::cout << "ScavTrap is boorn"<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _health = 100;
    _energy = 50;
    _aaDamage = 20;
    std::cout << "ScavTrap is boorn us a guy called " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap()
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    _name = obj._name;
    _health = obj._health;
    _energy = obj._energy;
    _aaDamage = obj._aaDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    std::cout << "ScavTrap Copy assigment operator called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _health = obj._health;
        _energy = obj._energy;
        _aaDamage = obj._aaDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << _name << " has been destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    if (_energy > 0)
    {
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
        _energy -= 1;
    }
    else
        std::cout << "ScavTrap " << _name << " is exausted let her rest" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_health <= 0)
    {
        std::cout << "ScavTrap " << _name << " is death" << std::endl;
        return;
    }
    if (this->_energy > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target <<
             ", causing " << _aaDamage << " points of damage!!" << std::endl;
        this->_energy -= 1;
    }
    else
        std::cout << "ScavTrap " << _name << " is exausted let her rest" << std::endl;
}