#include "Player.hpp"

Player::Player(std::string name) : _name{name}, _score{0}
{}

Player::~Player() {
	std::cout << "Player " << _name << " is destroyed." << std::endl;
}

std::string	Player::getName() const { return _name; }
int			Player::getScore() const { return _score; }

void		Player::markPoint() { _score += 10; }
void		Player::announces() const {
	std::cout << "Player " << _name << " has " << _score << " points." << std::endl;
}

Player*	createPlayer(const std::string& name) {
	return new Player(name);
}

void	deletePlayer(Player* player) {
	delete player;
}
