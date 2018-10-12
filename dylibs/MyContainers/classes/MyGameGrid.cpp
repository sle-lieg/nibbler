#include "MyGameGrid.hpp"

MyGameGrid::MyGameGrid(int width, int height, int tileSize) :
	MyWindow(width & ~(tileSize - 1), height & ~(tileSize - 1)), _tileSize{tileSize}
{
	std::cout << "Game grid width: " << _width << std::endl;
	std::cout << "Game grid height: " << _height << std::endl;

	_nbTilesWidth = _width / tileSize;
	_nbTilesHeight = _height / tileSize;
}

MyGameGrid::~MyGameGrid(void)
{}

int	MyGameGrid::getNbTilesWidth(void) const { return _nbTilesWidth; }
int	MyGameGrid::getNbTilesHeight(void) const { return _nbTilesHeight; }
int	MyGameGrid::getTileSize(void) const { return _tileSize; }
