#include <iostream>
#include "element_sceny.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include "paletka.h"
#include "trybb.h"
#include "scena.h"
//#include "tryb2vs2.h"
#include "bloczek.h"
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
    Pilka_tekstura.loadFromFile("Pilka.png");

    element_sceny Tlo(Tlo_tekstura);
    Tlo.setPosition(960,540);

    sf::Text wynik_tekst;
    wynik_tekst.setPosition(0,0);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "error w czcionce";
    }

    wynik_tekst.setFont(font);
    wynik_tekst.setCharacterSize(54);
    wynik_tekst.setFillColor(sf::Color::White);
    wynik_tekst.setStyle(sf::Text::Bold | sf::Text::Underlined);
    wynik_tekst.setPosition(20,900);


    trybb tryb_z_bloczkami(Paletka_tekstura, Bloczek_tekstura, Pilka_tekstura );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        tryb_z_bloczkami.aktualizuj_scene();
        window.clear(sf::Color::Black);

        std::string wynik = tryb_z_bloczkami.licz.wynik_do_tekstu();
        wynik_tekst.setString(wynik);
        //wynik_tekst.setString(std::to_string(licz.get_licznik()));


        window.draw(Tlo);
        tryb_z_bloczkami.rysuj_scene(window);
        window.draw(wynik_tekst);

        window.display();
    }
    return 0;
}
