#ifndef IMYLIB_HPP
# define IMYLIB_HPP

# include <iostream>

enum class Inputs : int {
	DEFAULT = 0,
	SFML,
	OPENGL,
	SDL,
	LEFT,
	RIGHT,
	ESC,
	PAUSE
};

class IMyLib
{
public:
	virtual ~IMyLib(void) {};
	// virtual void	initGraphicLibObjects(MyContainers &) = 0;
	virtual void	drawBackground(const std::vector<std::pair<int, int>> &coords, int widthLimit, int heightLimit) = 0;
	virtual void	drawSnake(const std::vector<std::pair<int, int> > &coords, int direction) = 0;
	virtual void	drawFruit(const std::vector<std::pair<int, int> > &coords) = 0;
	virtual void	clearScreen(void) = 0;
	virtual void	displayScreen(void) = 0;
	virtual Inputs	getInput(void) = 0;

	// virtual void	createWindow(int width, int height) = 0;
};

#endif
