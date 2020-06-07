#ifndef BLOCZEK_H
#define BLOCZEK_H
#include "element_sceny.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

class Bloczek:public element_sceny
{
private:
    int hp;

public:
    Bloczek();
    Bloczek(const sf::Texture&);
};

#endif // BLOCZEK_H
