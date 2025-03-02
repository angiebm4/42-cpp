/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/02 18:48:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "---------------------------" << std::endl << std::endl;

    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << rrf << std::endl;
        std::cout << *rrf << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "---------------------------" << std::endl << std::endl;

    try
    {
        Intern someRandomIntern2;
        AForm* rrf2;
        rrf2 = someRandomIntern2.makeForm("uwu", "Bender");
        std::cout << rrf2 << std::endl;
        std::cout << *rrf2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "---------------------------" << std::endl << std::endl;

    try
    {
        Intern someRandomIntern3;
        AForm* rrf3;
        rrf3 = someRandomIntern3.makeForm("presidential pardon", "Bender");
        std::cout << rrf3 << std::endl;
        std::cout << *rrf3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "---------------------------" << std::endl;
    
    return 0;
}
