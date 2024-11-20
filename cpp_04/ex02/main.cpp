/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:31:37 by angela            #+#    #+#             */
/*   Updated: 2024/11/20 16:55:48 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
    // // Animal Animal1;
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // i->setIdea("uwu", 2);
    // std::cout << i->getIdea(2) << std::endl;
    // delete j;//should not create a leak
    // delete i;

    Cat ori = Cat();
    Cat cpy = Cat(ori);

    ori.setIdea("Tengo cerebro!", 2);

    std::cout << "1. " << ori.getIdea(2) << std::endl;
    std::cout << "2. " << cpy.getIdea(2) << std::endl;

    return 0;
}

/* valgrind --leak-check=full  ./poly */