#define _CRT_SECURE_NO_WARNINGS

#include "Write.h"
#include "Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

Write::Write()
{
}

Write::~Write()
{
}

void Write::run(Player player, int difficulty)
{
	file.open("Highscores.txt", std::ios::out | std::ios::app);
	file << player.points << std::endl;
	file.close();
}