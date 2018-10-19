#ifndef SNAKE_HPP
# define SNAKE_HPP

#include "AGameEntity.hpp"

class Snake : public AGameEntity
{
private:
	Direction _currentDirection;
	Direction _newDirection;

	Snake();
	Snake(const Snake &);
	Snake &operator=(const Snake &);
public:
	Snake(int snakeHeadX, int snakeHeadY);
	virtual ~Snake( void );

	int		getCurrentDirection(void) const;
	int		getNewDirection(void) const;

	void	setCurrentDirection(int dir);
	void	setNewDirection(int dir);

	void	move(void);
};

#endif
