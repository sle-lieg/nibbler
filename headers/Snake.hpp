#ifndef SNAKE_HPP
# define SNAKE_HPP

#include <iostream>
#include <std::vector>

class BodyPart
{
private:
	int _width;
	int _height;
	// Color color;

public:
	BodyPart( void );
	~BodyPart( void );
	BodyPart(BodyPart const &);
	BodyPart&	operator=(BodyPart const &);

	void	increaseSize(void);
};

class Snake
{
private:
	std::vector<BodyPart>	_body;

public:
	Snake( void );
	~Snake( void );
	Snake(Snake const &);
	Snake&	operator=(Snake const &);

	void	grow();
};

#endif
