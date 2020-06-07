#include "element_sceny.h"
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>


element_sceny::element_sceny()
{

}
element_sceny::element_sceny(const sf::Texture& texture)
{
    setTexture(texture);
    setOrigin(getGlobalBounds().width/2.f,getGlobalBounds().height/2.f);
}
bool element_sceny::kolizja(element_sceny& obiekt)
{
    sf::FloatRect granice_ja=getGlobalBounds();
    sf::FloatRect granice_ty=obiekt.getGlobalBounds();
    if(granice_ja.intersects(granice_ty))
    {
        return true;
    }

    return false;
}
