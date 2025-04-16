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
        
    public:
        AForm();
        AForm(const std::string, const int, const int);
        virtual ~AForm();
        AForm(const AForm &obj);
        AForm& operator=(const AForm& obj);
        const std::string getName() const;
        int getRequiredGrade() const;
        int getRequiredGradeToExecute() const;
        bool getSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

# endif