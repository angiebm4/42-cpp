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

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string, int);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &obj);
        Bureaucrat& operator=(const Bureaucrat& obj);
        std::runtime_error NotSigned() throw(std::runtime_error);
        void incrementGrade();
        void decrementGrade();
        const std::string getName(void) const;
        int getGrade(void) const;
        void signAForm(AForm& Aform);
        void executeAForm(AForm const &Aform);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual char const *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const *what(void) const throw();
 
        };
        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

# endif