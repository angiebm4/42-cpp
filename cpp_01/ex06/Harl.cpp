/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:54:12 by angela            #+#    #+#             */
/*   Updated: 2024/05/27 17:08:55 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

Harl::Harl(void)
{
    
}

Harl::~Harl(void)
{
    
}

void    Harl::debug(void)
{
    std::cout << "<< DEBUG >>" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "<< INFO >>" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn t put enough bacon in my burger! If you did, I wouldn t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "<< WARNING >>" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "<< ERROR >>" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string strLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    
    while (i < 5)
    {
        if (level == strLevel[i])
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
            debug();
            break;
        case 1:
            info();
            break;
        case 2:
            warning();
            break;
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}