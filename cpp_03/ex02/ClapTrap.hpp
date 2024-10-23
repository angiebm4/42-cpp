/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:42 by angela            #+#    #+#             */
/*   Updated: 2024/10/23 15:30:30 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class   ClapTrap
{
    protected:
        std::string _name;
        int         _health;
        int         _energy;
        int         _aaDamage;

    public:
        ClapTrap();
        ClapTrap(std::string);
        ClapTrap& operator=(const ClapTrap& obj);
        ClapTrap(const ClapTrap &obj);
        virtual ~ClapTrap(void); /* virtual para funciones que vayan a cambiar su comportamiento del padre al hijo */

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif