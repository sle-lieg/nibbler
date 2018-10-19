#ifndef AGAMEENTITY_HPP
# define AGAMEENTITY_HPP

#include <iostream>
#include <vector>
#include <utility>
#include "nibbler.hpp"

// TODO: change AGameEntity for GameEntity ??
class AGameEntity {
protected:
	std::vector<std::pair<int, int>> _coords;

	AGameEntity(AGameEntity const &);
	AGameEntity&	operator=(AGameEntity const &);
public:
	AGameEntity(void);
	virtual ~AGameEntity(void);

	virtual const std::vector<std::pair<int, int>> &getCoords(void) const;
	// void	addCoord(int x, int y);
	// void	popCoord(void);
};

#endif
