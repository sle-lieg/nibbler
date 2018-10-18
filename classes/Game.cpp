#include "Game.hpp"
#include <sstream>

Game::Game(int ac, char **av) :
	_state{State::PAUSE}, _clock{}, _speed{Difficulty::EASY}
{
	std::cout << "Game initialized." << std::endl;
	if (ac != 3)
		_usage();

	std::stringstream	ss;
	int	width, height;
	ss.exceptions(std::ios::failbit);
	ss << av[1] << ' ' << av[2];
	try {
		ss >> width >> height;
	} catch (const std::stringstream::failure &e) {
		_usage();
	}
	_gameWidth = width & ~(TILE_SIZE - 1);
	_gameHeight = height & ~(TILE_SIZE - 1);
	if (_gameWidth < GAME_MIN_SIZE || _gameWidth > GAME_MAX_SIZE
	|| _gameHeight < GAME_MIN_SIZE || _gameHeight > GAME_MAX_SIZE)
		_usage();

	_openLibrary(SFML);
	_initGameElements();
}

Game::~Game(void)
{
	_gameGrid.reset(nullptr);
	_snake.reset(nullptr);
	_fruit.reset(nullptr);
	_closeLibrary();
}

void	Game::_initGameElements(void)
{
	_gameGrid = std::make_unique<GameEntity>();
	for (int y = 0; y < _gameHeight; y += TILE_SIZE) {
		for (int x = 0; x < _gameWidth; x += TILE_SIZE) {
			_gameGrid->addCoord(x, y);
		}
	}
	_snake = std::make_unique<GameEntity>();
	int snakeHeadY = (_gameWidth / 2) & ~(TILE_SIZE - 1);
	int snakeHeadX = (_gameHeight / 2) & ~(TILE_SIZE - 1);
	for (int i = 0; i < 4; i++)
		_snake->addCoord(snakeHeadX + TILE_SIZE * i, snakeHeadY);
	// _fruit = std::make_unique<GameEntity>();
	// _fruit->addCoord(_generateRandomCoord());
}

void	Game::start(void)
{
	_state = State::RUNNING;
	_clock.reset();
}

bool	Game::isOpen(void) const {
	if (_state == State::RUNNING || _state == State::PAUSE)
		return true;
	return false;
}

void	Game::handleInputs(void) {
	// Inputs input = _myLib->getInput();

	// switch (input) {
	// 	// case Inputs::LIB_1:
	// 	// case Inputs::LIB_2:
	// 	// case Inputs::LIB_3:
	// 	// 	_switchLibrary(input);
	// 	case Inputs::LEFT:
	// 	case Inputs::RIGHT:
	// 		_switchDirection(input);
	// 		break;
	// 	// case Inputs::ESC:
	// 	// 	_quitGame();
	// 	// 	break;
	// 	// case Inputs::PAUSE:
	// 	// 	_pauseGame();
	// 	// 	break;
	// 	default:
	// 		break;
	// }
}

void	Game::drawGame(void) const
{
	_dylib->drawBackground(_gameGrid->getCoords(), _gameWidth - TILE_SIZE, _gameHeight - TILE_SIZE);
	_dylib->drawSnake(_snake->getCoords(), _direction);
	// _dylib->drawFruit(_fruit.getCoords());
}

void	Game::_usage(void) const
{
	std::cout << "usage: nibbler `width` `height`" << std::endl;
	std::cout << "	`width`: minimum game width: [\033[1;32m" << GAME_MIN_SIZE << "\033[0m]" << std::endl;
	std::cout << "	`height`: minimum game height: [\033[1;32m" << GAME_MAX_SIZE << "\033[0m]" << std::endl;
	exit(EXIT_FAILURE);
}

//######################################################################
//########################### LIB MANAGEMENT ###########################
//######################################################################

void	Game::_openLibrary(const char *lib)
{
	if (!(_dl_handle = dlopen(lib, RTLD_NOW | RTLD_LOCAL)))
		_dlerrorWrapper();

	MyLibCreator	*createMyLib;
	if (!(createMyLib = (MyLibCreator*)dlsym(_dl_handle, "createMyLib")))
		_dlerrorWrapper();

	_dylib = createMyLib(_gameWidth, _gameHeight, TILE_SIZE);
}

void	Game::_closeLibrary()
{
	if (_dl_handle) {
		MyLibDeleter *deleteMyLib;

		if (!(deleteMyLib = (MyLibDeleter*)dlsym(_dl_handle, "deleteMyLib")))
			_dlerrorWrapper();
		deleteMyLib(_myLib);
		_myLib = nullptr;
		_dl_handle = nullptr;
	}
}

void	Game::_dlerrorWrapper() const
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

//######################################################################
//######################################################################
//######################################################################
