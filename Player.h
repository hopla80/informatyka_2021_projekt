#pragma once

#include "Level.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
private:
	float scale;
	int speed;
	sf::Texture texture;
public:
	int points;
	int isColliding;
	int life;
	sf::Sprite sprite;
	sf::Vector2f vector;
	Player(int difficulty);
	~Player();
	int posX();
	int posY();
	void move();
	int pointsFun();
	void run(sf::RenderTarget& target);
};