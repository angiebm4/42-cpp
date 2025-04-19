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

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Span.hpp"
#include <algorithm>

/* int main(void)
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return (0);
} */

int main(void)
{
    std::srand(std::time(NULL));
    try
    {
        Span    span1 = Span(10000);
        std::vector<int> vector;

        for (int i = 0; i < 10000; ++i)
            vector.push_back(rand());

        span1.addNumbers(vector.begin(), vector.end());
        
        clock_t start = clock();
        std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span1.longestSpan() << std::endl;
        clock_t end = clock();

        double duration = double(end - start) / CLOCKS_PER_SEC;
        std::cout << "Time to compute spans: " << duration << " seconds" << std::endl;

        for (int i = 0; i < 100; ++i)
            std::cout << vector[i] << " ";

        std::cout << std::endl << "------------------------" << std::endl;

        std::sort(vector.begin(), vector.end());
        for (int y = 0; y < 100; ++y)
            std::cout << vector[y] << " ";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
