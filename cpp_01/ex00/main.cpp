/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/08/05 12:51:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main(void)
{
    randomChump("Luizzzz");
    Zombie  *z1 = newZombie("Angie");

    z1->announce();
    delete z1;
    return (0);
}
