/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:51 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/12 19:29:27 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string    _ideas[100];
    public:
        Brain();
        ~Brain();
        Brain& operator=(const Brain& obj);
        Brain(const Brain &obj);
    
    std::string getType(int);
    void setType(std::string, int);

};

# endif