#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include "enumTypes.hpp"
# include "Scene.hpp"

enum class Inputs : int;
class Game
{
private:
	Scene	_scene;
	State	_state;
	float	_speed;
	// Snake	*_snake;

	Game(Game const &);
	Game& operator=(Game const &);
	Game( void );

public:
	Game(int width, int height);
	~Game( void );

	Scene	&getScene(void);
	bool	isOpen(void) const;

	void	switchDirection(Inputs input);
	void	quitGame(void);
	void	pauseGame(void);
	void	updateGame(void);

};

#endif
