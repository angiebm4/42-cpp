/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/04/17 17:37:01 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/* 
   Vectores de cualquier tipo, siempre que sean copiable y asignable:
   std::vector<int> numeros;
   std::vector<float> decimales;
   std::vector<char> caracteres;
   std::vector<bool> booleanos;

   A la hora de crear un vector, puedes:
   - Definir el número de elementos iniciales:
       std::vector<int> v(3);        // Crea un vector de 3 elementos, inicializados a 0
       std::vector<int> v(3, 42);    // Crea un vector de 3 elementos, todos con valor 42

   - O ir añadiendo elementos uno a uno con push_back():
       std::vector<int> v;
       v.push_back(2);
       v.push_back(3);

   - También se puede usar lista de inicialización, pero ¡solo a partir de C++11!
       std::vector<int> v = {3, 42, 1, 2};  // ⚠️ Esto es C++11 en adelante

   Tipos más complejos:
       std::vector<std::string> palabras;

   Tipos definidos por el usuario:
       std::vector<MiClase> objetos;

   Punteros:
       std::vector<int*> punteros;

   Para acceder a una posición del vector:
       v[1]              → acceso directo (no comprueba el rango)
       v.at(1)           → comprueba si estás dentro del rango y lanza excepción si no
*/

template    <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = container.begin();

    while(it != container.end())
    {
        if (*it == value)
        {
            return (it);
        }
        ++it;
    }
    throw(std::runtime_error("Value not found"));
}

int main(void)
{
    try
    {
        std::vector<int> v;

        v.push_back(444);
        v.push_back(555);
        v.push_back(666);
        v.push_back(777);
        std::vector<int>::iterator it = easyfind(v, 555);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "..........................." << std::endl;

    try
    {
        std::vector<int> v;

        v.push_back(444);
        v.push_back(555);
        v.push_back(666);
        v.push_back(777);
        std::vector<int>::iterator it = easyfind(v, 55);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "..........................." << std::endl;

    try
    {
        std::vector<int> v(3, 42);

        std::vector<int>::iterator it = easyfind(v, 42);
        std::cout << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return (0);
}
