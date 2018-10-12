#ifndef IMYLIB_HPP
# define IMYLIB_HPP

#include "MyContainers.hpp"

enum class Inputs : int {
	DEFAULT,
	LEFT,
	RIGHT,
	ESC,
	PAUSE,
	LIB_1,
	LIB_2,
	LIB_3
};

class IMyLib
{
public:
	virtual ~IMyLib(void) {};
	virtual bool	checkResolution(int width, int height) const = 0;
	virtual void	initGraphicLibObjects(MyContainers &) = 0;
	virtual void	draw(MyContainers &) = 0;
	virtual Inputs	getInput(void) = 0;

	// virtual void	createWindow(int width, int height) = 0;
};

#endif
