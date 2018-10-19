#include "nibbler.hpp"
#include "Game.hpp"

const char *LIBS[] = {
	"",
	"libmysfml.dylib",
	"libmyopengl.dylib",
	"libmysdl.dylib"
};

int main(int ac, char **av) {
	Game	game(ac, av);

	// game.displayMenu();
	game.start();
	while (game.isOpen()) {
		game.handleInputs();
		game.update();
		game.drawGame();
	}
}
