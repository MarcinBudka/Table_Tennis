#include "paletka.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>


Paletka::Paletka()
{

}
Paletka::Paletka(const sf::Texture& texture):element_sceny(texture)
{
    this->setColor(sf::Color::Blue);
}
void Paletka::steruj_paletka()
{
    czas_paletka=zegar_paletka.restart();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&getPosition().y>40)
    {
        move(0,-szybkosc*czas_paletka.asSeconds());
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&getPosition().y+getTexture()->getSize().y<1140)
    {
        move(0,szybkosc*czas_paletka.asSeconds());
    }
}
