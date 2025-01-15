/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* Al inicializar asi los valores en el constructor tienen que etar exactamente en el mismo
orden en el que se encuentran en el hpp*/

Form::Form(const std::string name, const int requiredGrade, const int requiredGradeToExecute)
    : _name(name), _signed(false) , _requiredGrade(requiredGrade)
    , _requiredGradeToExecute(requiredGradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;

    try
    {
        if (requiredGrade < GRADE_MAX || requiredGradeToExecute < GRADE_MAX)
            throw GradeTooHighException();
        if (requiredGrade > GRADE_MIN || requiredGradeToExecute > GRADE_MIN)
            throw GradeTooLowException();
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &obj)
    : _name(obj._name), _signed(obj._signed),
    _requiredGrade(obj._requiredGrade),
    _requiredGradeToExecute(obj._requiredGradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

std::runtime_error Form::GradeTooHighException() throw(std::runtime_error)
{
    throw std::runtime_error("Form too high exception");
}

std::runtime_error Form::GradeTooLowException() throw(std::runtime_error)
{
    throw std::runtime_error("Form too low exception");
}


void Form::beSigned(const Bureaucrat& bureaucrat)
{
    try
    {
        if (bureaucrat.getGrade() >= _requiredGrade)
            throw GradeTooLowException();
        _signed = true;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


const std::string Form::getName(void) const
{
    return(_name);
}

int Form::getRequiredGrade(void) const
{
    return(_requiredGrade);
}

int Form::getRequiredGradeToExecute(void) const
{
    return(_requiredGradeToExecute);
}

bool Form::getSigned(void) const
{
    return(_signed);
}

std::ostream& operator<<(std::ostream& os, const Form& b) 
{
    os << b.getName() << ", Form grade " << b.getRequiredGrade();
    return os;
}