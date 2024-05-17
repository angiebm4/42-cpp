/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/17 10:36:50 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>


void	leaks(void)
{
	system("leaks -q sed_losers");
}

void    replace_word(std::ifstream &file, std::ofstream &file2, char *argv[])
{

    std::string s1 = argv[2];
    std::string line;
    
    while(file.good())
    {
        std::getline(file, line);
        size_t find = 0;
        while(line.find(argv[2]))
        {
            if (find != std::string::npos)
            {
                line.erase(find, s1.length());
                file2 << line.insert(find, argv[3]) << std::endl;
                find += s1.length();
            }
            
        }
        file2 << line << std::endl;
    }
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
    std::ofstream   file2;
    std::string     str = argv[1];
    
    file.open(argv[1]);
    if (file.fail())
        std::cerr << "error opening file" << std::endl;
    str.append(".replace");
    file2.open(str.c_str());
    if (file2.fail())
        std::cerr << "error opening file" << std::endl;
    if (file.is_open())
        replace_word(file, file2 , argv);
    file.close();
    file2.close();
    return (0);
}
