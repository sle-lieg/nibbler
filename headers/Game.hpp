#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <dlfcn.h>
# include <memory.h>
# include "nibbler.hpp"
# include "GameEntity.hpp"
# include "Clock.hpp"
# include "IMyLib.hpp"

class Game
{
private:
	State		_state;
	Clock		_clock;
	float		_speed;
	int			_gameWidth;
	int			_gameHeight;
	int			_direction;

	// GAME ELEMENTS
	std::unique_ptr<GameEntity>	_gameGrid;
	std::unique_ptr<GameEntity>	_snake;
	std::unique_ptr<GameEntity>	_fruit;

	// DYLIB ELEMENTS
	void	*_dl_handle;
	IMyLib	*_dylib;


	void	_usage(void) const;
	void	_openLibrary(const char *lib);
	void	_closeLibrary(void);
	void	_dlerrorWrapper() const;
	void	_initGameElements(void);

	Game( void );
	Game(Game const &);
	Game&	operator=(Game const &);
public:
	Game(int ac, char **av);
	~Game(void);

	void	start(void);
	bool	isOpen(void) const;
	void	handleInputs(void);
	void	drawGame(void) const;
};

#endif
