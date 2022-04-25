#pragma once
#include <vector>
#include "Bullets.h"
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	sf::Sprite spr;
	sf::Texture tex;
	int spdx;
	float t;
	int xsize;
	int ysize;
public:
	Enemy();
	sf::Vector2f pos;
	sf::Sprite getSpr();
	void update(float elapsedTime, std::vector <Bullet> &buls, int n);
	void shoot(std::vector <Bullet> &bulsen);
	void moveD();
	bool mr;
	int spdy;
	bool move;
	bool alive;
	bool nextstep;
};
