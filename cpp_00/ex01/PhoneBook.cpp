/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:52:39 by angela            #+#    #+#             */
/*   Updated: 2024/05/02 18:29:00 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
/* TODO: getline ._. */

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

void    PhoneBook::search()
{
    
}