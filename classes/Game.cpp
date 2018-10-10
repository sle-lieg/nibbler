#include "Game.hpp"

Game::Game(int ac, char **av) :
	_myContainers{nullptr}, _state{State::RUNNING}, _speed{Difficulty::EASY}
{
	std::cout << "Game initialized." << std::endl;
	if (ac != 3)
		_usage();

	std::stringstream	ss;
	int					width;
	int					height;
	ss.exceptions(std::ios::failbit);
	ss << av[1] << ' ' << av[2];

	try {
		ss >> width >> height;
		if (width < TILE_SIZE * NB_TILES_MIN || height < TILE_SIZE * NB_TILES_MIN)
			_usage();
		_openLibrary(SFML);
	} catch (const std::stringstream::failure &e) {
		std::cout << e.what() << std::endl;
		_usage();
	} catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!_myLib->checkResolution(width, height))
		exit(EXIT_FAILURE);
	_initContainers(width, height);
	_myLib->initGraphicLibObjects(*_myContainers);
}

Game::~Game(void) {
	MyContainersDeleter *deleteMyContainers;

	if (!(deleteMyContainers = (MyContainersDeleter*)dlsym(_dl_handle, "deleteMyContainers"))) {
		std::cout << dlerror() << std::endl;
		exit(EXIT_FAILURE);
	}
	deleteMyContainers(_myContainers);
	_closeLibrary();
	std::cout << "Game destroyed" << std::endl;
}

void	Game::_openLibrary(const char *lib) {
	if (!(_dl_handle = dlopen(lib, RTLD_NOW | RTLD_LOCAL))) {
		throw std::invalid_argument(dlerror());
	}

	MyLibCreator	*createMyLib;
	if (!(createMyLib = (MyLibCreator*)dlsym(_dl_handle, "createMyLib")))
		throw std::invalid_argument(dlerror());
	
	_myLib = createMyLib();
}

void	Game::_closeLibrary() {
	if (_dl_handle) {
		MyLibDeleter *deleteMyLib;
		if (!(deleteMyLib = (MyLibDeleter*)dlsym(_dl_handle, "deleteMyLib")))
			throw std::invalid_argument(dlerror());

		deleteMyLib(_myLib);
		_myLib = nullptr;
		_dl_handle = nullptr;
	}
}

void	Game::_initContainers(int width, int height) {
	MyContainersCreator *createMyContainers;

	if (!(createMyContainers = (MyContainersCreator*)dlsym(_dl_handle, "createMyContainers")))
		throw std::invalid_argument(dlerror());

	_myContainers = createMyContainers(width, height);
}

void	Game::_usage(void) const {
	std::cout << "usage: nibbler `width` `height`" << std::endl;
	std::cout << "	`width`: minimum game width: [\033[1;32m" << TILE_SIZE * NB_TILES_MIN << "\033[0m]" << std::endl;
	std::cout << "	`height`: minimum game height: [\033[1;32m" << TILE_SIZE * NB_TILES_MIN << "\033[0m]" << std::endl;
	exit(EXIT_FAILURE);
}

bool	Game::isOpen(void) const {
	if (_state == State::RUNNING || _state == State::PAUSE)
		return true;
	return false;
}

void	Game::drawGame(void) {
	_myLib->draw(*_myContainers);
}

// ##########################################

void	Game::handleInputs(void) {
	Inputs input = _myLib->getInput();

	switch (input) {
		// case Inputs::LIB_1:
		// case Inputs::LIB_2:
		// case Inputs::LIB_3:
		// 	switchLibrary(input);
		// case Inputs::LEFT:
		// case Inputs::RIGHT:
		// 	game.switchDirection(input);
		// 	break;
		// case Inputs::ESC:
		// 	game.quitGame();
		// 	break;
		// case Inputs::PAUSE:
		// 	game.pauseGame();
		// 	break;
		default:
			break;
	}
}

// void	Game::switchDirection(Inputs input) {
// 	std::cout << "Switch direction: input=[" << static_cast<int>(input) << "]" << std::endl;
// }

// void	Game::quitGame(void) {
// 	std::cout << "Quiting game" << std::endl;
// }

// void	Game::pauseGame(void) {
// 	std::cout << "Pausing game" << std::endl;
// }

// void	Game::updateGame(void) {
	
// }

// // Scene& Game::getScene(void) {
// // 	return _scene;
// // }
