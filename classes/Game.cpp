#include "Game.hpp"

Game::Game(int width, int height) : _width {width}, _height {height} {
	std::cout << "Game initialized: width=" << _width << " height=" << _height << std::endl;
}

Game::~Game(void) {
	std::cout << "Game destroyed" << std::endl;
}

int	Game::getWidth(void) const {
	return (_width);
}

int	Game::getHeight(void) const {
	return (_height);
}
