#ifndef SCENA_H
#define SCENA_H
#include <vector>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "element_sceny.h"
#include <memory>
#include "paletka.h"
#include "bloczek.h"


class Scena
{
protected:
    std::vector<std::unique_ptr<element_sceny>>bloczki;
public:
    Scena();
    virtual void rysuj_scene(sf::RenderWindow&)=0;
    virtual void aktualizuj_scene()=0;
};


#endif // SCENA_H
