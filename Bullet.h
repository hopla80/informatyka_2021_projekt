#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float scale;
	int speed;
	sf::Texture* texture;
public:
	sf::Sprite sprite;
	Bullet(float posX = 0, float posY = 0);
	~Bullet();
	void move();
	void run(sf::RenderTarget& target);
};