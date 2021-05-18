#pragma once
#include<SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Waz.h"
class Znicz : public sf::Drawable
{
	void draw(sf::RenderTarget& win, sf::RenderStates state) const override;
	std::vector<sf::CircleShape> kulka;
	float radius{ 8.f };
	int ruch=0;
	int losuj();
	Waz* anakonda;
public:
	sf::Vector2f kulkaGetPosition();
	void kulkaSpawn();
	void move();
	Znicz(Waz &);
};

