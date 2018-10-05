#ifndef PAYER_HPP
# define PAYER_HPP

// #include "IEntity.hpp"
#include <iostream>

class Player
{
private:
	Player(void);
	std::string	_name;
	int			_score;

public:
	Player(std::string name);
	~Player();

	virtual std::string	getName(void) const;
	virtual int			getScore(void) const;
	virtual void		markPoint(void);
	virtual void		announces(void) const;
};

typedef Player*	creator(const std::string&);
typedef void	deleter(Player*);

extern "C" {
	Player*	createPlayer(const std::string& name);
	void	deletePlayer(Player* player);
}

#endif // PAYER_HPP
