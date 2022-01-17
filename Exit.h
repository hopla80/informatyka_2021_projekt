#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define exitItems 2

class Exit
{
private:
	int width;
	int height;
	int exitSelected;
	sf::Font font;
	sf::Text prompt;
	sf::Text mainExit[exitItems];
public:
	Exit(int width = 0, int height = 0);
	~Exit();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void run();
	int ExitPressed();
};