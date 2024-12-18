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

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;

    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
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

/* virtual indica que el metodo puede ser sobreescrito por clases derivadas
const char* what() const:

El método what() devuelve un puntero a una cadena de caracteres constante (const char*), que contiene un mensaje descriptivo del error.
El modificador const después de la función significa que el método no modificará ningún miembro de la clase. 
throw(): Especifica que la función no lanzará excepciones. Aunque esto es una característica antigua de C++ (obsoleta en versiones modernas), a menudo se encuentra en código legado.

En este caso, what() devuelve el mensaje "Grade too high!", que será mostrado cuando la excepción sea capturada.


std::exception es una clase base de la biblioteca standar de c++ diseñada para representar errores
al heredar de esta clase puedes personalizar tus propias excepciones y sobrescribir el metodo what()*/

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
        if (_grade - 1 < 1)
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
        if (_grade + 1 > 150)
            throw GradeTooLowException();
        _grade++;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
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
