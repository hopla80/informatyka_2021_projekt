#include "Menu.h"
#include "Game.h"
#include "End.h"

#include <iostream>
#include <SFML/Graphics.hpp>


End::End(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}

	prompt.setFont(font);
	prompt.setString("Game Over. Do you want to return to main menu?");
	prompt.setPosition(sf::Vector2f(width / 6, height / (endItems + 2) * 1));
	prompt.setCharacterSize(60);

	mainEnd[0].setFont(font);
	mainEnd[0].setFillColor(sf::Color::Blue);
	mainEnd[0].setStyle(sf::Text::Bold);
	mainEnd[0].setString("Return");
	mainEnd[0].setCharacterSize(40);
	mainEnd[0].setPosition(sf::Vector2f(width / 3, height / (endItems + 2) * 2));

	mainEnd[1].setFont(font);
	mainEnd[1].setFillColor(sf::Color::White);
	mainEnd[1].setString("Exit game");
	mainEnd[1].setCharacterSize(40);
	mainEnd[1].setPosition(sf::Vector2f(width / 3, height / (endItems + 2) * 3));

	endSelected = 0;
}

End::~End()
{
}

void End::draw(sf::RenderWindow& window)
{
	window.draw(prompt);
	for (int i = 0; i < endItems; i++)
	{
		window.draw(mainEnd[i]);
	}
}

void End::moveUp()
{
	if (endSelected >= 0)
	{
		mainEnd[endSelected].setFillColor(sf::Color::White);
		mainEnd[endSelected].setStyle(sf::Text::Regular);
		endSelected--;
		if (endSelected == -1)
		{
			endSelected = endItems - 1;
		}
		mainEnd[endSelected].setFillColor(sf::Color::Blue);
		mainEnd[endSelected].setStyle(sf::Text::Bold);
	}
}

void End::moveDown()
{
	if (endSelected <= endItems - 1)
	{
		mainEnd[endSelected].setFillColor(sf::Color::White);
		mainEnd[endSelected].setStyle(sf::Text::Regular);
		endSelected++;
		if (endSelected == endItems)
		{
			endSelected = 0;
		}
		mainEnd[endSelected].setFillColor(sf::Color::Blue);
		mainEnd[endSelected].setStyle(sf::Text::Bold);
	}
}

int End::EndPressed()
{
	return endSelected;
}

void End::run()
{
	std::cout << "Opening end menu\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameEnd(sf::VideoMode(width, height), "End", sf::Style::Fullscreen);
	End mainEnd(gameEnd.getSize().x, gameEnd.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameEnd.isOpen())
	{
		sf::Event event;
		while (gameEnd.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameEnd.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					mainEnd.moveUp();
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					mainEnd.moveDown();
				}
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing program\n";
					gameEnd.close();
					exit(0);
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					if (mainEnd.EndPressed() == 0)
					{
						std::cout << "Closing end menu\n";
						gameEnd.close();
						Menu menu;
						menu.run();
					}
					if (mainEnd.EndPressed() == 1)
					{
						std::cout << "Closing program\n";
						gameEnd.close();
						exit(0);
					}
				}
			}
		}
		gameEnd.clear();
		gameEnd.draw(background);
		mainEnd.draw(gameEnd);
		gameEnd.display();
	}
}