#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define endItems 2

class End
{
private:
	int width;
	int height;
	int endSelected;
	sf::Font font;
	sf::Text prompt;
	sf::Text mainEnd[endItems];
public:
	End(int width = 0, int height = 0);
	~End();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void run();
	int EndPressed();
};