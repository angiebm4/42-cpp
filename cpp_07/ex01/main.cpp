/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2024/12/04 10:42:44 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int &x)
{
    std::cout << x << " ";
}

void addOne(int &x)
{
    x += 1;
}

void printStr(std::string &s)
{
    std::cout << s << " ";
}

int main()
{
    int numbers[] = {10, 20, 30, 40, 50};
    std::string words[] = {"42", "Madrid", "CPP07"};

    std::cout << "Original numbers: ";
    ::iter(numbers, 5, printInt);
    std::cout << std::endl;

    ::iter(numbers, 5, addOne);
    std::cout << "After addOne: ";
    ::iter(numbers, 5, printInt);
    std::cout << std::endl;

    std::cout << "Words: ";
    ::iter(words, 3, printStr);
    std::cout << std::endl;

    return 0;
}