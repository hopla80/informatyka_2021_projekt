#pragma once

#include "Player.h"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

class Write
{
private:
	std::fstream file;
	std::string path;
public:
	Write();
	~Write();
	std::fstream returnFile();
	void update();
	void run(Player player, int difficulty);
};