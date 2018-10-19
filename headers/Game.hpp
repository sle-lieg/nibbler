#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <dlfcn.h>
# include <memory.h>
# include "nibbler.hpp"
# include "AGameEntity.hpp"
# include "GameGrid.hpp"
# include "Snake.hpp"
# include "Fruit.hpp"
# include "Clock.hpp"
# include "IMyLib.hpp"
# include "MySFML.hpp"


class Game
{
private:
	State		_state;
	Clock		_clock;
	float		_speed;
	int			_gameWidth;
	int			_gameHeight;

	// GAME ELEMENTS
	std::unique_ptr<GameGrid>	_gameGrid;
	std::unique_ptr<Snake>		_snake;
	std::unique_ptr<Fruit>		_fruit;
	// std::unique_ptr<Hud>	_hud;

	// DYLIB ELEMENTS
	void	*_dl_handle;
	IMyLib	*_dylib;
	Inputs	_currentLibrary;

	// DYLIB FUNCTIONS
	void	_openLibrary(const char *lib);
	void	_closeLibrary(void);
	void	_dlerrorWrapper() const;
	void	_switchLibrary(Inputs input);

	void	_switchDirection(Inputs input);
	void	_quitGame();
	void	_pauseGame();

	void	_initGameElements(void);
	void	_usage(void) const;

	Game( void );
	Game(Game const &);
	Game&	operator=(Game const &);
public:
	Game(int ac, char **av);
	~Game(void);

	void	start(void);
	bool	isOpen(void) const;
	void	handleInputs(void);
	void	update(void);
	void	drawGame(void) const;
};

#endif
