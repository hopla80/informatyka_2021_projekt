#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <stdio.h>
#include "Menu.h"
#include "Highscores.h"
#include "Write.h"

Highscores::Highscores(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}
	for (int i = 0; i < scoreItems; i++)
	{
		score[i].setFont(font);
		score[i].setCharacterSize(40);
		score[i].setPosition(sf::Vector2f(width / 3, (height-100) / (scoreItems + 1) * (i+1) + 100));
	}
}

Highscores::~Highscores()
{
}

void Highscores::draw(sf::RenderWindow& window)
{
	i = 0;
	std::ifstream file("Highscores.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			score[i].setString("Points: " + line);
			window.draw(score[i]);
			i++;
		}
		file.close();
	}
}

void Highscores::run()
{
	std::cout << "Opening highscores\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameHighscores(sf::VideoMode(width, height), "Highscores", sf::Style::Fullscreen);
	Highscores mainHighscores(gameHighscores.getSize().x, gameHighscores.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameHighscores.isOpen())
	{
		sf::Event event;
		while (gameHighscores.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameHighscores.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing highscores\n";
					gameHighscores.close();
					Menu menu;
					menu.run();
				}
			}
		}
		gameHighscores.clear();
		gameHighscores.draw(background);
		mainHighscores.draw(gameHighscores);
		gameHighscores.display();
	}
}