#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>

class Game
{
private:
	int		_width;
	int		_height;
	// Snake	*_snake;

	Game(Game const &);
	Game&	operator=(Game const &);
	Game( void );

public:
	Game(int width, int height);
	~Game( void );
};

#endif
