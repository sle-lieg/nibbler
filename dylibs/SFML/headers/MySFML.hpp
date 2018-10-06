#ifndef MYSFML_HPP
# define MYSFML_HPP

#include <iostream>
#include <SFML/Window.hpp>

class MyLib
{
private:
	sf::Window _window;

	MyLib&	operator=(MyLib const &);
	MyLib(MyLib const &);

public:
	MyLib( void );
	virtual ~MyLib( void );

	virtual void	createWindow(int width, int height);
	// void	draw(const Game) const;
};

extern "C"	MyLib *createMyLib(void);
typedef MyLib *MyLibCreator(void);

extern "C" void	deleteMyLib(void);
typedef void	MyLibDeleter(MyLib *);


#endif
