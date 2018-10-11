#ifndef LIBHANDLER_HPP
# define LIBHANDLER_HPP

# include <dlfcn.h>
# include "nibbler.hpp"
# include "MySFML.hpp"
# include "Scene.hpp"

class LibHandler
{
private:
	IMyLib	*_myLib;
	void	*_dl_handle;

	void	_dlerror_wrapper(void) const;

	LibHandler(LibHandler const &);
	LibHandler&	operator=(LibHandler const &);

public:
	LibHandler(void);
	~LibHandler(void);

	void	openLib(const char *lib);
	void	closeLib(void);

	// void	createWindow(int width, int height) const;
	bool	checkResolution(const Scene &);
	void	createWin(Scene &) const;
	void	handleInput(Game &);
	void	draw(const Game &);
	void	switchLibrary(Inputs input);
};

#endif