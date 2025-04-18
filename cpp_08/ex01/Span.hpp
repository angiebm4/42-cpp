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

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits.h>

class Span
{
    private:
        std::vector<int> container;
        unsigned int maxSize;

    public:
        Span();
        Span(unsigned int);
        ~Span(void);
        Span& operator=(const Span& obj);
        Span(const Span &obj);
        
        addNumber(int);
        int shortestSpan() const;
        int longestSpan() const;

};

# endif