#include "MyContainers.hpp"

MyContainers::MyContainers(int width, int height) :
	_mainWindow(width, height), _gameGrid(width, height) {}

MyContainers::~MyContainers( void ) {
}

const MyWindow	&MyContainers::getMainWindow(void) const { return _mainWindow; }

const MyWindow	&MyContainers::getGameGrid(void) const { return _gameGrid; }

MyContainers	*createMyContainers(int width, int height) {
	return new MyContainers(width, height);
}

void	deleteMyContainers(MyContainers *myContainers) {
	delete myContainers;
}
