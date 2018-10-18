#include "Clock.hpp"

Clock::Clock(void) {}

Clock::~Clock(void) {}

void	Clock::reset() {
	clock_gettime(CLOCK_REALTIME, &_last);
}

float	Clock::getElapsedTime() {
	float timeElapsed;

	clock_gettime(CLOCK_REALTIME, &_current);
	timeElapsed = _current.tv_sec - _last.tv_sec \
	+ ((static_cast<float>(_current.tv_nsec - _last.tv_nsec) / NANO));

	return (timeElapsed);
}
