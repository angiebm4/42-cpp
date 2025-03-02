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
#include "AForm.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;

    if (grade < GRADE_MAX)
           throw GradeTooHighException();
    if (grade > GRADE_MIN)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : _name(obj._name), _grade(obj._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &obj)
        this->_grade = obj.getGrade();
    return (*this);
}

std::runtime_error Bureaucrat::GradeTooHighException() throw(std::runtime_error)
{
    throw std::runtime_error("Grade too high exception");
}

std::runtime_error Bureaucrat::GradeTooLowException() throw(std::runtime_error)
{
    throw std::runtime_error("Grade too low exception");
}

std::runtime_error Bureaucrat::NotSigned() throw(std::runtime_error)
{
    throw std::runtime_error("Form not signed");
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < GRADE_MAX)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > GRADE_MIN)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signAForm(AForm& Aform)
{
    try
    {
        Aform.beSigned(*this);
        std::cout << getName() << " signed " << Aform.getName() << std::endl;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << getName() << " couldn t sign " << Aform.getName() <<
        " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeAForm(AForm const &Aform)
{
    try
    {
        if (Aform.getSigned() == false)
            throw NotSigned();
        Aform.execute(*this);
        std::cout << getName() << " executed " << Aform.getName() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << " couldn t execute " << Aform.getName() <<
        " because " << e.what() << std::endl;
    }
}

const std::string Bureaucrat::getName() const
{
    return(_name);
}

int Bureaucrat::getGrade() const
{
    return(_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) 
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return os;
}
