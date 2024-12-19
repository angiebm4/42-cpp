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

#ifndef FORM_HPP
# define FORMT_HPP

# include <iostream>
# include <stdexcept>

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _requiredGrade;

    public:
        Form(const std::string, int);
        ~Form();
        const std::string getName(void) const;
        int getGrade(void) const;

};

# endif