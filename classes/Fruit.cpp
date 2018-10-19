#include "Fruit.hpp"

Fruit::Fruit(void)
{
	_coords.emplace(_coords.begin(), std::make_pair(TILE_SIZE * 2, TILE_SIZE * 2));
}

Fruit::~Fruit(void)
{}

void	Fruit::popRandom(void)
{

}
