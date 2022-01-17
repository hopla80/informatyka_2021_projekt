#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Block
{
private:
public:
	float scale;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f vector;
	Block();
	~Block();
	int posX();
	int posY();
	void run(sf::RenderTarget& target);
};