/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 09:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>

# define GRADE_MIN 150
# define GRADE_MAX 1

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

struct FormType
{
    const   std::string name;
    int     index;
};

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &obj);
        Intern& operator=(const Intern& obj);
        AForm* makeForm(const std::string& , const std::string);       
};

std::ostream& operator<<(std::ostream& os, const Intern& obj);

# endif