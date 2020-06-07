#include "trybb.h"
#include "tryb_bloczki_scena.h"
#include <vector>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"
#include <memory>
#include "paletka.h"
#include "bloczek.h"
#include "scena.h"
#include "pilka.h"
trybb::trybb()
{

}
trybb::trybb(sf::Texture& paletka ,sf::Texture& bloczek, sf::Texture& pil)
{
    gracz.setTexture(paletka);
    tekstura_bloczkow=bloczek;
    pilka.setTexture(pil);
    pilka.setTextureRect(sf::IntRect(0,0,20,20));
    pilka.setPosition(300,300);
}
void trybb::rysuj_scene(sf::RenderWindow& okno)
{
    for(size_t i=0; i<bloczki.size(); i++)
    {
        okno.draw(*(bloczki[i].get()));
    }
    okno.draw(gracz);
    okno.draw(pilka);
}
void trybb::aktualizuj_scene()
{
    if(gracz.kolizja(pilka)==true)
    {
        pilka.zmien_x();
    }

    gracz.steruj_paletka();
    pilka.aktualizuj_pilka();
}
