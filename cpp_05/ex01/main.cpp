/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/02/15 19:04:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat  first = Bureaucrat("first", 100);
    
    std::cout << first << std::endl;
    first.incrementGrade();
    std::cout << first << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  second = Bureaucrat("second", 5);
    
    std::cout << second << std::endl;
    second.incrementGrade();
    std::cout << second << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  thirt = Bureaucrat("thirt", 149);
    
    std::cout << thirt << std::endl;
    thirt.decrementGrade();
    thirt.decrementGrade();
    thirt.decrementGrade();
    std::cout << thirt << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  cuatro = Bureaucrat("thirt", 154);

    std::cout << "..........................." << std::endl;

    Form    doc1 = Form("Rent", 2, 4);

    std::cout << thirt << std::endl;
    std::cout << doc1 << std::endl;
    doc1.beSigned(thirt);
    thirt.signForm(doc1);
    std::cout << thirt << std::endl;
    std::cout << doc1 << std::endl;

    std::cout << "..........................." << std::endl;

    Form    doc2 = Form("Rent2", 100, 80);

    std::cout << second << std::endl;
    std::cout << doc2 << std::endl;
    second.signForm(doc2);
    doc1.beSigned(second);
    std::cout << second << std::endl;
    std::cout << doc2 << std::endl;

    std::cout << "..........................." << std::endl;
    
    return 0;
}
