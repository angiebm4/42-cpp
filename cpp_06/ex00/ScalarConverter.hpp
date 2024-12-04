/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:00:51 by abarrio-          #+#    #+#             */
/*   Updated: 2024/12/04 10:33:59 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Un tipo escalar es un tipo de dato simple que  contiene un valor unico*/

#ifndef SCALARCONVERTER_HPP
# define SCARLARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(std::string);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
    public:
        static void convert(std::string number);
        
};

# endif