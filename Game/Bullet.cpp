#include "Bullets.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Bullet::Bullet()
{
	spd = 100;
	tex.loadFromFile("s3.png");
	spr.setTexture(tex);
}

sf::Sprite Bullet::getSpr()
{
	return spr;
}

void Bullet::update(float elapsedTime)
{
	pos.y -= spd*elapsedTime;
	spr.setPosition(pos);
}

void Bullet::DrawBul(sf::RenderWindow &win)
{
	win.draw(getSpr());
}