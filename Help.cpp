#include "Menu.h"
#include "Help.h"

Help::Help(int width, int height)
{
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}

	prompt[0].setFont(font);
	prompt[0].setString("Fly around in your spaceship using WASD");
	prompt[0].setCharacterSize(40);
	prompt[0].setPosition(sf::Vector2f(width / 3, height / (helpItems + 1) * 1));

	prompt[1].setFont(font);
	prompt[1].setString("Shoot your enemies");
	prompt[1].setCharacterSize(40);
	prompt[1].setPosition(sf::Vector2f(width / 3, height / (helpItems + 1) * 2));

	prompt[2].setFont(font);
	prompt[2].setString("Avoid the deadly poison clouds");
	prompt[2].setCharacterSize(40);
	prompt[2].setPosition(sf::Vector2f(width / 3, height / (helpItems + 1) * 3));
}

Help::~Help()
{
}

void Help::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < helpItems; i++)
	{
		window.draw(prompt[i]);
	}
}

void Help::run()
{
	std::cout << "Opening help\n";
	int width = 1920;
	int height = 1080;
	sf::RenderWindow gameHelp(sf::VideoMode(width, height), "Help", sf::Style::Fullscreen);
	Help mainHelp(gameHelp.getSize().x, gameHelp.getSize().y);
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(width, height));
	sf::Texture backdrop;
	backdrop.loadFromFile("Resources/Images/backdrop.png");
	background.setTexture(&backdrop);
	while (gameHelp.isOpen())
	{
		sf::Event event;
		while (gameHelp.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameHelp.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					std::cout << "Closing help\n";
					gameHelp.close();
					Menu menu;
					menu.run();
				}
			}
		}
		gameHelp.clear();
		gameHelp.draw(background);
		mainHelp.draw(gameHelp);
		gameHelp.display();
	}
}