/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:39:17 by angela            #+#    #+#             */
/*   Updated: 2024/05/27 17:10:22 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (1);
    }
    Harl    Harl;
    Harl.complain(argv[1]);
    return(0);
}