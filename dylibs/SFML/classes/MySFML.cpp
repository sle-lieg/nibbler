#include "MySFML.hpp"

MyLib::MyLib(void) {}

MyLib::~MyLib(void) {}

bool	MyLib::checkResolution(int width, int height) const {
	// std::cout << "RESOLUTION ENTERED: " << width << " x " << height << std::endl;
	// std::cout << "SCREEN RESOLUTION	: " << sf::VideoMode::getDesktopMode().width << " x " << sf::VideoMode::getDesktopMode().height << std::endl;
	int		screenWidth = sf::VideoMode::getDesktopMode().width;
	int		screenHeight = sf::VideoMode::getDesktopMode().height;
	bool	ret = true;

	if (width > screenWidth) {
		std::cout << "error: width [\033[1;31m" << width << "\033[0m] higher than screen resolution width [\033[1;32m" << screenWidth << "\033[0m]" << std::endl;
		ret = false;
	}
	if (height > screenHeight) {
		std::cout << "error: height [\033[1;31m" << height << "\033[0m] higher than screen resolution height [\033[1;32m" << screenHeight << "\033[0m]" << std::endl;
		ret = false;
	}
	return ret;
}

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
