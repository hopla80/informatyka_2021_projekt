#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define helpItems 3

class Help
{
private:
	int width;
	int height;
	sf::Font font;
	sf::Text prompt[helpItems];
public:
	Help(int width = 0, int height = 0);
	~Help();
	void draw(sf::RenderWindow& window);
	void run();
};