#ifndef IMYLIB_HPP
# define IMYLIB_HPP

class Game;
enum class Inputs : int;
class IMyLib
{
public:
	virtual void	createWindow(int width, int height) = 0;
	virtual Inputs	getInput(void) = 0;
	virtual bool	checkResolution(int width, int height) const = 0;
	virtual void	draw(const Game &) = 0;
	// virtual void	draw(const Game&) = 0;
};

#endif
