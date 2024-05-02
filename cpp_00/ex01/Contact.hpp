/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:13 by abarrio-          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:40 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.hpp"

class Contact
{
    private:
        std::string _phNumber;
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _darkestSecret;
    public:
        /* COSNTRUCTORES */
        Contact(std::string, std::string, std::string, std::string, std::string);
        Contact(void);
        /* DESTRUCTOR */
        ~Contact(void);
        /* GETTERS */
        std::string getPhNumber();
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getDarkestSecret();
        /* SETTERS */
        void setPhNumber(std::string);
        void setFirstName(std::string);
        void setLastName(std::string);
        void setNickname(std::string);
        void setDarkestSecret(std::string);

};

#endif
