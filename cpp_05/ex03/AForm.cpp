/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(const std::string name, const int requiredGrade, const int requiredGradeToExecute)
    : _name(name), _signed(false) , _requiredGrade(requiredGrade)
    , _requiredGradeToExecute(requiredGradeToExecute)
{
    std::cout << "AForm constructor called" << std::endl;


    if (requiredGrade < GRADE_MAX || requiredGradeToExecute < GRADE_MAX)
        throw GradeTooHighException();
    if (requiredGrade > GRADE_MIN || requiredGradeToExecute > GRADE_MIN)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &obj)
    : _name(obj._name), _signed(obj._signed),
    _requiredGrade(obj._requiredGrade),
    _requiredGradeToExecute(obj._requiredGradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

/* No tiene sentido poner esto son valores constantes y una vez inicializados no se pueden asignar
AForm& operator=(const AForm& obj) = delete; otra opcion*/

AForm& AForm::operator=(const AForm& obj)
{
    std::cout << "AForm copy assignment operator called" << std::endl;

    if (this != &obj)
        this->_signed = obj.getSigned();
    return(*this);
}

std::runtime_error AForm::GradeTooHighException() const throw(std::runtime_error)
{
    throw std::runtime_error("Grade too high exception");
}

std::runtime_error AForm::GradeTooLowException() const throw(std::runtime_error)
{
    throw std::runtime_error("Grade too low exception");
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _requiredGrade)
        throw GradeTooLowException();
    _signed = true;
}

const std::string AForm::getName() const
{
    return(_name);
}

int AForm::getRequiredGrade() const
{
    return(_requiredGrade);
}

int AForm::getRequiredGradeToExecute() const
{
    return(_requiredGradeToExecute);
}

bool AForm::getSigned() const
{
    return(_signed);
}


std::ostream& operator<<(std::ostream& os, const AForm& obj) 
{
    os << obj.getName() << ", AForm grade " << obj.getRequiredGrade() << ".";
    return os;
}