#include "Znicz.h"
Znicz::Znicz(Waz&w) : anakonda(&w)
{
    srand(time(0));
    kulka.emplace_back();
    kulka[0].setFillColor(sf::Color::Yellow);
    kulka[0].setRadius(radius);
    int los = (rand() % (800- 50)) + 1;
    int los2 = (rand() % (800 - 50)) + 1;
    kulka[0] .setPosition(sf::Vector2f(los2, los));
    kulka[0].setOrigin(4,4);
}

void Znicz::draw(sf::RenderTarget& win, sf::RenderStates state) const
{
    for (auto& d : kulka)
    {
        win.draw(d, state);
    }
    
}

int Znicz::losuj()
{
    srand(time(0));
    ruch = (rand() % 4) + 0;
    return ruch;
}

void Znicz::move()
{
    losuj();
    switch (ruch)
    {
    case 0:
        kulka[0].move(-7.f, 0.f);
        break;
    case 1:
        kulka[0].move(7.f, 0.f);
        break;
    case 2:
        kulka[0].move(0.f, 7.f);
        break;
    case 3:
        kulka[0].move(0.f,-7.f);
        break;
    }
}

void Znicz::kulkaSpawn()
{
    kulka.clear();
    kulka.emplace_back();
    kulka[0].setFillColor(sf::Color::Yellow);
    kulka[0].setRadius(radius);
    int los = (rand() % (800 - 50)) + 1;
    int los2 = (rand() % (800 - 50)) + 1;
    kulka[0].setPosition(sf::Vector2f(los2, los));

}

sf::Vector2f Znicz::kulkaGetPosition()
{
    return kulka[0].getPosition();
}
