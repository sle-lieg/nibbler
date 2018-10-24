#ifndef MYSFML_HPP
# define MYSFML_HPP

# include <iostream>
# include <SFML/Graphics.hpp>
# include "IMyLib.hpp"
# include <sstream>
# include <iomanip>

class MySFML: public IMyLib
{
private:
	sf::RenderWindow _window;

	sf::Sprite	_fieldSprite;
	sf::Sprite	_wallSprite;
	sf::Sprite	_snakeSprite;
	sf::Sprite	_fruitSprite;
	sf::Sprite	_hudSprite;

	sf::Texture	_fieldTexture;
	sf::Texture	_wallTexture;
	sf::Texture	_snakeTexture;
	sf::Texture	_fruitTexture;
	sf::Texture _hudTexture;

	sf::Font	_font;
	sf::Text	_hud;
	const int	_tileSize;

	MySFML(void);
	MySFML&	operator=(MySFML const &);
	MySFML(MySFML const &);
public:
	MySFML(int width, int height, int tileSize);
	virtual ~MySFML(void);

	// void	initGraphicLibObjects(int width, int height);
	void	drawBackground(const std::vector<std::pair<int, int>> &coords, int widthLimit, int heightLimit);
	void	drawSnake(const std::vector<std::pair<int, int>> &coords, int direction);
	void	drawFruit(const std::vector<std::pair<int, int>> &coords);
	void	drawHud(int score, int lvl);

	void	clearScreen(void);
	void	displayScreen(void);
	Inputs	getInput(void);
};

extern "C"	IMyLib *createMyLib(int, int, int);
typedef IMyLib *MyLibCreator(int, int, int);

extern "C" void	deleteMyLib(IMyLib *);
typedef void	MyLibDeleter(IMyLib *);


#endif
