#include "MySnake.hpp"

MySnake::MySnake(int width, int height, int tileSize) :
	_direction{SnakeDirection::LEFT}, _coords{4}
{
	int nbTilesWidht = (width & ~(tileSize - 1)) / tileSize;
	int nbTilesHeight = (height & ~(tileSize - 1)) / tileSize;

	std::cout << "nbTilesWidht: " << nbTilesWidht << " nbTilesHeight" << nbTilesHeight << std::endl;
	std::cout << "coord size: " << _coords.size() << std::endl;
	std::generate(_coords.begin(), _coords.end(), [&] () {
		std::pair<int, int> p = std::make_pair(nbTilesWidht / 2, nbTilesHeight / 2);
		nbTilesWidht += 2;
		// nbTilesHeight += 2;
		return p;
	});
	// for (auto e: _coords) {
	// 	std::cout << "COORDS: " << e.first << " " << e.second << std::endl;
	// }
	// _coords.push_back(std::make_pair<int, int>(nbTIlesWidht / 2, ))
}

MySnake::~MySnake(void) {}

SnakeDirection	MySnake::getDirection(void) const { return _direction; }
const std::vector<std::pair<int, int>> &	MySnake::getCoords(void) const { return _coords; }

void	MySnake::setDirection(SnakeDirection dir) {
	_direction = dir;
}
