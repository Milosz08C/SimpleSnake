#include "Apple.h"

Plansza p2;
Apple::Apple()
{
    srand(time(0));
    jablko.emplace_back();
    jablko[0].setFillColor(sf::Color::Red);
    jablko[0].setRadius(radius);
    int los = (rand() % (p2.win_heigth-70)) + 20;
    int los2 = (rand() % (p2.win_width-70)) + 20;
    jablko[0].setPosition(sf::Vector2f(los2, los));
}

void  Apple::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    for (auto& c : jablko)
    {
        win.draw(c, state);
    }
}

void Apple::appleSpawn()
{
    jablko.clear();
    jablko.emplace_back();
    jablko[0].setFillColor(sf::Color::Red);
    jablko[0].setRadius(radius);
    int los = (rand() % (p2.win_heigth-70)) + 20;
    int los2 = (rand() % (p2.win_width-70)) + 20;
    jablko[0].setPosition(sf::Vector2f(los2, los));
    
}

void Apple::jablkoClear()
{
    jablko.clear();
}

sf::Vector2f Apple::jablkoGetPosition()
{
    return jablko[0].getPosition();
}