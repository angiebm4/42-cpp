/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2025/02/15 17:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

void	leaks(void)
{
	system("leaks -q memory_manage");
}

int main(void)
{
    atexit(leaks);
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "The memory address of the string variable: [" << &str  << "]" << std::endl;
    std::cout << "The memory address held by stringPTR: [" << stringPTR << "]" << std::endl;
    std::cout << "The memory address held by stringREF: [" << &stringREF << "]" << std::endl;

    std::cout << "The value of the string variable: [" << str << "]" << std::endl;
    std::cout << "The value pointed to by stringPTR: [" << *stringPTR << "]" << std::endl;
    std::cout << "The value pointed to by stringREF: [" << stringREF << "]" << std::endl;

    return (0);
}
