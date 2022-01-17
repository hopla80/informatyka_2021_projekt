#include "Menu.h"
#include "Level.h"
#include "Help.h"
#include "Exit.h"
#include "Highscores.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

Menu::Menu(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Blue);
	mainMenu[0].setStyle(sf::Text::Bold);
	mainMenu[0].setString("Game");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(sf::Vector2f(width / 3, height / (menuItems + 1) * 1));

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Help");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(sf::Vector2f(width / 3, height / (menuItems + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Highscores");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(sf::Vector2f(width / 3, height / (menuItems + 1) * 3));

	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::White);
	mainMenu[3].setString("Exit");
	mainMenu[3].setCharacterSize(40);
	mainMenu[3].setPosition(sf::Vector2f(width / 3, height / (menuItems + 1) * 4));

	menuSelected = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < menuItems; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void Menu::moveUp()
{
	if (menuSelected >= 0)
	{
		mainMenu[menuSelected].setFillColor(sf::Color::White);
		mainMenu[menuSelected].setStyle(sf::Text::Regular);
		menuSelected--;
		if (menuSelected == -1)
		{
			menuSelected = menuItems - 1;
		}
		mainMenu[menuSelected].setFillColor(sf::Color::Blue);
		mainMenu[menuSelected].setStyle(sf::Text::Bold);
	}
}

void Menu::moveDown()
{
	if (menuSelected <= menuItems - 1)
	{
		mainMenu[menuSelected].setFillColor(sf::Color::White);
		mainMenu[menuSelected].setStyle(sf::Text::Regular);
		menuSelected++;
		if (menuSelected == menuItems )
		{
			menuSelected = 0;
		}
		mainMenu[menuSelected].setFillColor(sf::Color::Blue);
		mainMenu[menuSelected].setStyle(sf::Text::Bold);
	}
}

int Menu::MenuPressed()
{
	return menuSelected;
}

void Menu::run()
{
	std::cout << "Opening program\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameMenu(sf::VideoMode(width, height), "Project", sf::Style::Fullscreen);
	Menu mainMenu(gameMenu.getSize().x, gameMenu.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameMenu.isOpen())
	{
		sf::Event event;
		while (gameMenu.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameMenu.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainMenu.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainMenu.moveDown();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					gameMenu.close();
					Exit exit;
					exit.run();
				}
				if (event.key.code == sf::Keyboard::F1)
				{
					gameMenu.close();
					Help help;
					help.run();
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					if (mainMenu.MenuPressed() == 0)
					{
						gameMenu.close();
						Level level;
						level.run();
					}
					if (mainMenu.MenuPressed() == 1)
					{
						gameMenu.close();
						Help help;
						help.run();
					}
					if (mainMenu.MenuPressed() == 2)
					{
						gameMenu.close();
						Highscores highscores;
						highscores.run();
					}
					if (mainMenu.MenuPressed() == 3)
					{
						gameMenu.close();
						Exit exit;
						exit.run();
					}
				}
			}
			gameMenu.clear();
			gameMenu.draw(background);
			mainMenu.draw(gameMenu);
			gameMenu.display();
		}
	}
}