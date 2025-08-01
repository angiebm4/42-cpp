/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 13:25:06 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PMERGEME_HPP
# define  PMERGEME_HPP

# include <sstream>
# include <string>
# include <iostream>
# include <deque>
# include <cstdlib>
# include <list>

class  PmergeMe
{
    private:
        std::deque<int> _deque;
        std::list<int> _list;
        
    public:
        PmergeMe();
        PmergeMe(char* argv[]);
        ~PmergeMe();
        PmergeMe(const  PmergeMe &obj);
        PmergeMe& operator=(const  PmergeMe& obj);
        void    initContainers(char* argv[]);
        void    mergeInsertSortDeque(std::deque<int>& containerD);
        void    mergeInsertSortList(std::list<int>& containerL);
        void    insertInSortedList(std::list<int>& sorted, int value);
        void    doS();
};

# endif

