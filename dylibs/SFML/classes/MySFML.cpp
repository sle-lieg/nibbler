#include "MySFML.hpp"

MyLib::MyLib(void) {}

MyLib::~MyLib(void) {}

void	MyLib::createWindow(int width, int height) {
	_window.create(sf::VideoMode(width, height), "myWin", sf::Style::Default);
	while (true) {}

	// return new sf::Window{ sf::VideoMode(width, height), "myWin" };
}

MyLib	*createMyLib(void) {
	return new MyLib;
}

void	deleteMyLib(MyLib *myLib) {
	delete myLib;
}
