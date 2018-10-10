#include "MyGameGrid.hpp"

MyGameGrid::MyGameGrid(int width, int height) :
	MyWindow(width & ~(TILE_SIZE - 1), height & ~(TILE_SIZE - 1))
{
	std::cout << "Game grid width: " << _width << std::endl;
	std::cout << "Game grid height: " << _height << std::endl;

	_nbTilesWidth = _width / TILE_SIZE;
	_nbTilesHeight = _height / TILE_SIZE;
}

MyGameGrid::~MyGameGrid(void)
{}

int	MyGameGrid::getNbTilesWidth(void) const { return _nbTilesWidth; }
int	MyGameGrid::getNbTilesHeight(void) const { return _nbTilesHeight; }
