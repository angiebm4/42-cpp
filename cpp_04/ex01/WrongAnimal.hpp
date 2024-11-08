/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:51:27 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/04 12:26:04 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal(void);
        WrongAnimal& operator=(const WrongAnimal& obj);
        WrongAnimal(const WrongAnimal &obj);
        
        void makeSound(void) const;

        std::string getType(void) const;
        void setType(std::string);
};


# endif