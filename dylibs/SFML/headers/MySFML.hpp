#ifndef MYSFML_HPP
# define MYSFML_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IMyLib.hpp"

enum class Inputs : int {
	DEFAULT,
	LEFT,
	RIGHT,
	ESC,
	PAUSE,
	LIB_1,
	LIB_2,
	LIB_3
};

class MySFML: public IMyLib
{
private:
	sf::RenderWindow _window;

	MySFML&	operator=(MySFML const &);
	MySFML(MySFML const &);

public:
	MySFML( void );
	virtual ~MySFML( void );

	bool	checkResolution(int width, int height) const;
	void	createWindow(int width, int height);
	Inputs	getInput(void);
	void	draw(const Game &);
};

extern "C"	IMyLib *createMyLib(void);
typedef IMyLib *MyLibCreator(void);

extern "C" void	deleteMyLib(IMyLib *);
typedef void	MyLibDeleter(IMyLib *);


#endif
