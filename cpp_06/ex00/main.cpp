/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 14:18:52 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid number of arguments" << std::endl;
        return (1);
    }
    std::cout << std::endl << "---> ARG TEST <---" << std::endl;
    std::cout << std::endl;
    ScalarConverter::convert(argv[1]);
    std::cout << std::endl;
    std::cout << std::endl << "---> DEFAULT TEST <---" << std::endl;
    std::cout << std::endl << "---> 42 TEST <---" << std::endl;
    ScalarConverter::convert("42.0");
    std::cout << std::endl;
    std::cout << std::endl << "---> -54634355 TEST <---" << std::endl;
    ScalarConverter::convert("-54634355");
    std::cout << std::endl;
    std::cout << std::endl << "---> inf TEST <---" << std::endl;
    ScalarConverter::convert("inf");
    std::cout << std::endl;
    std::cout << std::endl << "---> uwu TEST <---" << std::endl;
    ScalarConverter::convert("uwu");
    std::cout << std::endl;
    std::cout << std::endl << "---> nan TEST <---" << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;
    std::cout << std::endl << "---> .7 TEST <---" << std::endl;
    ScalarConverter::convert(".7");
    std::cout << std::endl;
    std::cout << std::endl << "---> 0 TEST <---" << std::endl;
    ScalarConverter::convert("0");
    std::cout << std::endl;
    std::cout << std::endl << "---> C TEST <---" << std::endl;
    ScalarConverter::convert("C");
    std::cout << std::endl;
    std::cout << std::endl << "---> 42.0f TEST <---" << std::endl;
    ScalarConverter::convert("42.0f");
    std::cout << std::endl;
    return 0;
}
