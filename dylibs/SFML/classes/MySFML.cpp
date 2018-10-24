#include "MySFML.hpp"

MySFML::MySFML(int width, int height, int tileSize) :
	_tileSize{tileSize}
{
	_window.create(sf::VideoMode(width , height), "mainWin", sf::Style::Default);
	
	_fieldTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(tileSize * 3, 0, tileSize, tileSize));
	_wallTexture.loadFromFile("dylibs/textures/myTileSet.png", sf::IntRect(tileSize * 2, 0, tileSize, tileSize));
	_snakeTexture.loadFromFile("dylibs/textures/snake2.png");
	_fruitTexture.loadFromFile("dylibs/textures/myTileSet2.png", sf::IntRect(0, tileSize, tileSize, tileSize));
	_hudTexture.loadFromFile("dylibs/textures/hud.png");

	_fieldSprite.setTexture(_fieldTexture);
	_wallSprite.setTexture(_wallTexture);
	_snakeSprite.setTexture(_snakeTexture);
	_fruitSprite.setTexture(_fruitTexture);
	_hudSprite.setTexture(_hudTexture);

	// if (!(_font.loadFromFile("/System/Library/Fonts/Courier.dfont")))
	// if (!(_font.loadFromFile("/System/Library/Fonts/AquaKana.ttc")))
	if (!(_font.loadFromFile("dylibs/textures/angrybirds-regular.ttf")))
	{
		std::cout << "Error: wrong font path" << std::endl;
		exit(EXIT_FAILURE);
	}
	_hud.setFont(_font);
	_hud.setCharacterSize(18);
	// _hud.setStyle(sf::Text::Bold);
	_hud.setPosition(_tileSize, 5.0f);
	_hud.setFillColor(sf::Color::Green);
}

MySFML::~MySFML(void) {}

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
						return Inputs::SFML;
						break;
					case sf::Keyboard::Num2:
						return Inputs::OPENGL;
						break;
					case sf::Keyboard::Num3:
						return Inputs::SDL;
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
		if (tile.second == 0)
		{
			if (tile.first == 0)
				_hudSprite.setTextureRect(sf::IntRect(0, 0, _tileSize, _tileSize));
			else if (tile.first == widthLimit)
				_hudSprite.setTextureRect(sf::IntRect(_tileSize * 2, 0, _tileSize, _tileSize));
			else
				_hudSprite.setTextureRect(sf::IntRect(_tileSize, 0, _tileSize, _tileSize));
			_hudSprite.setPosition(tile.first, tile.second);
			_window.draw(_hudSprite);
		}
		else
		{
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
}

// void	MySFML::drawBackground(const std::vector<std::pair<int, int>> &coords, int widthLimit, int heightLimit)
// {
// 	for (auto tile: coords) {
// 		if (tile.first == 0 || tile.first == widthLimit
// 		|| tile.second == 32 || tile.second == heightLimit) {
// 			_wallSprite.setPosition(tile.first, tile.second);
// 			_window.draw(_wallSprite);
// 		}
// 		else {
// 			_fieldSprite.setPosition(tile.first, tile.second);
// 			_window.draw(_fieldSprite);
// 		}
// 	}
// }

void	MySFML::drawSnake(const std::vector<std::pair<int, int> > &coords, int direction)
{
	// draw head
	_snakeSprite.setTextureRect(sf::IntRect(direction * _tileSize, 0, _tileSize, _tileSize));
	_snakeSprite.setPosition(coords[0].first, coords[0].second);
	_window.draw(_snakeSprite);
	// draw body
	_snakeSprite.setTextureRect(sf::IntRect(4 * _tileSize, 0, _tileSize, _tileSize));
	for (size_t i = 1; i < coords.size(); i++) {
		_snakeSprite.setPosition(coords[i].first, coords[i].second);
		_window.draw(_snakeSprite);
	}
}

void	MySFML::drawFruit(const std::vector<std::pair<int, int>> &coords)
{
	for (auto tile: coords) {
		_fruitSprite.setPosition(tile.first, tile.second);
		_window.draw(_fruitSprite);
	}
}

void	MySFML::drawHud(int score, int lvl)
{
	std::stringstream ss;
	ss << "Score: " << std::setw(7) << std::setfill('0') << score << "	Level: " << lvl;

	_hud.setString(ss.str());
	_window.draw(_hud);
}


void	MySFML::clearScreen(void)
{
	_window.clear();
}

void	MySFML::displayScreen(void)
{
	_window.display();
}


IMyLib	*createMyLib(int width, int height, int tileSize) {
	return new MySFML(width, height, tileSize);
}

void	deleteMyLib(IMyLib *MySFML) {
	delete MySFML;
}
