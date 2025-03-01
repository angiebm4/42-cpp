/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", REQUIRED_GRADE_SIGN, REQUIRED_GRADE_EXEC),
    _target(target)
{
    std::cout << "PresidentialPardonForm constructor called" << std::endl;

}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

/* No tiene sentido poner esto son valores constantes y una vez inicializados no se pueden asignar
PresidentialPardonForm& operator=(const PresidentialPardonForm& obj) = delete; otra opcion*/

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& obj)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
    (void)obj;
    return(*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return(_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > REQUIRED_GRADE_EXEC)
        throw GradeTooLowException();
    else
    {
        std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}
