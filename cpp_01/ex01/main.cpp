/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/08 00:05:21 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <cstdlib>

/* TODO: por que mierdas el destructor destruye antes y despues */
void	leaks(void)
{
	system("leaks -q zombie");
}

int main(void)
{
    atexit(leaks);
    int N = 4;
    Zombie  *z1 = zombieHorde(N, "Angie");

    for (int i = 0; i < N; i++)
        z1[i].announce();
    delete[] z1;
    return (0);
}
