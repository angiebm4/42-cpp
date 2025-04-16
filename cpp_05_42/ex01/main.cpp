/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 13:35:17 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "..........................." << std::endl;
    try
    {
        Bureaucrat  cuatro = Bureaucrat("four", 140);
        Form    doc1 = Form("Rent", 20, 40);
        
        //std::cout << "________________________" << std::endl;
        std::cout << cuatro << std::endl;
        std::cout << doc1 << std::endl;
        //std::cout << "________________________" << std::endl;
        cuatro.signForm(doc1);
        //doc1.beSigned(cuatro);
        //std::cout << "________________________" << std::endl;
        std::cout << cuatro << std::endl;
        std::cout << doc1 << std::endl;
        //std::cout << "________________________" << std::endl;
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
        // doc2.beSigned(second);
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
