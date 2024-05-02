/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:30:11 by abarrio-          #+#    #+#             */
/*   Updated: 2024/05/02 18:30:54 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
    std::string type;
    PhoneBook   ph;
    int i;
    
    i = 0;
    while (1)
    {
        std::cout << "TO CONTINUE ENTER:" << std::endl;
        std::cout << "ADD -> IF YOU WANT TO ADD A NEW CONTACT" << std::endl;
        std::cout << "SEARCH -> IF YOU WANT TO SEARCH FOR ANY CONTACT" << std::endl;
        std::cout << "EXIT -> IF YOU WANT TO GO OUT THE PHONEBOOK" << std::endl;
        getline(std::cin, type);
        if (type == "EXIT" || type == "exit")
            return (0);
        else if (type == "SEARCH" || type == "search")
            ph.search();
        else if (type == "ADD" || type == "add")
        {
            ph.add(i);
            i++;
        }
    }
    return (0);
}
