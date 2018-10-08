#ifndef ENUMTYPES_HPP
# define ENUMTYPES_HPP

// enum class Inputs {
// 	DEFAULT,
// 	LEFT,
// 	RIGHT,
// 	ESC,
// 	PAUSE,
// 	LIB_1,
// 	LIB_2,
// 	LIB_3
// };

enum class State {
	RUNNING,
	PAUSE,
	OFF
};

enum class Color {
	BLUE
};

namespace Difficulty {
	static const float EASY = 3.0f;
	static const float MEDIUM = 2.0f;
	static const float HARD = 1.0f;
}

// enum class Difficulty {
// 	EASY = 3,
// 	MEDIUM = 2,
// 	HARD = 1
// };

#endif
