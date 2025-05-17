/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/17 17:30:43 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}
RPN::RPN(const  RPN &obj)
    : _container(obj._container)
{

}

RPN& RPN::operator=(const  RPN& obj)
{
    if (this != &obj)
    {
        _container = obj._container;
    }   
    return *this;
}

void RPN::addNb(std::string nb)
{
    _container.push(static_cast<int>(nb[0]) - static_cast<int>('0'));
}

void RPN::applyOperator(std::string op)
{
    int result = 0;

    if (_container.size() <= 1)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    int b = _container.top();
    _container.pop();
    int a = _container.top();
    _container.pop();
    
    if (op == "+")
        result = a + b;
    else if (op == "-")
        result = a - b;
    else if (op == "*")
        result = a * b;
    else if (op == "/") 
    {
        if (b == 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        result = a / b;
    }
    _container.push(result);
}

void RPN::checkStack()
{
    if (_container.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    else
        std::cout << _container.top() << std::endl;
}