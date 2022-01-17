#define _CRT_SECURE_NO_WARNINGS

#include "MakeTime.h"

#include <iostream>
#include <SFML/Graphics.hpp>

MakeTime::MakeTime()
{
	FILE* fp;
	fp = fopen("Times.dat", "a");
	fclose(fp);
}

MakeTime::~MakeTime()
{
}

void MakeTime::run()
{
}