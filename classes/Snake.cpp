#include "Snake.hpp"

Snake::Snake(int snakeHeadX, int snakeHeadY) :
	_currentDirection{Direction::LEFT}, _newDirection{Direction::LEFT}
{
	for (int i = 0; i < 4; i++)
		_coords.push_back(std::make_pair(snakeHeadX + TILE_SIZE * i, snakeHeadY));
}

Snake::~Snake(void) {}

int		Snake::getCurrentDirection(void) const
{
	return static_cast<int>(_currentDirection);
}

int		Snake::getNewDirection(void) const
{
	return static_cast<int>(_newDirection);
}

void	Snake::setCurrentDirection(int dir)
{
	_currentDirection = static_cast<Direction>(dir);;
}

void	Snake::setNewDirection(int dir)
{
	_newDirection = static_cast<Direction>(dir);;
}

void	Snake::move()
{
	_coords.pop_back();
	if (_newDirection == Direction::UP)
		_coords.emplace(_coords.begin(), std::make_pair(_coords[0].first, _coords[0].second - TILE_SIZE));
	else if (_newDirection == Direction::DOWN)
		_coords.emplace(_coords.begin(), std::make_pair(_coords[0].first, _coords[0].second + TILE_SIZE));
	else if (_newDirection == Direction::LEFT)
		_coords.emplace(_coords.begin(), std::make_pair(_coords[0].first - TILE_SIZE, _coords[0].second));
	else if (_newDirection == Direction::RIGHT)
		_coords.emplace(_coords.begin(), std::make_pair(_coords[0].first + TILE_SIZE, _coords[0].second));

	_currentDirection = _newDirection;
}