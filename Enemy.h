#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

class Enemy
{
private:
	float scale;
	int speed;
	sf::Texture* texture;
public:
	sf::Sprite sprite;
	sf::Vector2f vector;
	Enemy(int random = 0, int posX = 0);
	~Enemy();
	void move();
	int posY();
	void run(sf::RenderTarget& target);
	int type;
};