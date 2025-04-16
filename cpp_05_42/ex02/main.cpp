/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 13:44:46 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    std::cout << "---------------------------" << std::endl << std::endl;
    try
    {
        Bureaucrat  first = Bureaucrat("first", 7);
        PresidentialPardonForm    doc1 = PresidentialPardonForm("home");
        
        std::cout << ".............................." << std::endl;
        std::cout << first << std::endl;
        first.incrementGrade();
        first.signAForm(doc1);
        first.executeAForm(doc1);
        std::cout << first << std::endl;
        std::cout << ".............................." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl << "---------------------------" << std::endl << std::endl;

    try
    {
        Bureaucrat  second = Bureaucrat("second", 10);
        RobotomyRequestForm    doc2 = RobotomyRequestForm("hotel");
        
        std::cout << ".............................." << std::endl;
        std::cout << second << std::endl;
        second.incrementGrade();
        second.signAForm(doc2);
        second.executeAForm(doc2);
        std::cout << second << std::endl;
        std::cout << ".............................." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "---------------------------" << std::endl << std::endl;

    try
    {
        Bureaucrat  thirt = Bureaucrat("thirt", 10);
        ShrubberyCreationForm    doc3 = ShrubberyCreationForm("car");
        
        std::cout << ".............................." << std::endl;
        std::cout << thirt << std::endl;
        thirt.incrementGrade();
        thirt.signAForm(doc3);
        thirt.executeAForm(doc3);
        std::cout << thirt << std::endl;
        std::cout << ".............................." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << std::endl << "---------------------------" << std::endl;
    
    return 0;
}
