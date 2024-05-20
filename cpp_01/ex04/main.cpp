/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/20 11:15:07 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <fstream>

void    replace_word(std::ifstream &file, std::ofstream &file2, const std::string &s1, const std::string &s2)
{
    std::string line;
    
    while(std::getline(file, line))
    {
        size_t find = line.find(s1);
        while(find != std::string::npos)
        {
            line.erase(find, s1.length());
            line.insert(find, s2);
            find = line.find(s1, find + s2.length());
        }
        file2 << line << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Invalid arguments. Please follow the syntax: [filename] [sentence 1] [sentence 2]" << std::endl;
        return(0);
    }
    
    std::ifstream    file;
    std::ofstream   file2;
    std::string     file_name = argv[1];
    
    file.open(argv[1]);
    if (!file.is_open())
    {
        std::cerr << "error opening file" << std::endl;
        return (0);
    }
    file_name.append(".replace");
    file2.open(file_name.c_str());
    if (!file2.is_open())
    {
        std::cerr << "error opening file" << std::endl;
        return (0);
    }
    replace_word(file, file2 , argv[2], argv[3]);
    file.close();
    file2.close();
    return (0);
}
