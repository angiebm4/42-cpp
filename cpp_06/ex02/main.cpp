/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:16:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/06 09:22:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> 
#include <ctime>

/* El operador dynamic_cast realiza conversiones de tipo en tiempo de ejecución. 
El operador dynamic_cast garantiza la conversión de un puntero a una clase base a un puntero a 
una clase derivada, o la conversión de un lvalue que hace referencia a una clase base a una 
referencia a una clase derivada. 
De este modo, un programa puede utilizar una jerarquía de clases de forma segura. */

Base * generate(void)
{
    /*usamos la hora actual como semilla, la semilla sirve para tener un punto de partida
    para los numeros aleatorios sin ella siempre saldria el mismo numero
    se usa el tiempo para que cambie cada numero en cada ejecucion*/
    std::srand(time(NULL));
    int random_nb = std::rand() % 3; // para numeros entre 0 y 2

    switch (random_nb)
    {
    case 0:
        return(new A());
    case 1:
        retrun(new B());
    case 2:
        return(new C());
    }
}

void identify(Base* p)
{
    
}

void identify(Base& p)
{
    try
    {
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
    Base randomBase = generate();

    return 0;
}
