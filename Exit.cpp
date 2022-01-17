#include "Menu.h"
#include "Help.h"
#include "Exit.h"

#include <iostream>
#include <SFML/Graphics.hpp>


Exit::Exit(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}

	prompt.setFont(font);
	prompt.setString("Do you really want to exit?");
	prompt.setPosition(sf::Vector2f(width / 3, height / (exitItems + 2) * 1));
	prompt.setCharacterSize(60);

	mainExit[0].setFont(font);
	mainExit[0].setFillColor(sf::Color::Blue);
	mainExit[0].setStyle(sf::Text::Bold);
	mainExit[0].setString("Stay");
	mainExit[0].setCharacterSize(40);
	mainExit[0].setPosition(sf::Vector2f(width / 3, height / (exitItems + 2) * 2));

	mainExit[1].setFont(font);
	mainExit[1].setFillColor(sf::Color::White);
	mainExit[1].setString("Exit");
	mainExit[1].setCharacterSize(40);
	mainExit[1].setPosition(sf::Vector2f(width / 3, height / (exitItems + 2) * 3));

	exitSelected = 0;
}

Exit::~Exit()
{
}

void Exit::draw(sf::RenderWindow& window)
{
	window.draw(prompt);
	for (int i = 0; i < exitItems; i++)
	{
		window.draw(mainExit[i]);
	}
}

void Exit::moveUp()
{
	if (exitSelected >= 0)
	{
		mainExit[exitSelected].setFillColor(sf::Color::White);
		mainExit[exitSelected].setStyle(sf::Text::Regular);
		exitSelected--;
		if (exitSelected == -1)
		{
			exitSelected = exitItems - 1;
		}
		mainExit[exitSelected].setFillColor(sf::Color::Blue);
		mainExit[exitSelected].setStyle(sf::Text::Bold);
	}
}

void Exit::moveDown()
{
	if (exitSelected <= exitItems - 1)
	{
		mainExit[exitSelected].setFillColor(sf::Color::White);
		mainExit[exitSelected].setStyle(sf::Text::Regular);
		exitSelected++;
		if (exitSelected == exitItems)
		{
			exitSelected = 0;
		}
		mainExit[exitSelected].setFillColor(sf::Color::Blue);
		mainExit[exitSelected].setStyle(sf::Text::Bold);
	}
}

int Exit::ExitPressed()
{
	return exitSelected;
}

void Exit::run()
{
	std::cout << "Opening exit menu\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameExit(sf::VideoMode(width, height), "Exit", sf::Style::Fullscreen);
	Exit mainExit(gameExit.getSize().x, gameExit.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameExit.isOpen())
	{
		sf::Event event;
		while (gameExit.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameExit.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainExit.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainExit.moveDown();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing program\n";
					gameExit.close();
				}
				if (event.key.code == sf::Keyboard::F1)
				{
					std::cout << "Closing exit menu\n";
					gameExit.close();
					Help help;
					help.run();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					if (mainExit.ExitPressed() == 0)
					{
						std::cout << "Closing exit menu\n";
						gameExit.close();
						Menu menu;
						menu.run();
					}
					if (mainExit.ExitPressed() == 1)
					{
						std::cout << "Closing program\n";
						gameExit.close();
					}
				}
			}
		}
		gameExit.clear();
		gameExit.draw(background);
		mainExit.draw(gameExit);
		gameExit.display();
	}
}