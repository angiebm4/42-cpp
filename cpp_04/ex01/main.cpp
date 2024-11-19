/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:37 by angela            #+#    #+#             */
/*   Updated: 2024/11/19 20:08:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main(void)
{
    /*const Animal* j = new Dog();
    const Animal* i = new Cat();
    i->setIdea("uwu", 2);
    std::cout << i->getIdea(2) << std::endl;
    delete j;//should not create a leak
    delete i;*/
    const Animal* uwu[12];

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