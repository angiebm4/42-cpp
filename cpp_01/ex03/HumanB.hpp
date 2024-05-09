/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:11:55 by angela            #+#    #+#             */
/*   Updated: 2024/05/09 14:39:32 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    private:
        Weapon  *_weapon;
        std::string _name;
    public:
        HumanB(std::string, Weapon&);
        HumanB(std::string);
        void setWeapon(Weapon&);
        ~HumanB();
        void attack();
};

#endif