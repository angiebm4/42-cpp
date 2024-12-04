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
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
    }
    catch (std::exception & e)
    {
        _grade = grade;
    }
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::GradeTooHighException()
{
    std::cout << "Bureaucrat grade too high" << std::endl;
}

void Bureaucrat::GradeTooLowException()
{
    std::cout << "Bureaucrat grade too low" << std::endl;
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade - 1 < 1)
            throw GradeTooHighException();
    }
    catch (std::exception & e)
    {
        _grade--;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade + 1 > 150)
            throw GradeTooLowException();
    }
    catch (std::exception & e)
    {
        _grade++;
    }
}

const std::string Bureaucrat::getName(void)
{
    return(_name);
}

int Bureaucrat::getGrade(void)
{
    return(_grade);
}

