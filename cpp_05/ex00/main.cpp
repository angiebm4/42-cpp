/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2024/11/25 10:29:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat  first = Bureaucrat("first", 100);
    
    std::cout << first << std::endl;
    first.incrementGrade();
    std::cout << first << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  second = Bureaucrat("second", 1);
    
    std::cout << second << std::endl;
    second.incrementGrade();
    std::cout << second << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  thirt = Bureaucrat("thirt", 150);
    
    std::cout << thirt << std::endl;
    thirt.decrementGrade();
    std::cout << thirt << std::endl;

    std::cout << "..........................." << std::endl;

    Bureaucrat  cuatro = Bureaucrat("thirt", 154);

    std::cout << "..........................." << std::endl;
    
    return 0;
}