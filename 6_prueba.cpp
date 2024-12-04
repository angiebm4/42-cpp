/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_prueba.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:55:52 by abarrio-          #+#    #+#             */
/*   Updated: 2024/12/04 10:59:04 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename U>
auto max(T x, U y)
{
    return(x > y) ? x : y;
}

int main(void)
{
    std::cout << max(1, 2.1) << std::endl;
    return (0);
}