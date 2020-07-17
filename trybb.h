#ifndef TRYBB_H
#define TRYBB_H

#include <vector>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include <memory>
#include "licznik.h"
#include "element_sceny.h"
#include "paletka.h"
#include "bloczek.h"
#include "scena.h"
#include "pila.h"


class trybb:public Scena
{
private:
    sf::Texture tekstura_bloczkow;
    Paletka gracz;
    pila pilka;
    std::vector<std::unique_ptr<Bloczek>> bloczki;
    bool was_set;
public:
    trybb();
    trybb(sf::Texture&,sf::Texture&,sf::Texture&);
    void rysuj_scene(sf::RenderWindow &) override;
    void aktualizuj_scene() override;
    licznik licz;
};

#endif // TRYBB_H
