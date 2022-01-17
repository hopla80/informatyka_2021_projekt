#include "Player.h"
#include "Level.h"

Player::Player(int difficulty)
{
	life = 5;
	speed = 20 / (difficulty + 1);
	scale = 5;
	if (!texture.loadFromFile("Resources/Images/player.png"))
	{
		std::cout << "No player sprite";
	}
	sprite.setPosition(960, 0);
	sprite.setTexture(texture);
	sprite.scale(scale, scale);
}

Player::~Player()
{
}

int Player::posX()
{
	return vector.x;
}

int Player::posY()
{
	return vector.y;
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (posX() > 0)
		{
			sprite.move(-speed, 0);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (posY() > 0)
		{
			sprite.move(0, -speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (posY() < 1080 - sprite.getGlobalBounds().height)
		{
			sprite.move(0, speed);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (posX() < 1920 - sprite.getGlobalBounds().width)
		{
			sprite.move(speed, 0);
		}
	}
}

int Player::pointsFun()
{
	return points;
}

void Player::run(sf::RenderTarget& target)
{
	vector = sprite.getPosition();
	posX();
	posY();
	Player::move();
	target.draw(sprite);
}