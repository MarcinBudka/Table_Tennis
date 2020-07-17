 #include "pila.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <cmath>
#include "licznik.h"
#include <iostream>

pila::pila()
{
    predkosc.x=szybkosc;
    predkosc.y=szybkosc;
}
pila::pila(const sf::Texture& texture):element_sceny(texture)
{
    this->setColor(sf::Color::Green);
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
bool pila::czy_przegrana()
{
    if(getPosition().x<=0)
    {
        return true;
    }
    else
        return false;
}
bool pila::kolizja(element_sceny & obiekt)
{
    sf::Vector2f moja_pozycja=getPosition();
    sf::Vector2f moje_wymiary_polowa=zwroc_polowe();
    sf::Vector2f obiekt_polowa=obiekt.zwroc_polowe();
    sf::Vector2f obiekt_pozycja=obiekt.getPosition();
    sf::Vector2f delta;
    delta.x=obiekt_pozycja.x-moja_pozycja.x;
    delta.y=obiekt_pozycja.y-moja_pozycja.y;
    sf::Vector2f przenikanie;
    przenikanie.x=std::abs(delta.x)-(obiekt_polowa.x+moje_wymiary_polowa.x);
    przenikanie.y=std::abs(delta.y)-(obiekt_polowa.y+moje_wymiary_polowa.y);
    if(przenikanie.x<=0&&przenikanie.y<=0)
    {
        if(std::abs(przenikanie.x)<std::abs(przenikanie.y))
        {
            if(delta.x>=0)
            {
                //kolizja z lewej
                predkosc.x=-predkosc.x;
                std::cout<<"kolizja z lewej";
            }
            else if(delta.x<0)
            {
                //kolizja z prawej
                predkosc.x=-predkosc.x;
                std::cout<<"kolizja z prawej";
            }
        }else
        {
            if(delta.y>=0)
            {
                //kolizja z gory
                predkosc.y=-predkosc.y;
                std::cout<<"kolizja z gory";
            }
            else if(delta.y<0)
            {
                //kolizja z dołu
                predkosc.y=-predkosc.y;
                std::cout<<"kolizja z dolu";
            }
        }
    }
}
//{
//    return getGlobalBounds().intersects(obiekt.getGlobalBounds());
//}
bool pila::kolizja(sf::FloatRect kol)
{

}

void pila::aktualizuj_pilke(std::vector<std::unique_ptr<Bloczek> > *bloki)
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
    move(predkosc.x*czas_pilka.asSeconds(),0);
    for(auto&blok:*bloki)
    {
        if(kolizjaN(blok->getGlobalBounds()))
        {
            predkosc.x=-predkosc.x;
            move(predkosc.x*czas_pilka.asSeconds(),0);
            blok->setOdejmijHp();
        }
    }
    move(0,predkosc.y*czas_pilka.asSeconds());
    for(auto&blok:*bloki)
    {
        if(kolizjaN(blok->getGlobalBounds()))
        {
            predkosc.y=-predkosc.y;
            move(0,predkosc.y*czas_pilka.asSeconds());
            blok->setOdejmijHp();
        }
    }
}

void pila::set_szybkosc(int s)
{
    this->predkosc.x = s;
    this->predkosc.y = s;
}

int pila::get_szybkosc()
{
    return this->predkosc.x;
}
