#ifndef PALETKA_H
#define PALETKA_H

#include "element_sceny.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>



class Paletka:public element_sceny
{
private:
    sf::Time czas_paletka;
    sf::Clock zegar_paletka;
    int szybkosc=1000;
public:
    Paletka();
    Paletka(const sf::Texture&);
    void steruj_paletka();
};

#endif // PALETKA_H
