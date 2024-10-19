/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:06:14 by angela            #+#    #+#             */
/*   Updated: 2024/10/19 19:57:44 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap is boorn" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _name = name;
    _health = 100;
    _energy = 100;
    _aaDamage = 30;
    std::cout << "FragTrap is boorn us a guy called " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap()
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    _name = obj._name;
    _health = obj._health;
    _energy = obj._energy;
    _aaDamage = obj._aaDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << "FragTrap Copy assigment operator called" << std::endl;
    if (this != &obj)
    {
        _name = obj._name;
        _health = obj._health;
        _energy = obj._energy;
        _aaDamage = obj._aaDamage;
    }
    return *this;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << _name << " has been destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if (this->_health <= 0)
    {
        std::cout << "FragTrap " << _name << " is death" << std::endl;
        return;
    }
    if (this->_energy > 0)
    {
        std::cout << "FragTrap " << _name << " say to someone, high five " << std::endl;
        this->_energy -= 1;
    }
    else
        std::cout << "FragTrap " << _name << " is exausted let her rest" << std::endl;
}