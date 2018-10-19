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

	_openLibrary(LIBS[static_cast<int>(Inputs::SFML)]);
	_initGameElements();
}

Game::~Game(void)
{
	_gameGrid.reset(nullptr);
	_snake.reset(nullptr);
	// _fruit.reset(nullptr);
	_closeLibrary();
}

void	Game::_initGameElements(void)
{
	_gameGrid = std::make_unique<GameGrid>(_gameWidth, _gameHeight);

	int snakeHeadY = (_gameWidth / 2) & ~(TILE_SIZE - 1);
	int snakeHeadX = (_gameHeight / 2) & ~(TILE_SIZE - 1);
	_snake = std::make_unique<Snake>(snakeHeadX, snakeHeadY);

	_fruit = std::make_unique<Fruit>();
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
	Inputs input = _dylib->getInput();

	switch (input) {
		case Inputs::SFML:
		case Inputs::OPENGL:
		case Inputs::SDL:
			_switchLibrary(input);
			break;
		case Inputs::LEFT:
		case Inputs::RIGHT:
			_switchDirection(input);
			break;
		case Inputs::ESC:
			_quitGame();
			break;
		case Inputs::PAUSE:
			_pauseGame();
			break;
		default:
			break;
	}
}

void	Game::_switchDirection(Inputs input)
{
	// int curDir = _snake->getCurrentDirection();
	// int newDir = _snake->getNewDirection();
	int dir = _snake->getCurrentDirection();
	std::cout << "Switching direction" << std::endl;

	if (input == Inputs::LEFT)
		++dir;
	else if (input == Inputs::RIGHT)
		--dir;
	dir = dir < 0 ? 3 : dir % 4;
	_snake->setNewDirection(dir);
}

void	Game::_quitGame()
{
	std::cout << "Quit game" << std::endl;
	_state = State::OFF;
}

void	Game::_pauseGame()
{
	if (_state == State::RUNNING)
	{
		std::cout << "Pause game" << std::endl;
		_state = State::PAUSE;
	}
	else
	{
		std::cout << "Resume game" << std::endl;
		_state = State::RUNNING;
		_clock.reset();
	}
}

void	Game::drawGame(void) const
{
	_dylib->clearScreen();
	_dylib->drawBackground(_gameGrid->getCoords(), _gameWidth - TILE_SIZE, _gameHeight - TILE_SIZE);
	_dylib->drawSnake(_snake->getCoords(), _snake->getCurrentDirection());
	_dylib->drawFruit(_fruit->getCoords());
	_dylib->displayScreen();
}

void	Game::_usage(void) const
{
	std::cout << "usage: nibbler `width` `height`" << std::endl;
	std::cout << "	`width`: minimum game width: [\033[1;32m" << GAME_MIN_SIZE << "\033[0m]" << std::endl;
	std::cout << "	`height`: minimum game height: [\033[1;32m" << GAME_MAX_SIZE << "\033[0m]" << std::endl;
	exit(EXIT_FAILURE);
}

//######################################################################
//############################ UPDATE GAME ############################
//######################################################################

void	Game::update(void)
{
	float elapsed = _clock.getElapsedTime();

	if (elapsed > _speed) {
		_snake->move();
		// _checkCollisions();
		_clock.reset();
	}
}

//######################################################################
//######################################################################
//######################################################################

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
		deleteMyLib(_dylib);
		_dylib = nullptr;
		_dl_handle = nullptr;
	}
}

void	Game::_dlerrorWrapper() const
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void	Game::_switchLibrary(Inputs input)
{
	std::cout << "Switching library: " << LIBS[(int)input] << std::endl;
	// if (_currentLibrary != input)
	// {
	// 	const char *libraryToOpen = LIBS[static_cast<int>(input)];

	// 	_currentLibrary = input;
	// 	_closeLibrary();
	// 	_openLibrary(libraryToOpen);
	// }
}

//######################################################################
//######################################################################
//######################################################################
