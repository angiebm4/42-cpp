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

#include "Span.hpp"

Span::Span()
{
    this->maxSize = 0;
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
    this->maxSize = N;
    std::cout << "Span constructor called" << std::endl;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(const Span& obj)
{
    std::cout << "Span copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->container = obj.container;
        this->maxSize = obj.maxSize;
    }
    return (*this);
}

Span::Span(const Span &obj)
    :   container(obj.container),
        maxSize(obj.maxSize)
{
    std::cout << "Span copy constructor called" << std::endl;
}

void    Span::addNumber(int nb)
{
    if (container.size() < maxSize)
            container.push_back(nb);
    else
        throw std::runtime_error("Span is full");

}

int Span::shortestSpan() const
{
    if (container.size() < 2)
        throw std::runtime_error("No enought numbers in the span to compare");
    std::vector<int> sorted = this->container;

    std::sort(sorted.begin(), sorted.end());

    int min_span = INT_MAX;

    std::vector<int>::iterator it = sorted.begin();
    std::vector<int>::iterator it2 = sorted.begin() + 1;

    while (it2 != sorted.end())
    {
        int diff = *it2 - *it;
        if (min_span > diff)
            min_span = diff;
        it++;
        it2++;
    }
    return(min_span);
}

int Span::longestSpan() const
{
    if (container.size() < 2)
        throw std::runtime_error("No enought numbers in the span to compare");
    
    int min = *std::min_element(container.begin(), container.end());
    int max = *std::max_element(container.begin(), container.end());

    return(max - min);
}