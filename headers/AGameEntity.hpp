#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

#include <iostream>
#include <vector>
#include <utility>
#include "nibbler.hpp"

using tile_coords_t = std::vector<std::pair<int, int>>;

// TODO: change AGameEntity for GameEntity ??
class AGameEntity {
protected:
	tile_coords_t _coords;

	AGameEntity(AGameEntity const &);
	AGameEntity&	operator=(AGameEntity const &);
public:
	AGameEntity(void);
	virtual ~AGameEntity(void);

	virtual const tile_coords_t &getCoords(void) const;
	// void	addCoord(int x, int y);
	// void	popCoord(void);
};

#endif
