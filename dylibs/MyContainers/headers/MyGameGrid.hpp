#ifndef MYGAMEGRID_HPP
# define MYGAMEGRID_HPP

#include "MyWindow.hpp"

// constexpr int TILE_SIZE = 32;

class MyGameGrid : public MyWindow
{
private:
	int	_tileSize;
	int	_nbTilesWidth;
	int	_nbTilesHeight;

	MyGameGrid(void);
	MyGameGrid(MyGameGrid const &);
	MyGameGrid&	operator=(MyGameGrid const &);

public:
	MyGameGrid(int width, int height, int tileSize);
	virtual ~MyGameGrid(void);

	virtual int	getNbTilesWidth(void) const;
	virtual int	getNbTilesHeight(void) const;
	virtual int	getTileSize(void) const;
};

#endif
