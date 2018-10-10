#ifndef GAME_HPP
# define GAME_HPP

// # include <iostream>
# include <dlfcn.h>
// # include "enumTypes.hpp"
# include "MyContainers.hpp"
# include "MySFML.hpp"
# include "nibbler.hpp"

// enum class Inputs : int;
class Game
{
private:
	void			*_dl_handle;
	IMyLib			*_myLib;
	MyContainers	*_myContainers;
	State			_state;
	float			_speed;
	// Snake	*_snake;

	void	_usage(void) const;
	void	_openLibrary(const char *lib);
	void	_closeLibrary(void);
	void	_initContainers(int widht, int height);

	Game(Game const &);
	Game& operator=(Game const &);
	Game( void );

public:
	Game(int ac, char **av);
	// Game(int width, int height);
	~Game( void );

	bool	isOpen(void) const;
	void	drawGame(void);
	void	handleInputs(void);
	// ########################

	// Scene	&getScene(void);

	// void	switchDirection(Inputs input);
	// void	quitGame(void);
	// void	pauseGame(void);
	// void	updateGame(void);

};

#endif
