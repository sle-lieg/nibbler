#include "nibbler.hpp"
#include "Game.hpp"

int main(int ac, char **av) {
	Game	game(ac, av);

	// game.displayMenu();
	game.start();
	while (game.isOpen()) {
		game.handleInputs();
		// game.update();
		game.drawGame();
	}
}
