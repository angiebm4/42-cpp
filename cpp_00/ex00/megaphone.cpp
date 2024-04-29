/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:37:39 by angela            #+#    #+#             */
/*   Updated: 2024/04/29 10:24:23 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    std::string str;

    if (argc == 1)
    {
        str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << str << std::endl;
        return (0);
    }
    for (int i = 1; argv[i] != NULL; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            argv[i][j] = toupper(argv[i][j]);
            std::cout << argv[i][j];
        }
        std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
