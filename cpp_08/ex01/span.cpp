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

Span::Span(unsigned int N)
{
    this->N = N;
    std::cout << "default constructor called" << std::endl;
}

Span::~Span(void)
{
    std::cout << "default destructor called" << std::endl;
}

Span& Span::operator=(const Span& obj)
{
    this->container.insert(container.end(), obj.begin(), obj.end());
}

Span::Span(const Span &obj)
{

}

Span::addnumber(int nb)
{
    try
    {
        if (container.size() <= N)
            container.push_back(nb);
    }
    catch (const std::overflow_error& e)
    {
        std::cout << "error" << e.what() << std::endl;
    }
}

int Span::shortestSpan()
{
    int span;

    
    return(span)
}

int Span::longestSpan()
{
    int span;


    return(span)
}