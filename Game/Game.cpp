#include <SFML/Graphics.hpp>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include "Player.h"
#include "Bullets.h"
#include "Enemy.h"
#include <vector>
#include <fstream>
using namespace sf;

int main()
{
	srand(time(NULL));
	std::vector <Enemy> en (32);
	std::vector <Bullet> bul(0);
	std::vector <Bullet> bulsen(0);
	for (int i = 0; i < 32; i++)
	{
		en[i].pos.x = (i % 8) * 34;
		en[i].pos.y = 10 + (i / 8) * 14;
	}
	Player pl;
	RenderWindow window(VideoMode(374, 200), "BAD ALIENS BY PETRIGN");
	sf::Clock clock;
	int ennum = 24;
	bool enwon = false;
	int scrn = 0;
	sf::Texture Scr;
	Scr.loadFromFile("Logo.png");
	sf::Sprite ScrSpr;
	ScrSpr.setTexture(Scr);
	while (window.isOpen())
	{
		while (scrn == 0 || scrn == 2 || scrn == 3)
		{
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					return 0;
				}

			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
				return 0;
			}
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				scrn=1;
				pl.lvs = 3;
				ennum = 32;
				enwon = false;
				bul.clear();
				en.clear();
				bulsen.clear();
				en.resize(32);
				pl.pos.x = 0;
				for (int i = 0; i < 32; i++)
				{
					en[i].pos.x = (i % 8) * 34;
					en[i].pos.y = 10 + (i / 8) * 14;
				}
			}
			window.draw(ScrSpr);
			window.display();
		}
		while (scrn == 1)
		{
			window.clear(sf::Color(0, 0, 0));
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
				return 0;
			}
			Time dt = clock.restart();
			float dtAsSec = dt.asSeconds();
			pl.update(dtAsSec,bul, bulsen);
			bool move = false;
			int ennum0 = ennum;
			ennum = 0;
			int enst = 0; // enemy shoot
			bool sht = false; // step is done and enemy is ready to shoot
			for (int i = 0; i < en.size(); i++)
			{
				if (en[i].alive)
				{
					if (en[i].move && !move)
					{
						move = true;
						for (int j = 0; j < i; j++)
						{
							en[j].move = true;
						}
					}
					if (move)
					{
						en[i].move = true;
					}
					en[i].update(dtAsSec, bul, 32-ennum);
					window.draw(en[i].getSpr());
					if (en[i].nextstep)
					{
						sht = true;
					}
					en[i].nextstep = false;
					ennum++;
					if (en[i].pos.y >= 150)
					{
						enwon = true;
					}
				}
			}
			if (sht)
			{
				enst = rand() % 2;
				if (enst == 1)
				{
					enst = rand() % 32;
					while (!en[enst].alive)
					{
						enst = rand() % 32;
					}
					en[enst].shoot(bulsen);
				}
			}
			for (size_t i = 0; i < bul.size(); i++)
			{
				bul[i].update(dtAsSec);
				bul[i].DrawBul(window);
				if (bul[i].pos.y <= -10)
				{
					bul.erase(bul.begin() + i);
				}
			}
			for (size_t i = 0; i < bulsen.size(); i++)
			{
				bulsen[i].update(dtAsSec);
				bulsen[i].DrawBul(window);
				if (bulsen[i].pos.y >= 210)
				{
					bulsen.erase(bulsen.begin() + i);
				}
			}
			window.draw(pl.getSpr());
			window.display();
			if (pl.lvs <= 0 || enwon)
			{
				Scr.loadFromFile("LoseScr.png");
				ScrSpr.setTexture(Scr);
				scrn = 2;
			}
			if (ennum <= 0)
			{
				Scr.loadFromFile("VicScr.png");
				ScrSpr.setTexture(Scr);
				scrn = 3;
			}
		}
		window.display();
	}
	return 0;
}