#include "Player.h"
#include "Bullet.h"

Bullet::Bullet(float posX, float posY)
{
	speed = 40;
	scale = 1;
	texture = new sf::Texture;
	if (!texture->loadFromFile("Resources/Images/bullet.png"))
	{
		std::cout << "No bullet sprite";
	}
	sprite.setTexture(*texture);
	sprite.scale(scale, scale);
	sprite.setPosition(posX, posY);
}

Bullet::~Bullet()
{
}

void Bullet::move()
{
	sprite.move(0, -speed);
}

void Bullet::run(sf::RenderTarget& target)
{
	Bullet::move();
	target.draw(sprite);
}