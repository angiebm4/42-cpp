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

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class Type>

Type min(Type a, Type b)
{
    if (a <= b)
        return(a);
    return(b);
}

template <class Type>
Type max(Type a, Type b)
{
    if (a >= b)
        return(a);
    return(b);
}

template <class Type>
void swap(Type &a, Type &b)
{
    Type aux;

    aux = a;
    a = b;
    b = aux;
}

# endif