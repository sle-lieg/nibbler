#include "MySFML.hpp"

MySFML::MySFML(int width, int height, int tileSize) :
	_tileSize{tileSize}
{
	_window.create(sf::VideoMode(width , height), "mainWin", sf::Style::Default);
	
	_fieldTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(96, 0, 32, 32));
	_wallTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(64, 0, 32, 32));
	_snakeTexture.loadFromFile("dylibs/textures/snake.png");

	_fieldSprite.setTexture(_fieldTexture);
	_wallSprite.setTexture(_wallTexture);
	_snakeSprite.setTexture(_snakeTexture);
}

MySFML::~MySFML(void) {}

// void	MySFML::initGraphicLibObjects(int width, int height) {
// 	_window.create(sf::VideoMode(width , height), "mainWin", sf::Style::Default);
	
// 	_fieldTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(96, 0, 32, 32));
// 	_wallTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(64, 0, 32, 32));
// 	_snakeTexture.loadFromFile("dylibs/textures/snake.png");

// 	_fieldSprite.setTexture(_fieldTexture);
// 	_wallSprite.setTexture(_wallTexture);
// 	_snakeSprite.setTexture(_snakeTexture);
// }


// void	MySFML::createWindow(int width, int height) {
// 	_window.create(sf::VideoMode(width, height), "myWin", sf::Style::Default);
// }

Inputs	MySFML::getInput(void) {
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

void	MySFML::drawBackground(const std::vector<std::pair<int, int>> &coords, int widthLimit, int heightLimit)
{
	for (auto tile: coords) {
		if (tile.first == 0 || tile.first == widthLimit
		|| tile.second == 32 || tile.second == heightLimit) {
			_wallSprite.setPosition(tile.first, tile.second);
			_window.draw(_wallSprite);
		}
		else {
			_fieldSprite.setPosition(tile.first, tile.second);
			_window.draw(_fieldSprite);
		}
	}
}

void	MySFML::drawSnake(const std::vector<std::pair<int, int> > &coords, int direction)
{
	_snakeSprite.setTextureRect(sf::IntRect(direction * _tileSize, 0, _tileSize, _tileSize));
	_snakeSprite.setPosition(coords[0].first, coords[0].second);
	_window.draw(_snakeSprite);
	_snakeSprite.setTextureRect(sf::IntRect(4 * _tileSize, 0, _tileSize, _tileSize));
	for (size_t i = 1; i < coords.size(); i++) {
		_snakeSprite.setPosition(coords[i].first, coords[i].second);
		_window.draw(_snakeSprite);
	}
}

// void	MySFML::drawFruit(const std::vector<std::pair<int, int>> coords)
// {
// 	for (auto tile: coords) {
// 		_fruitSprite.setPosition(tile.first, tile.second);
// 		_window.draw(_fruitSprite);
// 	}
// }

IMyLib	*createMyLib(int width, int height, int tileSize) {
	return new MySFML(width, height, tileSize);
}

void	deleteMyLib(IMyLib *MySFML) {
	delete MySFML;
}
