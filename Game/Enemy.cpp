#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Enemy::Enemy()
{
	spdx = 34;
	spdy = 16;
	tex.loadFromFile("s2.png");
	spr.setTexture(tex);
	pos.y = 10;
	mr = true;
	t = 0;
	move = false;
	xsize = 34;
	ysize = 14;
	alive = true;
}

sf::Sprite Enemy::getSpr()
{
	return spr;
}

void Enemy::moveD()
{
	pos.y += spdy;
	mr = !mr;
	move = false;
}

void Enemy::shoot(std::vector <Bullet> &bulsen)
{
	Bullet b;
	b.spd = -b.spd;
	b.pos.x = pos.x + 16;
	b.pos.y = pos.y;
	bulsen.push_back(b);
}

void Enemy::update(float elapsedTime, std::vector <Bullet> &buls, int n)
{
	t += elapsedTime;
	if (t >= 150/(100+n))
	{
		nextstep = true;
		t = 0;
		if (move)
		{
			moveD();
		}
		else
		{
			if (mr)
			{
				pos.x += spdx;
			}
			else
			{
				pos.x -= spdx;
			}
		}
		if ((pos.x <= 0 && !mr) || (pos.x >= 340 && mr))
		{
			move = true;
		}
	}
	spr.setPosition(pos);
	for (size_t i = 0; i < buls.size(); i++)
	{
		if ((pos.x<= buls[i].pos.x) && (pos.x + xsize >= buls[i].pos.x) && (pos.y <= buls[i].pos.y) && (pos.y + ysize >= buls[i].pos.y))
		{
			buls.erase(buls.begin() + i);
			alive = false;
		}
	}
}
