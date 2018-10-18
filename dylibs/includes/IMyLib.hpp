#ifndef IMYLIB_HPP
# define IMYLIB_HPP

# include <iostream>

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
	// virtual void	initGraphicLibObjects(MyContainers &) = 0;
	virtual void	drawBackground(const std::vector<std::pair<int, int>> &coords, int widthLimit, int heightLimit) = 0;
	virtual void	drawSnake(const std::vector<std::pair<int, int> > &coords, int direction) = 0;
	// virtual void	drawFruit(const std::vector<std::pair<int, int> > coords) = 0;
	virtual Inputs	getInput(void) = 0;

	// virtual void	createWindow(int width, int height) = 0;
};

#endif
