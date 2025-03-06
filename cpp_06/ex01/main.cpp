/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/06 08:20:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data* data = new Data();
    Data* data2;
    uintptr_t aux;

    aux = Serializer::serialize(data);
    data2 = Serializer::deserialize(aux);

    std::cout << &data2->aux << std::endl; 
    std::cout << &data->aux << std::endl;
    if (data == data2)
        std::cout << "All ok bb" << std::endl;
    else
        std::cout << "Try again" << std::endl; 
    delete(data);
    return 0;
}
