#include <iostream>
#include "element_sceny.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "paletka.h"
#include "trybb.h"
#include "scena.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "My window");

    sf::Texture Tlo_tekstura;
    Tlo_tekstura.loadFromFile("Tlo.jpg");

    sf::Texture Paletka_tekstura;
    Paletka_tekstura.loadFromFile("Paletka.png");

    sf::Texture Bloczek_tekstura;
    Bloczek_tekstura.loadFromFile("Bloczek.png");

    sf::Texture Pilka_tekstura;
    Pilka_tekstura.loadFromFile("Paletka.png");

    element_sceny Tlo(Tlo_tekstura);
    Tlo.setPosition(960,540);

    trybb tryb_z_bloczkami(Paletka_tekstura, Bloczek_tekstura, Paletka_tekstura );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        tryb_z_bloczkami.aktualizuj_scene();
        window.clear(sf::Color::Black);
        tryb_z_bloczkami.rysuj_scene(window);
        window.display();
    }
    return 0;
}
