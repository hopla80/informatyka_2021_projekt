#include "Menu.h"
#include "Help.h"
#include "Level.h"
#include "Game.h"

#include <iostream>
#include <SFML/Graphics.hpp>


Level::Level(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/arial.ttf"))
	{
		std::cout << "No font";
	}

	prompt.setFont(font);
	prompt.setString("Choose the difficulty level");
	prompt.setPosition(sf::Vector2f(width / 3, height / (levelItems + 2) * 1));
	prompt.setCharacterSize(40);

	mainLevel[0].setFont(font);
	mainLevel[0].setFillColor(sf::Color::Blue);
	mainLevel[0].setStyle(sf::Text::Bold);
	mainLevel[0].setString("Easy");
	mainLevel[0].setCharacterSize(40);
	mainLevel[0].setPosition(sf::Vector2f(width / 3, height / (levelItems + 2) * 2));

	mainLevel[1].setFont(font);
	mainLevel[1].setFillColor(sf::Color::White);
	mainLevel[1].setString("Medium");
	mainLevel[1].setCharacterSize(40);
	mainLevel[1].setPosition(sf::Vector2f(width / 3, height / (levelItems + 2) * 3));

	mainLevel[2].setFont(font);
	mainLevel[2].setFillColor(sf::Color::White);
	mainLevel[2].setString("Hard");
	mainLevel[2].setCharacterSize(40);
	mainLevel[2].setPosition(sf::Vector2f(width / 3, height / (levelItems + 2) * 4));

	levelSelected = 0;
}

Level::~Level()
{
}

void Level::draw(sf::RenderWindow& window)
{
	window.draw(prompt);
	for (int i = 0; i < levelItems; i++)
	{
		window.draw(mainLevel[i]);
	}
}

void Level::moveUp()
{
	if (levelSelected >= 0)
	{
		mainLevel[levelSelected].setFillColor(sf::Color::White);
		mainLevel[levelSelected].setStyle(sf::Text::Regular);
		levelSelected--;
		if (levelSelected == -1)
		{
			levelSelected = levelItems - 1;
		}
		mainLevel[levelSelected].setFillColor(sf::Color::Blue);
		mainLevel[levelSelected].setStyle(sf::Text::Bold);
	}
}

void Level::moveDown()
{
	if (levelSelected <= levelItems - 1)
	{
		mainLevel[levelSelected].setFillColor(sf::Color::White);
		mainLevel[levelSelected].setStyle(sf::Text::Regular);
		levelSelected++;
		if (levelSelected == levelItems)
		{
			levelSelected = 0;
		}
		mainLevel[levelSelected].setFillColor(sf::Color::Blue);
		mainLevel[levelSelected].setStyle(sf::Text::Bold);
	}
}

int Level::LevelPressed()
{
	return levelSelected;
}

void Level::run()
{
	std::cout << "Opening level menu\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameLevel(sf::VideoMode(width, height), "Level", sf::Style::Fullscreen);
	Level mainLevel(gameLevel.getSize().x, gameLevel.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameLevel.isOpen())
	{
		sf::Event event;
		while (gameLevel.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameLevel.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainLevel.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainLevel.moveDown();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing level menu\n";
					gameLevel.close();
					Menu menu;
					menu.run();
				}
				if (event.key.code == sf::Keyboard::F1)
				{
					std::cout << "Closing level menu\n";
					gameLevel.close();
					Help help;
					help.run();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					if (mainLevel.LevelPressed() == 0)
					{
						std::cout << "Closing level menu\n";
						gameLevel.close();
						Game game;
						game.run(0);
					}
					if (mainLevel.LevelPressed() == 1)
					{
						std::cout << "Closing level menu\n";
						gameLevel.close();
						Game game;
						game.run(1);
					}
					if (mainLevel.LevelPressed() == 2)
					{
						std::cout << "Closing level menu\n";
						gameLevel.close();
						Game game;
						game.run(2);
					}
				}
			}
		}
		gameLevel.clear();
		gameLevel.draw(background);
		mainLevel.draw(gameLevel);
		gameLevel.display();
	}
}