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
    sf::Texture tekstura;
    bool usun_bloczek;
    int wynik=0;

public:
    Bloczek(int x, int y);
    Bloczek(const sf::Texture&);
    bool getUsunBloczek();
    void setUsunBloczek(bool);
    void setHp(int);
    void setOdejmijHp();
};

#endif // BLOCZEK_H
