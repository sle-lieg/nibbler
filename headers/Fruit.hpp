#ifndef FRUIT_HPP
# define FRUIT_HPP

# include "AGameEntity.hpp"
# include <ctime>
# include <cstdlib>

class Fruit: public AGameEntity
{
public:
	Fruit(void);
	~Fruit(void);
	void	popRandom(tile_coords_t snake);
};

#endif