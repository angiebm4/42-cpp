/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
    _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    try
    {
    /* do some stuff with bureaucrats */
    }
    catch (std::exception & e)
    {
        /* handle exception */
    }

    _grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}
