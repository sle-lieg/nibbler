#ifndef MYCONTAINERS_HPP
# define MYCONTAINERS_HPP

// # include "MyWindow.hpp"
# include "MyGameGrid.hpp"
# include "MySnake.hpp"

class MyContainers
{
private:
	MyGameGrid	_gameGrid;
	MySnake		_snake;
	// MyHud		_hud;

	MyContainers(MyContainers const &);
	MyContainers& operator=(MyContainers const &);
	MyContainers( void );

public:
	MyContainers(int width, int height, int tileSize);
	virtual ~MyContainers( void );

	virtual MyGameGrid	&getGameGrid(void);
	virtual MySnake				&getSnake(void);

	// bool		isOpen(void) const;

	// void		switchDirection(Inputs input);
	// void		quitGame(void);
	// void		pauseGame(void);
	// void		updateGame(void);
};

typedef MyContainers *MyContainersCreator(int width, int height, int tileSize);
extern "C" MyContainers	*createMyContainers(int width, int height, int tileSize);

typedef void	MyContainersDeleter(MyContainers *myContainers);
extern "C" void			deleteMyContainers(MyContainers *myContainers);

#endif
