/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/02/15 22:20:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat  first = Bureaucrat("first", 100);
        
        std::cout << first << std::endl;
        first.incrementGrade();
        std::cout << first << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Bureaucrat  second = Bureaucrat("second", 5);
    
        std::cout << second << std::endl;
        second.incrementGrade();
        std::cout << second << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "..........................." << std::endl;

    try
    {
        Bureaucrat  thirt = Bureaucrat("thirt", 149);
    
        std::cout << thirt << std::endl;
        thirt.decrementGrade();
        thirt.decrementGrade();
        thirt.decrementGrade();
        std::cout << thirt << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "..........................." << std::endl;
    
    try
    {
        Bureaucrat  cuatro = Bureaucrat("four", 14);
        Form    doc1 = Form("Rent", 20, 40);
    
        std::cout << cuatro << std::endl;
        std::cout << doc1 << std::endl;
        doc1.beSigned(cuatro);
        cuatro.signForm(doc1);
        std::cout << cuatro << std::endl;
        std::cout << doc1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Bureaucrat  second = Bureaucrat("second", 5);
        Form    doc2 = Form("Rent2", 100, 80);
    
        std::cout << second << std::endl;
        std::cout << doc2 << std::endl;
        second.signForm(doc2);
        doc2.beSigned(second);
        std::cout << second << std::endl;
        std::cout << doc2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "..........................." << std::endl;
    
    return 0;
}
