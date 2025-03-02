/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern& obj)
{
    (void)obj;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& obj)
{
    *this = obj;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return (*this);
}

/* el operador sizeof devuelve el tamaño en bytes de una variable o tipo de dato. 
Para determinar la cantidad de elementos en un array estático, se puede dividir el 
tamaño total del array por el tamaño de uno de sus elementos. 
Esta técnica es común y se utiliza para calcular la longitud de arrays definidos 
en tiempo de compilación.*/

AForm* Intern::makeForm(const std::string& formName, const std::string target)
{
    const FormType types[] = {
        {"shrubbery creation", 0},
        {"robotomy request", 1},
        {"presidential pardon", 2}
    };

    const int nbTypes = sizeof(types) / sizeof(FormType);

    int i = 0;
    while(i < nbTypes)
    {
        if (formName == types[i].name)
        {
            std::cout << "Inter creates a " << types[i].name << " form" << std::endl;
            switch (types[i].index)
            {
            case 0:
                return (new ShrubberyCreationForm(target));
            case 1:
                return (new RobotomyRequestForm(target));
            case 2:
                return (new PresidentialPardonForm(target));
            }
        }
        i++;
    }
    throw std::runtime_error("The form passed, doesn’t exist, try with a valid form");
    return(NULL);
}