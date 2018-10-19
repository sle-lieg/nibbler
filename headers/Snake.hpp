#ifndef SNAKE_HPP
# define SNAKE_HPP

#include "AGameEntity.hpp"

class Snake : public AGameEntity
{
private:
	Direction _currentDirection;
	Direction _newDirection;

public:
	Snake(int snakeHeadX, int snakeHeadY);
	virtual ~Snake( void );

	Direction	getCurrentDirection(void) const;
	Direction	getNewDirection(void) const;

	void	setCurrentDirection(void);
	void	setNewDirection(void);

};

#endif
