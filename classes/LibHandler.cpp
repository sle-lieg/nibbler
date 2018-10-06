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
	if (_dl_handle)
		if (!(dlclose(_dl_handle)))
			_dlerror_wrapper();
	delete _myLib;
}

void	LibHandler::createWindow(int width, int height) const {
	_myLib->createWindow(width, height);

}

void	LibHandler::draw(const Game& game) const {
	void	(*libDraw)(const Game&);

	if (!(libDraw = (void(*)(const Game&))dlsym(_dl_handle, "draw")))
		_dlerror_wrapper();
	libDraw(game);

	std::cout << "DRAWING" << std::endl;
}
