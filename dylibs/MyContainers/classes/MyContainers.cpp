#include "MyContainers.hpp"

MyContainers::MyContainers(int width, int height, int tileSize) :
	_gameGrid(width, height, tileSize), _snake(width, height, tileSize)
{}

MyContainers::~MyContainers( void ) {
}

// const MyWindow		&MyContainers::getMainWindow(void) const { return _mainWindow; }

MyGameGrid	&MyContainers::getGameGrid(void) { return _gameGrid; }
MySnake		&MyContainers::getSnake(void) { return _snake; }


MyContainers	*createMyContainers(int width, int height, int tileSize) {
	return new MyContainers(width, height, tileSize);
}

void	deleteMyContainers(MyContainers *myContainers) {
	delete myContainers;
}
