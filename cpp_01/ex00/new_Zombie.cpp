/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_Zombie.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:25:41 by angela            #+#    #+#             */
/*   Updated: 2024/05/07 18:54:29 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* newZombie(std::string name)
{
   Zombie *z1 = new Zombie(name);

   return(z1);
}
