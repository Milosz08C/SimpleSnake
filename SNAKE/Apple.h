#pragma once
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Plansza.h"
class Apple : public sf::Drawable
{
	std::vector<sf::CircleShape> jablko;
	float radius{ 8.f };
	void draw(sf::RenderTarget& win, sf::RenderStates state) const override;

public:
	void appleSpawn();
	sf::Vector2f jablkoGetPosition();
	void jablkoClear();
	Apple();
	
};

