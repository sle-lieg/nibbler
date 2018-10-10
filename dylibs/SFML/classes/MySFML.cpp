#include "MySFML.hpp"

MySFML::MySFML(void) {}

MySFML::~MySFML(void) {}

bool	MySFML::checkResolution(int width, int height) const {
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

void	MySFML::initGraphicLibObjects(const MyContainers & game) {
	_mainWindow.create(sf::VideoMode(game.getMainWindow().getWidth() , game.getMainWindow().getHeight()), "mainWin", sf::Style::Default);
	
	sf::Texture *texture = new sf::Texture;

	texture->loadFromFile("dylibs/textures/tileset.png", sf::IntRect(0, 0, 32, 32));
	texture->setRepeated(true);
	texture->setSmooth(true);
	_gameGrid.setTexture(*texture);
	// _gameGrid.create(sf::VideoMode(game.getGameGrid().getWidth() , game.getGameGrid().getHeight()), "gameGrid", sf::Style::None);

}


// void	MySFML::createWindow(int width, int height) {
// 	_window.create(sf::VideoMode(width, height), "myWin", sf::Style::Default);
// }

Inputs	MySFML::getInput(void) {
	sf::Event event;

	while (_mainWindow.pollEvent(event)) {
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

void	MySFML::draw(const MyContainers &game) {
	(void)game;
	// _drawMainWindow(game.getMainWindow());
	// _drawGameGrid(game.getGameGrid());
	// _drawSnake(game.getSnake());
	// _mainWindow.clear(sf::Color::Transparent);
	_mainWindow.draw(_gameGrid);
	// _mainWindow.clear(sf::Color::Blue);
	// _gameGrid.clear(sf::Color::Red);
	_mainWindow.display();
	// _gameGrid.display();
}

IMyLib	*createMyLib(void) {
	return new MySFML;
}

void	deleteMyLib(IMyLib *MySFML) {
	delete MySFML;
}
