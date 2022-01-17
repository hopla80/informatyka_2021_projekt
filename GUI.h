#pragma once

#include "Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class GUI
{
private:
	std::string timeString;
	sf::Time timeTime;
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Text lifesText;
	int scale;
public:
	sf::Text timeText;
	int timeInt;
	sf::Text scoreText;
	sf::Font font;
	std::string score;
	GUI();
	~GUI();
	void getTime();
	void getPoints(Player player);
	void getLifes(Player player);
	void run(sf::RenderTarget& target, Player player);
};