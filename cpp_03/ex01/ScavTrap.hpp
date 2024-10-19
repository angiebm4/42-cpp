/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:27:31 by abarrio-          #+#    #+#             */
/*   Updated: 2024/10/19 18:59:46 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string);
        ScavTrap& operator=(const ScavTrap& obj);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap(void);
        
        void guardGate();
        void attack(const std::string& target);
};

# endif