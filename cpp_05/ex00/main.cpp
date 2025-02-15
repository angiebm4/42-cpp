/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/02/15 21:51:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    std::cout << "..........................." << std::endl;
    
    try
    {
        Bureaucrat  first = Bureaucrat("first", 180);
        
        std::cout << first << std::endl;
        first.incrementGrade();
        std::cout << first << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Bureaucrat  second = Bureaucrat("second", 1);
        
        std::cout << second << std::endl;
        second.incrementGrade();
        std::cout << second << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Bureaucrat  thirt = Bureaucrat("thirt", 149);
        
        std::cout << thirt << std::endl;
        thirt.decrementGrade();
        std::cout << thirt << std::endl;
    }
    catch(std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "..........................." << std::endl;

    return (0);
}

/* exsite el catch(...) que sirve para capturar cualquier execpcion se coloca al fina de la linea de catch
es risky pero para evitar que el programa acabe de modo inesperado*/
