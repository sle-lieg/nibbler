# include "LibHandler.hpp"

LibHandler::LibHandler(void) : _dl_handle {nullptr} {}

LibHandler::~LibHandler(void) {
	closeLib();
}

void	LibHandler::_dlerror_wrapper(void) const
{
	std::cerr << "Error: " << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void	LibHandler::openLib(const char *lib) {
	if (_dl_handle)
		closeLib();
	if (!(_dl_handle = dlopen(lib, RTLD_NOW | RTLD_LOCAL)))
		_dlerror_wrapper();

	MyLibCreator *createMyLib;
	if (!(createMyLib = (MyLibCreator*)dlsym(_dl_handle, "createMyLib")))
		_dlerror_wrapper();

	_myLib = createMyLib();
}

void	LibHandler::closeLib(void) {
	MyLibDeleter *deleteMyLib;

	if(!(deleteMyLib = (MyLibDeleter*)dlsym(_dl_handle, "deleteMyLib")))
		_dlerror_wrapper();
	deleteMyLib(_myLib);

	if (_dl_handle)
		if (dlclose(_dl_handle))
			_dlerror_wrapper();
}

bool	LibHandler::checkResolution(const Scene &scene) {
	if (!_myLib->checkResolution(scene.getWidth(), scene.getHeight())) {
		closeLib();
		return false;
	}
	return true;
}

void	LibHandler::createWin(Scene &scene) const {
	_myLib->createWindow(scene.getWidth(), scene.getHeight());
}

void	LibHandler::handleInput(Game &game) {
	Inputs input = _myLib->getInput();

	switch (input) {
		case Inputs::LIB_1:
		case Inputs::LIB_2:
		case Inputs::LIB_3:
			switchLibrary(input);
		case Inputs::LEFT:
		case Inputs::RIGHT:
			game.switchDirection(input);
			break;
		case Inputs::ESC:
			game.quitGame();
			break;
		case Inputs::PAUSE:
			game.pauseGame();
			break;
		default:
			break;
	}
}

void	LibHandler::switchLibrary(Inputs input) {
	Dl_info libInfos;

	if (dladdr(_myLib, &libInfos))
		std::cout << "input: " << static_cast<int>(input) << " current lib: " << libInfos.dli_fname << std::endl;
}

void	LibHandler::draw(const Game& game) {
	_myLib->draw(game);
}
