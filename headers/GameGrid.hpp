#ifndef GAMEGRID_HPP
# define GAMEGRID_HPP

#include "AGameEntity.hpp"

class GameGrid : public AGameEntity
{
private:
	GameGrid(GameGrid const &);
	GameGrid&	operator=(GameGrid const &);

public:
	GameGrid(void);
	~GameGrid(void);

	const std::vector<std::pair<int, int>> getCoords(void) const;
};

#endif
