#ifndef NIBBLER_HPP
# define NIBBLER_HPP

constexpr int	TILE_SIZE = 32;
constexpr int	GAME_MIN_SIZE = 512;
constexpr int	GAME_MAX_SIZE = 1024;
constexpr auto	SFML { "libmysfml.dylib" };
constexpr auto	OPENGL { "libmyopengl.dylib" };
constexpr auto	SDL { "libmysdl.dylib" };

enum class State {
	RUNNING,
	PAUSE,
	OFF
};

namespace Difficulty {
	static const float EASY = 2.0f;
	static const float MEDIUM = 1.0f;
	static const float HARD = 0.5f;
}


#endif
