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
#include <stdexcept>

Bureaucrat::Bureaucrat()
    : _name("No name")
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
    _grade = 150;

}

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
    std::cout << " Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        _grade = obj.getGrade();
    return (*this);
}

char const	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat grade is too low");
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