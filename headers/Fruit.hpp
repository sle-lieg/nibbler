#ifndef FRUIT_HPP
# define FRUIT_HPP

# include "AGameEntity.hpp"

class Fruit: public AGameEntity
{
public:
	Fruit(void);
	~Fruit(void);
	void	popRandom(void);
};

#endif