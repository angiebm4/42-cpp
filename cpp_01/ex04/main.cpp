/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:24:03 by angela            #+#    #+#             */
/*   Updated: 2024/05/11 12:51:32 by angela           ###   ########.fr       */
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
        std::cout << "invalid args pls follow the following sintax: [filename] [sentence 1] [sentence 2]" << std::endl;
        return(0);
    }
    std::ofstream    file;
    file.open(argv[1], );
    if (file.fail())
    {
        std::cout << "error al"
    }

    file << argv[2] << std::endl;
    file.close();

    return (0);
}
