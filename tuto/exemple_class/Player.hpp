#ifndef PAYER_HPP
# define PAYER_HPP

#include "IEntity.hpp"

class Player: public IEntity
{
private:
	Player(void);
	std::string	_name;
	int			_score;

public:
	Player(std::string name);
	~Player();

	std::string	getName(void) const;
	int			getScore(void) const;
	void		markPoint(void);
	void		announces(void) const;
};

extern "C" {
	Player*	createPlayer(const std::string& name);
	void	deletePlayer(Player* player);
}

#endif // PAYER_HPP
