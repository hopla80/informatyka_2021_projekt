#include "Level.h"
#include "Menu.h"
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Block.h"
#include "Collision.h"
#include "GUI.h"
#include "Explosion.h"
#include "Write.h"
#include "End.h"

#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}
}

Game::~Game()
{
}

void Game::run(int difficulty)
{
	srand(time(0));

	int posX, posY;
	int expX, expY;

	Write write;
	Player player(difficulty);
	std::vector <Bullet> bullet;
	std::vector <Enemy> enemy;
	//std::vector <Explosion> explosion;
	Block block1;
	if (!block1.texture.loadFromFile("Resources/Images/block1.png"))
	{
		std::cout << "No block sprite";
	}
	block1.sprite.setPosition(rand() % 1920 - 50, rand() % 680);
	block1.sprite.setTexture(block1.texture);
	block1.scale = 2;
	block1.sprite.scale(block1.scale, block1.scale);

	Block block2;
	if (difficulty > 0)
	{
		if (!block2.texture.loadFromFile("Resources/Images/block2.png"))
		{
			std::cout << "No block sprite";
		}
		block2.sprite.setPosition(rand() % 1920 - 100, rand() % 680);
		block2.sprite.setTexture(block2.texture);
		block2.scale = 2.5f;
		block2.sprite.scale(block2.scale, block2.scale);
	}

	Block block3;
	if (difficulty > 1)
	{
		if (!block3.texture.loadFromFile("Resources/Images/block3.png"))
		{
			std::cout << "No block sprite";
		}
		block3.sprite.setPosition(rand() % 1920 - 200, rand() % 680);
		block3.sprite.setTexture(block3.texture);
		block3.scale = 4;
		block3.sprite.scale(block3.scale, block3.scale);
	}
	GUI Gui;

	std::cout << "Opening game\n";

	int width = 1920;
	int height = 1080;

	sf::RenderWindow gameWindow(sf::VideoMode(width, height), "Level", sf::Style::Fullscreen);
	Game mainGame(gameWindow.getSize().x, gameWindow.getSize().y);

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);

	gameWindow.setFramerateLimit(60);
	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing game";
					gameWindow.close();
					Menu menu;
					menu.run();
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					if (difficulty == 0)
					{
						bullet.emplace_back(player.posX(), player.posY() + player.sprite.getGlobalBounds().height);
						bullet.emplace_back(player.posX() + player.sprite.getGlobalBounds().width / 2, player.posY());
						bullet.emplace_back(player.posX() + player.sprite.getGlobalBounds().width, player.posY() + player.sprite.getGlobalBounds().height);
					}
					if (difficulty == 1)
					{
						bullet.emplace_back(player.posX() + player.sprite.getGlobalBounds().width / 2, player.posY());
					}
					if (difficulty == 2)
					{
						bullet.emplace_back(player.posX(), player.posY() + player.sprite.getGlobalBounds().height);
						bullet.emplace_back(player.posX() + player.sprite.getGlobalBounds().width, player.posY() + player.sprite.getGlobalBounds().height);
					}
				}
			}
		}
		elapsed = clock.getElapsedTime();
		if (elapsed.asMilliseconds() > 1000)
		{
			enemy.emplace_back();
			clock.restart();
		}
		if ((Collision::PixelPerfectTest(block1.sprite, player.sprite) && player.isColliding == 0) || (Collision::PixelPerfectTest(block2.sprite, player.sprite) && player.isColliding == 0))
		{
			player.isColliding = 1;
			player.life--;
		}
		if (!Collision::PixelPerfectTest(block1.sprite, player.sprite) && !Collision::PixelPerfectTest(block2.sprite, player.sprite))
		{
			player.isColliding = 0;
		}
		for (int i = 0; i < bullet.size(); i++)
		{
			for (int j = 0; j < enemy.size(); j++)
			{
				if (Collision::PixelPerfectTest(bullet[i].sprite, enemy[j].sprite))
				{
					bullet.erase(begin(bullet) + i);
					enemy.erase(begin(enemy) + j);
					player.points++;
				}
			}
			if ((Collision::PixelPerfectTest(block1.sprite, bullet[i].sprite)) || (Collision::PixelPerfectTest(block2.sprite, bullet[i].sprite)) || (Collision::PixelPerfectTest(block3.sprite, bullet[i].sprite)))
			{
				bullet.erase(begin(bullet) + i);
			}
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			if (enemy[i].posY() > 1080)
			{
				enemy.erase(begin(enemy) + i);
				player.life--;
			}
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			if (Collision::PixelPerfectTest(enemy[i].sprite, player.sprite))
			{
				enemy.erase(begin(enemy) + i);
				player.life--;
			}
		}
		if (player.life == 0)
		{
			write.run(player, difficulty);
			gameWindow.close();
			End end;
			end.run();
		}
		gameWindow.clear();
		gameWindow.draw(background);
		player.run(gameWindow);
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i].run(gameWindow);
		}
		for (int i = 0; i < enemy.size(); i++)
		{
			enemy[i].run(gameWindow);
		}
		block1.run(gameWindow);
		block2.run(gameWindow);
		block3.run(gameWindow);
		Gui.run(gameWindow, player);
		gameWindow.display();
	}
}