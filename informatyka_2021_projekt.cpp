#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define Menu_items 3

class Menu
{
private:
	sf::Font font;
	sf::Text menu[Menu_items];
	int selectedItem = 0;
public:
	Menu(float width, float height);
	~Menu() {};
	void GoL();
	void GoR();
	int getSelectedItem();
	void draw(sf::RenderWindow& window);
};

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Font.ttf"))
	{
		return;
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Magenta);
	menu[0].setStyle(sf::Text::Italic);
	menu[0].setScale(2, 2);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / (Menu_items + 1) * 1, height / 2));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Help");
	menu[1].setPosition(sf::Vector2f(width / (Menu_items + 1) * 2, height / 2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / (Menu_items + 1) * 3, height / 2));
}

void Menu::GoL()
{
	if (selectedItem >= 0 && selectedItem < Menu_items)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		menu[selectedItem].setScale(1, 1);
		selectedItem--;
		if (selectedItem < 0)
		{
			selectedItem = Menu_items - 1;
		}
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Italic);
		menu[selectedItem].setScale(2, 2);
	}
}

void Menu::GoR()
{
	if (selectedItem >= 0 && selectedItem < Menu_items)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		menu[selectedItem].setScale(1, 1);
		selectedItem++;
		if (selectedItem >= Menu_items)
		{
			selectedItem = 0;
		}
		menu[selectedItem].setFillColor(sf::Color::Magenta);
		menu[selectedItem].setStyle(sf::Text::Italic);
		menu[selectedItem].setScale(2, 2);
	}
}

int Menu::getSelectedItem()
{
	return selectedItem;
}

void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < Menu_items; i++)
	{
		window.draw(menu[i]);
	}
}

int main()
{
	srand(time(NULL));
	int menu_selected_flag = 0;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");
	Menu menu(window.getSize().x, window.getSize().y);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (menu_selected_flag == 0)
				{
					if (event.key.code == sf::Keyboard::Right)
					{
						menu.GoR();
					}
					if (event.key.code == sf::Keyboard::Left)
					{
						menu.GoL();
					}
				}
			}
		}
		window.clear();
		menu.draw(window);
		window.display();
	}
	return 0;
}