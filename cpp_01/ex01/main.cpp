/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/08/13 12:36:30 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <cstdlib>

int main(void)
{
    int N = 4;
    Zombie  *z1 = zombieHorde(N, "Angie");

    for (int i = 0; i < N; i++)
        z1[i].announce();
    delete[] z1;
    return (0);
}
