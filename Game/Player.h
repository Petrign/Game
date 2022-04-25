#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullets.h"

class Player
{
private:
	sf::Sprite spr;
	sf::Texture tex;
	int spd;
	float time;
	int xsize;
	int ysize;
public:
	Player();
	int lvs;
	sf::Vector2f pos;
	sf::Sprite getSpr();
	void update(float elapsedTime, std::vector <Bullet> &Buls, std::vector <Bullet> &Bulsen);
};
