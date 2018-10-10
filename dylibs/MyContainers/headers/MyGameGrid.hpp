#ifndef MYGAMEGRID_HPP
# define MYGAMEGRID_HPP

#include "MyWindow.hpp"

class MyGameGrid : public MyWindow
{
private:
	int	_nbTilesWidth;
	int	_nbTilesHeight;

	MyGameGrid(void);
	MyGameGrid(MyGameGrid const &);
	MyGameGrid&	operator=(MyGameGrid const &);

public:
	MyGameGrid(int width, int height);
	~MyGameGrid(void);

	int	getNbTilesWidth(void) const;
	int	getNbTilesHeight(void) const;
};

#endif
