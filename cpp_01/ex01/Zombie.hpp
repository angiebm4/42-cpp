/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:25:10 by angela            #+#    #+#             */
/*   Updated: 2024/05/07 20:25:40 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "Zombie.h"

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string);
        Zombie();
        ~Zombie(void);
        void announce(void);
};

#endif