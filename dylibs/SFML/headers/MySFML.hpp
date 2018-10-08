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

class MyLib: public IMyLib
{
private:
	sf::RenderWindow _window;

	MyLib&	operator=(MyLib const &);
	MyLib(MyLib const &);

public:
	MyLib( void );
	virtual ~MyLib( void );

	bool	checkResolution(int width, int height) const;
	void	createWindow(int width, int height);
	Inputs	getInput(void);
	// void	draw(const Game&) const;
};

extern "C"	MyLib *createMyLib(void);
typedef MyLib *MyLibCreator(void);

extern "C" void	deleteMyLib(MyLib *);
typedef void	MyLibDeleter(MyLib *);


#endif
