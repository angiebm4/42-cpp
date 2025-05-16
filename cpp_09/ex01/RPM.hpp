/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/13 14:04:56 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef  RPN_HPP
# define  RPN_HPP

# include <sstream>
# include <string>
# include <iostream>
# include <stack>

class  RPM
{
    private:
        std::stack<int> _container;
        
    public:
        RPM();
        ~RPM();
        RPM(const  RPM &obj);
        RPM operator=(const  RPM& obj);
        void addNb(std::string nb);
        void applyOperator(std::string op);

};

# endif