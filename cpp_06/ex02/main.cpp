/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarrio- <abarrio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/02 16:26:14 by abarrio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> 
#include <ctime>
#include <iostream>

/* El operador dynamic_cast realiza conversiones de tipo en tiempo de ejecución. 
El operador dynamic_cast garantiza la conversión de un puntero a una clase base a un puntero a 
una clase derivada, o la conversión de un lvalue que hace referencia a una clase base a una 
referencia a una clase derivada. 
De este modo, un programa puede utilizar una jerarquía de clases de forma segura. */

Base* generate(void)
{
    
    int random_nb = std::rand() % 3; // para numeros entre 0 y 2

    switch (random_nb)
    {
    case 0:
        return(new A());
    case 1:
        return(new B());
    case 2:
        return(new C());
    }
    return (NULL);
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))  // Si se puede castear a A*
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        // cuando el dynamic_cast falla con referencias →
        // lanza una excepción → así es como se detecta si es esa clase o no.
        (void)dynamic_cast<A&>(p); // si falla lanza execpcion  std::bad_cast
        std::cout << "Reference identify as A classs" << std::endl;
        return ;
    }
    catch(...) {} // fallo el casteo por lo que probamos con otra clase

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference identify as B classs" << std::endl;
        return ;
    }
    catch(...) {} // fallo el casteo por lo que probamos con otra clase

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference identify as C classs" << std::endl;
        return ;
    }
    catch(...) {} // fallo el casteo por lo que probamos con otra clase
}

int main(void)
{
    /*usamos la hora actual como semilla, la semilla sirve para tener un punto de partida
    para los numeros aleatorios sin ella siempre saldria el mismo numero
    se usa el tiempo para que cambie cada numero en cada ejecucion*/
    std::srand(time(NULL));
    
    Base *randomBase = generate();
    identify(randomBase);
    identify(*randomBase);
    delete (randomBase);

    return 0;
}
