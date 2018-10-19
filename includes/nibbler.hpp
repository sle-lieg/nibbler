#ifndef NIBBLER_HPP
# define NIBBLER_HPP

constexpr int	TILE_SIZE = 32;
constexpr int	GAME_MIN_SIZE = 512;
constexpr int	GAME_MAX_SIZE = 1024;
// constexpr auto	SFML = "libmysfml.dylib";
// constexpr auto	OPENGL = "libmyopengl.dylib";
// constexpr auto	SDL = "libmysdl.dylib";

extern const char *LIBS[];

enum class State {
	RUNNING,
	PAUSE,
	OFF
};

enum class Direction {
	UP,
	LEFT,
	DOWN,
	RIGHT
};

namespace Difficulty {
	static const float EASY = 0.5f;
	static const float MEDIUM = 0.5f;
	static const float HARD = 0.3f;
}


#endif
