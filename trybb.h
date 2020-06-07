#ifndef TRYBB_H
#define TRYBB_H

#include <vector>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"
#include <memory>
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
public:
    trybb();
    trybb(sf::Texture&,sf::Texture&,sf::Texture&);
    void rysuj_scene(sf::RenderWindow &) override;
    void aktualizuj_scene() override;
};

#endif // TRYBB_H
