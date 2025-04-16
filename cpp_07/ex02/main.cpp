/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/16 16:33:48 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);
        a[2] = 30;

        std::cout << "a[2]: " << a[2] << std::endl;
        std::cout << "a[0]: " << a[0] << std::endl;
        std::cout << "a[6]: " << a[6] << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Array<std::string> a(4);
        a[2] = "uwu";
        a[3] = "owo";

        std::cout << "a[2]: " << a[2] << std::endl;
        std::cout << "a[0]: " << a[0] << std::endl;
        std::cout << "a[3]: " << a[3] << std::endl;
        std::cout << "a[5]: " << a[5] << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "..........................." << std::endl;

    try
    {
        Array<std::string> a(4);
        a[2] = "uwu";
        a[5] = "owo";

        std::cout << "a[2]: " << a[2] << std::endl;
        std::cout << "a[0]: " << a[0] << std::endl;
        std::cout << "a[3]: " << a[3] << std::endl;
        std::cout << "a[5]: " << a[5] << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}