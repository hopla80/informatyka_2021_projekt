#define _CRT_SECURE_NO_WARNINGS

#include "MakeScore.h"

#include <iostream>
#include <SFML/Graphics.hpp>

MakeScore::MakeScore()
{
	FILE* fp;
	fp = fopen("Highscores.dat", "w+b");
}

MakeScore::~MakeScore()
{
}

void MakeScore::run()
{
}