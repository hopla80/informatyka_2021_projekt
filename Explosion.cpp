//#include "Explosion.h"
//
//Explosion::Explosion(float posX)
//{
//	speed = 1;
//	scale = 10;
//	texture = new sf::Texture;
//	if (!texture->loadFromFile("Resources/Images/explosion.png"))
//	{
//		std::cout << "No explosion";
//	}
//	sprite.setTexture(*texture);
//	sprite.setTextureRect(sf::IntRect(0, 0, 7, 7));
//	sprite.setScale(scale, scale);
//}
//
//Explosion::~Explosion()
//{
//}
//
//void Explosion::run(sf::RenderTarget& target)
//{
	//sf::IntRect rectSourceSprite(0, 0, 0, 0);
	//if (frameClock.getElapsedTime().asSeconds() > 1)
	//{
	//	if (rectSourceSprite.left == 21)
	//	{
	//		rectSourceSprite.left == 0;
	//	}
	//	else
	//	{
	//		rectSourceSprite.left += 7;
	//	}
	//sprite.setTextureRect(rectSourceSprite);
	//frameClock.restart();
	//target.draw(sprite);
	//}
//}