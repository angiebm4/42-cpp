/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:51 by abarrio-          #+#    #+#             */
/*   Updated: 2024/11/15 09:36:13 by marvin           ###   ########.fr       */
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
    
    std::string getIdea(int);
    void setIdea(std::string, int);

};

# endif