#include "GUI.h"
#include "Player.h"

GUI::GUI()
{
	scale = 1;
	if (!font.loadFromFile("Resources/Fonts/helvetica.ttf"))
	{
		std::cout << "No font";
	}
	timeText.setFont(font);
	timeText.setCharacterSize(40);
	timeText.setPosition(0, 0);
	scoreText.setFont(font);
	scoreText.setCharacterSize(40);
	scoreText.setPosition(0, 50);
	lifesText.setFont(font);
	lifesText.setCharacterSize(40);
	lifesText.setPosition(1580, 0);
	lifesText.setString("Lifes left: ");
}

GUI::~GUI()
{
}

void GUI::getTime()
{
	timeTime = clock.getElapsedTime();
	timeInt = timeTime.asMilliseconds();
	timeString = std::to_string(timeInt / 1000);
	timeText.setString("Time survived: " + timeString + "s");
}

void GUI::getPoints(Player player)
{
	score = std::to_string(player.pointsFun());
	scoreText.setString("Points: " + score);
}

void GUI::getLifes(Player player)
{
	
	if (!texture.loadFromFile("Resources/Images/bullet.png"))
	{
		std::cout << "No lifes";
	}
	sprite.setTexture(texture);
	sprite.setScale(scale, scale);
}

void GUI::run(sf::RenderTarget& target, Player player)
{
	GUI::getTime();
	GUI::getPoints(player);
	GUI::getLifes(player);
	target.draw(timeText);
	target.draw(scoreText);
	target.draw(lifesText);
	for (int i = 0; i < player.life; i++)
	{
		sprite.setPosition(1875 - i * 30, 0);
		target.draw(sprite);
	}
}