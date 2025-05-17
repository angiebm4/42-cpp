/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/17 17:30:47 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef  RPN_HPP
# define  RPN_HPP

# include <sstream>
# include <string>
# include <iostream>
# include <stack>
# include <cstdlib>

class  RPN
{
    private:
        std::stack<int> _container;
        
    public:
        RPN();
        ~RPN();
        RPN(const  RPN &obj);
        RPN& operator=(const  RPN& obj);
        void addNb(std::string nb);
        void applyOperator(std::string op);
        void checkStack();

};

# endif