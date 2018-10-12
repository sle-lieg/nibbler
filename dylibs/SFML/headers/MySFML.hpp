#ifndef MYSFML_HPP
# define MYSFML_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IMyLib.hpp"

class MySFML: public IMyLib
{
private:
	sf::RenderWindow _mainWindow;

	sf::Sprite	_gameGrid;
	sf::Sprite	_wall;
	sf::Sprite	_snake;

	sf::Texture	_gameGridTexture;
	sf::Texture	_wallTexture;
	sf::Texture	_snakeTexture;
	// sf::RenderWindow _gameGrid;

	void	_drawGameGrid(const MyGameGrid & gg);
	void	_drawSnake(const MySnake & snake, int tileSize);

	MySFML&	operator=(MySFML const &);
	MySFML(MySFML const &);

public:
	MySFML(void);
	virtual ~MySFML(void);

	bool	checkResolution(int width, int height) const;
	void	initGraphicLibObjects(MyContainers &);
	// void	createWindow(int width, int height);
	Inputs	getInput(void);
	void	draw(MyContainers &);
};

extern "C"	IMyLib *createMyLib(void);
typedef IMyLib *MyLibCreator(void);

extern "C" void	deleteMyLib(IMyLib *);
typedef void	MyLibDeleter(IMyLib *);


#endif
