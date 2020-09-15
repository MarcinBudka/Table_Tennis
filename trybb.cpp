#include "trybb.h"
//#include "tryb_bloczki_scena.h"
#include <vector>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"
#include <memory>
#include "paletka.h"
#include "bloczek.h"
#include "scena.h"
#include "licznik.h"

#define LVL_UP 2
#define SPEED_ADD 100

trybb::trybb() : licz(0)
{
    this->was_set = false;
}
trybb::trybb(sf::Texture& paletka ,sf::Texture& bloczek, sf::Texture& pil):gracz(paletka),pilka(pil),licz(0)
{
    //gracz.setTexture(paletka);
    tekstura_bloczkow=bloczek;
    //pilka.setTexture(pil);
    pilka.setTextureRect(sf::IntRect(0,0,20,20));
    pilka.setPosition(300,300);
    pilka.setOrigin(pilka.getTextureRect().width/2.f,pilka.getTextureRect().height/2.f);
    for(int i=0;i<14;i++)
    {
        bloczki.emplace_back(std::make_unique<Bloczek>(1560,0+i*78));
        bloczki.emplace_back(std::make_unique<Bloczek>(1560+70,0+i*78));
        bloczki.emplace_back(std::make_unique<Bloczek>(1560+140,0+i*78));
        bloczki.emplace_back(std::make_unique<Bloczek>(1560+210,0+i*78));
        bloczki.emplace_back(std::make_unique<Bloczek>(1560+280,0+i*78));
    }
    this->was_set = false;
}
void trybb::rysuj_scene(sf::RenderWindow& okno)
{

    for(auto&blok:bloczki)
    {
        if (pilka.kolizjaN(blok->getGlobalBounds()))
        {
            blok->setOdejmijHp();
        }
    }
    ssize_t len=bloczki.size();
    bloczki.erase(std::remove_if(bloczki.begin(), bloczki.end(), [](std::unique_ptr<Bloczek> &b){ return b->getUsunBloczek();}), bloczki.end());
    ssize_t punkty=len-bloczki.size();
    this->licz.aktualizuj_wynik(punkty);
    okno.draw(gracz);
    okno.draw(pilka);
    //okno.draw(wynik_tekst);



    if (!this->was_set && licz.get_licznik() % LVL_UP == 0 && licz.get_licznik() != 0) {
        auto obecna_szybkosc = pilka.get_szybkosc();
        if (obecna_szybkosc < 0) {
            obecna_szybkosc -= SPEED_ADD;
        }
        else {
            obecna_szybkosc += SPEED_ADD;
        }
        pilka.set_szybkosc(obecna_szybkosc);
        this->was_set = true;
    }
    else if (licz.get_licznik() % LVL_UP != 0) {
        this->was_set = false;
    }




    std::cout << "\n\n" << pilka.get_szybkosc() << std::endl;

    for(auto&blok:bloczki)
    {
        okno.draw(*blok);
    }
    if(pilka.czy_przegrana())
    {
        okno.close();
    }
}
void trybb::aktualizuj_scene()
{
    if(gracz.kolizja(pilka)==true)
    {
        pilka.zmien_x();
    }

    gracz.steruj_paletka();
    pilka.aktualizuj_pilke(&bloczki);
}
