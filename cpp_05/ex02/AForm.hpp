/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

# define GRADE_MIN 150
# define GRADE_MAX 1

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _requiredGrade;
        const int           _requiredGradeToExecute;
        friend std::ostream& operator<<(std::ostream& os, const AForm& b);

    public:
        AForm(const std::string, const int, const int);
        ~AForm();
        AForm(const AForm &obj);
        std::runtime_error GradeTooHighException() throw(std::runtime_error);
        std::runtime_error GradeTooLowException() throw(std::runtime_error);
        const std::string getName(void) const;
        int getRequiredGrade(void) const;
        int getRequiredGradeToExecute(void) const;
        bool getSigned(void) const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

# endif