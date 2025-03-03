/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:00:51 by abarrio-          #+#    #+#             */
/*   Updated: 2025/03/02 19:32:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Un tipo escalar es un tipo de dato simple que  contiene un valor unico*/

#ifndef SCALARCONVERTER_HPP
# define SCARLARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    /* al ser una clase no instanciable los metodos constructor/ destructor 
        ect tiene que ser privados no hace falta implementarlo ya que nunca 
        deberian usarse */
    private:
        ScalarConverter(std::string);
        ~ScalarConverter(void);
        ScalarConverter(const ScalarConverter &obj);
        ScalarConverter& operator=(const ScalarConverter& obj);
    public:
        static void convert(std::string number);
        /* Cuando declaras un método como static dentro de una clase en el .hpp, significa que:
            Es un método de clase, no de instancia. No necesita un objeto para ser llamado.
            Se comparte entre todas las instancias de la clase.
            No tiene acceso a this, porque no pertenece a un objeto en particular.*/
        
};

# endif