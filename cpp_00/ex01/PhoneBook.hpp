/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:52:37 by angela            #+#    #+#             */
/*   Updated: 2024/05/03 13:38:32 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class PhoneBook
{
    private:
        Contact _Contact[8];
    public:
        void add(int);
        void search();
        void display_all_contacts();
        void display_one_contact(int);
        PhoneBook(void);
        ~PhoneBook(void);
};

#endif
