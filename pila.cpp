#include "pila.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
pila::pila()
{
    predkosc.x=szybkosc;
    predkosc.y=szybkosc;
}
pila::pila(const sf::Texture& texture):element_sceny(texture)
{
    predkosc.x=szybkosc;
    predkosc.y=szybkosc;
}
void pila::aktualizuj_pilka()
{
    czas_pilka=zegar_pilka.restart();
    if(getPosition().y>1080)
    {
        predkosc.y=-predkosc.y;
    }
    if(getPosition().y<0)
    {
        predkosc.y=-predkosc.y;
    }
    if(getPosition().x>1920)
    {
        zmien_x();
    }


    move(predkosc.x*czas_pilka.asSeconds(),predkosc.y*czas_pilka.asSeconds());
}
void pila::zmien_x()
{
    predkosc.x=-predkosc.x;
}
