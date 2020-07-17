#include "bloczek.h"

Bloczek::Bloczek(int x, int y)
{
    usun_bloczek=0;
    if (!tekstura.loadFromFile("Bloczek.png"))
    {
        std::cout << "Nie da sie zaladowac tekstury" << std::endl;

    }
    int losowa=rand()%5;
    switch (losowa) {
    case 1:
        this -> setColor(sf::Color::Yellow);
        hp=1;
        break;
    case 2:
        this -> setColor(sf::Color::Magenta);
        hp=2;
        break;
    case 3:
        this -> setColor(sf::Color::White);
        hp=3;
        break;
    case 4:
        this -> setColor(sf::Color::Red);
        hp=4;
        break;
    case 0:
        this -> setColor(sf::Color::Cyan);
        hp=5;
        break;
    }
    setTexture(tekstura);
    move(x,y);
}

bool Bloczek::getUsunBloczek()
{
    return usun_bloczek;
}

void Bloczek::setUsunBloczek(bool usun)
{
    usun_bloczek=usun;
}

void Bloczek::setHp(int hhp)
{
    switch (hp) {
    case 1:
        this -> setColor(sf::Color::Yellow);
        hp=1;
        break;
    case 2:
        this -> setColor(sf::Color::Magenta);
        hp=2;
        break;
    case 3:
        this -> setColor(sf::Color::White);
        hp=3;
        break;
    case 4:
        this -> setColor(sf::Color::Red);
        hp=4;
        break;
    case 0:
        this -> setColor(sf::Color::Cyan);
        hp=5;
        break;
    }
}

void Bloczek::setOdejmijHp()
{
    hp--;
    if(hp<=0)
    {
        usun_bloczek=true;

    }
    setHp(hp);

}
