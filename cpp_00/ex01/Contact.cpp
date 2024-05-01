/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:12:37 by abarrio-          #+#    #+#             */
/*   Updated: 2024/05/01 16:59:42 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/* constructor, inicializa los atriibutos */
Contact::Contact(long _number, std::string _name)
{
    number = _number;
    name = _name;
    std::cout << "Constructor" << std::endl;
    return;
}

Contact::~Contact(void)
{
    std::cout << "Destructor" << std::endl;
    return;
}