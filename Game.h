#pragma once

#include "Level.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Game
{
private:
	int width;
	int height;
	sf::Font font;
	sf::Clock clock;
	sf::Time elapsed;
	int explosionCounter;
public:
	Game(int width = 0, int height = 0);
	~Game();
	void run(int difficulty);
};