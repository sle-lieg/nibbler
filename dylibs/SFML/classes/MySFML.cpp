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

void	MySFML::initGraphicLibObjects(MyContainers & game) {
	_mainWindow.create(sf::VideoMode(game.getGameGrid().getWidth() , game.getGameGrid().getHeight()), "mainWin", sf::Style::Default);
	
	// std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();

	_gameGridTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(96, 0, 32, 32));
	_wallTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(64, 0, 32, 32));
	_snakeTexture.loadFromFile("dylibs/textures/snake.png");

	_gameGrid.setTexture(_gameGridTexture);
	_wall.setTexture(_wallTexture);
	_snake.setTexture(_snakeTexture);


	// _gameGrid.setPosition(sf::Vector2f(0.0f, 32.0f));
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

void	MySFML::_drawGameGrid(const MyGameGrid & gg) {
	static int nbTilesWidth = gg.getNbTilesWidth();
	static int nbTilesHeight = gg.getNbTilesHeight();

	for (int y = 1; y < nbTilesHeight; y++) {
		for (int x = 0; x < nbTilesWidth; x++) {
			if (x == 0 || x == nbTilesWidth - 1 || y == 1 || y == nbTilesHeight - 1) {
				_wall.setPosition(x * 32.0f, y * 32.0f);
				_mainWindow.draw(_wall);
			}
			else {
				_gameGrid.setPosition(x * 32.0f, y * 32.0f);
				_mainWindow.draw(_gameGrid);
			}
		}
	}
}

void	MySFML::_drawSnake(const MySnake &snakeDatas, int tileSize) {
	auto	coords = snakeDatas.getCoords();
	int		dir = static_cast<int>(snakeDatas.getDirection());

	_snake.setTextureRect(sf::IntRect(dir * tileSize, 0, tileSize, tileSize));
	_snake.setPosition(coords[0].first * tileSize, coords[0].second * tileSize);
	_mainWindow.draw(_snake);
	for (size_t i = 1; i < coords.size(); i++) {
		_snake.setTextureRect(sf::IntRect(4 * tileSize, 0, tileSize, tileSize));
		_snake.setPosition(coords[i].first * tileSize, coords[i].second * tileSize);
		_mainWindow.draw(_snake);
	}
}

void	MySFML::draw(MyContainers &game) {
	// _drawMainWindow(game.getMainWindow());
	_mainWindow.clear();
	_drawGameGrid(game.getGameGrid());
	_drawSnake(game.getSnake(), game.getGameGrid().getTileSize());
	// _mainWindow.clear(sf::Color::Transparent);
	// _mainWindow.draw(_gameGrid);
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
