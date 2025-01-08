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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# define GRADE_MIN 150
# define GRADE_MAX 1

# include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
    public:
        Bureaucrat(const std::string, int);
        ~Bureaucrat();
        std::runtime_error GradeTooHighException() throw(std::runtime_error);
        std::runtime_error GradeTooLowException() throw(std::runtime_error);
        void incrementGrade();
        void decrementGrade();
        const std::string getName(void) const;
        int getGrade(void) const;
        void signForm(Form& form);
        
};


// std::ostream& operator<<(std::ostream &COUT, const Bureaucrat &obj);

# endif