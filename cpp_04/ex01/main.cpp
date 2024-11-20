/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:37 by angela            #+#    #+#             */
/*   Updated: 2024/11/20 17:19:49 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    /*const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;*/
    
    Animal* uwu[12];

    int in = 0;
    while (in < 6)
    {
        std::cout << in << " --------------------" << std::endl;
        uwu[in] = new Dog();
        in++;
    }
    while (in < 12)
    {
        std::cout << in <<" --------------------" << std::endl;
        uwu[in] = new Cat();
        in++;
    }

    in = 0;
    while (in < 6)
    {
        std::cout << in << " ...................." << std::endl;
        delete uwu[in];
        in++;
    }
     while (in < 12)
    {
        std::cout << in << " ...................." << std::endl;
        delete uwu[in];
        in++;
    }
    return 0;
}

/* valgrind --leak-check=full  ./poly */