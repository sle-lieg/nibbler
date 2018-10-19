#ifndef GAMEGRID_HPP
# define GAMEGRID_HPP

#include "AGameEntity.hpp"

class GameGrid : public AGameEntity
{
public:
	GameGrid(int width, int height);
	virtual ~GameGrid(void);
};

#endif
