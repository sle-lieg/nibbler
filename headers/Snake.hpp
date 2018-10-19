#ifndef SNAKE_HPP
# define SNAKE_HPP

#include "AGameEntity.hpp"

class Snake : public AGameEntity
{
public:
	Snake(int snakeHeadX, int snakeHeadY);
	virtual ~Snake( void );
};

#endif
