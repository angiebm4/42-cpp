#include <iostream>
#include <stdlib.h>

class Punto
{
    private:
        int _y;
        int _x;
    public:
        Punto();
        void    setPunto(int, int);
        int     getPuntoX();
        int     getPuntoY();
};

Punto::Punto()
{

}

int Punto::getPuntoX()
{
    return(_x);
}

int Punto::getPuntoY()
{
    return(_y);
}
    
/* los setters establecen valores a los atributos en cualqueir momento */
void Punto::setPunto(int x, int y)
{
    _x = x;
    _y = y;
}

int main()
{
    Punto punto1;

    punto1.setPunto(10, 50);
    std::cout << punto1.getPuntoX() << std::endl;
    std::cout << punto1.getPuntoY() << std::endl;
    return (0);
}