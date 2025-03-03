/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 02:33:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("-54634355");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("uwu");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    ScalarConverter::convert("0.7");
    std::cout << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    return 0;
}
