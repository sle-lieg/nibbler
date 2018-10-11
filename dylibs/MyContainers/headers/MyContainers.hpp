#ifndef MYCONTAINERS_HPP
# define MYCONTAINERS_HPP

# include "MyWindow.hpp"
# include "MyGameGrid.hpp"

class MyContainers
{
private:
	// MyWindow	_mainWindow;
	MyGameGrid	_gameGrid;
	// MyHud		_hud;
	// Snake	*_snake;

	MyContainers(MyContainers const &);
	MyContainers& operator=(MyContainers const &);
	MyContainers( void );

public:
	MyContainers(int width, int height);
	virtual ~MyContainers( void );

	// virtual const MyWindow		&getMainWindow(void) const;
	virtual const MyGameGrid	&getGameGrid(void) const;

	// bool		isOpen(void) const;

	// void		switchDirection(Inputs input);
	// void		quitGame(void);
	// void		pauseGame(void);
	// void		updateGame(void);
};

typedef MyContainers *MyContainersCreator(int width, int height);
extern "C" MyContainers	*createMyContainers(int width, int height);

typedef void	MyContainersDeleter(MyContainers *myContainers);
extern "C" void			deleteMyContainers(MyContainers *myContainers);

#endif
