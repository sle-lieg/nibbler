#ifndef MYSNAKE_HPP
# define MYSNAKE_HPP

# include <iostream>
# include <vector>
# include <utility>
#include <algorithm>

enum class SnakeDirection {
	TOP, LEFT, BOTTOM, RIGHT
};

class MySnake
{
private:
	SnakeDirection						_direction;
	std::vector<std::pair<int, int> >	_coords;

	MySnake(void);
	MySnake(MySnake const &);
	MySnake&	operator=(MySnake const &);
public:
	MySnake(int width, int height, int tileSize);
	~MySnake(void);

	virtual SnakeDirection	getDirection(void) const;
	virtual const std::vector<std::pair<int, int>> &	getCoords(void) const;

	virtual void			setDirection(SnakeDirection dir);
	// void			setCoords(std::pair<int, int> coord);
};

#endif
