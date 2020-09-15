#ifndef LICZNIK_H
#define LICZNIK_H

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
#include "pila.h"

class licznik
{
public:
    licznik(int start);
    void aktualizuj_wynik(int tmp_wynik);
    std::string wynik_do_tekstu();
    int get_licznik();
    int pom;
private:
    int val;
};

#endif // LICZNIK_H
