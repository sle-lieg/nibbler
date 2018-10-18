#ifndef CLOCK_HPP
# define CLOCK_HPP

#include <ctime>

constexpr int	NANO = 1000000000;

class Clock
{
private:
	struct timespec _last;
	struct timespec _current;

	Clock(Clock const &);
	Clock&	operator=(Clock const &);
public:
	Clock( void );
	~Clock( void );

	void	reset();
	float	getElapsedTime();

};

#endif
