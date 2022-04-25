#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <conio.h>
#include "Bullets.h"

using namespace sf;

Player::Player()
{
	spd = 50;
	tex.loadFromFile("s1.png");
	spr.setTexture(tex);
	pos.y = 180;
	lvs = 3;
	xsize = 34;
	ysize = 14;
}

sf::Sprite Player::getSpr()
{
	return spr;
}

void Player::update(float elapsedTime, std::vector <Bullet> &Buls, std::vector <Bullet> &Bulsen)
{
	time -= elapsedTime;
	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && pos.x < 340)
	{
		pos.x += spd*elapsedTime;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && pos.x > 0)
	{
		pos.x -= spd*elapsedTime;
	}
	if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Enter)))
	{
		if (time <= 0)
		{
			time = 0.5;
			Bullet b;
			b.pos.x = pos.x + 16;
			b.pos.y = pos.y;
			Buls.push_back(b);
		}
	}
	for (size_t i = 0; i < Bulsen.size(); i++)
	{
		if ((pos.x <= Bulsen[i].pos.x) && (pos.x + xsize >= Bulsen[i].pos.x) && (pos.y <= Bulsen[i].pos.y) && (pos.y + ysize >= Bulsen[i].pos.y))
		{
			Bulsen.erase(Bulsen.begin() + i);
			lvs--;
			pos.x = 0;
		}
	}
	spr.setPosition(pos);
}