#ifndef MYSFML_HPP
# define MYSFML_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IMyLib.hpp"

class MySFML: public IMyLib
{
private:
	sf::RenderWindow _mainWindow;
	sf::Sprite	_background;
	sf::Sprite	_gameGrid;
	// sf::RenderWindow _gameGrid;

	MySFML&	operator=(MySFML const &);
	MySFML(MySFML const &);

public:
	MySFML(void);
	virtual ~MySFML(void);

	bool	checkResolution(int width, int height) const;
	void	initGraphicLibObjects(const MyContainers &);
	// void	createWindow(int width, int height);
	Inputs	getInput(void);
	void	draw(const MyContainers &);
};

extern "C"	IMyLib *createMyLib(void);
typedef IMyLib *MyLibCreator(void);

extern "C" void	deleteMyLib(IMyLib *);
typedef void	MyLibDeleter(IMyLib *);


#endif
