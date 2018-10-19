#include "AGameEntity.hpp"

AGameEntity::AGameEntity( void )
{}

AGameEntity::~AGameEntity( void )
{}

const std::vector<std::pair<int, int>> &AGameEntity::getCoords(void) const
{
	return _coords;
}
