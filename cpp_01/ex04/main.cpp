/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/16 12:55:02 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>


void	leaks(void)
{
	system("leaks -q sed_losers");
}

int main(int argc, char *argv[])
{
    atexit(leaks);
    if (argc != 4)
    {
        std::cerr << "Invalid arguments. Please follow the syntax: [filename] [sentence 1] [sentence 2]" << std::endl;
        return(0);
    }
    std::ifstream    file;
    file.open(argv[1]);
    if (file.fail())
        std::cerr << "error al abrir el archivo" << std::endl;
    std::ofstream   file2;
    std::string     str = argv[2];
    str.append(".replace");
    file2.open(str.c_str());
    if (file2.fail())
        std::cerr << "error al abrir el archivo" << std::endl;
    if (file.is_open())
    {
        std::string     s1 = argv[3];
        std::string line;
        while(file.good())
        {
            std::getline(file, line);
            size_t find = line.find(argv[3]);
            if (find != std::string::npos)
            {
                line.erase(find, find + s1.length());
            }
        }
    }
    file2 << "hola que tal" << std::endl;
    file.close();
    file2.close();
    return (0);
}
