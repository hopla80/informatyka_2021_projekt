#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#define scoreItems 10

class Highscores
{
private:
	int i;
	int width;
	int height;
	sf::Font font;
	sf::Text score[scoreItems];
	std::string line;
	int nr_line;
	std::string scoreString;
public:
	Highscores(int width = 0, int height = 0);
	~Highscores();
	void draw(sf::RenderWindow& window);
	void run();
};