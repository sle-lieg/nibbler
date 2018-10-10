#ifndef ENUMTYPES_HPP
# define ENUMTYPES_HPP

enum class State {
	RUNNING,
	PAUSE,
	OFF
};

// enum class Color {
// 	BLUE
// };

namespace Difficulty {
	static const float EASY = 3.0f;
	static const float MEDIUM = 2.0f;
	static const float HARD = 1.0f;
}

#endif
