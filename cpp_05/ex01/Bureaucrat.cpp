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
#include "Form.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;

    try
    {
        if (grade < GRADE_MAX)
            throw GradeTooHighException();
        if (grade > GRADE_MIN)
            throw GradeTooLowException();
        _grade = grade;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    

}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : _name(obj._name), _grade(obj._grade)
{
    std::cout << " Bureaucrat copy constructor called" << std::endl;
}


std::runtime_error Bureaucrat::GradeTooHighException() throw(std::runtime_error)
{
    throw std::runtime_error("Bureaucrat too high exception");
}

std::runtime_error Bureaucrat::GradeTooLowException() throw(std::runtime_error)
{
    throw std::runtime_error("Bureaucrat too low exception");
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade - 1 < GRADE_MAX)
            throw GradeTooHighException();
        _grade--;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade + 1 > GRADE_MIN)
            throw GradeTooLowException();
        _grade++;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        if (form.getSigned() == false)
            throw GradeTooLowException();
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << getName() << " couldn t sign " << form.getName() <<
        " because " << e.what() << std::endl;
    }
}

const std::string Bureaucrat::getName(void) const
{
    return(_name);
}

int Bureaucrat::getGrade(void) const
{
    return(_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) 
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
