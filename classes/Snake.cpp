#include "Snake.hpp"

Snake::Snake(int snakeHeadX, int snakeHeadY) :
	_currentDirection{Direction::LEFT}, _newDirection{Direction::LEFT}, _nbFruitEaten{0}
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

int		Snake::getNbFruitEaten(void) const
{
	return _nbFruitEaten;
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

// bool	Snake::checkCollision(const int widthMax, const int heightMax) const
// {
// 	if (_coords[0].first == 0 || _coords[0].first == widthMax
// 	|| _coords[0].second == TILE_SIZE || _coords[0].second == heightMax)
// 		return true;
// 	for (int i = 1; i < _coords.size(); i++)
// 	{
// 		if (_coords[i] == _coords.front())
// 			return true;
// 	}
// 	return false;
// }

bool	Snake::checkCollision(void) const
{
	const int widthMax = g_gameWidth - TILE_SIZE;
	const int heightMax = g_gameHeight - TILE_SIZE;

	if (_coords[0].first == 0 || _coords[0].first == widthMax
	|| _coords[0].second == TILE_SIZE || _coords[0].second == heightMax)
		return true;
	for (size_t i = 1; i < _coords.size(); i++)
	{
		if (_coords[i] == _coords.front())
			return true;
	}
	return false;
}

bool	Snake::checkCollision(const std::pair<int, int> &fruit) const
{
	if (_coords.front() == fruit)
		return true;
	return false;
}

void	Snake::eatFruit(void)
{
	_hasEaten = true;
	_nbFruitEaten++;
	_newTail = _coords.back();
}

bool	Snake::hasEaten(void) const
{
	return _hasEaten;
}

void	Snake::digest(void)
{
	_hasEaten = false;
	_coords.push_back(_newTail);
}