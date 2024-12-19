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

Form::Form(const std::string name, int grade)
    : _name(name)
{
    std::cout << "Form constructor called" << std::endl;

    try
    {
        if (grade < GRADE_MAX)
            throw GradeTooHighException();
        if (grade > GRADE_MIN)
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

std::runtime_error Form::GradeTooHighException() throw(std::runtime_error)
{
    throw std::runtime_error("Form too high exception");
}

std::runtime_error Form::GradeTooLowException() throw(std::runtime_error)
{
    throw std::runtime_error("Form too low exception");
}

const std::string Form::getName(void) const
{
    return(_name);
}

int Form::getGrade(void) const
{
    return(_grade);
}

std::ostream& operator<<(std::ostream& os, const Form& b) 
{
    os << b.getName() << ", Form grade " << b.getGrade();
    return os;
}