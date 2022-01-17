#include "Block.h"

Block::Block()
{
}

Block::~Block()
{
}

void Block::run(sf::RenderTarget& target)
{
	target.draw(sprite);
}