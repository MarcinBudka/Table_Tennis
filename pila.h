#ifndef PILA_H
#define PILA_H

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"
#include "bloczek.h"
#include <memory.h>

class pila:public element_sceny
{
protected:
//    int szybkosc= 500;
//    sf::Vector2f predkosc;
    sf::Time czas_pilka;
    sf::Clock zegar_pilka;
private:
    int szybkosc= 500;
    sf::Vector2f predkosc;
public:
    pila();
    pila(const sf::Texture&);
    void aktualizuj_pilka();
    void zmien_x();
    bool czy_przegrana();
    bool kolizja(element_sceny &) override;
    bool kolizja(sf::FloatRect kol);
    void aktualizuj_pilke(std::vector<std::unique_ptr<Bloczek>> *bloki);
    void set_szybkosc(int s);
    int get_szybkosc();
};


#endif // PILA_H
