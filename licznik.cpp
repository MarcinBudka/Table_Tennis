#include "licznik.h"
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

licznik::licznik(int start)
{
    this->val=start;

}


void licznik::aktualizuj_wynik(int wynik)
{
    this->val = this->val + wynik;
}

int licznik::get_licznik()
{
    return this->val;
}

std::string licznik::wynik_do_tekstu()
{
    char buff[100];
    snprintf(buff, sizeof(buff), "Wynik: %d", this->get_licznik());
    std::string wynik_tekst = buff;
    return wynik_tekst;
}


