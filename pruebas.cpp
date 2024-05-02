#include <iostream>
#include <stdlib.h>

class Rectangulo
{
    private:
        float _largo;
        float _ancho;
    public:
        Rectangulo(float, float);
        ~Rectangulo(void);
        void perimetro();
        void area();
};

Rectangulo::Rectangulo(float largo, float ancho)
{
    _largo = largo;
    _ancho = ancho;
    return ;
}

Rectangulo::~Rectangulo(void)
{
    std::cout << "destroying" << std::endl;
    return ;
}


void    Rectangulo::perimetro()
{
    float _perimetro;

    _perimetro = (_ancho * 2) + (_largo * 2);
    std::cout << "El perimetro es: " << _perimetro << std::endl;
}

void    Rectangulo::area()
{
    float _area;

    _area = _largo * _ancho;
    std::cout << "El area es: " << _area << std::endl;
}

int main(void)
{
    float ancho;
    float largo;
    int     flag;

    flag = 0;
    ancho = 0;
    largo = 0;
    while (1)
    {
        std::cout << "inserte el ancho:";
        std::cin >> ancho;
        std::cout << "inserte el largo:";
        std::cin >> largo;
        std::cout << "El largo es " << largo << " y el ancho es " << ancho << std::endl;
        while (flag != 1 && flag != 2)
        {
            std::cout << "Si estas de acuerdo pulse 1, si no pulse 2: ";
            std::cin >> flag;
        }
        if (flag == 1)
            break ;
        flag = 0;
    }
    Rectangulo r1(largo, ancho);
    r1.perimetro();
    r1.area();


    return (0);
}