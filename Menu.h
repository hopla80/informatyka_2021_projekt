#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define menuItems 4

class Menu
{
private:
	int width;
	int height;
	int menuSelected;
	sf::Font font;
	sf::Text mainMenu[menuItems];
public:
	Menu(int width = 0, int height = 0);
	~Menu();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void run();
	void close();
	int MenuPressed();
};