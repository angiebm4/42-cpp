/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:08:17 by angela            #+#    #+#             */
/*   Updated: 2024/08/13 12:35:50 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

/* new y delete son operadores puede hacer referencia a un puntero o a una matriz*/

Zombie* zombieHorde(int N, std::string name)
{
   Zombie  *z = new Zombie[N];
    // Zombie  *z = new (std::nothrow) Zombie[N];
    // if (z == NULL)
    // {
    //     std::cout << "Error: memory coud not be allocated" << std::endl;
    //     return (NULL);
    // }

    for (int i = 0; i < N; i++)
        z[i].setname(name);
    
    // z[0].setname(name);
    // z[1].setname("uwu");
    // z[2].setname("owo");
    // z[3].setname("ewe");

    return(z);
}
