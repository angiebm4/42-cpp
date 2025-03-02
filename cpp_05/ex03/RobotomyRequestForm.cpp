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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", R_REQUIRED_GRADE_SIGN, R_REQUIRED_GRADE_EXEC),
    _target(target)
{
    std::cout << "RobotomyRequestForm constructor called" << std::endl;

}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), _target(obj._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

/* No tiene sentido poner esto son valores constantes y una vez inicializados no se pueden asignar
RobotomyRequestForm& operator=(const RobotomyRequestForm& obj) = delete; otra opcion*/

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& obj)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
    (void)obj;
    return(*this);
}

std::string RobotomyRequestForm::getTarget() const
{
    return(_target);
}

std::runtime_error RobotomyRequestForm::RobotomyFail() const throw(std::runtime_error)
{
    throw std::runtime_error("Robotomy failed");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > R_REQUIRED_GRADE_EXEC)
        throw RobotomyFail();
    else
        std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
}
