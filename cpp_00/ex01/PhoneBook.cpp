/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:52:39 by angela            #+#    #+#             */
/*   Updated: 2024/05/03 13:57:33 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook(void)
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

void    PhoneBook::add(int i)
{
    std::string aux;
    
    std::cout << "TO ADD A CONTACT FILL OUT THE FOLLOWING DATA" << std::endl;
    
    aux = "";
    while (aux == "")
    {
        std::cout << "PHONE NUMBER : ";
        getline(std::cin, aux);
    }
    _Contact[i % 8].setPhNumber(aux);
    
    aux = "";
    while (aux == "")
    {
        std::cout << "FIRST NAME : ";
        getline(std::cin, aux);
    }
    _Contact[i % 8].setFirstName(aux);
    
    aux = "";
    while (aux == "")
    {
        std::cout << "LAST NAME : ";
        getline(std::cin, aux);
    }
    _Contact[i % 8].setLastName(aux);
    
    aux = "";
    while (aux == "")
    {
        std::cout << "NICKNAME : ";
        getline(std::cin, aux);
    }
    _Contact[i % 8].setNickname(aux);
    
    aux = "";
    while (aux == "")
    {
        std::cout << "YOUR DARKEST SECRET, PLEASE : ";
        getline(std::cin, aux);
    }
    _Contact[i % 8].setDarkestSecret(aux);
}

void    PhoneBook::display_all_contacts()
{
    int i;

    i = 0;
    while (i < 8)
    {
        std::cout << std::setfill('.') << std::setw(10) << i << "|"
        << std::setfill('.') << std::setw(10) << _Contact[i].getFirstName() << "|"
        << std::setfill('.') << std::setw(10) << _Contact[i].getLastName() << "|"
        << std::setfill('.') << std::setw(10) << _Contact[i].getNickname()
        << std::endl;
        i++;
    }
}

void    PhoneBook::display_one_contact(int i)
{
    std::cout << "INDEX: " << i << std::endl
    << "FIRST NAME: " << _Contact[i].getFirstName() << std::endl
    << "LAST NAME: " << _Contact[i].getLastName() << std::endl
    << "NICKNAME: " << _Contact[i].getNickname() << std::endl
    << "PHONE NUMBER: " << _Contact[i].getPhNumber() << std::endl
    << "DARKEST SECRET: " << _Contact[i].getDarkestSecret() << std::endl;
}

void    PhoneBook::search()
{
    std::string aux;
    
    PhoneBook::display_all_contacts();
    aux = "";
    while (aux == "")
    {
        std::cout << "ENTER THE INDEX OF THE CONTACT YOU WANT TO SEE: " << std::endl;
        getline(std::cin, aux);
        if (aux == "exit" || aux == "EXIT")
            return ;
        else if (aux.length() == 1 && (aux[0] < '8' && aux[0] >= 0))
        {
            int i = aux[0] - '0';
            if (_Contact[i].getFirstName() == "")
                std::cout << "EMPTY CONTACT" << std::endl;
            else
            {
                PhoneBook::display_one_contact(i);
                break ;
            }
        }
        else
            std::cout << "---INVALID INPUT---" << std::endl;
        aux = "";
    }
    
}
