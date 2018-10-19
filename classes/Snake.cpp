#include "Snake.hpp"

Snake::Snake(int snakeHeadX, int snakeHeadY)
{
	for (int i = 0; i < 4; i++)
		_coords.push_back(std::make_pair(snakeHeadX + TILE_SIZE * i, snakeHeadY));
}

Snake::~Snake(void) {}
