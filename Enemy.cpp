#include "Enemy.h"
#include "Game.h"

Enemy::Enemy(int random, int posX)
{
	type = rand() % 3 + 1;
	sprite.setPosition(rand() % 1520 + 200, 0);
	if (type == 1)
	{
		texture = new sf::Texture;
		if (!texture->loadFromFile("Resources/Images/enemy1.png"))
		{
			std::cout << "No enemy sprite";
		}
		speed = 1;
		scale = 1;
	}
	if (type == 2)
	{
		texture = new sf::Texture;
		if (!texture->loadFromFile("Resources/Images/enemy2.png"))
		{
			std::cout << "No enemy sprite";
		}
		speed = 3;
		scale = 3;
	}
	if (type == 3)
	{
		texture = new sf::Texture;
		if (!texture->loadFromFile("Resources/Images/enemy3.png"))
		{
			std::cout << "No enemy sprite";
		}
		speed = 5;
		scale = 1;
	}
	sprite.setTexture(*texture);
	sprite.scale(scale, scale);
}

Enemy::~Enemy()
{
}

void Enemy::move()
{
	sprite.move(0, speed);
}

int Enemy::posY()
{
	return vector.y;
}

void Enemy::run(sf::RenderTarget& target)
{
	vector = sprite.getPosition();
	Enemy::move();
	target.draw(sprite);
}