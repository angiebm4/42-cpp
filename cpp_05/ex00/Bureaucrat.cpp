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


/* 
El método what() devuelve un puntero a una cadena de caracteres constante (const char*), 
que contiene un mensaje descriptivo del error.
throw(): Especifica que la función no lanzará excepciones. Aunque esto es una característica antigua de C++ 
(obsoleta en versiones modernas), a menudo se encuentra en código legado.

En este caso, what() devuelve el mensaje "Grade too high!", que será mostrado cuando la excepción sea capturada.

std::exception es una clase base de la biblioteca standar de c++ diseñada para representar errores
al heredar de esta clase puedes personalizar tus propias excepciones y sobrescribir el metodo what()

Las excepciones permiten separar el flujo de control del flujo de errores del programa.
std::exception
bad_alloc -> new(), exception throw on failure allocation memory
bad_cast -> exception throw on failure to dynamic cast
bad_exception -> exception throw by unexpected handler
bad_function_call -> exception throw on bad call
bad_typeid -> exception throw on typeid of null pointer
bad_weak_ptr -> bad weak pointer
ios_base::failure -> base class for stream exceptions
locic_error -> locic error exception 
runtime_error -> runtime error exception

throw -> encargada de lanzar la excepcion, el encargado de avisar que algo pasa
try-> detecta las advertencias lanzadas por throw, espera para activarse una vez detectado manda
    la advertencia a catch
catch -> Responsable de dar una respuesta a la excepcion 
    (puede contener varias respuesta dependiendo de la excepcion que se haya lanzado)
    cada catch solo puede tener una excepcion pero puede haber varios bloques catch
    todo bloque try tiene que tener inmediatamente un bloque catch a continuacion,
    pueden haber varios bloques cada uno para manejar una excepcion posible lanzada por el throw
    cuando se haya ejecutado el bloque catch el programa considerara que la excepcion ha sido manejada y continuara
    ejecutandolo con normalidad.
    suele responder a tipor de daots pero suele responder a parametros de captura, 
    las excepciones de tipos fundamentales pueden capturarse por valor, los no fundamentales 
    deben capturarse por referencia constante

 */

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

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
    : _name(obj._name), _grade(obj._grade)
{
    std::cout << " Bureaucrat copy constructor called" << std::endl;
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