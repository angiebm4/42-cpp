/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/07 18:59:22 by angela           ###   ########.fr       */
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
