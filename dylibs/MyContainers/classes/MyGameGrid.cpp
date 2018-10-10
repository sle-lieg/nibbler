#include "MyGameGrid.hpp"

MyGameGrid::MyGameGrid(int width, int height) :
	MyWindow(width, height)
{
	// set nbTiles***
}

MyGameGrid::~MyGameGrid(void)
{}

int	MyGameGrid::getNbTilesWidth(void) const { return _nbTilesWidth; }
int	MyGameGrid::getNbTilesHeight(void) const { return _nbTilesHeight; }
