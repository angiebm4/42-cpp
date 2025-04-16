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

Form::Form()
    :   _name("No name"),
        _requiredGrade(150),
        _requiredGradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
    _signed = false;
}

Form::Form(const std::string name, const int requiredGrade, const int requiredGradeToExecute)
    : _name(name), _signed(false) , _requiredGrade(requiredGrade)
    , _requiredGradeToExecute(requiredGradeToExecute)
{
    std::cout << "Form constructor called" << std::endl;


    if (requiredGrade < GRADE_MAX || requiredGradeToExecute < GRADE_MAX)
        throw Bureaucrat::GradeTooHighException();
    if (requiredGrade > GRADE_MIN || requiredGradeToExecute > GRADE_MIN)
        throw Bureaucrat::GradeTooLowException();
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

Form& Form::operator=(const Form& obj)
{
    std::cout << "Form copy assignment operator called" << std::endl;

    if (this != &obj)
        this->_signed = obj.getSigned();
    return(*this);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredGrade)
        throw Bureaucrat::GradeTooLowException();
    _signed = true;
}

const std::string Form::getName() const
{
    return(_name);
}

int Form::getRequiredGrade() const
{
    return(_requiredGrade);
}

int Form::getRequiredGradeToExecute() const
{
    return(_requiredGradeToExecute);
}

bool Form::getSigned() const
{
    return(_signed);
}

std::ostream& operator<<(std::ostream& os, const Form& obj) 
{
    os << obj.getName() << ", Form grade " << obj.getRequiredGrade() << ".";
    return os;
}