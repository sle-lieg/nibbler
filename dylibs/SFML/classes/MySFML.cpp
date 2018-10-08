#include "MySFML.hpp"

MyLib::MyLib(void) {}

MyLib::~MyLib(void) {}

void	MyLib::createWindow(int width, int height) {
	_window.create(sf::VideoMode(width, height), "myWin", sf::Style::Default);
}

Inputs	MyLib::getInput(void) {
	sf::Event event;

	while (_window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Left:
						return Inputs::LEFT;
						break;
					case sf::Keyboard::Right:
						return Inputs::RIGHT;
						break;
					case sf::Keyboard::Escape:
						return Inputs::ESC;
						break;
					case sf::Keyboard::Space:
						return Inputs::PAUSE;
						break;
					case sf::Keyboard::Num1:
						return Inputs::LIB_1;
						break;
					case sf::Keyboard::Num2:
						return Inputs::LIB_2;
						break;
					case sf::Keyboard::Num3:
						return Inputs::LIB_3;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
	return Inputs::DEFAULT;
}


MyLib	*createMyLib(void) {
	return new MyLib;
}

void	deleteMyLib(MyLib *myLib) {
	delete myLib;
}
