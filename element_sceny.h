#ifndef ELEMENT_SCENY_H
#define ELEMENT_SCENY_H

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>

class element_sceny:public sf::Sprite
{
public:
    element_sceny();
    element_sceny(const sf::Texture&);
    bool kolizja(element_sceny&);
private:
    sf::IntRect granice;
};


#endif // ELEMENT_SCENY_H
