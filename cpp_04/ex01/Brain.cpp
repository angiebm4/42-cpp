/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:29:55 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/12 19:27:53 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Default constuctor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain Copy Constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = obj._ideas[i];
}

Brain& Brain::operator=(const Brain& obj)
{
    std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        for (int i = 0; i < 100; i++)
        this->_ideas[i] = obj._ideas[i];
    }
    return *this;
}

std::string Brain::getType(int index)
{
    return (_ideas[index]);
}

void    Brain::setType(std::string idea, int index)
{
    _ideas[index] = idea;
}