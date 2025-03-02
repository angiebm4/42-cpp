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
# include "AForm.hpp"

# define GRADE_MIN 150
# define GRADE_MAX 1

# define REQUIRED_GRADE_SIGN 25
# define REQUIRED_GRADE_EXEC 5

class PresidentialPardonForm : public AForm
{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(std::string);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &obj);
        PresidentialPardonForm& operator=(PresidentialPardonForm& obj);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

# endif