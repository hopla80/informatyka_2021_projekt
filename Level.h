#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define levelItems 3

class Level
{
private:
	int width;
	int height;
	int levelSelected;
	sf::Font font;
	sf::Text prompt;
	sf::Text mainLevel[levelItems];
public:
	Level(int width = 0, int height = 0);
	~Level();
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	void run();
	int LevelPressed();
};