/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_Zombie.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:25:41 by angela            #+#    #+#             */
/*   Updated: 2024/05/06 14:27:39 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

 Zombie* newZombie( std::string name )
 {
    Zombie::Zombie new_zombie;

    return(&new_zombie);
 }