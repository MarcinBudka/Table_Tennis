#ifndef PILA_H
#define PILA_H

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"

class pila:public element_sceny
{
protected:
    int szybkosc= 500;
    sf::Vector2f predkosc;
    sf::Time czas_pilka;
    sf::Clock zegar_pilka;
public:
    pila();
    pila(const sf::Texture&);
    void aktualizuj_pilka();
    void zmien_x();
};
#endif // PILA_H
