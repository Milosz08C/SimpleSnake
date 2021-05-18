

#include<SFML\Graphics.hpp>
#include <iostream>
#include"Game_engine.h"
#include"Apple.h"
#include "Waz.h"
#include "Znicz.h"


int main()
{
    Waz w;
    Apple a;
    Znicz z(w);
    
    sf::Texture t;
    t.loadFromFile("kwad.png");
    sf::Sprite kwad;
    kwad.setTexture(t);
    sf::RenderWindow win(sf::VideoMode(800,800),"wub");

    Game_engine engine(w,a,z); 
    engine.display();
 
    return 0;
}

