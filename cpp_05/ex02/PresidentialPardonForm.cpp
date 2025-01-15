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

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define GRADE_MIN 150
# define GRADE_MAX 1


class PresidentialPardonForm : public Form
{
    private:
        /*const std::string   _name;
        bool                _signed;
        const int           _requiredGrade;
        const int           _requiredGradeToExecute;
        friend std::ostream& operator<<(std::ostream& os, const Form& b);*/

    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        std::runtime_error GradeTooHighException() throw(std::runtime_error);
        std::runtime_error GradeTooLowException() throw(std::runtime_error);
        const std::string getName(void) const;
        int getRequiredGrade(void) const;
        int getRequiredGradeToExecute(void) const;
        bool getSigned(void) const;
};

# endif