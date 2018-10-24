#ifndef SNAKE_HPP
# define SNAKE_HPP

#include "AGameEntity.hpp"

class Snake : public AGameEntity
{
private:
	Direction			_currentDirection;
	Direction			_newDirection;
	bool				_hasEaten;
	std::pair<int, int> _newTail;

	Snake();
	Snake(const Snake &);
	Snake &operator=(const Snake &);
public:
	Snake(int snakeHeadX, int snakeHeadY);
	virtual ~Snake( void );

	int		getCurrentDirection(void) const;
	int		getNewDirection(void) const;
	int		getNbFruitEaten(void) const;
	bool	hasEaten(void) const;

	void	setCurrentDirection(int dir);
	void	setNewDirection(int dir);

	void	move(void);
	bool	checkCollision(void) const;
	bool	checkCollision(const std::pair<int, int> &fruit) const;
	void	eatFruit(void);
	void	digest(void);
};

#endif
