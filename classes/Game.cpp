#include "Game.hpp"

/*
**	############ CLASS GAME ############
*/

Game::Game(int width, int height) :
	_scene{width, height}, _state{State::RUNNING}, _speed{Difficulty::EASY} {
	std::cout << "Game initialized." << std::endl;
}

Game::~Game(void) {
	std::cout << "Game destroyed" << std::endl;
}

Scene& Game::getScene(void) {
	return _scene;
}

bool	Game::isOpen(void) const {
	if (_state == State::RUNNING || _state == State::PAUSE)
		return true;
	return false;
}

void	Game::switchDirection(Inputs input) {
	std::cout << "Switch direction: input=[" << static_cast<int>(input) << "]" << std::endl;
}

void	Game::quitGame(void) {
	std::cout << "Quiting game" << std::endl;
}

void	Game::pauseGame(void) {
	std::cout << "Pausing game" << std::endl;
}

void	Game::updateGame(void) {
	
}
