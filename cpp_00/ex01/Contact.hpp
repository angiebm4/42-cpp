/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:13 by abarrio-          #+#    #+#             */
/*   Updated: 2024/05/01 16:58:32 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include "phonebook.hpp"

class Contact
{
    private:
        long number;
        std::string name;
        
    public:
        Contact(number, name); /* Constructor */
        ~Contact(number, name); /* Destructor */

};

#endif
