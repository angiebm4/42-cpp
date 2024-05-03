/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:12:37 by abarrio-          #+#    #+#             */
/*   Updated: 2024/05/03 13:58:15 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/* CONSTRUCTORS INIT ATRIBUTES */

Contact::Contact(void)
{
    _phNumber = "";
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _darkestSecret = "";
    return;
}

Contact::Contact(std::string phNumber, std::string firstname,
                std::string lastName, std::string nickname,
                std::string darkestSecret)
{
    _phNumber = phNumber;
    _firstName = firstname;
    _lastName = lastName;
    _nickname = nickname;
    _darkestSecret = darkestSecret;
    return;
}

/* DESTRUCTOR */

Contact::~Contact(void)
{
    return;
}

/* GETTERS */

std::string Contact::getPhNumber()
{
    return(_phNumber);
}

std::string Contact::getFirstName()
{
    return(_firstName);
}

std::string Contact::getLastName()
{
    return(_lastName);
}

std::string Contact::getNickname()
{
    return(_nickname);
}

std::string Contact::getDarkestSecret()
{
    return(_darkestSecret);
}

/* SETTERS */

void    Contact::setPhNumber(std::string phnumber)
{
    _phNumber = phnumber;
}

void    Contact::setFirstName(std::string firstname)
{
    _firstName = firstname;
}

void    Contact::setLastName(std::string lastname)
{
    _lastName = lastname;
}

void    Contact::setNickname(std::string nickname)
{
    _nickname = nickname;
}

void    Contact::setDarkestSecret(std::string darkestsecret)
{
    _darkestSecret = darkestsecret;
}
