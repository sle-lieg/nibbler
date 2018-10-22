#include "Fruit.hpp"

Fruit::Fruit(void)
{
	_coords.emplace(_coords.begin(), std::make_pair(TILE_SIZE * 2, TILE_SIZE * 2));
	srand(time(nullptr));
}

Fruit::~Fruit(void)
{}

void	Fruit::popRandom(tile_coords_t snake)
{
	_coords.front().first = ((rand() % (g_gameWidth - TILE_SIZE * 2) + TILE_SIZE) & ~(TILE_SIZE - 1));
	_coords.front().second = ((rand() % (g_gameHeight - TILE_SIZE * 3) + TILE_SIZE * 2) & ~(TILE_SIZE - 1));
	for (auto e: snake)
	{
		if (e == _coords.front())
		{
			popRandom(snake);
			break;
		}
	}
}
