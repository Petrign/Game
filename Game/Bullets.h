#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	sf::Sprite spr;
	sf::Texture tex;
public:
	int spd;
	Bullet();
	sf::Vector2f pos;
	sf::Sprite getSpr();
	void update(float elapsedTime);
	void DrawBul(sf::RenderWindow &win);
};
